#pragma once

#include <concepts>
#include <cstdint>
#include <string>

#include <aoc/aoc.hpp>
#include <aoc/types.hpp>

namespace aoc_2023 {
template<std::integral auto _day,
  aoc::example_input _example_input = aoc::example_input::same_for_both_parts,
  aoc::input _input = aoc::input::same_for_both_parts>
using y2023 = aoc::day_for_year<2023, _day, _example_input, _input>;

struct day_01 : public y2023<aoc::day_01, aoc::example_input::different_for_both_parts>
{
  uint64_t solve(std::string &&_input, aoc::part _part) noexcept;
  uint64_t expected_value(aoc::part _part) const noexcept { return _part == aoc::part::_01 ? 142 : 281; }
};

struct day_02 : public y2023<aoc::day_02>
{
  std::string solve(std::string &&_input, aoc::part _part) noexcept;
  std::string expected_value(aoc::part _part) const noexcept { return _part == aoc::part::_01 ? "bonjour" : "hello"; }
};

}// namespace aoc_2023