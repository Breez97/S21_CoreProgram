#include "s21_tests.h"

// Тестирование на базовых случаях:

START_TEST(known_error_code) {
  int errorCode = ENOMEM;  // Известный код ошибки
  const char *result = s21_strerror(errorCode);
  ck_assert_str_eq(result, strerror(errorCode));
  // Ожидаем, что s21_strerror вернет строку ошибки, соответствующую известному
  // коду ошибки.
}
END_TEST

START_TEST(unknown_error_code) {
  int errorCode = 9999;  // Неизвестный код ошибки
  const char *result = s21_strerror(errorCode);
  ck_assert_str_eq(result, strerror(errorCode));
  // Ожидаем, что s21_strerror вернет общее сообщение для неизвестного кода
  // ошибки.
}
END_TEST

// Тестирование на краевых случаях:

START_TEST(zero_error_code) {
  int errorCode = 0;  // Код ошибки 0
  const char *result = s21_strerror(errorCode);
  ck_assert_str_eq(result, strerror(errorCode));
  // Ожидаем, что s21_strerror вернет "Success" для кода ошибки 0.
}
END_TEST

START_TEST(negative_error_code) {
  int errorCode = -EINVAL;  // Отрицательный код ошибки
  const char *result = s21_strerror(errorCode);
  ck_assert_str_eq(result, strerror(errorCode));
  // Ожидаем, что s21_strerror вернет строку ошибки, соответствующую
  // отрицательному коду ошибки.
}
END_TEST

Suite *suite_strerror() {
  Suite *suite = suite_create("s21_strerror");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, known_error_code);
  tcase_add_test(basicTests, unknown_error_code);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, zero_error_code);
  tcase_add_test(edgeTests, negative_error_code);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}
