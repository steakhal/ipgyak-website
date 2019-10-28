#include <stdio.h>
#include "person.h"


int main() {
  person jason = { .age = 22, .name = "Jason" };
  jason.age = 23;
  person gason = { 44, "Gason" };
  person noname = { 44 };

  // jason.name[0] = 'G'; // compiler-error
  printf("person{ name: '%s', age: %d }\n", jason.name, jason.age);
  printf("person{ name: '%s', age: %d }\n", gason.name, gason.age);
  return 0;
}

