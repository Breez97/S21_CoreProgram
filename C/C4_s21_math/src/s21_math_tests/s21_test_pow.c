#include "s21_tests.h"

START_TEST(test_pow_base_positive_exponent_positive) {
  double base = 51.23;
  double exponent = 3.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_pow_base_positive_exponent_negative) {
  double base = 2.0;
  double exponent = -3.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}

START_TEST(test_pow_base_negative_exponent_positive_even) {
  double base = -2.0;
  double exponent = 4.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_pow_base_negative_exponent_positive_odd) {
  double base = -2.0;
  double exponent = 3.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_pow_base_zero_exponent_positive) {
  double base = 0.0;
  double exponent = 5.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_pow_base_zero_exponent_negative) {
  double base = 0.0;
  double exponent = -5.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert(result == expected);
}
END_TEST

// Тестирование на краевых случаях:

START_TEST(test_pow_zero_base_zero_exponent) {
  double base = 0.0;
  double exponent = 0.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_pow_negative_base_fractional_exponent) {
  double base = -5.0;
  double exponent = 2.5;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_pow_zero_base_negative_even_exponent) {
  double base = 0.0;
  double exponent = -2.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert(result == expected);
}
END_TEST

START_TEST(test_pow_zero_base_positive_even_exponent) {
  double base = 0.0;
  double exponent = 2.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_pow_negative_one_base_positive_inf_exponent) {
  double base = -1.0;
  double exponent = S21_INF_PLUS;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_pow_negative_one_base_negative_inf_exponent) {
  double base = -1.0;
  double exponent = S21_INF_MINUS;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_pow_base_zero_exponent) {
  double base = 25.0;
  double exponent = 0.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_pow_less_one_base_negative_inf_exponent) {
  double base = 0.5;
  double exponent = S21_INF_MINUS;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert(result == expected);
}
END_TEST

START_TEST(test_pow_more_one_base_negative_inf_exponent) {
  double base = 2.5;
  double exponent = S21_INF_MINUS;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert(result == expected);
}
END_TEST

START_TEST(test_pow_less_one_base_positive_inf_exponent) {
  double base = 0.5;
  double exponent = S21_INF_PLUS;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_pow_more_one_base_positive_inf_exponent) {
  double base = 2.5;
  double exponent = S21_INF_PLUS;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert(result == expected);
}
END_TEST

START_TEST(test_pow_negative_inf_base_negative_int_not_even_exponent) {
  double base = S21_INF_MINUS;
  double exponent = -7;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert(result == expected);
}
END_TEST

START_TEST(test_pow_negative_inf_base_negative_int_even_exponent) {
  double base = S21_INF_MINUS;
  double exponent = -8;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_pow_negative_inf_base_negative_not_int_exponent) {
  double base = S21_INF_MINUS;
  double exponent = -4.4;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_pow_negative_inf_base_positive_int_not_even_exponent) {
  double base = S21_INF_MINUS;
  double exponent = 3;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert(result == expected);
}
END_TEST

START_TEST(test_pow_negative_inf_base_positive_not_int_exponent) {
  double base = S21_INF_MINUS;
  double exponent = 4.4;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert(result == expected);
}
END_TEST

START_TEST(test_pow_negative_inf_base_positive_int_even_exponent) {
  double base = S21_INF_MINUS;
  double exponent = 6;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert(result == expected);
}
END_TEST

START_TEST(test_pow_large_base_large_exponent) {
  double base = 1.0e308;
  double exponent = 2.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert(result == expected);
}
END_TEST

START_TEST(test_pow_large_base_small_exponent) {
  double base = 1.0e308;
  double exponent = -2.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_pow_large_negative_base_small_exponent) {
  double base = -1.0e30;
  double exponent = 2.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_pow_large_negative_base_small_negative_exponent) {
  double base = -1.0e30;
  double exponent = -2.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_pow_nan_base) {
  double base = S21_NAN;
  double exponent = 2.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_pow_inf_base_positive_exponent) {
  double base = S21_INF_PLUS;
  double exponent = 3.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert(result == expected);
}
END_TEST

START_TEST(test_pow_inf_base_negative_exponent) {
  double base = S21_INF_PLUS;
  double exponent = -3.0;

  long double result = s21_pow(base, exponent);
  long double expected = pow(base, exponent);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

Suite *suite_pow() {
  Suite *suite = suite_create("s21_pow");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, test_pow_base_positive_exponent_positive);
  tcase_add_test(basicTests, test_pow_base_positive_exponent_negative);
  tcase_add_test(basicTests, test_pow_base_negative_exponent_positive_even);
  tcase_add_test(basicTests, test_pow_base_negative_exponent_positive_odd);
  tcase_add_test(basicTests, test_pow_base_zero_exponent_positive);
  tcase_add_test(basicTests, test_pow_base_zero_exponent_negative);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, test_pow_large_negative_base_small_exponent);
  tcase_add_test(edgeTests,
                 test_pow_large_negative_base_small_negative_exponent);

  tcase_add_test(edgeTests, test_pow_large_base_large_exponent);
  tcase_add_test(edgeTests, test_pow_large_base_small_exponent);
  tcase_add_test(edgeTests, test_pow_nan_base);
  tcase_add_test(edgeTests, test_pow_inf_base_positive_exponent);
  tcase_add_test(edgeTests, test_pow_inf_base_negative_exponent);

  tcase_add_test(edgeTests, test_pow_zero_base_zero_exponent);
  tcase_add_test(edgeTests, test_pow_negative_base_fractional_exponent);
  tcase_add_test(edgeTests, test_pow_zero_base_negative_even_exponent);
  tcase_add_test(edgeTests, test_pow_zero_base_positive_even_exponent);
  tcase_add_test(edgeTests, test_pow_negative_one_base_positive_inf_exponent);
  tcase_add_test(edgeTests, test_pow_negative_one_base_negative_inf_exponent);
  tcase_add_test(edgeTests, test_pow_base_zero_exponent);
  tcase_add_test(edgeTests, test_pow_less_one_base_negative_inf_exponent);
  tcase_add_test(edgeTests, test_pow_more_one_base_negative_inf_exponent);
  tcase_add_test(edgeTests, test_pow_less_one_base_positive_inf_exponent);
  tcase_add_test(edgeTests, test_pow_more_one_base_positive_inf_exponent);
  tcase_add_test(edgeTests,
                 test_pow_negative_inf_base_negative_int_not_even_exponent);
  tcase_add_test(edgeTests,
                 test_pow_negative_inf_base_negative_int_even_exponent);
  tcase_add_test(edgeTests,
                 test_pow_negative_inf_base_negative_not_int_exponent);
  tcase_add_test(edgeTests,
                 test_pow_negative_inf_base_positive_int_not_even_exponent);
  tcase_add_test(edgeTests,
                 test_pow_negative_inf_base_positive_not_int_exponent);
  tcase_add_test(edgeTests,
                 test_pow_negative_inf_base_positive_int_even_exponent);
  tcase_add_test(edgeTests,
                 test_pow_negative_inf_base_positive_not_int_exponent);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}
