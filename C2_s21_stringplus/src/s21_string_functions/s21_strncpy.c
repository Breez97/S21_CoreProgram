#include "../s21_string.h"

char* s21_strncpy(char* dest, const char* src, s21_size_t n) {
  s21_size_t i;
  char* ret = dest;
  for (i = 0; i < n && *src != '\0'; i++) {
    *dest = *src;
    dest++;
    src++;
  }
  for (; i < n; i++) {
    *dest = '\0';
  }
  return ret;
}