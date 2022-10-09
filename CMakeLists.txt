# project (global) CMakeLists.txt file

cmake_minimum_required (VERSION 3.8)

project("Upholsterer2k" VERSION 0.1.0 DESCRIPTION "the official assembler for the backseat safe system 2k")

# set C language standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if (MSVC)
    # enable code analysis
    set_property(GLOBAL PROPERTY VS_GLOBAL_EnableCppCoreCheck true)
    set_property(GLOBAL PROPERTY VS_GLOBAL_CodeAnalysisRuleSet CppCoreCheckRules.ruleset)
    set_property(GLOBAL PROPERTY VS_GLOBAL_RunCodeAnalysis true)

    # remove /W3 from defaults
    string(REGEX REPLACE "/W3" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
    string(REGEX REPLACE "-W3" "" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
endif ()

#set ouput directories
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib )

set(FILES
    "main.c"
    "string_view_utils.c"
    "string_view_utils.h"
    "string_view.h"
    "string_view.c"
    "token.c"
    "token.h"
    "types.h"
    "token_vector.h"
    "token_vector.c"
    "lexer.h"
    "lexer.c"
    "source_file.h"
    "error.h"
    "error.c"
    "opcode_specification.h"
    "opcode_specification.c"
    "opcodes.h"
    "opcodes.c"
    "vector.h"
    "parser.h"
    "parser.c"
    "constants.h"
    "constants.c"
    "constant_abbreviations.c"
    "constants_helpers.c"
    "hashmap.h"
    "hashmap.c"
)

set(TARGET_LIST "Upholsterer2k" "Upholsterer2kLib")

add_executable(
    Upholsterer2k
    ${FILES}
)

add_library(
    Upholsterer2kLib SHARED
    ${FILES}
)

set_target_properties(Upholsterer2kLib PROPERTIES PUBLIC_HEADER upholsterer2k.h)
target_include_directories(Upholsterer2kLib PRIVATE .)

include(GNUInstallDirs)

install(TARGETS Upholsterer2kLib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

foreach (target ${TARGET_LIST})
    # set warning levels
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        target_compile_options(${target} PUBLIC /W4 /permissive-)
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(${target} PUBLIC -Wall -Wextra -Wconversion -Wswitch -Wimplicit-fallthrough -pedantic -Werror)
        target_link_options(${target} PUBLIC)
    endif ()

    # define DEBUG_BUILD
    target_compile_definitions(${target} PUBLIC "$<$<CONFIG:DEBUG>:DEBUG_BUILD>")
endforeach ()
