#pragma once

#include <concepts>
#include <cstdint>
#include <string>

#include <aoc/aoc.hpp>
#include <aoc/types.hpp>

namespace aoc_2023 {
template<std::integral auto _day>
using y2023 = aoc::problem_for_date<2023, _day>;

struct day_01 : public y2023<aoc::day_01>
{
  uint64_t solve(std::string_view _input, aoc::part _part) noexcept;
};

}// namespace aoc_2023