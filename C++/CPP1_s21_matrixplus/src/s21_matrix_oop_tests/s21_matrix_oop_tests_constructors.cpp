#include "s21_matrix_oop_tests.h"

// Проверка конструктора по умолчанию
TEST(S21MatrixTestConstructors, DefaultContructor) {
  S21Matrix matrix;
  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetCols(), 0);
}

// Проверка конструктора с параметрами и заполненность нулями
TEST(S21MatrixTestConstructors, ParamConstructor_1) {
  S21Matrix matrix(2, 5);
  EXPECT_EQ(matrix.GetRows(), 2);
  EXPECT_EQ(matrix.GetCols(), 5);
  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      EXPECT_EQ(matrix(i, j), 0.0);
    }
  }
}

// Проверка конструктора с параметрами и заполненность нулями
TEST(S21MatrixTestConstructors, ParamConstructor_2) {
  S21Matrix matrix(5, 1);
  EXPECT_EQ(matrix.GetRows(), 5);
  EXPECT_EQ(matrix.GetCols(), 1);
  for (int i = 0; i < matrix.GetRows(); i++) {
    for (int j = 0; j < matrix.GetCols(); j++) {
      EXPECT_EQ(matrix(i, j), 0.0);
    }
  }
}

// Проверка на некорректное создание матрицы с параметрами (отрицательные
// значения и нулевые значения)
TEST(S21MatrixTestConstructors, InvalidConstructor) {
  EXPECT_THROW(S21Matrix(-3, 2), std::length_error);
  EXPECT_THROW(S21Matrix(5, 0), std::length_error);
  EXPECT_THROW(S21Matrix(0, 0), std::length_error);
  EXPECT_THROW(S21Matrix(-7, -3), std::length_error);
  EXPECT_THROW(S21Matrix(0, -2), std::length_error);
}

// Проверка конструктора копирования
TEST(S21MatrixTestConstructors, CopyConstructor_1) {
  S21Matrix matrix_1(3, 3);
  const double numbers[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = numbers[i][j];
    }
  }

  S21Matrix matrix_2(matrix_1);

  EXPECT_EQ(matrix_2.GetRows(), 3);
  EXPECT_EQ(matrix_2.GetCols(), 3);
  EXPECT_EQ(matrix_2(0, 0), 1);
  EXPECT_EQ(matrix_2(0, 1), 2);
  EXPECT_EQ(matrix_2(0, 2), 3);
  EXPECT_EQ(matrix_2(1, 0), 4);
  EXPECT_EQ(matrix_2(1, 1), 5);
  EXPECT_EQ(matrix_2(1, 2), 6);
  EXPECT_EQ(matrix_2(2, 0), 7);
  EXPECT_EQ(matrix_2(2, 1), 8);
  EXPECT_EQ(matrix_2(2, 2), 9);
}

// Проверка конструктора копирования
TEST(S21MatrixTestConstructors, CopyConstructor_2) {
  S21Matrix matrix_1(1, 2);
  matrix_1(0, 0) = 4;
  matrix_1(0, 1) = 7;

  S21Matrix matrix_2(matrix_1);

  EXPECT_EQ(matrix_2.GetRows(), 1);
  EXPECT_EQ(matrix_2.GetCols(), 2);
  EXPECT_EQ(matrix_2(0, 0), 4);
  EXPECT_EQ(matrix_2(0, 1), 7);
}

// Проверка конструктора переноса
TEST(S21MatrixTestConstructors, MoveConstructor_1) {
  S21Matrix matrix_1(3, 3);
  const double numbers[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = numbers[i][j];
    }
  }

  S21Matrix matrix_2(std::move(matrix_1));

  EXPECT_EQ(matrix_2.GetRows(), 3);
  EXPECT_EQ(matrix_2.GetCols(), 3);
  EXPECT_EQ(matrix_2(0, 0), 1);
  EXPECT_EQ(matrix_2(0, 1), 2);
  EXPECT_EQ(matrix_2(0, 2), 3);
  EXPECT_EQ(matrix_2(1, 0), 4);
  EXPECT_EQ(matrix_2(1, 1), 5);
  EXPECT_EQ(matrix_2(1, 2), 6);
  EXPECT_EQ(matrix_2(2, 0), 7);
  EXPECT_EQ(matrix_2(2, 1), 8);
  EXPECT_EQ(matrix_2(2, 2), 9);

  EXPECT_EQ(matrix_1.GetRows(), 0);
  EXPECT_EQ(matrix_1.GetCols(), 0);
  EXPECT_THROW(matrix_1(0, 1), std::out_of_range);
}

TEST(S21MatrixTestConstructors, MoveConstructor_2) {
  S21Matrix matrix_1(4, 1);
  matrix_1(0, 0) = 3;
  matrix_1(1, 0) = -6.5;
  matrix_1(2, 0) = -2;
  matrix_1(3, 0) = 0;

  S21Matrix matrix_2(std::move(matrix_1));

  EXPECT_EQ(matrix_2.GetRows(), 4);
  EXPECT_EQ(matrix_2.GetCols(), 1);
  EXPECT_EQ(matrix_2(0, 0), 3);
  EXPECT_EQ(matrix_2(1, 0), -6.5);
  EXPECT_EQ(matrix_2(2, 0), -2);
  EXPECT_EQ(matrix_2(3, 0), 0);

  EXPECT_EQ(matrix_1.GetRows(), 0);
  EXPECT_EQ(matrix_1.GetCols(), 0);
  EXPECT_THROW(matrix_1(2, 0), std::out_of_range);
}

// Проверка деструктора
TEST(S21MatrixTestConstructors, Destructor) {
  S21Matrix* matrix = new S21Matrix(3, 3);
  EXPECT_NO_THROW(delete matrix);
}