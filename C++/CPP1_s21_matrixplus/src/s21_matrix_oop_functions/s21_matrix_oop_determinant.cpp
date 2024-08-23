#include "../s21_matrix_oop.h"

double S21Matrix::Determinant() const {
  if (rows_ != cols_) {
    throw std::logic_error(
        "COUNT DETERMINANT ERROR: Amount of rows not equal amount of columns "
        "(not square matrix)");
  }
  double result = 0.0;
  if (rows_ == 1) {
    result = (*this)(0, 0);
  } else {
    int sign = 1;
    for (int i = 0; i < cols_; i++) {
      S21Matrix tempMatrix(rows_ - 1, cols_ - 1);
      FillTempMatrix(0, i, tempMatrix);
      result += sign * (*this)(0, i) * tempMatrix.Determinant();
      sign *= -1;
    }
  }
  return result;
}