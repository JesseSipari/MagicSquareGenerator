cmake_minimum_required(VERSION 3.31)
project(magic_squares)

set(CMAKE_CXX_STANDARD 20)

# Set default build type if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add source files (expandable)
file(GLOB SOURCES "*.cpp")

add_executable(magic_squares ${SOURCES})
