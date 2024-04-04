#include "s21_tests.h"

// Функция sin - тригонометрическая функция
// Базовые, нормальные случаи

START_TEST(test_sin_basic_1) {
  double number = 0;
  long double result = s21_sin(number);
  long double expected = sin(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_sin_basic_2) {
  double number = 112343;
  long double result = s21_sin(number);
  long double expected = sin(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_sin_basic_3) {
  double number = -312345;
  long double result = s21_sin(number);
  long double expected = sin(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_sin_basic_4) {
  double number = 2442.5894;
  long double result = s21_sin(number);
  long double expected = sin(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_sin_basic_5) {
  double number = -312345.32676;
  long double result = s21_sin(number);
  long double expected = sin(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_sin_basic_6) {
  double number = 0.000001;
  long double result = s21_sin(number);
  long double expected = sin(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_sin_basic_7) {
  double number = S21_PI;
  long double result = s21_sin(number);
  long double expected = sin(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

// Краевые тесты - передача бесконечно отрицательного или бесконечно
// положительного числа, неопределенного числа Nan

START_TEST(test_sin_edge_nan) {
  double number = S21_NAN;
  long double result = s21_sin(number);
  long double expected = sin(number);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_sin_edge_inf_plus) {
  double number = S21_INF_PLUS;
  long double result = s21_sin(number);
  long double expected = sin(number);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_sin_edge_inf_minus) {
  double number = S21_INF_MINUS;
  long double result = s21_sin(number);
  long double expected = sin(number);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

Suite *suite_sin() {
  Suite *suite = suite_create("s21_sin");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, test_sin_basic_1);
  tcase_add_test(basicTests, test_sin_basic_2);
  tcase_add_test(basicTests, test_sin_basic_3);
  tcase_add_test(basicTests, test_sin_basic_4);
  tcase_add_test(basicTests, test_sin_basic_5);
  tcase_add_test(basicTests, test_sin_basic_6);
  tcase_add_test(basicTests, test_sin_basic_7);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, test_sin_edge_nan);
  tcase_add_test(edgeTests, test_sin_edge_inf_plus);
  tcase_add_test(edgeTests, test_sin_edge_inf_minus);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}
