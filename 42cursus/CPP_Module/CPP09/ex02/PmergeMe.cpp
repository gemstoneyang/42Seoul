#include "PmergeMe.hpp"

#include <algorithm>
#include <ctime>
#include <iostream>
#include <sstream>
#include <stdexcept>

std::vector<int> PmergeMe::_vec;
std::deque<int> PmergeMe::_deq;
size_t PmergeMe::_size;

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
  PmergeMe::_size = _vec.size();
}

bool PmergeMe::isDuplicate(std::vector<int> const &arr) {
  std::vector<int> temp = arr;
  std::sort(temp.begin(), temp.end());

  for (size_t i = 1; i < temp.size(); ++i) {
    if (temp[i] == temp[i - 1]) {
      return true;
    }
  }
  return false;
}

bool PmergeMe::isDuplicate(std::deque<int> const &arr) {
  std::deque<int> temp = arr;
  std::sort(temp.begin(), temp.end());

  for (size_t i = 1; i < temp.size(); ++i) {
    if (temp[i] == temp[i - 1]) {
      return true;
    }
  }
  return false;
}

void PmergeMe::checkDuplicate(void) {
  if (PmergeMe::isDuplicate(_vec) or PmergeMe::isDuplicate(_deq))
    throw std::invalid_argument("Arguments contain duplicate numbers.");
}

void PmergeMe::checkArgument(int argc, char **argv) {
  if (argc < 2)
    throw std::invalid_argument("No argument provided to the program.");
  PmergeMe::checkInteger(argc, argv);
  PmergeMe::checkDuplicate();
}

