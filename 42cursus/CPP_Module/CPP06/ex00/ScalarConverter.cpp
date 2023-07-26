#include "ScalarConverter.hpp"

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>

double ScalarConverter::num = 0;
char ScalarConverter::c = 0;
int ScalarConverter::i = 0;
float ScalarConverter::f = 0;
double ScalarConverter::d = 0;
bool ScalarConverter::overflow[2] = {false};

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

int ScalarConverter::countPrecision(char *str) {
  if (std::strchr(str, 'f') == NULL)
    return std::strchr(str, '\0') - std::strchr(str, '.') - 1;
  return std::strchr(str, 'f') - std::strchr(str, '.') - 1;
}

void ScalarConverter::checkOverflow(void) {
  if (std::numeric_limits<char>::min() > ScalarConverter::d or
      std::numeric_limits<char>::max() < ScalarConverter::d)
    ScalarConverter::overflow[CHAR] = true;
  if (std::numeric_limits<int>::min() > ScalarConverter::d or
      std::numeric_limits<int>::max() < ScalarConverter::d)
    ScalarConverter::overflow[INT] = true;
}

void ScalarConverter::print(char *str, int p) {
  ScalarConverter::checkOverflow();

  // char
  if (overflow[CHAR] == true or ScalarConverter::isPseudo(str))
    std::cout << "char: impossible" << std::endl;
  else if (ScalarConverter::i < 32 or ScalarConverter::i > 126)
    std::cout << "char: Non displayable" << std::endl;
  else {
    std::cout << "char: '" << ScalarConverter::c << "'" << std::endl;
  }

  // int
  if (overflow[INT] == true or ScalarConverter::isPseudo(str))
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << ScalarConverter::i << std::endl;

  // float
  std::cout << "float: " << std::fixed << std::setprecision(p)
            << ScalarConverter::f << "f" << std::endl;

  // double
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

void ScalarConverter::intCasting(char *str, double n) {
  if ((static_cast<double>(std::numeric_limits<int>::min()) > n or
       static_cast<double>(std::numeric_limits<int>::max()) < n)) {
    std::cout << "invalid" << std::endl;
    return;
  }

  int i = static_cast<int>(n);

  ScalarConverter::c = static_cast<char>(i);
  ScalarConverter::i = i;
  ScalarConverter::f = static_cast<float>(i);
  ScalarConverter::d = static_cast<double>(i);

  ScalarConverter::print(str, 1);
}

void ScalarConverter::floatCasting(char *str, double n) {
  float f = static_cast<float>(n);

  ScalarConverter::c = static_cast<char>(f);
  ScalarConverter::i = static_cast<int>(f);
  ScalarConverter::f = f;
  ScalarConverter::d = static_cast<double>(f);

  ScalarConverter::print(str, ScalarConverter::countPrecision(str));
}

void ScalarConverter::doubleCasting(char *str, double n) {
  double d = n;

  ScalarConverter::c = static_cast<char>(d);
  ScalarConverter::i = static_cast<int>(d);
  ScalarConverter::f = static_cast<float>(d);
  ScalarConverter::d = d;

  ScalarConverter::print(str, ScalarConverter::countPrecision(str));
}

void ScalarConverter::casting(char *str) {
  ScalarConverter::Type type = ScalarConverter::getType(str);

  if (type == CHAR)
    ScalarConverter::charCasting(str);
  else if (type == INT)
    ScalarConverter::intCasting(str, ScalarConverter::num);
  else if (type == FLOAT)
    ScalarConverter::floatCasting(str, ScalarConverter::num);
  else if (type == DOUBLE)
    ScalarConverter::doubleCasting(str, ScalarConverter::num);
  else
    std::cout << "invalid" << std::endl;
}
