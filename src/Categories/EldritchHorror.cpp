#include "../../inc/EldritchHorror.h"

EldritchHorror::EldritchHorror(int life, int strength, int intelligence, bool natural,
                               int disquiet, int traumatism)
    : Creature(life, strength, intelligence, natural, disquiet) {
    this->set_category("Eldritch Horror");
    this->set_traumatism(traumatism);
}

int EldritchHorror::get_traumatism() { return this->_traumatism; }

void EldritchHorror::set_traumatism(int traumatism) { this->_traumatism = traumatism; }

void EldritchHorror::print() {
    Creature::print();
    std::cout << "\tTraumatism -> " << this->get_traumatism() << "\n";
}