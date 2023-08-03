#include "RPN.hpp"

#include <iostream>

void RPN::printError(void) { std::cout << "Error" << std::endl; }

RPN::RPN(void) : _stack() {}

RPN::RPN(RPN const& rpn) {}

RPN::~RPN(void) {}

RPN& RPN::operator=(RPN const& rpn) {}
