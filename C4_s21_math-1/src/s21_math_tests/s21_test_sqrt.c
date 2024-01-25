#include "s21_tests.h"

START_TEST(test_sqrt_base_normal_positive) {
  double base = 4.0;
  long double result = s21_sqrt(base);
  long double expected = sqrt(base);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_sqrt_base_normal_positive_not_sqrt) {
  double base = 7.0;
  long double result = s21_sqrt(base);
  long double expected = sqrt(base);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_sqrt_base_one_positive) {
  double base = 1.0;
  long double result = s21_sqrt(base);
  long double expected = sqrt(base);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_sqrt_base_one_negative) {
  double base = -1.0;
  long double result = s21_sqrt(base);
  long double expected = sqrt(base);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_sqrt_base_zero_positive) {
  double base = 0.0;
  long double result = s21_sqrt(base);
  long double expected = sqrt(base);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_sqrt_base_zero_negative) {
  double base = -0.0;
  long double result = s21_sqrt(base);
  long double expected = sqrt(base);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_sqrt_base_large_positive_not_sqrt) {
  double base = 99999999999.99999999;
  long double result = s21_sqrt(base);
  long double expected = sqrt(base);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_sqrt_base_large_positive) {
  double base = 2313441.0;
  long double result = s21_sqrt(base);
  long double expected = sqrt(base);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_sqrt_base_large_negative_not_sqrt) {
  double base = -99999999999.99999999;
  long double result = s21_sqrt(base);
  long double expected = sqrt(base);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_sqrt_base_large_negative) {
  double base = -2313441.0;
  long double result = s21_sqrt(base);
  long double expected = sqrt(base);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_sqrt_base_inf_positive) {
  double base = S21_INF_PLUS;
  long double result = s21_sqrt(base);
  long double expected = sqrt(base);
  ck_assert(result == expected);
}
END_TEST

START_TEST(test_sqrt_base_inf_negative) {
  double base = S21_INF_MINUS;
  long double result = s21_sqrt(base);
  long double expected = sqrt(base);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_sqrt_base_nan) {
  double base = S21_NAN;
  long double result = s21_sqrt(base);
  long double expected = sqrt(base);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

Suite *suite_sqrt() {
  Suite *suite = suite_create("s21_sqrt");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, test_sqrt_base_normal_positive);
  tcase_add_test(basicTests, test_sqrt_base_normal_positive_not_sqrt);
  tcase_add_test(basicTests, test_sqrt_base_one_positive);
  tcase_add_test(basicTests, test_sqrt_base_zero_positive);
  tcase_add_test(basicTests, test_sqrt_base_large_positive_not_sqrt);
  tcase_add_test(basicTests, test_sqrt_base_large_positive);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, test_sqrt_base_zero_negative);
  tcase_add_test(edgeTests, test_sqrt_base_large_negative_not_sqrt);
  tcase_add_test(edgeTests, test_sqrt_base_one_negative);
  tcase_add_test(edgeTests, test_sqrt_base_large_negative);
  tcase_add_test(edgeTests, test_sqrt_base_inf_positive);
  tcase_add_test(edgeTests, test_sqrt_base_inf_negative);
  tcase_add_test(edgeTests, test_sqrt_base_nan);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}
