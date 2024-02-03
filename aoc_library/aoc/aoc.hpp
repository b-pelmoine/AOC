#pragma once

#include "aoc/file.hpp"
#include "aoc/types.hpp"

#include <chrono>
#include <concepts>
#include <filesystem>
#include <format>
#include <string>

namespace aoc {
struct problem
{
  template<class Self> constexpr auto get_date(this Self &&self)
  {
    return std::format("{2:%Y}-{1:%m}-{0:%d}", self.day, self.month, self.year);
  }
  template<class Self> constexpr auto as_formattable(this Self &&self, const part _part)
  {
    return std::format("{} [\33[37mpart {}\33[0m]", self.get_date(), std::to_underlying(_part) + 1u);
  }
  template<class Self, bool _different_file_per_part = true> constexpr auto get_file(this Self &&self, const part _part)
  {
    if constexpr (_different_file_per_part)
      return std::format("{}-p{}.txt", self.get_date(), std::to_underlying(_part) + 1u);
    else
      return std::format("{}.txt", self.get_date());
  }
  template<class Self> constexpr auto get_input_file(this Self &&self, const part _part)
  {
    return self.get_file<Self, has_different_inputs<Self>>(_part);
  }
  template<class Self> constexpr auto get_result_file(this Self &&self, const part _part)
  {
    return self.get_file(_part);
  }
  template<class Self> constexpr auto get_input_path(this Self &&self, const part _part)
  {
    return std::filesystem::path{ s_inputs_directory } / self.get_input_file(_part);
  }
  template<class Self> constexpr auto get_result_path(this Self &&self, const part _part)
  {
    return std::filesystem::path{ s_inputs_directory } / s_results_directory / self.get_result_file(_part);
  }
};
}// namespace aoc