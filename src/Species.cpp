#include "../inc/Species.h"

Species::Species(std::string name, int life, int strenght, int intellegence, bool natural,
                 int disquiet, bool is_eldritch) {
    if (is_eldritch)
        this->_creature = new EldritchHorror(life, strenght, intellegence, false, 10, disquiet);
    else
        this->_creature = new Creature(life, strenght, intellegence, natural, disquiet);
    this->_name = name;
}

std::string Species::get_name() { return this->_name; }

int Species::get_life() { return this->_creature->get_life(); }

int Species::get_strength() { return this->_creature->get_strength(); }

int Species::get_intelligence() { return this->_creature->get_intelligence(); }

bool Species::get_natural() { this->_creature->get_natural(); }

int Species::get_disquiet() { this->_creature->get_disquiet(); }

void Species::print() {
    std::cout << "Name: " << this->_name << std::endl;
    this->_creature->print();
}
