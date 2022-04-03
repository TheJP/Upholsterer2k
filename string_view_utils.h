#pragma once

#include "types.h"
#include "string_view.h"

typedef enum {
    BASE_DECIMAL = 10,
    BASE_HEXADECIMAL = 16,
    BASE_BINARY = 2,
} Base;

Word parse_word(StringView string_view);
Word parse_word_with_base(StringView const string_view, Base const base);