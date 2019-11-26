#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "fibonacci.h"

bool test2(size_t input, unsigned long long* expected) {
  unsigned long long result[200];
  fibs2(input, result);

  for (size_t i = 0; i < input; ++i)
    if (result[i] != expected[i])
      return false;
  return true;
}

bool test(size_t input, unsigned long long* expected) {
  unsigned long long *tmp = fibs1(input);

  if (expected == NULL) {
    if (tmp == NULL)
      return true;
    free(tmp);
    return false;
  }

  for (size_t i = 0; i < input; ++i) {
    if (tmp[i] != expected[i]) {
      free(tmp);
      return false;
    }
  }
  free(tmp);
  return true;
}

int main() {
  unsigned long long expected[] = {0,1,1,2,3,5,8};

  printf("tesing fibs1\n");
  printf("%s\n", test(0, NULL) ? "success" : "failed");
  printf("%s\n", test(1, expected) ? "success" : "failed");
  printf("%s\n", test(2, expected) ? "success" : "failed");
  printf("%s\n", test(7, expected) ? "success" : "failed");

  printf("\ntesing fibs2\n");
  printf("%s\n", test2(0, NULL) ? "success" : "failed");
  printf("%s\n", test2(1, expected) ? "success" : "failed");
  printf("%s\n", test2(2, expected) ? "success" : "failed");
  printf("%s\n", test2(7, expected) ? "success" : "failed");
  return 0;
}

