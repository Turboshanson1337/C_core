#include <check.h>

#include "s21_matrix.h"

// EQ_MATRIX TESTS START -->
START_TEST(test_s21_eq_matrix1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double rand_number = (double)rand() + (double)rand() / RAND_MAX;
      A.matrix[i][j] = rand_number;
      B.matrix[i][j] = rand_number;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_not_eq_matrix1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double rand_number = (double)rand() + (double)rand() / RAND_MAX;
      A.matrix[i][j] = rand_number;
      B.matrix[i][j] = rand_number + 0.0001;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_not_eq_matrix2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 4, &A);
  s21_create_matrix(4, 3, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// EQ_MATRIX TESTS END <--

// SUM_MATRIX TESTS START -->
START_TEST(test_s21_sum_matrix1) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  matrix_t sum_res;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &res);
  double number = 1.00123;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      number += number;
      A.matrix[i][j] = number;
      B.matrix[i][j] = number;
      res.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &sum_res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &sum_res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&sum_res);
}
END_TEST

START_TEST(test_s21_sum_matrix2) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  matrix_t sum_res;
  s21_create_matrix(4, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &res);
  double number = 1.00123;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      number += number;
      A.matrix[i][j] = number;
      B.matrix[i][j] = number;
      res.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &sum_res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST
// SUM_MATRIX TESTS END <--

// SUB_MATRIX TESTS START -->
START_TEST(test_s21_sub_matrix1) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  matrix_t sub_res;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &res);
  double number = 1.00123;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      number += number;
      A.matrix[i][j] = number;
      B.matrix[i][j] = number + 3.3412;
      res.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &sub_res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &sub_res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&sub_res);
}
END_TEST

START_TEST(test_s21_sub_matrix2) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  matrix_t sub_res;
  s21_create_matrix(4, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &res);
  double number = 1.00123;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      number += number;
      A.matrix[i][j] = number;
      B.matrix[i][j] = number + 3.3412;
      res.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &sub_res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST
// SUB_MATRIX TESTS END <--

// MULT_NUMBER TESTS START -->
START_TEST(test_s21_mult_number1) {
  matrix_t A;
  matrix_t res;
  matrix_t mul_res;
  double mult = 2.123;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res);
  double number = 1.00123;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      number += number;
      A.matrix[i][j] = number;
      res.matrix[i][j] = A.matrix[i][j] * mult;
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, mult, &mul_res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &mul_res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&mul_res);
}
END_TEST

START_TEST(test_s21_mult_number2) {
  matrix_t A = {0};
  matrix_t mul_res;
  double mult = 2.123;
  ck_assert_int_eq(s21_mult_number(&A, mult, &mul_res), 1);
  s21_remove_matrix(&A);
}
END_TEST
// MULT_NUMBER TESTS END <--

// MULT_MATRIX TESTS START -->
START_TEST(test_s21_mult_matrix1) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  matrix_t mul_res;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &res);
  double number = 1.00123;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      number += number;
      A.matrix[i][j] = pow(-1, j + 1) * number;
      B.matrix[i][j] = pow(-1, j + 1) * number;
    }
  }
  res.matrix[0][0] = 966.3728984;
  res.matrix[0][1] = -1932.7457969;
  res.matrix[0][2] = 3865.4915937;
  res.matrix[1][0] = 7730.9831875;
  res.matrix[1][1] = -15461.9663750;
  res.matrix[1][2] = 30923.9327499;
  res.matrix[2][0] = 61847.8654999;
  res.matrix[2][1] = -123695.7309998;
  res.matrix[2][2] = 247391.4619995;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &mul_res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &mul_res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&mul_res);
}
END_TEST

START_TEST(test_s21_mult_matrix2) {
  matrix_t A = {0};
  matrix_t B;
  matrix_t mul_res;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &mul_res), 1);
}
END_TEST

