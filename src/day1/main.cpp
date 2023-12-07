#include "ArgParse.h"
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

namespace day1 {

uint32_t solve_line(std::string &line) {
  line.erase(std::remove_if(line.begin(), line.end(),
                            [](const auto &i) { return std::isalpha(i); }),
             line.end());

  const auto first = line.front();
  const auto last = line.back();
  std::stringstream ss;
  ss << first << last;

  return std::atoi(ss.str().c_str());
}
} // namespace day1

namespace day2 {

static const std::unordered_map<std::string, uint32_t> forward_map{
    {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4}, {"five", 5},
    {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

std::pair<uint32_t, uint32_t>
first_from_string(const std::string &line,
                  const std::unordered_map<std::string, uint32_t>& map) {
  std::size_t first_idx = line.size() + 1;
  uint32_t first_number = -1;

  for (const auto &[literal, number] : map) {
    const auto found = line.find(literal);
    if (found != std::string::npos) {
      if (found < first_idx) {
        first_idx = found;
        first_number = number;
      }
    }
  }

  return std::pair{first_idx, first_number};
}

std::pair<uint32_t, uint32_t> first_from_number(const std::string &line) {
  std::size_t first_idx = line.size() + 1;
  uint32_t first_number = -1;

  for (auto i = 0; i < 10; i++) {
    const auto number_as_char = std::to_string(i);
    const auto found = line.find(number_as_char);
    if (found != std::string::npos) {
      if (found < first_idx) {
        first_idx = found;
        first_number = i;
      }
    }
  }

  return std::pair{first_idx, first_number};
}

uint32_t solve_line(std::string &line) {
  const auto first_string = first_from_string(line, forward_map);
  const auto first_number = first_from_number(line);

  auto first = 0U;
  if (first_string.first < first_number.first) {
    first = first_string.second;
  } else {
    first = first_number.second;
  }

  std::reverse(line.begin(), line.end());
  std::unordered_map<std::string, uint32_t> reverse_map{};

  for (const auto &[literal, number] : forward_map) {
    std::string reverse_literal = literal;
    std::reverse(reverse_literal.begin(), reverse_literal.end());
    reverse_map[reverse_literal] = number;
  }

  auto last_string = first_from_string(line, reverse_map);
  auto last_number = first_from_number(line);

  auto last = 0U;
  if (last_string.first < last_number.first) {
    last = last_string.second;
  } else {
    last = last_number.second;
  }

  std::stringstream ss;
  ss << first << last;

  return std::atoi(ss.str().c_str());
}
} // namespace day2

int main(int argc, char *argv[]) {
  const auto &args = utils::get_args(argc, argv);
  if (!args.has_value()) {
    std::cerr << "No input!" << std::endl;
    return EXIT_FAILURE;
  }

  auto input = std::ifstream{args->input, std::ios::in};

  std::string line;
  auto total = 0U;
  while (std::getline(input, line)) {
    const auto result = day2::solve_line(line);
    total += result;
  }

  std::cout << total << '\n';

  return EXIT_SUCCESS;
}
