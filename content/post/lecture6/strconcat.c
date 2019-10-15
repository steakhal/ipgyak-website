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

// MUST free the returned pointer!
char *strconcat(char * str1, char * str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  char *tmp = malloc(len1 + len2 + 1);
  memcpy(tmp, str1, len1);
  memcpy(tmp + len1, str2, len2);
  tmp[len1 + len2] = '\0';
  return tmp;
}


int main() {
  char *str = "wizard";
  char *mycopy = strdup(str);
  printf("original: '%s'\n", str);
  *mycopy = 'W';
  printf("Hi, #%s#\n", mycopy);
  char *conc = strconcat(str, mycopy);
  printf("conc: '%s'\n", conc);
  free(mycopy);
  free(conc);
  return 0;
}
