#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *nextStr = S21_NULL;

  if (str) {
    nextStr = str;
  } else {
    str = (nextStr == S21_NULL) ? S21_NULL : nextStr;
  }

  if (str) {
    while (*str && s21_strchr(delim, *str)) {
      str++;
    }
    if (*str == '\0') {
      str = S21_NULL;
    } else {
      s21_size_t lengthWithoutDelimiters = s21_strcspn(str, delim);
      nextStr = str + lengthWithoutDelimiters;
      while (*nextStr && s21_strchr(delim, *nextStr)) {
        nextStr++;
      }
      nextStr = (*nextStr == '\0') ? S21_NULL : nextStr;
      for (s21_size_t i = lengthWithoutDelimiters; i < s21_strlen(str); i++) {
        str[i] = '\0';
      }
    }
  }
  return str;
}
