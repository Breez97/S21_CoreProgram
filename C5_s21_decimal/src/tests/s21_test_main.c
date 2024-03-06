#include "s21_tests.h"

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
  Suite *arrayDecimalTests[] = {suite_s21_sub(),
                                suite_s21_add(),
                                suite_s21_div(),
                                suite_s21_mul(),
                                suite_s21_is_equal(),
                                suite_s21_is_greater_or_equal(),
                                suite_s21_is_greater(),
                                suite_s21_is_less_or_equal(),
                                suite_s21_is_less(),
                                suite_s21_is_not_equal(),
                                suite_s21_from_decimal_to_float(),
                                suite_s21_from_decimal_to_int(),
                                suite_s21_from_float_to_decimal(),
                                suite_s21_from_int_to_decimal(),
                                suite_s21_floor(),
                                suite_s21_round(),
                                suite_s21_negate(),
                                suite_s21_truncate(),
                                NULL};

  for (int i = 0; arrayDecimalTests[i] != NULL; i++) {
    RunTest(arrayDecimalTests[i]);
  }
}