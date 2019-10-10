#include <stdio.h>

#define MAX_N 1000

void swap(int *lhs, int *rhs) {
  int tmp = *lhs;
  *lhs = *rhs;
  *rhs = tmp;
}

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

  for (int i = 0; i < n / 2; ++i) {
    swap(&nums[i], &nums[n - i - 1]);
  }

  for (int i = 0; i < n; ++i)
    printf("%d ", nums[i]);
  printf("\n");

  return 0;
}

