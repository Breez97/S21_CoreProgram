#include "s21_test_matrix.h"

int main() { RunAllTests(); }

void RunTest(Suite *test) {
  SRunner *sr = srunner_create(test);
  srunner_run_all(sr, CK_NORMAL);

  int numFailed = srunner_ntests_failed(sr);
  if (numFailed == 0) {
    printf("All tests passed!\n");
  } else {
    printf("Number of failed tests: %d\n", numFailed);
  }

  srunner_free(sr);
}

void RunAllTests() {
  Suite *arrayMatrixTests[] = {
      suite_s21_create_matrix(),      suite_s21_remove_matrix(),
      suite_s21_eq_matrix(),          suite_s21_sum_matrix(),
      suite_s21_sub_matrix(),         suite_s21_mult_number(),
      suite_s21_mult_matrix(),        suite_s21_transpose_matrix(),
      suite_s21_complements_matrix(), suite_s21_determinant(),
      suite_s21_inverse_matrix(),     NULL};

  for (int i = 0; arrayMatrixTests[i] != NULL; i++) {
    RunTest(arrayMatrixTests[i]);
  }
}
