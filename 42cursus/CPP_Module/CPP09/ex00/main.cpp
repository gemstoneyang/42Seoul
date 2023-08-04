#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
  // if (argc != 2) return 0;

  (void)argc;
  (void)argv;
  BitcoinExchange::readDatabase();

  return 0;
}
