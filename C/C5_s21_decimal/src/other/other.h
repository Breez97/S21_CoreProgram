#ifndef SRC_S21_DECIMAL_OTHER_H
#define SRC_S21_DECIMAL_OTHER_H

#include "../s21_decimal.h"

#define S21_OTHER_OK 0
#define S21_OTHER_ERROR 1

int s21_negate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);

s21_decimal RoundBanking(const s21_decimal decimal,
                         const s21_decimal remainder);

#endif
