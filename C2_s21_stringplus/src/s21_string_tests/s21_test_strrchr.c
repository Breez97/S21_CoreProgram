#include "s21_tests.h"

// Тестирование на базовых случаях:

// Функция принимает строку и символ конца строки для поиска.

START_TEST(end_of_line_symbol) {
  char stringForSearch[] = "Hello";
  int symbol = '\0';
  ck_assert_ptr_eq(s21_strrchr(stringForSearch, symbol),
                   strrchr(stringForSearch, symbol));
  // Ожидаем, что s21_strrchr найдет символ на позиции 6.
}
END_TEST

// Функция принимает пустую строку и символ конца строки для поиска.

START_TEST(end_of_line_symbol_empty_string) {
  char stringForSearch[] = "";
  int symbol = '\0';
  ck_assert_ptr_eq(s21_strrchr(stringForSearch, symbol),
                   strrchr(stringForSearch, symbol));
  // Ожидаем, что s21_strrchr найдет символ на позиции 1.
}
END_TEST

// Функция принимает строку и символ для поиска.

START_TEST(search_normal_symbol) {
  char stringForSearch[] = "world";
  int symbol = 'r';
  ck_assert_ptr_eq(s21_strrchr(stringForSearch, symbol),
                   strrchr(stringForSearch, symbol));
  // Ожидаем, что s21_strrchr найдет символ на позиции 3.
}
END_TEST

// Функция принимает строку и символ для поиска.

START_TEST(search_normal_symbol_at_the_end) {
  char stringForSearch[] = "HellO";
  int symbol = 'O';
  ck_assert_ptr_eq(s21_strrchr(stringForSearch, symbol),
                   strrchr(stringForSearch, symbol));
  // Ожидаем, что s21_strrchr найдет символ на позиции 5.
}
END_TEST

// Функция принимает строку из одинаковых символов, кроме последнего и символ
// для поиска.

START_TEST(search_normal_symbol_in_similar_string) {
  char stringForSearch[] = "ooooooOooooO";
  int symbol = 'o';
  ck_assert_ptr_eq(s21_strrchr(stringForSearch, symbol),
                   strrchr(stringForSearch, symbol));
  // Ожидаем, что s21_strrchr найдет символ на позиции 11.
}
END_TEST

// Функция принимает строку и численный символ для поиска.

START_TEST(search_number_symbol) {
  char stringForSearch[] = "0123456789";
  int symbol = '7';
  ck_assert_ptr_eq(s21_strrchr(stringForSearch, symbol),
                   strrchr(stringForSearch, symbol));
  // Ожидаем, что s21_strrchr найдет символ на позиции 8.
}
END_TEST

// Тестирование на краевых значениях (возврат 0-го указателя):

// Функция принимает пустую строку и символ для поиска.

START_TEST(empty_string) {
  char stringForSearch[] = "";
  int symbol = 'a';
  ck_assert_ptr_eq(s21_strrchr(stringForSearch, symbol),
                   strrchr(stringForSearch, symbol));
  // Ожидаем, что s21_strrchr вернет NULL.
}
END_TEST

// Функция принимает строку и символ для поиска, который отличается регистром.

START_TEST(search_different_register_string_symbol) {
  char stringForSearch[] = "WoRlD";
  int symbol = 'r';
  ck_assert_ptr_eq(s21_strrchr(stringForSearch, symbol),
                   strrchr(stringForSearch, symbol));
  // Ожидаем, что s21_strrchr вернет NULL.
}
END_TEST

// Функция принимает строку и символ для поиска, которого нет в строке.

START_TEST(no_symbol_in_string) {
  char stringForSearch[] = "thank you";
  int symbol = 'w';
  ck_assert_ptr_eq(s21_strrchr(stringForSearch, symbol),
                   strrchr(stringForSearch, symbol));
  // Ожидаем, что s21_strrchr вернет NULL.
}
END_TEST

Suite *suite_strrchr() {
  Suite *suite = suite_create("s21_strrchr");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, end_of_line_symbol);
  tcase_add_test(basicTests, end_of_line_symbol_empty_string);
  tcase_add_test(basicTests, search_normal_symbol);
  tcase_add_test(basicTests, search_number_symbol);
  tcase_add_test(basicTests, search_normal_symbol_at_the_end);
  tcase_add_test(basicTests, search_normal_symbol_in_similar_string);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, empty_string);
  tcase_add_test(edgeTests, search_different_register_string_symbol);
  tcase_add_test(edgeTests, no_symbol_in_string);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}