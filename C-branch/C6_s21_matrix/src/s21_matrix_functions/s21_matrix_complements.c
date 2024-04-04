#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int errorCode = S21_OK;

  if (CheckMatrix(A) != S21_OK) {
    errorCode = S21_INCORRECT_MATRIX;
  }

  if (errorCode == S21_OK) {
    if (A->rows == A->columns && A->rows > 1) {
      ComplementHandle(A, result, &errorCode);
    } else {
      errorCode = S21_INCORRECT_CALC;
    }
  }

  return errorCode;
}

void ComplementHandle(matrix_t *A, matrix_t *result, int *errorCode) {
  *errorCode = s21_create_matrix(A->rows, A->columns, result);
  if (*errorCode == S21_OK) {
    for (int i = 0; i < A->rows && *errorCode == S21_OK; i++) {
      for (int j = 0; j < A->columns && *errorCode == S21_OK; j++) {
        matrix_t tmpMatrix;
        *errorCode = s21_create_matrix(A->rows - 1, A->columns - 1, &tmpMatrix);
        if (*errorCode == S21_OK) {
          FillTmpMatrix(i, j, *A, &tmpMatrix);
          result->matrix[i][j] =
              CountDeterminant(&tmpMatrix, errorCode) * pow(-1, i + j);
          s21_remove_matrix(&tmpMatrix);
        }
      }
    }
  }
}
