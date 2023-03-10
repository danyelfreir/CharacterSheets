#pragma once
#include <iostream>

#include "../inc/Creature.h"

class EldritchHorror : public Creature {
private:
  int _traumatism;

public:
  EldritchHorror(int life, int strength, int intelligence, bool natural,
                 int disquiet, int traumatism);
  int get_traumatism();
  void set_traumatism(int traumatism);
  void print();
};