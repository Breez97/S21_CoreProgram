#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  for (s21_size_t i = 0; i < n && (*str1 != '\0' || *str2 != '\0'); i++) {
    if (*str1 != *str2) {
      result = *str1 - *str2;
      break;
    }
    str1++;
    str2++;
  }
  return result;
}