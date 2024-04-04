#include "s21_tests.h"

START_TEST(test_log_positive_value) {
  double x = 42.42;

  double result = s21_log(x);
  double expected = log(x);
  ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(test_log_negative_value) {
  double x = -123.456;

  double result = s21_log(x);
  double expected = log(x);
  ck_assert(IsNan(result) &&
            IsNan(expected));  // log отрицательного числа возвращает NaN
}
END_TEST

START_TEST(test_log_zero) {
  double x = 0.0;

  double result = s21_log(x);
  double expected = log(x);
  ck_assert(result ==
            expected);  // log(0) возвращает отрицательную бесконечность
}
END_TEST

// Тестирование на краевых случаях:

START_TEST(test_log_large_positive_value) {
  double x = 1.0e308;

  double result = s21_log(x);
  double expected = log(x);
  ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(test_log_large_negative_value) {
  double x = -1.0e308;

  double result = s21_log(x);
  double expected = log(x);
  ck_assert(IsNan(result) &&
            IsNan(expected));  // log отрицательного числа возвращает NaN
}
END_TEST

START_TEST(test_log_nan_value) {
  double x = S21_NAN;

  double result = s21_log(x);
  double expected = log(x);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_log_inf_plus_value) {
  double x = S21_INF_PLUS;

  double result = s21_log(x);
  double expected = log(x);
  ck_assert(
      result ==
      expected);  // log(бесконечность) возвращает положительную бесконечность
}
END_TEST

START_TEST(test_log_inf_minus_value) {
  double x = S21_INF_MINUS;

  double result = s21_log(x);
  double expected = log(x);
  ck_assert(IsNan(result) &&
            IsNan(expected));  // log(минус бесконечность) возвращает NaN
}
END_TEST

START_TEST(test_log_one_value) {
  double x = 1.0;

  double result = s21_log(x);
  double expected = log(x);
  ck_assert_double_eq_tol(result, expected,
                          1e-6);  // log(минус бесконечность) возвращает NaN
}
END_TEST

Suite *suite_log() {
  Suite *suite = suite_create("s21_log");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, test_log_positive_value);
  tcase_add_test(basicTests, test_log_negative_value);
  tcase_add_test(basicTests, test_log_zero);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, test_log_large_positive_value);
  tcase_add_test(edgeTests, test_log_large_negative_value);
  tcase_add_test(edgeTests, test_log_nan_value);
  tcase_add_test(edgeTests, test_log_inf_plus_value);
  tcase_add_test(edgeTests, test_log_inf_minus_value);
  tcase_add_test(edgeTests, test_log_one_value);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}
