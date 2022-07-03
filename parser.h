#pragma once

#include <stdint.h>
#include "vector.h"
#include "token_vector.h"
#include "opcodes.h"
#include "source_file.h"
#include "constants.h"

CREATE_VECTOR_DECLARATION(ByteVector, uint8_t, byte_vector)

ByteVector parse(SourceFile source_file, TokenVector tokens, OpcodeList opcodes, ConstantsMap const* constants);
