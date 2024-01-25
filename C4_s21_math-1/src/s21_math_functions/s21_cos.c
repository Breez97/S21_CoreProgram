#include "../s21_math.h"

long double s21_cos(double x) {
  long double result = x;
  if (IsInf(x)) {
    result = -S21_NAN;
  } else {
    while (x < -S21_PI || x > S21_PI) {
      long double convert = 2 * S21_PI;
      x += (x < -S21_PI) ? convert : -convert;
    }
    result = 1.0;
    long double step = 1.0;
    long int n = 2;
    while (s21_fabs(step) > 1e-10) {
      step *= (-1 * x * x / ((n - 1) * n));
      result += step;
      n += 2;
    }
  }
  return result;
}