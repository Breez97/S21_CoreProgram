#include "arithmetic.h"

int s21_mul(s21_decimal decimal1, s21_decimal decimal2, s21_decimal *result) {
  byte code = S21_OK;
  if (result == NULL) {
    code = S21_ANY_ERROR;
  } else if (IsDecimalNotCorrect(decimal1) || IsDecimalNotCorrect(decimal2)) {
    code = S21_BIG_NUMBER_ERROR;
  }

  if (code == S21_OK) {
    *result = GetZeroDecimal();
    int resultPow = GetPow(decimal1.bits, DECIMAL_SIZE - 1) +
                    GetPow(decimal2.bits, DECIMAL_SIZE - 1);
    if (isZeroes(decimal1.bits, 0, DECIMAL_SIZE - 1) ||
        isZeroes(decimal2.bits, 0, DECIMAL_SIZE - 1)) {
      SetPowDecimal(&result->bits[DECIMAL_SIZE - 1], resultPow);
      *result = SetSign(*result, POSITIVE_NUMBER);
    } else {
      CheckOperatorMulLogic(&code, GetSign(decimal1.bits, DECIMAL_SIZE),
                            GetSign(decimal2.bits, DECIMAL_SIZE), decimal1,
                            decimal2, result, resultPow);
    }
  }

  return code;
}

void CheckOperatorMulLogic(byte *code, const byte sign1, const byte sign2,
                           const s21_decimal decimal1,
                           const s21_decimal decimal2, s21_decimal *result,
                           const int resultPow) {
  if (sign1 == POSITIVE_NUMBER) {
    if (sign2 == POSITIVE_NUMBER) {
      MainMulLogic(decimal1, decimal2, result, code, resultPow);
    } else {
      MainMulLogic(decimal1, s21_abs(decimal2), result, code, resultPow);
      s21_negate(*result, result);
    }
  } else {
    if (sign2 == POSITIVE_NUMBER) {
      MainMulLogic(s21_abs(decimal1), decimal2, result, code, resultPow);
      s21_negate(*result, result);
    } else {
      MainMulLogic(s21_abs(decimal1), s21_abs(decimal2), result, code,
                   resultPow);
    }
  }

  if (GetSign(result->bits, DECIMAL_SIZE) && *code == S21_BIG_NUMBER_ERROR)
    *code = S21_SMALL_NUMBER_ERROR;
}

void MainMulLogic(const s21_decimal decimal1, const s21_decimal decimal2,
                  s21_decimal *result, byte *code, const int resultPow) {
  s21_big_decimal decimalBig1 = FromDecimalToBigDecimal(decimal1);
  s21_big_decimal decimalBig2 = FromDecimalToBigDecimal(decimal2);
  s21_big_decimal resultBigDecimal =
      s21_big_decimal_multiply(decimalBig1, decimalBig2);
  SetPowDecimal(&resultBigDecimal.bits[7], resultPow);
  *code = ConvertBigDecimalToDecimal(resultBigDecimal, result);
}

void multiply_numbers(unsigned int *result, const unsigned int *a,
                      const unsigned int *b, byte size) {
  unsigned int temp[size * 2];

  for (int i = 0; i < size * 2; i++) {
    temp[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    unsigned int carry = 0;
    for (int j = 0; j < size; j++) {
      unsigned long long product =
          (unsigned long long)a[i] * b[j] + temp[i + j] + carry;
      temp[i + j] = (unsigned int)product;
      carry = (unsigned int)(product >> 32);
    }
    temp[i + size] = carry;
  }

  for (int i = 0; i < size; i++) {
    result[i] = temp[i];
  }
}

s21_decimal s21_decimal_multiply(const s21_decimal a, const s21_decimal b) {
  s21_decimal result = {0};
  multiply_numbers(result.bits, a.bits, b.bits, DECIMAL_SIZE - 1);
  return result;
}

s21_big_decimal s21_big_decimal_multiply(const s21_big_decimal a,
                                         const s21_big_decimal b) {
  s21_big_decimal result = {0};
  multiply_numbers(result.bits, a.bits, b.bits, DECIMAL_BIG_SIZE - 1);
  return result;
}
