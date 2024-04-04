#include "s21_test_matrix.h"

// Проверка на основе создания и очистки матрицы.
// @return S21_OK

START_TEST(s21_remove_matrix_true_1) {
  matrix_t A;
  const int rows = 1;
  const int columns = 1;

  int resultCode = s21_create_matrix(rows, columns, &A);
  if (resultCode == CHECK_OK) {
    s21_remove_matrix(&A);
    if (A.matrix != NULL || A.rows != 0 || A.columns != 0) {
      resultCode = CHECK_OTHER_ERROR;
    }
  }

  ck_assert_int_eq(resultCode, CHECK_OK);
}
END_TEST

START_TEST(s21_remove_matrix_true_2) {
  matrix_t A;
  const int rows = 4;
  const int columns = 5;

  int resultCode = s21_create_matrix(rows, columns, &A);
  if (resultCode == CHECK_OK) {
    s21_remove_matrix(&A);
    if (A.matrix != NULL || A.rows != 0 || A.columns != 0) {
      resultCode = CHECK_OTHER_ERROR;
    }
  }

  ck_assert_int_eq(resultCode, CHECK_OK);
}
END_TEST

START_TEST(s21_remove_matrix_true_3) {
  matrix_t A;
  const int rows = 7;
  const int columns = 21;

  int resultCode = s21_create_matrix(rows, columns, &A);
  if (resultCode == CHECK_OK) {
    s21_remove_matrix(&A);
    if (A.matrix != NULL || A.rows != 0 || A.columns != 0) {
      resultCode = CHECK_OTHER_ERROR;
    }
  }

  ck_assert_int_eq(resultCode, CHECK_OK);
}
END_TEST

START_TEST(s21_remove_matrix_true_4) {
  matrix_t A;
  const int rows = 4;
  const int columns = 1;

  int resultCode = s21_create_matrix(rows, columns, &A);
  if (resultCode == CHECK_OK) {
    s21_remove_matrix(&A);
    if (A.matrix != NULL || A.rows != 0 || A.columns != 0) {
      resultCode = CHECK_OTHER_ERROR;
    }
  }

  ck_assert_int_eq(resultCode, CHECK_OK);
}
END_TEST

START_TEST(s21_remove_matrix_true_5) {
  matrix_t A;
  const int rows = 6;
  const int columns = 2;

  int resultCode = s21_create_matrix(rows, columns, &A);
  if (resultCode == CHECK_OK) {
    s21_remove_matrix(&A);
    if (A.matrix != NULL || A.rows != 0 || A.columns != 0) {
      resultCode = CHECK_OTHER_ERROR;
    }
  }

  ck_assert_int_eq(resultCode, CHECK_OK);
}
END_TEST

Suite *suite_s21_remove_matrix() {
  Suite *suite = suite_create("s21_remove_matrix");

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_remove_matrix_true_1);
  tcase_add_test(testsTrue, s21_remove_matrix_true_2);
  tcase_add_test(testsTrue, s21_remove_matrix_true_3);
  tcase_add_test(testsTrue, s21_remove_matrix_true_4);
  tcase_add_test(testsTrue, s21_remove_matrix_true_5);

  suite_add_tcase(suite, testsTrue);

  return suite;
}
