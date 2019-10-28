#ifndef RATIONAL_WHATEVER_DUNNO_WHAT_H
#define RATIONAL_WHATEVER_DUNNO_WHAT_H

struct rational {
  int nom;
  int denom;
};
typedef struct rational      rational;
typedef struct rational      real;

void rational_print(rational r);
rational rational_add(rational lhs, rational rhs);


#endif // RATIONAL_WHATEVER_DUNNO_WHAT_H

