#pragma once

#include "token.h"

typedef struct {
    Token* data;
    size_t size, capacity;
} TokenVector;

TokenVector token_vector_create(void);
void token_vector_push(TokenVector* vector, Token token);
void token_vector_free(TokenVector* vector);
