#ifndef DFGJKLKJHGFD_PERSON_H
#define DFGJKLKJHGFD_PERSON_H

struct person {
  char name[32];
  int age;
};
typedef struct person    person;


int person_age_compare(const person *fst, const person *snd);

void person_print(person p);

void people_sort(person *ps, int size);

#endif

