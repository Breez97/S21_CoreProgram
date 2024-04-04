#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = base;
  if (IsNan(base) || IsNan(exp) ||
      (!IsInf(base) && base < 0 && !IsInf(exp) && !IsInt(exp))) {
    result = S21_NAN;
  } else if (IsZero(base) && IsZero(exp)) {
    result = 1.0;
  } else if (IsZero(base) && exp < 0.0) {
    result = (IsInt(exp) && !IsEven(exp)) ? (-exp) / base : S21_INF_PLUS;
  } else if (IsZero(base) && exp > 0.0) {
    result = (IsInt(exp) && !IsEven(exp)) ? base : s21_fabs(base);
  } else if ((IsInf(exp) && base == -1) || base == 1 || IsZero(exp)) {
    result = 1;
  } else if (exp == S21_INF_MINUS && !IsNan(base) && !IsInf(base)) {
    result = (s21_fabs(base) < 1) ? S21_INF_PLUS : 0.0;
  } else if (exp == S21_INF_PLUS && !IsNan(base) && !IsInf(base)) {
    result = (s21_fabs(base) < 1) ? 0.0 : S21_INF_PLUS;
  } else if (base == S21_INF_MINUS && IsInt(exp) && exp < 0.0) {
    result = (!IsEven(exp)) ? -0.0 : 0.0;
  } else if (base == S21_INF_MINUS && !IsInt(exp) && exp < 0.0) {
    result = 0.0;
  } else if (base == S21_INF_MINUS && IsInt(exp) && exp > 0.0 && IsEven(exp)) {
    result = S21_INF_PLUS;
  } else if ((base == S21_INF_PLUS && exp < 0.0) ||
             (base > DB_MAX && exp < 0.0)) {
    result = 0.0;
  } else if (base == S21_INF_MINUS && IsInt(exp) && exp > 0.0 && !IsEven(exp)) {
    result = S21_INF_MINUS;
  } else if (base == S21_INF_PLUS && exp > 0.0) {
    result = S21_INF_PLUS;
  } else {
    CountPow(base, exp, &result);
  }
  if (result >= DBL_MAX) {
    result = S21_INF_PLUS;
  } else if (result <= -DBL_MAX) {
    result = S21_INF_MINUS;
  }
  return result;
}

void CountPow(double base, double exp, long double *result) {
  if ((long int)exp == exp) {
    if (exp > 0) {
      *result = base;
      for (long int i = 0; i < (long int)exp - 1; i++) {
        (*result) *= base;
      }
    } else if (exp == 0) {
      *result = 1;
    } else {
      *result = 1 / base;
      for (long int i = 0; i < (long int)exp * (-1) - 1; i++) {
        (*result) /= base;
      }
    }
  } else {
    int sign = 1;
    if (base < 0.0) {
      sign = -1;
      base = -base;
    }
    *result = s21_exp(exp * s21_log(base));
    if (sign < 0 && IsInt(exp) && !IsEven(exp)) {
      (*result) *= sign;
    }
  }
}