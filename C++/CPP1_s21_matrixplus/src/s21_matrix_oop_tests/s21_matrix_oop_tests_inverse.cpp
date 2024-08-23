#include "s21_matrix_oop_tests.h"

// Проверка вычисления обратной матрицы, когда подается некорректная матрица
TEST(S21MatrixTestInverse, InverseFalse_1) {
  S21Matrix matrix(3, 4);

  EXPECT_THROW(matrix.InverseMatrix(), std::logic_error);
}

// Проверка вычисления обратной матрицы, когда подается некорректная матрица
TEST(S21MatrixTestInverse, InverseFalse_2) {
  S21Matrix matrix(3, 3);
  const double numbers[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  EXPECT_THROW(matrix.InverseMatrix(), std::logic_error);
}

// Проверка вычисления обратной матрицы, когда подается корректная матрица
TEST(S21MatrixTestInverse, InverseTrue_1) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 2.5;

  S21Matrix result = matrix.InverseMatrix();

  S21Matrix expected(1, 1);
  expected(0, 0) = 0.4;

  EXPECT_DOUBLE_EQ(result(0, 0), expected(0, 0));
}

// Проверка вычисления обратной матрицы, когда подается корректная матрица
TEST(S21MatrixTestInverse, InverseTrue_2) {
  S21Matrix matrix(2, 2);
  const double numbers[2][2] = {{-149.09, 101.39}, {-1.46, -147.92}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  S21Matrix result = matrix.InverseMatrix();

  S21Matrix expected(2, 2);
  const double numbersExpected[2][2] = {{-0.0066626, -0.0045668},
                                        {0.0000658, -0.0067153}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      expected(i, j) = numbersExpected[i][j];
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_TRUE(fabs(result(i, j) - expected(i, j)) < EPS);
    }
  }
}

// Проверка вычисления обратной матрицы, когда подается корректная матрица
TEST(S21MatrixTestInverse, InverseTrue_3) {
  S21Matrix matrix(3, 3);
  const double numbers[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  S21Matrix result = matrix.InverseMatrix();

  S21Matrix expected(3, 3);
  const double numbersExpected[3][3] = {
      {1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      expected(i, j) = numbersExpected[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(result(i, j), expected(i, j));
    }
  }
}

// Проверка вычисления обратной матрицы, когда подается корректная матрица
TEST(S21MatrixTestInverse, InverseTrue_4) {
  S21Matrix matrix(4, 4);
  const double numbers[4][4] = {
      {234, 12, 32, 15}, {64, 2, 14, 21}, {3, 42, 2, 332}, {98, 65, 73, 13}};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  S21Matrix result = matrix.InverseMatrix();

  S21Matrix expected(4, 4);
  const double numbersExpected[4][34] = {
      {0.0077891, -0.0107987, 0.0003842, -0.0013539},
      {0.0276924, -0.1170698, 0.0057562, 0.0101549},
      {-0.0345149, 0.1162071, -0.0060537, 0.0067079},
      {-0.0033657, 0.0142076, 0.0023169, -0.0013128}};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      expected(i, j) = numbersExpected[i][j];
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      EXPECT_TRUE(fabs(result(i, j) - expected(i, j)) < EPS);
    }
  }
}