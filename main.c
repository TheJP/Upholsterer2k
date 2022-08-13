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

#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif

void read_whole_file(FILE* const file, char** contents, size_t* length) {
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
                *contents = NULL;
                *length = 0;
                return;
            }
            buffer = new_buffer;
        }
        buffer[size] = (char)current_char;
        ++size;
    }
    *contents = buffer;
    *length = size;
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
    char* source_data = NULL;
    StringView source = { 0 };
    if (argc == 1) {
        size_t length;
        read_whole_file(stdin, &source_data, &length);
        source = (StringView){ .data = source_data, .length = length };
    } else if (argc == 2) {
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Could not open file %s: %s.\n", argv[1], strerror(errno));
            return EXIT_FAILURE;
        }
        size_t length;
        read_whole_file(file, &source_data, &length);
        fclose(file);
        source = (StringView){ .data = source_data, .length = length };
    } else {
        fprintf(stderr, "Usage: %s [SOURCEFILE]\n", argv[0]);
        return EXIT_FAILURE;
    }
    SourceFile source_file = {
        .filename = string_view_from_string(argc == 1 ? "<stdin>" : argv[1]),
        .source = source,
    };

    ConstantsMap constants = constants_map_create(16);
    fill_constants_map(&constants);

    TokenVector tokens = tokenize(source_file, &constants);

    OpcodeList opcodes = opcode_specifications();
    check_opcodes(opcodes);

    ByteVector machine_code = parse(source_file, tokens, opcodes, &constants);

    // when in windows, we have to set the mode of stdout to binary because otherwise
    // every \n will be automatically replaced with \r\n which destroys the generated
    // binary
#ifdef _WIN32
    _setmode(_fileno(stdout), _O_BINARY);
#endif

    write_machine_code(machine_code, stdout);

    // cleanup
    byte_vector_free(&machine_code);
    token_vector_free(&tokens);
    constants_map_free(&constants);
    free(source_data);
    free(opcodes.specifications);
    return EXIT_SUCCESS;
}
