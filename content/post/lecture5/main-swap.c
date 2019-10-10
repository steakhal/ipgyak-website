#include <stdio.h>

#include "swap.h"
#include "swap.h"

int main() {
  int a = 2;
  int b = 3;
  printf("%d %d\n", a, b);
  swap(&a, &b);
  printf("%d %d\n", a, b);
  return 0;
}

