#include <stdio.h>

int main() {
  int a = 2;
  int b = 3;
  printf("&a: %p\n", (void*)&a);
  printf("&b: %p\n", (void*)&b);
  printf("NULL: %p\n", (void*)NULL);
  return 0;
}

