# CMakeLists.txt
# src directory

cmake_minimum_required (VERSION 3.8)

add_executable (${OUTPUT_ELF} "Console_Star.cpp")

target_link_libraries (${OUTPUT_ELF} star)