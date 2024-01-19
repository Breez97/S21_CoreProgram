#include "s21_tests.h"

// Тестирование на базовых случаях (нормальные тесты):
// Функция возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src) -
// Удаление символов из начала и конца строки, удаление всех символов, обрезка
// строки, содержащей только символы для удаления.

START_TEST(trim_chars_from_start_and_end) {
  char *source = "  \tTrimming whitespace.  \t";
  char *trim_chars = " \t";
  char *resultString = s21_trim(source, trim_chars);
  char *expected = "Trimming whitespace.";

  ck_assert_str_eq(resultString, expected);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - удаление символов из начала и конца строки
}
END_TEST

START_TEST(trim_others_chars_from_start_and_end) {
  char *source = " !+1-- \tTri&*32123!!()__--space.  --1+!\t";
  char *trim_chars = " \t!1-+";
  char *resultString = s21_trim(source, trim_chars);
  char *expected = "Tri&*32123!!()__--space.";

  ck_assert_str_eq(resultString, expected);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - удаление символов из начала и конца строки
  // (при разных символах)
}
END_TEST

START_TEST(trim_empty_string) {
  char *source = "";
  char *trim_chars = " \t";
  char *resultString = s21_trim(source, trim_chars);
  char *expected = "";
  ck_assert_str_eq(resultString, expected);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - пустая строка, так как исходная строка
  // пуста
}
END_TEST

START_TEST(trim_string_with_only_trim_chars) {
  char *source = "  \t\t\t1234567890!;%:?*()_-+";
  char *trim_chars = " \t1234567890!;%:?*()_-+";
  char *resultString = s21_trim(source, trim_chars);
  char *expected = "";
  ck_assert_str_eq(resultString, expected);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - пустая строка, так как исходная строка
  // состоит только из символов для удаления
}
END_TEST

// Тестирование на ненормальных, краевых случаях:
// Исходная строка - null, символы для удаления - null, исходная строка и
// символы для удаления - null, символы для удаления - пустая строка

START_TEST(trim_null_source_string) {
  char *source = NULL;
  char *trim_chars = " \t";
  char *resultString = s21_trim(source, trim_chars);
  ck_assert_ptr_eq(resultString, S21_NULL);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - обработка null исходной строки
}
END_TEST

START_TEST(trim_null_trim_chars) {
  char *source = "   Trimming whitespace.   ";
  char *trim_chars = S21_NULL;
  char *resultString = s21_trim(source, trim_chars);
  char *expected = "Trimming whitespace.";
  ck_assert_str_eq(resultString, expected);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - обработка null символов для удаления
}
END_TEST

START_TEST(trim_null_source_and_trim_chars) {
  char *source = S21_NULL;
  char *trim_chars = S21_NULL;
  char *resultString = s21_trim(source, trim_chars);
  ck_assert_ptr_eq(resultString, S21_NULL);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - обработка null исходной строки и символов
  // для удаления
}
END_TEST

START_TEST(trim_empty_trim_chars) {
  char *source = "   Trimming whitespace.   ";
  char *trim_chars = "";
  char *resultString = s21_trim(source, trim_chars);
  char *expected = "Trimming whitespace.";

  ck_assert_str_eq(resultString, expected);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - никаких изменений, так как символов для
  // удаления нет
}
END_TEST

Suite *suite_trim() {
  Suite *suite = suite_create("s21_trim");

  TCase *normalTests = tcase_create("Normal Tests");
  tcase_add_test(normalTests, trim_chars_from_start_and_end);
  tcase_add_test(normalTests, trim_empty_string);
  tcase_add_test(normalTests, trim_string_with_only_trim_chars);
  tcase_add_test(normalTests, trim_others_chars_from_start_and_end);

  TCase *abnormalTests = tcase_create("Abnormal Tests");
  tcase_add_test(abnormalTests, trim_null_source_string);
  tcase_add_test(abnormalTests, trim_null_trim_chars);
  tcase_add_test(abnormalTests, trim_null_source_and_trim_chars);
  tcase_add_test(abnormalTests, trim_empty_trim_chars);

  suite_add_tcase(suite, normalTests);
  suite_add_tcase(suite, abnormalTests);

  return suite;
}
