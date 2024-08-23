#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_) {
    throw std::logic_error(
        "CALC COMPLEMENT MATRIX ERROR: amount of rows not equal amount of "
        "columns (not square matrix)");
  }
  S21Matrix resultMatrix(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix tempMatrix(rows_ - 1, cols_ - 1);
      FillTempMatrix(i, j, tempMatrix);
      resultMatrix(i, j) = tempMatrix.Determinant() * pow(-1, i + j);
    }
  }
  return resultMatrix;
}