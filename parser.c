#include "parser.h"
#include "error.h"
#include "types.h"
#include "constants.h"
#include <stdlib.h>
#include <assert.h>

CREATE_VECTOR_DEFINITION(ByteVector, uint8_t, byte_vector)

typedef struct {
    ArgumentType type;
    Token const* first_token;
} Argument;

typedef struct {
    StringView name;
    Address address;
} Label;

CREATE_VECTOR_DECLARATION(LabelVector, Label, label_vector)
CREATE_VECTOR_DEFINITION(LabelVector, Label, label_vector)

CREATE_VECTOR_DECLARATION(ArgumentVector, Argument, argument_vector)
CREATE_VECTOR_DEFINITION(ArgumentVector, Argument, argument_vector)

typedef struct {
    TokenVector tokens;
    OpcodeList opcodes;
    size_t current;
    ByteVector machine_code;
    LabelVector labels;
    SourceFile source_file;
} ParserState;

typedef struct {
    uint8_t bytes[4];
} U32Bytes;

typedef struct {
    uint8_t bytes[8];
} U64Bytes;

static ParserState state;

Token* current() {
    return &state.tokens.data[state.current];
}

Token* peek() {
    return state.current == state.tokens.size - 1 ? NULL : &state.tokens.data[state.current + 1];
}

Token* next() {
    if (state.current == state.tokens.size - 1) {
        return NULL;
    }
    ++state.current;
    return current();
}

U32Bytes u32_to_big_endian(uint32_t value) {
    return (U32Bytes){
        .bytes = {
            (uint8_t)(value >> 24),
            (uint8_t)(value >> 16),
            (uint8_t)(value >> 8),
            (uint8_t)(value >> 0),
        }
    };
}

U64Bytes u64_to_big_endian(uint64_t value) {
    return (U64Bytes){
        .bytes = {
            (uint8_t)(value >> 56),
            (uint8_t)(value >> 48),
            (uint8_t)(value >> 40),
            (uint8_t)(value >> 32),
            (uint8_t)(value >> 24),
            (uint8_t)(value >> 16),
            (uint8_t)(value >> 8),
            (uint8_t)(value >> 0),
        }
    };
}

void emit_u32(uint32_t value) {
    U32Bytes const bytes = u32_to_big_endian(value);
    byte_vector_push(&state.machine_code, bytes.bytes[0]);
    byte_vector_push(&state.machine_code, bytes.bytes[1]);
    byte_vector_push(&state.machine_code, bytes.bytes[2]);
    byte_vector_push(&state.machine_code, bytes.bytes[3]);
}

void emit_u64(uint64_t value) {
    U64Bytes const bytes = u64_to_big_endian(value);
    byte_vector_push(&state.machine_code, bytes.bytes[0]);
    byte_vector_push(&state.machine_code, bytes.bytes[1]);
    byte_vector_push(&state.machine_code, bytes.bytes[2]);
    byte_vector_push(&state.machine_code, bytes.bytes[3]);
    byte_vector_push(&state.machine_code, bytes.bytes[4]);
    byte_vector_push(&state.machine_code, bytes.bytes[5]);
    byte_vector_push(&state.machine_code, bytes.bytes[6]);
    byte_vector_push(&state.machine_code, bytes.bytes[7]);
}

bool register_label(StringView label_name) {
    for (size_t i = 0; i < state.labels.size; ++i) {
        if (string_view_compare(label_name, state.labels.data[i].name) == 0) {
            return false;
        }
    }
    label_vector_push(&state.labels, (Label){
        .name = label_name,
        .address = (Address)(state.machine_code.size + ENTRY_POINT),
    });
    return true;
}

void error_on_token(char const * const message, Token const * const token) {
    error(
        state.source_file,
        message,
        token->line,
        token->column,
        token->string_view.length
    );
}

void error_on_current_token(char const * const message) {
    error_on_token(message, current());
}

void init_state(SourceFile const source_file, TokenVector const tokens, OpcodeList const opcodes) {
    state = (ParserState){
        .tokens = tokens,
        .opcodes = opcodes,
        .current = 0,
        .machine_code = byte_vector_create(),
        .labels = label_vector_create(),
        .source_file = source_file,
    };
}

ByteVector cleanup_state() {
    label_vector_free(&state.labels);
    return state.machine_code;
}

bool do_arguments_match(ArgumentType const lhs, ArgumentType const rhs) {
    return lhs == rhs
        || (lhs == ARGUMENT_TYPE_ADDRESS && rhs == ARGUMENT_TYPE_LABEL)
        || (lhs == ARGUMENT_TYPE_LABEL && rhs == ARGUMENT_TYPE_ADDRESS);
}

bool do_argument_lists_match(
    ArgumentVector const arguments,
    OpcodeSpecification const * const opcode
) {
    assert(arguments.size == opcode->argument_count);
    for (size_t i = 0; i < arguments.size; ++i) {
        if (!do_arguments_match(arguments.data[i].type, opcode->required_arguments[arguments.size - i - 1])) {
            return false;
        }
    }
    return true;
}

