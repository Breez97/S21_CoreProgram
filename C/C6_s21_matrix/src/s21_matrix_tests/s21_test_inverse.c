#include "s21_test_matrix.h"

// Проверка на некорректные значения.
// 1. На вычисление подается некорректная матрица.
// 2. На вычисление подается не квадратная матрица (необходимо, чтобы была
// квадратная, потому что в противном случае нельзя будет найти определитель).
// 3. Определитель исходной матрицы равен нулю.
// @return
// для первого случая -> INCORRECT_MATRIX (1)
// для второго случая -> INCORRECT_CALC (2)
// для третьего случая -> INCORRECT_CALC (2)

START_TEST(s21_inverse_matrix_false_1) {
  // На вычисление подается некорректная матрица.
  matrix_t A;
  const int rows = 3;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);
  A.rows = -2;

  matrix_t result;

  int resultCode = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  A.rows = rows;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_false_2) {
  // На вычисление подается некорректная матрица.
  matrix_t A;
  const int rows = 3;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);
  A.columns = 0;

  matrix_t result;

  int resultCode = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  A.columns = columns;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_false_3) {
  // На вычисление подается не квадратная матрица.
  matrix_t A;
  const int rows = 1;
  const int columns = 4;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  int resultCode = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_CALC);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_false_4) {
  // На вычисление подается не квадратная матрица.
  matrix_t A;
  const int rows = 5;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  int resultCode = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_CALC);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_false_5) {
  // Определитель исходной матрицы равен нулю.
  matrix_t A;
  const int rows = 5;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
    }
  }

  int resultCode = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_CALC);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_false_6) {
  matrix_t A;
  const int rows = 1;
  const int columns = 1;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[1][1] = {{34.862}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
    }
  }

  int resultCodeInverse = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(resultCodeInverse, CHECK_INCORRECT_CALC);

  s21_remove_matrix(&A);
}
END_TEST

// Проверка на корректные значения.

START_TEST(s21_inverse_matrix_true_1) {
  matrix_t A;
  const int rows = 3;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeInverse = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(resultCodeInverse, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_inverse_matrix_true_2) {
  matrix_t A;
  const int rows = 2;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[2][2] = {{-149.09, 101.39}, {-1.46, -147.92}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[2][2] = {{-0.0066626, -0.0045668},
                                  {0.0000658, -0.0067153}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeInverse = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(resultCodeInverse, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_inverse_matrix_true_3) {
  matrix_t A;
  const int rows = 3;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[3][3] = {{45, -173, 63}, {-123, 186, 50}, {-18, -12, -78}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[3][3] = {{-0.0093123, -0.0095412, -0.0136376},
                                  {-0.0070263, -0.0015909, -0.0066949},
                                  {0.0032299, 0.0024466, -0.0086434}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeInverse = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(resultCodeInverse, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_inverse_matrix_true_4) {
  matrix_t A;
  const int rows = 4;
  const int columns = 4;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[4][4] = {
      {234, 12, 32, 15}, {64, 2, 14, 21}, {3, 42, 2, 332}, {98, 65, 73, 13}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[4][34] = {
      {0.0077891, -0.0107987, 0.0003842, -0.0013539},
      {0.0276924, -0.1170698, 0.0057562, 0.0101549},
      {-0.0345149, 0.1162071, -0.0060537, 0.0067079},
      {-0.0033657, 0.0142076, 0.0023169, -0.0013128}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeInverse = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(resultCodeInverse, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *suite_s21_inverse_matrix() {
  Suite *suite = suite_create("s21_inverse");

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_inverse_matrix_false_1);
  tcase_add_test(testsFalse, s21_inverse_matrix_false_2);
  tcase_add_test(testsFalse, s21_inverse_matrix_false_3);
  tcase_add_test(testsFalse, s21_inverse_matrix_false_4);
  tcase_add_test(testsFalse, s21_inverse_matrix_false_5);
  tcase_add_test(testsFalse, s21_inverse_matrix_false_6);

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsFalse, s21_inverse_matrix_true_1);
  tcase_add_test(testsFalse, s21_inverse_matrix_true_2);
  tcase_add_test(testsFalse, s21_inverse_matrix_true_3);
  tcase_add_test(testsFalse, s21_inverse_matrix_true_4);

  suite_add_tcase(suite, testsFalse);
  suite_add_tcase(suite, testsTrue);

  return suite;
}