#pragma once
#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

class ScalarConverter {
 public:
  enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID };
  static void casting(char* str);

 private:
  static double num;
  static char c;
  static int i;
  static float f;
  static double d;
  static bool overflow[4];

  static inline bool hasDot(char* str);
  static bool isPseudo(char* str);
  static Type getType(char* str);
  static int countPrecision(char* str);
  static void checkOverflow(char* str);

  static void print(char* str, int p);
  static void charCasting(char* str);
  static void intCasting(char* str, double n);
  static void floatCasting(char* str, double n);
  static void doubleCasting(char* str, double n);

  ScalarConverter(void);
  ScalarConverter(ScalarConverter const& scalarconverter);
  ~ScalarConverter(void);

  ScalarConverter& operator=(ScalarConverter const& scalarconverter);
};

#endif