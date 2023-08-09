#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Error: Invalid argument" << std::endl;
    return 0;
  }

  try {
    BitcoinExchange::execute(argv[1]);
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}
