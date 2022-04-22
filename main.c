#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include "lexer.h"
#include "string_view.h"
#include "source_file.h"
#include "opcodes.h"
#include "parser.h"

StringView read_whole_file(FILE* const file) {
    size_t capacity = 0;
    size_t size = 0;
    char* buffer = NULL;
    int current_char;
    while ((current_char = fgetc(file)) != EOF) {
        if (size == capacity) { // needs to resize
            capacity = capacity == 0 ? 1 : 2 * capacity;
            char* const new_buffer = realloc(buffer, capacity);
            if (new_buffer == NULL) {
                free(buffer);
                return (StringView){
                    .data = NULL,
                    .length = 0,
                };
            }
            buffer = new_buffer;
        }
        buffer[size] = (char)current_char;
        ++size;
    }
    return (StringView){
        .data = buffer,
        .length = size,
    };
}

void write_machine_code(ByteVector machine_code, FILE* const file) {
    fwrite(machine_code.data, sizeof(uint8_t), machine_code.size, file);
}

void check_opcodes(OpcodeList const opcodes) {
    for (size_t i = 0; i < opcodes.num_specifications; ++i) {
        OpcodeSpecification const * const specification = &opcodes.specifications[i];
        assert(specification->mnemonic.length > 0 && "unknown opcode");
    }
}

int main(int argc, char** argv) {
    StringView source = { 0 };
    if (argc == 1) {
        source = read_whole_file(stdin);
    } else if (argc == 2) {
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Could not open file %s: %s.\n", argv[1], strerror(errno));
            return EXIT_FAILURE;
        }
        source = read_whole_file(file);
        fclose(file);
    } else {
        fprintf(stderr, "Usage: %s [SOURCEFILE]\n", argv[0]);
        return EXIT_FAILURE;
    }
    SourceFile source_file = {
        .filename = string_view_from_string(argc == 1 ? "<stdin>" : argv[1]),
        .source = source,
    };

    TokenVector tokens = tokenize(source_file);

    OpcodeList opcodes = opcode_specifications();
    check_opcodes(opcodes);

    ByteVector machine_code = parse(source_file, tokens, opcodes);

    write_machine_code(machine_code, stdout);

    // cleanup
    byte_vector_free(&machine_code);
    token_vector_free(&tokens);
    free(source.data);
    free(opcodes.specifications);
    return EXIT_SUCCESS;
}