START_TEST(test_s21_mult_matrix3) {
  matrix_t A;
  matrix_t B;
  matrix_t mul_res;
  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &mul_res), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
// MULT_MATRIX TESTS END <--

// TRANSPOSE TESTS START -->
START_TEST(test_s21_transpose1) {
  matrix_t A;
  matrix_t res;
  matrix_t tr_res;
  s21_create_matrix(3, 4, &A);
  s21_create_matrix(4, 3, &res);
  A.matrix[0][0] = 2.1234;
  A.matrix[1][1] = -1232.1234;
  A.matrix[2][3] = -543.1233334;
  res.matrix[0][0] = 2.1234;
  res.matrix[1][1] = -1232.1234;
  res.matrix[3][2] = -543.1233334;
  ck_assert_int_eq(s21_transpose(&A, &tr_res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &tr_res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&tr_res);
}
END_TEST

START_TEST(test_s21_transpose2) {
  matrix_t A = {0};
  matrix_t res;
  ck_assert_int_eq(s21_transpose(&A, &res), 1);
}
END_TEST
// TRANSPOSE TESTS END <--

// DETERMINANT TESTS START -->
START_TEST(test_s21_determinant1) {
  matrix_t A;
  double res = 0.0;
  s21_create_matrix(3, 3, &A);
  double number = 1.00123;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      number += number;
      A.matrix[i][j] = pow(-1, j + 1) * number;
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_float_eq(res, 0.0);
  s21_remove_matrix(&A);
}

START_TEST(test_s21_determinant2) {
  matrix_t A;
  double res = 0.0;
  s21_create_matrix(3, 4, &A);
  ck_assert_int_eq(s21_determinant(&A, &res), 2);
  s21_remove_matrix(&A);
}

START_TEST(test_s21_determinant3) {
  matrix_t A = {0};
  double res = 0.0;
  ck_assert_int_eq(s21_determinant(&A, &res), 1);
}
// DETERMINANT TESTS END <--

// CALC_COMPLEMENTS TESTS START -->
START_TEST(test_s21_calc_complements1) {
  matrix_t A;
  matrix_t res;
  matrix_t cc_res;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  res.matrix[0][0] = 0;
  res.matrix[0][1] = 10;
  res.matrix[0][2] = -20;
  res.matrix[1][0] = 4;
  res.matrix[1][1] = -14;
  res.matrix[1][2] = 8;
  res.matrix[2][0] = -8;
  res.matrix[2][1] = -2;
  res.matrix[2][2] = 4;
  ck_assert_int_eq(s21_calc_complements(&A, &cc_res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &cc_res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&cc_res);
}
END_TEST

START_TEST(test_s21_calc_complements2) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(3, 4, &A);
  ck_assert_int_eq(s21_calc_complements(&A, &res), 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements3) {
  matrix_t A = {0};
  matrix_t res;
  ck_assert_int_eq(s21_calc_complements(&A, &res), 1);
}
END_TEST

START_TEST(test_s21_calc_complements4) {
  matrix_t A;
  matrix_t res;
  matrix_t cc_res;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &res);
  A.matrix[0][0] = -123;
  res.matrix[0][0] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &cc_res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &cc_res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&cc_res);
}
END_TEST

// CALC_COMPLEMENTS TESTS END <--

// INVERSE_MATRIX TESTS START -->
START_TEST(test_s21_inverse_matrix1) {
  matrix_t A;
  matrix_t res;
  matrix_t inv_res;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &res);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = -4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = -8;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 12;
  res.matrix[0][0] = 0.2888889;
  res.matrix[0][1] = 0.1;
  res.matrix[0][2] = -0.0888889;
  res.matrix[1][0] = 0.0888889;
  res.matrix[1][1] = -0.2;
  res.matrix[1][2] = 0.0111111;
  res.matrix[2][0] = 0.1777778;
  res.matrix[2][1] = 0.1;
  res.matrix[2][2] = 0.0222222;
  ck_assert_int_eq(s21_inverse_matrix(&A, &inv_res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &inv_res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&inv_res);
}
END_TEST

