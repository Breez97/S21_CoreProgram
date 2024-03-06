#include "support.h"

s21_big_decimal FromDecimalToBigDecimal(s21_decimal decimal) {
  s21_big_decimal bigDecimal = {0};

  bigDecimal.bits[0] = decimal.bits[0];
  bigDecimal.bits[1] = decimal.bits[1];
  bigDecimal.bits[2] = decimal.bits[2];
  bigDecimal.bits[7] = decimal.bits[3];
  return bigDecimal;
}

void FromBigDecimalToDecimal(s21_big_decimal bigDecimal, s21_decimal *decimal) {
  decimal->bits[0] = bigDecimal.bits[0];
  decimal->bits[1] = bigDecimal.bits[1];
  decimal->bits[2] = bigDecimal.bits[2];
  decimal->bits[3] = bigDecimal.bits[7];
}

int ConvertBigDecimalToDecimal(s21_big_decimal bigDecimal,
                               s21_decimal *decimal) {
  int code = 0;
  int canFit = isZeroes(bigDecimal.bits, 3, DECIMAL_BIG_SIZE - 1);

  if (canFit) {
    FromBigDecimalToDecimal(bigDecimal, decimal);
  } else {
    byte tenPowToConvert = 0;
    s21_big_decimal remainder = {0};
    decimal_last_bit bit7;
    bit7.i = bigDecimal.bits[7];
    bigDecimal.bits[7] = 0;

    SetTenPowToConvertBigDecimal(bigDecimal, &tenPowToConvert);
    bigDecimal = s21_big_decimal_divide(
        bigDecimal, FromDecimalToBigDecimal(GetTenToPow(tenPowToConvert)),
        &remainder);

    bigDecimal.bits[7] = bit7.i;
    if (bit7.parts.decimalPow - tenPowToConvert >= 0) {
      bigDecimal = DecreasePowBigDecimal(bigDecimal, tenPowToConvert);
    } else {
      s21_big_decimal fillMaxDecimal = {
          {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0, 0x0, 0x0}};
      bigDecimal = fillMaxDecimal;
      code = S21_BIG_NUMBER_ERROR;
    }

    FromBigDecimalToDecimal(bigDecimal, decimal);
    s21_decimal remainderDecimal = {0};
    SetPowDecimal(&remainder.bits[7], tenPowToConvert);
    if (!isZeroes(remainder.bits, 3, DECIMAL_BIG_SIZE - 1)) {
      int firstPositiveBits =
          GetFirstPositiveBit(remainder.bits, DECIMAL_BIG_SIZE) % BITS_INT;
      for (int i = 0; i < DECIMAL_SIZE - 1; i++) {
        remainderDecimal.bits[i] = remainder.bits[firstPositiveBits - i];
      }
    } else {
      FromBigDecimalToDecimal(remainder, &remainderDecimal);
    }
    remainderDecimal.bits[3] = remainder.bits[7];
    *decimal = RoundBanking(*decimal, remainderDecimal);
  }
  return code;
}

void SetTenPowToConvertBigDecimal(s21_big_decimal bigDecimal,
                                  byte *tenPowToConvert) {
  s21_big_decimal fillMaxDecimal = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0, 0x0, 0x0}};
  s21_big_decimal remainder = {0};
  s21_big_decimal quotient =
      s21_big_decimal_divide(bigDecimal, fillMaxDecimal, &remainder);
  int powBigDecimal = GetPow(bigDecimal.bits, DECIMAL_BIG_SIZE - 1);

  while (UnsignedNotPowCompare(
             quotient.bits,
             FromDecimalToBigDecimal(GetTenToPow(*tenPowToConvert)).bits,
             DECIMAL_BIG_SIZE) > 0) {
    (*tenPowToConvert)++;
    if (*tenPowToConvert > MAX_TEN_POW - powBigDecimal) {
      (*tenPowToConvert)--;
      break;
    }
  }

  s21_big_decimal tmp = s21_big_decimal_divide(
      bigDecimal, FromDecimalToBigDecimal(GetTenToPow(*tenPowToConvert)),
      &remainder);
  if (!isZeroes(tmp.bits, 3, DECIMAL_BIG_SIZE - 1)) {
    (*tenPowToConvert)++;
    if (*tenPowToConvert > MAX_TEN_POW - powBigDecimal) {
      (*tenPowToConvert)--;
    }
  }
}
