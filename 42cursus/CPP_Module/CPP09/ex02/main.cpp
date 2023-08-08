#include <exception>
#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  try {
    PmergeMe::execute(argc, argv);
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}
