#include "tests.h"

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
  Suite *arrayTetrisTests[] = {suite_figures_creation(), suite_handlers(),
                               suite_fsm(), suite_backend(), NULL};

  for (int i = 0; arrayTetrisTests[i] != NULL; i++) {
    RunTest(arrayTetrisTests[i]);
  }
}