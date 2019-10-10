#include <stdio.h>

int preplusplus(int *p) {
  *p = *p + 1;
  return *p;
}

int postplusplus(int *p) {
  int old = *p;
  *p = old + 1;
  return old;
}

int main() {
  int i = 1;

  printf("%d\n", ++i);
  printf("%d\n", i);

  printf("%d\n", preplusplus(&i));
  printf("%d\n", i);

  printf("------\n");

  printf("%d\n", i++);
  printf("%d\n", i);

  printf("%d\n", postplusplus(&i));
  printf("%d\n", i);
}

