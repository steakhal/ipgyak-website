// gcc -Wall -Wextra -std=c99 -pedantic main-vec.c vec.c -fsanitize=address -g

#include <stdio.h>

#include "vec.h"

int main() {
  int_vec v = vec_default_init();

  printf("size: %d\n", vec_size(&v));
  printf("capacity: %d\n", vec_capacity(&v));

  vec_push_back(&v, 12);
  printf("size: %d\n", vec_size(&v));
  printf("capacity: %d\n", vec_capacity(&v));

  printf("item[0]: %d\n", vec_at(&v, 0));

  vec_replace_at(&v, 0, 44);
  vec_push_back(&v, 13);
  vec_push_back(&v, 14);
  printf("item[0]: %d\n", vec_at(&v, 0));

  printf("all items in the vector:\n");
  for (int i = 0; i < vec_size(&v); ++i)
    printf("  item[%d]: %d\n", i, vec_at(&v, i));
  
  vec_pop_back(&v);
  printf("all items in the vector:\n");
  for (int i = 0; i < vec_size(&v); ++i)
    printf("  item[%d]: %d\n", i, vec_at(&v, i));

  // printf("item[2]: %d\n", vec_at(&v, 2)); // UB
  vec_destroy(&v);
}

