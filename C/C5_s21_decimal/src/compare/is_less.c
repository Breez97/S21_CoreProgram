#include "s21_decimal_compare.h"

int s21_is_less(s21_decimal decimal1, s21_decimal decimal2) {
  byte isLess = S21_COMPARE_OK;
  byte sign1 = GetSign(decimal1.bits, DECIMAL_SIZE);
  byte sign2 = GetSign(decimal2.bits, DECIMAL_SIZE);
  if (!(s21_is_equal(decimal1, GetZeroDecimal()) &&
        s21_is_equal(decimal2, GetZeroDecimal()))) {
    if (sign1 == NEGATIVE_NUMBER && sign2 == POSITIVE_NUMBER)
      isLess = 1;
    else if (sign1 == POSITIVE_NUMBER && sign2 == POSITIVE_NUMBER)
      isLess = IsLessCompareWithLeveling(decimal1, decimal2) == -1
                   ? S21_COMPARE_ERROR
                   : S21_COMPARE_OK;
    else if (sign1 == NEGATIVE_NUMBER && sign2 == NEGATIVE_NUMBER)
      isLess = IsLessCompareWithLeveling(decimal1, decimal2) == 1
                   ? S21_COMPARE_ERROR
                   : S21_COMPARE_OK;
  }
  return isLess;
}