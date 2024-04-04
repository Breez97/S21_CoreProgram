#include "s21_tests.h"

// Функция floor округляет число к нижней границе
// Базовые, нормальные случаи

START_TEST(test_floor_basic_1) {
  long double x = 7.3;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_basic_2) {
  long double x = 56734892.34657;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_basic_3) {
  long double x = -7549282.23457;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_basic_4) {
  long double x = 0.000001;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_basic_5) {
  long double x = -0.000001;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_basic_6) {
  long double x = -0.901010;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_basic_7) {
  long double x = 99.999999;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_basic_8) {
  long double x = 99.090909;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_basic_9) {
  long double x = 12345678998765.;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_basic_10) {
  long double x = -23423423423.;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_basic_11) {
  long double x = -99345678998765.9;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_basic_12) {
  long double x = -99345678998765.4;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_basic_13) {
  long double x = 1e18;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_basic_14) {
  long double x = -1e+18;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_basic_15) {
  long double x = 112345.1234e+13;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_basic_16) {
  long double x = -112345.1234e+10;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

//краевые тесты - бесконечность, ноль, НаН

START_TEST(test_floor_edge_posInf) {
  long double x = S21_INF_PLUS;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert(IsInf(result) && IsInf(expected));
}
END_TEST

START_TEST(test_floor_edge_negInf) {
  long double x = S21_INF_MINUS;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert(IsInf(result) && IsInf(expected));
}
END_TEST

START_TEST(test_floor_edge_zero) {
  long double x = 0.;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_floor_edge_NaN) {
  long double x = S21_NAN;
  long double result = s21_floor(x);
  long double expected = floor(x);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

Suite *suite_floor() {
  Suite *suite = suite_create("s21_floor");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, test_floor_basic_1);
  tcase_add_test(basicTests, test_floor_basic_2);
  tcase_add_test(basicTests, test_floor_basic_3);
  tcase_add_test(basicTests, test_floor_basic_4);
  tcase_add_test(basicTests, test_floor_basic_5);
  tcase_add_test(basicTests, test_floor_basic_6);
  tcase_add_test(basicTests, test_floor_basic_7);
  tcase_add_test(basicTests, test_floor_basic_8);
  tcase_add_test(basicTests, test_floor_basic_9);
  tcase_add_test(basicTests, test_floor_basic_10);
  tcase_add_test(basicTests, test_floor_basic_11);
  tcase_add_test(basicTests, test_floor_basic_12);
  tcase_add_test(basicTests, test_floor_basic_13);
  tcase_add_test(basicTests, test_floor_basic_14);
  tcase_add_test(basicTests, test_floor_basic_15);
  tcase_add_test(basicTests, test_floor_basic_16);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, test_floor_edge_posInf);
  tcase_add_test(edgeTests, test_floor_edge_negInf);
  tcase_add_test(edgeTests, test_floor_edge_zero);
  tcase_add_test(edgeTests, test_floor_edge_NaN);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}