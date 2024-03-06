#include "s21_decimal_compare.h"

int s21_is_greater(s21_decimal decimal1, s21_decimal decimal2) {
  return !s21_is_less(decimal1, decimal2) && !s21_is_equal(decimal1, decimal2);
}