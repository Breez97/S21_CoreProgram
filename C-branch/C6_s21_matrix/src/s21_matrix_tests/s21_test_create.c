#include "s21_test_matrix.h"

// Проверка на некорректные значения.
// Количество строк или столбцов при создании матрицы меньше или равно нулю.
// @return S21_INCORRECT_MATRIX (1)

START_TEST(s21_create_matrix_false_1) {
  matrix_t result;
  const int rows = 0;
  const int columns = 5;

  int resultCode = s21_create_matrix(rows, columns, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_false_2) {
  matrix_t result;
  const int rows = 0;
  const int columns = 0;

  int resultCode = s21_create_matrix(rows, columns, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_false_3) {
  matrix_t result;
  const int rows = -4;
  const int columns = 2;

  int resultCode = s21_create_matrix(rows, columns, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_false_4) {
  matrix_t result;
  const int rows = 6;
  const int columns = -1;

  int resultCode = s21_create_matrix(rows, columns, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_false_5) {
  matrix_t result;
  const int rows = 8;
  const int columns = 0;

  int resultCode = s21_create_matrix(rows, columns, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);
}
END_TEST

// Проверка на корректные значения.
// Матрица успешно создается, количество строк и столбцов больше 0.
// @return S21_OK (0)

START_TEST(s21_create_matrix_true_1) {
  matrix_t result;
  const int rows = 1;
  const int columns = 1;

  int resultCode = s21_create_matrix(rows, columns, &result);
  if (resultCode == CHECK_OK) {
    s21_remove_matrix(&result);
  }

  ck_assert_int_eq(resultCode, CHECK_OK);
}
END_TEST

START_TEST(s21_create_matrix_true_2) {
  matrix_t result;
  const int rows = 3;
  const int columns = 5;

  int resultCode = s21_create_matrix(rows, columns, &result);
  if (resultCode == CHECK_OK) {
    s21_remove_matrix(&result);
  }

  ck_assert_int_eq(resultCode, CHECK_OK);
}
END_TEST

START_TEST(s21_create_matrix_true_3) {
  matrix_t result;
  const int rows = 12;
  const int columns = 18;

  int resultCode = s21_create_matrix(rows, columns, &result);
  if (resultCode == CHECK_OK) {
    s21_remove_matrix(&result);
  }

  ck_assert_int_eq(resultCode, CHECK_OK);
}
END_TEST

START_TEST(s21_create_matrix_true_4) {
  matrix_t result;
  const int rows = 9;
  const int columns = 9;

  int resultCode = s21_create_matrix(rows, columns, &result);
  if (resultCode == CHECK_OK) {
    s21_remove_matrix(&result);
  }

  ck_assert_int_eq(resultCode, CHECK_OK);
}
END_TEST

START_TEST(s21_create_matrix_true_5) {
  matrix_t result;
  const int rows = 2;
  const int columns = 6;

  int resultCode = s21_create_matrix(rows, columns, &result);
  if (resultCode == CHECK_OK) {
    s21_remove_matrix(&result);
  }

  ck_assert_int_eq(resultCode, CHECK_OK);
}
END_TEST

Suite *suite_s21_create_matrix() {
  Suite *suite = suite_create("s21_create_matrix");

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_create_matrix_false_1);
  tcase_add_test(testsFalse, s21_create_matrix_false_2);
  tcase_add_test(testsFalse, s21_create_matrix_false_3);
  tcase_add_test(testsFalse, s21_create_matrix_false_4);
  tcase_add_test(testsFalse, s21_create_matrix_false_5);

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_create_matrix_true_1);
  tcase_add_test(testsTrue, s21_create_matrix_true_2);
  tcase_add_test(testsTrue, s21_create_matrix_true_3);
  tcase_add_test(testsTrue, s21_create_matrix_true_4);
  tcase_add_test(testsTrue, s21_create_matrix_true_5);

  suite_add_tcase(suite, testsFalse);
  suite_add_tcase(suite, testsTrue);

  return suite;
}
