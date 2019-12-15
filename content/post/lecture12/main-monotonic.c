#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

bool is_monotonic_in_any_way(const int *ints, size_t len) {
  if (len < 3) return true;

  bool inc = true;
  bool dec = true;

  for (size_t i = 1; i < len; ++i) {
    if (ints[i - 1] < ints[i])
      dec = false;
    else if (ints[i - 1] > ints[i])
      inc = false;
  }
  return inc || dec;
}

int main() {
  const int ints[] = {1, -3, -22};
  bool res = is_monotonic_in_any_way(ints, sizeof(ints) / sizeof(int));
  return res;
}
