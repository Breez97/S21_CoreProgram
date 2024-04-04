#include "s21_test_matrix.h"

// Проверка на некорректные значения.
// 1. На вычисление подается некорректная матрица.
// 2. На вычисление подается не квадратная матрица (необходимо, чтобы была
// квадратная, потому что в противном случае нельзя будет найти определитель).
// @return
// для первого случая -> INCORRECT_MATRIX (1)
// для второго случая -> INCORRECT_CALC (2)

START_TEST(s21_complements_matrix_false_1) {
  // На вычисление подается некорректная матрицы.
  matrix_t A;
  const int rows = 3;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);
  A.rows = 0;
  A.columns = -12;

  matrix_t result;

  int resultCode = s21_calc_complements(&A, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  A.rows = rows;
  A.columns = columns;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_complements_matrix_false_3) {
  // На вычисление подается не квадратная матрица.
  matrix_t A;
  const int rows = 4;
  const int columns = 1;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  int resultCode = s21_calc_complements(&A, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_CALC);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_complements_matrix_false_4) {
  // На вычисление подается не квадратная матрица.
  matrix_t A;
  const int rows = 5;
  const int columns = 8;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  int resultCode = s21_calc_complements(&A, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_CALC);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_complements_matrix_false_2) {
  // На вычисление подаются некорректные матрицы.
  matrix_t A;
  const int rows = 3;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);
  A.columns = -3;

  matrix_t result;

  int resultCode = s21_calc_complements(&A, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  A.columns = columns;
  s21_remove_matrix(&A);
}
END_TEST

// Проверка на корректные значения.

START_TEST(s21_complements_matrix_true_1) {
  matrix_t A;
  const int rows = 3;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeComplement = s21_calc_complements(&A, &result);

  ck_assert_int_eq(resultCodeComplement, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_complements_matrix_true_2) {
  matrix_t A;
  const int rows = 2;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[2][2] = {{74.8890, 89.8377}, {-90.4941, 45.6501}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[2][2] = {{45.6501, 90.4941}, {-89.8377, 74.889}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeComplement = s21_calc_complements(&A, &result);

  ck_assert_int_eq(resultCodeComplement, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_complements_matrix_true_3) {
  matrix_t A;
  const int rows = 3;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[3][3] = {
      {62.32, -35.77, 81.82}, {64.14, -4.89, 8.62}, {23.69, 69.92, 35.96}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[3][3] = {{-778.5548, -2102.2666, 4600.5129},
                                  {7007.1436, 302.7114, -5204.8057},
                                  {91.7624, 4710.7364, 1989.543}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeComplement = s21_calc_complements(&A, &result);

  ck_assert_int_eq(resultCodeComplement, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_complements_matrix_true_4) {
  matrix_t A;
  const int rows = 3;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[3][3] = {{60.720, 13.695, 82.377},
                          {17.944, -63.318, -34.025},
                          {36.136, -86.990, -78.965}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[3][3] = {{2040.07112, 187.42056, 727.110688},
                                  {-6084.549555, -7771.530072, 5776.91532},
                                  {4749.974511, 3544.170888, -4090.41204}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeComplement = s21_calc_complements(&A, &result);

  ck_assert_int_eq(resultCodeComplement, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_complements_matrix_true_5) {
  matrix_t A;
  const int rows = 4;
  const int columns = 4;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[4][4] = {{11.62, 49.03, 11.03, -16.96},
                          {84.64, 45.03, -17.47, -42.62},
                          {-96.90, -68.31, 27.16, -99.62},
                          {67.40, 49.85, -95.83, 95.21}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[4][4] = {
      {-561596.221843, 950773.98217, -7415.131934, -107710.216912},
      {412381.011435, -179624.31567, -109107.668268, -307698.727914},
      {-294111.805214, 69764.353946, -481533.882646, -312992.430908},
      {-223174.154506, 161952.140992, -553999.945892, -45011.179582}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeComplement = s21_calc_complements(&A, &result);

  ck_assert_int_eq(resultCodeComplement, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_complements_matrix_true_6) {
  matrix_t A;
  const int rows = 5;
  const int columns = 5;
  s21_create_matrix(rows, columns, &A);

  matrix_t result;

  double numbers[5][5] = {{74, -64, 0, -34, -87},
                          {79, -18, -75, -5, 79},
                          {-90, 21, -41, 27, 72},
                          {-23, 54, 83, -33, -86},
                          {-97, -82, 31, -97, -49}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[5][5] = {
      {-12002050, 24710790, -103485420, -1199610, -80689220},
      {15178902, 42371102, -41775126, -68684576, 8583492},
      {-39720456, 59653564, -130173632, -16292032, -71301296},
      {-3499310, 75152910, -54477900, -59821210, -34882920},
      {-6441236, -19808476, 20726418, -27553422, 19861004}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeComplement = s21_calc_complements(&A, &result);

  ck_assert_int_eq(resultCodeComplement, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *suite_s21_complements_matrix() {
  Suite *suite = suite_create("s21_complement_matrix");

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_complements_matrix_false_1);
  tcase_add_test(testsFalse, s21_complements_matrix_false_2);
  tcase_add_test(testsFalse, s21_complements_matrix_false_3);
  tcase_add_test(testsFalse, s21_complements_matrix_false_4);

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_complements_matrix_true_1);
  tcase_add_test(testsTrue, s21_complements_matrix_true_2);
  tcase_add_test(testsTrue, s21_complements_matrix_true_3);
  tcase_add_test(testsTrue, s21_complements_matrix_true_4);
  tcase_add_test(testsTrue, s21_complements_matrix_true_5);
  tcase_add_test(testsTrue, s21_complements_matrix_true_6);

  suite_add_tcase(suite, testsFalse);
  suite_add_tcase(suite, testsTrue);

  return suite;
}
