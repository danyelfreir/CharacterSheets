#include <iostream>
#include <vector>

#include "../inc/Being.h"
#include "../inc/Investigator.h"
#include "../inc/Person.h"

int main(int argc, char *argv[]) {
  std::vector<Being *> beings;
  beings.push_back(new Person("Male"));
  beings.push_back(new Being());
  beings.push_back(new Person("Female"));
  beings.push_back(new Person("Male"));
  beings.push_back(new Being());
  beings.push_back(new Being());
  beings.push_back(new Person("Female"));
  beings.push_back(new Investigator("Male"));

  for (Being *b : beings)
    b->print();

  return 0;
}
