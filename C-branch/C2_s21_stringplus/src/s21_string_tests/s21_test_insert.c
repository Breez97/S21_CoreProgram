#include "s21_tests.h"

// Тестирование на базовых случаях (нормальные тесты):
// Функция возвращает новую строку, в которой указанная str строка вставлена в
// определенную позицию строки src - Новая строка вставляется в начало,
// середину, конец исходной строки (вставляемая строка может превышать длину
// исходной);

START_TEST(inserting_word_at_the_beginning) {
  char *source = "hello school 21! I am ...";
  char *appendedString = "I hate writing tests. ";
  char *resultString = s21_insert(source, appendedString, 0);
  char *expected = "I hate writing tests. hello school 21! I am ...";

  ck_assert_str_eq(resultString, expected);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - вставка в начало строки из-за index = 0
}
END_TEST

START_TEST(inserting_word_in_the_middle) {
  char *source = "Hello 21! I am learning programming.";
  char *appendedString = "exciting ";
  char *resultString = s21_insert(source, appendedString, 15);
  char *expected = "Hello 21! I am exciting learning programming.";

  ck_assert_str_eq(resultString, expected);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - вставка в середину строки из-за index = 15
}
END_TEST

START_TEST(inserting_word_at_the_end) {
  char *source = " This is the end.";
  char *appendedString = " The end of the line. ";
  char *resultString = s21_insert(source, appendedString, 17);
  char *expected = " This is the end. The end of the line. ";

  ck_assert_str_eq(resultString, expected);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - вставка в конец строки из-за index = 17
}
END_TEST

START_TEST(inserting_longer_string) {
  char *source = " Short string.";
  char *appendedString = "This is a longer string.";
  char *resultString = s21_insert(source, appendedString, 0);
  char *expected = "This is a longer string. Short string.";

  ck_assert_str_eq(resultString, expected);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - вставка строки, которая длиннее исходной,
  // в начало
}
END_TEST

// Тестирование на ненормальных, краевых случаях:
// Новая строка - пустая, исходная строка - пустая, исходная и новая строка
// пустые, стартовый индекс за пределом, исходная/новая строка null

START_TEST(inserting_empty_string_into_empty_string) {
  char *source = "";
  char *appendedString = "";
  char *resultString = s21_insert(source, appendedString, 0);
  char *expected = "";

  ck_assert_str_eq(resultString, expected);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - пустая строка, так как исходная и
  // вставляемая строки пусты
}
END_TEST

START_TEST(inserting_into_empty_string) {
  char *source = "";
  char *appendedString = "This is a non-empty string.";
  char *resultString = s21_insert(source, appendedString, 0);
  char *expected = "This is a non-empty string.";

  ck_assert_str_eq(resultString, expected);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - вставка в начало пустой строки (изменений
  // не будет)
}
END_TEST

START_TEST(inserting_empty_string_into_non_empty_string) {
  char *source = "This is a non-empty string.";
  char *appendedString = "";
  char *resultString = s21_insert(source, appendedString, 10);
  char *expected = "This is a non-empty string.";

  ck_assert_str_eq(resultString, expected);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - вставка пустой строки в середину непустой
  // строки (изменений не будет)
}
END_TEST

START_TEST(inserting_string_at_out_of_bound_index) {
  char *source = "This is a non-empty string.";
  char *appendedString = "Inserted string.";
  char *resultString = s21_insert(source, appendedString, 50);

  ck_assert_ptr_eq(resultString, S21_NULL);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - вставка не произойдет, так как индекс за
  // пределами строки
}
END_TEST

START_TEST(inserting_into_null_source_string) {
  char *source = S21_NULL;
  char *appendedString = "Inserted string.";
  char *resultString = s21_insert(source, appendedString, 5);

  ck_assert_ptr_eq(resultString, S21_NULL);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - вставка не произойдет, так как исходная
  // строка null
}
END_TEST

START_TEST(inserting_null_appended_string) {
  char *source = "This is a non-empty string.";
  char *appendedString = S21_NULL;
  char *resultString = s21_insert(source, appendedString, 5);

  ck_assert_str_eq(resultString, source);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - вставка не произойдет, так как вставляемая
  // строка null, новая строка будет равна source
}
END_TEST

START_TEST(inserting_into_null_source_and_destination) {
  char *source = S21_NULL;
  char *appendedString = S21_NULL;
  char *resultString = s21_insert(source, appendedString, 0);

  ck_assert_ptr_eq(resultString, S21_NULL);
  if (resultString) {
    free(resultString);
  }
  // Ожидание от выполнение функции - вставка не произойдет, так как исходная и
  // вставляемая строки null
}
END_TEST

Suite *suite_insert() {
  Suite *suite = suite_create("s21_insert");

  TCase *normalTests = tcase_create("Normal Tests");
  tcase_add_test(normalTests, inserting_word_at_the_beginning);
  tcase_add_test(normalTests, inserting_word_in_the_middle);
  tcase_add_test(normalTests, inserting_word_at_the_end);
  tcase_add_test(normalTests, inserting_longer_string);

  TCase *abnormalTests = tcase_create("Abnormal Tests");
  tcase_add_test(abnormalTests, inserting_empty_string_into_empty_string);
  tcase_add_test(abnormalTests, inserting_into_empty_string);
  tcase_add_test(abnormalTests, inserting_empty_string_into_non_empty_string);
  tcase_add_test(abnormalTests, inserting_string_at_out_of_bound_index);
  tcase_add_test(abnormalTests, inserting_into_null_source_string);
  tcase_add_test(abnormalTests, inserting_null_appended_string);
  tcase_add_test(abnormalTests, inserting_into_null_source_and_destination);

  suite_add_tcase(suite, normalTests);
  suite_add_tcase(suite, abnormalTests);

  return suite;
}
