#include "../inc/Species.h"

Species::Species(std::string name, int life, int strenght, int intellegence, bool natural,
                 int disquiet, bool is_eldritch) {
    if (is_eldritch) {
        this->_traumatism = disquiet;
        this->_creature =
            new EldritchHorror(life, strenght, intellegence, false, 10, this->_traumatism);
    } else
        this->_creature = new Creature(life, strenght, intellegence, natural, disquiet);
    this->_name = name;
}

Species::Species(std::string name, Creature *creature) {
    this->set_name(name);
    this->_creature = creature;
}

int Species::get_id() { return this->_creature->get_id(); }

std::string Species::get_name() { return this->_name; }

std::string Species::get_category() { return this->_creature->get_category(); }

int Species::get_life() { return this->_creature->get_life(); }

int Species::get_strength() { return this->_creature->get_strength(); }

int Species::get_intelligence() { return this->_creature->get_intelligence(); }

bool Species::get_natural() { this->_creature->get_natural(); }

int Species::get_disquiet() { this->_creature->get_disquiet(); }

int Species::get_traumatism() { return this->_traumatism; }

void Species::set_name(std::string name) { this->_name = name; }

void Species::set_life(int life) { this->_creature->set_life(life); }

void Species::set_strength(int strength) { this->_creature->set_strength(strength); }

void Species::set_intelligence(int intelligence) {
    this->_creature->set_intelligence(intelligence);
}

void Species::set_natural(bool natural) { this->_creature->set_natural(natural); }

void Species::set_disquiet(int disquiet) { this->_creature->set_disquiet(disquiet); }

void Species::print() {
    std::cout << "\nSpecies: " << this->_name << std::endl;
    this->_creature->print();
}
