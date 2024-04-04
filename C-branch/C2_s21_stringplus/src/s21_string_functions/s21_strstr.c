#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  char *haystackCopy = (char *)haystack;
  char *needleCopy = (char *)needle;
  s21_size_t needleLength = s21_strlen(needle);
  if (s21_strlen(needle) == 0) {
    result = haystackCopy;
  } else {
    int isFound = 0;
    while (*haystackCopy != '\0' && isFound == 0) {
      if (*haystackCopy == *needleCopy &&
          s21_strncmp(haystackCopy, needleCopy, needleLength) == 0) {
        result = haystackCopy;
        isFound = 1;
      }
      haystackCopy++;
    }
  }
  return result;
}
