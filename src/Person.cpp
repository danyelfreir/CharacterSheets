#include "../inc/Person.h"

Person::Person(int life, int strength, int intelligence, std::string gender, int fear)
    : Being(life, strength, intelligence) {
    this->set_category("Person");
    this->set_gender(gender);
    this->set_fear(fear);
}

std::string Person::get_gender() { return this->_gender; }

int Person::get_fear() { return this->_fear; }

void Person::set_gender(std::string gender) {
    if (gender.size() == 0)
        this->_gender = "Unknown";
    else
        this->_gender = gender;
}

void Person::set_fear(int fear) {
    if (fear < 0)
        this->_fear = 0;
    else if (fear > 10)
        this->_fear = 10;
    else
        this->_fear = fear;
}

void Person::print() {
    Being::print();
    std::cout << "\tGender -> " << this->get_gender() << "\n"
              << "\tFear -> " << this->get_fear() << "\n";
}
