#include "s21_tests.h"

// Тестирование на базовых случаях:
// Копирование из одного буфера в другой с различными случаями: идентичные
// буферы, различные буферы, часть буфера.

START_TEST(copy_identical_buffers) {
  char *source = "Hello world";
  char destination[12];
  s21_size_t countBytesToCopy = 11;

  s21_memcpy(destination, source, countBytesToCopy);
  memcpy(destination, source, countBytesToCopy);

  ck_assert_mem_eq(destination, source, countBytesToCopy);
  // Ожидаем, что содержимое destination стало таким же, как у source
}
END_TEST

START_TEST(copy_different_buffers) {
  char *source = "Hello world";
  char destination[12] = "Different";
  s21_size_t countBytesToCopy = 11;

  s21_memcpy(destination, source, countBytesToCopy);
  memcpy(destination, source, countBytesToCopy);

  ck_assert_mem_eq(destination, source, countBytesToCopy);
  // Ожидаем, что содержимое destination заменится содержимым source
}
END_TEST

START_TEST(copy_partial_buffer) {
  char *source = "Hello world";
  char destination[30] = "Goodbyeeeeeeeee";
  s21_size_t countBytesToCopy = 5;

  s21_memcpy(destination, source, countBytesToCopy);
  memcpy(destination, source, countBytesToCopy);

  ck_assert_mem_eq(destination, source, countBytesToCopy);
  // Ожидаем, что только первые 5 символов destination заменятся содержимым
  // source
}
END_TEST

// Тестирование на краевых случаях:
// Копирование при длине копирования 0, копирование в/из пустых буферов,
// копирование с null символами.

START_TEST(copy_empty_buffers) {
  char *source = "";
  char destination[] = "Hello";
  s21_size_t countBytesToCopy = 0;

  s21_memcpy(destination, source, countBytesToCopy);
  memcpy(destination, source, countBytesToCopy);

  ck_assert_mem_eq(destination, "Hello", 5);
  // Ожидаем, что содержимое destination не изменилось
}
END_TEST

START_TEST(copy_to_empty_buffer) {
  char *source = "Hello world";
  char destination[12] = "";
  s21_size_t countBytesToCopy = 11;

  s21_memcpy(destination, source, countBytesToCopy);
  memcpy(destination, source, countBytesToCopy);

  ck_assert_mem_eq(destination, source, countBytesToCopy);
  // Ожидаем, что содержимое destination стало таким же, как у source
}
END_TEST

START_TEST(copy_with_nulls_in_middle) {
  char *source = "Hello\0world";
  char destination[12];
  s21_size_t countBytesToCopy = 11;

  s21_memcpy(destination, source, countBytesToCopy);
  memcpy(destination, source, countBytesToCopy);

  ck_assert_mem_eq(destination, "Hello\0world", 11);
  // Ожидаем, что содержимое destination стало таким же, как у source
}
END_TEST

START_TEST(copy_large_string_to_empty_buffer) {
  char source[10000];
  char destination[10000] = "";
  for (s21_size_t i = 0; i < sizeof(source) / sizeof(char); i++) {
    source[i] = i & 26;
  }
  s21_size_t countBytesToCopy = sizeof(source);

  s21_memcpy(destination, source, countBytesToCopy);
  memcpy(destination, source, countBytesToCopy);

  ck_assert_mem_eq(destination, source, countBytesToCopy);
  // Ожидаем, что содержимое destination стало таким же, как у source
}
END_TEST

START_TEST(copy_large_string_to_small_buffer) {
  char source[10000];
  char destination[5000];
  for (s21_size_t i = 0; i < sizeof(source) / sizeof(char); i++) {
    source[i] = i & 26;
  }
  s21_size_t countBytesToCopy = sizeof(destination);

  s21_memcpy(destination, source, countBytesToCopy);
  memcpy(destination, source, countBytesToCopy);

  ck_assert_mem_eq(destination, source, countBytesToCopy);
  // Ожидаем, что только первые 5000 символов destination заменятся содержимым
  // source
}
END_TEST

Suite *suite_memcpy() {
  Suite *suite = suite_create("s21_memcpy");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, copy_identical_buffers);
  tcase_add_test(basicTests, copy_different_buffers);
  tcase_add_test(basicTests, copy_partial_buffer);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, copy_empty_buffers);
  tcase_add_test(edgeTests, copy_to_empty_buffer);
  tcase_add_test(edgeTests, copy_with_nulls_in_middle);
  tcase_add_test(edgeTests, copy_large_string_to_empty_buffer);
  tcase_add_test(edgeTests, copy_large_string_to_small_buffer);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}