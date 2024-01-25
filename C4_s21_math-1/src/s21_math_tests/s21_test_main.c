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
  Suite *arrayMathTests[] = {
      suite_exp(),   suite_abs(),  suite_fabs(), suite_log(),
      suite_pow(),   suite_atan(), suite_sin(),  suite_cos(),
      suite_tan(),   suite_fmod(), suite_sqrt(), suite_ceil(),
      suite_floor(), suite_asin(), suite_acos(), NULL};
  for (int i = 0; arrayMathTests[i] != NULL; i++) {
    RunTest(arrayMathTests[i]);
  }
}
