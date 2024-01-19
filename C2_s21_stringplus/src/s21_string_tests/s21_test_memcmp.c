#include "s21_tests.h"

// Тестирование на базовых случаях:
// Функция корректно считает разницу между строками в простых случаях -
// строки одинаковые, символ отличается, часть строки одинакова.

START_TEST(compare_equal_strings) {
  char *string1 = "Hello world";
  char *string2 = "Hello world";
  s21_size_t countBytesToCompare = 11;
  ck_assert_int_eq(s21_memcmp(string1, string2, countBytesToCompare),
                   memcmp(string1, string2, countBytesToCompare));
  // Ожидаем, что s21_memcmp вернет 0, так как строки идентичны.
}
END_TEST

START_TEST(compare_different_strings) {
  char *string1 = "Hello world";
  char *string2 = "Heflo World";
  s21_size_t countBytesToCompare = 11;
  ck_assert_int_eq(s21_memcmp(string1, string2, countBytesToCompare),
                   memcmp(string1, string2, countBytesToCompare));
  // Ожидаем, что s21_memcmp вернет ненулевое значение, так как строки
  // различаются. (отрицательное число)
}
END_TEST

START_TEST(compare_partial_strings) {
  char *string1 = "My br1ther is a ...";
  char *string2 = "My br2coul a ...";
  s21_size_t countBytesToCompare = 5;
  ck_assert_int_eq(s21_memcmp(string1, string2, countBytesToCompare),
                   memcmp(string1, string2, countBytesToCompare));
  // Ожидаем, что s21_memcmp вернет 0, так как первые 5 символов идентичны.
}
END_TEST

// Проверка функции при длине сравнения 0

START_TEST(compare_different_strings_but_zero_length) {
  char *string1 = "Hello";
  char *string2 = "World";
  s21_size_t countBytesToCompare = 0;

  ck_assert_int_eq(s21_memcmp(string1, string2, countBytesToCompare),
                   memcmp(string1, string2, countBytesToCompare));
  // Ожидаеим, что функция вернёт 0, поскольку длина, заданная для сравнения
  // равна 0
}
END_TEST

START_TEST(compare_equal_strings_but_zero_length) {
  char *string1 = "Hello";
  char *string2 = "Hello";
  s21_size_t countBytesToCompare = 0;

  ck_assert_int_eq(s21_memcmp(string1, string2, countBytesToCompare),
                   memcmp(string1, string2, countBytesToCompare));
  // Ожидаем, что функция вернёт 0, поскольку длина, заданная для сравнения
  // равна 0
}
END_TEST

// Тестирование на краевых случаях:
// В функцию передают пустые строки, строки содержат null символ, в функцию
// передают достаточно большое число (одинаковое и различаемое)

START_TEST(compare_empty_strings) {
  char *string1 = "";
  char *string2 = "";
  s21_size_t countBytesToCompare = 0;
  ck_assert_int_eq(s21_memcmp(string1, string2, countBytesToCompare),
                   memcmp(string1, string2, countBytesToCompare));
  // Ожидаем, что s21_memcmp вернет 0, так как обе строки пусты.
}
END_TEST

START_TEST(compare_strings_with_nulls) {
  char *string1 = "Hello\0Zorld";
  char *string2 = "Hello\0World";
  s21_size_t countBytesToCompare = 12;
  ck_assert_int_eq(s21_memcmp(string1, string2, countBytesToCompare),
                   memcmp(string1, string2, countBytesToCompare));
  // Ожидаем, что s21_memcmp вернет ненулевое значение, так как строки
  // отличаются после нулевого символа. (положительное число)
}
END_TEST

START_TEST(compare_equal_strings_at_large_length) {
  char string1[10000];
  char string2[10000];

  for (s21_size_t i = 0; i < sizeof(string1) / sizeof(char); i++) {
    string1[i] = string2[i] = i & 26;
  }

  s21_size_t countBytesToCompare = 12;
  ck_assert_int_eq(s21_memcmp(string1, string2, countBytesToCompare),
                   memcmp(string1, string2, countBytesToCompare));
  // Ожидаем, что s21_memcmp вернет 0, поскольку строки одинаковые
}
END_TEST

START_TEST(compare_different_strings_at_large_length) {
  char string1[10000];
  char string2[10000];

  for (s21_size_t i = 0; i < sizeof(string1) / sizeof(char); i++) {
    string1[i] = 'A' + (i % 26);
    string2[i] = 'B' + (i % 26);
  }

  s21_size_t countBytesToCompare = 12;
  ck_assert_int_ne(s21_memcmp(string1, string2, countBytesToCompare), 0);
  // Ожидаем, что s21_memcmp вернет не 0, поскольку строки различны
}
END_TEST

Suite *suite_memcmp() {
  Suite *suite = suite_create("s21_memcmp");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, compare_equal_strings);
  tcase_add_test(basicTests, compare_different_strings);
  tcase_add_test(basicTests, compare_partial_strings);
  tcase_add_test(basicTests, compare_different_strings_but_zero_length);
  tcase_add_test(basicTests, compare_equal_strings_but_zero_length);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, compare_empty_strings);
  tcase_add_test(edgeTests, compare_strings_with_nulls);
  tcase_add_test(edgeTests, compare_equal_strings_at_large_length);
  tcase_add_test(edgeTests, compare_different_strings_at_large_length);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}