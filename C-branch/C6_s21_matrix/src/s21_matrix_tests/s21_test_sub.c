#include "s21_test_matrix.h"

// Проверка на некорректные значения.
// 1. На вычитание подаются некорректные матрицы.
// 2. Матрицы отличаются размерами.
// @return
// для первого случая -> INCORRECT_MATRIX (1)
// для второго случая -> INCORRECT_CALC (2)

START_TEST(s21_sub_matrix_false_1) {
  // На вычитание подаются некорректные матрицы.
  matrix_t A;
  const int rowsA = 1;
  const int columnsA = 2;
  s21_create_matrix(rowsA, columnsA, &A);
  A.columns = 0;

  matrix_t B;
  const int rowsB = 1;
  const int columnsB = 2;
  s21_create_matrix(rowsB, columnsB, &B);

  matrix_t result;

  int resultCode = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  A.columns = columnsA;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_false_2) {
  // На вычитание подаются некорректные матрицы.
  matrix_t A;
  const int rowsA = 4;
  const int columnsA = 5;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 4;
  const int columnsB = 5;
  s21_create_matrix(rowsB, columnsB, &B);
  B.rows = 0;

  matrix_t result;

  int resultCode = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_MATRIX);

  B.rows = rowsB;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_false_3) {
  // Матрицы отличаются размерами.
  matrix_t A;
  const int rowsA = 6;
  const int columnsA = 1;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 6;
  const int columnsB = 2;
  s21_create_matrix(rowsB, columnsB, &B);

  matrix_t result;

  int resultCode = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_CALC);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_false_4) {
  // Матрицы отличаются размерами.
  matrix_t A;
  const int rowsA = 1;
  const int columnsA = 2;
  s21_create_matrix(rowsA, columnsA, &A);

  matrix_t B;
  const int rowsB = 4;
  const int columnsB = 5;
  s21_create_matrix(rowsB, columnsB, &B);

  matrix_t result;

  int resultCode = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCode, CHECK_INCORRECT_CALC);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// Проверка на корректные значения.

START_TEST(s21_sub_matrix_true_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  const int rows = 1;
  const int columns = 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[1][1] = {{464.364057}};
  double numbersB[1][1] = {{-365.864111}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[1][1] = {{830.228168}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeSub = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeSub, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_sub_matrix_true_2) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  const int rows = 2;
  const int columns = 2;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[2][2] = {{-837.7776, -540.1709}, {565.1774, -515.2874}};
  double numbersB[2][2] = {{-322.7124, -190.3712}, {-351.9367, -5.1150}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[2][2] = {{-515.0652, -349.7997},
                                  {917.1141, -510.1724}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeSub = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeSub, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_sub_matrix_true_3) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  const int rows = 5;
  const int columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[5][5] = {{-137.35, -178.68, -786.49, -904.03, 363.73},
                           {-355.97, 424.03, -486.28, -7.76, -89.04},
                           {929.12, 624.76, 299.75, -561.71, 521.90},
                           {388.78, 987.45, -854.29, -710.44, 590.20},
                           {-883.21, -240.15, 339.08, 418.87, -273.19}};
  double numbersB[5][5] = {
      {904.84150, 388.83325, -801.32524, -968.79299, -191.55252},
      {-576.34942, -584.82471, 674.11323, 982.27790, 760.76145},
      {648.98677, -489.83635, -726.59762, -95.61871, -600.94085},
      {-620.32737, -484.83008, 984.25521, 47.48588, -84.24448},
      {395.44279, 229.55092, 477.04520, -9.02048, -532.00532}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[5][5] = {
      {-1042.19150, -567.51325, 14.83524, 64.76299, 555.28252},
      {220.37942, 1008.85471, -1160.39323, -990.03790, -849.80145},
      {280.13323, 1114.59635, 1026.34762, -466.09129, 1122.84085},
      {1009.10737, 1472.28008, -1838.54521, -757.92588, 674.44448},
      {-1278.65279, -469.70092, -137.96520, 427.89048, 258.81532}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeSub = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeSub, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_sub_matrix_true_4) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  const int rows = 2;
  const int columns = 4;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[2][4] = {{248.2119, 506.2550, -778.0811, -625.8733},
                           {-270.8854, -281.6105, 105.5642, -813.5467}};
  double numbersB[2][4] = {{304.8237, 813.4474, -429.1825, 699.2310},
                           {-183.4056, 628.3511, 236.1007, -623.8791}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[2][4] = {{-56.6118, -307.1924, -348.8986, -1325.1043},
                                  {-87.4798, -909.9616, -130.5365, -189.6676}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeSub = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeSub, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_sub_matrix_true_5) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  const int rows = 6;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[6][3] = {
      {-534.20866, -941.30143, 897.90268}, {-932.55377, 849.68545, -526.04083},
      {-194.30167, -752.01529, 77.18824},  {-416.04832, 848.46883, -782.30983},
      {616.32305, 836.68405, 436.07177},   {680.84038, -264.64981, -661.11216}};
  double numbersB[6][3] = {{15, 169, 405},   {366, 749, -406},
                           {971, 873, -868}, {-251, -708, 850},
                           {158, 461, -248}, {-682, 779, 64}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[6][3] = {{-549.20866, -1110.30143, 492.90268},
                                  {-1298.55377, 100.68545, -120.04083},
                                  {-1165.30167, -1625.01529, 945.18824},
                                  {-165.04832, 1556.46883, -1632.30983},
                                  {458.32305, 375.68405, 684.07177},
                                  {1362.84038, -1043.64981, -725.11216}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeSub = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeSub, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(s21_sub_matrix_true_6) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  const int rows = 2;
  const int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  double numbersA[2][3] = {{-343.01, 140.26, -780.69},
                           {108.02, 977.82, -175.38}};
  double numbersB[2][3] = {{633.68, -379.60, 699.03},
                           {-217.19, 411.28, 185.91}};

  matrix_t expected;
  s21_create_matrix(rows, columns, &expected);

  double numbersExpected[2][3] = {{-976.69, 519.86, -1479.72},
                                  {325.21, 566.54, -361.29}};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = numbersA[i][j];
      B.matrix[i][j] = numbersB[i][j];
      expected.matrix[i][j] = numbersExpected[i][j];
    }
  }

  int resultCodeSub = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(resultCodeSub, CHECK_OK);

  int resultCodeEq = s21_eq_matrix(&result, &expected);

  ck_assert_int_eq(resultCodeEq, CHECK_SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *suite_s21_sub_matrix() {
  Suite *suite = suite_create("s21_sub_matrix");

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_sub_matrix_false_1);
  tcase_add_test(testsFalse, s21_sub_matrix_false_2);
  tcase_add_test(testsFalse, s21_sub_matrix_false_3);
  tcase_add_test(testsFalse, s21_sub_matrix_false_4);

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_sub_matrix_true_1);
  tcase_add_test(testsTrue, s21_sub_matrix_true_2);
  tcase_add_test(testsTrue, s21_sub_matrix_true_3);
  tcase_add_test(testsTrue, s21_sub_matrix_true_4);
  tcase_add_test(testsTrue, s21_sub_matrix_true_5);
  tcase_add_test(testsTrue, s21_sub_matrix_true_6);

  suite_add_tcase(suite, testsFalse);
  suite_add_tcase(suite, testsTrue);

  return suite;
}
