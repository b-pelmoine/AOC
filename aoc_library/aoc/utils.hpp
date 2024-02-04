#pragma once

#include "aoc/file.hpp"
#include "aoc/types.hpp"

#include <print>
#include <string_view>
#include <type_traits>

namespace aoc::utils {
template<aoc::part _part, class Problem>
  requires aoc::testable<Problem> && aoc::printable<Problem>
void solve_and_print(Problem &&_problem)
{
  const auto result_and_duration = aoc::solve<_part>(_problem);

  if (!result_and_duration) {
    std::println(
      "{} \33[31;41m{} not found\33[0m", _problem.as_formattable(_part), _problem.get_input_path(_part).string());
    return;
  }

  const auto [result, duration] = *result_and_duration;
  std::println("{}: \33[36m{}\33[0m in \33[35m{}\33[0m",
    _problem.as_formattable(_part),
    result,
    std::chrono::duration_cast<std::chrono::microseconds>(duration));
}

template<aoc::part _part, class Problem>
  requires aoc::testable<Problem> && aoc::printable<Problem>
void solve_and_check_result(Problem &&_problem)
{
  const auto expected_result = aoc::get_expected_result<_part>(_problem);

  if (!expected_result) {
    std::println(
      "{} \33[31;41m{} not found\33[0m", _problem.as_formattable(_part), _problem.get_result_path(_part).string());
    return;
  }

  const auto result_and_duration = aoc::solve<_part>(_problem);

  if (!result_and_duration) {
    std::println(
      "{} \33[31;41m{} not found\33[0m", _problem.as_formattable(_part), _problem.get_input_path(_part).string());
    return;
  }

  const auto [result, duration] = *result_and_duration;
  const auto result_string = std::format("{}", result);
  const auto duration_string =
    std::format("in \33[35m{}\33[0m", std::chrono::duration_cast<std::chrono::microseconds>(duration));
  if (result_string == *expected_result) {
    std::println("{}: \33[32;1;42m[SUCCESS]\33[0m got expected answer \33[36m{}\33[0m {}",
      _problem.as_formattable(_part),
      result_string,
      duration_string);
  } else {
    std::println("{}: \33[31;1;41m[FAILURE]\33[0m expected \33[36m{}\33[0m but got \33[36m{}\33[0m {}",
      _problem.as_formattable(_part),
      *expected_result,
      result_string,
      duration_string);
  }
}
}// namespace aoc::utils