#include "arithmetic.h"

int s21_sub(s21_decimal decimal1, s21_decimal decimal2, s21_decimal *result) {
  byte code = S21_OK;
  if (result == NULL) {
    code = S21_ANY_ERROR;
  } else if (IsDecimalNotCorrect(decimal1) || IsDecimalNotCorrect(decimal2)) {
    code = S21_BIG_NUMBER_ERROR;
  }

  if (code == S21_OK) {
    *result = GetZeroDecimal();
    CheckOperatorSubLogic(&code, GetSign(decimal1.bits, DECIMAL_SIZE),
                          GetSign(decimal2.bits, DECIMAL_SIZE), decimal1,
                          decimal2, result);
  }
  return code;
}

void MainSubLogic(const s21_decimal decimal1, const s21_decimal decimal2,
                  s21_decimal *result, byte *code) {
  s21_big_decimal decimalBig1 = {0};
  s21_big_decimal decimalBig2 = {0};
  int resPow = PowLeveling(decimal1, decimal2, &decimalBig1, &decimalBig2);
  SetPowDecimal(&decimalBig1.bits[7], 0);
  SetPowDecimal(&decimalBig2.bits[7], 0);
  s21_big_decimal resultBigDecimal =
      s21_big_decimal_subtract(decimalBig1, decimalBig2);
  SetPowDecimal(&resultBigDecimal.bits[7], resPow);
  *code = ConvertBigDecimalToDecimal(resultBigDecimal, result);
}

void CheckOperatorSubLogic(byte *code, const byte sign1, const byte sign2,
                           const s21_decimal decimal1,
                           const s21_decimal decimal2, s21_decimal *result) {
  if (sign1 == POSITIVE_NUMBER) {
    if (sign2 == POSITIVE_NUMBER) {
      if (s21_is_greater_or_equal(decimal1, decimal2)) {
        MainSubLogic(decimal1, decimal2, result, code);
      } else {
        MainSubLogic(decimal2, decimal1, result, code);
        s21_negate(*result, result);
      }
    } else {
      *code = s21_add(decimal1, s21_abs(decimal2), result);
    }
  } else {
    if (sign2 == POSITIVE_NUMBER) {
      *code = s21_add(s21_abs(decimal1), decimal2, result);
      s21_negate(*result, result);
    } else {
      if (s21_is_greater_or_equal(decimal1, decimal2)) {
        MainSubLogic(s21_abs(decimal2), s21_abs(decimal1), result, code);
      } else {
        MainSubLogic(s21_abs(decimal1), s21_abs(decimal2), result, code);
        s21_negate(*result, result);
      }
    }
  }

  if (GetSign(result->bits, DECIMAL_SIZE) && *code == S21_BIG_NUMBER_ERROR)
    *code = S21_SMALL_NUMBER_ERROR;
}

s21_decimal s21_decimal_subtract(const s21_decimal a, const s21_decimal b) {
  s21_decimal b_complemented = {
      {~b.bits[0], ~b.bits[1], ~b.bits[2], ~b.bits[3]}};
  s21_decimal one = {{1, 0, 0, 0}};
  return s21_decimal_add(a, s21_decimal_add(b_complemented, one));
}

s21_big_decimal s21_big_decimal_subtract(const s21_big_decimal a,
                                         const s21_big_decimal b) {
  s21_big_decimal b_complemented = {{~b.bits[0], ~b.bits[1], ~b.bits[2],
                                     ~b.bits[3], ~b.bits[4], ~b.bits[5],
                                     ~b.bits[6], ~b.bits[7]}};
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  return s21_big_decimal_add(a, s21_big_decimal_add(b_complemented, one));
}