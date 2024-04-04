#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int errorCode = S21_OTHER_OK;
  if (!result || IsDecimalNotCorrect(value)) {
    errorCode = S21_OTHER_ERROR;
  } else {
    byte sign = GetSign(value.bits, DECIMAL_SIZE);

    s21_decimal zeroedValue = {0};
    s21_decimal one = GetOneDecimal();

    s21_decimal unsignedValue = s21_abs(value);

    s21_decimal truncatedValue = {0};
    s21_truncate(unsignedValue, &truncatedValue);

    s21_decimal fractionalPart = {0};
    s21_sub(unsignedValue, truncatedValue, &fractionalPart);

    if (sign == NEGATIVE_NUMBER &&
        s21_is_greater(fractionalPart, zeroedValue)) {
      s21_add(truncatedValue, one, &truncatedValue);
    }

    *result = SetSign(truncatedValue, sign);
  }
  return errorCode;
}