#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <cstddef>

template <typename T>
void iter(T* arr, size_t len, void (*func)(T&)) {
  for (size_t i = 0; i < len; i++) {
    (*func)(arr[i]);
  }
}

template <typename T>
void iter(T* arr, size_t len, void (*func)(T const&)) {
  for (size_t i = 0; i < len; i++) {
    (*func)(arr[i]);
  }
}

template <typename T>
void tprint(T const& a) {
  std::cout << a << std::endl;
}

#endif