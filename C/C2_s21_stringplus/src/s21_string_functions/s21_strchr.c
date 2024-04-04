#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  int isFind = 0;

  while (*str != '\0') {
    if (*str == c) {
      isFind = 1;
      break;
    }
    str++;
  }
  return (isFind == 1 || c == '\0') ? (char *)str : S21_NULL;
}