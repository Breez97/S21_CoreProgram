#include "s21_tests.h"

// Функция arctg - обратная тригонометрическая функция
// Базовые, нормальные случаи - значения x не являющиеся краевыми и входящими в
// область определения

START_TEST(test_atan_normal_basic_1) {
  long double result = s21_atan(0.5);
  long double expected = atan(0.5);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_atan_normal_basic_2) {
  long double result = s21_atan(-0.5);
  long double expected = atan(-0.5);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_atan_normal_basic_3) {
  long double result = s21_atan(1);
  long double expected = atan(1);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_atan_normal_basic_4) {
  long double result = s21_atan(-1);
  long double expected = atan(-1);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_atan_normal_basic_5) {
  long double result = s21_atan(0);
  long double expected = atan(0);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_atan_normal_basic_6) {
  long double result = s21_atan(2);
  long double expected = atan(2);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_atan_normal_basic_7) {
  long double result = s21_atan(4.32432);
  long double expected = atan(4.32432);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_atan_normal_basic_8) {
  long double result = s21_atan(0.0001);
  long double expected = atan(0.0001);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_atan_normal_basic_9) {
  long double result = s21_atan(-5.3234);
  long double expected = atan(-5.3234);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}

// Краевые тесты - передача бесконечно отрицательного или положительного числа,
// неопределенного числа Nan, большего числа

START_TEST(test_atan_edge_inf_plus_10) {
  long double result = s21_atan(S21_INF_PLUS);
  long double expected = atan(S21_INF_PLUS);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_atan_edge_inf_minus_11) {
  long double result = s21_atan(S21_INF_MINUS);
  long double expected = atan(S21_INF_MINUS);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_atan_edge_nan_12) {
  long double result = s21_atan(S21_NAN);
  long double expected = atan(S21_NAN);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_atan_large_numbers_13) {
  long double result = s21_atan(1e20);
  long double expected = atan(1e20);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_atan_large_numbers_14) {
  long double result = s21_atan(-1e20);
  long double expected = atan(-1e20);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_atan_large_numbers_15) {
  long double result = s21_atan(123432434.123456789);
  long double expected = atan(123432434.123456789);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_atan_large_numbers_16) {
  long double result = s21_atan(-123432434.123456789);
  long double expected = atan(-123432434.123456789);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_atan_large_numbers_17) {
  long double result = s21_atan(999999999999.999999999);
  long double expected = atan(999999999999.999999999);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_atan_large_numbers_18) {
  long double result = s21_atan(-999999999999.999999999);
  long double expected = atan(-999999999999.999999999);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

Suite *suite_atan() {
  Suite *suite = suite_create("s21_atan");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, test_atan_normal_basic_1);
  tcase_add_test(basicTests, test_atan_normal_basic_2);
  tcase_add_test(basicTests, test_atan_normal_basic_3);
  tcase_add_test(basicTests, test_atan_normal_basic_4);
  tcase_add_test(basicTests, test_atan_normal_basic_5);
  tcase_add_test(basicTests, test_atan_normal_basic_6);
  tcase_add_test(basicTests, test_atan_normal_basic_7);
  tcase_add_test(basicTests, test_atan_normal_basic_8);
  tcase_add_test(basicTests, test_atan_normal_basic_9);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, test_atan_edge_inf_plus_10);
  tcase_add_test(edgeTests, test_atan_edge_inf_minus_11);
  tcase_add_test(edgeTests, test_atan_edge_nan_12);
  tcase_add_test(edgeTests, test_atan_large_numbers_13);
  tcase_add_test(edgeTests, test_atan_large_numbers_14);
  tcase_add_test(edgeTests, test_atan_large_numbers_15);
  tcase_add_test(edgeTests, test_atan_large_numbers_16);
  tcase_add_test(edgeTests, test_atan_large_numbers_17);
  tcase_add_test(edgeTests, test_atan_large_numbers_18);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);
  return suite;
}