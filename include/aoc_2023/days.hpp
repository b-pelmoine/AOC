#pragma once

#include <concepts>
#include <cstdint>
#include <string>

#include <aoc/aoc.hpp>
#include <aoc/types.hpp>

namespace aoc_2023 {
template<std::integral auto _day> using y2023 = aoc::day_for_year<2023, _day>;

struct day_01 : public y2023<aoc::day_01>
{
  uint64_t solve(std::string &&_input, aoc::part _part) noexcept;
  uint64_t expected_value(aoc::part _part) const noexcept { return _part == aoc::part::_01 ? 142 : 281; }
};

}// namespace aoc_2023