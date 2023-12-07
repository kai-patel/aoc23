#include "include/ArgParse.h"
#include <boost/program_options.hpp>
#include <iostream>
#include <optional>
#include <string>

namespace utils {

std::optional<CommandLineArgs> get_args(int ac, char *av[]) {
  boost::program_options::options_description desc("Allowed options");
  desc.add_options()("help", "show program options")(
      "input", boost::program_options::value<std::string>(),
      "path to input file");

  boost::program_options::variables_map vm;
  try {
    boost::program_options::store(
        boost::program_options::parse_command_line(ac, av, desc), vm);
  } catch (const boost::program_options::unknown_option &e) {
    std::cerr << "Could not parse options:\n" << desc << '\n';
    return std::nullopt;
  }

  boost::program_options::notify(vm);

  if (vm.count("help")) {
    std::cout << desc << '\n';
    return std::nullopt;
  }

  auto args = CommandLineArgs{};

  if (vm.count("input")) {
    args.input = vm["input"].as<std::string>();
    std::cout << "Input: " << args.input << "\n";
  } else {
    std::cout << "Input was not set\n";
    return std::nullopt;
  }

  return args;
}
} // namespace utils
