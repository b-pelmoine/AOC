#pragma once

#include "aoc/file.hpp"
#include "aoc/types.hpp"

#include <print>
#include <string_view>
#include <type_traits>

namespace aoc::utils {

template<aoc::part _part> constexpr auto stringify()
{
  using namespace std::literals;
  if constexpr (_part == aoc::part::_01)
    return "part 01"sv;
  else if constexpr (_part == aoc::part::_02)
    return "part 02"sv;
}

template<typename Day, aoc::part _part> constexpr auto stringify()
{
  return std::format("{} [\33[37m{}\33[0m]", Day::get_date(), stringify<_part>());
}

template<aoc::part _part> void solve_and_print(aoc::solvable auto &&_problem)
{
  using day_t = std::remove_cvref_t<decltype(_problem)>;

  if (const auto result_and_duration = aoc::solve<_part>(_problem)) {
    const auto [result, duration] = *result_and_duration;
    std::println("{}: \33[36m{}\33[0m in \33[35m{}\33[0m", stringify<day_t, _part>(), result, duration);
  } else
    std::println("{} \33[31;41m{} not found\33[0m", stringify<day_t, _part>(), day_t::get_input_path(_part).string());
}

template<aoc::part _part> void test_example_and_print(aoc::testable auto &&_problem)
{
  using day_t = std::remove_cvref_t<decltype(_problem)>;

  if (const auto result_and_duration = aoc::solve_example<_part>(_problem)) {
    const auto [result, duration] = *result_and_duration;
    const auto expected_result = _problem.expected_value(_part);
    const auto duration_string = std::format("in \33[35m{}\33[0m", duration);
    if (result == expected_result) {
      std::println("{}: \33[32;1;42m[SUCCESS]\33[0m got expected answer \33[36m{}\33[0m {}",
        stringify<day_t, _part>(),
        result,
        duration_string);
    } else {
      std::println("{}: \33[31;1;41m[FAILURE]\33[0m expected \33[36m{}\33[0m but got \33[36m{}\33[0m {}",
        stringify<day_t, _part>(),
        expected_result,
        result,
        duration_string);
    }
  } else {
    std::println(
      "{} \33[31;41m{} not found\33[0m", stringify<day_t, _part>(), day_t::get_example_input_path(_part).string());
  }
}
}// namespace aoc::utils