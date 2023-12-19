#pragma once

#include "aoc/file.hpp"
#include "aoc/types.hpp"

#include <chrono>
#include <concepts>
#include <filesystem>
#include <format>
#include <string>

namespace aoc {
constexpr auto part_shorthand(const part _part)
{
  using namespace std::string_view_literals;
  switch (_part) {
  case part::_01:
    return "p1"sv;
  case part::_02:
    return "p2"sv;
  default:
    std::unreachable();
  }
}
enum class input { same_for_both_parts, different_for_both_parts };
enum class example_input { same_for_both_parts, different_for_both_parts };
template<std::integral auto _year,
  std::integral auto _day,
  example_input _example_input = example_input::same_for_both_parts,
  input _input = input::same_for_both_parts>
struct day_for_year
{
  static constexpr auto get_date() { return std::format("{2:%Y}-{1:%m}-{0:%d}", day(), month(), year()); }
  static constexpr auto get_input(const part _part)
  {
    if constexpr (_input == input::same_for_both_parts)
      return std::format("{}.txt", get_date());
    else
      return std::format("{}-{}.txt", get_date(), part_shorthand(_part));
  }
  static constexpr auto get_example_input(const part _part)
  {
    if constexpr (_example_input == example_input::same_for_both_parts)
      return std::format("{}.txt", get_date());
    else
      return std::format("{}-{}.txt", get_date(), part_shorthand(_part));
  }
  static constexpr auto get_input_path(const part _part)
  {
    return std::filesystem::path{ s_inputs_directory } / get_input(_part);
  }
  static constexpr auto get_example_input_path(const part _part)
  {
    return std::filesystem::path{ s_example_inputs_directory } / get_example_input(_part);
  }

  static constexpr auto day() noexcept { return s_day; };
  static constexpr auto month() noexcept { return s_month; };
  static constexpr auto year() noexcept { return s_year; };

  static constexpr std::chrono::day s_day{ _day };
  static constexpr std::chrono::year s_year{ _year };
  static constexpr auto s_month{ std::chrono::December };

  static_assert([]() {
    using namespace std::chrono_literals;
    // 25 days, started in 2015
    return s_day >= 1d && s_day <= 25d && s_year >= 2015y;
  }());
};
}// namespace aoc