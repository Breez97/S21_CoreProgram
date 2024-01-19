#ifndef S21_TESTS_STRING
#define S21_TESTS_STRING

#include <check.h>
#include <string.h>

#include "../s21_string.h"

void RunAllTests();

void RunTest(Suite *test);

Suite *suite_memchr();
Suite *suite_memcmp();
Suite *suite_memcpy();
Suite *suite_memset();
Suite *suite_strncat();

Suite *suite_strlen();
Suite *suite_strpbrk();
Suite *suite_strrchr();
Suite *suite_strstr();
Suite *suite_strtok();

Suite *suite_strchr();
Suite *suite_strcspn();
Suite *suite_strerror();
Suite *suite_strncmp();
Suite *suite_strncpy();

Suite *suite_to_upper();
Suite *suite_to_lower();
Suite *suite_trim();
Suite *suite_insert();

Suite *suite_sprintf();

#endif