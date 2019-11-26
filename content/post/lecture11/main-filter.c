#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "filter_first_n_positive.h"

// disclaimer: im pretty sure that is could be simplified a LOT

void test_and_print(int *input, size_t input_len, size_t n, int *expected) {
  int *actual = filter_first_n_positive(input, input_len, n);
  if (expected == NULL) {
    if (actual == NULL) {
      printf("success\n");
      return;
    }
    free(actual);
    printf("fail\n");
    return;
  }

  bool correct = true;
  for (size_t i = 0; i < n; ++i)
    if (actual[i] != expected[i])
      correct = false;
  free(actual);
  printf("%s\n", correct ? "success" : "fail");
}

int main() {
  {
    int n = 3;
    int expected[] = {1,3,4};
    int nums[] = {1,-2,3,4,5,-6,7,-8,-9,0};
    size_t nums_len = sizeof(nums)/sizeof(nums[0]);
    test_and_print(nums, nums_len, n, expected);
  }

  {
    int n = 0;
    int *expected = NULL;
    int nums[] = {1,-2,3,4,5,-6,7,-8,-9,0};
    size_t nums_len = sizeof(nums)/sizeof(nums[0]);
    test_and_print(nums, nums_len, n, expected);
  }

  {
    int n = 6;
    int *expected = NULL;
    int nums[] = {1,-2,3,4,5,-6,7,-8,-9,0};
    size_t nums_len = sizeof(nums)/sizeof(nums[0]);
    test_and_print(nums, nums_len, n, expected);
  }

  {
    int n = 5;
    int expected[] = {1,3,4,5,7};
    int nums[] = {1,-2,3,4,5,-6,7,-8,-9,0};
    size_t nums_len = sizeof(nums)/sizeof(nums[0]);
    test_and_print(nums, nums_len, n, expected);
  }

  {
    int n = 1;
    int expected[] = {1};
    int nums[] = {0,0,0,0,0,1};
    size_t nums_len = sizeof(nums)/sizeof(nums[0]);
    test_and_print(nums, nums_len, n, expected);
  }

  {
    int n = 1;
    int expected[] = {42};
    int nums[] = {42,0,-5,0,0,-1};
    size_t nums_len = sizeof(nums)/sizeof(nums[0]);
    test_and_print(nums, nums_len, n, expected);
  }

  {
    int n = 1;
    int expected[] = {42};
    int nums[] = {42,0,-5,0,0,4};
    size_t nums_len = sizeof(nums)/sizeof(nums[0]);
    test_and_print(nums, nums_len, n, expected);
  }

  {
    int n = 2;
    int expected[] = {42, 4};
    int nums[] = {42,0,-5,0,0,4};
    size_t nums_len = sizeof(nums)/sizeof(nums[0]);
    test_and_print(nums, nums_len, n, expected);
  }
}

