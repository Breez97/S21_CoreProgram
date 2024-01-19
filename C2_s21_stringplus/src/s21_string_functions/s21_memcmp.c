#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *pointerStrOne = (const unsigned char *)str1;
  const unsigned char *pointerStrTwo = (const unsigned char *)str2;
  int difference = 0;

  if (pointerStrOne != pointerStrTwo) {
    for (s21_size_t i = 0; i < n; i++) {
      if (pointerStrOne[i] != pointerStrTwo[i]) {
        difference = pointerStrOne[i] - pointerStrTwo[i];
        break;
      }
    }
  }

  return difference;
}