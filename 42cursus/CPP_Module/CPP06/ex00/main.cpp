#include <cstdlib>
#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
  if (argc != 2) return 0;

  ScalarConverter::casting(argv[1]);

  return 0;
}
