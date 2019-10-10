#include <stdio.h>


int divisors(int n) {
  if (n < 0)
    return 1;

  if (n <= 1)
    return 1;

  int number_of_divisors = 1;
  for (int i = 2; i <= n; i++) {
    if (n % i == 0)
      number_of_divisors++;
  }
  return number_of_divisors;
}

int main() {
  int n;
  printf("Please enter a number: ");
  if (scanf("%f", &n) != 1) {
    printf("Next time enter a number! Abort.\n");
    return 1;
  }
  int divs = divisors(n);
  if (divs == 2)
    printf("%d is prime\n", n);
  else
    printf("%d is not prime\n", n);
  return 0;
}
