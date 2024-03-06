#include "arithmetic.h"

int s21_add(s21_decimal decimal1, s21_decimal decimal2, s21_decimal *result) {
  byte code = S21_OK;
  if (result == NULL) {
    code = S21_ANY_ERROR;
  } else if (IsDecimalNotCorrect(decimal1) || IsDecimalNotCorrect(decimal2)) {
    code = S21_BIG_NUMBER_ERROR;
  }

  if (code == S21_OK) {
    *result = GetZeroDecimal();
    CheckOperatorAddLogic(&code, GetSign(decimal1.bits, DECIMAL_SIZE),
                          GetSign(decimal2.bits, DECIMAL_SIZE), decimal1,
                          decimal2, result);
  }

  return code;
}

void CheckOperatorAddLogic(byte *code, const byte sign1, const byte sign2,
                           const s21_decimal decimal1,
                           const s21_decimal decimal2, s21_decimal *result) {
  if (sign1 == POSITIVE_NUMBER) {
    if (sign2 == POSITIVE_NUMBER) {
      MainAddLogic(decimal1, decimal2, result, code);
    } else {
      *code = s21_sub(decimal1, s21_abs(decimal2), result);
    }
  } else {
    if (sign2 == POSITIVE_NUMBER) {
      *code = s21_sub(decimal2, s21_abs(decimal1), result);
    } else {
      MainAddLogic(s21_abs(decimal1), s21_abs(decimal2), result, code);
      s21_negate(*result, result);
    }
  }
  if (GetSign(result->bits, DECIMAL_SIZE) && *code == S21_BIG_NUMBER_ERROR)
    *code = S21_SMALL_NUMBER_ERROR;
}

void MainAddLogic(const s21_decimal decimal1, const s21_decimal decimal2,
                  s21_decimal *result, byte *code) {
  s21_big_decimal decimalBig1 = {0};
  s21_big_decimal decimalBig2 = {0};
  int resPow = PowLeveling(decimal1, decimal2, &decimalBig1, &decimalBig2);
  SetPowDecimal(&decimalBig1.bits[7], 0);
  SetPowDecimal(&decimalBig2.bits[7], 0);
  s21_big_decimal resultBigDecimal =
      s21_big_decimal_add(decimalBig1, decimalBig2);
  SetPowDecimal(&resultBigDecimal.bits[7], resPow);
  *code = ConvertBigDecimalToDecimal(resultBigDecimal, result);
}

void add_numbers(unsigned int *result, const unsigned int *a,
                 const unsigned int *b, byte size) {
  unsigned int carry = 0;
  for (int i = 0; i < size; i++) {
    unsigned long long sum = (unsigned long long)a[i] + b[i] + carry;
    result[i] = (unsigned int)sum;
    carry = (unsigned int)(sum >> 32);
  }
}

s21_decimal s21_decimal_add(const s21_decimal a, const s21_decimal b) {
  s21_decimal result = {0};
  add_numbers(result.bits, a.bits, b.bits, DECIMAL_SIZE);
  return result;
}

s21_big_decimal s21_big_decimal_add(const s21_big_decimal a,
                                    const s21_big_decimal b) {
  s21_big_decimal result = {0};
  add_numbers(result.bits, a.bits, b.bits, DECIMAL_BIG_SIZE);
  return result;
}

// int main() {
//     s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
//     s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
//     s21_decimal result;
//     int result_value = s21_add(dec_1, dec_2, &result);
//     printf("%d", result_value);
//     return 0;
// }

// START_TEST(invalid_dec_s21_add_2) {
//   // степень 56 (допустимое значение от 0 до 28)
//   // биты 0-15 не пустые
//   // биты 24-30 не пустые
//   s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
//   s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
//   s21_decimal result;
//   int result_value = s21_add(dec_1, dec_2, &result);

//   ck_assert_int_eq(result_value, 1);
// }
// END_TEST