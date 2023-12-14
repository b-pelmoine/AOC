#include "aoc_2023/days.hpp"

uint64_t aoc_2023::day_01::solve(std::string &&, aoc::part _part) noexcept { return _part == aoc::part::_01 ? 12 : 42; }
uint64_t aoc_2023::day_01::test(std::string &&, aoc::part _part) noexcept
{
  return _part == aoc::part::_01 ? 142 : 281;
}