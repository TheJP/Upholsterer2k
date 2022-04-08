#pragma once

#include <stdlib.h>
#include "string_view.h"
#include "types.h"

#define TOKEN_TYPE_LIST \
    X(TOKEN_TYPE_ASTERISK) \
    X(TOKEN_TYPE_COLON) \
    X(TOKEN_TYPE_IDENTIFIER) \
    X(TOKEN_TYPE_STRING_LITERAL) \
    X(TOKEN_TYPE_WORD_LITERAL) \
    X(TOKEN_TYPE_LEFT_BRACKET) \
    X(TOKEN_TYPE_RIGHT_BRACKET) \
    X(TOKEN_TYPE_DOT) \
    X(TOKEN_TYPE_REGISTER) \
    X(TOKEN_TYPE_COMMA) \
    X(TOKEN_TYPE_NEWLINE) \
    X(TOKEN_TYPE_EOF)

typedef enum {
    #define X(type) type,
    TOKEN_TYPE_LIST
    #undef X
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