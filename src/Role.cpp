#include "../inc/Role.h"

Role::Role(std::string name, int min_hp, int max_hp, int min_str, int max_str, int min_int,
           int max_int, std::string gender, bool is_investigator) {
    int life = (rand() % (max_hp - min_hp + 1)) + min_hp;
    int strength = (rand() % (max_str - min_str + 1)) + min_str;
    int intelligence = (rand() % (max_int - min_int + 1)) + min_int;
    if (is_investigator)
        this->_person =
            new Investigator(life, strength, intelligence, gender, rand() % 11, rand() % 4);
    else
        this->_person = new Person(life, strength, intelligence, gender, rand() % 11);
    this->set_name(name);
}

Role::Role(std::string name, Person *person) {
    this->_person = person;
    this->set_name(name);
}

std::string Role::get_name() { return this->_name; }

int Role::get_life() { return this->_person->get_life(); }

int Role::get_strength() { return this->_person->get_strength(); }

int Role::get_intelligence() { return this->_person->get_intelligence(); }

std::string Role::get_gender() { return this->_person->get_gender(); }

int Role::get_fear() { return this->_person->get_fear(); }

void Role::set_name(std::string name) { this->_name = name; }

void Role::set_life(int life) { this->_person->set_life(life); }

void Role::set_strength(int strength) { this->_person->set_strength(strength); }

void Role::set_intelligence(int intelligence) { this->_person->set_intelligence(intelligence); }

void Role::set_gender(std::string gender) { this->_person->set_gender(gender); }

void Role::set_fear(int fear) { this->_person->set_fear(fear); }

void Role::print() {
    std::cout << this->_name << std::endl;
    this->_person->print();
}

bool Role::operator==(Role &that) { return this->get_name().compare(that.get_name()) == 0; }
