#include "ScalarConverter.hpp"

#include <cstdlib>
#include <cstring>
#include <iostream>

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
  std::strtod(str, &end);

  if (std::strcmp(str, "") == 0) return INVALID;
  if (*end == '\0') {
    if (isPseudo(str) or hasDot(str)) return DOUBLE;
    return INT;
  }
  if (std::strlen(str) == 1)
    return CHAR;
  else if (isPseudo(str) or
           (*end == 'f' and *(end + 1) == '\0' and hasDot(str)))
    return FLOAT;
  else
    return INVALID;
}

void ScalarConverter::print(char c, int i, float f, double d) {
  std::cout << "char: '" << c << "'" << std::endl;
  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << f << std::endl;
  std::cout << "double: " << d << std::endl;
}

void ScalarConverter::charCasting(char *str) {
  char c = str[0];

  int i = static_cast<int>(c);
  float f = static_cast<float>(c);
  double d = static_cast<double>(c);

  ScalarConverter::print(c, i, f, d);
}

void ScalarConverter::casting(char *str) {
  ScalarConverter::Type type = ScalarConverter::getType(str);

  if (type == CHAR) ScalarConverter::charCasting(str);
}
