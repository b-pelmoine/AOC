#pragma once

#include <expected>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <print>
#include <string>
#include <string_view>

namespace aoc {
template<typename T>
concept solvable = requires(T &&_problem, std::string &&_data) {
  {
    _problem.solve(std::move(_data))
  } -> std::convertible_to<std::string>;
  {
    _problem.get_input_path()
  } -> std::convertible_to<std::filesystem::path>;
};

template<typename T>
concept testable = requires(T &&_problem, std::string &&_data) {
  {
    _problem.test(std::move(_data))
  } -> std::convertible_to<std::string>;
  {
    _problem.get_test_input_path()
  } -> std::convertible_to<std::filesystem::path>;
};

inline constexpr auto s_inputs_directory = std::string_view{ "inputs" };
inline constexpr auto s_test_inputs_directory = std::string_view{ "inputs/test" };

static std::optional<std::string> read_file(std::filesystem::path _path)
{
  auto file = std::ifstream{ _path, std::ios::in };

  if (!file.is_open())
    return {};

  using Iterator = std::istreambuf_iterator<char>;
  auto buffer = std::string{ Iterator{ file }, Iterator{} };

  return buffer;
}

static std::optional<std::string> solve(solvable auto &&_problem)
{
  return read_file(_problem.get_input_path()).transform([&](auto &&_input) {
    return _problem.solve(std::move(_input));
  });
}

static std::optional<std::string> test(testable auto &&_problem)
{
  return read_file(_problem.get_test_input_path()).transform([&](auto &&_input) {
    return _problem.test(std::move(_input));
  });
}

template<uint32_t _year, uint8_t _day> struct day_for_year
{
  static constexpr auto get_date() { return std::format("{2:%Y}-{1:%m}-{0:%d}", day(), month(), year()); }
  static constexpr auto get_input() { return std::format("{}.txt", get_date()); }
  static constexpr auto get_input_path() { return std::filesystem::path{ s_inputs_directory } / get_input(); }
  static constexpr auto get_test_input_path() { return std::filesystem::path{ s_test_inputs_directory } / get_input(); }

  static constexpr auto day() noexcept { return s_day; };
  static constexpr auto month() noexcept { return s_month; };
  static constexpr auto year() noexcept { return s_year; };

  static constexpr std::chrono::day s_day{ _day };
  static constexpr std::chrono::year s_year{ _year };
  static constexpr auto s_month{ std::chrono::December };

  virtual std::string solve(std::string &&_input) noexcept { return _input; };
  virtual std::string test(std::string &&_input) noexcept { return _input; };

  static_assert([]() {
    using namespace std::chrono_literals;
    // 25 days, started in 2015
    return s_day >= 1d && s_day <= 25d && s_year >= 2015y;
  }());
};
}// namespace aoc