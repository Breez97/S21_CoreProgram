#include "s21_tests.h"

// Функция fmod - возвращает остаток операции от деления числа с плавающей
// точкой Базовые, нормальные случаи

START_TEST(test_fmod_basic_1) {
  long double x = 7.3;
  long double y = 2.9;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_fmod_basic_2) {
  long double x = 12312.3453;
  long double y = 32.234657;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_fmod_basic_3) {
  long double x = 123;
  long double y = 5694.32;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_fmod_basic_4) {
  long double x = -24.3212;
  long double y = 459.221;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_fmod_basic_5) {
  long double x = 2932.212;
  long double y = -54;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_fmod_basic_6) {
  long double x = 9374;
  long double y = 453;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_fmod_basic_7) {
  long double x = -834304.2123;
  long double y = -4.23212;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_fmod_basic_8) {
  long double x = 0.000;
  long double y = 213.1233;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

// Краевые тесты - передача бесконечно отрицательного или положительного числа,
// неопределенного числа Nan, большего числа

START_TEST(test_fmod_edge_zero) {
  long double x = 32842.123;
  long double y = 0;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert(IsNan(result) && IsNan(expected));
}

START_TEST(test_fmod_edge_nan_x) {
  long double x = S21_NAN;
  long double y = 123.476;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert(IsNan(result) && IsNan(expected));
}

START_TEST(test_fmod_edge_nan_y) {
  long double x = 324.123356;
  long double y = S21_NAN;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert(IsNan(result) && IsNan(expected));
}

START_TEST(test_fmod_edge_nan_x_y) {
  long double x = S21_NAN;
  long double y = S21_NAN;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert(IsNan(result) && IsNan(expected));
}

START_TEST(test_fmod_edge_inf_plus) {
  long double x = S21_INF_PLUS;
  long double y = 6532.21;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert(IsNan(result) && IsNan(expected));
}

START_TEST(test_fmod_edge_inf_minus) {
  long double x = S21_INF_MINUS;
  long double y = 34534.12;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert(IsNan(result) && IsNan(expected));
}

START_TEST(test_fmod_edge_inf_minus_nan_y) {
  long double x = S21_INF_MINUS;
  long double y = S21_NAN;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert(IsNan(result) && IsNan(expected));
}

START_TEST(test_fmod_edge_inf_plus_y_zero) {
  long double x = S21_INF_PLUS;
  long double y = 0;
  long double result = s21_fmod(x, y);
  long double expected = fmod(x, y);
  ck_assert(IsNan(result) && IsNan(expected));
}

Suite *suite_fmod() {
  Suite *suite = suite_create("s21_fmod");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, test_fmod_basic_1);
  tcase_add_test(basicTests, test_fmod_basic_2);
  tcase_add_test(basicTests, test_fmod_basic_3);
  tcase_add_test(basicTests, test_fmod_basic_4);
  tcase_add_test(basicTests, test_fmod_basic_5);
  tcase_add_test(basicTests, test_fmod_basic_6);
  tcase_add_test(basicTests, test_fmod_basic_7);
  tcase_add_test(basicTests, test_fmod_basic_8);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, test_fmod_edge_zero);
  tcase_add_test(edgeTests, test_fmod_edge_nan_x);
  tcase_add_test(edgeTests, test_fmod_edge_nan_y);
  tcase_add_test(edgeTests, test_fmod_edge_nan_x_y);
  tcase_add_test(edgeTests, test_fmod_edge_inf_plus);
  tcase_add_test(edgeTests, test_fmod_edge_inf_minus);
  tcase_add_test(edgeTests, test_fmod_edge_inf_minus_nan_y);
  tcase_add_test(edgeTests, test_fmod_edge_inf_plus_y_zero);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}