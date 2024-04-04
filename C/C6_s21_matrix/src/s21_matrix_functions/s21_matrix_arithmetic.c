#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int errorCode = S21_OK;

  if (CheckMatrix(A) != S21_OK || CheckMatrix(B) != S21_OK) {
    errorCode = S21_INCORRECT_MATRIX;
  }

  if (errorCode == S21_OK) {
    SumSubHandle(0, A, B, result, &errorCode);
  }

  return errorCode;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int errorCode = S21_OK;

  if (CheckMatrix(A) != S21_OK || CheckMatrix(B) != S21_OK) {
    errorCode = S21_INCORRECT_MATRIX;
  }

  if (errorCode == S21_OK) {
    SumSubHandle(1, A, B, result, &errorCode);
  }

  return errorCode;
}

void SumSubHandle(int operation, matrix_t *A, matrix_t *B, matrix_t *result,
                  int *errorCode) {
  if (A->rows == B->rows && A->columns == B->columns) {
    *errorCode = s21_create_matrix(A->rows, A->columns, result);
    if (*errorCode == S21_OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = (operation)
                                     ? A->matrix[i][j] - B->matrix[i][j]
                                     : A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  } else {
    *errorCode = S21_INCORRECT_CALC;
  }
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int errorCode = S21_OK;

  if (CheckMatrix(A) != S21_OK) {
    errorCode = S21_INCORRECT_MATRIX;
  }

  if (errorCode == S21_OK) {
    errorCode = s21_create_matrix(A->rows, A->columns, result);
    if (errorCode == S21_OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = number * A->matrix[i][j];
        }
      }
    }
  }

  return errorCode;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int errorCode = S21_OK;

  if (CheckMatrix(A) != S21_OK || CheckMatrix(B) != S21_OK) {
    errorCode = S21_INCORRECT_MATRIX;
  }

  if (errorCode == S21_OK) {
    if (A->columns == B->rows) {
      MultHandle(A, B, result, &errorCode);
    } else {
      errorCode = S21_INCORRECT_CALC;
    }
  }

  return errorCode;
}

void MultHandle(matrix_t *A, matrix_t *B, matrix_t *result, int *errorCode) {
  *errorCode = s21_create_matrix(A->rows, B->columns, result);
  if (*errorCode == S21_OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0.0;
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
}
