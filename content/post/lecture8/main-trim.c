#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trim.h"

void test(const char *input, const char *expected) {
  char *res = trim(input);
  printf("%s", (strcmp(expected, res) == 0? "success\n" : "fail\n"));
  free(res);
}

int main() {
  test("" , "");
  test("a", "a");
  test(" a", "a");
  test("  \n  ", "");
  test("  \n \tablak  \n\t\t", "ablak");
  test("  \n ablak alatt \t", "ablak alatt");
}

