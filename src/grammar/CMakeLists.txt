cmake_minimum_required(VERSION 3.14)
project(tser-parser)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

set(CMAKE_CXX_STANDARD 17)

# main project root director
get_filename_component(MAIN_PROJECT_ROOT_PATH "${PROJECT_SOURCE_DIR}" PATH)
get_filename_component(MAIN_PROJECT_ROOT_PATH "${MAIN_PROJECT_ROOT_PATH}" PATH)

include_directories(
  ${MAIN_PROJECT_ROOT_PATH}/lib/antlr/include/antlr4-runtime
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
