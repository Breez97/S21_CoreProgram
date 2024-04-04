#include "s21_tests.h"

// Тестирование на базовых случаях:

// Функция принимает непустые строки и строка, по которой идет поиск содержится
// в строке, в которой идет поиск.

START_TEST(normal_strings) {
  char haystack[] = "Hello";
  char needle[] = "ll";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  // Ожидаем, что s21_strstr найдет строку, которая начинается с позиции 3.
}
END_TEST

// Функция принимает непустые строки, строка, по которой идет поиск не
// содержится в строке, в которой идет поиск.

START_TEST(null_result) {
  char haystack[] = "World";
  char needle[] = "rty";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  // Ожидаем, что s21_strstr вернет NULL.
}
END_TEST

// Функция принимает непустые строки разных регистров.

START_TEST(different_register) {
  char haystack[] = "TherE iS diFFereNt_ RegisTeR!";
  char needle[] = "diFFE";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  // Ожидаем, что s21_strstr вернет NULL.
}
END_TEST

// Функция принимает непустые строки, в строке, в которой идет поиск есть
// повтоярющиеся части.

START_TEST(repeats_in_string) {
  char haystack[] = "repeat repeat repeat repeat repeat";
  char needle[] = "eat";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  // Ожидаем, что s21_strstr найдет строку, которая начинается с позиции 4.
}
END_TEST

// Функция принимает непустые строки из одного символа.

START_TEST(one_symbol_strings) {
  char haystack[] = "3";
  char needle[] = "3";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  // Ожидаем, что s21_strstr найдет строку, которая начинается с позиции 1.
}
END_TEST

// Функция принимает непустые строки, строка, в которой идет поиск состоит из
// одного символа.

START_TEST(one_symbol_haystack) {
  char haystack[] = "_";
  char needle[] = "Hello_";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  // Ожидаем, что s21_strstr вернет NULL.
}
END_TEST

// Тестирование на краевых случаях:

// Функция принимает две пустые строки.

START_TEST(empty_strings) {
  char haystack[] = "";
  char needle[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  // Ожидаем, что s21_strstr найдет строку, которая начинается с позиции 1.
}
END_TEST

// Функция принимает пустую строку, в которой идет поиск.

START_TEST(empty_haystack_string) {
  char haystack[] = "";
  char needle[] = "vflfdlmfdv";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  // Ожидаем, что s21_strstr вернет NULL.
}
END_TEST

// Функция принимает пустую строку, по которой идет поиск.

START_TEST(empty_needle_string) {
  char haystack[] = "frtvprlpvptrvlp";
  char needle[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  // Ожидаем, что s21_strstr вернет NULL.
}
END_TEST

Suite *suite_strstr() {
  Suite *suite = suite_create("s21_strstr");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, normal_strings);
  tcase_add_test(basicTests, null_result);
  tcase_add_test(basicTests, different_register);
  tcase_add_test(basicTests, repeats_in_string);
  tcase_add_test(basicTests, one_symbol_strings);
  tcase_add_test(basicTests, one_symbol_haystack);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, empty_strings);
  tcase_add_test(edgeTests, empty_haystack_string);
  tcase_add_test(edgeTests, empty_needle_string);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}