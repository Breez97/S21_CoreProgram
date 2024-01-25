#include "s21_tests.h"

// Функция tan - тригонометрическая функция
// Базовые, нормальные случаи

START_TEST(test_tan_basic_1) {
  double number = 0;
  long double result = s21_tan(number);
  long double expected = tan(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_tan_basic_2) {
  double number = 345342;
  long double result = s21_tan(number);
  long double expected = tan(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_tan_basic_3) {
  double number = -48657;
  long double result = s21_tan(number);
  long double expected = tan(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_tan_basic_4) {
  double number = 7463.13271;
  long double result = s21_tan(number);
  long double expected = tan(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_tan_basic_5) {
  double number = -45896.1956;
  long double result = s21_tan(number);
  long double expected = tan(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_tan_basic_6) {
  double number = 0.000001;
  long double result = s21_tan(number);
  long double expected = tan(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_tan_basic_7) {
  double number = S21_PI;
  long double result = s21_tan(number);
  long double expected = tan(number);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

// Краевые тесты - передача бесконечно отрицательного или бесконечно
// положительного числа, неопределенного числа Nan

START_TEST(test_tan_edge_nan) {
  double number = S21_NAN;
  long double result = s21_tan(number);
  long double expected = tan(number);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_tan_edge_inf_plus) {
  double number = S21_INF_PLUS;
  long double result = s21_tan(number);
  long double expected = tan(number);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_tan_edge_inf_minus) {
  double number = S21_INF_MINUS;
  long double result = s21_tan(number);
  long double expected = tan(number);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

Suite *suite_tan() {
  Suite *suite = suite_create("s21_tan");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, test_tan_basic_1);
  tcase_add_test(basicTests, test_tan_basic_2);
  tcase_add_test(basicTests, test_tan_basic_3);
  tcase_add_test(basicTests, test_tan_basic_4);
  tcase_add_test(basicTests, test_tan_basic_5);
  tcase_add_test(basicTests, test_tan_basic_6);
  tcase_add_test(basicTests, test_tan_basic_7);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, test_tan_edge_nan);
  tcase_add_test(edgeTests, test_tan_edge_inf_plus);
  tcase_add_test(edgeTests, test_tan_edge_inf_minus);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}