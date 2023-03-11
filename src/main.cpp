#include <iostream>
#include <vector>

#include "../inc/Role.h"
#include "../inc/RoleSpeciesHandler.h"
#include "../inc/Species.h"

int main(int argc, char *argv[]) {
    RoleSpeciesHandler rc;
    std::vector<Role> roles;
    std::vector<Species> species;

    rc.read_from_file(roles, species);

    Person *p = new Person(4, 5, 6, "dno", 7);
    rc.create_role(roles, "Danni", p);

    for (Role r : roles) {
        r.print();
    }

    for (Species s : species) {
        s.print();
    }

    rc.delete_species_or_role(species, roles, 9);

    for (Role r : roles) {
        r.print();
    }

    for (Species s : species) {
        s.print();
    }

    return 0;
}
