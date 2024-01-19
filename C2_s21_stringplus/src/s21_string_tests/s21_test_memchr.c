#include "s21_tests.h"

// Тестирование на базовых случаях:
// Функция корректно находит символ в простых случаях -
// строка из одного символа, строка с несколькими символами, символ в начале,
// середине и конце блока памяти.

START_TEST(search_character_at_beggining_line) {
  char *stringForTest = "Hello world";
  int symbolSearchByte = 'H';
  s21_size_t countBytesToFind = 11;
  ck_assert_ptr_eq(
      s21_memchr(stringForTest, symbolSearchByte, countBytesToFind),
      memchr(stringForTest, symbolSearchByte, countBytesToFind));
  // Ожидаем, что s21_memchr найдет символ 'h' в начале строки.
}
END_TEST

START_TEST(search_character_at_middle_line) {
  char *stringForTest = "hello world";
  int symbolSearchByte = ' ';
  s21_size_t countBytesToFind = 11;
  ck_assert_ptr_eq(
      s21_memchr(stringForTest, symbolSearchByte, countBytesToFind),
      memchr(stringForTest, symbolSearchByte, countBytesToFind));
  // Ожидаем, что s21_memchr найдет символ 'o' в середине строки.
}
END_TEST

START_TEST(search_character_at_end_line) {
  char *stringForTest = "hello world!";
  int symbolSearchByte = '!';
  s21_size_t countBytesToFind = 12;
  ck_assert_ptr_eq(
      s21_memchr(stringForTest, symbolSearchByte, countBytesToFind),
      memchr(stringForTest, symbolSearchByte, countBytesToFind));
  // Ожидаем, что s21_memchr найдет символ 'd' в конце строки.
}
END_TEST

// Тестирование на краевых случаях (возврат 0-го указателя):
// Функция принимает пустую строку либо же функция принимает строку - с попыткой
// найти null символ

START_TEST(search_null_character_in_empty_string) {
  char *stringForTest = "";
  int symbolSearchByte = '\0';
  s21_size_t countBytesToFind = 0;
  ck_assert_ptr_eq(
      s21_memchr(stringForTest, symbolSearchByte, countBytesToFind),
      memchr(stringForTest, symbolSearchByte, countBytesToFind));
  // Ожидаем, что s21_memchr найдет null символ в пустой строке на 0 позиции
}
END_TEST

START_TEST(search_null_character_in_border) {
  char *stringForTest = "Hello123World";
  int symbolSearchByte = '\0';
  s21_size_t countBytesToFind = 14;
  ck_assert_ptr_eq(
      s21_memchr(stringForTest, symbolSearchByte, countBytesToFind),
      memchr(stringForTest, symbolSearchByte, countBytesToFind));
  // Ожидаем, что s21_memchr найдет null символ на граничной позиции (конец
  // строки)
}
END_TEST

// Иные тесты для проверки

START_TEST(search_nonexistent_character) {
  char *stringForTest = "Hello World";
  int symbolSearchByte = 'x';
  s21_size_t countBytesToFind = 11;
  ck_assert_ptr_eq(
      s21_memchr(stringForTest, symbolSearchByte, countBytesToFind),
      memchr(stringForTest, symbolSearchByte, countBytesToFind));
  // Ожидаем, что s21_memchr вернет NULL, так как символ 'x' отсутствует в
  // строке.
}
END_TEST

START_TEST(search_character_within_limit) {
  char *stringForTest = "Hell1 World";
  int symbolSearchByte = 'o';
  s21_size_t countBytesToFind = 5;
  ck_assert_ptr_eq(
      s21_memchr(stringForTest, symbolSearchByte, countBytesToFind),
      memchr(stringForTest, symbolSearchByte, countBytesToFind));
  // Ожидаем, что s21_memchr не найдет символ 'o' в первых 5 символах строки.
}
END_TEST

START_TEST(find_integer_float_number_in_array) {
  int integerArray[] = {1, 2, 3, 1234, 5, 1, 100};
  s21_size_t countElements = sizeof(integerArray) / sizeof(int);
  int findNumber = 1234;

  ck_assert_ptr_eq(
      s21_memchr(integerArray, findNumber, countElements * sizeof(int)),
      memchr(integerArray, findNumber, countElements * sizeof(int)));

  // Ожидаем, что s21_memchr правильно найдет указатель на первое вхождение
  // числа 1234 (integer)

  float floatArray[] = {1, 2, 3, 1234, 5, 1, 100};
  ck_assert_ptr_eq(
      s21_memchr(floatArray, findNumber, countElements * sizeof(int)),
      memchr(floatArray, findNumber, countElements * sizeof(int)));

  // Ожидаем, что s21_memchr правильно найдет указатель на первое вхождение
  // числа 1234 (float)
}
END_TEST

Suite *suite_memchr() {
  Suite *suite = suite_create("s21_memchr");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, search_character_at_beggining_line);
  tcase_add_test(basicTests, search_character_at_middle_line);
  tcase_add_test(basicTests, search_character_at_end_line);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, search_null_character_in_empty_string);
  tcase_add_test(edgeTests, search_null_character_in_border);

  TCase *otherTests = tcase_create("Other Tests");
  tcase_add_test(otherTests, search_nonexistent_character);
  tcase_add_test(otherTests, search_character_within_limit);
  tcase_add_test(otherTests, find_integer_float_number_in_array);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);
  suite_add_tcase(suite, otherTests);

  return suite;
}