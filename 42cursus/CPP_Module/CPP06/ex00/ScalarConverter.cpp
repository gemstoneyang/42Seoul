#include "ScalarConverter.hpp"

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

double ScalarConverter::num = 0;
char ScalarConverter::c = 0;
int ScalarConverter::i = 0;
float ScalarConverter::f = 0;
double ScalarConverter::d = 0;
char *ScalarConverter::str = 0;

inline bool ScalarConverter::hasDot(char *str) {
  return (std::strchr(str, '.') != NULL);
}

bool ScalarConverter::isPseudo(char *str) {
  char const *pseudo[8] = {"inf",  "+inf",  "-inf",  "nan",
                           "inff", "+inff", "-inff", "nanf"};

  for (int i = 0; i < 8; i++)
    if (std::strcmp(str, pseudo[i]) == 0) return true;
  return false;
}

ScalarConverter::Type ScalarConverter::getType(char *str) {
  char *end;
  ScalarConverter::num = std::strtod(str, &end);

  if (std::strcmp(str, "") == 0)
    return INVALID;
  else if (*end == '\0') {
    if (isPseudo(str) or hasDot(str))
      return DOUBLE;
    else
      return INT;
  } else if (std::strlen(str) == 1)
    return CHAR;
  else if (isPseudo(str) or
           (*end == 'f' and *(end + 1) == '\0' and hasDot(str)))
    return FLOAT;

  return INVALID;
}

void ScalarConverter::print(char *str, int p) {
  if (ScalarConverter::isPseudo(str))
    std::cout << "char: impossible" << std::endl;
  else if (ScalarConverter::i < 32 or ScalarConverter::i > 126)
    std::cout << "char: Non displayable" << std::endl;
  else {
    std::cout << "char: '" << ScalarConverter::c << "'" << std::endl;
  }
  if (ScalarConverter::isPseudo(str))
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << ScalarConverter::i << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(p)
            << ScalarConverter::f << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(p)
            << ScalarConverter::d << std::endl;
}

void ScalarConverter::charCasting(char *str) {
  char c = str[0];
  ScalarConverter::c = c;
  ScalarConverter::i = static_cast<int>(c);
  ScalarConverter::f = static_cast<float>(c);
  ScalarConverter::d = static_cast<double>(c);

  ScalarConverter::print(str, 1);
}

void ScalarConverter::intCasting(double n) {
  int i = static_cast<int>(n);
  ScalarConverter::c = static_cast<char>(i);
  ScalarConverter::i = i;
  ScalarConverter::f = static_cast<float>(i);
  ScalarConverter::d = static_cast<double>(i);

  ScalarConverter::print(str, 1);
}

void ScalarConverter::floatCasting(char *str, double n) {
  float f = static_cast<float>(n);

  char c = static_cast<char>(f);
  if (ScalarConverter::isPseudo(str))
    std::cout << "char: impossible" << std::endl;
  else if (std::isprint(c))
    std::cout << "char: '" << c << "'" << std::endl;
  else {
    std::cout << "char: Non displayable" << std::endl;
  }

  int i = static_cast<int>(f);
  if (ScalarConverter::isPseudo(str))
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << i << std::endl;
  std::cout << "float: " << std::fixed << f << "f" << std::endl;
  std::cout << "double: " << std::fixed << static_cast<double>(f) << std::endl;
}

void ScalarConverter::doubleCasting(char *str, double n) {
  double d = n;

  char c = static_cast<char>(d);
  if (ScalarConverter::isPseudo(str))
    std::cout << "char: impossible" << std::endl;
  else if (std::isprint(c))
    std::cout << "char: '" << c << "'" << std::endl;
  else {
    std::cout << "char: Non displayable" << std::endl;
  }

  int i = static_cast<int>(d);
  if (ScalarConverter::isPseudo(str))
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << i << std::endl;
  std::cout << "float: " << std::fixed << static_cast<float>(d) << "f"
            << std::endl;
  std::cout << "double: " << std::fixed << d << std::endl;
}

void ScalarConverter::casting(char *str) {
  ScalarConverter::Type type = ScalarConverter::getType(str);

  if (type == CHAR)
    ScalarConverter::charCasting(str);
  else if (type == INT)
    ScalarConverter::intCasting(ScalarConverter::num);
  else if (type == FLOAT)
    ScalarConverter::floatCasting(str, ScalarConverter::num);
  else if (type == DOUBLE)
    ScalarConverter::doubleCasting(str, ScalarConverter::num);
  else
    std::cout << "invalid" << std::endl;
}
