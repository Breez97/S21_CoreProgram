#include "../s21_math.h"

long double s21_atan(double x) {
  long double result = 0;
  if (IsNan(x)) {
    result = S21_NAN;
  } else if (IsInf(x)) {
    result = (x > 0) ? S21_PI_2 : -S21_PI_2;
  } else if (s21_fabs(x) == 1) {
    result = (x > 0) ? S21_PI_4 : -S21_PI_4;
  } else if (IsZero(x)) {
    result = x;
  } else {
    long double upperBoundaryAbscissaAxis = S21_PI_2;
    long double downBoundaryAbscissaAxis = -S21_PI_2;
    while (upperBoundaryAbscissaAxis - downBoundaryAbscissaAxis > 1e-10) {
      long double y = s21_tan(result);
      if (y < x) {
        downBoundaryAbscissaAxis = result;
      } else {
        upperBoundaryAbscissaAxis = result;
      }
      result = (downBoundaryAbscissaAxis + upperBoundaryAbscissaAxis) / 2;
    }
  }
  return result;
}