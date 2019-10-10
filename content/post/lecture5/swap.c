#include "swap.h"

void swap(float *lhs, float *rhs) {
  int tmp = *lhs;
  *lhs = *rhs;
  *rhs = tmp;
}


