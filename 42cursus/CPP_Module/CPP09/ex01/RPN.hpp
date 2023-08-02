#pragma once
#ifndef __RPN_HPP__
#define __RPN_HPP__

class RPN {
 public:
  RPN(void);
  RPN(RPN const& rpn);
  ~RPN(void);

  RPN& operator=(RPN const& rpn);

  static void printError(void);

 private:
};

#endif