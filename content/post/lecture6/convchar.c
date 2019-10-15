#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include <string.h>

size_t len(char *str) {
  size_t length = 0;
  while (*str != '\0') {
    length++;
    str++;
  }
  return length;
}

void conv(char *str) {
  while (*str != '\0') {
    if ('a' <= *str && *str <= 'z')
      *str = *str - 'a' + 'A';
    else if ('A' <= *str && *str <= 'Z')
      *str = *str - 'A' + 'a';
    else if (*str == '!')
      *str = '#';
    str++;
  }
}

int main() {
  char str[] = "ablak ALATT !!! volt";
  //char *str2 = "ablak ALATT !!! volt";
  printf("%s with length: %d\n", str, (int)strlen(str));
  conv(str);
  str[4] = '\0';
  printf("%s with length: %d\n", str, (int)strlen(str));
  return 0;
}
