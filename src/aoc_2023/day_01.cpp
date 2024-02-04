#include "aoc/2023/days.hpp"

#include <algorithm>
#include <ranges>
#include <string_view>
#include <vector>

uint64_t as_number(std::string_view _word, aoc::part _part)
{
  switch (_part) {
  case aoc::part_01: {
    return (_word[_word.find_first_of("0123456789")] - '0') * 10 + _word[_word.find_last_of("0123456789")] - '0';
  } break;
  case aoc::part_02: {
    const auto all_digits = std::invoke([&]() {
      using namespace std::literals;
      static const auto digits = {
        "one"sv, "two"sv, "three"sv, "four"sv, "five"sv, "six"sv, "seven"sv, "eight"sv, "nine"sv
      };
      auto found_digits = std::vector<int>{};
      for (const auto [i, c] : std::views::enumerate(_word)) {
        if (std::isdigit(c))
          found_digits.push_back(c - '0');
        else if (auto it = std::ranges::find_if(
                   digits, [&](const auto _digit) { return _word.substr(i, _digit.size()) == _digit; });
                 it != std::end(digits)) {
          found_digits.push_back(static_cast<int>(std::distance(std::begin(digits), it)) + 1);
        }
      }
      return found_digits;
    });
    return all_digits[0] * 10 + all_digits.back();
  } break;
  }
  std::unreachable();
}

uint64_t aoc_2023::day_01::solve(std::string_view _input, aoc::part _part) const noexcept
{
  return std::ranges::fold_left(std::views::split(_input, '\n'), 0ull, [_part](uint64_t _sum, const auto _word) {
    return _sum + as_number(std::string_view{ _word }, _part);
  });
}