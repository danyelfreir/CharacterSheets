#pragma once
#include "Being.h"
#include <iostream>

class Creature : public Being {
private:
  bool _natural;
  int _disquiet;

public:
  Creature(int life, int strength, int intelligence, bool natural,
           int disquiet);
  bool get_natural();
  int get_disquiet();
  void set_natural(bool natural);
  void set_disquiet(int disquiet);
  void print();
};
