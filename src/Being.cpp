#include "../inc/Being.h"

#include <cstdlib>
#include <random>

int Being::s_being_num = 0;

Being::Being(int life, int strength, int intelligence) {
    this->set_category("Being");
    this->set_id();
    this->set_life(life);
    this->set_strength(strength);
    this->set_intelligence(intelligence);
}

int Being::get_id() { return this->_id; }

int Being::get_life() { return this->_life; }

int Being::get_strength() { return this->_strength; }

int Being::get_intelligence() { return this->_intelligence; }

std::string Being::get_category() { return this->_category; }

void Being::set_id() {
    int id = this->s_being_num;
    this->s_being_num++;
    this->_id = id;
}

void Being::set_life(int life) {
    if (life < 0)
        this->_life = 0;
    else if (life > 10)
        this->_life = 10;
    else
        this->_life = life;
}

void Being::set_strength(int strength) {
    if (strength < 0)
        this->_strength = 0;
    else if (strength > 10)
        this->_strength = 10;
    else
        this->_strength = strength;
}

void Being::set_intelligence(int intelligence) {
    if (intelligence < 0)
        this->_intelligence = 0;
    else if (intelligence > 10)
        this->_intelligence = 10;
    else
        this->_intelligence = intelligence;
}

void Being::set_category(std::string category) { this->_category = category; }

void Being::print() {
    std::cout << "\tID -> " << this->get_id() << "\n"
              << "\tCategory -> " << this->get_category() << "\n"
              << "\tLife -> " << this->get_life() << "\n"
              << "\tStrength -> " << this->get_strength() << "\n"
              << "\tIntelligence -> " << this->get_intelligence() << "\n";
}
