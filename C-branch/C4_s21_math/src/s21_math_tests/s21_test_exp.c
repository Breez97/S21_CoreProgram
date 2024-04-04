#include "s21_tests.h"

// Тестирование на базовых случаях:

START_TEST(test_exp_positive_value) {  // Проблема с большими числами не хватает
                                       // точности, поэтому проверяю 15 цифр
  double x = 20;
  char str1[30];
  char str2[30];

  long double result = s21_exp(x);
  long double expected = exp(x);
  sprintf(str1, "%.*Lg", 15, result);
  sprintf(str2, "%.*Lg", 15, expected);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_exp_negative_value) {
  double x = -20;

  double result = s21_exp(x);
  double expected = exp(x);
  ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(test_exp_zero) {
  double x = 0.0;
  double result = s21_exp(x);
  double expected = exp(x);
  ck_assert_double_eq_tol(result, expected, 1e-10);
}
END_TEST

// Тестирование на краевых случаях:

START_TEST(test_exp_large_value) {
  double x = 9999999999.999999;
  double result = s21_exp(x);
  double expected = exp(x);
  ck_assert(IsInf(result) && IsInf(expected));
}
END_TEST

START_TEST(test_exp_small_value) {
  double x = -1000.0;
  double result = s21_exp(x);
  double expected = exp(x);
  ck_assert_double_eq_tol(result, expected, 1e-10);
}
END_TEST

START_TEST(test_nan_value) {
  double x = S21_NAN;
  double result = s21_exp(x);
  double expected = exp(x);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_inf_plus_value) {
  double x = S21_INF_PLUS;
  double result = s21_exp(x);
  double expected = exp(x);
  ck_assert(IsInf(result) && IsInf(expected));
}
END_TEST

START_TEST(test_inf_minus_value) {
  double x = S21_INF_MINUS;
  double result = s21_exp(x);
  double expected = exp(x);
  ck_assert_double_eq_tol(result, expected, 1e-10);
}
END_TEST

Suite *suite_exp() {
  Suite *suite = suite_create("s21_exp");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, test_exp_positive_value);
  tcase_add_test(basicTests, test_exp_negative_value);
  tcase_add_test(basicTests, test_exp_zero);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, test_exp_large_value);
  tcase_add_test(edgeTests, test_exp_small_value);
  tcase_add_test(edgeTests, test_nan_value);
  tcase_add_test(edgeTests, test_inf_plus_value);
  tcase_add_test(edgeTests, test_inf_minus_value);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}
