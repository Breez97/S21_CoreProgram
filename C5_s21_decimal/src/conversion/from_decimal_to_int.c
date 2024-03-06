#include "conversion.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  byte code = S21_CONVERSION_OK;
  if (dst == NULL)
    code = S21_CONVERSION_ERROR;
  else if (IsDecimalNotCorrect(src))
    code = S21_CONVERSION_ERROR;

  if (code == S21_CONVERSION_OK) {
    s21_decimal withoutFloatingPart = {0};
    s21_truncate(src, &withoutFloatingPart);

    ConversionWithoutFloatingPart(withoutFloatingPart, dst, &code);

    if (GetSign(src.bits, DECIMAL_SIZE)) *dst *= -1;
  }

  return code;
}

s21_decimal GetDecimalOfMinMaxInt(const byte flagMinMax) {
  s21_decimal result = {0};
  s21_from_int_to_decimal(flagMinMax ? INT_MAX : INT_MIN, &result);
  return result;
}

void ConversionWithoutFloatingPart(const s21_decimal withoutFloatingPart,
                                   int *dst, byte *code) {
  if (s21_is_less(withoutFloatingPart, GetDecimalOfMinMaxInt(0)) ||
      s21_is_greater(withoutFloatingPart, GetDecimalOfMinMaxInt(1)))
    *code = S21_CONVERSION_ERROR;
  else {
    for (int i = 0; i < BITS_INT; i++) {
      if (GetBit(withoutFloatingPart.bits[0], i)) *dst += (1 << i);
    }
  }
}