#include "../s21_matrix.h"

int CheckMatrix(matrix_t *A) {
  int errorCode = S21_OK;

  if (A == NULL || A->rows <= 0 || A->columns <= 0 || A->matrix == NULL) {
    errorCode = S21_INCORRECT_MATRIX;
  }

  return errorCode;
}

void FillTmpMatrix(int rowNumber, int columnNumber, matrix_t A,
                   matrix_t *tmpMatrix) {
  int tmpRow = 0;
  for (int i = 0; i < A.rows; i++) {
    if (i != rowNumber) {
      int tmpCol = 0;
      for (int j = 0; j < A.columns; j++) {
        if (j != columnNumber) {
          tmpMatrix->matrix[tmpRow][tmpCol] = A.matrix[i][j];
          tmpCol++;
        }
      }
      tmpRow++;
    }
  }
}
