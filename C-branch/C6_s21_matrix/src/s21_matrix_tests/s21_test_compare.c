#include "s21_test_matrix.h"

// Проверка на некорректные значения.
// 1. На сравнение подаются некорректные матрицы.
// 2. Матрицы отличаются размерами.
// 3. Различаются элементы матриц.
// @return FAILURE (0)

START_TEST(s21_eq_matrix_false_1) {
  // На сравнение подаются некорректные матрицы.
  matrix_t A;
  const int rowsA = 1;
  const int columnsA = 2;
  s21_create_matrix(rowsA, columnsA, &A);
  A.rows = 0;

  matrix_t B;
  const int rowsB = 4;
  const int columnsB = 2;
  s21_create_matrix(rowsB, columnsB, &B);

  int resultCode = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(resultCode, CHECK_FAILURE);

  A.rows = rowsA;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_false_2) {
  // На сравнение подаются некорректные матрицы.
  matrix_t A;
  const int rowsA = 2;
  const int columnsA = 3;
  s21_create_matrix(rowsA, columnsA, &A);
  A.columns = 0;

  matrix_t B;
  const int rowsB = 8;
  const int columnsB = 4;
  s21_create_matrix(rowsB, columnsB, &B);
  B.rows = 0;

  int resultCode = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(resultCode, CHECK_FAILURE);

  A.columns = columnsA;
  B.rows = rowsB;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_false_3) {
  // Матрицы отличаются размерами.
  matrix_t A;
  const int rowsA = 2;
  const int columnsA = 3;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 1;
  const int columnsB = 3;
  s21_create_matrix(rowsB, columnsB, &B);

  int resultCode = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(resultCode, CHECK_FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_false_4) {
  // Матрицы отличаются размерами.
  matrix_t A;
  const int rowsA = 4;
  const int columnsA = 4;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 5;
  const int columnsB = 4;
  s21_create_matrix(rowsB, columnsB, &B);

  int resultCode = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(resultCode, CHECK_FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_false_5) {
  // Различаются элементы матриц.
  matrix_t A;
  matrix_t B;
  const int rows = 3;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  double numbersB[3][3] = {{1, 2, 3}, {4, 9, 8}, {1, 2, 9}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
    }
  }

  int resultCode = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(resultCode, CHECK_FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_false_6) {
  // Различаются элементы матриц.
  matrix_t A;
  matrix_t B;
  const int rows = 2;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[2][2] = {{1, 2}, {3, 4}};

  double numbersB[2][2] = {{0, 0}, {3, 4}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
    }
  }

  int resultCode = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(resultCode, CHECK_FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// Проверка на корректные значения.
// @return SUCCESS (1)

START_TEST(s21_eq_matrix_true_1) {
  matrix_t A;
  matrix_t B;
  const int rows = 2;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[2][2] = {{1, 2}, {3, 4}};

  double numbersB[2][2] = {{1, 2}, {3, 4}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
    }
  }

  int resultCode = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(resultCode, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_true_2) {
  matrix_t A;
  matrix_t B;
  const int rows = 3;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[3][3] = {{1.0000001, 2.0000234, 8.8128905},
                           {4.12312, 3.21123, 12},
                           {132.15421, 3231.6546, 8.223}};

  double numbersB[3][3] = {{1.0000001, 2.0000234, 8.8128905},
                           {4.12312, 3.21123, 12},
                           {132.15421, 3231.6546, 8.223}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
    }
  }

  int resultCode = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(resultCode, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_true_3) {
  matrix_t A;
  matrix_t B;
  const int rows = 4;
  const int columns = 4;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[4][4] = {{97.7469847, 93.8323805, 61.8509902, 89.4423365},
                           {73.1112140, 98.0371762, 53.7931744, 10.7254307},
                           {91.6343300, 62.5120757, 7.0233966, 90.3443043},
                           {59.9280984, 95.2074173, 63.8589374, 51.3516172}};

  double numbersB[4][4] = {{97.7469847, 93.8323805, 61.8509902, 89.4423365},
                           {73.1112140, 98.0371762, 53.7931744, 10.7254307},
                           {91.6343300, 62.5120757, 7.0233966, 90.3443043},
                           {59.9280984, 95.2074173, 63.8589374, 51.3516172}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
    }
  }

  int resultCode = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(resultCode, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_true_4) {
  matrix_t A;
  matrix_t B;
  const int rows = 4;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[4][2] = {
      {32.355, 91.137}, {13.050, 20.384}, {79.655, 61.707}, {75.628, 78.712}};

  double numbersB[4][2] = {
      {32.355, 91.137}, {13.050, 20.384}, {79.655, 61.707}, {75.628, 78.712}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
    }
  }

  int resultCode = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(resultCode, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_s21_eq_matrix() {
  Suite *suite = suite_create("s21_eq_matrix");

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_eq_matrix_false_1);
  tcase_add_test(testsFalse, s21_eq_matrix_false_2);
  tcase_add_test(testsFalse, s21_eq_matrix_false_3);
  tcase_add_test(testsFalse, s21_eq_matrix_false_4);
  tcase_add_test(testsFalse, s21_eq_matrix_false_5);
  tcase_add_test(testsFalse, s21_eq_matrix_false_6);

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsFalse, s21_eq_matrix_true_1);
  tcase_add_test(testsFalse, s21_eq_matrix_true_2);
  tcase_add_test(testsFalse, s21_eq_matrix_true_3);
  tcase_add_test(testsFalse, s21_eq_matrix_true_4);

  suite_add_tcase(suite, testsFalse);
  suite_add_tcase(suite, testsTrue);

  return suite;
}
