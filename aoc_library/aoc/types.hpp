#pragma once

#include <concepts>
#include <filesystem>
#include <format>
#include <string>
#include <type_traits>

namespace aoc {

enum class part { _01, _02 };

template<typename T>
concept solvable = requires(T &&_problem, std::string &&_data, aoc::part _part) {
  {
    _problem.solve(std::move(_data), _part)
  } -> std::integral;
  {
    _problem.get_input_path()
  } -> std::convertible_to<std::filesystem::path>;
};

template<typename T>
concept testable = requires(T &&_problem, std::string &&_data, aoc::part _part) {
  {
    _problem.solve(std::move(_data), _part)
  } -> std::equality_comparable_with<decltype(_problem.expected_value(_part))>;
  {
    _problem.get_example_input_path()
  } -> std::convertible_to<std::filesystem::path>;
};

// for a readable template argument
inline constexpr auto day_01{ 1 };
inline constexpr auto day_02{ 2 };
inline constexpr auto day_03{ 3 };
inline constexpr auto day_04{ 4 };
inline constexpr auto day_05{ 5 };
inline constexpr auto day_06{ 6 };
inline constexpr auto day_07{ 7 };
inline constexpr auto day_08{ 8 };
inline constexpr auto day_09{ 9 };
inline constexpr auto day_10{ 10 };
inline constexpr auto day_11{ 11 };
inline constexpr auto day_12{ 12 };
inline constexpr auto day_13{ 13 };
inline constexpr auto day_14{ 14 };
inline constexpr auto day_15{ 15 };
inline constexpr auto day_16{ 16 };
inline constexpr auto day_17{ 17 };
inline constexpr auto day_18{ 18 };
inline constexpr auto day_19{ 19 };
inline constexpr auto day_20{ 20 };
inline constexpr auto day_21{ 21 };
inline constexpr auto day_22{ 22 };
inline constexpr auto day_23{ 23 };
inline constexpr auto day_24{ 24 };
inline constexpr auto day_25{ 25 };

}// namespace aoc