#ifndef SRC_S21_DECIMAL_ARITHMETIC_H
#define SRC_S21_DECIMAL_ARITHMETIC_H

#include "../compare/s21_decimal_compare.h"
#include "../other/other.h"
#include "../s21_decimal.h"
#include "../supports/support.h"

#define S21_OK 0
#define S21_BIG_NUMBER_ERROR 1
#define S21_SMALL_NUMBER_ERROR 2
#define S21_ZERO_DIV_ERROR 3
#define S21_ANY_ERROR 4

// Основные функции, обязательные для реализации

int s21_add(s21_decimal decimal1, s21_decimal decimal2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Важные вспомогательные (операционные)

byte CalculationFractionalPart(s21_big_decimal *res,
                               const s21_big_decimal divisor,
                               s21_big_decimal *remainder, byte *code);
void add_numbers(unsigned int *result, const unsigned int *a,
                 const unsigned int *b, byte size);
s21_decimal s21_decimal_add(const s21_decimal a, const s21_decimal b);
s21_big_decimal s21_big_decimal_add(const s21_big_decimal a,
                                    const s21_big_decimal b);

s21_decimal s21_decimal_subtract(const s21_decimal a, const s21_decimal b);
s21_big_decimal s21_big_decimal_subtract(const s21_big_decimal a,
                                         const s21_big_decimal b);

void multiply_numbers(unsigned int *result, const unsigned int *a,
                      const unsigned int *b, byte size);
s21_decimal s21_decimal_multiply(const s21_decimal a, const s21_decimal b);
s21_big_decimal s21_big_decimal_multiply(const s21_big_decimal a,
                                         const s21_big_decimal b);

short int GetFirstPositiveBit(const unsigned int *decimal, const byte size);
void BinaryShiftLeft(unsigned int *result, const unsigned int *decimal,
                     const byte size);
void IterateBinaryShiftLeft(unsigned int *result, const unsigned int *decimal,
                            const short int shift, const byte size);
void BinaryShiftRight(unsigned int *result, const unsigned int *decimal,
                      const byte size);
void IterateBinaryShiftRight(unsigned int *result, const unsigned int *decimal,
                             const short int shift, const byte size);
s21_decimal s21_decimal_divide(const s21_decimal dividend,
                               const s21_decimal divisor,
                               s21_decimal *remainder);
s21_big_decimal s21_big_decimal_divide(const s21_big_decimal dividend,
                                       const s21_big_decimal divisor,
                                       s21_big_decimal *remainder);

// Вспомогательные функции

void CheckOperatorAddLogic(byte *code, const byte sign1, const byte sign2,
                           const s21_decimal decimal1,
                           const s21_decimal decimal2, s21_decimal *result);
void MainAddLogic(const s21_decimal decimal1, const s21_decimal decimal2,
                  s21_decimal *result, byte *code);

void CheckOperatorSubLogic(byte *code, const byte sign1, const byte sign2,
                           const s21_decimal decimal1,
                           const s21_decimal decimal2, s21_decimal *result);
void MainSubLogic(const s21_decimal decimal1, const s21_decimal decimal2,
                  s21_decimal *result, byte *code);

void CheckOperatorDivLogic(byte *code, const byte sign1, const byte sign2,
                           s21_decimal decimal1, s21_decimal decimal2,
                           s21_decimal *result);
void MainDivLogic(s21_decimal decimal1, s21_decimal decimal2,
                  s21_decimal *result, byte *code);

void CheckOperatorMulLogic(byte *code, const byte sign1, const byte sign2,
                           const s21_decimal decimal1,
                           const s21_decimal decimal2, s21_decimal *result,
                           const int resultPow);
void MainMulLogic(const s21_decimal decimal1, const s21_decimal decimal2,
                  s21_decimal *result, byte *code, const int resultPow);

#endif