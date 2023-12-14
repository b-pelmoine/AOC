#pragma once

#include "aoc/file.hpp"
#include "aoc/types.hpp"

#include <print>
#include <type_traits>

namespace aoc::utils {
void print_day_solution(auto &&_ex, const auto &_path)
{
  if (_ex.has_value())
    std::println("{}", _ex.value());
  else
    std::println("\33[31;41m{} not found\33[0m", _path.string());
}

template<part_flags _parts = part_flags{ aoc::both_parts }> void solve_and_print(aoc::solvable auto &&_problem)
{
  using day_t = std::remove_cvref_t<decltype(_problem)>;
  print_day_solution(aoc::solve<_parts>(_problem), day_t::get_input_path());
}

template<part_flags _parts = aoc::both_parts> void test_and_print(aoc::testable auto &&_problem)
{
  using day_t = std::remove_cvref_t<decltype(_problem)>;
  print_day_solution(aoc::test<_parts>(_problem), day_t::get_test_input_path());
}
}// namespace aoc::utils