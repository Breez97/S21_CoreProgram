#include "s21_tests.h"

// Тестирование на базовых случаях:

START_TEST(find_char_in_normal_string) {
  char stringForTest[] = "normalString";
  char *result = s21_strchr(stringForTest, 'l');
  ck_assert_ptr_eq(result, strchr(stringForTest, 'l'));
  // Ожидаем, что s21_strchr найдет указатель на первое вхождение 'l'.
}
END_TEST

START_TEST(find_char_in_number_string) {
  char stringForTest[] = "8493584398959845";
  char *result = s21_strchr(stringForTest, '5');
  ck_assert_ptr_eq(result, strchr(stringForTest, '5'));
  // Ожидаем, что s21_strchr найдет указатель на первое вхождение '5'.
}
END_TEST

START_TEST(find_char_in_combined_string) {
  char stringForTest[] = "Give me some_water, please....";
  char *result = s21_strchr(stringForTest, '_');
  ck_assert_ptr_eq(result, strchr(stringForTest, '_'));
  // Ожидаем, что s21_strchr найдет указатель на первое вхождение '_'.
}
END_TEST

START_TEST(find_char_in_symbols_string) {
  char stringForTest[] = ".../,/,/././'[]'''/..";
  char *result = s21_strchr(stringForTest, '/');
  ck_assert_ptr_eq(result, strchr(stringForTest, '/'));
  // Ожидаем, что s21_strchr найдет указатель на первое вхождение '/'.
}
END_TEST

// Тестирование на краевых случаях:

START_TEST(find_null_char_in_string) {
  char stringForTest[] = "Hello\0World";
  char *result = s21_strchr(stringForTest, '\0');
  ck_assert_ptr_eq(result, strchr(stringForTest, '\0'));
  // Ожидаем, что s21_strchr вернет пустоту.
}
END_TEST

START_TEST(find_char_in_empty_string) {
  char stringForTest[] = "";
  char *result = s21_strchr(stringForTest, 'a');
  ck_assert_ptr_eq(result, strchr(stringForTest, 'a'));
  // Ожидаем, что s21_strchr не найдет вхождение в пустой строке и вернет NULL.
}
END_TEST

Suite *suite_strchr() {
  Suite *suite = suite_create("s21_strchr");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, find_char_in_normal_string);
  tcase_add_test(basicTests, find_char_in_number_string);
  tcase_add_test(basicTests, find_char_in_combined_string);
  tcase_add_test(basicTests, find_char_in_symbols_string);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, find_null_char_in_string);
  tcase_add_test(edgeTests, find_char_in_empty_string);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}
