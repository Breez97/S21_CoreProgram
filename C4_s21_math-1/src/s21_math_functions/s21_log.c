#include "../s21_math.h"

long double s21_log(double x) {
  long double result;
  if (x < 0) {
    result = S21_NAN;
  } else if (IsZero(x)) {
    result = S21_INF_MINUS;
  } else if (x == 1.0) {
    result = 0.0;
  } else if (x == S21_INF_PLUS) {
    result = S21_INF_PLUS;
  } else if (IsNan(x)) {
    result = S21_NAN;
  } else {
    int exPow = 0;
    result = 0;
    for (; x >= S21_E; x /= S21_E, exPow++) continue;

    for (int i = 0; i < 100; i++) {
      double compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }

    result = result + exPow;
  }
  return result;
}
