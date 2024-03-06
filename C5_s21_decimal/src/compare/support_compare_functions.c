#include "s21_decimal_compare.h"

char IsLessCompareWithLeveling(const s21_decimal decimal1,
                               const s21_decimal decimal2) {
  s21_big_decimal bigDecimal1 = {0};
  s21_big_decimal bigDecimal2 = {0};
  PowLeveling(decimal1, decimal2, &bigDecimal1, &bigDecimal2);
  return UnsignedNotPowCompare(bigDecimal1.bits, bigDecimal2.bits,
                               DECIMAL_BIG_SIZE);
}

char UnsignedNotPowCompare(const unsigned int *decimal1,
                           const unsigned int *decimal2, const byte size) {
  unsigned char result = 0;
  for (int i = size - 2; i >= 0 && result == 0; i--) {
    if (decimal1[i] > decimal2[i]) {
      result = 1;
    } else if (decimal1[i] < decimal2[i]) {
      result = -1;
    }
  }
  return result;
}

byte IsEqualBigDecimal(const s21_big_decimal decimal1,
                       const s21_big_decimal decimal2) {
  return (isZeroes(decimal1.bits, 0, DECIMAL_BIG_SIZE - 1) &&
          isZeroes(decimal2.bits, 0, DECIMAL_BIG_SIZE - 1))
             ? 1
         : memcmp(decimal1.bits, decimal2.bits, sizeof(s21_big_decimal)) == 0
             ? 1
             : 0;
}
