#include <stdio.h>

#include "max.h"

int main() {
  // int mx[5][4] = { {1,2,3}, {}, {}, {} };
  int nums[] = {1,5,-4};
  int m = max(nums,
    sizeof(nums) / sizeof(nums[0]));
  printf("max value: %d\n", m);

  char txts[] = "a\0bc";
  char maxchar = maxchr(txts,
    sizeof(txts) / sizeof(txts[0]));
  printf("max value2: %c\n", maxchar);
  printf("txts: %s\n", txts);
}

