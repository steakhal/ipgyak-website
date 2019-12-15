#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "compress.h"

bool test(char *input, const char *expected) {
  compress(input);
  return strcmp(input, expected) == 0;
}

int main() {
  char inputs[][40] = {"az abba   aaaah, de joooooooooo!!!",
                       "aabb",
                       "abc",
                       "b",
                       "",
                       "            ",
                       "  bbbcc  kkkk    "};
  const char expected[][40] = {
      "az ab2a 3a4h, de jo10!3", "a2b2", "abc", "b", "", " 12", " 2b3c2 2k4 4"};

  const size_t number_of_tests = sizeof(inputs) / sizeof(inputs[0]);
  assert(number_of_tests == sizeof(expected) / sizeof(expected[0]) &&
         "must have expected result for each input");
  for (size_t i = 0; i < number_of_tests; ++i)
    printf("%s\n", test(inputs[i], expected[i]) ? "success" : "fail");
  return 0;
}
