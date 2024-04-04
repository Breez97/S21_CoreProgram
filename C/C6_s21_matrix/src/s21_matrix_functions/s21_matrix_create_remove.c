#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int errorCode = S21_OK;

  if (rows <= 0 || columns <= 0) {
    errorCode = S21_INCORRECT_MATRIX;
  }

  if (errorCode == S21_OK) {
    FillMatrixStruct(rows, columns, result, &errorCode);
  }

  return errorCode;
}

void FillMatrixStruct(int rows, int columns, matrix_t *A, int *errorCode) {
  A->rows = rows;
  A->columns = columns;
  A->matrix = malloc(rows * sizeof(double *));
  if (A->matrix != NULL) {
    for (int i = 0; i < rows && *errorCode == S21_OK; i++) {
      A->matrix[i] = malloc(columns * sizeof(double));
      if (A->matrix == NULL) {
        *errorCode = S21_INCORRECT_MATRIX;
        for (int j = 0; j < i; j++) {
          free(A->matrix[j]);
        }
        free(A->matrix);
      }
    }
  } else
    *errorCode = S21_INCORRECT_MATRIX;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}
