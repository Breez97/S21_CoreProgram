#include "s21_tests.h"

// Тестирование на базовых случаях:

START_TEST(copy_entire_source_string) {
  char source[] = "Hello, World!";
  char destination[20] = {'\0'};
  char expected[20] = {'\0'};
  strncpy(expected, source, 13);
  s21_strncpy(destination, source, 13);

  ck_assert_str_eq(destination, expected);
  // Ожидаем, что s21_strncpy скопирует всю строку, как и стандартная strncpy.
}
END_TEST

START_TEST(copy_partial_source_string) {
  char source[] = "Hello, World!";
  char destination[20];
  char expected[20];
  destination[13] = '\0';
  strncpy(expected, source, 5);
  s21_strncpy(destination, source, 5);

  ck_assert_str_eq(destination, expected);
  // Ожидаем, что s21_strncpy скопирует только часть строки, как и стандартная
  // strncpy.
}
END_TEST

START_TEST(append_null_character) {
  char source[] = "Hello, World!";
  char destination[20];

  // strncpy(expected, source, 13);

  // s21_strncpy(destination, source, 13);

  ck_assert_ptr_eq(strncpy(destination, source, 13),
                   s21_strncpy(destination, source, 13));
  // Ожидаем, что s21_strncpy добавит нулевой символ, как и стандартная strncpy.
}
END_TEST

// Тестирование на краевых случаях:

START_TEST(copy_zero_characters) {
  char source[] = "Hello, World!";
  char destination[20] = "ExistingContent";
  char expected[20] = "ExistingContent";

  s21_strncpy(destination, source, 0);

  ck_assert_str_eq(destination, expected);
  // Ожидаем, что s21_strncpy не изменит строку, так как не скопировало ни
  // одного символа.
}
END_TEST

START_TEST(copy_more_than_source_length) {
  char source[] = "Hello, World!";
  char destination[20];
  char expected[20];

  strncpy(expected, source, 20);
  s21_strncpy(destination, source, 20);

  ck_assert_str_eq(destination, expected);
  // Ожидаем, что s21_strncpy скопирует всю строку, даже если указанная длина
  // больше, чем длина исходной строки.
}
END_TEST

Suite *suite_strncpy() {
  Suite *suite = suite_create("s21_strncpy");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, copy_entire_source_string);
  tcase_add_test(basicTests, copy_partial_source_string);
  tcase_add_test(basicTests, append_null_character);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, copy_zero_characters);
  tcase_add_test(edgeTests, copy_more_than_source_length);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}
