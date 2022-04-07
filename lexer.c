#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "lexer.h"

static void error(char* message, size_t line, size_t column) {
    fprintf(stderr, "Error at line %zu:%zu: %s\n", line, column, message);
    exit(EXIT_FAILURE); // no memory cleanup? ¯\_(ツ)_/¯
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
            case 'R':
            case 'r':
                // register
                break;
            case '"':
                // string literals
                break;
            default:
                if (isdigit(*current)) { // word literal
                    
                } else { // identifier

                }
                break;
        }
        ++current;
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