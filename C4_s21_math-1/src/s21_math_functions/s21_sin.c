#include "../s21_math.h"

long double s21_sin(double x) {
  long double result = x;
  if (IsInf(x)) {
    result = -S21_NAN;
  } else {
    while (x < -S21_PI || x > S21_PI) {
      long double convert = 2 * S21_PI;
      x += (x < -S21_PI) ? convert : -convert;
    }
    result = x;
    long double step = x;
    long int n = 3;
    while (s21_fabs(step) > 1e-10) {
      step *= (-1 * x * x / ((n - 1) * n));
      result += step;
      n += 2;
    }
  }
  return result;
}