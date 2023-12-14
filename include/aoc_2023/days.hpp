#pragma once

#include <concepts>
#include <string>

#include <aoc/aoc.hpp>
#include <aoc/types.hpp>

namespace aoc_2023 {
template<std::integral auto _day> using y2023 = aoc::day_for_year<2023, _day>;

struct day_01 : public y2023<aoc::day_01>
{
  std::string solve(std::string &&_input, aoc::part_flags _parts) noexcept override;
  std::string test(std::string &&_input, aoc::part_flags _parts) noexcept override;
};

}// namespace aoc_2023