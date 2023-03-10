#pragma once
#include <iostream>

class Being {
private:
  static int s_being_num;
  std::string _category;
  int _id;
  int _life;
  int _strength;
  int _intelligence;

protected:
  int get_id();
  std::string get_category();
  void set_id();
  void set_category(std::string category);

public:
  Being(int life, int strength, int intelligence);
  int get_life();
  int get_strength();
  int get_intelligence();
  void set_life(int life);
  void set_strength(int strength);
  void set_intelligence(int intelligence);
  virtual void print();
};
