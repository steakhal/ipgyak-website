#include "rational.h"
#include <stdio.h>

void rational_print(rational r) {
  printf("%d/%d\n", r.nom, r.denom);
}

rational rational_add(rational lhs, rational rhs) {
  rational res = {
    .denom = lhs.denom * rhs.denom,
    .nom = lhs.nom * rhs.denom +
           rhs.nom * lhs.denom
  };

  return res;
  /*
  rational result;
  result.denom = lhs.denom * rhs.denom;
  result.nom = lhs.nom * rhs.denom +
               rhs.nom * lhs.denom;
  return result;
  */
}

