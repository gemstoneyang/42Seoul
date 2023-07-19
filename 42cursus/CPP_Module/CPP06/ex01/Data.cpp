#include "Data.hpp"

Data::Data(void) : num(42) {}
Data::Data(Data const& data) : num(data.num) {}
Data::~Data(void) {}

Data& Data::operator=(Data const& data) {
  if (this == &data) return *this;
  num = data.num;
  return *this;
}