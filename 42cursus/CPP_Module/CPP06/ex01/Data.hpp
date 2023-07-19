#pragma once
#ifndef __DATA_HPP__
#define __DATA_HPP__

struct Data {
 public:
  Data(void);
  Data(Data const& data);
  ~Data(void);

  Data& operator=(Data const& data);

  int num;
};

#endif