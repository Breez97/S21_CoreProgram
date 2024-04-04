#include "s21_tests.h"

// Тестирование на базовых случаях:
// Функция корректно копирует (нормальное выполнение) заданную часть символов
// после n-ого количества байт

START_TEST(test_strncat_basic_copy) {
  char destination1[20] = "Hello, ", destination2[20] = "Hello, ";
  char src[] = "School 21!";
  char expected[20] = "Hello, School 21!";

  s21_strncat(destination1, src, 12);
  strncat(destination2, src, 12);

  ck_assert_mem_eq(destination1, expected, sizeof(expected));
  ck_assert_mem_eq(destination1, destination2, sizeof(expected));

  // Ожидание от выполнения функции - strncat и s21_strncat на выходе дадут
  // результат выполнения Hello, School 21!
}

START_TEST(test_strncat_empty_dest) {
  char destination1[20] = "", destination2[20] = "";
  char src[] = "School 21!";
  char expected[20] = "School 21!";

  s21_strncat(destination1, src, 10);
  strncat(destination2, src, 10);

  ck_assert_mem_eq(destination1, expected, sizeof(expected));
  ck_assert_mem_eq(destination1, destination2, sizeof(expected));
  // Ожидание от выполнения функции - strncat и s21_strncat на выходе дадут
  // результат выполнения School 21!
}
END_TEST

START_TEST(test_strncat_number_exceeding_len_strings) {
  char destination1[50] = "Hello, ", destination2[50] = "Hello, ";
  char src[] = "School 21!";
  char expected[20] = "Hello, School 21!";

  s21_strncat(destination1, src, 40);
  strncat(destination2, src, 40);

  ck_assert_mem_eq(destination1, expected, sizeof(expected));
  ck_assert_mem_eq(destination1, destination2, sizeof(expected));
  // Ожидание от выполнения функции - strncat и s21_strncat на выходе дадут
  // полною конкотенацию строк при длине большей чем source и dest (выход при
  // null символе)
}
END_TEST

START_TEST(test_strncat_empty_src) {
  char destination1[20] = "Hello, ", destination2[20] = "Hello, ";
  char src[] = "";
  char expected[20] = "Hello, ";

  s21_strncat(destination1, src, 5);
  strncat(destination2, src, 5);

  ck_assert_mem_eq(destination1, expected, sizeof(expected));
  ck_assert_mem_eq(destination1, destination2, sizeof(expected));
  // Ожидание от выполнения функции - строка destinationN останется неизменной,
  // так как src пустая
}
END_TEST

START_TEST(test_strncat_full_dest) {
  char destination1[20] = "Hello, School ", destination2[20] = "Hello, School ";
  char src[] = "21!!!!!!";
  char expected[20] = "Hello, School 21!";

  s21_strncat(destination1, src, 3);
  strncat(destination2, src, 3);

  ck_assert_mem_eq(destination1, expected, sizeof(expected));
  ck_assert_mem_eq(destination1, destination2, sizeof(expected));
  // Ожидание от выполнения функции - строка destinationN будет содержать
  // объединение destinationN и первых 3 символов src
}
END_TEST

// Тестирование на краевых случаях:
// Работа функции при пустых dest, src, 0 количество байт

START_TEST(test_strncat_empty_strings) {
  char destination1[20] = "", destination2[20] = "";
  char src[] = "";
  char expected[20] = "";

  s21_strncat(destination1, src, 0);
  strncat(destination2, src, 0);

  ck_assert_mem_eq(destination1, expected, sizeof(expected));
  ck_assert_mem_eq(destination1, destination2, sizeof(expected));
  // Ожидание от выполнения функции - строка destinationN останется пустой, так
  // как оба исходных массива пусты
}
END_TEST

START_TEST(test_strncat_zero_bytes) {
  char destination1[20] = "Hello, ", destination2[20] = "Hello, ";
  char src[] = "School 21!";
  char expected[20] = "Hello, ";

  s21_strncat(destination1, src, 0);
  strncat(destination2, src, 0);

  ck_assert_mem_eq(destination1, expected, sizeof(expected));
  ck_assert_mem_eq(destination1, destination2, sizeof(expected));
  // Ожидание от выполнения функции - строка destinationN останется неизменной,
  // так как количество байт для копирования равно 0
}
END_TEST

Suite *suite_strncat() {
  Suite *suite = suite_create("s21_strncat");

  TCase *normalTests = tcase_create("Normal Tests");
  tcase_add_test(normalTests, test_strncat_basic_copy);
  tcase_add_test(normalTests, test_strncat_number_exceeding_len_strings);
  tcase_add_test(normalTests, test_strncat_empty_dest);
  tcase_add_test(normalTests, test_strncat_empty_src);
  tcase_add_test(normalTests, test_strncat_full_dest);
  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, test_strncat_empty_strings);
  tcase_add_test(edgeTests, test_strncat_zero_bytes);

  suite_add_tcase(suite, normalTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}