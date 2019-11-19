#include "person.h"

int main() {
  person people[] = {
    { "Pisti",   12 },
    { "Pistike", 13 },
    { "Wauw", 7 },
    { "Janos", 55 },
  };

  int size = sizeof(people) / sizeof(person);
  people_sort(people, size);

  for (int i = 0; i < size; ++i) {
    person_print(people[i]);
  }
  return 0;
}

