#include "s21_matrix_oop_tests.h"

// Проверка траспонирования матрицы
TEST(S21MatrixTestTranspose, Transpose_1) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 2;

  S21Matrix result = matrix.Transpose();

  S21Matrix expected(1, 1);
  expected(0, 0) = 2;

  EXPECT_DOUBLE_EQ(result(0, 0), expected(0, 0));
}

// Проверка траспонирования матрицы
TEST(S21MatrixTestTranspose, Transpose_2) {
  S21Matrix matrix(3, 2);
  const double numbers[3][2] = {{1, 4}, {2, 5}, {3, 6}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  S21Matrix result = matrix.Transpose();

  S21Matrix expected(2, 3);
  const double numbersExpected[2][3] = {{1, 2, 3}, {4, 5, 6}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      expected(i, j) = numbersExpected[i][j];
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(result(i, j), expected(i, j));
    }
  }
}

// Проверка траспонирования матрицы
TEST(S21MatrixTestTranspose, Transpose_3) {
  S21Matrix matrix(4, 3);
  const double numbers[4][3] = {{-17.7442168, -48.5823665, -91.4641348},
                                {77.3216167, 96.7926044, -12.7023110},
                                {-81.4057943, -63.4716668, 31.3969032},
                                {69.4251863, 17.9638838, 30.1815726}};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  S21Matrix result = matrix.Transpose();

  S21Matrix expected(3, 4);
  const double numbersExpected[3][4] = {
      {-17.7442168, 77.3216167, -81.4057943, 69.4251863},
      {-48.5823665, 96.7926044, -63.4716668, 17.9638838},
      {-91.4641348, -12.7023110, 31.3969032, 30.1815726}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      expected(i, j) = numbersExpected[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      EXPECT_DOUBLE_EQ(result(i, j), expected(i, j));
    }
  }
}