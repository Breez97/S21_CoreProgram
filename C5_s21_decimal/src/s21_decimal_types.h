#ifndef S21_DECIMAL_TYPES_H
#define S21_DECIMAL_TYPES_H

#define DECIMAL_SIZE 4
#define DECIMAL_BIG_SIZE 8

#define BITS_INT 32

typedef unsigned char byte;

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

typedef union decimal_last_bit {
  int i;
  struct {
    unsigned int emptyOne : 16;
    unsigned int decimalPow : 8;
    unsigned int emptyTwo : 7;
    unsigned int sign : 1;
  } parts;
} decimal_last_bit;

#endif