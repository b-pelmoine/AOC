#pragma once

#include "aoc/file.hpp"

#include <concepts>
#include <filesystem>
#include <format>
#include <string>

namespace aoc {
template<std::integral auto _year, std::integral auto _day> struct day_for_year
{
  static constexpr auto get_date() { return std::format("{2:%Y}-{1:%m}-{0:%d}", day(), month(), year()); }
  static constexpr auto get_input() { return std::format("{}.txt", get_date()); }
  static constexpr auto get_input_path() { return std::filesystem::path{ s_inputs_directory } / get_input(); }
  static constexpr auto get_test_input_path() { return std::filesystem::path{ s_test_inputs_directory } / get_input(); }

  static constexpr auto day() noexcept { return s_day; };
  static constexpr auto month() noexcept { return s_month; };
  static constexpr auto year() noexcept { return s_year; };

  static constexpr std::chrono::day s_day{ _day };
  static constexpr std::chrono::year s_year{ _year };
  static constexpr auto s_month{ std::chrono::December };

  virtual std::string solve(std::string &&_input, aoc::part_flags = aoc::both_parts) noexcept { return _input; };
  virtual std::string test(std::string &&_input, aoc::part_flags = aoc::both_parts) noexcept { return _input; };

  static_assert([]() {
    using namespace std::chrono_literals;
    // 25 days, started in 2015
    return s_day >= 1d && s_day <= 25d && s_year >= 2015y;
  }());
};
}// namespace aoc