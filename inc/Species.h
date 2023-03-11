
#pragma once
#include <string>
#include <iostream>
#include "Creature.h"
#include "EldritchHorror.h"

class Species {
    public: 
        Species(std::string name, int life, int strenght, int intellegence, bool natural, int disquiet, bool is_eldritch);
        std::string get_name();
        int get_life();
        int get_strength();
        int get_intelligence();
        bool get_natural();
        int get_disquiet();
        void print();
    private:
        Creature *_creature;
        std::string _name;
        std::string _nature;
};