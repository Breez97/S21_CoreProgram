#include "s21_tests.h"

START_TEST(test_fabs_positive_value) {
  double x = 42.42;

  double result = s21_fabs(x);
  double expected = fabs(x);
  ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(test_fabs_negative_value) {
  double x = -123.456;

  double result = s21_fabs(x);
  double expected = fabs(x);
  ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(test_fabs_zero) {
  double x = 0.0;

  double result = s21_fabs(x);
  double expected = fabs(x);
  ck_assert_double_eq_tol(result, expected, 1e-10);
}
END_TEST

// Тестирование на краевых случаях:

START_TEST(test_fabs_large_positive_value) {
  double x = 1.0e308;

  double result = s21_fabs(x);
  double expected = fabs(x);
  ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(test_fabs_large_negative_value) {
  double x = -1.0e308;

  double result = s21_fabs(x);
  double expected = fabs(x);
  ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(test_fabs_nan_value) {
  double x = S21_NAN;

  double result = s21_fabs(x);
  ck_assert(IsNan(result));
}
END_TEST

START_TEST(test_fabs_inf_plus_value) {
  double x = S21_INF_PLUS;

  double result = s21_fabs(x);
  ck_assert(IsInf(result));
}
END_TEST

START_TEST(test_fabs_inf_minus_value) {
  double x = S21_INF_MINUS;

  double result = s21_fabs(x);
  ck_assert(IsInf(result));
}
END_TEST

Suite *suite_fabs() {
  Suite *suite = suite_create("s21_fabs");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, test_fabs_positive_value);
  tcase_add_test(basicTests, test_fabs_negative_value);
  tcase_add_test(basicTests, test_fabs_zero);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, test_fabs_large_positive_value);
  tcase_add_test(edgeTests, test_fabs_large_negative_value);
  tcase_add_test(edgeTests, test_fabs_nan_value);
  tcase_add_test(edgeTests, test_fabs_inf_plus_value);
  tcase_add_test(edgeTests, test_fabs_inf_minus_value);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}