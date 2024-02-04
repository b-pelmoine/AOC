#pragma once

#include <concepts>
#include <cstdint>
#include <string>

#include <aoc/aoc.hpp>
#include <aoc/types.hpp>

namespace aoc_2023 {
template<std::integral auto _day> struct y2023 : public aoc::problem
{
  std::chrono::day day{ _day };
  std::chrono::month month{ std::chrono::December };
  std::chrono::year year{ 2023 };
};

struct day_01 : public y2023<aoc::day_01>
{
  uint64_t solve(std::string_view _input, aoc::part _part) noexcept;
};

}// namespace aoc_2023