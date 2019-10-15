#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  int a = 0x0; // 00000000 00000000 00000000 00001100
  int b = 0x1; // 00000000 00000000 00001000 00000011
               // 00000000 00000000 00001000 00000010
  printf("%d\n", a | b); // bitwise or
  printf("%d\n", a & b); // bitwise and
  printf("%d\n", a ^ b); // bitwise xor

  a ^= b; // same as: a = a ^ b;
  // etc.
  return 0;
}
