#pragma once

#include <string>

#include <aoc/aoc.hpp>

namespace aoc_2023 {
template<uint8_t _day> using day = aoc::day_for_year<2023, _day>;

struct day_01 : public day<1>
{
  std::string solve(std::string &&_input) noexcept override;
  std::string test(std::string &&_input) noexcept override;
};

}// namespace aoc_2023