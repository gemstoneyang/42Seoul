#include <exception>
#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main(void) {
  std::vector<int> vec(5);

  for (int i = 0; i < static_cast<int>(vec.size()); i++) {
    vec[i] = i * 10;
  }

  std::cout << ::easyfind(vec, 20) << std::endl;

  try {
    std::cout << ::easyfind(vec, 42) << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
