#include "support.h"

#include <stdio.h>

int GetBit(unsigned int value, int index) { return value & (1 << index); }

int GetPow(const unsigned int *decimals, int powBitIndex) {
  decimal_last_bit bitPow;
  bitPow.i = decimals[powBitIndex];
  return bitPow.parts.decimalPow;
}

s21_big_decimal IncreasePowBigDecimal(s21_big_decimal value, int addPowValue) {
  decimal_last_bit bit7;
  bit7.i = value.bits[7];
  bit7.parts.decimalPow += addPowValue;
  value.bits[7] = bit7.i;
  return value;
}

s21_big_decimal DecreasePowBigDecimal(s21_big_decimal value, int subPowValue) {
  decimal_last_bit bit7;
  bit7.i = value.bits[7];
  bit7.parts.decimalPow -= subPowValue;
  value.bits[7] = bit7.i;
  return value;
}

void SetPowDecimal(unsigned int *bits, const byte pow) {
  decimal_last_bit bit3;
  bit3.i = *bits;
  bit3.parts.decimalPow = pow;
  *bits = bit3.i;
}

s21_decimal GetZeroDecimal() {
  s21_decimal zeroDecimal = {0};
  return zeroDecimal;
}

s21_decimal GetTenToPow(const byte pow) {
  s21_decimal tenPow = {0};
  tenPow = tenPowUpTo29[pow];
  return tenPow;
}

s21_decimal GetMaxDecimal() {
  s21_decimal maxDecimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  return maxDecimal;
}

s21_decimal GetOneDecimal() {
  s21_decimal oneDecimal = {{0x00000001, 0x0, 0x0, 0x0}};
  return oneDecimal;
}

s21_decimal GetZeroFiveDecimal() {
  s21_decimal zeroFiveDecimal = {{0x00000005, 0x0, 0x0, 0x0}};
  SetPowDecimal(&zeroFiveDecimal.bits[3], 1);
  return zeroFiveDecimal;
}

byte isZeroes(const unsigned int *decimalBits, const int startBitsindex,
              const int endBitsIndex) {
  byte isZeroes = 1;
  for (int i = startBitsindex; i < endBitsIndex && isZeroes; i++) {
    if (decimalBits[i] != 0) isZeroes = 0;
  }
  return isZeroes;
}

byte IsPowsNotEmpty(const s21_decimal value) {
  decimal_last_bit bit3;
  bit3.i = value.bits[3];
  return (bit3.parts.emptyOne != 0 || bit3.parts.emptyTwo != 0);
}

s21_decimal SetSign(const s21_decimal value, const byte sign) {
  s21_decimal newValue = value;
  decimal_last_bit bit3;
  bit3.i = newValue.bits[3];
  bit3.parts.sign = sign;
  newValue.bits[3] = bit3.i;
  return newValue;
}

s21_decimal s21_abs(const s21_decimal decimal1) {
  return SetSign(decimal1, POSITIVE_NUMBER);
}

byte GetSign(const unsigned int *value, const byte size) {
  decimal_last_bit bit3;
  bit3.i = value[size - 1];
  return bit3.parts.sign;
}

byte IsDecimalNotCorrect(const s21_decimal value) {
  return (IsPowsNotEmpty(value) || GetPow(value.bits, DECIMAL_SIZE - 1) < 0 ||
          GetPow(value.bits, DECIMAL_SIZE - 1) > 28);
}

byte TotalDigits(const unsigned int *arr, const byte size) {
  byte result = 0;
  for (byte i = 0; i < size; i++) {
    if (arr[i] != 0) result += floor(log10(arr[i])) + 1;
  }
  return result;
}
