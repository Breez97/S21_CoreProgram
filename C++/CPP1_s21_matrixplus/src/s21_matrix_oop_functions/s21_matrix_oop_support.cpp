#include "../s21_matrix_oop.h"

void S21Matrix::FillTempMatrix(int rowNumber, int colNumber,
                               S21Matrix& tempMatrix) const noexcept {
  int tempRow = 0;
  for (int i = 0; i < rows_; i++) {
    if (i != rowNumber) {
      int tempCol = 0;
      for (int j = 0; j < cols_; j++) {
        if (j != colNumber) {
          tempMatrix(tempRow, tempCol) = (*this)(i, j);
          tempCol++;
        }
      }
      tempRow++;
    }
  }
}

void S21Matrix::AllocateMemory() {
  matrix_ = new double*[rows_];
  if (matrix_ == nullptr) {
    throw std::bad_alloc();
  }
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_]();
    if (matrix_[i] == nullptr) {
      for (int j = 0; j < i; ++j) {
        delete[] matrix_[j];
      }
      delete[] matrix_;
      throw std::bad_alloc();
    }
  }
}

void S21Matrix::DeallocateMemory() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
}