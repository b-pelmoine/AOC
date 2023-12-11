add_executable (aoc-2023)

target_sources(aoc-2023
  PUBLIC
  main.cpp
  day_01.cpp
)

target_link_libraries(aoc-2023
    PUBLIC 
        aoc::aoc
)

target_compile_features(aoc-2023 PUBLIC cxx_std_23)

target_compile_options(aoc-2023 PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

target_include_directories(aoc-2023 ${WARNING_GUARD} PUBLIC 
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)