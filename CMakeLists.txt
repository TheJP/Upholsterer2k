# project (global) CMakeLists.txt file

cmake_minimum_required (VERSION 3.8)

project("Upholsterer2k")

# set C language standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

#set ouput directories
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib )

set (TARGET_NAME Main)

add_executable (
    ${TARGET_NAME}
    "main.c"
    "string_view_utils.c"
    "string_view_utils.h"
    "string_view.h"
    "token.c"
    "token.h"
    "types.h"
)

# set binary filenames
set_target_properties( ${TARGET_NAME} PROPERTIES OUTPUT_NAME_DEBUG ${TARGET_NAME}-debug )
set_target_properties( ${TARGET_NAME} PROPERTIES OUTPUT_NAME_RELWITHDEBINFO ${TARGET_NAME}-relwidthdebinfo )
set_target_properties( ${TARGET_NAME} PROPERTIES OUTPUT_NAME_RELEASE ${TARGET_NAME}-release )
set_target_properties( ${TARGET_NAME} PROPERTIES OUTPUT_NAME_MINSIZEREL ${TARGET_NAME}-minsizerel )

# set warning levels
target_compile_options(${TARGET_NAME} PUBLIC -Wall -Wextra -Wconversion -pedantic)