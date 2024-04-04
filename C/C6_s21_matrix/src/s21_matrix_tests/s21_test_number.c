#include "s21_test_matrix.h"

// Проверка на некорректные значения.
// При умножении на число в функцию подается неверная матрица.
// @return INCORRECT_MATRIX (1)

START_TEST(s21_mult_number_false_1) {
  // При умножении на число в функцию подается неверная матрица.
  matrix_t A;
  const int rows = 2;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.rows = 0;

  double number = 1.2;

  matrix_t result;

  int resultCode = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  A.rows = rows;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_false_2) {
  // При умножении на число в функцию подается неверная матрица.
  matrix_t A;
  const int rows = 5;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);
  A.columns = -2;

  double number = 4;

  matrix_t result;

  int resultCode = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  A.rows = rows;
  s21_remove_matrix(&A);
}
END_TEST

// Проверка на корректные данные.

START_TEST(s21_mult_number_true_1) {
  matrix_t A;
  double number = 3.9217;
  matrix_t result;
  const int rows = 1;
  const int columns = 1;
  s21_create_matrix(rows, columns, &A);

  double numbers[1][1] = {{935.14}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersdExpected[1][1] = {{3667.3385380}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersdExpected[i][j];
    }
  }

  int resultCode = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(resultCode, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_number_true_2) {
  matrix_t A;
  double number = 324.82438;
  matrix_t result;
  const int rows = 2;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);

  double numbers[2][2] = {{-644.0829, 681.8628}, {-782.3611, 854.8787}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersdExpected[2][2] = {{-209213.8286611, 221485.6612551},
                                   {-254129.9592436, 277685.4437027}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersdExpected[i][j];
    }
  }

  int resultCode = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(resultCode, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_number_true_3) {
  matrix_t A;
  double number = 220.9518;
  matrix_t result;
  const int rows = 3;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  double numbers[3][3] = {{371.171134, -652.798751, -876.153339},
                          {179.658105, 782.156107, -304.199893},
                          {-959.705658, -349.457250, -985.108056}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersdExpected[3][3] = {
      {82010.9301653, -144237.0590712, -193587.6573281},
      {39695.7816843, 172818.7997226, -67213.5139182},
      {-212048.6926053, -77213.2084105, -217661.3981677}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersdExpected[i][j];
    }
  }

  int resultCode = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(resultCode, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_number_true_4) {
  matrix_t A;
  double number = 2;
  matrix_t result;
  const int rows = 3;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);

  double numbers[3][3] = {{1, 2, 3}, {0, 4, 2}, {2, 3, 4}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersdExpected[3][3] = {{2, 4, 6}, {0, 8, 4}, {4, 6, 8}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersdExpected[i][j];
    }
  }

  int resultCode = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(resultCode, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_number_true_5) {
  matrix_t A;
  double number = -701.580842;
  matrix_t result;
  const int rows = 4;
  const int columns = 4;
  s21_create_matrix(rows, columns, &A);

  double numbers[4][4] = {{-889.350750, 128.267464, 45.411374, 327.441152},
                          {-818.658297, 450.541742, -843.796605, 207.924819},
                          {-210.637349, 865.181462, 328.059705, -939.274489},
                          {-37.156383, -892.584695, -90.896604, 605.586220}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersdExpected[4][4] = {
      {623951.4480183, -89989.9953943, -31859.7500073, -229726.4391256},
      {574354.9773195, -316091.4547085, 591991.5326126, -145876.0695867},
      {147779.1286681, -606994.7385928, -230160.4040602, 658976.9868617},
      {26068.2064708, 626220.3218744, 63771.3159693, -424867.6901312}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersdExpected[i][j];
    }
  }

  int resultCode = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(resultCode, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_number_true_6) {
  matrix_t A;
  double number = -251.8;
  matrix_t result;
  const int rows = 2;
  const int columns = 6;
  s21_create_matrix(rows, columns, &A);

  double numbers[2][6] = {
      {816.030, -469.686, -585.671, -616.958, 835.217, 451.261},
      {304.716, 530.392, -102.642, -176.209, 808.136, 211.958}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersdExpected[2][6] = {{-205476.3540, 118266.9348, 147471.9578,
                                    155350.0244, -210307.6406, -113627.5198},
                                   {-76727.4888, -133552.7056, 25845.2556,
                                    44369.4262, -203488.6448, -53371.0244}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersdExpected[i][j];
    }
  }

  int resultCode = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(resultCode, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_number_true_7) {
  matrix_t A;
  double number = 801;
  matrix_t result;
  const int rows = 3;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);

  double numbers[3][2] = {{216.3834547, 992.7366633},
                          {-365.4350735, 49.3584056},
                          {338.5723794, -824.8521728}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersdExpected[3][2] = {{173323.1472147, 795182.0673033},
                                   {-292713.4938735, 39536.0828856},
                                   {271196.4758994, -660706.5904128}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersdExpected[i][j];
    }
  }

  int resultCode = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(resultCode, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_mult_number_true_8) {
  matrix_t A;
  double number = 405.252;
  matrix_t result;
  const int rows = 4;
  const int columns = 1;
  s21_create_matrix(rows, columns, &A);

  double numbers[4][1] = {{632.057}, {-845.414}, {812.067}, {-2.936}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersdExpected[4][1] = {
      {256142.363364}, {-342605.714328}, {329091.775884}, {-1189.819872}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbers[i][j];
      expected.matrix[i][j] = numbersdExpected[i][j];
    }
  }

  int resultCode = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(resultCode, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *suite_s21_mult_number() {
  Suite *suite = suite_create("s21_mult_number");

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_mult_number_false_1);
  tcase_add_test(testsFalse, s21_mult_number_false_2);

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_mult_number_true_1);
  tcase_add_test(testsTrue, s21_mult_number_true_2);
  tcase_add_test(testsTrue, s21_mult_number_true_3);
  tcase_add_test(testsTrue, s21_mult_number_true_4);
  tcase_add_test(testsTrue, s21_mult_number_true_5);
  tcase_add_test(testsTrue, s21_mult_number_true_6);
  tcase_add_test(testsTrue, s21_mult_number_true_7);
  tcase_add_test(testsTrue, s21_mult_number_true_8);

  suite_add_tcase(suite, testsFalse);
  suite_add_tcase(suite, testsTrue);

  return suite;
}
