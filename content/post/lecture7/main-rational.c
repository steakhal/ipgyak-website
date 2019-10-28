#include <stdio.h>
#include "rational.h"

int main() {
  real a, b;
  scanf("%d %d", &a.nom, &a.denom);
  scanf("%d %d", &b.nom, &b.denom);

  real res = rational_add(a, b);
  rational_print(a);
  rational_print(b);
  rational_print(res);
  return 0;
}


