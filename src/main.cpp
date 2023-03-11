#include <iostream>
#include <vector>

#include "../inc/Role.h"
#include "../inc/RoleCreator.h"
#include "../inc/Species.h"

int main(int argc, char *argv[]) {
    RoleCreator rc;
    std::vector<Role> roles;
    std::vector<Species> species;
    rc.read_from_file(roles, species);
    // RoleSpeciesMap<Role> rsm;
    // rsm.add(Role("Nurse", 5, 7, 2, 6, 7, 9, "Male", false));
    // rsm.add(Role("Reporter", 5, 7, 2, 6, 6, 8, "Female", true));
    // rsm.add(Role("Professor", 4, 6, 1, 5, 8, 10, "Male", true));
    // rsm.add(Role("Nurse", 5, 7, 2, 6, 7, 9, "Female", false));
    // rsm.print();

    return 0;
}
