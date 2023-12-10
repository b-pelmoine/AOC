#include <aoc/aoc.hpp>
#include <print>

#include <aoc_2023/all_days.hpp>

int main()
{
  std::println("hello, world");
  int a{ 0 };
  foo::bar(&a);
  std::println("{} {}", a, aoc::get());
}