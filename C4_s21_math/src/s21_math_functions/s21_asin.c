#include "../s21_math.h"

long double s21_asin(double x) {
  long double result;
  if (IsNan(x) || x > 1 || x < -1) {
    result = S21_NAN;
  } else if (IsZero(x)) {
    result = 0;
  } else if (s21_fabs(x) == 1) {
    result = x > 0 ? S21_PI_2 : -S21_PI_2;
  } else {
    result = s21_atan(x / s21_sqrt(1 - s21_pow(x, 2)));
  }
  return result;
}