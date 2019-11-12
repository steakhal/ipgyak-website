#include "ispalindrom.h"

#include <stdbool.h>
#include <string.h>

bool ispalindrom(const char *str) {
  size_t len = strlen(str);

  for (size_t i = 0; i < len / 2; i++)
    if (str[i] != str[len - i - 1])
      return false;

  return true;
}

