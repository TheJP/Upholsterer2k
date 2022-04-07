#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "token_vector.h"

TokenVector token_vector_create(void) {
    return (TokenVector){
        .data = NULL,
        .size = 0,
        .capacity = 0,
    };
}

static void grow(TokenVector* const vector) {
    vector->capacity = vector->capacity == 0 ? 1 : vector->capacity * 2;
    Token* new_data = realloc(vector->data, sizeof(Token) * vector->capacity);
    if (!new_data) {
        fprintf(stderr, "Unable to allocate memory\n");
        free(vector->data);
        exit(EXIT_FAILURE);
    }
    vector->data = new_data;
}

void token_vector_push(TokenVector* const vector, Token token) {
    bool const needs_to_grow = vector->size == vector->capacity;
    if (needs_to_grow) {
        grow(vector);
    }
    vector->data[vector->size] = token;
    ++vector->size;
}

void token_vector_free(TokenVector* const vector) {
    free(vector->data);
    vector->size = 0;
    vector->capacity = 0;
}