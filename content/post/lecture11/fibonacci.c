#include "fibonacci.h"

#include <stdlib.h>

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...


void fibs2(size_t n, unsigned long long *result) {
  if (n == 0)
    return;

  result[0] = 0;

  if (n > 1)
    result[1] = 1;

  for (size_t i = 2; i < n; ++i)
    result[i] = result[i-1] + result[i-2];
}

// MUST FREE the returned pointer
unsigned long long* fibs1(size_t n) {
  if (n == 0)
    return NULL;

  unsigned long long* p = malloc( sizeof(unsigned long long) * n );
  if (p == NULL)
    return NULL;

  fibs2(n, p);
  return p;
}

