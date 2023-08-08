#include "PmergeMe.hpp"

#include <sstream>

bool PmergeMe::isInteger(const char *str) {
  std::stringstream ss(str);
  int num;
  ss >> num;

  return (not ss.fail() and ss.eof());
}

bool PmergeMe::checkInteger(int argc, char **argv) {
  for (int i = 0; i < argc; ++i) {
  }
}

void PmergeMe::checkArgument(int argc, char **argv) {}

void PmergeMe::execute(int argc, char **argv) {}