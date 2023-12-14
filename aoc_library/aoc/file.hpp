#pragma once

#include "aoc/types.hpp"

#include <fstream>
#include <iterator>
#include <optional>

namespace aoc {
inline constexpr auto s_inputs_directory = std::string_view{ "inputs" };
inline constexpr auto s_test_inputs_directory = std::string_view{ "inputs/test" };

static std::optional<std::string> read_file(std::filesystem::path _path)
{
  auto file = std::ifstream{ _path, std::ios::in };

  if (!file.is_open())
    return {};

  using Iterator = std::istreambuf_iterator<char>;
  auto buffer = std::string{ Iterator{ file }, Iterator{} };

  return buffer;
}

template<part_flags _parts> static std::optional<std::string> solve(solvable auto &&_problem)
{
  return read_file(_problem.get_input_path()).transform([&](auto &&_input) {
    return _problem.solve(std::move(_input), _parts);
  });
}

template<part_flags _parts> static std::optional<std::string> test(testable auto &&_problem)
{
  return read_file(_problem.get_test_input_path()).transform([&](auto &&_input) {
    return _problem.test(std::move(_input), _parts);
  });
}
}// namespace aoc
