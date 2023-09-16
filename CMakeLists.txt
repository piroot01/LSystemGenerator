# Project header
cmake_minimum_required(VERSION 3.27)
project(LSystemGenerator VERSION 0.1.0 )

# Compiler settings
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -O1")
set(CMAKE_BUILD_TYPE Debug)

# The project
add_subdirectory(${PROJECT_NAME})

# The tests
add_subdirectory(tests)
