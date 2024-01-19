#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *trimString = S21_NULL;
  if (src != S21_NULL) {
    if (trim_chars == S21_NULL || *trim_chars == '\0') {
      trim_chars = " \t\n\v\r\f";
    }
    s21_size_t sourceLength = s21_strlen(src);

    s21_size_t startIndex = 0;
    while (startIndex < sourceLength &&
           s21_strchr(trim_chars, src[startIndex]) != S21_NULL) {
      startIndex++;
    }

    if (startIndex == sourceLength) {
      trimString = (char *)malloc(sizeof(char));
      if (trimString != S21_NULL) {
        *trimString = '\0';
      }
    } else {
      s21_size_t endIndex = sourceLength - 1;
      while (endIndex > startIndex &&
             s21_strchr(trim_chars, src[endIndex]) != S21_NULL) {
        endIndex--;
      }
      s21_size_t trimmedLength = endIndex - startIndex + 1;
      trimString = (char *)malloc(sizeof(char) * (trimmedLength + 1));

      if (trimString != S21_NULL) {
        s21_strncpy(trimString, src + startIndex, trimmedLength);
        trimString[trimmedLength] = '\0';
      }
    }
  }
  return trimString;
}