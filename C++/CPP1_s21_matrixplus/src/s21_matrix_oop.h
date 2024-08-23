#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <cmath>
#include <iostream>

#define EPS 1e-7

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

  // Support functions
  void AllocateMemory();
  void DeallocateMemory();
  void FillTempMatrix(int rowNumber, int colNumber,
                      S21Matrix& tempMatrix) const noexcept;

 public:
  // Accessors and mutators
  int GetRows() const noexcept;
  int GetCols() const noexcept;
  void SetRows(int rows);
  void SetCols(int cols);

  // Constructors and destructor
  S21Matrix() noexcept;
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix() noexcept;

  // Matrix operations
  bool EqMatrix(const S21Matrix& other) const noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  // Operators overloading
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double number) const;

  bool operator==(const S21Matrix& other) const;
  S21Matrix& operator=(const S21Matrix& other) noexcept;

  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double number);

  double& operator()(int row, int col);
  const double& operator()(int row, int col) const;
};

#endif
