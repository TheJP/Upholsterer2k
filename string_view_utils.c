#include <stdbool.h>
#include <assert.h>
#include "string_view_utils.h"

Word char_value(char c) {
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return (Word)(c - '0');
        case 'a':
        case 'A':
            return 10;
        case 'b':
        case 'B':
            return 11;
        case 'c':
        case 'C':
            return 12;
        case 'd':
        case 'D':
            return 13;
        case 'e':
        case 'E':
            return 14;
        case 'f':
        case 'F':
            return 15;
        default:
            assert(false && "unexpected character in string");
            break;
    }
}

Word parse_word_with_base(StringView const string_view, Base const base) {
    Word current_factor = 1;
    Word result = 0;
    for (size_t i = 0; i < string_view.length; ++i) {
        size_t const index = string_view.length - i - 1;
        result += char_value(string_view.data[index]) * current_factor;
        current_factor *= (Word)base;
    }
    return result;
}

StringView strip_prefix(StringView const string_view) {
    return (StringView){
        .data = string_view.data + 2,
        .length = string_view.length - 2,
    };
}

Word parse_word(StringView const string_view) {
    bool const may_have_prefix = string_view.length > 2;
    if (may_have_prefix) {
        switch (string_view.data[1]) {
            case 'x':
                return parse_word_with_base(strip_prefix(string_view), BASE_HEXADECIMAL);
            case 'b':
                return parse_word_with_base(strip_prefix(string_view), BASE_BINARY);
            default:
                return parse_word_with_base(strip_prefix(string_view), BASE_DECIMAL);
        }
    }
    return parse_word_with_base(strip_prefix(string_view), BASE_DECIMAL);
}