#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int resultCompare = SUCCESS;

  if (CheckMatrix(A) != S21_OK || CheckMatrix(B) != S21_OK) {
    resultCompare = FAILURE;
  }

  if (resultCompare == SUCCESS) {
    CompareMatrices(A, B, &resultCompare);
  }

  return resultCompare;
}

void CompareMatrices(matrix_t *A, matrix_t *B, int *resultCompare) {
  if (A->rows == B->rows && A->columns == B->columns) {
    CompareHandle(A, B, resultCompare);
  } else {
    *resultCompare = FAILURE;
  }
}

void CompareHandle(matrix_t *A, matrix_t *B, int *resultCompare) {
  for (int i = 0; i < A->rows && *resultCompare == SUCCESS; i++) {
    for (int j = 0; j < A->columns && *resultCompare == SUCCESS; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
        *resultCompare = FAILURE;
      }
    }
  }
}
