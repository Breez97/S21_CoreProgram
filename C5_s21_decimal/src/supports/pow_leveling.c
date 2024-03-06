#include "support.h"

int PowLeveling(s21_decimal decimal1, s21_decimal decimal2,
                s21_big_decimal *bigDecimal1, s21_big_decimal *bigDecimal2) {
  int pow1 = GetPow(decimal1.bits, DECIMAL_SIZE - 1);
  int pow2 = GetPow(decimal2.bits, DECIMAL_SIZE - 1);
  int resPow = 0;

  if (pow1 > pow2) {
    *bigDecimal1 = FromDecimalToBigDecimal(decimal1);
    *bigDecimal2 = FromDecimalToBigDecimal(decimal2);
    SetPowDecimal(&bigDecimal2->bits[7], 0);
    *bigDecimal2 = s21_big_decimal_multiply(
        *bigDecimal2, FromDecimalToBigDecimal(GetTenToPow(pow1 - pow2)));
    SetPowDecimal(&bigDecimal2->bits[7],
                  pow1);  // Установка порядка в соответствии с новым порядком
    resPow = pow1;
  } else if (pow2 > pow1) {
    *bigDecimal2 = FromDecimalToBigDecimal(decimal2);
    *bigDecimal1 = FromDecimalToBigDecimal(decimal1);
    SetPowDecimal(&bigDecimal1->bits[7], 0);
    *bigDecimal1 = s21_big_decimal_multiply(
        *bigDecimal1, FromDecimalToBigDecimal(GetTenToPow(pow2 - pow1)));
    SetPowDecimal(&bigDecimal1->bits[7],
                  pow2);  // Установка порядка в соответствии с новым порядком
    resPow = pow2;
  } else {
    *bigDecimal1 = FromDecimalToBigDecimal(decimal1);
    *bigDecimal2 = FromDecimalToBigDecimal(decimal2);
    resPow = pow1;  // или pow2, так как они равны
  }

  return resPow;
}
