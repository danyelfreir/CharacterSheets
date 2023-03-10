#include "../inc/Creature.h"

Creature::Creature(int life, int strength, int intelligence, bool natural,
                   int disquiet)
    : Being(life, strength, intelligence) {
  this->set_natural(natural);
  this->set_disquiet(disquiet);
}

bool Creature::get_natural() { return this->_natural; };

int Creature::get_disquiet() { return this->_disquiet; }

void Creature::set_natural(bool natural) { this->_natural = natural; }

void Creature::set_disquiet(int disquiet) { this->_disquiet = disquiet; }

void Creature::print() {
  Being::print();
  std::cout << "Natural -> " << (this->get_natural() ? 1 : 0) << "\n"
            << "Disquiet -> " << this->get_disquiet() << "\n";
}
