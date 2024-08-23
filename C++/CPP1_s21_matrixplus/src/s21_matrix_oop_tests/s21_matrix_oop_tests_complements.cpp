#include "s21_matrix_oop_tests.h"

// Подсчет матрицы алгебраических дополнений, когда подается неверная матрица
TEST(S21MatrixTestComplements, ComplementsFalse_1) {
  S21Matrix matrix(3, 2);

  EXPECT_THROW(matrix.CalcComplements(), std::logic_error);
}

// Подсчет матрицы алгебраических дополнений, когда подается неверная матрица
TEST(S21MatrixTestComplements, ComplementsFalse_2) {
  S21Matrix matrix(6, 9);

  EXPECT_THROW(matrix.CalcComplements(), std::logic_error);
}

// Подсчет матрицы алгебраических дополнений, когда подается корректная матрица
TEST(S21MatrixTestComplements, ComplementsTrue_1) {
  S21Matrix matrix(2, 2);
  const double numbers[2][2] = {{74.8890, 89.8377}, {-90.4941, 45.6501}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  S21Matrix result = matrix.CalcComplements();

  S21Matrix expected(2, 2);
  const double numbersExpected[2][2] = {{45.6501, 90.4941}, {-89.8377, 74.889}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      expected(i, j) = numbersExpected[i][j];
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_DOUBLE_EQ(result(i, j), expected(i, j));
    }
  }
}

// Подсчет матрицы алгебраических дополнений, когда подается корректная матрица
TEST(S21MatrixTestComplements, ComplementsTrue_2) {
  S21Matrix matrix(3, 3);
  const double numbers[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  S21Matrix result = matrix.CalcComplements();

  S21Matrix expected(3, 3);
  const double numbersExpected[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
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

// Подсчет матрицы алгебраических дополнений, когда подается корректная матрица
TEST(S21MatrixTestComplements, ComplementsTrue_3) {
  S21Matrix matrix(3, 3);
  const double numbers[3][3] = {{60.720, 13.695, 82.377},
                                {17.944, -63.318, -34.025},
                                {36.136, -86.990, -78.965}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  S21Matrix result = matrix.CalcComplements();

  S21Matrix expected(3, 3);
  const double numbersExpected[3][3] = {
      {2040.07112, 187.42056, 727.110688},
      {-6084.549555, -7771.530072, 5776.91532},
      {4749.974511, 3544.170888, -4090.41204}};
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

// Подсчет матрицы алгебраических дополнений, когда подается корректная матрица
TEST(S21MatrixTestComplements, ComplementsTrue_4) {
  S21Matrix matrix(5, 5);
  const double numbers[5][5] = {{74, -64, 0, -34, -87},
                                {79, -18, -75, -5, 79},
                                {-90, 21, -41, 27, 72},
                                {-23, 54, 83, -33, -86},
                                {-97, -82, 31, -97, -49}};
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  S21Matrix result = matrix.CalcComplements();

  S21Matrix expected(5, 5);
  const double numbersExpected[5][5] = {
      {-12002050, 24710790, -103485420, -1199610, -80689220},
      {15178902, 42371102, -41775126, -68684576, 8583492},
      {-39720456, 59653564, -130173632, -16292032, -71301296},
      {-3499310, 75152910, -54477900, -59821210, -34882920},
      {-6441236, -19808476, 20726418, -27553422, 19861004}};
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      expected(i, j) = numbersExpected[i][j];
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      EXPECT_DOUBLE_EQ(result(i, j), expected(i, j));
    }
  }
}