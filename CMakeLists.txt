cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(LIBRARYLOADER VERSION 0.1.0 LANGUAGES CXX)

add_library(mylib SHARED ./example/mylib/private/box_impl.cpp)
add_library(mylib_wrapper STATIC ./example/mylib/mylib.cpp ./example/mylib/Box.cpp)
target_include_directories(mylib_wrapper PRIVATE ./include)

add_executable(Example ./example/example.cpp)
target_link_libraries(Example PRIVATE mylib_wrapper)
target_include_directories(Example PRIVATE ./include)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(Example PRIVATE -static-libstdc++)
    target_compile_options(Example PRIVATE -Wall)
    target_compile_options(Example PRIVATE -pedantic)
endif()

