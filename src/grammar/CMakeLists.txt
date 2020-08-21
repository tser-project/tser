cmake_minimum_required(VERSION 3.14)
project(tser-parser)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

set(CMAKE_CXX_STANDARD 17)

set(ANTLR_EXECUTABLE $ENV{ANTLR_EXECUTABLE})

include_directories(
  $ENV{ANTLR_RUNTIME}/include/antlr4-runtime
)

include_directories(
  ./
)

file(GLOB parser_files
  ./*.cpp
)

add_library(tser-parser STATIC
  ${parser_files}
)
