#include "s21_tests.h"

// Тестирование на базовых случаях:
// Функция корректно заполняет заданную часть строки новыми символами -
// часть, полностью, нулевая длина

START_TEST(test_memset_basic) {
  char destinationS21[] =
      "Hello its school 21, we test memset and i want to go sleep";
  char destinationOrigin[] =
      "Hello its school 21, we test memset and i want to go sleep";
  char symbol = 's';
  s21_size_t lenBytes = 12;
  s21_memset(destinationS21, symbol, lenBytes);
  memset(destinationOrigin, symbol, lenBytes);

  ck_assert_str_eq(destinationS21, destinationOrigin);
  // Ожидаем, что первые 12 символов двух строк будут заменены символом s
}
END_TEST

START_TEST(test_memset_fill) {
  char buffer[20] = "Hello, School 21!   ";
  char bufferOrigin[20] = "Hello, School 21!   ";
  s21_size_t lenBytes = 20;
  s21_memset(buffer, 's', lenBytes);
  memset(bufferOrigin, 's', lenBytes);
  buffer[lenBytes - 1] = '\0';
  bufferOrigin[lenBytes - 1] = '\0';
  ck_assert_str_eq(buffer, bufferOrigin);
}
END_TEST

START_TEST(test_memset_partial_fill) {
  char buffer[20] = "Hello, School 21!";
  char expected[20] = "Hello, Ssssss 21!";
  s21_size_t lenBytes = 5;
  s21_memset(buffer + 8, 's', lenBytes);
  ck_assert_str_eq(buffer, expected);
  // Ожидаем, что часть массива с 8 элемента будет заполнена s
}
END_TEST

START_TEST(test_memset_zero_length) {
  char buffer[20] = "Hello, School 21!";
  char expected[20] = "Hello, School 21!";
  s21_size_t lenBytes = 0;
  s21_memset(buffer, 's', lenBytes);
  ck_assert_str_eq(buffer, expected);
  // Ожидаем, что строка никак не изменится (i > lenBytes)
}
END_TEST

// Тестирование на краевых случаях:
// Работа функции при заполнении null символом, заполнение при пустом массиве,
// заполнение превышающие длину массива,

START_TEST(test_memset_null_terminator) {
  char buffer[20] = "Hello, School 21!";
  char expected[20] = "";
  s21_size_t lenBytes = 20;
  s21_memset(buffer, '\0', lenBytes);
  ck_assert_str_eq(buffer, expected);
  //Ожидаем заполнение строки null символом
}
END_TEST

START_TEST(test_memset_empty_buffer) {
  char buffer[2] = "";
  s21_size_t lenBytes = 1;
  s21_memset(buffer, 's', lenBytes);
  buffer[1] = '\0';
  ck_assert_str_eq(buffer, "s");
  // Ожидаем, что строка будет состоять из одного символа s
}
END_TEST

START_TEST(test_memset_zero_symbol) {
  char buffer[20] = "Hello, School 21!";
  char expected[20] = "\0";
  s21_size_t lenBytes = 5;
  s21_memset(buffer, 0, lenBytes);
  ck_assert_str_eq(buffer, expected);
  // Ожидаем, что строка будет содержать в начале null символ
}
END_TEST

// Иные - другие тесты

START_TEST(test_replace_with_null_byte) {
  char res[] = "Hello, School 21!";
  char expected[] = "\0ello, School 21!";
  char replace = '\0';
  s21_size_t n_byte = 1;

  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);

  ck_assert_str_eq(res, expected);
  // Ожидаем, что первый символ массива будет заменен на null символ
}
END_TEST

START_TEST(test_replace_middle) {
  char res[] = "Hello, School 21!";
  char expected[] = "Hello, School 21!";
  char replace = 'A';
  s21_size_t n_byte = 1;

  s21_memset(res + 6, replace, n_byte);
  memset(expected + 6, replace, n_byte);

  ck_assert_str_eq(res, expected);
  // Ожидаем, что шестой символ строки будет заменен на символ 'A'
}
END_TEST

START_TEST(test_replace_alpha_numeric) {
  char res[] = "d11255";
  char expected[] = "d99555";
  char replace = '5';
  s21_size_t n_byte = 3;

  s21_memset(res + 1, replace, n_byte);
  memset(expected + 1, replace, n_byte);

  ck_assert_str_eq(res, expected);
  // Ожидаем, что со второго символа строки будут заменены на символ '5'
}
END_TEST

Suite *suite_memset() {
  Suite *suite = suite_create("s21_memset");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, test_memset_basic);
  tcase_add_test(basicTests, test_memset_fill);
  tcase_add_test(basicTests, test_memset_partial_fill);
  tcase_add_test(basicTests, test_memset_zero_length);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, test_memset_null_terminator);
  tcase_add_test(edgeTests, test_memset_empty_buffer);
  tcase_add_test(edgeTests, test_memset_zero_symbol);

  TCase *otherTests = tcase_create("Other Tests");
  tcase_add_test(otherTests, test_replace_with_null_byte);
  tcase_add_test(otherTests, test_replace_middle);
  tcase_add_test(otherTests, test_replace_alpha_numeric);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);
  suite_add_tcase(suite, otherTests);

  return suite;
}