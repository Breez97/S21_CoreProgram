#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *newString = S21_NULL;

  if (src != S21_NULL) {
    s21_size_t lenSourceString = s21_strlen(src);
    if (start_index <= lenSourceString) {
      if (str != S21_NULL) {
        s21_size_t lenInsertedString = s21_strlen(str);
        s21_size_t newLenString = lenSourceString + lenInsertedString;
        newString = (char *)malloc((newLenString + 1) * sizeof(char));
        if (newString != S21_NULL) {
          s21_strncpy(newString, src, start_index);
          s21_strncpy(newString + start_index, str, lenInsertedString);
          s21_strncpy(newString + start_index + lenInsertedString,
                      src + start_index, lenSourceString - start_index);
          newString[newLenString] = '\0';
        }
      } else {
        newString = (char *)malloc((lenSourceString + 1) * sizeof(char));
        if (newString != S21_NULL) {
          s21_strncpy(newString, src, lenSourceString);
          newString[lenSourceString] = '\0';
        }
      }
    }
  }

  return newString;
}