#include "s21_tests.h"

// Тестирование на базовых случаях:

// Функция принимает непустые строки: строку для разделения и строку
// разделителей, состоящую из одного символа.

START_TEST(single_delim) {
  char s21_str[] = "Test1/Test2/Test3/Test4";
  char str[] = "Test1/Test2/Test3/Test4";
  const char delim[] = "/";

  char *s21_result = s21_strtok(s21_str, delim);
  char *result = strtok(str, delim);

  if (s21_result && result) {
    ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(result));
  }

  ck_assert_str_eq(s21_result, result);

  while (s21_result && result) {
    s21_result = s21_strtok(S21_NULL, delim);
    result = strtok(NULL, delim);

    if (s21_result && result) {
      ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(result));
    }

    if (s21_result || result) {
      ck_assert_str_eq(s21_result, result);
    } else {
      ck_assert_ptr_null(s21_result);
      ck_assert_ptr_null(result);
    }
  }
}
END_TEST

// Функция принимает непустые строки: строку для разделения и строку
// разделителей, состояющую из нескольких символов.

START_TEST(multiple_delims) {
  char s21_str[] = "Hello, s21!How_are.you? Good_thx";
  char str[] = "Hello, s21!How_are.you? Good_thx";
  const char delim[] = ",._! ";

  char *s21_result = s21_strtok(s21_str, delim);
  char *result = strtok(str, delim);

  if (s21_result && result) {
    ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(result));
  }

  ck_assert_str_eq(s21_result, result);

  while (s21_result && result) {
    s21_result = s21_strtok(S21_NULL, delim);
    result = strtok(NULL, delim);

    if (s21_result && result) {
      ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(result));
    }

    if (s21_result || result) {
      ck_assert_str_eq(s21_result, result);
    } else {
      ck_assert_ptr_null(s21_result);
      ck_assert_ptr_null(result);
    }
  }
}
END_TEST

// Функция принимает непустые строки: строку для разделения и строку
// разделителей, состояющую из специальных символов.

START_TEST(symbols_in_delims) {
  char s21_str[] = "\n\tThis\tis\nmy way\nhome";
  char str[] = "\n\tThis\tis\nmy way\nhome";
  const char delim[] = "\t \n\0";

  char *s21_result = s21_strtok(s21_str, delim);
  char *result = strtok(str, delim);

  if (s21_result && result) {
    ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(result));
  }

  ck_assert_str_eq(s21_result, result);

  while (s21_result && result) {
    s21_result = s21_strtok(S21_NULL, delim);
    result = strtok(NULL, delim);

    if (s21_result && result) {
      ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(result));
    }

    if (s21_result || result) {
      ck_assert_str_eq(s21_result, result);
    } else {
      ck_assert_ptr_null(s21_result);
      ck_assert_ptr_null(result);
    }
  }
}
END_TEST

// Функция принимает непустые строки: строку для разделения и строку
// разделителей, состояющую из специальных символов и обычных букв.

START_TEST(combined_delims) {
  char s21_str[] = "23.4t\nest_4305\t043hello_s\tc,llc;sa.aaa\n.a:poi\t";
  char str[] = "23.4t\nest_4305\t043hello_s\tc,llc;sa.aaa\n.a:poi\t";
  const char delim[] = "_,:\t\n";

  char *s21_result = s21_strtok(s21_str, delim);
  char *result = strtok(str, delim);

  if (s21_result && result) {
    ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(result));
  }

  ck_assert_str_eq(s21_result, result);

  while (s21_result && result) {
    s21_result = s21_strtok(S21_NULL, delim);
    result = strtok(NULL, delim);

    if (s21_result && result) {
      ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(result));
    }

    if (s21_result || result) {
      ck_assert_str_eq(s21_result, result);
    } else {
      ck_assert_ptr_null(s21_result);
      ck_assert_ptr_null(result);
    }
  }
}
END_TEST

// Функция принимает непустые строки: строку для разделения и строку
// разделителей, состояющую из унарных операторов.

