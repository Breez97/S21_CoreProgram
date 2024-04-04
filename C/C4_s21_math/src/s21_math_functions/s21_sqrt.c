#include "../s21_math.h"

long double s21_sqrt(double x) { return (x < 0) ? S21_NAN : s21_pow(x, 0.5); }
