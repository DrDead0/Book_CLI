cmake_minimum_required(VERSION 3.10)

project(BookCLI VERSION 0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(book src/main.cpp src/shell/shell.cpp src/command/workspace.cpp)
target_include_directories(book PRIVATE ${CMAKE_SOURCE_DIR}/include)