#include "s21_test_matrix.h"

// Проверка не некорректные значения.
// 1. На вычисление определителя подается некорректная матрица.
// 2. На вычисление определителя подается не квадратная матрица.
// @return
// для первого случая -> INCORRECT_MATRIX (1)
// для второго случая -> INCORRECT_CALC (2)

START_TEST(s21_determinant_false_1) {
  // На вычисление определителя подается некорректная матрица.
  matrix_t A;
  const int rows = 2;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.rows = -2;

  double result = 0.0;

  int resultCode = s21_determinant(&A, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  A.rows = rows;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_false_2) {
  // На вычисление определителя подается некорректная матрица.
  matrix_t A;
  const int rows = 5;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.rows = -4;
  A.columns = 0;

  double result = 1.2;

  int resultCode = s21_determinant(&A, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  A.rows = rows;
  A.columns = columns;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_false_3) {
  // На вычисление определителя подается не квадратная матрица.
  matrix_t A;
  const int rows = 2;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  double result = 1.2;

  int resultCode = s21_determinant(&A, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_false_4) {
  // На вычисление определителя подается не квадратная матрица.
  matrix_t A;
  const int rows = 1;
  const int columns = 4;
  s21_create_matrix(rows, columns, &A);

  double result = 1.2;

  int resultCode = s21_determinant(&A, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

// Проверка на корректные значения.

START_TEST(s21_determinant_true_1) {
  matrix_t A;
  const int rows = 1;
  const int columns = 1;
  s21_create_matrix(rows, columns, &A);

  double result = 0.0;

  double numbers[1][1] = {{65.239}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
    }
  }

  double expected = 65.239;

  int resultCodeDeterminant = s21_determinant(&A, &result);

  ck_assert_int_eq(resultCodeDeterminant, CHECK_OK);

  ck_assert_double_eq(result, expected);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_true_2) {
  matrix_t A;
  const int rows = 2;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);

  double result = 0.0;

  double numbers[2][2] = {{74.88221, -14.6309}, {9.20492, -18.6401}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
    }
  }

  double expected = -1261.135618593;

  int resultCodeDeterminant = s21_determinant(&A, &result);

  ck_assert_int_eq(resultCodeDeterminant, CHECK_OK);

  ck_assert(fabs(result - expected) < 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_true_3) {
  matrix_t A;
  const int rows = 3;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  double result = 0.0;

  double numbers[3][3] = {{37.07, -20.10, 31.66},
                          {-92.73, -13.92, 66.04},
                          {-32.33, -62.34, -96.21}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
    }
  }

  double expected = 593270.357262;

  int resultCodeDeterminant = s21_determinant(&A, &result);

  ck_assert_int_eq(resultCodeDeterminant, CHECK_OK);

  ck_assert(fabs(result - expected) < 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_true_4) {
  matrix_t A;
  const int rows = 3;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  double result = 0.0;

  double numbers[3][3] = {{-33.729, 86.184, -75.027},
                          {36.604, 22.623, 96.613},
                          {51.691, 46.824, 97.916}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
    }
  }

  double expected = 158524.634214891;

  int resultCodeDeterminant = s21_determinant(&A, &result);

  ck_assert_int_eq(resultCodeDeterminant, CHECK_OK);

  ck_assert(fabs(result - expected) < 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_true_5) {
  matrix_t A;
  const int rows = 4;
  const int columns = 4;
  s21_create_matrix(rows, columns, &A);

  double result = 0.0;

  double numbers[4][4] = {{71, 26, -78, 21},
                          {6, 48, -81, 19},
                          {-77, 16, 89, 27},
                          {-3, 12, 95, -26}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
    }
  }

  double expected = -19625694;

  int resultCodeDeterminant = s21_determinant(&A, &result);

  ck_assert_int_eq(resultCodeDeterminant, CHECK_OK);

  ck_assert(fabs(result - expected) < 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_true_6) {
  matrix_t A;
  const int rows = 4;
  const int columns = 4;
  s21_create_matrix(rows, columns, &A);

  double result = 0.0;

  double numbers[4][4] = {{17, -171, -73, -139},
                          {-63, 17, -197, -42},
                          {-85, -46, -187, 152},
                          {67, 190, 10, 120}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
    }
  }

  double expected = -860036381;

  int resultCodeDeterminant = s21_determinant(&A, &result);

  ck_assert_int_eq(resultCodeDeterminant, CHECK_OK);

  ck_assert(fabs(result - expected) < 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_s21_determinant() {
  Suite *suite = suite_create("s21_determinant");

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_determinant_false_1);
  tcase_add_test(testsFalse, s21_determinant_false_2);
  tcase_add_test(testsFalse, s21_determinant_false_3);
  tcase_add_test(testsFalse, s21_determinant_false_4);

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_determinant_true_1);
  tcase_add_test(testsTrue, s21_determinant_true_2);
  tcase_add_test(testsTrue, s21_determinant_true_3);
  tcase_add_test(testsTrue, s21_determinant_true_4);
  tcase_add_test(testsTrue, s21_determinant_true_5);
  tcase_add_test(testsTrue, s21_determinant_true_6);

  suite_add_tcase(suite, testsFalse);
  suite_add_tcase(suite, testsTrue);

  return suite;
}
