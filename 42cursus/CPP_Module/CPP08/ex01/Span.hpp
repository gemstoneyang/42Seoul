#pragma once
#ifndef __SPAN_HPP__
#define __SPAN_HPP__

class Span {
 public:
  Span(unsigned int n);
  Span(Span const& span);
  ~Span(void);

  Span& operator=(Span const& span);

  void addNumber(int n);
  int const& shortestSpan(void) const;
  int const& longestSpan(void) const;

 private:
  Span(void);
};

#endif