#include "s21_tests.h"

// Функция ceil - кругляет дробь в большую сторону до целого
// Базовые, нормальные случаи - значения не превышающие бесконечность и
// определенные на числовой прямой

START_TEST(test_ceil_normal_basic_1) {
  long double result = s21_ceil(0.0);
  long double expected = ceil(0.0);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_ceil_normal_basic_2) {
  long double result = s21_ceil(2.5);
  long double expected = ceil(2.5);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_ceil_normal_basic_3) {
  long double result = s21_ceil(-3.8);
  long double expected = ceil(-3.8);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_ceil_normal_basic_4) {
  long double result = s21_ceil(1000000.12345);
  long double expected = ceil(1000000.12345);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_ceil_normal_basic_5) {
  long double result = s21_ceil(3.14);
  long double expected = ceil(3.14);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

// Краевые тесты - передача бесконечно отрицательного или положительного числа,
// неопределенного числа Nan, больших чисел

START_TEST(test_ceil_edge_basic_1) {
  long double result = s21_ceil(0.000001);
  long double expected = ceil(0.000001);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_ceil_edge_basic_2) {
  long double result = s21_ceil(-0.000001);
  long double expected = ceil(-0.000001);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_ceil_edge_basic_3) {
  long double result = s21_ceil(1.000001);
  long double expected = ceil(1.000001);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_ceil_edge_basic_4) {
  long double result = s21_ceil(-1.000001);
  long double expected = ceil(-1.000001);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_ceil_edge_basic_5) {
  long double result = s21_ceil(1.);
  long double expected = ceil(1.);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_ceil_edge_basic_6) {
  long double result = s21_ceil(-1.);
  long double expected = ceil(-1.);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_ceil_edge_large_neg_7) {
  long double result = s21_ceil(-2345678910.123456);
  long double expected = ceil(-2345678910.123456);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_ceil_edge_large_pos_8) {
  long double result = s21_ceil(2345678910.123456);
  long double expected = ceil(2345678910.123456);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_ceil_edge_large_extra_neg_9) {
  long double result = s21_ceil(-9999999999.999999);
  long double expected = ceil(-9999999999.999999);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_ceil_edge_large_extra_pos_10) {
  long double result = s21_ceil(9999999999.999999);
  long double expected = ceil(9999999999.999999);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_ceil_edge_inf_plus_11) {
  long double result = s21_ceil(S21_INF_PLUS);
  long double expected = ceil(S21_INF_PLUS);
  ck_assert(result == expected);
}
END_TEST

START_TEST(test_ceil_edge_inf_minus_12) {
  long double result = s21_ceil(S21_INF_MINUS);
  long double expected = ceil(S21_INF_MINUS);
  ck_assert(result == expected);
}
END_TEST

START_TEST(test_ceil_edge_nan_13) {
  long double result = s21_ceil(S21_NAN);
  long double expected = ceil(S21_NAN);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

Suite *suite_ceil() {
  Suite *suite = suite_create("s21_ceil");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, test_ceil_normal_basic_1);
  tcase_add_test(basicTests, test_ceil_normal_basic_2);
  tcase_add_test(basicTests, test_ceil_normal_basic_3);
  tcase_add_test(basicTests, test_ceil_normal_basic_4);
  tcase_add_test(basicTests, test_ceil_normal_basic_5);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, test_ceil_edge_basic_1);
  tcase_add_test(edgeTests, test_ceil_edge_basic_2);
  tcase_add_test(edgeTests, test_ceil_edge_basic_3);
  tcase_add_test(edgeTests, test_ceil_edge_basic_4);
  tcase_add_test(edgeTests, test_ceil_edge_basic_5);
  tcase_add_test(edgeTests, test_ceil_edge_basic_6);
  tcase_add_test(edgeTests, test_ceil_edge_large_neg_7);
  tcase_add_test(edgeTests, test_ceil_edge_large_pos_8);
  tcase_add_test(edgeTests, test_ceil_edge_large_extra_neg_9);
  tcase_add_test(edgeTests, test_ceil_edge_large_extra_pos_10);
  tcase_add_test(edgeTests, test_ceil_edge_inf_plus_11);
  tcase_add_test(edgeTests, test_ceil_edge_inf_minus_12);
  tcase_add_test(edgeTests, test_ceil_edge_nan_13);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);
  return suite;
}