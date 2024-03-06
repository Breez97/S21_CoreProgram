#include "s21_decimal_compare.h"

int s21_is_equal(s21_decimal decimal1, s21_decimal decimal2) {
  s21_big_decimal bigDecimal1 = {0};
  s21_big_decimal bigDecimal2 = {0};
  PowLeveling(decimal1, decimal2, &bigDecimal1, &bigDecimal2);
  return IsEqualBigDecimal(bigDecimal1, bigDecimal2);
}
