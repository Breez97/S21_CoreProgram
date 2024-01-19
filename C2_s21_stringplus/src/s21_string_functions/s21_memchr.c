#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *pointer = (const unsigned char *)str;
  unsigned char symbol = (unsigned char)c;
  void *isCharExist = S21_NULL;

  for (s21_size_t i = 0; pointer != S21_NULL && i < n; i++) {
    if (pointer[i] == symbol) {
      isCharExist = (void *)&pointer[i];
      break;
    }
  }
  return isCharExist;
}
