#include "opcode_specification.h"
#include <string.h>
#include <assert.h>

char* opcode_to_mnemonic(char const * const opcode) {
    #define X(code, mnemonic) if (strcmp(opcode, #code) == 0) return #mnemonic ;
    OPCODE_MAPPINGS
    #undef X
    return NULL;
}
