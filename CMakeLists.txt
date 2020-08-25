cmake_minimum_required(VERSION 3.14)
project(tser)

set(CMAKE_C_COMPILER $ENV{CC})
set(CMAKE_CXX_COMPILER $ENV{CXX})
set(CMAKE_CXX_STANDARD 17)

add_compile_options(-std=c++17)
add_compile_options(-stdlib=libc++)

# mark llvm is built for debug
set(LLVM_BUILD_DEBUG false)
set(TSER_TARGET_MAC true)

set(ANTLR_EXECUTABLE $ENV{ANTLR_EXECUTABLE})

configure_file(
  "${PROJECT_SOURCE_DIR}/src/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)

include_directories(
  ${PROJECT_BINARY_DIR}
)

include_directories(
  $ENV{ANTLR_RUNTIME}/include/antlr4-runtime
)
include_directories(
  ${PROJECT_SOURCE_DIR}/src
)

# llvm
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})

file(GLOB src_files
  ${PROJECT_SOURCE_DIR}/src/*.cpp
  ${PROJECT_SOURCE_DIR}/src/utils/*.cpp
  ${PROJECT_SOURCE_DIR}/src/scope/*.cpp
  ${PROJECT_SOURCE_DIR}/src/ffi/*.cpp
  ${PROJECT_SOURCE_DIR}/src/visit/*.cpp
  ${PROJECT_SOURCE_DIR}/src/visit/reference/*.cpp
  ${PROJECT_SOURCE_DIR}/src/visit/function/*.cpp
  ${PROJECT_SOURCE_DIR}/src/visit/expression/*.cpp
  ${PROJECT_SOURCE_DIR}/src/visit/class/*.cpp
  ${PROJECT_SOURCE_DIR}/src/visit/iteration/*.cpp
  ${PROJECT_SOURCE_DIR}/src/common/error/*.cpp
)
  
file(GLOB debug_files
  ${PROJECT_SOURCE_DIR}/src/perf/*.cpp
)

llvm_map_components_to_libnames(llvm_libs support core orcjit nativecodegen)

add_executable(tser
  ${src_files}
  ${debug_files}
)

target_link_libraries(tser
  $ENV{ANTLR_RUNTIME}/lib/libantlr4-runtime.a
  ${PROJECT_SOURCE_DIR}/src/grammar/build/libtser-parser.a
  ${llvm_libs}
)
