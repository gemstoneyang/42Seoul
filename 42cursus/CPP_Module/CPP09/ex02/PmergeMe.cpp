#include "PmergeMe.hpp"

#include <algorithm>
#include <sstream>
#include <stdexcept>

std::vector<int> PmergeMe::_vec;
std::deque<int> PmergeMe::_deq;

void PmergeMe::checkInteger(int argc, char **argv) {
  for (int i = 1; i < argc; ++i) {
    std::stringstream ss(argv[i]);
    int num;
    ss >> num;

    if ((not ss.fail() and ss.eof()) == false)
      throw std::invalid_argument("Argument is not a valid integer.");
    else if (num < 0)
      throw std::invalid_argument("Argument is not a positive integer.");

    PmergeMe::_vec.push_back(num);
    PmergeMe::_deq.push_back(num);
  }
}

void PmergeMe::checkDuplicate(void) {
  if (PmergeMe::isDuplicate(_vec) or PmergeMe::isDuplicate(_deq))
    throw std::invalid_argument("Arguments contain duplicate numbers.");
}

void PmergeMe::checkArgument(int argc, char **argv) {
  PmergeMe::checkInteger(argc, argv);
  PmergeMe::checkDuplicate();
}

void PmergeMe::execute(int argc, char **argv) {
  PmergeMe::checkArgument(argc, argv);
}