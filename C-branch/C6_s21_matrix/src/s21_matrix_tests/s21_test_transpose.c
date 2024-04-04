#include "s21_test_matrix.h"

// Проверка на неккоректные значения.
// Для транспонирования подается некорректная матрица.
// @return INCORRECT_MATRIX (1)

START_TEST(s21_transpose_false_1) {
  // Для транспонирования подается некорректная матрица.
  matrix_t A;
  const int rows = 1;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);
  A.rows = 0;

  matrix_t result;

  int resultCode = s21_transpose(&A, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  A.rows = rows;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_false_2) {
  // Для транспонирования подается некорректная матрица.
  matrix_t A;
  const int rows = 3;
  const int columns = 4;
  s21_create_matrix(rows, columns, &A);
  A.columns = -3;

  matrix_t result;

  int resultCode = s21_transpose(&A, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  A.columns = columns;
  s21_remove_matrix(&A);
}
END_TEST

// Проверка на корректные значения.

START_TEST(s21_transpose_true_1) {
  matrix_t A;
  const int rows = 3;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[3][2] = {{1, 4}, {2, 5}, {3, 6}};

  matrix_t expected;
  s21_create_matrix(columns, rows, &expected);

  double numbersExpected[2][3] = {{1, 2, 3}, {4, 5, 6}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[j][i] = numbersExpected[j][i];
    }
  }

  int resultCodeTranspose = s21_transpose(&A, &result);

  ck_assert_int_eq(resultCodeTranspose, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

START_TEST(s21_transpose_true_2) {
  matrix_t A;
  const int rows = 1;
  const int columns = 1;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[1][1] = {{2}};

  matrix_t expected;
  s21_create_matrix(columns, rows, &expected);

  double numbersExpected[1][1] = {{2}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[j][i] = numbersExpected[j][i];
    }
  }

  int resultCodeTranspose = s21_transpose(&A, &result);

  ck_assert_int_eq(resultCodeTranspose, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

START_TEST(s21_transpose_true_3) {
  matrix_t A;
  const int rows = 4;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[4][3] = {{-17.7442168, -48.5823665, -91.4641348},
                          {77.3216167, 96.7926044, -12.7023110},
                          {-81.4057943, -63.4716668, 31.3969032},
                          {69.4251863, 17.9638838, 30.1815726}};

  matrix_t expected;
  s21_create_matrix(columns, rows, &expected);

  double numbersExpected[3][4] = {
      {-17.7442168, 77.3216167, -81.4057943, 69.4251863},
      {-48.5823665, 96.7926044, -63.4716668, 17.9638838},
      {-91.4641348, -12.7023110, 31.3969032, 30.1815726}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[j][i] = numbersExpected[j][i];
    }
  }

  int resultCodeTranspose = s21_transpose(&A, &result);

  ck_assert_int_eq(resultCodeTranspose, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

START_TEST(s21_transpose_true_4) {
  matrix_t A;
  const int rows = 2;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[2][2] = {{20.46370, -83.65994}, {15.20652, -92.38261}};

  matrix_t expected;
  s21_create_matrix(columns, rows, &expected);

  double numbersExpected[2][2] = {{20.46370, 15.20652}, {-83.65994, -92.38261}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[j][i] = numbersExpected[j][i];
    }
  }

  int resultCodeTranspose = s21_transpose(&A, &result);

  ck_assert_int_eq(resultCodeTranspose, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

START_TEST(s21_transpose_true_5) {
  matrix_t A;
  const int rows = 6;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[6][3] = {{83.35, 41.81, 57.76},  {-70.01, 54.13, 83.62},
                          {12.72, -69.73, 39.71}, {74.98, -96.55, -67.80},
                          {51.62, 59.47, 78.57},  {12.13, -83.62, 29.14}};

  matrix_t expected;
  s21_create_matrix(columns, rows, &expected);

  double numbersExpected[3][6] = {{83.35, -70.01, 12.72, 74.98, 51.62, 12.13},
                                  {41.81, 54.13, -69.73, -96.55, 59.47, -83.62},
                                  {57.76, 83.62, 39.71, -67.80, 78.57, 29.14}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[j][i] = numbersExpected[j][i];
    }
  }

  int resultCodeTranspose = s21_transpose(&A, &result);

  ck_assert_int_eq(resultCodeTranspose, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

START_TEST(s21_transpose_true_6) {
  matrix_t A;
  const int rows = 1;
  const int columns = 5;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[1][5] = {{38.921, 75.764, 60.671, 40.409, 8.496}};

  matrix_t expected;
  s21_create_matrix(columns, rows, &expected);

  double numbersExpected[5][1] = {
      {38.921}, {75.764}, {60.671}, {40.409}, {8.496}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[j][i] = numbersExpected[j][i];
    }
  }

  int resultCodeTranspose = s21_transpose(&A, &result);

  ck_assert_int_eq(resultCodeTranspose, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

START_TEST(s21_transpose_true_7) {
  matrix_t A;
  const int rows = 2;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[2][3] = {{-16.2825126, 29.5949406, -25.6459816},
                          {4.4530272, 72.0944173, -64.4003044}};

  matrix_t expected;
  s21_create_matrix(columns, rows, &expected);

  double numbersExpected[3][2] = {{-16.2825126, 4.4530272},
                                  {29.5949406, 72.0944173},
                                  {-25.6459816, -64.4003044}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[j][i] = numbersExpected[j][i];
    }
  }

  int resultCodeTranspose = s21_transpose(&A, &result);

  ck_assert_int_eq(resultCodeTranspose, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

START_TEST(s21_transpose_true_8) {
  matrix_t A;
  const int rows = 7;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[7][3] = {
      {-18.3845, -12.0772, 77.6348}, {40.5512, 13.2210, -34.0012},
      {44.7051, 97.3223, 93.7960},   {-4.5210, -62.6992, -44.4500},
      {-72.9067, 33.7257, 73.7268},  {5.6401, -86.6188, 82.2083},
      {-70.3666, -65.2261, -81.5217}};

  matrix_t expected;
  s21_create_matrix(columns, rows, &expected);

  double numbersExpected[3][7] = {
      {-18.3845, 40.5512, 44.7051, -4.5210, -72.9067, 5.6401, -70.3666},
      {-12.0772, 13.2210, 97.3223, -62.6992, 33.7257, -86.6188, -65.2261},
      {77.6348, -34.0012, 93.7960, -44.4500, 73.7268, 82.2083, -81.5217}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[j][i] = numbersExpected[j][i];
    }
  }

  int resultCodeTranspose = s21_transpose(&A, &result);

  ck_assert_int_eq(resultCodeTranspose, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}

Suite *suite_s21_transpose_matrix() {
  Suite *suite = suite_create("s21_transpose_matrix");

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_transpose_false_1);
  tcase_add_test(testsFalse, s21_transpose_false_2);

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_transpose_true_1);
  tcase_add_test(testsTrue, s21_transpose_true_2);
  tcase_add_test(testsTrue, s21_transpose_true_3);
  tcase_add_test(testsTrue, s21_transpose_true_4);
  tcase_add_test(testsTrue, s21_transpose_true_5);
  tcase_add_test(testsTrue, s21_transpose_true_6);
  tcase_add_test(testsTrue, s21_transpose_true_7);
  tcase_add_test(testsTrue, s21_transpose_true_8);

  suite_add_tcase(suite, testsFalse);
  suite_add_tcase(suite, testsTrue);

  return suite;
}
