#pragma once
#include <iostream>

#include "Being.h"

class Person : public Being {
private:
  std::string _gender;
  int _fear;

public:
  Person(int life, int strength, int intelligence, std::string gender,
         int fear);
  std::string get_gender();
  void set_gender(std::string gender);
  int get_fear();
  void set_fear(int fear);
  void print() override;
};
