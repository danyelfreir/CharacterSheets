#include "../inc/RoleCreator.h"

RoleCreator::RoleCreator() {}

std::vector<std::string> RoleCreator::get_filenames() {
    std::ifstream fin("data/roles.txt");
    std::vector<std::string> filenames;
    std::string filename;
    while (fin >> filename) {
        filenames.push_back(filename);
    }
    return filenames;
}

void RoleCreator::read_from_file(std::vector<Role> &roles, std::vector<Species> &species) {
    std::ifstream fin;
    std::vector<std::string> filenames = this->get_filenames();

    std::string category;
    std::string name;
    std::string gender;
    int hp_min;
    int hp_max;
    int str_min;
    int str_max;
    int int_min;
    int int_max;
    int tmp;
    bool natural;
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