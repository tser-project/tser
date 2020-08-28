cmake_minimum_required(VERSION 3.14)
project(tser)

set(CMAKE_C_COMPILER $ENV{CC})
set(CMAKE_CXX_COMPILER $ENV{CXX})
set(CMAKE_CXX_STANDARD 17)
set(Boost_USE_STATIC_LIBS ON)

add_compile_options(-std=c++17)
add_compile_options(-stdlib=libc++)

# mark llvm is built for debug
set(LLVM_BUILD_DEBUG false)
set(TSER_TARGET_MAC true)

# custom config
configure_file(
  "${PROJECT_SOURCE_DIR}/src/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)

include_directories(
  ${PROJECT_BINARY_DIR} # for config.h
  ${PROJECT_SOURCE_DIR}/lib/antlr/include/antlr4-runtime
  ${PROJECT_SOURCE_DIR}/src
)

# Add LLVM config
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
llvm_map_components_to_libnames(llvm_libs support core orcjit nativecodegen)

# src files
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
  ${PROJECT_SOURCE_DIR}/src/perf/*.cpp
)

# Boost
set(boost_min_ver 1.50.0)
set(boost_libs system filesystem)
find_package(Boost ${boost_min_ver})

if(Boost_FOUND)
    find_package(Boost ${boost_min_ver} COMPONENTS ${boost_libs})
endif()

# target
add_executable(tser ${src_files})

target_link_libraries(tser
  ${PROJECT_SOURCE_DIR}/lib/antlr/lib/libantlr4-runtime.a
  ${Boost_LIBRARIES}
  ${PROJECT_SOURCE_DIR}/src/grammar/build/libtser-parser.a
  ${llvm_libs}
)
