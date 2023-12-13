add_subdirectory(aoc_2023)

add_library(all-aoc INTERFACE)
add_library(aoc::all ALIAS all-aoc)

target_link_libraries(all-aoc
    INTERFACE 
        aoc::aoc-2023
)

target_compile_features(all-aoc INTERFACE cxx_std_23)

target_compile_options(all-aoc INTERFACE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

target_include_directories(all-aoc ${WARNING_GUARD} INTERFACE 
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)

add_executable(all-aoc-selector)

target_sources(all-aoc-selector
    PUBLIC
        main.cpp
)

target_link_libraries(all-aoc-selector
    PUBLIC 
        aoc::all
)

target_compile_features(all-aoc-selector PUBLIC cxx_std_23)

target_compile_options(all-aoc-selector PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

target_include_directories(all-aoc-selector ${WARNING_GUARD} PUBLIC 
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)

  
add_executable(aoc-workbench)

target_sources(aoc-workbench
    PUBLIC
        workbench.cpp
)

target_link_libraries(aoc-workbench
    PUBLIC 
        aoc::all
)

target_compile_features(aoc-workbench PUBLIC cxx_std_23)

target_compile_options(aoc-workbench PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

target_include_directories(aoc-workbench ${WARNING_GUARD} PUBLIC 
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)