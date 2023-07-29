#include <iostream>

#include "Array.hpp"

int main(void) {
  Array<int> arr = Array<int>(5);

  std::cout << "Array size: " << arr.size() << std::endl;

  for (int i = 0; i < 5; i++) {
    arr[i] = i;
  }

  for (int i = 0; i < 5; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  try {
    arr[42] = 42;
    std::cout << "Wow.." << std::endl;
  } catch (std::exception &e) {
    std::cout << "exception!" << std::endl;
  }

  return 0;
}
