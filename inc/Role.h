#pragma once
#include <iostream>

#include "Investigator.h"
#include "Person.h"

class Role {
  private:
    Person *_person;
    std::string _name;
    int _terror;

  public:
    Role(std::string name, int min_hp, int max_hp, int min_str, int max_str, int min_int,
         int max_int, std::string gender, bool isInvestigator);
    Role(std::string name, Person *person);
    int get_id();
    std::string get_name();
    std::string get_category();
    int get_life();
    int get_strength();
    int get_intelligence();
    std::string get_gender();
    int get_fear();
    int get_terror();
    void set_name(std::string name);
    void set_life(int life);
    void set_strength(int strength);
    void set_intelligence(int intelligence);
    void set_gender(std::string gender);
    void set_fear(int fear);
    void print();
    bool operator==(Role &that);
};
