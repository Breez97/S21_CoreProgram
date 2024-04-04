#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = x;
  if (IsNan(x) || IsNan(y)) {
    result = S21_NAN;
  } else if (IsInf(x) || y == 0) {
    result = -S21_NAN;
  } else {
    if (x / y > 0) {
      result = x - y * s21_floor(x / y);
    } else {
      result = x - y * s21_ceil(x / y);
    }
  }
  return result;
}