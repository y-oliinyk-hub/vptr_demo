cmake_minimum_required(VERSION 4.1)
project(MyCProject VERSION 1.0.0 LANGUAGES C)

# Use standard C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF) # Keep it pure C, no compiler-specific fluff

# Automatically find all source files in the src directory
file(GLOB_RECURSE SOURCES "src/*.c")

# Create the executable
add_executable(vptr_demo ${SOURCES})

# Tell CMake where to find header files
target_include_directories(vptr_demo PRIVATE include)

# Add strict warning flags to keep code clean
if(MSVC)
    target_compile_options(vptr_demo PRIVATE /W4 /WX)
else()
    target_compile_options(vptr_demo PRIVATE -Wall -Wextra -Werror)
endif()
