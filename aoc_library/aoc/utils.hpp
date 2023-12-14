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

  if (const auto result = aoc::solve<_part>(_problem))
    std::println("{}: {}", stringify<day_t, _part>(), result.value());
  else
    std::println("{} \33[31;41m{} not found\33[0m", stringify<day_t, _part>(), day_t::get_input_path().string());
}

template<aoc::part _part> void test_and_print(aoc::testable auto &&_problem)
{
  using day_t = std::remove_cvref_t<decltype(_problem)>;

  const auto date = day_t::get_date();

  if (const auto result = aoc::test<_part>(_problem)) {
    const auto expected_result = _problem.expected_value(_part);
    if (result == expected_result) {
      std::println(
        "{}: \33[32;1;42m[SUCCESS]\33[0m got expected answer \33[36m{}\33[0m", stringify<day_t, _part>(), *result);
    } else {
      std::println(
        "{}: \33[31;1;41m[FAILURE]\33[0m expected \33[36m{}\33[0m but got \33[36m{}\33[0m "
        "instead",
        stringify<day_t, _part>(),
        expected_result,
        *result);
    }
  } else {
    std::println("{} \33[31;41m{} not found\33[0m", stringify<day_t, _part>(), day_t::get_test_input_path().string());
  }
}
}// namespace aoc::utils