#include <filesystem>
#include <fstream>
#include <iterator>
#include <string>

namespace aoc {
template<typename T>
concept solvable = requires(T &&_problem, std::string &&_file) {
  {
    _problem.solve(std::move(_file))
  } -> std::convertible_to<std::string>;
  {
    _problem.input()
  } -> std::convertible_to<const char *>;
};

constexpr auto solve(solvable auto &&_problem)
{
  const auto path = std::filesystem::path{ "inputs" } / _problem.input();
  auto file = std::ifstream{ path, std::ios::in };

  if (!file.is_open())
    return std::string{ std::string{ _problem.input() } + " not found" };

  using Iterator = std::istreambuf_iterator<char>;
  auto buffer = std::string{ Iterator{ file }, Iterator{} };

  return _problem.solve(std::move(buffer));
}
}// namespace aoc