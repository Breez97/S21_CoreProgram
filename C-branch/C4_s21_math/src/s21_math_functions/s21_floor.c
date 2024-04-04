#include "../s21_math.h"

long double s21_floor(double x) {
  long double result = 0;

  if (IsZero(x) || IsInf(x) || IsNan(x)) {
    result = x;
  } else {
    if (x >= 0) {
      result = (long long int)x;

    } else {
      long double difference = x - (long long int)x;
      result = difference >= -1e-8 ? x : (long long int)x - 1;
    }
  }
  return result;
}
