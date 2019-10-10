#include "max.h"

int max(int *ns, int size) {
  int max_val = ns[0];
  for (int i = 1; i < size; ++i) {
    if (max_val < ns[i]) {
      max_val = ns[i];
    }
  }
  return max_val;
}

char maxchr(char *ns, int size) {
  char max_val = ns[0];
  for (int i = 1; i < size; ++i) {
    if (max_val < ns[i]) {
      max_val = ns[i];
    }
  }
  return max_val;
}


