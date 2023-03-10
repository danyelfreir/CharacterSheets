#include "../inc/Investigator.h"

Investigator::Investigator(int life, int strength, int intelligence,
                           std::string gender, int fear, int terror)
    : Person(life, strength, intelligence, gender, fear) {
  this->set_category("Investigator");
  this->set_terror(terror);
}

int Investigator::get_terror() { return this->_terror; }

void Investigator::set_terror(int terror) {
  if (terror < 0)
    this->_terror = 0;
  else if (terror > 3)
    this->_terror = 3;
  else
    this->_terror = terror;
}

void Investigator::print() {
  Person::print();
  std::cout << "\tTerror -> " << this->get_terror() << "\n";
}
