#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix resultMatrix = *this;
  resultMatrix.SumMatrix(other);
  return resultMatrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix resultMatrix = *this;
  resultMatrix.SubMatrix(other);
  return resultMatrix;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix resultMatrix = *this;
  resultMatrix.MulMatrix(other);
  return resultMatrix;
}

S21Matrix S21Matrix::operator*(const double number) const {
  S21Matrix resultMatrix = *this;
  resultMatrix.MulNumber(number);
  return resultMatrix;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  bool result = EqMatrix(other);
  return result;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) noexcept {
  if (this != &other) {
    S21Matrix temp(other);
    std::swap(rows_, temp.rows_);
    std::swap(cols_, temp.cols_);
    std::swap(matrix_, temp.matrix_);
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double number) {
  MulNumber(number);
  return *this;
}

double& S21Matrix::operator()(int row, int col) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}

const double& S21Matrix::operator()(int row, int col) const {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}