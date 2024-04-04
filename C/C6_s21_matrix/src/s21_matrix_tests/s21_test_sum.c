#include "s21_test_matrix.h"

// Проверка на некорректные значения.
// 1. На сложение подаются некорректные матрицы.
// 2. Матрицы отличаются размерами.
// @return
// для первого случая -> INCORRECT_MATRIX (1)
// для второго случая -> INCORRECT_CALC (2)

START_TEST(s21_sum_matrix_false_1) {
  // На сложение подаются некорректные матрицы.
  matrix_t A;
  const int rowsA = 2;
  const int columnsA = 2;
  s21_create_matrix(rowsA, columnsA, &A);
  A.rows = -2;

  matrix_t B;
  const int rowsB = 5;
  const int columnsB = 2;
  s21_create_matrix(rowsB, columnsB, &B);

  matrix_t result;

  int resultCode = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  A.rows = rowsA;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_false_2) {
  // На сложение подаются некорректные матрицы.
  matrix_t A;
  const int rowsA = 3;
  const int columnsA = 3;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 3;
  const int columnsB = 3;
  s21_create_matrix(rowsB, columnsB, &B);
  B.columns = 0;

  matrix_t result;

  int resultCode = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  B.columns = columnsB;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_false_3) {
  // Матрицы отличаются размерами.
  matrix_t A;
  const int rowsA = 3;
  const int columnsA = 4;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 3;
  const int columnsB = 2;
  s21_create_matrix(rowsB, columnsB, &B);

  matrix_t result;

  int resultCode = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_CALC);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_false_4) {
  // Матрицы отличаются размерами.
  matrix_t A;
  const int rowsA = 12;
  const int columnsA = 6;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 1;
  const int columnsB = 5;
  s21_create_matrix(rowsB, columnsB, &B);

  matrix_t result;

  int resultCode = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_CALC);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// Проверка на корректные значения.

START_TEST(s21_sum_matrix_true_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  const int rows = 1;
  const int columns = 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[1][1] = {{15.65605}};
  double numbersB[1][1] = {{18.05023}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[1][1] = {{33.70628}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeSum = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeSum, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_sum_matrix_true_2) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  const int rows = 2;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[2][2] = {{-5.92, 4.67}, {35.73, -29.26}};
  double numbersB[2][2] = {{71.87, -13.99}, {-40.22, -87.87}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[2][2] = {{65.95, -9.32}, {-4.49, -117.13}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeSum = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeSum, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_sum_matrix_true_3) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  const int rows = 3;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[3][3] = {{845.56804, 964.22131, 38.42916},
                           {683.62991, -309.85545, -316.40247},
                           {252.61442, -48.73787, 0.40921}};
  double numbersB[3][3] = {{-42.417706, -707.223542, -943.969167},
                           {-802.603905, -318.327120, -886.938035},
                           {282.790181, -503.689388, -736.932820}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[3][3] = {{803.150334, 256.997768, -905.540007},
                                  {-118.973995, -628.182570, -1203.340505},
                                  {535.404601, -552.427258, -736.523610}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeSum = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeSum, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_sum_matrix_true_4) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  const int rows = 4;
  const int columns = 4;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[4][4] = {{-169.749, -262.732, 672.151, -862.728},
                           {32.809, 818.445, -80.450, 761.612},
                           {-590.988, -624.360, -291.366, -228.837},
                           {-392.298, 62.563, 959.216, 885.577}};
  double numbersB[4][4] = {{-669.34, 819.28, 864.16, 493.80},
                           {465.76, 942.93, -245.38, 163.88},
                           {-175.48, 982.35, 285.36, -192.51},
                           {-490.71, -655.03, -460.83, 992.75}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[4][4] = {{-839.089, 556.548, 1536.311, -368.928},
                                  {498.569, 1761.375, -325.83, 925.492},
                                  {-766.468, 357.99, -6.006, -421.347},
                                  {-883.008, -592.467, 498.386, 1878.327}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeSum = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeSum, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_sum_matrix_true_5) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  const int rows = 1;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[1][3] = {{-592.2269036, 637.8023248, 623.6853993}};
  double numbersB[1][3] = {{-759.1953272, -540.3533170, -88.1647312}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[1][3] = {{-1351.4222308, 97.4490078, 535.5206681}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeSum = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeSum, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_sum_matrix_true_6) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  const int rows = 4;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[4][2] = {{-206.609, -734.950},
                           {-541.702, 900.980},
                           {-636.336, 623.379},
                           {37.238, -283.688}};
  double numbersB[4][2] = {{560.999, -913.516},
                           {-30.083, -187.304},
                           {-765.408, 457.860},
                           {349.164, -215.716}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[4][2] = {{354.390, -1648.466},
                                  {-571.785, 713.676},
                                  {-1401.744, 1081.239},
                                  {386.402, -499.404}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeSum = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeSum, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *suite_s21_sum_matrix() {
  Suite *suite = suite_create("s21_sum_matrix");

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_sum_matrix_false_1);
  tcase_add_test(testsFalse, s21_sum_matrix_false_2);
  tcase_add_test(testsFalse, s21_sum_matrix_false_3);
  tcase_add_test(testsFalse, s21_sum_matrix_false_4);

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_sum_matrix_true_1);
  tcase_add_test(testsTrue, s21_sum_matrix_true_2);
  tcase_add_test(testsTrue, s21_sum_matrix_true_3);
  tcase_add_test(testsTrue, s21_sum_matrix_true_4);
  tcase_add_test(testsTrue, s21_sum_matrix_true_5);
  tcase_add_test(testsTrue, s21_sum_matrix_true_6);

  suite_add_tcase(suite, testsFalse);
  suite_add_tcase(suite, testsTrue);

  return suite;
}
