#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

size_t len(char *str) {
  size_t n = 0;
  while (*str != '\0') {
    ++n;
    ++str;
  }
  return n;
}

char *search(char *haystack, char *needle) {
  size_t len1 = len(haystack);
  size_t len2 = len(needle);

// ablak at alatt
//       at
//       ^-- returned

  for (size_t i = 0; i < len1 - len2; ++i) {
    bool is_full_match = true;
    for (size_t j = 0; j < len2; ++j) {
      if (haystack[i + j] != needle[j]) {
        is_full_match = false;
      }
    }
    if (is_full_match) {
      return &haystack[i];
    }
  }

  return NULL;
}

int main() {
  char line[] = "ablak at alatt";
  char *item = search(line, "at");
  assert(item != NULL);
  int idx = item - line;
  printf("at: %d\n", idx);
}

