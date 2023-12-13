#include "aoc.hpp"

namespace aoc::utils {
void print_day_solution(auto &&_ex, const auto &_path)
{
  if (_ex.has_value())
    std::println("{}", _ex.value());
  else
    std::println("\33[31;41m{} not found\33[0m", _path.string());
}

void solve_and_print(aoc::solvable auto &&_problem)
{
  using day_t = std::remove_cvref_t<decltype(_problem)>;
  print_day_solution(aoc::solve(_problem), day_t::get_input_path());
}

void test_and_print(aoc::testable auto &&_problem)
{
  using day_t = std::remove_cvref_t<decltype(_problem)>;
  print_day_solution(aoc::test(_problem), day_t::get_test_input_path());
}
}// namespace aoc