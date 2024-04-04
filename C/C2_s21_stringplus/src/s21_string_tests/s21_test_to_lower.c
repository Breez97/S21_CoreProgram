#include "s21_tests.h"

// Тестирование на базовых случаях (нормальные тесты):
// Функция переводит в нижний регистр символы при следующих примерах-
// обычная строка (все в верхнем регистре), строка с пробелами, строка с
// символами нижнего регистра

START_TEST(converting_single_line_to_lowercase) {
  char *singleUpperLine = "HELLOSCHOOL";
  char *singleLowerLine = s21_to_lower(singleUpperLine);
  char *expected = "helloschool";
  ck_assert_str_eq(singleLowerLine, expected);
  if (singleLowerLine) {
    free(singleLowerLine);
  }

  // Ожидаем, что функция переведет HELLOSCHOOL в нижний регистр
}

END_TEST

START_TEST(converting_line_with_spaces_to_lowercase) {
  char *upperLineWithSpaces =
      "          THIS IS A             TEST               ";
  char *lineWithSpaces = s21_to_lower(upperLineWithSpaces);
  char *expected = "          this is a             test               ";
  ck_assert_str_eq(lineWithSpaces, expected);
  if (lineWithSpaces) {
    free(lineWithSpaces);
  }
  // Ожидаем, что функция переведет строку с пробелами в нижний регистр
}

END_TEST

START_TEST(converting_line_with_lowercase_to_lowercase) {
  char *lineWithLowercase = "lowercase";
  char *lowerLineWithLowercase = s21_to_lower(lineWithLowercase);
  char *expected = "lowercase";
  ck_assert_str_eq(lowerLineWithLowercase, expected);
  if (lowerLineWithLowercase) {
    free(lowerLineWithLowercase);
  }
  // Ожидаем, что функция никак не повлияет на строку поскольку она уже в нижнем
  // регистре
}

END_TEST

//Тестирование на ненормальных случаях, включая краевые случаи
//Строка содержит символы, не входящие в область перевода, пустая строка, null
//символ, строка большого размера

START_TEST(converting_empty_line_to_lowercase) {
  char *emptyLine = "";
  char *lowerEmptyLine = s21_to_lower(emptyLine);
  char *expected = "";
  ck_assert_str_eq(lowerEmptyLine, expected);
  if (lowerEmptyLine) {
    free(lowerEmptyLine);
  }
  // Ожидаем, что функция корректно обработает пустую строку и вернет её же
}

END_TEST

START_TEST(converting_spaces_line_to_lowercase) {
  char *emptyLine = "               ";
  char *lowerEmptyLine = s21_to_lower(emptyLine);
  char *expected = "               ";
  ck_assert_str_eq(lowerEmptyLine, expected);
  if (lowerEmptyLine) {
    free(lowerEmptyLine);
  }
  // Ожидаем, что функция корректно обработает строку с пробелами и вернёт её же
}

END_TEST

START_TEST(converting_line_with_numbers_to_lowercase) {
  char *lineWithNumbers = "TEST123";
  char *lowerLineWithNumbers = s21_to_lower(lineWithNumbers);
  char *expected = "test123";
  ck_assert_str_eq(lowerLineWithNumbers, expected);
  if (lowerLineWithNumbers) {
    free(lowerLineWithNumbers);
  }
  // Ожидаем, что функция переведет строку с цифрами в нижний регистр корректно
}

END_TEST

START_TEST(converting_line_with_different_symbols_to_lowercase) {
  char *lineWithSymbols =
      "TEST123 %?()№;:?)!! +++ HELLO WOLRLD ___ --- *** 938248";
  char *lowerLineWithSymbols = s21_to_lower(lineWithSymbols);
  char *expected = "test123 %?()№;:?)!! +++ hello wolrld ___ --- *** 938248";
  ck_assert_str_eq(lowerLineWithSymbols, expected);
  if (lowerLineWithSymbols) {
    free(lowerLineWithSymbols);
  }
  // Ожидаем, что функция переведет строку с разными символами в нижний регистр
  // (лежащие в ACSCII диапазоне)
}

END_TEST

START_TEST(converting_string_with_null_character_to_lowercase) {
  char stringWithNull[] = "Test\0ing";
  char *lowerStringWithNull = s21_to_lower(stringWithNull);
  char *expected = "test";
  ck_assert_mem_eq(expected, lowerStringWithNull, s21_strlen(expected));
  if (lowerStringWithNull) {
    free(lowerStringWithNull);
  }
  // Ожидаем, что функция вернет test поскольку выделит память до null символа,
  // после чего обработают только начальную часть
}

END_TEST

START_TEST(converting_large_string_to_lowercase) {
  char largeString[10000], expected[10000];
  for (int i = 0; i < 9999; ++i) {
    largeString[i] = 'A';
    expected[i] = 'a';
  }
  largeString[9999] = '\0', expected[9999] = '\0';
  char *lowerLargeString = s21_to_lower(largeString);
  ck_assert_str_eq(lowerLargeString, expected);
  if (lowerLargeString) {
    free(lowerLargeString);
  }
  // Ожидаем, что функция корректно переведет в нижний регистр, поскольку размер
  // для переводна unsigned long
}

END_TEST

Suite *suite_to_lower() {
  Suite *suite = suite_create("s21_to_lower");

  TCase *normalTests = tcase_create("Normal Tests");
  tcase_add_test(normalTests, converting_single_line_to_lowercase);
  tcase_add_test(normalTests, converting_line_with_spaces_to_lowercase);
  tcase_add_test(normalTests, converting_line_with_lowercase_to_lowercase);

  TCase *abnormalTests = tcase_create("Abnormal Tests");
  tcase_add_test(abnormalTests, converting_empty_line_to_lowercase);
  tcase_add_test(abnormalTests, converting_spaces_line_to_lowercase);
  tcase_add_test(abnormalTests, converting_line_with_numbers_to_lowercase);
  tcase_add_test(abnormalTests,
                 converting_line_with_different_symbols_to_lowercase);
  tcase_add_test(abnormalTests,
                 converting_string_with_null_character_to_lowercase);
  tcase_add_test(abnormalTests, converting_large_string_to_lowercase);

  suite_add_tcase(suite, normalTests);
  suite_add_tcase(suite, abnormalTests);

  return suite;
}
