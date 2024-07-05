cmake_minimum_required(VERSION 3.10)

# Set the project name
project(EsperaProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Export compilation database for neovim lsp
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories
include_directories(include)

# Gather all source files
file(GLOB SOURCES "src/*.cpp")

# Add the executable
add_executable(EsperaProject ${SOURCES})