OpcodeSpecification const* find_opcode(Token const * const mnemonic, ArgumentVector const arguments) {
    for (size_t i = 0; i < state.opcodes.num_specifications; ++i) {
        OpcodeSpecification const * const opcode = &state.opcodes.specifications[i];
        if (
            opcode->argument_count == arguments.size
            && string_view_compare_case_insensitive(mnemonic->string_view, opcode->mnemonic) != 0
        ) {

        }
        if (
            opcode->argument_count == arguments.size
            && string_view_compare_case_insensitive(mnemonic->string_view, opcode->mnemonic) == 0
            && do_argument_lists_match(arguments, opcode)
        ) {
            return opcode;
        }
    }
    return NULL;
}

void emit_instruction(Token const * const mnemonic, ArgumentVector const arguments) {
    printf(
        "should emit instruction for mnemonic %.*s with %zu arguments.\n",
        (int)mnemonic->string_view.length,
        mnemonic->string_view.data,
        arguments.size
    );
    for (size_t i = 0; i < arguments.size; ++i) {
        printf(
            "\t%.*s\n",
            (int)arguments.data[i].first_token->string_view.length,
            arguments.data[i].first_token->string_view.data
        );
    }
    OpcodeSpecification const * const opcode = find_opcode(mnemonic, arguments);
    if (opcode == NULL) {
        error_on_token("unknown instruction or invalid arguments", mnemonic);
    } else {
        printf(
            "\tfound matching opcode: %.*s (0x%#.04x)\n",
            (int)opcode->name.length,
            opcode->name.data,
            opcode->opcode
        );
    }
}

void parse_label() {
    if (!register_label(identifier_from_token(current()))) {
        error_on_current_token("label redefinition");
    }
    next(); // consume colon following label name
}

void parse_instruction() {
    Token const * const mnemonic = current();
    Token const* current_argument_start = NULL;
    ArgumentVector arguments = argument_vector_create();
    bool valid_argument_start_position = true;
    next();
    while (true) {
        if (current()->type == TOKEN_TYPE_COMMA) {
            if (valid_argument_start_position) {
                error_on_current_token("unexpected comma");
            } else {
                next();
                valid_argument_start_position = true;
            }
        }
        if (current()->type == TOKEN_TYPE_ASTERISK) {
            // pointer or address
            current_argument_start = current();
        } else if (current()->type == TOKEN_TYPE_EOF || current()->type == TOKEN_TYPE_NEWLINE) {
            if (current_argument_start != NULL) {
                error_on_current_token("register or address expected");
            }
            break;
        } else {
            if (current_argument_start == NULL) {
                // no pointer and no address
                switch (current()->type) {
                    case TOKEN_TYPE_WORD_LITERAL:
                        argument_vector_push(&arguments, (Argument){
                            .type = ARGUMENT_TYPE_IMMEDIATE,
                            .first_token = current(),
                        });
                        valid_argument_start_position = false;
                        break;
                    case TOKEN_TYPE_REGISTER:
                        argument_vector_push(&arguments, (Argument){
                            .type = ARGUMENT_TYPE_REGISTER,
                            .first_token = current(),
                        });
                        valid_argument_start_position = false;
                        break;
                    case TOKEN_TYPE_IDENTIFIER:
                        argument_vector_push(&arguments, (Argument){
                            .type = ARGUMENT_TYPE_LABEL,
                            .first_token = current(),
                        });
                        valid_argument_start_position = false;
                        break;
                    default:
                        error_on_current_token("invalid argument");
                }
            } else {
                // second token of pointer or address
                switch (current()->type) {
                    case TOKEN_TYPE_WORD_LITERAL:
                        argument_vector_push(&arguments, (Argument){
                            .type = ARGUMENT_TYPE_ADDRESS,
                            .first_token = current_argument_start,
                        });
                        valid_argument_start_position = false;
                        break;
                    case TOKEN_TYPE_REGISTER:
                        argument_vector_push(&arguments, (Argument){
                            .type = ARGUMENT_TYPE_POINTER,
                            .first_token = current_argument_start,
                        });
                        valid_argument_start_position = false;
                        break;
                    default:
                        error_on_current_token("invalid argument");
                }
                current_argument_start = NULL;
            }
        }
        next();
    }
    emit_instruction(mnemonic, arguments);
    argument_vector_free(&arguments);
}

void parse_identifier() {
    if (peek()->type == TOKEN_TYPE_COLON) {
        parse_label();
    } else {
        parse_instruction();
    }
}

ByteVector parse(SourceFile const source_file, TokenVector const tokens, OpcodeList const opcodes) {
    assert(tokens.size > 0);
    assert(tokens.data[tokens.size - 1].type == TOKEN_TYPE_EOF);
    if (tokens.size == 1) {
        error(source_file, "empty input", tokens.data[0].line, tokens.data[0].column, 1);
    }
    init_state(source_file, tokens, opcodes);
    while (current()->type != TOKEN_TYPE_EOF) {
        switch (current()->type) {
            case TOKEN_TYPE_IDENTIFIER:
                parse_identifier();
                break;
            case TOKEN_TYPE_NEWLINE:
                break;
            default:
                error_on_current_token("unexpected token");
                break;
        }
        next();
    }
    return cleanup_state();
}
