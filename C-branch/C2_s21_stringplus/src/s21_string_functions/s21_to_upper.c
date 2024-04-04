#include "../s21_string.h"

char upper(char symbol) {
  if (symbol >= 'a' && symbol <= 'z') {
    symbol = symbol - 'a' + 'A';
  }
  return symbol;
}

void *s21_to_upper(const char *str) {
  char *upperString = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t numberElements = s21_strlen(str);
    upperString = (char *)malloc((numberElements + 1) * sizeof(char));
    if (upperString != S21_NULL) {
      for (s21_size_t i = 0; i < numberElements; i++) {
        upperString[i] = upper(str[i]);
      }
      upperString[numberElements] = '\0';
    }
  }

  return upperString;
}