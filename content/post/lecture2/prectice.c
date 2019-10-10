#include <stdio.h>
#include <stdbool.h>

int main() {
  char ch = 'z';
  int i = 3;
  float f = 3.14;
  double d = f;
  printf("f: %f\n", f);
  printf("d: %lf\n", d);
  printf("ch: %c\n", ch);

  bool b = i;
  printf("b: %d\n", (int)b);

  for (i = 0; i <= 20; i += 2) {
    printf("i: %d\n", i);
  }
  return 0;
}

