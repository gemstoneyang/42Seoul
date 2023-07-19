#pragma once
#ifndef __SERIALIZATION_HPP__
#define __SERIALIZATION_HPP__

#include <stdint.h>

#include "Data.hpp"

class Serialization {
 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);

 private:
  Serialization(void);
  Serialization(Serialization const& serialization);
  ~Serialization(void);

  Serialization& operator=(Serialization const& serialization);
};

#endif