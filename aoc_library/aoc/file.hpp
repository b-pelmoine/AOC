#pragma once

#include "aoc/types.hpp"

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <optional>
#include <string>
#include <string_view>

namespace aoc {
inline constexpr auto s_inputs_directory = std::string_view{ "inputs" };
inline constexpr auto s_example_inputs_directory = std::string_view{ "inputs\\example" };

static std::optional<std::string> read_file(std::filesystem::path _path)
{
  auto file = std::ifstream{ _path, std::ios::in };

  if (!file.is_open())
    return {};

  using istream_it = std::istreambuf_iterator<char>;
  return std::string{ istream_it{ file }, istream_it{} };
}

auto solve_and_mesure_duration_for(auto &&_input, aoc::part _part, auto &&_problem)
{
  using day_t = std::remove_cvref_t<decltype(_problem)>;
  using input_t = decltype(_input);

  struct res_and_duration
  {
    decltype(std::declval<day_t>().solve(std::declval<input_t>(), std::declval<aoc::part>())) result;
    std::chrono::nanoseconds duration;
  };

  const auto start = std::chrono::high_resolution_clock::now();
  const auto res = _problem.solve(std::move(_input), _part);
  const auto stop = std::chrono::high_resolution_clock::now();

  return res_and_duration{ res, stop - start };
}

template<aoc::part _part> static auto solve(solvable auto &&_problem)
{
  return read_file(_problem.get_input_path()).transform([&](auto &&_input) {
    return solve_and_mesure_duration_for(std::move(_input), _part, _problem);
  });
}

template<aoc::part _part> static auto solve_example(testable auto &&_problem)
{
  return read_file(_problem.get_example_input_path()).transform([&](auto &&_input) {
    return solve_and_mesure_duration_for(std::move(_input), _part, _problem);
  });
}
}// namespace aoc
