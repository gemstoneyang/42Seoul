#pragma once
#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <stack>

class RPN {
 public:
  RPN(void);
  RPN(RPN const& rpn);
  ~RPN(void);

  RPN& operator=(RPN const& rpn);

  static void printError(void);

 private:
  std::stack _stack;
};

#endif
// 나누기 0 처리하기