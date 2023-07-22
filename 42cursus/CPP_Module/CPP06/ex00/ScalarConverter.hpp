#pragma once
#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

class ScalarConverter {
 public:
  enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID };
  static void casting(char* str);

 private:
  ScalarConverter(void);
  ScalarConverter(ScalarConverter const& scalarconverter);
  ~ScalarConverter(void);

  ScalarConverter& operator=(ScalarConverter const& scalarconverter);

  static inline bool hasDot(char* str);
  static bool isPseudo(char* str);
  static Type getType(char* str);
  static void print(char c, int i, float f, double d);
  static void charCasting(char* str);
};

#endif