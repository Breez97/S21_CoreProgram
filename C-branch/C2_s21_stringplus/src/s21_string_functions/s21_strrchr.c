#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;
  char *strCopy = (char *)str;
  while (*strCopy != '\0') {
    if (*strCopy == (char)c) {
      result = strCopy;
    }
    strCopy++;
  }
  if ((char)c == '\0') {
    result = strCopy;
  }
  return result;
}
