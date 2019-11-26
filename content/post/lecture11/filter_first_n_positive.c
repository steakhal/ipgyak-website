#include "filter_first_n_positive.h"

#include <stdlib.h>

// disclaimer: im pretty sure that is could be simplified a LOT

// FIXME: nums could be const
// MUST FREE the returned pointer
int *filter_first_n_positive(int *nums, size_t nums_size,    size_t n) {
  if (nums_size == 0)
    return NULL;

  // the zero length result means here a NULL pointer :D
  if (n == 0)
    return NULL;

  // how to return more elements than we have -- cant
  if (n > nums_size)
    return NULL;

  int *result = malloc(sizeof(int) * nums_size);
  if (result == NULL)
    return NULL;

  size_t result_len = 0;
  for (size_t i = 0; i < nums_size && result_len < n; ++i) {
    if (nums[i] > 0)
      result[result_len++] = nums[i];
  }

  if (result_len != n) {
    free(result);
    return NULL;
  }

  return result;
}

