# Advent of code
This repository goal is to be forked by anyone and used as a framework to quickly get to work on advent of code problem solving.
The whole point is that every mundane common task is taken care of for you. The problem structure is based on very few [concepts](aoc_library/aoc/types.hpp) which makes it easily adptable to your use case and not dependant on types defined by the library but on the interface instead.
## Using the AOC library
The aoc library is an interface for setting up file reading and jump straight to parsing and solving the day's problem

Setting up the year can be done by using the `aoc::problem_for_date` templated struct:
```cpp
#include <aoc/aoc.hpp>

template<std::integral auto _day>
using y2023 = aoc::problem_for_date<2023, _day>;
```

A day only has to inherit from this new struct:
```cpp
namespace aoc_2023 {
struct day_01 : public y2023<aoc::day_01>
{
  uint64_t solve(std::string_view _input, aoc::part _part) const noexcept { return 42ULL; };
};
}// namespace aoc_2023
```

Now to run your solution, modify the [workbench main.cpp](src/workbench/main.cpp) 
and call `aoc::utils::solve_and_print` with your problem instance:
```cpp
aoc::utils::solve_and_print<aoc::part_01>(aoc_2023::day_01{});
```
then build and run the **workbench** target

Compiling and running your program at this point you should see the following output log
> 2023-12-01 [part 1] inputs\2023-12-01.txt not found

We need to create a file with the problem's input as follow: `inputs/2023-12-01.txt` (with the format `YYYY-MM-DD.txt`).

Running the workbench target again you should see:
> 2023-12-01 [part 1]: 42 in 0us

That's it for the setup, you now have access to the problem input in the _input variable and the part to solve in the _part variable.

## Testing and benchmarking using **Catch2**
Testing and benchmarking your problem can be done by compling with the `testable` concept
```cpp
template<typename T>
concept testable = requires(T &&_problem, std::string &&_data, aoc::part _part) {
  solvable<T>;
  {
    _problem.get_result_path(_part)
  } -> std::same_as<std::filesystem::path>;
};
```
which is the default if you're using the `aoc::problem` meaning all you have to do is:
- create a `inputs/results/YYYY-MM-DD-p1.txt` with your expected part 1 solution as content
- create a `inputs/results/YYYY-MM-DD-p2.txt` with your expected part 2 solution as content
- modify the [test file](tests/test.cpp)
```cpp
TEST_CASE("AOC 2023 day 01 succeed", "[aoc][aoc-2023]") {
  test_and_benchmark<aoc_2023::day_01>("Day 01: Trebuchet?!");
}
```
- compile, discover and run the tests using your prefered method

If you're only looking for tests or benchmarks you can use the functions `test` and `benchmark` separately

## Workbench testing

In addition to tests requirements, to use `aoc::solve_and_check_result` the problem struct has to comply with the `printable` concept
```cpp
template<typename T>
concept printable = requires(T &&_problem, aoc::part _part) {
  {
    _problem.as_formattable(_part)
  } -> formattable;
};
```
which is the default if you're using the `aoc::problem`.

The output is similar to unit tests but can be used without running tests to make sure solving the part 2 for the day doesn't invalidate the 1st part solution
additionialy it can be used when running sample problem input with an expected result

Example output:
```txt
2023-12-01 [part 1]: [SUCCESS] got expected answer 54916 in 110us
2023-12-01 [part 2]: [FAILURE] expected 54728 but got 55728 in 951us
```

## FAQ
> Both parts doesn't share the same input, what should I do?

add a `static constexpr bool different_inputs = true` in your problem struct which will make the parser look for different input for each part:
`inputs/YYYY-MM-DD-p1.txt` for part 1 and `inputs/YYYY-MM-DD-p2.txt` for part 2

> The solution result is not a number, what should I return?

anything formattable works, it doesn't have to be a number, it could be a `std::string` or your own structure for which you have a `std::formatter` template specialization as described in the solvable concept:

```cpp
template<typename T>
concept formattable =
  requires(T &v, std::format_context ctx) { std::formatter<std::remove_cvref_t<T>>().format(v, ctx); };

template<typename T>
concept solvable = requires(T &&_problem, std::string &&_data, aoc::part _part) {
  {
    _problem.solve(std::move(_data), _part)
  } -> formattable;
  {
    _problem.get_input_path(_part)
  } -> std::same_as<std::filesystem::path>;
};
```
