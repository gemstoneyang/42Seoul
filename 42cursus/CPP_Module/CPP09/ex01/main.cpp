#include <iostream>

#include "RPN.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    RPN::printError();
    return 0;
  }

  (void)argv;

  return 0;
}
