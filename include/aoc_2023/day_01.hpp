#include <ostream>
#include <string>

namespace aoc_2023 {
struct day1
{
  constexpr auto input() const noexcept { return "2023-12-01.txt"; }
  std::string solve(std::string &&_input) noexcept;
};
}// namespace aoc_2023