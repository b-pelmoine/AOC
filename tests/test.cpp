#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>

#include <utility>

#include <aoc/all_days.hpp>

template<aoc::part _part> auto get_input(const aoc::testable auto &_problem)
{
  auto input = aoc::read_file(_problem.get_input_path(_part));
  INFO(std::format("input file is {}", _problem.get_input_path(_part).string()));
  REQUIRE(input);

  return *input;
}

template<aoc::part _part> auto get_expected_result(const aoc::testable auto &_problem)
{
  auto expected_result = aoc::read_file(_problem.get_result_path(_part));
  INFO(std::format("result file is {}", _problem.get_result_path(_part).string()));
  REQUIRE(expected_result);

  return *expected_result;
}

template<aoc::part _part> auto get_input_and_expected_result(const aoc::testable auto &_problem)
{
  return std::tuple{ get_input<_part>(_problem), get_expected_result<_part>(_problem) };
}

template<aoc::part _part> auto get_solution_and_expectation(aoc::testable auto _problem)
{
  auto [input, expectation] = get_input_and_expected_result<_part>(_problem);
  return std::tuple{ std::format("{}", _problem.solve(input, _part)), std::move(expectation) };
}

template<typename Problem>
  requires aoc::testable<Problem>
void benchmark()
{
  BENCHMARK_ADVANCED("part 1")(Catch::Benchmark::Chronometer _meter)
  {
    auto problem = Problem{};
    _meter.measure(
      [&, input_part_01 = get_input<aoc::part_01>(problem)] { return problem.solve(input_part_01, aoc::part_01); });
  };
  BENCHMARK_ADVANCED("part 2")(Catch::Benchmark::Chronometer _meter)
  {
    auto problem = Problem{};
    _meter.measure(
      [&, input_part_02 = get_input<aoc::part_02>(problem)] { return problem.solve(input_part_02, aoc::part_02); });
  };
}

auto solve(aoc::testable auto _problem)
{
  const auto [part_01_result, expected_part_01_result] = get_solution_and_expectation<aoc::part_01>(_problem);
  const auto [part_02_result, expected_part_02_result] = get_solution_and_expectation<aoc::part_02>(_problem);

  return std::tuple{ part_01_result, expected_part_01_result, part_02_result, expected_part_02_result };
}

template<typename Problem>
  requires aoc::testable<Problem>
void test(std::string_view _problem_name)
{
  GIVEN(_problem_name)
  {
    const auto [part_01, expected_part_01, part_02, expected_part_02] = solve(Problem{});
    THEN(std::format("Part 01 solution is {}", expected_part_01)) { CHECK(part_01 == expected_part_01); }
    AND_THEN(std::format("Part 02 solution is {}", expected_part_02)) { CHECK(part_02 == expected_part_02); }
  }

  benchmark<aoc_2023::day_01>();
}

TEST_CASE("AOC 2023 examples succeed", "[aoc][aoc-2023]") { test<aoc_2023::day_01>("Day 01: Trebuchet?!"); }