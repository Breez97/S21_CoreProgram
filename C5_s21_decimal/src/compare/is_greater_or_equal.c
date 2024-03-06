#include "s21_decimal_compare.h"

int s21_is_greater_or_equal(s21_decimal decimal1, s21_decimal decimal2) {
  return s21_is_greater(decimal1, decimal2) || s21_is_equal(decimal1, decimal2);
}