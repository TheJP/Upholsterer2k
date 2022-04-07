#include "token.h"
#include "string_view_utils.h"
#include <assert.h>

#define TOKEN_TYPE_CASE(type) case type : return #type

char const* token_type_to_string(TokenType token_type) {
    switch (token_type) {
        TOKEN_TYPE_CASE(TOKEN_TYPE_ASTERISK);
        TOKEN_TYPE_CASE(TOKEN_TYPE_COLON);
        TOKEN_TYPE_CASE(TOKEN_TYPE_IDENTIFIER);
        TOKEN_TYPE_CASE(TOKEN_TYPE_STRING_LITERAL);
        TOKEN_TYPE_CASE(TOKEN_TYPE_WORD_LITERAL);
        TOKEN_TYPE_CASE(TOKEN_TYPE_LEFT_BRACKET);
        TOKEN_TYPE_CASE(TOKEN_TYPE_RIGHT_BRACKET);
        TOKEN_TYPE_CASE(TOKEN_TYPE_DOT);
        TOKEN_TYPE_CASE(TOKEN_TYPE_REGISTER);
        TOKEN_TYPE_CASE(TOKEN_TYPE_COMMA);
        TOKEN_TYPE_CASE(TOKEN_TYPE_NEWLINE);
        TOKEN_TYPE_CASE(TOKEN_TYPE_EOF);
        default:
            return "unknown token type";
    }
}

#undef TOKEN_TYPE_CASE

StringView identifier_from_token(Token const * const token) {
    assert(token->type == TOKEN_TYPE_IDENTIFIER);
    return token->string_view;
}

StringView string_literal_from_token(Token const * const token) {
    assert(token->type == TOKEN_TYPE_STRING_LITERAL);
    return (StringView){
        .data = token->string_view.data + 1,
        .length = token->string_view.length - 2,
    };
}

Word word_from_token(Token const * const token) {
    assert(token->type == TOKEN_TYPE_WORD_LITERAL);
    return parse_word(token->string_view);
}

Register register_from_token(Token const * const token) {
    assert(token->type == TOKEN_TYPE_REGISTER);
    // TODO
}