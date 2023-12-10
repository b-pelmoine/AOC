cmake_minimum_required(VERSION 3.28)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(AOC_MASTER_PROJECT ON)
    message(STATUS "CMake version: ${CMAKE_VERSION}")
endif ()

project (advent_of_code 
	LANGUAGES CXX
	VERSION 1.0
)

add_subdirectory(src)
add_subdirectory(aoc_library)