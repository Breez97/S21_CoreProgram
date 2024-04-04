#include "s21_tests.h"

// Базовые, нормальные случаи

START_TEST(test_asin_basic_1) {
  long double x = 0.000001;
  long double result = s21_asin(x);
  long double expected = asin(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_asin_basic_2) {
  long double x = -0.010101;
  long double result = s21_asin(x);
  long double expected = asin(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_asin_basic_3) {
  long double x = 1;
  long double result = s21_asin(x);
  long double expected = asin(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_asin_basic_4) {
  long double x = 0;
  long double result = s21_asin(x);
  long double expected = asin(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

START_TEST(test_asin_basic_5) {
  long double x = 0.774216;
  long double result = s21_asin(x);
  long double expected = asin(x);
  ck_assert_double_eq_tol(result, expected, S21_EPS);
}
END_TEST

//краевые случаи - not[-1; 1], isNan

START_TEST(test_asin_edge_leftEdge1) {
  long double x = -1.000001;
  long double result = s21_asin(x);
  long double expected = asin(x);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_asin_edge_leftEdge2) {
  long double x = -123.34354;
  long double result = s21_asin(x);
  long double expected = asin(x);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_asin_edge_leftEdge3) {
  long double x = S21_INF_MINUS;
  long double result = s21_asin(x);
  long double expected = asin(x);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_asin_edge_rightEdge1) {
  long double x = 1.000001;
  long double result = s21_asin(x);
  long double expected = asin(x);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_asin_edge_rightEdge2) {
  long double x = 123.34354;
  long double result = s21_asin(x);
  long double expected = asin(x);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_asin_edge_rightEdge3) {
  long double x = S21_INF_PLUS;
  long double result = s21_asin(x);
  long double expected = asin(x);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

START_TEST(test_asin_edge_NaN) {
  long double x = S21_INF_PLUS;
  long double result = s21_asin(x);
  long double expected = asin(x);
  ck_assert(IsNan(result) && IsNan(expected));
}
END_TEST

Suite *suite_asin() {
  Suite *suite = suite_create("s21_asin");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, test_asin_basic_1);
  tcase_add_test(basicTests, test_asin_basic_2);
  tcase_add_test(basicTests, test_asin_basic_3);
  tcase_add_test(basicTests, test_asin_basic_4);
  tcase_add_test(basicTests, test_asin_basic_5);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, test_asin_edge_leftEdge1);
  tcase_add_test(edgeTests, test_asin_edge_leftEdge2);
  tcase_add_test(edgeTests, test_asin_edge_leftEdge3);
  tcase_add_test(edgeTests, test_asin_edge_rightEdge1);
  tcase_add_test(edgeTests, test_asin_edge_rightEdge2);
  tcase_add_test(edgeTests, test_asin_edge_rightEdge3);
  tcase_add_test(edgeTests, test_asin_edge_NaN);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}