#include "s21_matrix_oop_tests.h"

// Проверка на равенство, когда подаются матрицы разных размеров
TEST(S21MatrixTestCompare, CompareFalse_1) {
  S21Matrix matrix_1(2, 3);
  S21Matrix matrix_2(2, 4);

  bool result = matrix_1.EqMatrix(matrix_2);

  EXPECT_FALSE(result);
}

// Проверка на равенство, когда подаются матрицы разных размеров
TEST(S21MatrixTestCompare, CompareFalse_2) {
  S21Matrix matrix_1(6, 9);
  S21Matrix matrix_2(1, 8);

  bool result = matrix_1.EqMatrix(matrix_2);

  EXPECT_FALSE(result);
}

// Проверка на равенство, когда подаются равные друг другу матрицы
TEST(S21MatrixTestCompare, CompareTrue_1) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);
  const double numbers[2][2] = {{3, 22}, {34, -3}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      matrix_1(i, j) = numbers[i][j];
      matrix_2(i, j) = numbers[i][j];
    }
  }
  bool result = matrix_1.EqMatrix(matrix_2);

  EXPECT_TRUE(result);
}

// Проверка на равенство, когда подаются равные друг другу матрицы
TEST(S21MatrixTestCompare, CompareTrue_2) {
  S21Matrix matrix_1(2, 5);
  S21Matrix matrix_2(2, 5);
  const double numbers[2][5] = {{4, 23, 6, 86.2, 22}, {3, 22, 4.32, 9.1, 60}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      matrix_1(i, j) = numbers[i][j];
      matrix_2(i, j) = numbers[i][j];
    }
  }

  bool result = matrix_1.EqMatrix(matrix_2);

  EXPECT_TRUE(result);
}

// Проверка на равенство, когда подаются неравные друг другу матрицы
TEST(S21MatrixTestCompare, CompareFalse_3) {
  S21Matrix matrix_1(2, 1);
  S21Matrix matrix_2(2, 1);
  const double numbers_1[2][1] = {{2}, {43}};
  const double numbers_2[2][1] = {{2}, {44}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
      matrix_1(i, j) = numbers_1[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
      matrix_2(i, j) = numbers_2[i][j];
    }
  }

  bool result = matrix_1.EqMatrix(matrix_2);

  EXPECT_FALSE(result);
}

// Проверка на равенство, когда подаются неравные друг другу матрицы
TEST(S21MatrixTestCompare, CompareFalse_4) {
  S21Matrix matrix_1(4, 2);
  S21Matrix matrix_2(4, 2);

  matrix_1(2, 0) = 43;

  bool result = matrix_1.EqMatrix(matrix_2);

  EXPECT_FALSE(result);
}