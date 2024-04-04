#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int errorCode = S21_OK;

  if (CheckMatrix(A) != S21_OK) {
    errorCode = S21_INCORRECT_MATRIX;
  }

  if (errorCode == S21_OK) {
    if (A->rows == A->columns) {
      double determinant = CountDeterminant(A, &errorCode);
      if (errorCode == S21_OK) {
        if (determinant == 0.0) {
          errorCode = S21_INCORRECT_CALC;
        } else {
          InverseHandle(A, result, determinant, &errorCode);
        }
      }
    } else {
      errorCode = S21_INCORRECT_CALC;
    }
  }

  return errorCode;
}

void InverseHandle(matrix_t *A, matrix_t *result, double determinant,
                   int *errorCode) {
  matrix_t complementMatrix;
  int code = s21_calc_complements(A, &complementMatrix);
  *errorCode = code;
  if (*errorCode == S21_OK) {
    matrix_t transposeComplementMatrix;
    *errorCode = s21_transpose(&complementMatrix, &transposeComplementMatrix);
    if (*errorCode == S21_OK) {
      *errorCode =
          s21_mult_number(&transposeComplementMatrix, 1 / determinant, result);
      s21_remove_matrix(&transposeComplementMatrix);
    }
    s21_remove_matrix(&complementMatrix);
  }
}
