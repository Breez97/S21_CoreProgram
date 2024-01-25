#include "s21_tests.h"

// Тестирование на базовых случаях:

START_TEST(test_abs_negative_value) {
  int result = s21_abs(-1);
  int expected = abs(-1);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_abs_positive_value) {
  int result = s21_abs(1);
  int expected = abs(1);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_abs_zero_value) {
  int result = s21_abs(0);
  int expected = abs(0);
  ck_assert_int_eq(result, expected);
}
END_TEST

Suite *suite_abs() {
  Suite *suite = suite_create("s21_abs");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, test_abs_negative_value);
  tcase_add_test(basicTests, test_abs_positive_value);
  tcase_add_test(basicTests, test_abs_zero_value);

  suite_add_tcase(suite, basicTests);

  return suite;
}
