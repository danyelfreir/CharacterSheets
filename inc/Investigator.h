#pragma once
#include <iostream>

#include "../inc/Person.h"

class Investigator : public Person {
private:
  int _terror;

public:
  Investigator(int life, int strength, int intelligence, std::string gender,
               int fear, int terror);
  int get_terror();
  void set_terror(int terror);
  void print() override;
};
