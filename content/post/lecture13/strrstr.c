#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

const char *strrstr(const char* str, const char* substr) {
  const size_t str_len = strlen(str);
  const size_t substr_len = strlen(substr);
  const size_t upperbound = str_len - substr_len;

  bool match = false;
  int i;
  for (i = upperbound; i >= 0 && !match; --i) {
    match = true;
    for (size_t j = 0; j < substr_len; ++j) {
      if (str[i + j] != substr[j]) {
        match = false;
        break;
      }
    }
  }
  return match ? &str[i + 1] : NULL;
}

int main() {
  puts(strrstr("ablak", "bl"));
}
