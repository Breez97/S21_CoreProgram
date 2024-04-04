#ifndef S21_MATRIX_TESTS
#define S21_MATRIX_TESTS

#include <check.h>

#include "../s21_matrix.h"

void RunAllTests();

void RunTest(Suite *test);

#define CHECK_OK 0
#define CHECK_INCORRECT_MATRIX 1
#define CHECK_INCORRECT_CALC 2
#define CHECK_OTHER_ERROR 3

#define CHECK_FAILURE 0
#define CHECK_SUCCESS 1

// Create and remove matrix
Suite *suite_s21_create_matrix();
Suite *suite_s21_remove_matrix();

// Compare matrices
Suite *suite_s21_eq_matrix();

// Arithmetic
Suite *suite_s21_sum_matrix();
Suite *suite_s21_sub_matrix();
Suite *suite_s21_mult_number();
Suite *suite_s21_mult_matrix();

// Transpose
Suite *suite_s21_transpose_matrix();

// Complement matrix
Suite *suite_s21_complements_matrix();

// Matrix's determinant
Suite *suite_s21_determinant();

// Inverse matrix
Suite *suite_s21_inverse_matrix();

#endif
