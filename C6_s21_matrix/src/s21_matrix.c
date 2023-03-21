#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error_code = 0;
  if (rows > 0 && columns > 0 && result != NULL) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows && !error_code; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          for (int j = 0; j < i + 1; j++) {
            free(result->matrix[j]);
          }
          free(result->matrix);
          error_code = 1;
        }
      }
    }
  } else {
    error_code = 1;
  }
  return error_code;
}

void s21_remove_matrix(matrix_t *A) {
  if (!s21_check_matrix(A)) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->rows = 0;
    A->columns = 0;
    A->matrix = NULL;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result_code = SUCCESS;
  if (!s21_check_matrix(A) && !s21_check_matrix(B)) {
    if (A->rows != B->rows || A->columns != B->columns) {
      result_code = FAILURE;
    }
    for (int i = 0; i < A->rows && result_code; i++) {
      for (int j = 0; j < A->columns && result_code; j++) {
        if (fabs(fabs(A->matrix[i][j]) - fabs(B->matrix[i][j])) >= EPS) {
          result_code = FAILURE;
        }
      }
    }
  } else {
    result_code = FAILURE;
  }
  return result_code;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = 0;
  if ((!s21_check_matrix(A) && !s21_check_matrix(B))) {
    if (A->rows != B->rows || A->columns != B->columns) {
      error_code = 1;
    }
    if (!error_code) {
      error_code = s21_create_matrix(A->rows, A->columns, result);
    }
    if (!error_code) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }
  return error_code;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = 0;
  if ((!s21_check_matrix(A) && !s21_check_matrix(B))) {
    if (A->rows != B->rows || A->columns != B->columns) {
      error_code = 1;
    }
    if (!error_code) {
      error_code = s21_create_matrix(A->rows, A->columns, result);
    }
    if (!error_code) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }
  return error_code;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error_code = 0;
  if (!s21_check_matrix(A)) {
    error_code = s21_create_matrix(A->rows, A->columns, result);
    if (!error_code) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  } else {
    error_code = 1;
  }
  return error_code;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code;
  if (!s21_check_matrix(A) && !s21_check_matrix(B)) {
    if (A->columns == B->rows) {
      error_code = s21_create_matrix(A->rows, B->columns, result);
      if (!error_code) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            double sum = 0;
            for (int k = 0; k < A->columns; k++) {
              sum += A->matrix[i][k] * B->matrix[k][j];
            }
            result->matrix[i][j] = sum;
          }
        }
      }
    } else {
      error_code = 2;
    }
  } else {
    error_code = 1;
  }
  return error_code;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error_code = 0;
  if (!s21_check_matrix(A)) {
    error_code = s21_create_matrix(A->columns, A->rows, result);
    if (!error_code) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  } else {
    error_code = 1;
  }
  return error_code;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error_code = 0;
  if (!s21_check_matrix(A)) {
    if (A->rows == A->columns) {
      error_code = s21_create_matrix(A->columns, A->rows, result);
      if (A->rows == 1 && A->columns == 1) {
        result->matrix[0][0] = A->matrix[0][0] ? 1 : 0;
      } else {
        if (!error_code) {
          for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
              matrix_t B;
              double determinant = 0;
              error_code = s21_create_matrix(A->columns - 1, A->rows - 1, &B);
              if (!error_code) {
                s21_get_matrix(A, i, j, &B);
                s21_determinant(&B, &determinant);
                result->matrix[i][j] = pow(-1, (i + j)) * determinant;
                s21_remove_matrix(&B);
              }
            }
          }
        }
      }
    } else {
      error_code = 2;
    }
  } else {
    error_code = 1;
  }
  return error_code;
}

int s21_determinant(matrix_t *A, double *result) {
  int error_code = 0;
  if (!s21_check_matrix(A)) {
    if (A->rows == A->columns) {
      int n = A->rows;
      *result = s21_determinant_recursive(A, n);
    } else {
      error_code = 2;
    }
  } else {
    error_code = 1;
  }
  return error_code;
}

int s21_determinant_recursive(matrix_t *A, int n) {
  double det = 0.0;
  if (n == 1) {
    det = A->matrix[0][0];
  } else {
    matrix_t B;
    s21_create_matrix(n - 1, n - 1, &B);
    for (int j = 0; j < n; j++) {
      s21_get_matrix(A, 0, j, &B);
      det +=
          pow(-1.0, j) * A->matrix[0][j] * s21_determinant_recursive(&B, n - 1);
    }
    s21_remove_matrix(&B);
  }
  return det;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error_code = 1;
  double det;
  matrix_t B;
  if (!s21_check_matrix(A)) {
    error_code = s21_determinant(A, &det);
    if (!error_code && det) {
      error_code = s21_calc_complements(A, &B);
      matrix_t C;
      if (!error_code) {
        error_code = s21_transpose(&B, &C);
        if (!error_code) {
          error_code = s21_create_matrix(A->rows, A->rows, result);
          if (!error_code) {
            for (int i = 0; i < result->rows; i++) {
              for (int j = 0; j < result->rows; j++) {
                result->matrix[i][j] = C.matrix[i][j] / det;
              }
            }
            s21_remove_matrix(&C);
          }
          s21_remove_matrix(&B);
        }
      }
    }
  }
  return error_code;
}