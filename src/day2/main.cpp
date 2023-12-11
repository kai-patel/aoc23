#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ostream>
#include <string>
#include <vector>

#include "ArgParse.h"
#include "StringUtils.h"

namespace day1 {

bool solve_line(std::string &line) {
  std::vector<std::string> split;
  boost::split(split, line, boost::is_any_of(":"));

  std::vector<std::string> sets;
  boost::split(sets, split[1], boost::is_any_of(";"));

  static constexpr uint32_t red = 12;
  static constexpr uint32_t green = 13;
  static constexpr uint32_t blue = 14;

  for (const auto &set : sets) {
    std::vector<std::string> cubes;
    boost::split(cubes, set, boost::is_any_of(","));

    for (auto &cube : cubes) {
      boost::trim_left(cube);
      std::vector<std::string> cube_split;
      boost::split(cube_split, cube, boost::is_any_of(" "));

      if (cube_split[1] == "red") {
        if (std::stoi(cube_split[0]) > red) {
          return false;
        }
      }
      if (cube_split[1] == "green") {
        if (std::stoi(cube_split[0]) > green) {
          return false;
        }
      }
      if (cube_split[1] == "blue") {
        if (std::stoi(cube_split[0]) > blue) {
          return false;
        }
      }
    }
  }

  return true;
}

uint32_t solve(std::ifstream &input) {
  std::string line;
  uint32_t line_number = 0;
  std::vector<uint32_t> results;

  while (std::getline(input, line)) {
    const auto result = day1::solve_line(line);
    if (result) {
      results.push_back(line_number + 1);
    }

    ++line_number;
  }
  const auto result = std::accumulate(results.begin(), results.end(), 0U);
  return result;
}
} // namespace day1

namespace day2 {

uint32_t solve_line(std::string &line) {
  std::vector<std::string> split;
  boost::split(split, line, boost::is_any_of(":"));

  std::vector<std::string> sets;
  boost::split(sets, split[1], boost::is_any_of(";"));

  uint32_t max_red{0};
  uint32_t max_green{0};
  uint32_t max_blue{0};

  for (const auto &set : sets) {
    std::vector<std::string> cubes;
    boost::split(cubes, set, boost::is_any_of(","));

    for (auto &cube : cubes) {
      boost::trim_left(cube);
      std::vector<std::string> cube_split;
      boost::split(cube_split, cube, boost::is_any_of(" "));

      if (cube_split[1] == "red") {
        max_red =
            std::max(max_red, static_cast<uint32_t>(std::stoi(cube_split[0])));
      }
      if (cube_split[1] == "green") {
        max_green = std::max(max_green,
                             static_cast<uint32_t>(std::stoi(cube_split[0])));
      }
      if (cube_split[1] == "blue") {
        max_blue =
            std::max(max_blue, static_cast<uint32_t>(std::stoi(cube_split[0])));
      }
    }
  }

  return max_red * max_green * max_blue;
}

uint32_t solve(std::ifstream &input) {
  std::string line;
  uint32_t line_number = 0;
  std::vector<uint32_t> results;

  while (std::getline(input, line)) {
    results.emplace_back(day2::solve_line(line));
  }

  const auto total = std::accumulate(results.begin(), results.end(), 0U);
  return total;
}

} // namespace day2

int main(int argc, char *argv[]) {
  const auto &args = utils::get_args(argc, argv);
  if (!args.has_value()) {
    std::cerr << "No input!" << std::endl;
    return EXIT_FAILURE;
  }

  auto input = std::ifstream{args->input, std::ios::in};

  std::cout << day1::solve(input) << '\n';
  input.clear();
  input.seekg(0);
  std::cout << day2::solve(input) << '\n';

  return EXIT_SUCCESS;
}
