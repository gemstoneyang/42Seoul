#include "RPN.hpp"

#include <iostream>
#include <stdexcept>

std::stack<int> RPN::_stack;

void RPN::printError(void) { std::cout << "Error" << std::endl; }

bool RPN::isValidChar(char c) {
  if (c >= '0' and c <= '9')
    return true;
  else if (c == '+' or c == '-' or c == '*' or c == '/' or c == ' ')
    return true;
  return false;
}

bool RPN::isValidString(char* argv) {
  for (size_t i = 0; i < std::strlen(argv); i++) {
    if (RPN::isValidChar(argv[i]) == false) return false;
  }
  return true;
}

void RPN::executeOperation(char op) {
  if (_stack.size() < 2) throw std::invalid_argument("Invalid argument");

  int n2 = _stack.top();
  _stack.pop();
  int n1 = _stack.top();
  _stack.pop();

  switch (op) {
    case '+':
      _stack.push(n1 + n2);
      break;
    case '-':
      _stack.push(n1 - n2);
      break;
    case '*':
      _stack.push(n1 * n2);
      break;
    case '/':
      if (n2 == 0) throw std::invalid_argument("Division by zero");
      _stack.push(n1 / n2);
      break;
  }
}

int RPN::calculate(char* argv) {
  if (RPN::isValidString(argv) == false)
    throw std::invalid_argument("Invalid argument");

  for (size_t i = 0; i < std::strlen(argv); i++) {
    if (argv[i] == ' ')
      continue;
    else if (isnumber(argv[i]) == true)
      _stack.push(argv[i] - '0');
    else
      RPN::executeOperation(argv[i]);
  }
  if (_stack.size() != 1) throw std::invalid_argument("Invalid argument");

  return _stack.top();
}