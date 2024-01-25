#include "../s21_math.h"

long double s21_fabs(double x) {
  long double result;
  if (IsZero(x)) {
    result = 0.0;
  }

  else if (IsInf(x)) {
    result = S21_INF_PLUS;
  }

  else if (IsNan(x)) {
    result = S21_NAN;
  }

  else {
    result = (x < 0 ? -x : x);
  }

  return result;
}
