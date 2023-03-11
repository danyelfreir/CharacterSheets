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
};