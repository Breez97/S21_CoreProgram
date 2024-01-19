#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *destinationPointer = dest;
  s21_size_t countSymbolsStep = s21_strlen(destinationPointer);
  s21_size_t i = 0;
  for (; i < n && src[i] != '\0'; i++) {
    destinationPointer[countSymbolsStep + i] = src[i];
  }

  destinationPointer[i + countSymbolsStep] = '\0';

  return dest;
}