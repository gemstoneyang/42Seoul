#include <exception>
#include <iostream>

#include "PmergeMe.hpp"

int jacobsthal(int n) {
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

std::vector<int> generateOrder(int max) {
  int n = 1;
  while (max > jacobsthal(n)) n++;

  std::vector<int> order;
  for (int i = 1; i <= n; ++i) {
    for (int j = jacobsthal(i); j > jacobsthal(i - 1); --j) {
      if (j <= max) order.push_back(j);
    }
  }
  return order;
}

int main(int argc, char **argv) {
  try {
    PmergeMe::execute(argc, argv);
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  std::vector<int> vec = generateOrder(12);

  for (size_t i = 0; i < vec.size(); ++i) std::cout << vec[i] << " ";
  std::cout << std::endl;

  return 0;
}
