#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// MUST free the returned pointer!
char *strdup(char * str) {
  int len = strlen(str);
  char *tmp = malloc(len + 1);
  memcpy(tmp, str, len + 1);
  return tmp;
}

int main() {
  char *str = "wizard";
  char *mycopy = strdup(str);
  printf("original: '%s'\n", str);
  *mycopy = 'W';
  printf("Hi, #%s#\n", mycopy);
  free(mycopy);
  return 0;
}
