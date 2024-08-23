#include "s21_matrix_oop_tests.h"

// Проверка перегруженного оператора +
TEST(S21MatrixTestOperators, SumOperator_1) {
  S21Matrix matrix_1(1, 2);
  S21Matrix matrix_2(3, 2);

  EXPECT_THROW(matrix_1 + matrix_2, std::logic_error);
}

// Проверка перегруженного оператора +
TEST(S21MatrixTestOperators, SumOperator_2) {
  S21Matrix matrix_1(1, 1);
  S21Matrix matrix_2(1, 1);

  matrix_1(0, 0) = 12;
  matrix_2(0, 0) = 14;

  S21Matrix result = matrix_1 + matrix_2;

  S21Matrix expected(1, 1);
  expected(0, 0) = 26;

  EXPECT_DOUBLE_EQ(result(0, 0), expected(0, 0));
}

// Проверка перегруженного оператора +
TEST(S21MatrixTestOperators, SumOperator_3) {
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

  S21Matrix result = matrix_1 + matrix_2;

  S21Matrix expected(3, 3);
  const double numbersExpected[3][3] = {{5, 16, 3}, {38, 11, 29}, {2, 6, 9}};
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

// Проверка перегружженого оператора -
TEST(S21MatrixTestOperators, SubOperator_1) {
  S21Matrix matrix_1(5, 12);
  S21Matrix matrix_2(5, 2);

  EXPECT_THROW(matrix_1 - matrix_2, std::logic_error);
}

// Проверка перегружженого оператора -
TEST(S21MatrixTestOperators, SubOperator_2) {
  S21Matrix matrix_1(1, 1);
  S21Matrix matrix_2(1, 1);

  matrix_1(0, 0) = 5;
  matrix_2(0, 0) = 8;

  S21Matrix result = matrix_1 - matrix_2;

  S21Matrix expected(1, 1);
  expected(0, 0) = -3;

  EXPECT_DOUBLE_EQ(result(0, 0), expected(0, 0));
}

// Проверка перегружженого оператора -
TEST(S21MatrixTestOperators, SubOperator_3) {
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

  S21Matrix result = matrix_1 - matrix_2;

  S21Matrix expected(2, 2);
  const double numbersExpected[2][2] = {{-10, -5}, {10, -3}};
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

// Проверка перегружженого оператора * (умножение матриц)
TEST(S21MatrixTestOperators, MulOperator_1) {
  S21Matrix matrix_1(7, 2);
  S21Matrix matrix_2(3, 1);

  EXPECT_THROW(matrix_1 * matrix_2, std::logic_error);
}

// Проверка перегружженого оператора * (умножение матриц)
TEST(S21MatrixTestOperators, MulOperator_2) {
  S21Matrix matrix_1(1, 1);
  S21Matrix matrix_2(1, 1);

  matrix_1(0, 0) = 4;
  matrix_2(0, 0) = 4;

  S21Matrix result = matrix_1 * matrix_2;

  S21Matrix expected(1, 1);
  expected(0, 0) = 16;

  EXPECT_DOUBLE_EQ(result(0, 0), expected(0, 0));
}

// Проверка перегружженого оператора * (умножение матриц)
TEST(S21MatrixTestOperators, MulOperator_3) {
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

  S21Matrix result = matrix_1 * matrix_2;

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
      EXPECT_DOUBLE_EQ(result(i, j), expected(i, j));
    }
  }
}

// Проверка перегружженого оператора * (умножение матрицы на число)
TEST(S21MatrixTestOperators, MulNumberOperator_1) {
  S21Matrix matrix(1, 1);

  matrix(0, 0) = 6;

  S21Matrix result = matrix * 2.5;

  S21Matrix expected(1, 1);
  expected(0, 0) = 15;

  EXPECT_DOUBLE_EQ(result(0, 0), expected(0, 0));
}

