#pragma once
#include <iostream>
#include <vector>

template <class T> class RoleSpeciesMap {
  private:
    std::vector<std::pair<T, int>> role_species;

  public:
    RoleSpeciesMap(){};
    void add(T element) {
        for (int i = 0; i < this->role_species.size(); i++) {
            std::pair<T, int> tmp = this->role_species[i];
            if (tmp.first == element) {
                this->role_species.push_back(std::pair<T, int>(tmp.first, tmp.second + 1));
                this->role_species.erase(this->role_species.begin() + i);
                return;
            }
        }
        role_species.push_back(std::pair<T, int>(element, 1));
    };
    int peek(T element) {
        for (std::pair<T, int> rs : this->role_species)
            if (rs.first == element)
                return rs.second;
        return 0;
    }
    void print() {
        for (std::pair<T, int> rs : this->role_species) {
            std::cout << "Val -> " << rs.second << "\n";
        }
    }
};
