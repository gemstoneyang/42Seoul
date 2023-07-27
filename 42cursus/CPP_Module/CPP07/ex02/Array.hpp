#pragma once
#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

template <typename T>
class Array {
 public:
  Array(void);
  Array(unsigned int n);
  Array(Array const& array);
  ~Array(void);

  Array& operator=(Array const& array);
  T& operator[](unsigned int idx);

  unsigned int const& size(void) const;

 private:
  T* arr;
  unsigned int n;
};

#include "Array.tpp"

#endif