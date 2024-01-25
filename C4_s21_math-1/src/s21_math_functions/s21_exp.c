#include "../s21_math.h"

long double s21_exp(double x) {
  long double result;
  if (IsNan(x)) {
    result = S21_NAN;
  } else if (x == S21_INF_PLUS) {
    result = S21_INF_PLUS;
  } else if (x == S21_INF_MINUS) {
    result = 0;
  } else if (IsZero(x)) {
    result = 1;
  } else {
    result = 1;
    long double addValue = 1;
    long double i = 1;
    while (s21_fabs(addValue) > 1e-15) {
      addValue *= x / i;
      i += 1;
      result += addValue;
      if (result > DBL_MAX || result < -DBL_MAX) {
        break;
      }
    }
  }
  if (result >= DBL_MAX) {
    result = S21_INF_PLUS;
  } else if (result <= -DBL_MAX) {
    result = 0.0;
  }
  return result;
}