// Проверка перегружженого оператора * (умножение матрицы на число)
TEST(S21MatrixTestOperators, MulNumberOperator_2) {
  S21Matrix matrix(3, 3);
  const double numbers[3][3] = {{1, 2, 3}, {0, 4, 2}, {2, 3, 4}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  S21Matrix result = matrix * 2;

  S21Matrix expected(3, 3);
  const double numbersExpected[3][3] = {{2, 4, 6}, {0, 8, 4}, {4, 6, 8}};
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

// Провека перегруженного оператора ==
TEST(S21MatrixTestOperators, EqualOperator_1) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = i + j;
      matrix_2(i, j) = i + j;
    }
  }

  EXPECT_TRUE(matrix_1 == matrix_2);
  EXPECT_TRUE(matrix_2 == matrix_1);
}

// Провека перегруженного оператора ==
TEST(S21MatrixTestOperators, EqualOperator_2) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = i + j;
      matrix_2(i, j) = i - j;
    }
  }

  EXPECT_FALSE(matrix_1 == matrix_2);
  EXPECT_FALSE(matrix_2 == matrix_1);
}

// Проверка перегруженного оператора =
TEST(S21MatrixTestOperators, AssignmentOperator_1) {
  S21Matrix matrix_1(3, 3);
  matrix_1(0, 0) = 0;
  matrix_1(1, 1) = 1;
  matrix_1(2, 2) = 2;

  S21Matrix matrix_2;
  matrix_2 = matrix_1;

  EXPECT_EQ(matrix_2.GetRows(), 3);
  EXPECT_EQ(matrix_2.GetCols(), 3);
  EXPECT_DOUBLE_EQ(matrix_1(0, 0), 0);
  EXPECT_DOUBLE_EQ(matrix_1(1, 1), 1);
  EXPECT_DOUBLE_EQ(matrix_1(2, 2), 2);
}

// Проверка перегруженного оператора =
TEST(S21MatrixTestOperators, AssignmentOperator_2) {
  S21Matrix matrix_1(3, 3);
  const double numbers[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = numbers[i][j];
    }
  }

  S21Matrix matrix_2;
  matrix_2 = matrix_1;

  S21Matrix expected(3, 3);
  const double numbersExpected[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      expected(i, j) = numbersExpected[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(matrix_2(i, j), expected(i, j));
    }
  }
}

// Проверка перегруженного оператора +=
TEST(S21MatrixTestOperators, SumEqualOperator_1) {
  S21Matrix matrix_1(3, 7);
  S21Matrix matrix_2(1, 6);

  EXPECT_THROW(matrix_1 += matrix_2, std::logic_error);
}

// Проверка перегруженного оператора +=
TEST(S21MatrixTestOperators, SumEqualOperator_2) {
  S21Matrix matrix_1(1, 1);
  S21Matrix matrix_2(1, 1);

  matrix_1(0, 0) = 12;
  matrix_2(0, 0) = 14;

  matrix_1 += matrix_2;

  S21Matrix expected(1, 1);
  expected(0, 0) = 26;

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), expected(0, 0));
}

// Проверка перегруженного оператора +=
TEST(S21MatrixTestOperators, SumEqualOperator_3) {
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

  matrix_1 += matrix_2;

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

// Проверка перегруженного оператора -=
TEST(S21MatrixTestOperators, SubEqualOperator_1) {
  S21Matrix matrix_1(3, 1);
  S21Matrix matrix_2(4, 7);

  EXPECT_THROW(matrix_1 -= matrix_2, std::logic_error);
}

// Проверка перегруженного оператора -=
TEST(S21MatrixTestOperators, SubEqualOperator_2) {
  S21Matrix matrix_1(1, 1);
  S21Matrix matrix_2(1, 1);

  matrix_1(0, 0) = 5;
  matrix_2(0, 0) = 8;

  matrix_1 -= matrix_2;

  S21Matrix expected(1, 1);
  expected(0, 0) = -3;

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), expected(0, 0));
}

