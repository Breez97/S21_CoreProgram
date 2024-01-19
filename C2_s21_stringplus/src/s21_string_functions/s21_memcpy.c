#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *destinationPonter = (unsigned char *)dest;
  const unsigned char *sourcePointer = (const unsigned char *)src;

  if (destinationPonter != sourcePointer) {
    for (s21_size_t i = 0; i < n; i++) {
      destinationPonter[i] = sourcePointer[i];
    }
  }

  return dest;
}