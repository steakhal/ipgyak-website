#include <stdio.h>

#define MAX_N 1000

int main() {
  int n;

  printf("adj meg N-et: ");
  if (scanf("%d", &n) != 1) {
    printf("could not read n, abort\n");    
    return 1;
  }
  if (n <= 0) {
    printf("N nem pozitiv, abort\n");
    return 1;
  }
  if (n >= MAX_N) {
    printf("N tul nagy, abort\n");
    return 1;
  }

  int nums[MAX_N];
  printf("adj meg N db szamot: ");
  for (int i = 0; i < n; ++i) {
    if (scanf("%d", &nums[i]) != 1) {
      printf("nem egesz szam, abort\n");
      return 1;
    }
  }

  int minidx = 0;
  int minval = nums[0];
  for (int i = 1; i < n; ++i) {
    if (nums[i] < minval) {
      minval = nums[i];
      minidx = i;    
    }
  }
  printf("legkisebb ertek: %d, idx: %d\n", minval, minidx);

  for (int i = 0; i < n; ++i)
    printf("%d ", nums[i]);
  printf("\n");

  return 0;
}

