#include <aoc/2023/days.hpp>
#include <aoc/utils.hpp>

int main()
{
  auto day = aoc_2023::day_01{};
  aoc::utils::test_example_and_print<aoc::part_01>(day);
  aoc::utils::test_example_and_print<aoc::part_02>(day);
  aoc::utils::solve_and_print<aoc::part_01>(day);
  aoc::utils::solve_and_print<aoc::part_02>(day);
}