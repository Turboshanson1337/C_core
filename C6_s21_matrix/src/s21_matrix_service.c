#include "s21_matrix.h"

int s21_check_matrix(matrix_t *A) {
  int error_code = 0;
  if (A != NULL) {
    if (A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
      error_code = 1;
    }
  }
  return error_code;
}

void s21_get_matrix(matrix_t *A, int row, int col, matrix_t *result) {
  int n = A->rows;
  int m = A->columns;
  int i_new = 0;
  int j_new = 0;
  for (int i = 0; i < n; i++) {
    if (i == row) {
      continue;
    }
    j_new = 0;
    for (int j = 0; j < m; j++) {
      if (j == col) {
        continue;
      }
      result->matrix[i_new][j_new] = A->matrix[i][j];
      j_new++;
    }
    i_new++;
  }
  result->rows = n - 1;
  result->columns = m - 1;
}

// void s21_print_matrix(matrix_t *A) {
//   if (!s21_check_matrix(A)) {
//     for (int i = 0; i < A->rows; i++) {
//       for (int j = 0; j < A->columns; j++) {
//         printf("%.7f ", A->matrix[i][j]);
//       }
//       printf("\n");
//     }
//   }
// }