cmake_minimum_required(VERSION 3.28)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(AOC_MASTER_PROJECT ON)
    message(STATUS "CMake version: ${CMAKE_VERSION}")
endif ()

option(AOC_BUILD_TESTING "build unit tests" AOC_MASTER_PROJECT)

if (AOC_BUILD_TESTING)
    list(APPEND VCPKG_MANIFEST_FEATURES "tests")
endif()

project (advent_of_code 
	LANGUAGES CXX
	VERSION 1.0
)

if (AOC_BUILD_TESTING)
    add_subdirectory(tests)
endif()

add_subdirectory(src)
add_subdirectory(aoc_library)