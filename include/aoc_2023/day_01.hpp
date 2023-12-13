#include <string>

#include "aoc_2023/aoc_2023.hpp"

namespace aoc_2023 {
struct day_01 : public day<1>
{
  std::string solve(std::string &&_input) noexcept override;
  std::string test(std::string &&_input) noexcept override;
};
}// namespace aoc_2023