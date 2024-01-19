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
  Suite *arrayStringTests[] = {
      suite_memchr(),   suite_memcmp(),   suite_memcpy(),
      suite_memset(),   suite_strncat(),  suite_strchr(),
      suite_strncmp(),  suite_strncpy(),  suite_strcspn(),
      suite_strerror(), suite_strlen(),   suite_strpbrk(),
      suite_strrchr(),  suite_strstr(),   suite_strtok(),
      suite_to_lower(), suite_to_upper(), suite_insert(),
      suite_trim(),     suite_sprintf(),  NULL};

  for (int i = 0; arrayStringTests[i] != NULL; i++) {
    RunTest(arrayStringTests[i]);
  }
}
