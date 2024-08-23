#include "s21_matrix_oop_tests.h"

// Подсчет определителя, когда подается некорректная матрица
TEST(S21MatrixTestDeterminant, DeterminantFalse_1) {
  S21Matrix matrix(3, 5);

  EXPECT_THROW(matrix.Determinant(), std::logic_error);
}

// Подсчет определителя, когда подается некорректная матрица
TEST(S21MatrixTestDeterminant, DeterminantFalse_2) {
  S21Matrix matrix(4, 2);

  EXPECT_THROW(matrix.Determinant(), std::logic_error);
}

// Подсчет определите, когда подается корректная матрица
TEST(S21MatrixTestDeterminant, DeterminantTrue_1) {
  S21Matrix matrix(1, 1);

  matrix(0, 0) = 34;

  double result = matrix.Determinant();

  EXPECT_DOUBLE_EQ(result, 34);
}

// Подсчет определите, когда подается корректная матрица
TEST(S21MatrixTestDeterminant, DeterminantTrue_2) {
  S21Matrix matrix(2, 2);
  const double numbers[2][2] = {{9, 7}, {3, 2}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  double result = matrix.Determinant();

  EXPECT_DOUBLE_EQ(result, -3);
}

// Подсчет определите, когда подается корректная матрица
TEST(S21MatrixTestDeterminant, DeterminantTrue_3) {
  S21Matrix matrix(3, 3);
  const double numbers[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  double result = matrix.Determinant();

  EXPECT_DOUBLE_EQ(result, 0);
}

// Подсчет определите, когда подается корректная матрица
TEST(S21MatrixTestDeterminant, DeterminantTrue_4) {
  S21Matrix matrix(4, 4);
  const double numbers[4][4] = {{17, -171, -73, -139},
                                {-63, 17, -197, -42},
                                {-85, -46, -187, 152},
                                {67, 190, 10, 120}};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  double result = matrix.Determinant();

  EXPECT_DOUBLE_EQ(result, -860036381);
}