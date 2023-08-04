#pragma once
#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <stack>
#include <string>

class RPN {
 public:
  static void printError(void);
  static int calculate(char* argv);

 private:
  static std::stack<int> _stack;

  static bool isValidChar(char c);
  static bool isValidString(char* argv);
  static void executeOperation(char op);

  RPN(void);
  RPN(RPN const& rpn);
  ~RPN(void);
  RPN& operator=(RPN const& rpn);
};

#endif
// 나누기 0 처리하기