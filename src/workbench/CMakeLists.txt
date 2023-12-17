add_executable(aoc-workbench)

target_sources(aoc-workbench
    PUBLIC
        main.cpp
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