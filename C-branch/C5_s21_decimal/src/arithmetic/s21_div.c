#include "arithmetic.h"

int s21_div(s21_decimal decimal1, s21_decimal decimal2, s21_decimal *result) {
  byte code = S21_OK;

  if (!result) {
    code = S21_ANY_ERROR;
  } else if (IsDecimalNotCorrect(decimal1) || IsDecimalNotCorrect(decimal2)) {
    code = S21_BIG_NUMBER_ERROR;
  } else if (s21_is_equal(decimal1, GetZeroDecimal())) {
    *result = GetZeroDecimal();
  }

  else if (s21_is_equal(decimal2, GetZeroDecimal())) {
    code = S21_ZERO_DIV_ERROR;
    *result = GetMaxDecimal();
  } else {
    if (s21_is_less(s21_abs(decimal1), s21_abs(decimal2))) {
      code = S21_SMALL_NUMBER_ERROR;
    }
    *result = GetZeroDecimal();
    CheckOperatorDivLogic(&code, GetSign(decimal1.bits, DECIMAL_SIZE),
                          GetSign(decimal2.bits, DECIMAL_SIZE), decimal1,
                          decimal2, result);
  }

  return code;
}

void CheckOperatorDivLogic(byte *code, const byte sign1, const byte sign2,
                           const s21_decimal decimal1,
                           const s21_decimal decimal2, s21_decimal *result) {
  if ((sign1 == NEGATIVE_NUMBER && sign2 == NEGATIVE_NUMBER) ||
      (sign1 == POSITIVE_NUMBER && sign2 == POSITIVE_NUMBER)) {
    MainDivLogic(decimal1, decimal2, result, code);
  } else {
    MainDivLogic(decimal1, decimal2, result, code);
    s21_negate(*result, result);
  }

  if (GetSign(result->bits, DECIMAL_SIZE) && *code == S21_BIG_NUMBER_ERROR)
    *code = S21_SMALL_NUMBER_ERROR;
}

void MainDivLogic(s21_decimal decimal1, s21_decimal decimal2,
                  s21_decimal *result, byte *code) {
  *result = GetZeroDecimal();
  // степени для увеличения исходной степени числа
  int powMul1 = 0;

  // обработка случая (пример) 7 / 56 = 0.125 -> 7 * 10^2 (количество разрядов
  // делителя) = 700 , 700 / 56 = 12.5
  if (s21_is_less(s21_abs(decimal1), s21_abs(decimal2))) {
    // устанавливаем степень для последующего увеличения
    powMul1 = TotalDigits(decimal2.bits, DECIMAL_SIZE - 1);
  }
  int pow1 = GetPow(decimal1.bits, DECIMAL_SIZE - 1);
  int pow2 = GetPow(decimal2.bits, DECIMAL_SIZE - 1);

  decimal1.bits[3] = 0;
  decimal2.bits[3] = 0;

  s21_big_decimal bigDecimal1 = FromDecimalToBigDecimal(decimal1);
  s21_big_decimal bigDecimal2 = FromDecimalToBigDecimal(decimal2);
  s21_big_decimal remainder = {0};
  s21_big_decimal res = {0};

  // Высчитваем результат деления без дробной части по правилу деления
  // обыкновенных дробей пример 2/10^2 : 4/10^3 = (2 * 10^3)/(10^2 * 4)
  s21_big_decimal tmpDivinded = s21_big_decimal_multiply(
      bigDecimal1, FromDecimalToBigDecimal(GetTenToPow(pow2 + powMul1)));
  s21_big_decimal tmpDivisor = s21_big_decimal_multiply(
      bigDecimal2, FromDecimalToBigDecimal(GetTenToPow(pow1)));
  res = s21_big_decimal_divide(tmpDivinded, tmpDivisor, &remainder);

  // добавляем дробную часть и запоминаем степень на которую надо будет
  // увеличить итоговый результат

  powMul1 += CalculationFractionalPart(&res, tmpDivisor, &remainder, code);
  res = IncreasePowBigDecimal(res, powMul1);
  ConvertBigDecimalToDecimal(res, result);

  // Опять получаем дробную часть отдельно для банковского округления
  s21_big_decimal fractPart = {0};
  s21_decimal fractPartDecimal = {0};
  SetPowDecimal(
      &fractPart.bits[7],
      CalculationFractionalPart(&fractPart, tmpDivisor, &remainder, code));

  FromBigDecimalToDecimal(fractPart, &fractPartDecimal);
  fractPartDecimal.bits[3] = fractPart.bits[7];
  *result = RoundBanking(*result, fractPartDecimal);
}

