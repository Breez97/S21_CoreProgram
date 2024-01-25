#ifndef S21_MATH_H
#define S21_MATH_H

#include <float.h>
#include <stdint.h>
#include <stdio.h>

#define S21_E 2.71828182845904523536028747135266250L
#define S21_EPS 1e-6
#define S21_NAN -(0.0 / 0.0)
#define S21_INF_PLUS 1.0 / 0.0
#define S21_INF_MINUS -1.0 / 0.0
#define S21_PI 3.14159265358979323846264338327950288L
#define DB_MAX 10000000000000000L
#define S21_PI_2 1.57079632679489661923132169163975144L
#define S21_PI_4 0.785398163397448309615660845819875721L

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_pow(double base, double exp);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

int IsInt(double x);
int IsInf(double x);
int IsZero(double x);
int IsNan(double x);
int IsEven(double x);
void CountPow(double base, double exp, long double *result);

#endif
