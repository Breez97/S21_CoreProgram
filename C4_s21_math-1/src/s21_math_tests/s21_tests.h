#ifndef S21_TESTS_MATH
#define S21_TESTS_MATH

#include <check.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_math.h"

void RunAllTests();

void RunTest(Suite *test);

Suite *suite_pow();
Suite *suite_sqrt();
Suite *suite_ceil();
Suite *suite_exp();
Suite *suite_log();
Suite *suite_fabs();
Suite *suite_abs();
Suite *suite_atan();
Suite *suite_sin();
Suite *suite_cos();
Suite *suite_tan();
Suite *suite_fmod();
Suite *suite_floor();
Suite *suite_acos();
Suite *suite_asin();

#endif
