#include <assert.h>
#include <stdio.h>

#include "compress.h"

size_t count_same_chars_from(const char *text, size_t start) {
  assert(text[start] != '\0' && "text can not be empty");
  size_t cnt = 1;
  while (text[start + cnt - 1] == text[start + cnt]) {
    cnt++;
  }
  return cnt;
}

size_t append_number_if_has_multiple_digits(char *compressed,
                                            size_t compressed_len,
                                            size_t repetition) {
  // if the repetition is NOT greater than 2, no need to convert to decimal
  // representation
  if (repetition <= 1)
    return 0; // no character appended to the compressed string

  char digits[11] = {0}; // INT_MAX can only have 10 digits in decimal, but we
                         // need place for the NULL-TERMINATOR...
  const int number_of_digits =
      sprintf(digits, "%d", (int)repetition); // int, not size_t
  assert(number_of_digits >= 1 && "int to string must succeed");

  // copy the decimal representation of the repetition number to the compressed
  // string copy each character, except the NULL-TERMINATOR (we dont want to
  // overwrite the next character)
  for (int i = 0; i < number_of_digits; ++i)
    compressed[compressed_len + i] = digits[i];
  return number_of_digits;
}

void compress(char *arr) {
  size_t i = 0;
  size_t compressed_len = 0;

  while (arr[i] != '\0') {
    arr[compressed_len++] = arr[i];

    const size_t repetition = count_same_chars_from(arr, i);
    const size_t number_of_digits =
        append_number_if_has_multiple_digits(arr, compressed_len, repetition);
    compressed_len += number_of_digits;
    // move forward by the number of repeted characters
    i += repetition;
  }
  arr[compressed_len] = '\0';
}
