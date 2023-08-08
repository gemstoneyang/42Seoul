#include "PmergeMe.hpp"

#include <algorithm>
#include <iostream>
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
  PmergeMe::mergeInsertionSort();
}

void PmergeMe::merge(std::vector<std::vector<int> > &vec) {
  size_t end = vec.size();
  if (end < 4) return;

  for (size_t i = 0; i < end / 2; ++i) {
    int a = vec[i][0];
    int b = vec[i + 1][0];
    if (a > b) {
      for (vec_reverse_iterator rit = vec[i + 1].rbegin();
           rit < vec[i + 1].rend(); ++rit) {
        vec[i].push_back(*rit);
      }
      vec.erase(vec.begin() + i + 1);
    } else {
      for (vec_reverse_iterator rit = vec[i].rbegin(); rit < vec[i].rend();
           ++rit) {
        vec[i + 1].push_back(*rit);
      }
      vec.erase(vec.begin() + i);
    }
  }

  PmergeMe::merge(vec);
}

int PmergeMe::jacobsthal(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  std::vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= n; ++i) {
    dp[i] = dp[i - 1] + 2 * dp[i - 2];
  }

  return dp[n];
}

std::vector<int> PmergeMe::generateOrder(int max) {
  int n = 1;
  while (max > PmergeMe::jacobsthal(n)) n++;

  std::vector<int> order;
  for (int i = 1; i <= n; ++i) {
    for (int j = PmergeMe::jacobsthal(i); j > PmergeMe::jacobsthal(i - 1);
         --j) {
      if (j < max) order.push_back(j);
    }
  }
  return order;
}

void PmergeMe::binarySearch(std::vector<std::vector<int> > &vec,
                            std::vector<int> target) {
  size_t left = 0;
  size_t right = vec.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (vec[mid][0] < target[0]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  vec.insert(vec.begin() + left, target);
}

void PmergeMe::devide(std::vector<std::vector<int> > &vec) {
  std::vector<std::vector<int> > loserVec;

  for (vecvec_iterator vit = vec.begin(); vit < vec.end(); ++vit) {
    std::vector<int> &tmpVec = *vit;
    std::vector<int> newVec;
    for (vec_reverse_iterator rit = tmpVec.rbegin();
         rit < tmpVec.rbegin() + tmpVec.size() / 2; ++rit) {
      newVec.push_back(*rit);
    }
    size_t size = tmpVec.size();
    for (size_t i = 0; i < size / 2; ++i) tmpVec.pop_back();
    loserVec.push_back(newVec);
  }

  vec.insert(vec.begin(), loserVec[0]);

  std::vector<int> order = generateOrder(loserVec.size());
  for (vec_iterator it = order.begin(); it < order.end(); ++it) {
    PmergeMe::binarySearch(vec, loserVec[*it]);
  }

  for (size_t i = 0; i < loserVec.size(); i++) {
    for (size_t j = 0; j < loserVec[i].size(); j++) {
      std::cout << loserVec[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "------------" << std::endl;
}

void PmergeMe::mergeInsertionSort(void) {
  std::vector<std::vector<int> > vec;

  for (vec_iterator it = _vec.begin(); it < _vec.end(); it++) {
    std::vector<int> newVec(1, *it);
    vec.push_back(newVec);
  }

  if (vec.size() == 1) return;

  PmergeMe::merge(vec);
  PmergeMe::devide(vec);
  PmergeMe::devide(vec);
  PmergeMe::devide(vec);

  for (size_t i = 0; i < vec.size(); i++) {
    for (size_t j = 0; j < vec[i].size(); j++) {
      std::cout << vec[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
