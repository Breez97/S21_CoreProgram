#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int errorCode = S21_OK;

  if (CheckMatrix(A) != S21_OK) {
    errorCode = S21_INCORRECT_MATRIX;
  }

  if (errorCode == S21_OK) {
    errorCode = s21_create_matrix(A->columns, A->rows, result);
    if (errorCode == S21_OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  }

  return errorCode;
}
