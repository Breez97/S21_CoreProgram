#include "../s21_math.h"

long double s21_ceil(double x) {
  long double result;
  if (IsZero(x) || IsInf(x)) {
    result = x;
  } else if (IsNan(x)) {
    result = S21_NAN;
  } else {
    result =
        (x >= 0 ? (long long int)(x + 0.99999999999L) : (long long int)(x));
  }
  return result;
}