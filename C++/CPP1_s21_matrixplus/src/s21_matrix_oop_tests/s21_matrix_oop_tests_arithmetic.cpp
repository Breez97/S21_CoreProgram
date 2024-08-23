#include "s21_matrix_oop_tests.h"

// Проверка суммы матриц, когда подаются некорретные матрицы
TEST(S21MatrixTestArithmetic, SumMatrixFalse_1) {
  S21Matrix matrix_1(1, 2);
  S21Matrix matrix_2(3, 2);

  EXPECT_THROW(matrix_1.SumMatrix(matrix_2), std::logic_error);
}

// Проверка суммы матриц, когда подаются некорретные матрицы
TEST(S21MatrixTestArithmetic, SumMatrixFalse_2) {
  S21Matrix matrix_1(3, 7);
  S21Matrix matrix_2(1, 6);

  EXPECT_THROW(matrix_1.SumMatrix(matrix_2), std::logic_error);
}

// Проверка суммы матриц, когда подаются корректные матрицы
TEST(S21MatrixTestArithmetic, SumMatrixTrue_1) {
  S21Matrix matrix_1(1, 1);
  S21Matrix matrix_2(1, 1);

  matrix_1(0, 0) = 12;
  matrix_2(0, 0) = 14;

  matrix_1.SumMatrix(matrix_2);

  S21Matrix expected(1, 1);
  expected(0, 0) = 26;

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), expected(0, 0));
}

// Проверка суммы матриц, когда подаются корректные матрицы
TEST(S21MatrixTestArithmetic, SumMatrixTrue_2) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  const double numbers_1[3][3] = {{2, 4, -1}, {7, 3, 6}, {0, 5, 9}};
  const double numbers_2[3][3] = {{3, 12, 4}, {31, 8, 23}, {2, 1, 0}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = numbers_1[i][j];
      matrix_2(i, j) = numbers_2[i][j];
    }
  }

  matrix_1.SumMatrix(matrix_2);

  S21Matrix expected(3, 3);
  const double numbersExpected[3][3] = {{5, 16, 3}, {38, 11, 29}, {2, 6, 9}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      expected(i, j) = numbersExpected[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(matrix_1(i, j), expected(i, j));
    }
  }
}

// Проверка разницы матриц, когда подаются некорретные матрицы
TEST(S21MatrixTestArithmetic, SubMatrixFalse_1) {
  S21Matrix matrix_1(5, 12);
  S21Matrix matrix_2(5, 2);

  EXPECT_THROW(matrix_1.SubMatrix(matrix_2), std::logic_error);
}

// Проверка разницы матриц, когда подаются некорретные матрицы
TEST(S21MatrixTestArithmetic, SubMatrixFalse_2) {
  S21Matrix matrix_1(3, 1);
  S21Matrix matrix_2(4, 7);

  EXPECT_THROW(matrix_1.SubMatrix(matrix_2), std::logic_error);
}

// Проверка разницы матриц, когда подаются корректные матрицы
TEST(S21MatrixTestArithmetic, SubMatrisTrue_1) {
  S21Matrix matrix_1(1, 1);
  S21Matrix matrix_2(1, 1);

  matrix_1(0, 0) = 5;
  matrix_2(0, 0) = 8;

  matrix_1.SubMatrix(matrix_2);

  S21Matrix expected(1, 1);
  expected(0, 0) = -3;

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), expected(0, 0));
}

// Проверка разницы матриц, когда подаются корректные матрицы
TEST(S21MatrixTestArithmetic, SubMatrixTrue_2) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);
  const double numbers_1[2][2] = {{-4, 9}, {12, -2}};
  const double numbers_2[2][2] = {{6, 14}, {2, 1}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      matrix_1(i, j) = numbers_1[i][j];
      matrix_2(i, j) = numbers_2[i][j];
    }
  }

  matrix_1.SubMatrix(matrix_2);

  S21Matrix expected(2, 2);
  const double numbersExpected[2][2] = {{-10, -5}, {10, -3}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      expected(i, j) = numbersExpected[i][j];
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_DOUBLE_EQ(matrix_1(i, j), expected(i, j));
    }
  }
}

// Проверка произведения матриц, когда подаются некорректные матрицы
TEST(S21MatrixTestArithmetic, MulMatrixFalse_1) {
  S21Matrix matrix_1(7, 2);
  S21Matrix matrix_2(3, 1);

  EXPECT_THROW(matrix_1.MulMatrix(matrix_2), std::logic_error);
}

// Проверка произведения матриц, когда подаются некорректные матрицы
TEST(S21MatrixTestArithmetic, MulMatrixFalse_2) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(3, 2);

  EXPECT_THROW(matrix_1.MulMatrix(matrix_2), std::logic_error);
}

// Проверка произведения матриц, когда подаются корректные матрицы
TEST(S21MatrixTestArithmetic, MulMatrixTrue_1) {
  S21Matrix matrix_1(1, 1);
  S21Matrix matrix_2(1, 1);

  matrix_1(0, 0) = 4;
  matrix_2(0, 0) = 4;

  matrix_1.MulMatrix(matrix_2);

  S21Matrix expected(1, 1);
  expected(0, 0) = 16;

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), expected(0, 0));
}

// Проверка произведения матриц, когда подаются корректные матрицы
TEST(S21MatrixTestArithmetic, MulMatrixTrue_2) {
  S21Matrix matrix_1(3, 2);
  S21Matrix matrix_2(2, 3);
  const double numbers_1[3][2] = {{1, 4}, {2, 5}, {3, 6}};
  const double numbers_2[2][3] = {{1, -1, 1}, {2, 3, 4}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      matrix_1(i, j) = numbers_1[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_2(i, j) = numbers_2[i][j];
    }
  }

  matrix_1.MulMatrix(matrix_2);

  S21Matrix expected(3, 3);
  const double numbersExpected[3][3] = {
      {9, 11, 17}, {12, 13, 22}, {15, 15, 27}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      expected(i, j) = numbersExpected[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(matrix_1(i, j), expected(i, j));
    }
  }
}

// Проверка произведения матрицы на число
TEST(S21MatrixTestArithmetic, MulNumberMatrixTest_1) {
  S21Matrix matrix(1, 1);

  matrix(0, 0) = 6;

  matrix.MulNumber(2.5);

  S21Matrix expected(1, 1);
  expected(0, 0) = 15;

  EXPECT_DOUBLE_EQ(matrix(0, 0), expected(0, 0));
}

// Проверка произведения матрицы на число
TEST(S21MatrixTestArithmetic, MulNumberMatrixTest_2) {
  S21Matrix matrix(3, 3);
  const double numbers[3][3] = {{1, 2, 3}, {0, 4, 2}, {2, 3, 4}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  matrix.MulNumber(2);

  S21Matrix expected(3, 3);
  const double numbersExpected[3][3] = {{2, 4, 6}, {0, 8, 4}, {4, 6, 8}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      expected(i, j) = numbersExpected[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(matrix(i, j), expected(i, j));
    }
  }
}