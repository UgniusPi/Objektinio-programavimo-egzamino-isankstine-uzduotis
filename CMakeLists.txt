cmake_minimum_required(VERSION 3.10)
project(ObjektinioProgramavimoUzduotis VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a small static library for shared utilities
add_library(utils STATIC
    text_utils.cpp
    url_utils.cpp
)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(word_counter main.cpp)
target_link_libraries(word_counter PRIVATE utils)

add_executable(url_finder url.cpp)
target_link_libraries(url_finder PRIVATE utils)

option(BUILD_TESTS "Build unit tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