byte CalculationFractionalPart(s21_big_decimal *res,
                               const s21_big_decimal divisor,
                               s21_big_decimal *remainder, byte *code) {
  s21_big_decimal number = *res;
  s21_big_decimal tmpRemainder = *remainder;
  s21_big_decimal ten = FromDecimalToBigDecimal(GetTenToPow(1));
  byte power = 0;

  for (; power < 28 && !isZeroes(tmpRemainder.bits, 0, DECIMAL_BIG_SIZE - 1);
       power++) {
    s21_big_decimal numberPrev = number;
    s21_big_decimal remainderPrev = tmpRemainder;

    tmpRemainder = s21_big_decimal_multiply(tmpRemainder, ten);
    s21_big_decimal digit =
        s21_big_decimal_divide(tmpRemainder, divisor, &tmpRemainder);
    number = s21_big_decimal_add(s21_big_decimal_multiply(number, ten), digit);

    if (!isZeroes(number.bits, 3, DECIMAL_BIG_SIZE - 1)) {
      number = numberPrev;
      tmpRemainder = remainderPrev;
      break;
    }
  }

  if (*code == S21_SMALL_NUMBER_ERROR && power != 0 &&
      IsEqualBigDecimal(tmpRemainder,
                        FromDecimalToBigDecimal(GetZeroDecimal())))
    *code = S21_OK;

  *res = number;
  *remainder = tmpRemainder;

  return power;
}

short int GetFirstPositiveBit(const unsigned int *decimal, const byte size) {
  short int result = -1;
  for (short int i = (size * BITS_INT) - 1; i >= 0 && result == -1; i--) {
    if (GetBit(decimal[i / BITS_INT], i % BITS_INT)) result = i;
  }

  return result;
}

void BinaryShiftLeft(unsigned int *result, const unsigned int *decimal,
                     const byte size) {
  byte carry = 0;

  for (short int i = 0; i < size; i++) {
    byte new_carry = GetBit(decimal[i], BITS_INT - 1) == 0 ? 0 : 1;
    result[i] = (decimal[i] << 1) | carry;
    carry = new_carry;
  }
}

void IterateBinaryShiftLeft(unsigned int *result, const unsigned int *decimal,
                            const short int shift, const byte size) {
  unsigned int tempResult[size];
  memcpy(tempResult, decimal, size * sizeof(unsigned int));

  for (short int i = 0; i < shift; i++) {
    BinaryShiftLeft(result, tempResult, size);
    memcpy(tempResult, result, size * sizeof(unsigned int));
  }
}

void BinaryShiftRight(unsigned int *result, const unsigned int *decimal,
                      const byte size) {
  byte carry = 0;

  for (short int i = size - 1; i >= 0; i--) {
    byte temparyCarry = GetBit(decimal[i], 0) == 0 ? 0 : 1;
    result[i] = (decimal[i] >> 1) | (carry ? (1U << (BITS_INT - 1)) : 0);
    carry = temparyCarry;
  }
}

void IterateBinaryShiftRight(unsigned int *result, const unsigned int *decimal,
                             const short int shift, const byte size) {
  unsigned int tempResult[size];
  memcpy(tempResult, decimal, size * sizeof(unsigned int));

  for (short int i = 0; i < shift; i++) {
    BinaryShiftRight(result, tempResult, size);
    memcpy(tempResult, result, size * sizeof(unsigned int));
  }
}

