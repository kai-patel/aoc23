#include "StringUtils.h"

namespace utils {
std::vector<std::string> split(std::string s,
                               const std::string &delim) noexcept {
  std::size_t pos = 0;
  std::vector<std::string> result;

  while ((pos = s.find(delim)) != std::string::npos) {
    result.emplace_back(s.substr(0, pos));
    s.erase(0, pos + delim.size());
  }

  return result;
}
} // namespace utils
