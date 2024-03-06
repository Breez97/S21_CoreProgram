#ifndef S21_TESTS_MATH
#define S21_TESTS_MATH

#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "./../s21_decimal.h"

void RunAllTests();

void RunTest(Suite *test);

// Arithmetic
Suite *suite_s21_add();
Suite *suite_s21_sub();
Suite *suite_s21_mul();
Suite *suite_s21_div();

// Comparison
#define COMPARISON_FALSE 0
#define COMPARISON_TRUE 1
Suite *suite_s21_is_less();
Suite *suite_s21_is_less_or_equal();
Suite *suite_s21_is_greater();
Suite *suite_s21_is_greater_or_equal();
Suite *suite_s21_is_equal();
Suite *suite_s21_is_not_equal();

// Converters
#define CONVERSION_OK 0
#define CONVERSION_ERROR 1
Suite *suite_s21_from_int_to_decimal();
Suite *suite_s21_from_float_to_decimal();
Suite *suite_s21_from_decimal_to_int();
Suite *suite_s21_from_decimal_to_float();

// Others
#define OTHER_OK 0
#define OTHER_ERROR 1
Suite *suite_s21_floor();
Suite *suite_s21_round();
Suite *suite_s21_truncate();
Suite *suite_s21_negate();

#endif
