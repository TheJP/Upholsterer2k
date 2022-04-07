#pragma once

#include <stdlib.h>
#include "string_view.h"
#include "types.h"

typedef enum {
    ASTERISK,
    COLON,
    IDENTIFIER,
    STRING_LITERAL,
    WORD_LITERAL,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    DOT,
    REGISTER,
    COMMA,
    NEWLINE,
    EOF,
} TokenType;

typedef struct {
    TokenType type;
    StringView string_view;
    size_t row, column;
} Token;

StringView identifier_from_token(Token const* token);
StringView string_literal_from_token(Token const* token);
Word word_from_token(Token const* token);
Register register_from_token(Token const* token);