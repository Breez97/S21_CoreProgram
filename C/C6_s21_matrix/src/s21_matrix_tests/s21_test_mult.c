#include "s21_test_matrix.h"

// Проверка на некорректные значения.
// 1. На умножение подаются некорректные матрицы.
// 2. Число столбцов первой матрицы не равно числу строк второй матрицы.
// @return
// для первого случая -> INCORRECT_MATRIX (1)
// для второго случая -> INCORRECT_CALC (2)

START_TEST(s21_mult_matrix_false_1) {
  // На умножение подаются некорректные матрицы.
  matrix_t A;
  const int rowsA = 2;
  const int columnsA = 3;
  s21_create_matrix(rowsA, columnsA, &A);
  A.rows = -1;

  matrix_t B;
  const int rowsB = 3;
  const int columnsB = 1;
  s21_create_matrix(rowsB, columnsB, &B);

  matrix_t result;

  int resultCode = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  A.rows = rowsA;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_false_2) {
  // На умножение подаются некорректные матрицы.
  matrix_t A;
  const int rowsA = 1;
  const int columnsA = 3;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 7;
  const int columnsB = 2;
  s21_create_matrix(rowsB, columnsB, &B);
  B.columns = 0;

  matrix_t result;

  int resultCode = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  B.columns = columnsB;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_false_3) {
  // Число столбцов первой матрицы не равно числу строк второй матрицы.
  matrix_t A;
  const int rowsA = 7;
  const int columnsA = 3;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 4;
  const int columnsB = 1;
  s21_create_matrix(rowsB, columnsB, &B);

  matrix_t result;

  int resultCode = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_CALC);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_false_4) {
  // Число столбцов первой матрицы не равно числу строк второй матрицы.
  matrix_t A;
  const int rowsA = 4;
  const int columnsA = 4;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 9;
  const int columnsB = 5;
  s21_create_matrix(rowsB, columnsB, &B);

  matrix_t result;

  int resultCode = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_CALC);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// Проверка на корректные значения.

