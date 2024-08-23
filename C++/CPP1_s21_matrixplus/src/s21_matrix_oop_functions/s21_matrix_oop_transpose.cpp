#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() const {
  S21Matrix resultMatrix(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      resultMatrix(j, i) = (*this)(i, j);
    }
  }
  return resultMatrix;
}