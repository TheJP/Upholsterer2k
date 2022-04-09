#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "lexer.h"

typedef enum {
    DECIMAL,
    HEXADECIMAL,
    BINARY,
    UNKNOWN,
} WordLiteralType;

static void error(char* message, size_t line, size_t column) {
    fprintf(stderr, "Error at line %zu:%zu: %s\n", line, column, message);
    exit(EXIT_FAILURE); // no memory cleanup? ¯\_(ツ)_/¯
}

static size_t minimum_required_length(WordLiteralType type) {
    switch (type) {
        case DECIMAL:
            return 1;
        case HEXADECIMAL:
        case BINARY:
            return 3;
        default:
            return 0;
    }
}

static bool is_valid_digit(char const c, WordLiteralType base) {
    switch (base) {
        case DECIMAL:
            return isdigit(c);
        case HEXADECIMAL:
            return isxdigit(c);
        case BINARY:
            return c == '0' || c == '1';
        case UNKNOWN:
            return false;
        default:
            assert(false && "invalid base");
            return false;
    }
}

static bool is_valid_identifier_start_char(char const c) {
    return isalpha(c) || c == '_' || c == '$';
}

static bool is_valid_identifier_inner_char(char const c) {
    return is_valid_identifier_start_char(c) || isdigit(c);
}

TokenVector tokenize(StringView source) {
    TokenVector tokens = token_vector_create();
    if (source.length == 0) {
        return tokens;
    }
    char* current = source.data;
    char* const end = source.data + source.length;
    size_t line = 0;
    size_t column = 0;
    while (current != end) {
        ++column;
        switch (*current) {
            case '\n':
                if (tokens.size == 0 || tokens.data[tokens.size - 1].type != TOKEN_TYPE_NEWLINE) {
                    token_vector_push(&tokens, (Token){
                        .type = TOKEN_TYPE_NEWLINE,
                        .string_view = {
                            .data = current,
                            .length = 1,
                        },
                        .column = column,
                        .line = line,
                    });
                }
                ++line;
                column = 0;
                break;
            case '*':
                token_vector_push(&tokens, (Token){
                    .type = TOKEN_TYPE_ASTERISK,
                    .string_view = {
                        .data = current,
                        .length = 1,
                    },
                    .column = column,
                    .line = line,
                });
                break;
            case ':':
                token_vector_push(&tokens, (Token){
                    .type = TOKEN_TYPE_COLON,
                    .string_view = {
                        .data = current,
                        .length = 1,
                    },
                    .column = column,
                    .line = line,
                });
                break;
            case '.':
                token_vector_push(&tokens, (Token){
                    .type = TOKEN_TYPE_DOT,
                    .string_view = {
                        .data = current,
                        .length = 1,
                    },
                    .column = column,
                    .line = line,
                });
                break;
            case ',':
                token_vector_push(&tokens, (Token){
                    .type = TOKEN_TYPE_COMMA,
                    .string_view = {
                        .data = current,
                        .length = 1,
                    },
                    .column = column,
                    .line = line,
                });
                break;
            case '[':
                token_vector_push(&tokens, (Token){
                    .type = TOKEN_TYPE_LEFT_BRACKET,
                    .string_view = {
                        .data = current,
                        .length = 1,
                    },
                    .column = column,
                    .line = line,
                });
                break;
            case ']':
                token_vector_push(&tokens, (Token){
                    .type = TOKEN_TYPE_RIGHT_BRACKET,
                    .string_view = {
                        .data = current,
                        .length = 1,
                    },
                    .column = column,
                    .line = line,
                });
                break;
            case '/':
                ++current;
                if (current == end || *current != '/') {
                    error("'/' expected", line, column);
                }
                while (current != end && *current != '\n') {
                    ++current;
                }
                column = 0;
                ++line;
                break;
            case '"':
                // string literals
                break;
            default:
                if (isspace(*current)) {
                    // do nothing
                } else if ((*current == 'r' || *current == 'R') && current + 1 != end && isdigit(*(current + 1))) {
                    // register
                    char* const register_start = current;
                    ++current;
                    ++column;
                    while (current != end && isdigit(*current)) {
                        ++current;
                        ++column;
                    }
                    token_vector_push(&tokens, (Token){
                        .type = TOKEN_TYPE_REGISTER,
                        .string_view = string_view_from_pointers(register_start, current),
                        .line = line,
                        .column = column,
                    });
                    --current;
                    --column;
                } else if (isdigit(*current)) {
                    // word literal
                    if (current + 1 == end) {
                        // reached EOF
                        token_vector_push(&tokens, (Token){
                            .type = TOKEN_TYPE_WORD_LITERAL,
                            .string_view = {
                                .data = current,
                                .length = 1,
                            },
                            .column = column,
                            .line = line,
                        });
                    } else {
                        char* const literal_start = current;
                        ++current;
                        ++column;
                        WordLiteralType word_literal_type;
                        switch (*current) {
                            case 'x':
                                ++current;
                                ++column;
                                word_literal_type = HEXADECIMAL;
                                break;
                            case 'b':
                                ++current;
                                ++column;
                                word_literal_type = BINARY;
                                break;
                            default:
                                word_literal_type = isdigit(*current) ? DECIMAL : UNKNOWN;
                                break;
                        }
                        while (current != end && is_valid_digit(*current, word_literal_type)) {
                            ++current;
                            ++column;
                        }
                        size_t const literal_length = (size_t)(current - literal_start);
                        if (literal_length < minimum_required_length(word_literal_type)) {
                            error("end of word literal unexpected", line, column);
                        }
                        token_vector_push(&tokens, (Token){
                            .type = TOKEN_TYPE_WORD_LITERAL,
                            .string_view = {
                                .data = literal_start,
                                .length = literal_length,
                            },
                            .column = column,
                            .line = line,
                        });
                        --current;
                        --column;
                    }
                } else if (is_valid_identifier_start_char(*current)) {
                    // identifier
                    char* const identifier_start = current;
                    ++current;
                    ++column;
                    while (current != end && is_valid_identifier_inner_char(*current)) {
                        ++current;
                        ++column;
                    }
                    token_vector_push(&tokens, (Token){
                        .type = TOKEN_TYPE_IDENTIFIER,
                        .string_view = string_view_from_pointers(identifier_start, current),
                        .line = line,
                        .column = column,
                    });
                    --current;
                    --column;
                } else {
                    error("unexpected input", line, column);
                }
                break;
        }
        ++current;
        ++column;
    }
    token_vector_push(&tokens, (Token){
        .type = TOKEN_TYPE_EOF,
        .string_view = {
            .data = NULL,
            .length = 0,
        },
        .column = column,
        .line = line,
    });
    return tokens;
}
