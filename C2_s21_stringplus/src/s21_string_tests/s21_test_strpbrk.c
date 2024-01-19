#include "s21_tests.h"

// Тестирование на базовых случаях:

// Функция принимает строку, состоящую из одного символа, из которой нужно
// искать.

START_TEST(search_one_symbol) {
  char stringForSearch[] = "0123456789";
  char stringOfSymbols[] = "3";
  ck_assert_pstr_eq(s21_strpbrk(stringForSearch, stringOfSymbols),
                    strpbrk(stringForSearch, stringOfSymbols));
  // Ожидаем, что s21_strpbrk найдет символ на позиции 4.
}
END_TEST

// Функция принимает строку, состоящую из нескольких символов, из которой нужно
// искать.

START_TEST(search_multiple_symbol) {
  char stringForSearch[] = "0123456789";
  char stringOfSymbols[] = "856";
  ck_assert_pstr_eq(s21_strpbrk(stringForSearch, stringOfSymbols),
                    strpbrk(stringForSearch, stringOfSymbols));
  // Ожидаем, что s21_strpbrk найдет символ на позиции 6.
}
END_TEST

// Функция принимает строки разных регистров.

START_TEST(search_in_different_register_string) {
  char stringForSearch[] = "How are you?";
  char stringOfSymbols[] = "A hR";
  ck_assert_pstr_eq(s21_strpbrk(stringForSearch, stringOfSymbols),
                    strpbrk(stringForSearch, stringOfSymbols));
  // Ожидаем, что s21_strpbrk найдет символ на позиции 4.
}
END_TEST

// Функция ищет символ в самом начале строки.

START_TEST(search_at_the_beginning_of_the_string) {
  char stringForSearch[] = "_thANk YoU)";
  char stringOfSymbols[] = "_0vA";
  ck_assert_pstr_eq(s21_strpbrk(stringForSearch, stringOfSymbols),
                    strpbrk(stringForSearch, stringOfSymbols));
  // Ожидаем, что s21_strpbrk найдет символ на позиции 4.
}
END_TEST

// Функция принимает строку символов, содержащую только символ конца строки.

START_TEST(end_of_line_symbol_string) {
  char stringForSearch[] = "0123456789";
  char stringOfSymbols[] = "2  \0 34";
  ck_assert_pstr_eq(s21_strpbrk(stringForSearch, stringOfSymbols),
                    strpbrk(stringForSearch, stringOfSymbols));
  // Ожидаем, что s21_strpbrk найдет символ на позиции 3.
}
END_TEST

// Тестирование на краевых случаях (возврат 0-го указателя):

// Функция принимает две пустые строки: строку, в которой необходимо искать
// символы и строку, из которой берутся символы.

START_TEST(search_empty_strings) {
  char stringForSearch[] = "";
  char stringOfSymbols[] = "";
  ck_assert_pstr_eq(s21_strpbrk(stringForSearch, stringOfSymbols),
                    strpbrk(stringForSearch, stringOfSymbols));
  // Ожидаем, что s21_strpbrk вернет NULL.
}
END_TEST

// Функция принимает пустую строку, в которой необходимо искать символы.

START_TEST(search_in_empty_string) {
  char stringForSearch[] = "";
  char stringOfSymbols[] = "hello";
  ck_assert_pstr_eq(s21_strpbrk(stringForSearch, stringOfSymbols),
                    strpbrk(stringForSearch, stringOfSymbols));
  // Ожидаем, что s21_strpbrk вернет NULL.
}
END_TEST

// Функция принимает пустую строку символов, которые нужно искать.

START_TEST(empty_symbols_string) {
  char stringForSearch[] = "Hello world";
  char stringOfSymbols[] = "";
  ck_assert_pstr_eq(s21_strpbrk(stringForSearch, stringOfSymbols),
                    strpbrk(stringForSearch, stringOfSymbols));
  // Ожидаем, что s21_strpbrk вернет NULL.
}
END_TEST

// Функция принимает строку символов, содержащую символ конца строки.

START_TEST(only_end_of_line_symbol_string) {
  char stringForSearch[] = "Hello world";
  char stringOfSymbols[] = "\0";
  ck_assert_pstr_eq(s21_strpbrk(stringForSearch, stringOfSymbols),
                    strpbrk(stringForSearch, stringOfSymbols));
  // Ожидаем, что s21_strpbrk вернет NULL.
}
END_TEST

Suite *suite_strpbrk() {
  Suite *suite = suite_create("s21_strpbrk");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, search_one_symbol);
  tcase_add_test(basicTests, search_multiple_symbol);
  tcase_add_test(basicTests, search_in_different_register_string);
  tcase_add_test(basicTests, search_at_the_beginning_of_the_string);
  tcase_add_test(basicTests, end_of_line_symbol_string);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, search_empty_strings);
  tcase_add_test(edgeTests, search_in_empty_string);
  tcase_add_test(edgeTests, empty_symbols_string);
  tcase_add_test(edgeTests, only_end_of_line_symbol_string);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}