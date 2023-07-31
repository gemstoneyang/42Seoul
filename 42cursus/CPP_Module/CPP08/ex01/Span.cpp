#include "Span.hpp"

#include <iostream>

Span::Span(unsigned int n) : _vec(), _maxSize(n) {}

Span::Span(Span const& span) : _vec(span._vec), _maxSize(span._maxSize) {}

Span::~Span(void) {}

Span& Span::operator=(Span const& span) {
  if (this == &span) return *this;

  _vec = span._vec;
  _maxSize = span._maxSize;
  return *this;
}

void Span::addNumber(int n) {
  if (_vec.size() >= _maxSize)
    throw std::length_error("Array is full: Maximum capacity reached");

  _vec.push_back(n);
  std::sort(_vec.begin(), _vec.end());
}

int Span::shortestSpan(void) const {
  if (_vec.size() < 2)
    throw std::logic_error("Too few elements: Must be at least two elements");

  int dist = _vec[1] - _vec[0];
  for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end() - 1;
       ++it)
    if (dist > *(it + 1) - *it) dist = *(it + 1) - *it;

  return dist;
}

int Span::longestSpan(void) const {
  if (_vec.size() < 2)
    throw std::logic_error("Too few elements: Must be at least two elements");

  int min = *(_vec.begin());
  int max = *(_vec.end() - 1);
  return (max - min);
}

unsigned int Span::getSize(void) const { return _vec.size(); }

void Span::print(void) const {
  if (_vec.size() < 1) return;

  for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end();
       ++it)
    std::cout << *it << " ";

  std::cout << std::endl;
}
