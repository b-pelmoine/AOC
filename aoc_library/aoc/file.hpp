#pragma once

#include "aoc/types.hpp"

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <optional>
#include <string>
#include <string_view>
#include <utility>

namespace aoc {
inline constexpr auto s_inputs_directory = std::string_view{ "inputs" };
inline constexpr auto s_results_directory = std::string_view{ "results" };

static std::optional<std::string> read_file(std::filesystem::path _path)
{
  auto file = std::ifstream{ _path, std::ios::in };

  if (!file.is_open())
    return {};

  using istream_it = std::istreambuf_iterator<char>;
  return std::string{ istream_it{ file }, istream_it{} };
}

auto solve_and_mesure_execution_time_for(auto &&_input, aoc::part _part, solvable auto &&_problem)
{
  const auto start = std::chrono::high_resolution_clock::now();
  auto res = _problem.solve(std::move(_input), _part);
  const auto stop = std::chrono::high_resolution_clock::now();

  return std::tuple{ std::move(res), stop - start };
}

template<aoc::part _part> static auto solve(solvable auto &&_problem)
{
  return read_file(_problem.get_input_path(_part)).transform([&](auto &&_input) {
    return solve_and_mesure_execution_time_for(std::move(_input), _part, _problem);
  });
}

template<aoc::part _part> static auto get_expected_result(testable auto &&_problem)
{
  return read_file(_problem.get_result_path(_part));
}
}// namespace aoc
