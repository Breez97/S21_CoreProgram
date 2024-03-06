#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int errorCode = S21_OTHER_OK;
  s21_decimal zeroedValue = GetZeroDecimal();
  if (!result || IsDecimalNotCorrect(value)) {
    errorCode = S21_OTHER_ERROR;
  } else {
    *result = zeroedValue;
    byte sign = GetSign(value.bits, DECIMAL_SIZE);
    s21_decimal unsignedValue = s21_abs(value);

    s21_decimal trancatedValue;
    s21_truncate(unsignedValue, &trancatedValue);

    s21_decimal fracPart;
    s21_sub(unsignedValue, trancatedValue, &fracPart);

    trancatedValue = RoundBanking(trancatedValue, fracPart);
    *result = trancatedValue;
    *result = SetSign(*result, sign);
  }
  return errorCode;
}

s21_decimal RoundBanking(const s21_decimal decimal,
                         const s21_decimal remainder) {
  const s21_decimal zerofive = GetZeroFiveDecimal();
  const s21_decimal one = GetOneDecimal();

  int needsRounding =
      s21_is_greater(remainder, zerofive) ||
      (s21_is_equal(remainder, zerofive) && GetBit(decimal.bits[0], 0));

  return needsRounding ? s21_decimal_add(decimal, one) : decimal;
}