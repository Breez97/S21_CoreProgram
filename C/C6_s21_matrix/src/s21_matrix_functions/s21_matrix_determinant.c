#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int errorCode = S21_OK;

  if (CheckMatrix(A) != S21_OK) {
    errorCode = S21_INCORRECT_MATRIX;
  }

  if (errorCode == S21_OK) {
    *result = 0.0;
    if (A->rows == A->columns) {
      *result = CountDeterminant(A, &errorCode);
    } else {
      errorCode = S21_INCORRECT_MATRIX;
    }
  }

  return errorCode;
}

double CountDeterminant(matrix_t *A, int *errorCode) {
  double result = 0.0;
  matrix_t tmpMatrix;

  if (A->rows == 1) {
    result = A->matrix[0][0];
  } else {
    int sign = 1;
    for (int i = 0; i < A->columns; i++) {
      *errorCode = s21_create_matrix(A->rows - 1, A->columns - 1, &tmpMatrix);
      if (*errorCode == S21_OK) {
        FillTmpMatrix(0, i, *A, &tmpMatrix);
        result +=
            sign * A->matrix[0][i] * CountDeterminant(&tmpMatrix, errorCode);
        sign *= -1;
        s21_remove_matrix(&tmpMatrix);
      }
    }
  }

  return result;
}
