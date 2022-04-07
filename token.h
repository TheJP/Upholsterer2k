#pragma once

#include <stdlib.h>
#include "string_view.h"
#include "types.h"

typedef enum {
    TOKEN_TYPE_ASTERISK,
    TOKEN_TYPE_COLON,
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_TYPE_STRING_LITERAL,
    TOKEN_TYPE_WORD_LITERAL,
    TOKEN_TYPE_LEFT_BRACKET,
    TOKEN_TYPE_RIGHT_BRACKET,
    TOKEN_TYPE_DOT,
    TOKEN_TYPE_REGISTER,
    TOKEN_TYPE_COMMA,
    TOKEN_TYPE_NEWLINE,
    TOKEN_TYPE_EOF,
} TokenType;

char const* token_type_to_string(TokenType token_type);

typedef struct {
    TokenType type;
    StringView string_view;
    size_t line, column;
} Token;

StringView identifier_from_token(Token const* token);
StringView string_literal_from_token(Token const* token);
Word word_from_token(Token const* token);
Register register_from_token(Token const* token);