#include "token.h"
#include "string_view_utils.h"
#include <assert.h>

StringView identifier_from_token(Token const * const token) {
    assert(token->type == IDENTIFIER);
    return token->string_view;
}

StringView string_literal_from_token(Token const * const token) {
    assert(token->type == STRING_LITERAL);
    return (StringView){
        .data = token->string_view.data + 1,
        .length = token->string_view.length - 2,
    };
}

Word word_from_token(Token const * const token) {
    assert(token->type == WORD_LITERAL);
    return parse_word(token->string_view);
}

Register register_from_token(Token const * const token) {
    assert(token->type == REGISTER);
    
}