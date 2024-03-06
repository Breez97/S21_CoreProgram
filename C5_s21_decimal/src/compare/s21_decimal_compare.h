#ifndef SRC_S21_DECIMAL_COMPARE_H
#define SRC_S21_DECIMAL_COMPARE_H

#include <string.h>

#include "../arithmetic/arithmetic.h"
#include "../s21_decimal_types.h"
#include "../supports/support.h"

#define S21_COMPARE_OK 0
#define S21_COMPARE_ERROR 1
// Основные функции, обязательные для реализации

int s21_is_less(s21_decimal decimal1, s21_decimal decimal2);
int s21_is_less_or_equal(s21_decimal decimal1, s21_decimal decimal2);
int s21_is_greater(s21_decimal decimal1, s21_decimal decimal2);
int s21_is_greater_or_equal(s21_decimal decimal1, s21_decimal decimal2);
int s21_is_equal(s21_decimal decimal1, s21_decimal decimal2);
int s21_is_not_equal(s21_decimal decimal1, s21_decimal decimal2);

// Сопутствующие, вспомогательные функции для compare
byte IsEqualBigDecimal(const s21_big_decimal decimal1,
                       const s21_big_decimal decimal2);
char UnsignedNotPowCompare(const unsigned int *decimal1,
                           const unsigned int *decimal2, const byte size);
char IsLessCompareWithLeveling(const s21_decimal decimal1,
                               const s21_decimal decimal2);

#endif