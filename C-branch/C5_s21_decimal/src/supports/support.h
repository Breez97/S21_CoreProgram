#ifndef SRC_S21_DECIMAL_SUPPORT_H
#define SRC_S21_DECIMAL_SUPPORT_H

#include <math.h>
#include <stdlib.h>

#include "../arithmetic/arithmetic.h"
#include "../s21_decimal_types.h"

#define MAX_TEN_POW 28
#define POSITIVE_NUMBER 0
#define NEGATIVE_NUMBER 1

int PowLeveling(s21_decimal decimal1, s21_decimal decimal2,
                s21_big_decimal *bigDecimal1, s21_big_decimal *bigDecimal2);

void SetBit(unsigned int *value, int index, int target);
int GetBit(unsigned int value, int index);
void InvertBit(unsigned int *value, int index);
int GetPow(const unsigned int *decimals, int powBitIndex);
byte IsDecimalNotCorrect(const s21_decimal value);
byte IsPowsNotEmpty(const s21_decimal value);

s21_big_decimal FromDecimalToBigDecimal(s21_decimal decimal);
int ConvertBigDecimalToDecimal(s21_big_decimal bigDecimal,
                               s21_decimal *decimal);
void FromBigDecimalToDecimal(s21_big_decimal bigDecimal, s21_decimal *decimal);
s21_big_decimal IncreasePowBigDecimal(s21_big_decimal value, int addPowValue);
s21_big_decimal DecreasePowBigDecimal(s21_big_decimal value, int subPowValue);

byte GetSign(const unsigned int *value, const byte size);
s21_decimal SetSign(const s21_decimal value, const byte sign);
byte isZeroes(const unsigned int *decimalBits, const int startBitsindex,
              const int endBitsIndex);

s21_decimal GetZeroDecimal();
s21_decimal GetTenToPow(const byte pow);
s21_decimal GetOneDecimal();
s21_decimal GetZeroFiveDecimal();
s21_decimal GetMaxDecimal();

void FromBigDecimalToDecimal(s21_big_decimal bigDecimal, s21_decimal *decimal);
void SetTenPowToConvertBigDecimal(s21_big_decimal bigDecimal,
                                  byte *tenPowToConvert);
void SetPowDecimal(unsigned int *bits, const byte pow);
byte TotalDigits(const unsigned int *arr, const byte size);

s21_decimal s21_abs(const s21_decimal decimal1);

static const s21_decimal tenPowUpTo29[29] = {
    [0] = {{0x1, 0x0, 0x0, 0x0}},
    [1] = {{0xA, 0x0, 0x0, 0x0}},
    [2] = {{0x64, 0x0, 0x0, 0x0}},
    [3] = {{0x3E8, 0x0, 0x0, 0x0}},
    [4] = {{0x2710, 0x0, 0x0, 0x0}},
    [5] = {{0x186A0, 0x0, 0x0, 0x0}},
    [6] = {{0xF4240, 0x0, 0x0, 0x0}},
    [7] = {{0x989680, 0x0, 0x0, 0x0}},
    [8] = {{0x5F5E100, 0x0, 0x0, 0x0}},
    [9] = {{0x3B9ACA00, 0x0, 0x0, 0x0}},
    [10] = {{0x540BE400, 0x2, 0x0, 0x0}},
    [11] = {{0x4876E800, 0x17, 0x0, 0x0}},
    [12] = {{0xD4A51000, 0xE8, 0x0, 0x0}},
    [13] = {{0x4E72A000, 0x918, 0x0, 0x0}},
    [14] = {{0x107A4000, 0x5AF3, 0x0, 0x0}},
    [15] = {{0xA4C68000, 0x38D7E, 0x0, 0x0}},
    [16] = {{0x6FC10000, 0x2386F2, 0x0, 0x0}},
    [17] = {{0x5D8A0000, 0x1634578, 0x0, 0x0}},
    [18] = {{0xA7640000, 0xDE0B6B3, 0x0, 0x0}},
    [19] = {{0x89E80000, 0x8AC72304, 0x0, 0x0}},
    [20] = {{0x63100000, 0x6BC75E2D, 0x5, 0x0}},
    [21] = {{0xDEA00000, 0x35C9ADC5, 0x36, 0x0}},
    [22] = {{0xB2400000, 0x19E0C9BA, 0x21E, 0x0}},
    [23] = {{0xF6800000, 0x2C7E14A, 0x152D, 0x0}},
    [24] = {{0xA1000000, 0x1BCECCED, 0xD3C2, 0x0}},
    [25] = {{0x4A000000, 0x16140148, 0x84595, 0x0}},
    [26] = {{0xE4000000, 0xDCC80CD2, 0x52B7D2, 0x0}},
    [27] = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x0}},
    [28] = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}},
};

#endif