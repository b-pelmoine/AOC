#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>

#include <utility>

#include <aoc/all_days.hpp>

template<aoc::part _part> auto solve_part(aoc::testable auto _problem)
{
  auto expected_result = aoc::read_file(_problem.get_result_path(_part));
  INFO(std::format("result file is {}", _problem.get_result_path(_part).string()));
  REQUIRE(expected_result);

  auto input = aoc::read_file(_problem.get_input_path(_part));
  INFO(std::format("input file is {}", _problem.get_input_path(_part).string()));
  REQUIRE(input);

  return std::tuple{ std::format("{}", _problem.solve(std::move(*input), _part)), std::move(*expected_result) };
}

auto solve(aoc::testable auto _problem)
{
  const auto [part_01_result, expected_part_01_result] = solve_part<aoc::part_01>(_problem);
  const auto [part_02_result, expected_part_02_result] = solve_part<aoc::part_02>(_problem);

  return std::tuple{ part_01_result, expected_part_01_result, part_02_result, expected_part_02_result };
}

template<typename Problem>
  requires aoc::testable<Problem>
void check_result_for()
{
  const auto [part_01, expected_part_01, part_02, expected_part_02] = solve(Problem{});
  THEN(std::format("Part 01 solution is {}", expected_part_01)) { CHECK(part_01 == expected_part_01); }
  AND_THEN(std::format("Part 02 solution is {}", expected_part_02)) { CHECK(part_02 == expected_part_02); }
}

TEST_CASE("AOC 2023 examples succeed", "[aoc][aoc-2023]")
{
  GIVEN("Day 01: Trebuchet?!") { check_result_for<aoc_2023::day_01>(); }
}