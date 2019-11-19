#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

/*
void perror(const char* msg) {
  const char * str = strerror(errno);
  printf("%s: %s\n", msg, str);
}*/

// fopen, fclose, FILE*
//   open modes
// fread, fwrite
// fprintf, fscanf, fgets
// fgetc, EOF, feof, ferror
// errno, perror, strerror
// Feladatok:
//  1 Ird ki a fájl tartalmát a konzolra. 
//  2 Az 1. feladat csak minden sort ">> "-al kezdj.
//  3 Az első futtatási argumentum legyen a megnyitandó fájl elérési útja: argc == 2
//     ./a.out  myfile.txt
//      ^        ^
//      |        |
//     argv[0], argv[1] 
int main(int argc, const char** argv) {
  /*if (argc != 2) {
    printf("You must call with an argument like: ./a.out myfile.txt");
    return -2;
  }
  printf("arg0: %s\n", argv[0]);
  FILE *f = fopen(argv[1], "r");
  */
  FILE *f = fopen("main.c", "r");
  
  if (!f) {
    perror("Could not open file");
    return -1;
  }
  
  char buff[32] = {0}; // zero initialized
  int read_bytes;
  bool print_prefix = true;
  while (fgets(buff, sizeof(buff), f)) {
    if (print_prefix)
      printf(">> ");
    if (buff[strlen(buff) - 1] == '\n')
      print_prefix = true;
    else
      print_prefix = false;
    printf("%s", buff);
  }

  if (ferror(f)) {
    perror("something bad happened");
  }
  if (feof(f)) {
    printf("file has been successfully processed\n");
  }

  fclose(f);
  return 0;
}

