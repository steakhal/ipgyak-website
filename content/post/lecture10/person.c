#include "person.h"

#include <stdio.h>
#include <stdlib.h>

int person_age_compare(const person *fst, const person *snd) {
  if (fst->age < snd->age)
    return -404;
  if (fst->age > snd->age)
    return 143;
  return 0;
}

void person_print(person p) {
  printf("person{ .name: '%s', .age: %d }\n", p.name, p.age);
}

static int wrapped_person_age_compare(const void *lhs, const void *rhs) {
  return person_age_compare((const person*)lhs, (const person*)rhs);
}

void people_sort(person *ps, int size) {
  qsort(ps, size, sizeof(person), wrapped_person_age_compare);
/*
  for (int i = 0; i < size - 1; ++i) {
    int min_idx = i;
    for (int j = i + 1; j < size; ++j) {
      int res = person_age_compare(&ps[j], &ps[min_idx]);
      if (res < 0)
        min_idx = j;
    }
    // swaps two persons
    person tmp = ps[i];
    ps[i] = ps[min_idx];
    ps[min_idx] = tmp;
  }
*/
}

