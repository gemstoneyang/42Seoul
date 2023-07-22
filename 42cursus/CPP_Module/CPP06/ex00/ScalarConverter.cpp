#include "ScalarConverter.hpp"

#include <cstdlib>
#include <cstring>

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