START_TEST(test_s21_inverse_matrix2) {
  matrix_t A = {0};
  matrix_t res;
  ck_assert_int_eq(s21_inverse_matrix(&A, &res), 1);
}
END_TEST

START_TEST(test_s21_inverse_matrix3) {
  matrix_t A;
  matrix_t res;
  matrix_t inv_res;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &res);
  A.matrix[0][0] = -123;
  res.matrix[0][0] = -0.0081301;
  ck_assert_int_eq(s21_inverse_matrix(&A, &inv_res), 0);
  ck_assert_int_eq(s21_eq_matrix(&res, &inv_res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&inv_res);
}
END_TEST
// INVERSE_MATRIX TESTS END <--

// ADDITIONAL CREATE_MATRIX TEST
START_TEST(test_s21_create_matrix1) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(0, 1, &A), 1);
}
END_TEST

Suite *suite_insert(void) {
  Suite *s = suite_create("start_tests");
  TCase *tc = tcase_create("insert_tc");

  // EQ_MATRIX TESTS START -->
  tcase_add_test(tc, test_s21_eq_matrix1);
  tcase_add_test(tc, test_s21_not_eq_matrix1);
  tcase_add_test(tc, test_s21_not_eq_matrix2);
  // EQ_MATRIX TESTS END <--

  // SUM_MATRIX TESTS START -->
  tcase_add_test(tc, test_s21_sum_matrix1);
  tcase_add_test(tc, test_s21_sum_matrix2);
  // SUM_MATRIX TESTS END <--

  // SUB_MATRIX TESTS START -->
  tcase_add_test(tc, test_s21_sub_matrix1);
  tcase_add_test(tc, test_s21_sub_matrix2);
  // SUB_MATRIX TESTS END <--

  // MULT_NUMBER TESTS START -->
  tcase_add_test(tc, test_s21_mult_number1);
  tcase_add_test(tc, test_s21_mult_number2);
  // MULT_NUMBER TESTS END <--

  // MULT_MATRIX TESTS START -->
  tcase_add_test(tc, test_s21_mult_matrix1);
  tcase_add_test(tc, test_s21_mult_matrix2);
  tcase_add_test(tc, test_s21_mult_matrix3);
  // MULT_MATRIX TESTS END <--

  // TRANSPOSE TESTS START -->
  tcase_add_test(tc, test_s21_transpose1);
  tcase_add_test(tc, test_s21_transpose2);
  // TRANSPOSE TESTS END <--

  // DETERMINANT TESTS START -->
  tcase_add_test(tc, test_s21_determinant1);
  tcase_add_test(tc, test_s21_determinant2);
  tcase_add_test(tc, test_s21_determinant3);
  // DETERMINANT TESTS END <--

  // CALC_COMPLEMENTS TESTS START -->
  tcase_add_test(tc, test_s21_calc_complements1);
  tcase_add_test(tc, test_s21_calc_complements2);
  tcase_add_test(tc, test_s21_calc_complements3);
  tcase_add_test(tc, test_s21_calc_complements4);
  // CALC_COMPLEMENTS TESTS END <--

  // INVERSE_MATRIX TESTS START -->
  tcase_add_test(tc, test_s21_inverse_matrix1);
  tcase_add_test(tc, test_s21_inverse_matrix2);
  tcase_add_test(tc, test_s21_inverse_matrix3);
  // INVERSE_MATRIX TESTS END <--

  // ADDITIONAL CREATE_MATRIX TEST
  tcase_add_test(tc, test_s21_create_matrix1);

  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  Suite *s1;
  SRunner *sr;
  s1 = suite_insert();
  sr = srunner_create(s1);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_VERBOSE);
  srunner_free(sr);
  return 0;
}