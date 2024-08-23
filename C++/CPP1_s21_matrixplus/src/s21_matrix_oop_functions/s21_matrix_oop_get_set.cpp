#include "../s21_matrix_oop.h"

int S21Matrix::GetRows() const noexcept { return rows_; }

int S21Matrix::GetCols() const noexcept { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows < 1) {
    throw std::length_error(
        "CHANGE ROWS ERROR: amount of rows must be grater than zero");
  }
  if (rows != rows_) {
    S21Matrix tempMatrix(rows, cols_);
    int minRows = std::min(rows_, rows);
    for (int i = 0; i < minRows; i++) {
      for (int j = 0; j < cols_; j++) {
        tempMatrix(i, j) = (*this)(i, j);
      }
    }
    *this = tempMatrix;
  }
}

void S21Matrix::SetCols(int cols) {
  if (cols < 1) {
    throw std::length_error(
        "CHANGE COLS ERROR: amount of columns must be grater than zero");
  }
  if (cols != cols_) {
    S21Matrix tempMatrix(rows_, cols);
    int minCols = std::min(cols_, cols);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < minCols; j++) {
        tempMatrix(i, j) = (*this)(i, j);
      }
    }
    *this = tempMatrix;
  }
}
