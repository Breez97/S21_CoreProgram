#include "conversion.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  byte code = S21_CONVERSION_OK;
  if (dst == NULL)
    code = S21_CONVERSION_ERROR;
  else if (IsDecimalNotCorrect(src))
    code = S21_CONVERSION_ERROR;

  if (code == S21_CONVERSION_OK) {
    double result = 0.0;
    for (int i = 0; i < BITS_INT * 3; i++) {
      if (GetBit(src.bits[i / BITS_INT], i % BITS_INT)) result += pow(2.0, i);
    }
    result /= pow(10, GetPow(src.bits, DECIMAL_SIZE - 1));
    if (GetSign(src.bits, DECIMAL_SIZE)) result *= -1.0;
    *dst = result;
  }

  return code;
}
