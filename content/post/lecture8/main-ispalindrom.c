#include <stdio.h>
#include <stdbool.h>
#include "ispalindrom.h"

int main() {
  printf("%s", (ispalindrom("")? "success\n" : "fail\n"));
  printf("%s", (ispalindrom("a")? "success\n" : "fail\n"));
  printf("%s", (ispalindrom("aba")? "success\n" : "fail\n"));
  printf("%s", (ispalindrom("abl ak ka lba")? "success\n" : "fail\n"));
  printf("%s", (ispalindrom("aa")? "success\n" : "fail\n"));
  printf("%s", (ispalindrom("aabbaa")? "success\n" : "fail\n"));

  printf("%s", (!ispalindrom("ab")? "success\n" : "fail\n"));
  printf("%s", (!ispalindrom("abbe")? "success\n" : "fail\n"));
  printf("%s", (!ispalindrom("abc")? "success\n" : "fail\n"));
}

