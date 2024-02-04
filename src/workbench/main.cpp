#include "aoc/types.hpp"
#include <aoc/2023/days.hpp>
#include <aoc/utils.hpp>

int main()
{
  auto day = aoc_2023::day_01{};
  aoc::utils::solve_and_check_result<aoc::part_01>(day);
  aoc::utils::solve_and_check_result<aoc::part_02>(day);
}