START_TEST(unary_delims) {
  char s21_str[] = "Hel lo^Unar%yOp!era to=+rsCh+eckCor-rect";
  char str[] = "Hel lo^Unar%yOp!era to=+rsCh+eckCor-rect";
  const char delim[] = "+ -!=^";

  char *s21_result = s21_strtok(s21_str, delim);
  char *result = strtok(str, delim);

  if (s21_result && result) {
    ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(result));
  }

  ck_assert_str_eq(s21_result, result);

  while (s21_result && result) {
    s21_result = s21_strtok(S21_NULL, delim);
    result = strtok(NULL, delim);

    if (s21_result && result) {
      ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(result));
    }

    if (s21_result || result) {
      ck_assert_str_eq(s21_result, result);
    } else {
      ck_assert_ptr_null(s21_result);
      ck_assert_ptr_null(result);
    }
  }
}
END_TEST

//Тестирование на краевых случаях:

//Функция принимает непустую строку, которую нужно разделить и пустую строку
//разделителей.

START_TEST(no_delims) {
  char s21_str[] = "Hello, s21!How_are.you? Good_thx";
  char str[] = "Hello, s21!How_are.you? Good_thx";
  const char delim[] = "";

  char *s21_result = s21_strtok(s21_str, delim);
  char *result = strtok(str, delim);

  if (s21_result && result) {
    ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(result));
  }

  ck_assert_str_eq(s21_result, result);

  while (s21_result && result) {
    s21_result = s21_strtok(S21_NULL, delim);
    result = strtok(NULL, delim);

    if (s21_result && result) {
      ck_assert_uint_eq(s21_strlen(s21_result), s21_strlen(result));
    }

    if (s21_result || result) {
      ck_assert_str_eq(s21_result, result);
    } else {
      ck_assert_ptr_null(s21_result);
      ck_assert_ptr_null(result);
    }
  }
}
END_TEST

// Функция принимает пустую строку, которую нужно разделить и не пустую строку
// разделителей.

START_TEST(empty_string) {
  char s21_str[] = "";
  char str[] = "";
  const char delim[] = "_-+=,:?";

  char *s21_result = s21_strtok(s21_str, delim);
  char *result = strtok(str, delim);

  ck_assert_ptr_null(s21_result);
  ck_assert_ptr_null(result);
}
END_TEST

// Функция принимает пустые строки.

START_TEST(empty_string_and_delims) {
  char s21_str[] = "";
  char str[] = "";
  const char delim[] = "";

  char *s21_result = s21_strtok(s21_str, delim);
  char *result = strtok(str, delim);

  ck_assert_ptr_null(s21_result);
  ck_assert_ptr_null(result);
}
END_TEST

// Функция принимает непустые строки, однако строка, которую нужно разделить
// состоит только из символов, которые есть в строке разделителей.

START_TEST(only_delims_in_string) {
  char s21_str[] = "+++++++------======++++";
  char str[] = "+++++++------======++++";
  const char delim[] = "+-=";

  char *s21_result = s21_strtok(s21_str, delim);
  char *result = strtok(str, delim);

  ck_assert_ptr_null(s21_result);
  ck_assert_ptr_null(result);
}
END_TEST

Suite *suite_strtok() {
  Suite *suite = suite_create("s21_strtok");

  TCase *basicTests = tcase_create("Basic Tests");
  tcase_add_test(basicTests, single_delim);
  tcase_add_test(basicTests, multiple_delims);
  tcase_add_test(basicTests, symbols_in_delims);
  tcase_add_test(basicTests, combined_delims);
  tcase_add_test(basicTests, unary_delims);

  TCase *edgeTests = tcase_create("Edge Tests");
  tcase_add_test(edgeTests, no_delims);
  tcase_add_test(edgeTests, empty_string);
  tcase_add_test(edgeTests, empty_string_and_delims);
  tcase_add_test(edgeTests, only_delims_in_string);

  suite_add_tcase(suite, basicTests);
  suite_add_tcase(suite, edgeTests);

  return suite;
}