// Проверка перегруженного оператора -=
TEST(S21MatrixTestOperators, SubEqualOperator_3) {
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

  matrix_1 -= matrix_2;

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

// Проверка перегруженного оператора *= (умножение матриц)
TEST(S21MatrixTestOperators, MulEqualOperator_1) {
  S21Matrix matrix_1(7, 2);
  S21Matrix matrix_2(3, 1);

  EXPECT_THROW(matrix_1 *= matrix_2, std::logic_error);
}

// Проверка перегруженного оператора *= (умножение матриц)
TEST(S21MatrixTestOperators, MulEqualOperator_2) {
  S21Matrix matrix_1(1, 1);
  S21Matrix matrix_2(1, 1);

  matrix_1(0, 0) = 4;
  matrix_2(0, 0) = 4;

  matrix_1 *= matrix_2;

  S21Matrix expected(1, 1);
  expected(0, 0) = 16;

  EXPECT_DOUBLE_EQ(matrix_1(0, 0), expected(0, 0));
}

// Проверка перегруженного оператора *= (умножение матриц)
TEST(S21MatrixTestOperators, MulEqualOperator_3) {
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

  matrix_1 *= matrix_2;

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

// Проверка перегруженного оператора *= (умножение матрицы на число)
TEST(S21MatrixTestOperators, MulNumberEqualOperator_1) {
  S21Matrix matrix(1, 1);

  matrix(0, 0) = 6;

  matrix *= 2.5;

  S21Matrix expected(1, 1);
  expected(0, 0) = 15;

  EXPECT_DOUBLE_EQ(matrix(0, 0), expected(0, 0));
}

// Проверка перегруженного оператора *= (умножение матрицы на число)
TEST(S21MatrixTestOperators, MulNumberEqualOperator_2) {
  S21Matrix matrix(3, 3);
  const double numbers[3][3] = {{1, 2, 3}, {0, 4, 2}, {2, 3, 4}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix(i, j) = numbers[i][j];
    }
  }

  matrix *= 2;

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

// Проверка перегруженного оператора (int i, int j) (запись и чтение)
TEST(S21MatrixTestOperators, IndexOperator_1) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 0;
  matrix(1, 1) = 1;
  matrix(2, 2) = 2;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 1);
  EXPECT_DOUBLE_EQ(matrix(2, 2), 2);
}

// Проверка перегруженного оператора (int i, int j) (запись и чтение)
TEST(S21MatrixTestOperators, IndexOperator_2) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 0;
  matrix(1, 1) = 1;
  matrix(2, 2) = 2;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 1);
  EXPECT_DOUBLE_EQ(matrix(2, 2), 2);

  matrix(0, 0) = 10;
  matrix(1, 1) = 11;
  matrix(2, 2) = 12;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 10);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 11);
  EXPECT_DOUBLE_EQ(matrix(2, 2), 12);
}

// Проверка перегруженного оператора (int i, int j) (чтение для const объекта)
TEST(S21MatrixTestOperators, IndexOperator_3) {
  const S21Matrix matrix(3, 3);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 0);
  EXPECT_DOUBLE_EQ(matrix(2, 2), 0);
}

// Проверка перегруженного оператора (int i, int j) (выход за границы)
TEST(S21MatrixTestOperators, IndexOperator_4) {
  S21Matrix matrix(3, 3);

  EXPECT_THROW(matrix(5, 6), std::out_of_range);
  EXPECT_THROW(matrix(1, 7), std::out_of_range);
  EXPECT_THROW(matrix(3, 0), std::out_of_range);
}

// Проверка перегруженного оператора (int i, int j) (выход за границы)
TEST(S21MatrixTestOperators, IndexOperator_5) {
  const S21Matrix matrix(3, 3);

  EXPECT_THROW(matrix(5, 6), std::out_of_range);
  EXPECT_THROW(matrix(1, 7), std::out_of_range);
  EXPECT_THROW(matrix(3, 0), std::out_of_range);
}