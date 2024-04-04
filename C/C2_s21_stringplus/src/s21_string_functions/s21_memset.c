#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  const unsigned char symbol = (const unsigned char)c;
  unsigned char *stringPointer = (unsigned char *)str;

  for (s21_size_t i = 0; i < n; i++) {
    stringPointer[i] = symbol;
  }

  return str;
}