s21_decimal s21_decimal_divide(const s21_decimal dividend,
                               const s21_decimal divisor,
                               s21_decimal *remainder) {
  s21_decimal quotient = {0};
  s21_decimal shiftedDivisor = {0};
  s21_decimal temparyDividend = dividend;
  *remainder = temparyDividend;

  char shift = GetFirstPositiveBit(dividend.bits, DECIMAL_SIZE) -
               GetFirstPositiveBit(divisor.bits, DECIMAL_SIZE);
  IterateBinaryShiftLeft(shiftedDivisor.bits, divisor.bits, shift,
                         DECIMAL_SIZE);

  byte carry = 0;

  for (char sh_i = shift; sh_i >= 0; sh_i--) {
    *remainder = temparyDividend;

    *remainder = carry == 0 ? s21_decimal_subtract(*remainder, shiftedDivisor)
                            : s21_decimal_add(*remainder, shiftedDivisor);

    carry = GetSign(remainder->bits, DECIMAL_SIZE) == 0 ? 0 : 1;

    IterateBinaryShiftLeft(quotient.bits, quotient.bits, 1, DECIMAL_SIZE);
    quotient.bits[0] |= !carry;
    IterateBinaryShiftLeft(temparyDividend.bits, remainder->bits, 1,
                           DECIMAL_SIZE);
  }

  if (carry) {
    *remainder = s21_decimal_add(*remainder, shiftedDivisor);
  }

  IterateBinaryShiftRight(remainder->bits, remainder->bits, shift,
                          DECIMAL_SIZE);
  if (s21_is_equal(*remainder, dividend)) {
    *remainder = s21_decimal_subtract(*remainder,
                                      s21_decimal_multiply(divisor, quotient));
  }
  return quotient;
}

s21_big_decimal s21_big_decimal_divide(const s21_big_decimal dividend,
                                       const s21_big_decimal divisor,
                                       s21_big_decimal *remainder) {
  s21_big_decimal quotient = {0};
  s21_big_decimal shiftedDivisor = {0};
  s21_big_decimal temparyDividend = dividend;

  short int shift = GetFirstPositiveBit(dividend.bits, DECIMAL_BIG_SIZE) -
                    GetFirstPositiveBit(divisor.bits, DECIMAL_BIG_SIZE);
  IterateBinaryShiftLeft(shiftedDivisor.bits, divisor.bits, shift,
                         DECIMAL_BIG_SIZE);

  byte carry = 0;
  *remainder = temparyDividend;
  for (short int sh_i = shift; sh_i >= 0; sh_i--) {
    *remainder = temparyDividend;

    *remainder = carry == 0
                     ? s21_big_decimal_subtract(*remainder, shiftedDivisor)
                     : s21_big_decimal_add(*remainder, shiftedDivisor);

    carry = GetSign(remainder->bits, DECIMAL_BIG_SIZE);

    IterateBinaryShiftLeft(quotient.bits, quotient.bits, 1, DECIMAL_BIG_SIZE);
    quotient.bits[0] |= !carry;
    IterateBinaryShiftLeft(temparyDividend.bits, remainder->bits, 1,
                           DECIMAL_BIG_SIZE);
  }

  if (carry) *remainder = s21_big_decimal_add(*remainder, shiftedDivisor);

  IterateBinaryShiftRight(remainder->bits, remainder->bits, shift,
                          DECIMAL_BIG_SIZE);
  if (IsEqualBigDecimal(*remainder, dividend)) {
    *remainder = s21_big_decimal_subtract(
        *remainder, s21_big_decimal_multiply(divisor, quotient));
    if (remainder->bits[7] != 0) {
      *remainder = dividend;
      quotient = FromDecimalToBigDecimal(GetZeroDecimal());
    }
  }
  return quotient;
}
