﻿# CMakeLists.txt
# Root directory of project Console_Star

cmake_minimum_required (VERSION 3.8)

project (Console_Star VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 17)

set (OUTPUT_ELF ${CMAKE_PROJECT_NAME}-${PROJECT_VERSION})

set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory (src)
add_subdirectory (src/lib)