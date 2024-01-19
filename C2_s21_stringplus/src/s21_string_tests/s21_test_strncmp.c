#include "s21_tests.h"

// Тестирование на базовых случаях:

START_TEST(compare_equal_strings) {
  char string1[] = "Hello, World!";
  char string2[] = "Hello, World!";
  int result = s21_strncmp(string1, string2, 13);
  ck_assert_int_eq(result, strncmp(string1, string2, 13));
  // Ожидаем, что s21_strncmp вернет 0, так как строки полностью равны.
}
END_TEST

START_TEST(compare_strings_with_numeric_difference) {
  char string1[] = "Version 2.0";
  char string2[] = "Version 10.0";
  int result = s21_strncmp(string1, string2, 9);
  ck_assert_int_eq(result, strncmp(string1, string2, 9));
  // Ожидаем, что s21_strncmp вернет 1, так как "2" < "10".
}
END_TEST

START_TEST(compare_strings_with_case_sensitive_difference) {
  char string1[] = "OpenAI";
  char string2[] = "openai";
  int result = s21_strncmp(string1, string2, 6);
  ck_assert_int_eq(result, strncmp(string1, string2, 6));
  // Ожидаем, что s21_strncmp вернет ненулевое значение из-за различия в
  // регистре.
}
END_TEST

START_TEST(compare_strings_different_case) {
  char string1[] = "CaseSensitive";
  char string2[] = "casesensitive";
  int result = s21_strncmp(string1, string2, 14);
  ck_assert_int_eq(result, strncmp(string1, string2, 14));
  // Ожидаем, что s21_strncmp_ignore_case вернет 0, так как строки равны без
  // учета регистра.
}
END_TEST

// Тестирование на краевых случаях:

START_TEST(compare_empty_strings) {
  char string1[] = "";
  char string2[] = "";
  int result = s21_strncmp(string1, string2, 0);
  ck_assert_int_eq(result, strncmp(string1, string2, 0));
  // Ожидаем, что s21_strncmp вернет 0, так как строки пусты.
}
END_TEST

START_TEST(compare_strings_with_null_char) {
  char string1[] = "Hello\0World";
  char string2[] = "Hello\0OpenAI";
  int result = s21_strncmp(string1, string2, 12);
  ck_assert_int_eq(result, strncmp(string1, string2, 12));
  // Ожидаем, что s21_strncmp вернет 0, так как сравнение до '\0'.
}
END_TEST

Suite *suite_strncmp() {
  Suite *suite = suite_create("s21_strncmp");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, compare_equal_strings);
  tcase_add_test(basicTests, compare_strings_with_numeric_difference);
  tcase_add_test(basicTests, compare_strings_with_case_sensitive_difference);
  tcase_add_test(basicTests, compare_strings_different_case);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, compare_empty_strings);
  tcase_add_test(edgeTests, compare_strings_with_null_char);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}
