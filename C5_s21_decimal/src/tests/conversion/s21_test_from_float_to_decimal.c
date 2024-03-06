#include "../s21_tests.h"

// Проверка на некорректные значения
// 1. Указатель на s21_decimal, куда будет записываться результат равен NULL
// 2. Если числа слишком малы (0 < |x| < 1e-28), вернуть ошибку и значение
// s21_decimal, равное 0
// 3. Если числа слишком велики (|x| > 79,228,162,514,264,337,593,543,950,335)
// или равны бесконечности, вернуть ошибку Вовзращаемое значение 1

START_TEST(s21_from_float_to_decimal_false_1) {
  // Указатель на s21_decimal, куда будет записываться результат равен NULL
  float number = 12.43543;
  int result = s21_from_float_to_decimal(number, NULL);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_false_2) {
  // Если числа слишком малы (0 < |x| < 1e-28), вернуть ошибку и значение
  // s21_decimal, равное 0
  float number = 1e-29;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_false_3) {
  // Если числа слишком малы (0 < |x| < 1e-28), вернуть ошибку и значение
  // s21_decimal, равное 0
  float number = 1e-35;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_false_4) {
  // Если числа слишком малы (0 < |x| < 1e-28), вернуть ошибку и значение
  // s21_decimal, равное 0
  float number =
      0.0000000000000000000000000000000000000000999994610111475958152591905227349949604220526961919185041279;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_false_5) {
  // Если числа слишком велики (|x| > 79,228,162,514,264,337,593,543,950,335)
  // или равны бесконечности, вернуть ошибку
  float number = 782348734287874327843783428784238742387.8;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_false_6) {
  // Если числа слишком велики (|x| > 79,228,162,514,264,337,593,543,950,335)
  // или равны бесконечности, вернуть ошибку
  float number = 23784843287342783783428787342877832417883289322.3240942043;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_false_7) {
  // Если числа слишком велики (|x| > 79,228,162,514,264,337,593,543,950,335)
  // или равны бесконечности, вернуть ошибку
  float number =
      8894385989345895432883425890580923290912391909329032.6231613267612731132;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_false_8) {
  float number = -1.0 / 0.0;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
  ck_assert_int_eq(conversion.bits[0], 0);
  ck_assert_int_eq(conversion.bits[1], 0);
  ck_assert_int_eq(conversion.bits[2], 0);
  ck_assert_int_eq(conversion.bits[3], 0);
}
END_TEST

// Проверка на корректные значения

START_TEST(s21_from_float_to_decimal_true_1) {
  float number = 1.02E+08;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_2) {
  float number = -435.1235;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_3) {
  float number = 22.14836E+03;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_4) {
  float number = 2867;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_5) {
  float number = -1234.567;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_6) {
  float number = 0.03;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_7) {
  float number = 8598534.213;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_8) {
  float number = -732447;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_9) {
  float number = 18192839.985;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_10) {
  float number = -354536.1;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_11) {
  float number = 96.234;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_12) {
  float number = 54.5340;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_13) {
  float number = 1.0764E+7;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_14) {
  float number = -11223;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_15) {
  float number = 435345;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_16) {
  float number = -128.023;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_17) {
  float number = -342.94;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_18) {
  float number = 9239049;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_19) {
  float number = 995834;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_20) {
  float number = 737324.324;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_21) {
  float number = 4569076.8456;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_22) {
  float number = 9.81289;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_23) {
  float number = 34845;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_24) {
  float number = 0;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_25) {
  float number = 966356;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_26) {
  float number = 0.234423;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_27) {
  float number = 8712387;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_28) {
  float number = 0.367768;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_29) {
  float number = 8748745.68998;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_30) {
  float number = 27.93621;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_31) {
  float number = 67784;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_32) {
  float number = 1111134;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_33) {
  float number = 975482;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_34) {
  float number = 2344.975;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_35) {
  float number = 46771;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_36) {
  float number = 4.5213;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_37) {
  float number = 96583;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_38) {
  float number = 453.1231;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_39) {
  float number = 921390.1;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_40) {
  float number = 8181.21;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_41) {
  float number = 7238781;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_true_42) {
  float number = 444.222;
  s21_decimal conversion = {0};

  int result = s21_from_float_to_decimal(number, &conversion);

  float tmp = 0;
  s21_from_decimal_to_float(conversion, &tmp);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq_tol(number, tmp, 1e-28);
}
END_TEST

Suite *suite_s21_from_float_to_decimal() {
  Suite *suite = suite_create("s21_from_float_to_decimal");

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_from_float_to_decimal_false_1);
  tcase_add_test(testsFalse, s21_from_float_to_decimal_false_2);
  tcase_add_test(testsFalse, s21_from_float_to_decimal_false_3);
  tcase_add_test(testsFalse, s21_from_float_to_decimal_false_4);
  tcase_add_test(testsFalse, s21_from_float_to_decimal_false_5);
  tcase_add_test(testsFalse, s21_from_float_to_decimal_false_6);
  tcase_add_test(testsFalse, s21_from_float_to_decimal_false_7);
  tcase_add_test(testsFalse, s21_from_float_to_decimal_false_8);

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_1);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_2);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_3);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_4);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_5);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_6);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_7);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_8);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_9);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_10);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_11);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_12);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_13);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_14);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_15);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_16);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_17);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_18);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_19);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_20);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_21);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_22);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_23);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_24);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_25);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_26);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_27);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_28);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_29);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_30);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_31);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_32);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_33);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_34);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_35);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_36);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_37);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_38);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_39);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_40);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_41);
  tcase_add_test(testsTrue, s21_from_float_to_decimal_true_42);

  suite_add_tcase(suite, testsFalse);
  suite_add_tcase(suite, testsTrue);

  return suite;
}