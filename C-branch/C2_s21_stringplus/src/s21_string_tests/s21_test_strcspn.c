#include "s21_tests.h"

// Тестирование на базовых случаях:

START_TEST(find_character_in_middle) {
  char str[] = "Hello, World!";
  char charset[] = ", ";

  s21_size_t result = s21_strcspn(str, charset);
  ck_assert_int_eq(result, strcspn(str, charset));
  // Ожидаем, что s21_strcspn найдет первое вхождение ',' или ' ' в строке.
}
END_TEST

START_TEST(find_character_at_beginning) {
  char str[] = "Hello, World!";
  char charset[] = "H";

  s21_size_t result = s21_strcspn(str, charset);
  ck_assert_int_eq(result, strcspn(str, charset));
  // Ожидаем, что s21_strcspn найдет первое вхождение 'H' в начале строки.
}
END_TEST

START_TEST(find_character_at_end) {
  char str[] = "Hello, World!";
  char charset[] = "!";

  s21_size_t result = s21_strcspn(str, charset);
  ck_assert_int_eq(result, strcspn(str, charset));
  // Ожидаем, что s21_strcspn найдет первое вхождение '!' в конце строки.
}
END_TEST

START_TEST(no_match_characters) {
  char str[] = "Hello, World!";
  char charset[] = "1234567890";

  s21_size_t result = s21_strcspn(str, charset);
  ck_assert_int_eq(result, strcspn(str, charset));
  // Ожидаем, что s21_strcspn вернет длину строки, так как нет совпадений с
  // символами в charset.
}
END_TEST

// Тестирование на краевых случаях:

START_TEST(empty_string_and_charset) {
  char str[] = "";
  char charset[] = "";

  s21_size_t result = s21_strcspn(str, charset);
  ck_assert_int_eq(result, strcspn(str, charset));
  // Ожидаем, что s21_strcspn вернет 0 для пустой строки и charset.
}
END_TEST

START_TEST(empty_string_with_charset) {
  char str[] = "";
  char charset[] = "abc";

  s21_size_t result = s21_strcspn(str, charset);
  ck_assert_int_eq(result, strcspn(str, charset));
  // Ожидаем, что s21_strcspn вернет 0 для пустой строки и непустого charset.
}
END_TEST

START_TEST(string_with_empty_charset) {
  char str[] = "Hello, World!";
  char charset[] = "";

  s21_size_t result = s21_strcspn(str, charset);
  ck_assert_int_eq(result, strcspn(str, charset));
  // Ожидаем, что s21_strcspn вернет длину строки, так как charset пуст.
}
END_TEST

Suite *suite_strcspn() {
  Suite *suite = suite_create("s21_strcspn");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, find_character_in_middle);
  tcase_add_test(basicTests, find_character_at_beginning);
  tcase_add_test(basicTests, find_character_at_end);
  tcase_add_test(basicTests, no_match_characters);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, empty_string_and_charset);
  tcase_add_test(edgeTests, empty_string_with_charset);
  tcase_add_test(edgeTests, string_with_empty_charset);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}
