#pragma once
#include <fstream>
#include <iostream>

#include "../inc/Role.h"
#include "../inc/Species.h"
#include "RoleSpeciesMap.h"

class RoleCreator {
  private:
    RoleSpeciesMap<std::string> rsm;
    std::vector<std::string> get_filenames();

  public:
    RoleCreator();
    void read_from_file(std::vector<Role> &roles, std::vector<Species> &species);
    void write_species_to_file(Species &species);
    void write_role_to_file(Role &role);
    void create_species(std::vector<Species> &species, std::string name, Creature *creature);
    void create_role(std::vector<Role> &roles, std::string name, Person *person);
    void delete_species_or_role(std::vector<Species> &species, std::vector<Role> &roles,
                                int being_id);
    void delete_file(std::string filename);
};