#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>

#include <aoc/all_days.hpp>

template<aoc::part _part> auto solve_part(aoc::testable auto _problem)
{
  using day_t = std::remove_cvref_t<decltype(_problem)>;
  using result_t = decltype(std::declval<day_t>().solve({}, {}));

  struct res_both_parts
  {
    result_t part_result;
    result_t expected_part_result;
  };

  const auto expected_result = _problem.expected_value(_part);

  auto input = aoc::read_file(_problem.get_example_input_path(_part));

  REQUIRE(input);

  return res_both_parts{ _problem.solve(std::move(*input), _part), expected_result };
}

auto solve_example(aoc::testable auto _problem)
{
  using day_t = std::remove_cvref_t<decltype(_problem)>;
  using result_t = decltype(std::declval<day_t>().solve({}, {}));

  struct res_both_parts
  {
    result_t part_01;
    result_t expected_part_01;
    result_t part_02;
    result_t expected_part_02;
  };

  const auto [part_01, expected_part_01] = solve_part<aoc::part_01>(_problem);
  const auto [part_02, expected_part_02] = solve_part<aoc::part_02>(_problem);

  return res_both_parts{ part_01, expected_part_01, part_02, expected_part_02 };
}

template<typename Problem>
  requires aoc::testable<Problem>
void check_example_for()
{
  const auto [part_01, expected_part_01, part_02, expected_part_02] = solve_example(Problem{});
  THEN(std::format("Part 01 solution is {}", expected_part_01)) { CHECK(part_01 == expected_part_01); }
  THEN(std::format("Part 02 solution is {}", expected_part_02)) { CHECK(part_02 == expected_part_02); }
}

TEST_CASE("AOC 2023 examples succeed", "[aoc][aoc-2023]")
{
  GIVEN("Day 01: Trebuchet?!") { check_example_for<aoc_2023::day_01>(); }
}