cmake_minimum_required(VERSION 3.10)
project(BookCLI VERSION 0.2.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(book
    src/main.cpp
    src/core/shell.cpp
    src/core/dispatcher.cpp
    src/commands/workspace_command.cpp
    src/commands/system_command.cpp
)

target_include_directories(book PRIVATE ${CMAKE_SOURCE_DIR}/include)

install(TARGETS book DESTINATION bin)

set(CPACK_PACKAGE_NAME "Book")
set(CPACK_PACKAGE_VENDOR "Ashish(DrDead0)")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A lightning-fast C++23 developer workspace manager.")
set(CPACK_PACKAGE_VERSION "0.2.0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "BookCLI")
set(CPACK_GENERATOR "NSIS")
set(CPACK_NSIS_MODIFY_PATH ON)

include(CPack)