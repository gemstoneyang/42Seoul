#include <iostream>

#include "RPN.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    RPN::printError();
    return 0;
  }

  try {
    std::cout << RPN::calculate(argv[1]) << std::endl;
  } catch (std::exception &e) {
    (void)e;
    RPN::printError();
  }

  return 0;
}
