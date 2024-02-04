add_library(aoc INTERFACE)
add_library(aoc::aoc ALIAS aoc)

target_compile_features(aoc INTERFACE cxx_std_23)

target_compile_options(aoc INTERFACE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

target_include_directories(aoc INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)