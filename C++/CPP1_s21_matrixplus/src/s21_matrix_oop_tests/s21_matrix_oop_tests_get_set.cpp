#include "s21_matrix_oop_tests.h"

// Проверка получения количества строк и столбцов через аксессоры
TEST(S21MatrixTestGetSet, GetTest_1) {
  S21Matrix matrix(3, 2);

  EXPECT_EQ(matrix.GetRows(), 3);
  EXPECT_EQ(matrix.GetCols(), 2);
}

// Проверка получения количества строк и столбцов через аксессоры
TEST(S21MatrixTestGetSet, GetTest_2) {
  S21Matrix matrix(5, 1);

  EXPECT_EQ(matrix.GetRows(), 5);
  EXPECT_EQ(matrix.GetCols(), 1);
}

// Проверка установки количества строк через мутатор, когда подается неверное
// число строк
TEST(S21MatrixTestGetSet, SetRows_1) {
  S21Matrix matrix(2, 5);

  EXPECT_THROW(matrix.SetRows(-3), std::length_error);
}

// Проверка установки количества строк через мутатор, когда подается верное
// число строк
TEST(S21MatrixTestGetSet, SetRows_2) {
  S21Matrix matrix(3, 2);

  matrix.SetRows(5);

  EXPECT_EQ(matrix.GetRows(), 5);
  EXPECT_EQ(matrix(4, 1), 0);
}

// Проверка установки количества строк через мутатор, когда подается верное
// число строк
TEST(S21MatrixTestGetSet, SetRows_3) {
  S21Matrix matrix(5, 4);

  matrix.SetRows(2);

  EXPECT_EQ(matrix.GetRows(), 2);
  EXPECT_THROW(matrix(4, 3), std::logic_error);
}

// Проверка установки количества столбцов через мутатор, когда подается неверное
// число столбцов
TEST(S21MatrixTestGetSet, SetCols_1) {
  S21Matrix matrix(1, 3);

  EXPECT_THROW(matrix.SetCols(0), std::length_error);
}

// Проверка установки количества столбцов через мутатор, когда подается неверное
// число столбцов
TEST(S21MatrixTestGetSet, SetCols_2) {
  S21Matrix matrix(2, 2);

  matrix.SetCols(5);

  EXPECT_EQ(matrix.GetCols(), 5);
  EXPECT_EQ(matrix(0, 4), 0);
}

// Проверка установки количества столбцов через мутатор, когда подается неверное
// число столбцов
TEST(S21MatrixTestGetSet, SetCols_3) {
  S21Matrix matrix(6, 7);

  matrix.SetCols(3);

  EXPECT_EQ(matrix.GetCols(), 3);
  EXPECT_THROW(matrix(4, 3), std::logic_error);
}