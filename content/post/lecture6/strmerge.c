#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// MUST free the returned pointer!
char *strmerge(char *lhs, char *rhs) {
  int len1 = strlen(lhs);
  int len2 = strlen(rhs);
  char *tmp = malloc(len1 + len2 + 1);
  char *w = tmp;
  while (*lhs != '\0' && *rhs != '\0') {
    if (*lhs < *rhs) {
      *w = *lhs;
      lhs++;
    } else {
      *w = *rhs;
      rhs++;
    }
    ++w;
  }

  while (*lhs != '\0') {
    *w = *lhs;
    lhs++;
    ++w;
  }

  while (*rhs != '\0') {
    *w = *rhs;
    rhs++;
    ++w;
  }
  *w = '\0';
  return tmp;
}


int main() {
  char *merg = strmerge("abc", "aakkzz");
  printf("merged: %s\n", merg);
  free(merg);
  return 0;
}

