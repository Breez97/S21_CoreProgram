#ifndef SRC_S21_DECIMAL_CONVERSION_H
#define SRC_S21_DECIMAL_CONVERSION_H

#include "../s21_decimal.h"

#define S21_CONVERSION_OK 0
#define S21_CONVERSION_ERROR 1

#define S21_MIN_FLOAT \
  0.0000000000000000000000000001000000003171076850971051347135264753814751475646110945305622408341150731
#define S21_MAX_FLOAT 79228162514264337593543950335.0f

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

s21_decimal GetDecimalOfMinMaxInt(const byte flagMinMax);
void ConversionWithoutFloatingPart(const s21_decimal withoutFloatingPart,
                                   int *dst, byte *code);
int GetExpAndBringToInt(float src, s21_decimal *result);

#endif