START_TEST(s21_mult_matrix_true_1) {
  matrix_t A;
  const int rowsA = 3;
  const int columnsA = 2;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 2;
  const int columnsB = 5;
  s21_create_matrix(rowsB, columnsB, &B);

  double numbersA[3][2] = {{5, 68}, {85, 91}, {53, -83}};
  double numbersB[2][5] = {{47, -28, -41, 33, 49}, {-44, 11, 9, 91, -91}};

  matrix_t result;

  matrix_t expected;
  s21_create_matrix(rowsA, columnsB, &expected);

  double numbersExpected[3][5] = {{-2757, 608, 407, 6353, -5943},
                                  {-9, -1379, -2666, 11086, -4116},
                                  {6143, -2397, -2920, -5804, 10150}};

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsA; j++) {
      A.matrix[i][j] = numbersA[i][j];
    }
  }

  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < columnsB; j++) {
      B.matrix[i][j] = numbersB[i][j];
    }
  }

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsB; j++) {
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeMult = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeMult, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_matrix_true_2) {
  matrix_t A;
  const int rowsA = 1;
  const int columnsA = 3;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 3;
  const int columnsB = 2;
  s21_create_matrix(rowsB, columnsB, &B);

  double numbersA[1][3] = {{-24.6769, 94.9646, 50.2505}};
  double numbersB[3][2] = {
      {-81.23886, 59.68876}, {57.38335, -95.25866}, {66.85369, 48.13493}};

  matrix_t result;

  matrix_t expected;
  s21_create_matrix(rowsA, columnsB, &expected);

  double numbersExpected[1][2] = {{10813.5414531, -8100.3298051}};

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsA; j++) {
      A.matrix[i][j] = numbersA[i][j];
    }
  }

  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < columnsB; j++) {
      B.matrix[i][j] = numbersB[i][j];
    }
  }

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsB; j++) {
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeMult = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeMult, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_matrix_true_3) {
  matrix_t A;
  const int rowsA = 3;
  const int columnsA = 4;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 4;
  const int columnsB = 1;
  s21_create_matrix(rowsB, columnsB, &B);

  double numbersA[3][4] = {{53.1736296, 78.4644751, -4.8520482, 42.5341409},
                           {-31.3821174, 96.9178704, -19.7790362, -56.9191809},
                           {83.2691605, -79.3246560, 90.4134277, -58.9073213}};
  double numbersB[4][1] = {{-96.3179}, {-83.1610}, {-67.9238}, {-4.0971}};

  matrix_t result;

  matrix_t expected;
  s21_create_matrix(rowsA, columnsB, &expected);

  double numbersExpected[3][1] = {
      {-11491.4536294}, {-3460.4564997}, {-7323.4673508}};

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsA; j++) {
      A.matrix[i][j] = numbersA[i][j];
    }
  }

  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < columnsB; j++) {
      B.matrix[i][j] = numbersB[i][j];
    }
  }

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsB; j++) {
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeMult = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeMult, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_matrix_true_4) {
  matrix_t A;
  const int rowsA = 3;
  const int columnsA = 2;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 2;
  const int columnsB = 3;
  s21_create_matrix(rowsB, columnsB, &B);

  double numbersA[3][2] = {{1, 4}, {2, 5}, {3, 6}};
  double numbersB[2][3] = {{1, -1, 1}, {2, 3, 4}};

  matrix_t result;

  matrix_t expected;
  s21_create_matrix(rowsA, columnsB, &expected);

  double numbersExpected[3][3] = {{9, 11, 17}, {12, 13, 22}, {15, 15, 27}};

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsA; j++) {
      A.matrix[i][j] = numbersA[i][j];
    }
  }

  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < columnsB; j++) {
      B.matrix[i][j] = numbersB[i][j];
    }
  }

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsB; j++) {
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeMult = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeMult, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_matrix_true_5) {
  matrix_t A;
  const int rowsA = 2;
  const int columnsA = 2;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 2;
  const int columnsB = 2;
  s21_create_matrix(rowsB, columnsB, &B);

  double numbersA[2][2] = {{-30.591, -85.917}, {81.332, 36.722}};
  double numbersB[2][2] = {{75.002, -80.033}, {62.534, -61.553}};

  matrix_t result;

  matrix_t expected;
  s21_create_matrix(rowsA, columnsB, &expected);

  double numbersExpected[2][2] = {{-7667.11986, 7736.738604},
                                  {8396.436212, -8769.593222}};

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsA; j++) {
      A.matrix[i][j] = numbersA[i][j];
    }
  }

  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < columnsB; j++) {
      B.matrix[i][j] = numbersB[i][j];
    }
  }

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsB; j++) {
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeMult = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeMult, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_matrix_true_6) {
  matrix_t A;
  const int rowsA = 5;
  const int columnsA = 1;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 1;
  const int columnsB = 3;
  s21_create_matrix(rowsB, columnsB, &B);

  double numbersA[5][1] = {
      {12.97775}, {78.19946}, {-73.88710}, {94.92632}, {34.36619}};
  double numbersB[1][3] = {{39.4590155, -77.7867329, 87.2936071}};

  matrix_t result;

  matrix_t expected;
  s21_create_matrix(rowsA, columnsB, &expected);

  double numbersExpected[5][3] = {{512.0892384, -1009.4967729, 1132.8746095},
                                  {3085.6737042, -6082.8805079, 6826.3129367},
                                  {-2915.5122242, 5747.4361125, -6449.8714772},
                                  {3745.6991322, -7384.0082990, 8286.4608815},
                                  {1356.0560239, -2673.2336423, 2999.9486874}};

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsA; j++) {
      A.matrix[i][j] = numbersA[i][j];
    }
  }

  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < columnsB; j++) {
      B.matrix[i][j] = numbersB[i][j];
    }
  }

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsB; j++) {
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeMult = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeMult, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *suite_s21_mult_matrix() {
  Suite *suite = suite_create("S21_mult_matrix");

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_mult_matrix_false_1);
  tcase_add_test(testsFalse, s21_mult_matrix_false_2);
  tcase_add_test(testsFalse, s21_mult_matrix_false_3);
  tcase_add_test(testsFalse, s21_mult_matrix_false_4);

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_mult_matrix_true_1);
  tcase_add_test(testsTrue, s21_mult_matrix_true_2);
  tcase_add_test(testsTrue, s21_mult_matrix_true_3);
  tcase_add_test(testsTrue, s21_mult_matrix_true_4);
  tcase_add_test(testsTrue, s21_mult_matrix_true_5);
  tcase_add_test(testsTrue, s21_mult_matrix_true_6);

  suite_add_tcase(suite, testsFalse);
  suite_add_tcase(suite, testsTrue);

  return suite;
}
