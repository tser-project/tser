cmake_minimum_required(VERSION 3.14)
project(tser)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

set(CMAKE_CXX_STANDARD 17)

SET(PROJECT_ROOT_PATH "${PROJECT_SOURCE_DIR}/../")   

add_compile_options(-std=c++17)
add_compile_options(-stdlib=libc++)
add_compile_options(-o)

include_directories(
  ${PROJECT_ROOT_PATH}
  ${PROJECT_ROOT_PATH}/../build
)

# antlr
include_directories(
  $ENV{ANTLR_RUNTIME}/include/antlr4-runtime
)

# llvm
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})

file(GLOB src_files
  ${PROJECT_SOURCE_DIR}/*.cpp
)

add_library(builtin OBJECT ${src_files})
