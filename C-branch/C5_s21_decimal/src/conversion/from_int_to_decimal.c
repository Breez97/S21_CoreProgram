#include "conversion.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  byte code = S21_CONVERSION_OK;
  if (dst == NULL) code = S21_CONVERSION_ERROR;

  if (code == S21_CONVERSION_OK) {
    *dst = GetZeroDecimal();
    if (src < 0) {
      s21_negate(*dst, dst);
      if (src != INT_MIN) src = -src;
    }
    dst->bits[0] = src;
  }

  return code;
}
