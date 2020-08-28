cmake_minimum_required(VERSION 3.14)
project(tser)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

set(CMAKE_CXX_STANDARD 17)

# main project root director
get_filename_component(MAIN_PROJECT_ROOT_PATH "${PROJECT_SOURCE_DIR}" PATH)
get_filename_component(MAIN_PROJECT_ROOT_PATH "${MAIN_PROJECT_ROOT_PATH}" PATH)

add_compile_options(-std=c++17)
add_compile_options(-stdlib=libc++)
add_compile_options(-o)

# llvm
find_package(LLVM REQUIRED CONFIG)

include_directories(
  ${MAIN_PROJECT_ROOT_PATH}/src
  ${MAIN_PROJECT_ROOT_PATH}/build
  ${MAIN_PROJECT_ROOT_PATH}/lib/antlr/include/antlr4-runtime
  ${LLVM_INCLUDE_DIRS}
)

file(GLOB src_files
  ${PROJECT_SOURCE_DIR}/*.cpp
)

add_library(builtin OBJECT ${src_files})
