
#pragma once
#include "Creature.h"
#include "EldritchHorror.h"
#include <iostream>
#include <string>

class Species {
  public:
    Species(std::string name, int life, int strenght, int intellegence, bool natural,
            int disquiet, bool is_eldritch);
    Species(std::string name, Creature *creature);
    int get_id();
    std::string get_name();
    std::string get_category();
    int get_life();
    int get_strength();
    int get_intelligence();
    bool get_natural();
    int get_disquiet();
    int get_traumatism();
    void set_name(std::string name);
    void set_life(int life);
    void set_strength(int strength);
    void set_intelligence(int intelligence);
    void set_natural(bool natural);
    void set_disquiet(int disquiet);

    void print();

  private:
    Creature *_creature;
    std::string _name;
    std::string _nature;
    int _traumatism;
};