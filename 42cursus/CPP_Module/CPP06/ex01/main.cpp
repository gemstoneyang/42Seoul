#include <iostream>

#include "Data.hpp"
#include "Serialization.hpp"

int main(void) {
  Data data;

  uintptr_t rawData;

  rawData = Serialization::serialize(&data);

  Data* dataPtr = Serialization::deserialize(rawData);

  std::cout << dataPtr << std::endl;
  std::cout << &data << std::endl;

  std::cout << data.num << std::endl;
  std::cout << dataPtr->num << std::endl;

  return 0;
}
