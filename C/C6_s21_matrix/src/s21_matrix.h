#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#define S21_OK 0
#define S21_INCORRECT_MATRIX 1
#define S21_INCORRECT_CALC 2

// Create and remove matrix
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

void FillMatrixStruct(int rows, int columns, matrix_t *A, int *errorCode);

// Compare matrices
#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B);

void CompareMatrices(matrix_t *A, matrix_t *B, int *resultCompare);
void CompareHandle(matrix_t *A, matrix_t *B, int *resultCompare);

// Aritmetic with matrices
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

void SumSubHandle(int operation, matrix_t *A, matrix_t *B, matrix_t *result,
                  int *errorCode);
void MultHandle(matrix_t *A, matrix_t *B, matrix_t *result, int *errorCode);

// Transpose matrix
int s21_transpose(matrix_t *A, matrix_t *result);

// Complement matrix
int s21_calc_complements(matrix_t *A, matrix_t *result);

void ComplementHandle(matrix_t *A, matrix_t *result, int *errorCode);

// Matrix's determinant
int s21_determinant(matrix_t *A, double *result);

double CountDeterminant(matrix_t *A, int *errorCode);

// Inverse matrix
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void InverseHandle(matrix_t *A, matrix_t *result, double determinant,
                   int *errorCode);

// Support
int CheckMatrix(matrix_t *A);
void FillTmpMatrix(int rowNumber, int columnNumber, matrix_t A,
                   matrix_t *tmpMatrix);

#endif
