#include "s21_tests.h"

// Тестирование на базовых случаях (нормальные тесты):
// Функция переводит в верхний регистр символы при следующих примерах-
// обычная строка (все в нижнем регистре), строка с пробелами, строка с
// символами верхнего регистра

START_TEST(converting_single_line_to_uppercase) {
  char *singleLowerLine = "helloschool";
  char *singleUpperLine = s21_to_upper(singleLowerLine);
  char *expected = "HELLOSCHOOL";
  ck_assert_str_eq(singleUpperLine, expected);
  if (singleUpperLine) {
    free(singleUpperLine);
  }
  // Ожидаем, что функция переведет helloschool в верхний регистр
}
END_TEST

START_TEST(converting_line_with_spaces_to_uppercase) {
  char *lineWithSpaces = "          this is a             test               ";
  char *upperLineWithSpaces = s21_to_upper(lineWithSpaces);
  char *expected = "          THIS IS A             TEST               ";
  ck_assert_str_eq(upperLineWithSpaces, expected);
  if (upperLineWithSpaces) {
    free(upperLineWithSpaces);
  }
  // Ожидаем, что функция переведет строку с пробелами в верхний регистр
}
END_TEST

START_TEST(converting_line_with_uppercase_to_uppercase) {
  char *lineWithUppercase = "UPPERCASE";
  char *upperLineWithUppercase = s21_to_upper(lineWithUppercase);
  char *expected = "UPPERCASE";
  ck_assert_str_eq(upperLineWithUppercase, expected);
  if (upperLineWithUppercase) {
    free(upperLineWithUppercase);
  }
  // Ожидаем, что функция оставит строку с символами верхнего регистра без
  // изменений
}
END_TEST

//Тестирование на ненормальных случаях, включая краевые случаи
//Строка содержит символы, не входящие в область перевода, пустая строка, null
//символ, строка большого размера

START_TEST(converting_empty_line_to_uppercase) {
  char *emptyLine = "";
  char *upperEmptyLine = s21_to_upper(emptyLine);
  char *expected = "";
  ck_assert_str_eq(upperEmptyLine, expected);
  if (upperEmptyLine) {
    free(upperEmptyLine);
  }
  // Ожидаем, что функция корректно обработает пустую строку
}
END_TEST

START_TEST(converting_spaces_line_to_uppercase) {
  char *emptyLine = "               ";
  char *upperEmptyLine = s21_to_upper(emptyLine);
  char *expected = "               ";
  ck_assert_str_eq(upperEmptyLine, expected);
  if (upperEmptyLine) {
    free(upperEmptyLine);
  }
  // Ожидаем, что функция корректно обработает строку пробелов
}
END_TEST

START_TEST(converting_line_with_numbers_to_uppercase) {
  char *lineWithNumbers = "test123";
  char *upperLineWithNumbers = s21_to_upper(lineWithNumbers);
  char *expected = "TEST123";
  ck_assert_str_eq(upperLineWithNumbers, expected);
  if (upperLineWithNumbers) {
    free(upperLineWithNumbers);
  }
  // Ожидаем, что функция переведет строку с цифрами в верхний регистр
}
END_TEST

START_TEST(converting_line_with_different_symbols_to_uppercase) {
  char *lineWithNumbers =
      "test123 %?()№;:?)!! +++ HELLO Wolrld ___ --- *** 938248";
  char *upperLineWithNumbers = s21_to_upper(lineWithNumbers);
  char *expected = "TEST123 %?()№;:?)!! +++ HELLO WOLRLD ___ --- *** 938248";
  ck_assert_str_eq(upperLineWithNumbers, expected);
  if (upperLineWithNumbers) {
    free(upperLineWithNumbers);
  }
  // Ожидаем, что функция переведет строку с разными символами в верхний регистр
  // (лежащие в ACSCII диапазоне)
}
END_TEST

START_TEST(converting_string_with_null_character) {
  char stringWithNull[] = "Test\0ing";
  char *upperStringWithNull = s21_to_upper(stringWithNull);
  char *expected = "TEST";
  ck_assert_mem_eq(expected, upperStringWithNull, s21_strlen(expected));
  if (upperStringWithNull) {
    free(upperStringWithNull);
  }
  // Ожидаем, что функция вернет TEST поскольку выделит память до null символа,
  // после чего обработают только начальную часть
}
END_TEST

START_TEST(converting_large_string_to_uppercase) {
  char largeString[10000], expected[10000];
  for (int i = 0; i < 9999; ++i) {
    largeString[i] = 'a';
    expected[i] = 'A';
  }
  largeString[9999] = '\0', expected[9999] = '\0';
  char *upperLargeString = s21_to_upper(largeString);
  ck_assert_str_eq(upperLargeString, expected);
  if (upperLargeString) {
    free(upperLargeString);
  }
  // Ожидаем, что функция корректно переведет в верхний регистр, поскольку
  // размер для переводна unsigned long
}
END_TEST

Suite *suite_to_upper() {
  Suite *suite = suite_create("s21_to_upper");

  TCase *normalTests = tcase_create("Normal Tests");
  tcase_add_test(normalTests, converting_single_line_to_uppercase);
  tcase_add_test(normalTests, converting_line_with_spaces_to_uppercase);
  tcase_add_test(normalTests, converting_line_with_uppercase_to_uppercase);

  TCase *abnormalTests = tcase_create("Abnormal Tests");
  tcase_add_test(abnormalTests, converting_empty_line_to_uppercase);
  tcase_add_test(abnormalTests, converting_spaces_line_to_uppercase);
  tcase_add_test(abnormalTests, converting_line_with_numbers_to_uppercase);
  tcase_add_test(abnormalTests,
                 converting_line_with_different_symbols_to_uppercase);
  tcase_add_test(abnormalTests, converting_string_with_null_character);
  tcase_add_test(abnormalTests, converting_large_string_to_uppercase);

  suite_add_tcase(suite, normalTests);
  suite_add_tcase(suite, abnormalTests);

  return suite;
}
