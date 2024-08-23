#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() const {
  if (rows_ != cols_) {
    throw std::logic_error(
        "INVERSE MATRIX ERROR: Amount of rows not equal amount of columns (not "
        "square matrix)");
  }
  if (fabs(Determinant()) < EPS) {
    throw std::logic_error("INVERSE MATRIX ERROR: Determinant is equal to 0");
  }
  double determinant = Determinant();
  S21Matrix result(1, 1);
  if (rows_ == 1) {
    result(0, 0) = 1 / determinant;
  } else {
    S21Matrix complementsMatrix = CalcComplements();
    result = complementsMatrix.Transpose();
    result.MulNumber(1 / determinant);
  }
  return result;
}