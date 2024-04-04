#include "s21_tests.h"

// Тестирование на базовых случаях:
// Функция корректно определеят длину строки.

START_TEST(length_of_normal_string) {
  char stringForTest[] = "normalString";
  ck_assert_int_eq(s21_strlen(stringForTest), strlen(stringForTest));
  // Ожидаем, что s21_strlen выведет 12.
}
END_TEST

START_TEST(length_of_number_string) {
  char stringForTest[] = "8493584398959845";
  ck_assert_int_eq(s21_strlen(stringForTest), strlen(stringForTest));
  // Ожидаем, что s21_strlen выведет 16.
}
END_TEST

START_TEST(length_of_combined_string) {
  char stringForTest[] = "Give me some_water, please....";
  ck_assert_int_eq(s21_strlen(stringForTest), strlen(stringForTest));
  // Ожидаем, что s21_strlen выведет 30.
}
END_TEST

START_TEST(length_of_symbols_string) {
  char stringForTest[] = ".../,/,/././'[]'''/..";
  ck_assert_int_eq(s21_strlen(stringForTest), strlen(stringForTest));
  // Ожидаем, что s21_strlen выведет 21.
}
END_TEST

// Тестирование на краевых случаях:
// Функция принимает пустую строку.

START_TEST(length_of_empty_string) {
  char stringForTest[] = "";
  ck_assert_int_eq(s21_strlen(stringForTest), strlen(stringForTest));
  // Ожидаем, что s21_strlen выведет 0.
}
END_TEST

// Иные тесты для проверки:

START_TEST(length_of_end_in_middle_string) {
  char stringForTest[] = "Hello\0World";
  ck_assert_int_eq(s21_strlen(stringForTest), strlen(stringForTest));
  // Ожидаем, что s21_strlen выведет 5.
}
END_TEST

START_TEST(length_of_symbols_in_string) {
  char stringForTest[] = "Thank \n\tyou\t so much)000))";
  ck_assert_int_eq(s21_strlen(stringForTest), strlen(stringForTest));
  // Ожидаем, что s21_strlen выведет 26.
}
END_TEST

Suite *suite_strlen() {
  Suite *suite = suite_create("s21_strlen");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, length_of_normal_string);
  tcase_add_test(basicTests, length_of_number_string);
  tcase_add_test(basicTests, length_of_combined_string);
  tcase_add_test(basicTests, length_of_symbols_string);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, length_of_empty_string);

  TCase *otherTests = tcase_create("Other Tests");
  tcase_add_test(otherTests, length_of_end_in_middle_string);
  tcase_add_test(otherTests, length_of_symbols_in_string);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);
  suite_add_tcase(suite, otherTests);

  return suite;
}
