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

add_subdirectory(workbench)
