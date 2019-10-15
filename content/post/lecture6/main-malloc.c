#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include <string.h>

int main() {
  int n = 0;
  scanf("%d", &n);
  int *p = malloc(sizeof(int) * n);
  //memset(p, 0, sizeof(int) * n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
  }
  printf("entered %d numbers:\n", n);
  for (int i = 0; i < n; ++i) {
    printf("%d ", p[i]);
  }
  free(p);
  p = NULL;
  return 0;
}
