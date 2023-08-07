#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
  if (argc != 2) return 0;

  try {
    BitcoinExchange::execute(argv[1]);
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}
