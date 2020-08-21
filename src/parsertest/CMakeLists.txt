cmake_minimum_required(VERSION 3.14)
project(tser)
set(CMAKE_CXX_STANDARD 14)

set(ANTLR_EXECUTABLE $ENV{ANTLR_EXECUTABLE})

include_directories(
  $ENV{ANTLR_RUNTIME}/include
)
include_directories(
  ${PROJECT_SOURCE_DIR}/../src
)

# llvm编译选项
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})

file(GLOB src_files
  ${PROJECT_SOURCE_DIR}/../src/grammar/*.cpp
  )
  
file(GLOB debug_files
  ${PROJECT_SOURCE_DIR}/../src/perf/*.cpp
)

# LINK_DIRECTORIES($ENV{ANTLR_RUNTIME}/lib)

llvm_map_components_to_libnames(llvm_libs support core orcjit irreader nativecodegen)

add_executable(tser ${src_files} ${debug_files})
# target_link_libraries(tser $ENV{ANTLR_RUNTIME}/lib/libantlr4-runtime.a ${llvm_libs})