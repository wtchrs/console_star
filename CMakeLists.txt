# CMakeList.txt : CMake project for Console_Star, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(Console_Star VERSION 0.1.0)

# Add source to this project's executable.
add_executable (Console_Star "Console_Star.cpp" "Console_Star.h" "star.cpp" "star.h")

# TODO: Add tests and install targets if needed.
