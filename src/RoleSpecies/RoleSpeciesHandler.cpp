#include "../../inc/RoleSpeciesHandler.h"
#include <cstdio>

RoleSpeciesHandler::RoleSpeciesHandler() {}

std::vector<std::string> RoleSpeciesHandler::get_filenames() {
    std::ifstream fin("data/roles.txt");
    std::vector<std::string> filenames;
    std::string filename;
    while (fin >> filename) {
        filenames.push_back(filename);
    }
    return filenames;
}

void RoleSpeciesHandler::read_from_file(std::vector<Role> &roles,
                                        std::vector<Species> &species) {
    std::ifstream fin;
    std::vector<std::string> filenames = this->get_filenames();

    std::string category;
    std::string name;
    std::string gender;
    bool natural;
    int tmp;
    int hp_min;
    int hp_max;
    int str_min;
    int str_max;
    int int_min;
    int int_max;
    int disquiet;
    int traumatism;

    for (std::string filename : filenames) {
        fin.open(filename);
        fin >> category;
        if (category.compare("Person") == 0) {
            fin >> name;
            rsm.add(name);
            name.append(std::to_string(rsm.peek(name)));
            fin >> hp_min;
            fin >> hp_max;
            fin >> str_min;
            fin >> str_max;
            fin >> int_min;
            fin >> int_max;
            fin >> gender;
            roles.push_back(
                Role(name, hp_min, hp_max, str_min, str_max, int_min, int_max, gender, false));
        } else if (category.compare("Creature") == 0) {
            fin >> name;
            rsm.add(name);
            name.append(std::to_string(rsm.peek(name)));
            fin >> hp_max;
            fin >> str_max;
            fin >> int_max;
            fin >> tmp;
            natural = tmp == 1 ? true : false;
            fin >> disquiet;
            species.push_back(
                Species(name, hp_max, str_max, int_max, natural, disquiet, false));
        } else if (category.compare("Eldritch") == 0) {
            fin >> name;
            rsm.add(name);
            name.append(std::to_string(rsm.peek(name)));
            fin >> hp_max;
            fin >> str_max;
            fin >> int_max;
            fin >> traumatism;
            species.push_back(Species(name, hp_max, str_max, int_max, false, traumatism, true));
        } else if (category.compare("Investigator") == 0) {
            fin >> name;
            rsm.add(name);
            name.append(std::to_string(rsm.peek(name)));
            fin >> hp_min;
            fin >> hp_max;
            fin >> str_min;
            fin >> str_max;
            fin >> int_min;
            fin >> int_max;
            fin >> gender;
            roles.push_back(
                Role(name, hp_min, hp_max, str_min, str_max, int_min, int_max, gender, true));
        }
        fin.close();
    }
}

void RoleSpeciesHandler::write_role_to_file(Role &role) {
    std::string filename = "data/Roles/";
    filename.append(role.get_name());
    filename.append(".txt");
    std::ofstream fout(filename);
    fout << role.get_category() << "\n";
    fout << role.get_name() << "\n";
    fout << role.get_life() << "\n";
    fout << role.get_life() << "\n";
    fout << role.get_strength() << "\n";
    fout << role.get_strength() << "\n";
    fout << role.get_intelligence() << "\n";
    fout << role.get_intelligence() << "\n";
    fout << role.get_gender();
}

void RoleSpeciesHandler::write_species_to_file(Species &species) {
    std::string filename = "data/Roles/";
    filename.append(species.get_name());
    filename.append(".txt");
    std::ofstream fout(filename);
    if (species.get_category().compare("Eldritch Horror") == 0)
        fout << "Eldritch\n";
    else
        fout << species.get_category() << "\n";
    fout << species.get_name() << "\n";
    fout << species.get_life() << "\n";
    fout << species.get_strength() << "\n";
    fout << species.get_intelligence() << "\n";
    if (species.get_category().compare("Creature") == 0) {
        fout << species.get_natural();
        fout << species.get_disquiet();
    } else if (species.get_category().compare("Eldritch Horror") == 0) {
        fout << species.get_traumatism();
    }
}

void RoleSpeciesHandler::create_species(std::vector<Species> &species, std::string name,
                                        Creature *creature) {
    rsm.add(name);
    name.append(std::to_string(this->rsm.peek(name)));
    Species sp(name, creature);
    species.push_back(sp);
    this->write_species_to_file(sp);
}

void RoleSpeciesHandler::create_role(std::vector<Role> &roles, std::string name,
                                     Person *person) {
    rsm.add(name);
    name.append(std::to_string(this->rsm.peek(name)));
    Role r(name, person);
    roles.push_back(r);
    this->write_role_to_file(r);
}

void RoleSpeciesHandler::delete_species_or_role(std::vector<Species> &species,
                                                std::vector<Role> &roles, int being_id) {
    for (int i = 0; i < species.size(); i++) {
        if (species[i].get_id() == being_id) {
            Species tmp = species[i];
            this->delete_file(tmp.get_name());
            species.erase(species.begin() + i);
            return;
        }
    }
    for (int i = 0; i < roles.size(); i++) {
        if (roles[i].get_id() == being_id) {
            Role tmp = roles[i];
            this->delete_file(tmp.get_name());
            roles.erase(roles.begin() + i);
            return;
        }
    }
}

void RoleSpeciesHandler::delete_file(std::string name) {
    std::string filename = "data/Roles/";
    filename.append(name);
    filename.append(".txt");
    remove(filename.c_str());
}