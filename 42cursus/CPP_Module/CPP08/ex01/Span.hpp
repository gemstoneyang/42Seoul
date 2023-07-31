#pragma once
#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>

class Span {
 public:
  Span(unsigned int n);
  Span(Span const& span);
  ~Span(void);

  Span& operator=(Span const& span);

  void addNumber(int n);

  template <typename InputIterator>
  void addNumber(InputIterator first, InputIterator last) {
    if (std::distance(first, last) > _maxSize - getSize())
      throw std::length_error("Array is full: Maximum capacity reached");

    for (InputIterator it = first; it != last; ++it) _vec.push_back(*it);

    std::sort(_vec.begin(), _vec.end());
  }

  int shortestSpan(void) const;
  int longestSpan(void) const;

  unsigned int getSize(void) const;
  void print(void) const;

 private:
  std::vector<int> _vec;
  unsigned int _maxSize;

  Span(void);
};

#endif