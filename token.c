#include "token.h"
#include "string_view_utils.h"
#include <assert.h>

char const* token_type_to_string(TokenType token_type) {
    switch (token_type) {
        #define X(type) case type : return #type ;
        TOKEN_TYPE_LIST
        #undef X
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