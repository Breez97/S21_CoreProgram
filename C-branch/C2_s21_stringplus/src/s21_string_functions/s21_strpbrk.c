#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str2); i++) {
    char *symbol = s21_strchr(str1, str2[i]);
    if (symbol != S21_NULL && (symbol < result || result == S21_NULL)) {
      result = symbol;
    }
  }
  return result;
}
