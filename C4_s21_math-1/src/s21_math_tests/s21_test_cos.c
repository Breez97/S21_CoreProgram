#include "s21_tests.h"

// Функция cos - тригонометрическая функция
// Базовые, нормальные случаи

START_TEST(test_cos_basic_1) {
  double number = 0;
  long double result = s21_cos(number);
  long double expected = cos(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_cos_basic_2) {
  double number = 462383;
  long double result = s21_cos(number);
  long double expected = cos(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_cos_basic_3) {
  double number = -347753;
  long double result = s21_cos(number);
  long double expected = cos(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_cos_basic_4) {
  double number = 34293.232113;
  long double result = s21_cos(number);
  long double expected = cos(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_cos_basic_5) {
  double number = -349340.9434598;
  long double result = s21_cos(number);
  long double expected = cos(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_cos_basic_6) {
  double number = 0.000001;
  long double result = s21_cos(number);
  long double expected = cos(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_cos_basic_7) {
  double number = S21_PI_2;
  long double result = s21_cos(number);
  long double expected = cos(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

// Краевые тесты - передача бесконечно отрицательного или бесконечно
// положительного числа, неопределенного числа Nan

START_TEST(test_cos_edge_nan) {
  double number = S21_NAN;
  long double result = s21_cos(number);
  long double expected = cos(number);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_cos_edge_inf_plus) {
  double number = S21_INF_PLUS;
  long double result = s21_cos(number);
  long double expected = cos(number);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_cos_edge_inf_minus) {
  double number = S21_INF_MINUS;
  long double result = s21_cos(number);
  long double expected = cos(number);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

Suite *suite_cos() {
  Suite *suite = suite_create("s21_cos");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, test_cos_basic_1);
  tcase_add_test(basicTests, test_cos_basic_2);
  tcase_add_test(basicTests, test_cos_basic_3);
  tcase_add_test(basicTests, test_cos_basic_4);
  tcase_add_test(basicTests, test_cos_basic_5);
  tcase_add_test(basicTests, test_cos_basic_6);
  tcase_add_test(basicTests, test_cos_basic_7);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(basicTests, test_cos_edge_nan);
  tcase_add_test(basicTests, test_cos_edge_inf_plus);
  tcase_add_test(basicTests, test_cos_edge_inf_minus);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}
