#include "other.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int errorCode = S21_OTHER_OK;
  if (!result)
    errorCode = S21_OTHER_ERROR;
  else {
    *result = SetSign(value, !GetSign(value.bits, DECIMAL_SIZE));
    if (IsDecimalNotCorrect(value)) errorCode = S21_OTHER_ERROR;
  }
  return errorCode;
}