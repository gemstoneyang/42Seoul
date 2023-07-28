#pragma once
#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& arr, int n) {
  typename T::iterator it;

  it = std::find(arr.begin(), arr.end(), n);
  if (it != arr.end()) {
    return it;
  } else {
    throw std::logic_error("Can't find number");
  }
}

#endif