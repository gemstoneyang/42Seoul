#include <iostream>

#include "iter.hpp"

void multiple(int& n) { n *= 2; }

int main(void) {
  int arr[10];

  for (int i = 0; i < 10; i++) {
    arr[i] = i;
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  iter(arr, 10, multiple);

  for (int i = 0; i < 10; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
