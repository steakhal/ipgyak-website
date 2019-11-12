
typedef  int (*szorny_t)(int);

int square(int num) {
    return num * num;
}

int inc(int num) {
    return num + 1;
}



int main() {
  int asd = 1;
  szorny_t fp = square;

  szorny_t fp2 = square;
  szorny_t fp3 = square;


  if (asd) {
      fp = square;
  } else {
      fp = inc;
  }
  return fp(44);
}
