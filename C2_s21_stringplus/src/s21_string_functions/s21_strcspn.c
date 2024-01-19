#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  while (*str1 != '\0') {
    if (s21_strchr(str2, *str1) != S21_NULL) {
      break;
    }
    result++;
    str1++;
  }
  return result;
}