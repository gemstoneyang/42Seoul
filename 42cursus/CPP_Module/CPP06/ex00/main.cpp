#include <cstdlib>
#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
  if (argc != 2) return 0;

  std::cout << ScalarConverter::getType(argv[1]) << std::endl;

  return 0;
}
