#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int errorCode = S21_OTHER_OK;
  s21_decimal zeroedValue = GetZeroDecimal();
  s21_decimal reminder = GetZeroDecimal();
  if (!result || IsDecimalNotCorrect(value)) {
    errorCode = S21_OTHER_ERROR;
  } else {
    s21_decimal one = GetOneDecimal();
    s21_decimal minusOne = SetSign(one, NEGATIVE_NUMBER);
    if (s21_is_less(value, one) && s21_is_greater(value, minusOne)) {
      *result = GetZeroDecimal();
    } else {
      *result = zeroedValue;
      int power = GetPow(value.bits, DECIMAL_SIZE - 1);
      s21_decimal tmp = value;
      tmp.bits[DECIMAL_SIZE - 1] = 0;
      tmp = s21_decimal_divide(tmp, tenPowUpTo29[power], &reminder);

      *result = tmp;
    }
    if (GetSign(value.bits, DECIMAL_SIZE) == NEGATIVE_NUMBER) {
      *result = SetSign(*result, NEGATIVE_NUMBER);
    }
  }
  return errorCode;
}