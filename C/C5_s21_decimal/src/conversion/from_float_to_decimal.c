#include "conversion.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  byte code = S21_CONVERSION_OK;
  if (dst == NULL)
    code = S21_CONVERSION_ERROR;
  else if (0.0 < fabs(src) && fabs(src) < S21_MIN_FLOAT) {
    code = S21_CONVERSION_ERROR;
    *dst = GetZeroDecimal();
  } else if (isinf(src) || isnan(src))
    code = S21_CONVERSION_ERROR;

  if (code == S21_CONVERSION_OK) {
    s21_decimal result = {0};
    int sign = (src < 0.0) ? 1 : 0;
    if (sign) src = fabs(src);

    int exp = GetExpAndBringToInt(src, &result);

    SetPowDecimal(&result.bits[3], exp);
    if (sign) s21_negate(result, &result);
    *dst = result;
  }

  return code;
}

int GetExpAndBringToInt(float src, s21_decimal *result) {
  char floatToString[128];
  sprintf(floatToString, "%.7g", src);
  src = (float)(atof(floatToString));
  long long int intPart = (long long int)src;
  int exp = 0;
  while (src - ((float)intPart / (long long int)(pow(10, exp))) != 0) {
    exp++;
    intPart = src * (long long int)pow(10, exp);
  }
  s21_from_int_to_decimal((int)intPart, result);
  return exp;
}
