#include <stdio.h>
#include <errno.h>
#include <string.h>

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
  if (argc != 2) {
    printf("You must call with an argument like: ./a.out myfile.txt");
    return -2;
  }
  printf("arg0: %s\n", argv[0]);

  FILE *f = fopen(argv[1], "r");
  
  if (!f) {
    perror("Could not open file");
    return -1;
  }
  
  char buff[32] = {0}; // zero initialized
  int read_bytes;
  while ((read_bytes = fgets(buff, 1, sizeof(buff) - 1, f)) > 0) {
    buff[read_bytes] = '\0';
    printf("%s", buff);
  }

  fclose(f);
  
  return 0;
} // bah