void PmergeMe::printArray(std::vector<int> &vec) {
  for (vec_iterator it = vec.begin(); it < vec.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::printTime(clock_t time, std::string name) {
  std::cout << "Time to process a range of " << _size << " elements with "
            << name << " : "
            << (static_cast<double>(time)) / CLOCKS_PER_SEC * 1e6 << " us"
            << std::endl;
}

void PmergeMe::execute(int argc, char **argv) {
  clock_t vecterTime, dequeTime;

  PmergeMe::checkArgument(argc, argv);

  std::cout << "Before: ";
  PmergeMe::printArray(_vec);

  // std::vector
  vecterTime = std::clock();
  PmergeMe::vectorMergeInsertionSort();
  vecterTime = std::clock() - vecterTime;

  // std::deque
  dequeTime = std::clock();
  PmergeMe::vectorMergeInsertionSort();
  dequeTime = std::clock() - dequeTime;

  std::cout << "After: ";
  PmergeMe::printArray(_vec);

  printTime(vecterTime, "std::vector");
  printTime(dequeTime, "std::deque");
}

// ---------------------------------------------------------------------
// std::vector Ford-Johnson Algorithm
void PmergeMe::hardSort(vecMatrix &vec) {
  if (vec.size() == 2) {
    if (vec[0].front() > vec[1].front()) std::swap(vec[0], vec[1]);
  } else if (vec.size() == 3) {
    int a = vec[0].front();
    int b = vec[1].front();
    int c = vec[2].front();

    if (a > b) std::swap(vec[0], vec[1]);
    if (a > c) std::swap(vec[0], vec[2]);
    if (b > c) std::swap(vec[1], vec[2]);
  }
}

void PmergeMe::merge(vecMatrix &vec) {
  size_t end = vec.size();
  if (end < 3) return;

  for (size_t i = 0; i < end / 2; ++i) {
    int a = vec[i].front();
    int b = vec[i + 1].front();
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
}

int PmergeMe::vectorJacobsthal(int n) {
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

std::vector<int> PmergeMe::vectorGenerateOrder(int max) {
  int n = 1;
  while (max > PmergeMe::vectorJacobsthal(n)) n++;

  std::vector<int> order;
  for (int i = 1; i <= n; ++i) {
    for (int j = PmergeMe::vectorJacobsthal(i);
         j > PmergeMe::vectorJacobsthal(i - 1); --j) {
      if (j < max) order.push_back(j);
    }
  }
  return order;
}

void PmergeMe::binarySearchInsertion(vecMatrix &vec, std::vector<int> target) {
  size_t left = 0;
  size_t right = vec.size();

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (vec[mid].front() < target.front()) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  vec.insert(vec.begin() + left, target);
}

void PmergeMe::devide(vecMatrix &vec) {
  if (vec[0].size() == 1) return;

  vecMatrix loserVec;

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

  std::vector<int> order = vectorGenerateOrder(loserVec.size());
  for (vec_iterator it = order.begin(); it < order.end(); ++it) {
    PmergeMe::binarySearchInsertion(vec, loserVec[*it]);
  }
}

void PmergeMe::divideAndConquer(vecMatrix &vec) {
  std::vector<int> leftVec;

  if (vec.size() == 2 or vec.size() == 3) {
    PmergeMe::hardSort(vec);
    return;
  }

  if (vec.size() % 2 == 1) {
    leftVec = vec.back();
    vec.pop_back();
  }

  PmergeMe::merge(vec);
  PmergeMe::divideAndConquer(vec);

  PmergeMe::devide(vec);
  if (not leftVec.empty()) PmergeMe::binarySearchInsertion(vec, leftVec);
}

void PmergeMe::vectorMergeInsertionSort(void) {
  vecMatrix vec;

  for (vec_iterator it = _vec.begin(); it < _vec.end(); ++it) {
    std::vector<int> newVec(1, *it);
    vec.push_back(newVec);
  }

  if (vec.size() == 1) return;

  PmergeMe::divideAndConquer(vec);

  _vec.clear();
  for (vecvec_iterator vit = vec.begin(); vit < vec.end(); ++vit) {
    _vec.push_back((*vit).front());
  }
}

// ---------------------------------------------------------------------
// std::deque Ford-Johnson Algorithm
void PmergeMe::hardSort(deqMatrix &deq) {
  if (deq.size() == 2) {
    if (deq[0].front() > deq[1].front()) std::swap(deq[0], deq[1]);
  } else if (deq.size() == 3) {
    int a = deq[0].front();
    int b = deq[1].front();
    int c = deq[2].front();

    if (a > b) std::swap(deq[0], deq[1]);
    if (a > c) std::swap(deq[0], deq[2]);
    if (b > c) std::swap(deq[1], deq[2]);
  }
}

void PmergeMe::merge(deqMatrix &deq) {
  size_t end = deq.size();
  if (end < 3) return;

  for (size_t i = 0; i < end / 2; ++i) {
    int a = deq[i].front();
    int b = deq[i + 1].front();
    if (a > b) {
      for (deq_reverse_iterator rit = deq[i + 1].rbegin();
           rit < deq[i + 1].rend(); ++rit) {
        deq[i].push_back(*rit);
      }
      deq.erase(deq.begin() + i + 1);
    } else {
      for (deq_reverse_iterator rit = deq[i].rbegin(); rit < deq[i].rend();
           ++rit) {
        deq[i + 1].push_back(*rit);
      }
      deq.erase(deq.begin() + i);
    }
  }
}

int PmergeMe::dequeJacobsthal(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  std::deque<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= n; ++i) {
    dp[i] = dp[i - 1] + 2 * dp[i - 2];
  }

  return dp[n];
}

std::deque<int> PmergeMe::dequeGenerateOrder(int max) {
  int n = 1;
  while (max > PmergeMe::dequeJacobsthal(n)) n++;

  std::deque<int> order;
  for (int i = 1; i <= n; ++i) {
    for (int j = PmergeMe::dequeJacobsthal(i);
         j > PmergeMe::dequeJacobsthal(i - 1); --j) {
      if (j < max) order.push_back(j);
    }
  }
  return order;
}

void PmergeMe::binarySearchInsertion(deqMatrix &deq, std::deque<int> target) {
  size_t left = 0;
  size_t right = deq.size();

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (deq[mid].front() < target.front()) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  deq.insert(deq.begin() + left, target);
}

void PmergeMe::devide(deqMatrix &deq) {
  if (deq[0].size() == 1) return;

  deqMatrix loserDeq;

  for (deqdeq_iterator vit = deq.begin(); vit < deq.end(); ++vit) {
    std::deque<int> &tmpDeq = *vit;
    std::deque<int> newDeq;
    for (deq_reverse_iterator rit = tmpDeq.rbegin();
         rit < tmpDeq.rbegin() + tmpDeq.size() / 2; ++rit) {
      newDeq.push_back(*rit);
    }
    size_t size = tmpDeq.size();
    for (size_t i = 0; i < size / 2; ++i) tmpDeq.pop_back();
    loserDeq.push_back(newDeq);
  }

  deq.insert(deq.begin(), loserDeq[0]);

  std::deque<int> order = dequeGenerateOrder(loserDeq.size());
  for (deq_iterator it = order.begin(); it < order.end(); ++it) {
    PmergeMe::binarySearchInsertion(deq, loserDeq[*it]);
  }
}

void PmergeMe::divideAndConquer(deqMatrix &deq) {
  std::deque<int> leftDeq;

  if (deq.size() == 2 or deq.size() == 3) {
    PmergeMe::hardSort(deq);
    return;
  }

  if (deq.size() % 2 == 1) {
    leftDeq = deq.back();
    deq.pop_back();
  }

  PmergeMe::merge(deq);
  PmergeMe::divideAndConquer(deq);

  PmergeMe::devide(deq);
  if (not leftDeq.empty()) PmergeMe::binarySearchInsertion(deq, leftDeq);
}

void PmergeMe::dequeMergeInsertionSort(void) {
  deqMatrix deq;

  for (deq_iterator it = _deq.begin(); it < _deq.end(); ++it) {
    std::deque<int> newDeq(1, *it);
    deq.push_back(newDeq);
  }

  if (deq.size() == 1) return;

  PmergeMe::divideAndConquer(deq);

  _deq.clear();
  for (deqdeq_iterator vit = deq.begin(); vit < deq.end(); ++vit) {
    _deq.push_back((*vit).front());
  }
}