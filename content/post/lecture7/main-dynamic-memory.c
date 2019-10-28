#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  int size = 5;
  scanf("%d", &size);
/*
  int *p = malloc(sizeof(int) * size);
  memset(p, 0, sizeof(int) * size);
*/
  int *p = calloc(size, sizeof(int));
  p[0] = 1;
  p[1] = 2;
  p[2] = 4;
  p[3] = 8;

  for (int i = 0; i < size; ++i) {
    printf("%d ", p[i]);
  }
  printf("\n");

  size = 10;
  int *p2 = realloc(p, size * sizeof(int));

  if (p2 != NULL)
    p = p2;

  for (int i = 0; i < size; ++i) {
    printf("%d ", p[i]);
  }
  printf("\n");
  free(p);
}

