#include "../s21_string.h"

char lower(char symbol) {
  if (symbol >= 'A' && symbol <= 'Z') {
    symbol = symbol - 'A' + 'a';
  }
  return symbol;
}

void *s21_to_lower(const char *str) {
  char *lowerString = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t numberElements = s21_strlen(str);
    lowerString = (char *)malloc((numberElements + 1) * sizeof(char));
    if (lowerString != S21_NULL) {
      for (s21_size_t i = 0; i < numberElements; i++) {
        lowerString[i] = lower(str[i]);
      }
      lowerString[numberElements] = '\0';
    }
  }

  return lowerString;
}