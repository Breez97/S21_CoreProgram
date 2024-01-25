#include "../s21_math.h"
int IsInt(double x) { return (x == (long long int)x); }

int IsInf(double x) { return (x == S21_INF_PLUS || x == S21_INF_MINUS); }

int IsZero(double x) { return (x == 0.0 || x == -0.0); }

int IsNan(double x) { return (x != x); }

int IsEven(double x) { return ((long long int)s21_fabs(x) % 2ll == 0ll); }
