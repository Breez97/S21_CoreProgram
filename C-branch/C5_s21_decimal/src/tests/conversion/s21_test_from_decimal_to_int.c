#include "../s21_tests.h"

// Проверка на некорректные значения
// 1. Указатель на int, куда будет записываться результат равен NULL
// 2. В изначальном decimal неверно записаны биты в bits[3]
// 3. Изначальный decimal представляет из себя число, которое больше MAX_INT,
// либо меньше MIN_INT Возвращаемое значение 1

START_TEST(s21_from_decimal_to_int_false_1) {
  // Указатель на int, куда будет записываться результат равен NULL
  s21_decimal number = {{0x4d4b6a1f, 0x0, 0x0, 0x0}};
  int result = s21_from_decimal_to_int(number, NULL);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_int_false_2) {
  // В изначальном decimal неверно записаны биты в bits[3]
  s21_decimal number = {{0x0, 0x0, 0x0, 0b00010000100010110000001000100000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_int_false_3) {
  // В изначальном decimal неверно записаны биты в bits[3]
  s21_decimal number = {{0x0, 0x0, 0x0, 0b01110000100010110000001000000001}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_int_false_4) {
  // В изначальном decimal неверно записаны биты в bits[3]
  s21_decimal number = {{0x1, 0x0, 0x0, 0b00000000100010110001000000110001}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_int_false_5) {
  // В изначальном decimal неверно записаны биты в bits[3]
  s21_decimal number = {{0x1, 0x1, 0x1, 0b10010000111110110001000000110001}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_int_false_6) {
  // Изначальный decimal представляет из себя число, которое больше MAX_INT,
  // либо меньше MIN_INT 7374860838763954591627
  s21_decimal number = {{0x20de578b, 0xcac0fb2b, 0x18f, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_int_false_7) {
  // Изначальный decimal представляет из себя число, которое больше MAX_INT,
  // либо меньше MIN_INT -618014344533900774
  s21_decimal number = {{0xa009fde6, 0x893a0c5, 0x0, 0x80000000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_int_false_8) {
  // Изначальный decimal представляет из себя число, которое больше MAX_INT,
  // либо меньше MIN_INT 56161733385452130013751836
  s21_decimal number = {{0xb572a1c, 0xaad7a47e, 0x2e74b5, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_int_false_9) {
  // Изначальный decimal представляет из себя число, которое больше MAX_INT,
  // либо меньше MIN_INT 904020808523565681757
  s21_decimal number = {{0x88ecc5d, 0x1cf17a5, 0x31, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_int_false_10) {
  // Изначальный decimal представляет из себя число, которое больше MAX_INT,
  // либо меньше MIN_INT -68804142948044977
  s21_decimal number = {{0xe37e50b1, 0xf47100, 0x0, 0x80000000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_int_false_11) {
  // Изначальный decimal представляет из себя число, которое больше MAX_INT,
  // либо меньше MIN_INT 4686793359406724452435
  s21_decimal number = {{0x597e9053, 0x1252e0af, 0xfe, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_int_false_12) {
  // Изначальный decimal представляет из себя число, которое больше MAX_INT,
  // либо меньше MIN_INT -8983896847783776
  s21_decimal number = {{0x7c4f9760, 0x1feace, 0x0, 0x80000000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

// Проверка на корректные значения
// Возвращаемое значение 1

START_TEST(s21_from_decimal_to_int_true_1) {
  // 6
  int check = 6;

  s21_decimal number = {{0x6, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_2) {
  // 50681.13
  int check = 50681;

  s21_decimal number = {{0x4d5551, 0x0, 0x0, 0x20000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_3) {
  // -50661.822465104
  int check = -50661;

  s21_decimal number = {{0x9fee8450, 0x2e13, 0x0, 0x80090000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_4) {
  // 130077067
  int check = 130077067;

  s21_decimal number = {{0x7c0d18b, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_5) {
  // 1068
  int check = 1068;

  s21_decimal number = {{0x42c, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_6) {
  // 5.4942885872292
  int check = 5;

  s21_decimal number = {{0x633202a4, 0x31f8, 0x0, 0xd0000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_7) {
  // 4353456
  int check = 4353456;

  s21_decimal number = {{0x426db0, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_8) {
  // 2272.3946
  int check = 2272;

  s21_decimal number = {{0x15abd6a, 0x0, 0x0, 0x40000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_9) {
  // 177.1523195131
  int check = 177;

  s21_decimal number = {{0x7702c0fb, 0x19c, 0x0, 0xa0000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_10) {
  // 92.51
  int check = 92;

  s21_decimal number = {{0x2423, 0x0, 0x0, 0x20000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_11) {
  // -103.40
  int check = -103;

  s21_decimal number = {{0x2864, 0x0, 0x0, 0x80020000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_12) {
  // 204
  int check = 204;

  s21_decimal number = {{0xcc, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_13) {
  // 864518
  int check = 864518;

  s21_decimal number = {{0xd3106, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_14) {
  // 719836
  int check = 719836;

  s21_decimal number = {{0xafbdc, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_15) {
  // 14675
  int check = 14675;

  s21_decimal number = {{0x3953, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_16) {
  // 155748
  int check = 155748;

  s21_decimal number = {{0x26064, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_17) {
  // 9418930
  int check = 9418930;

  s21_decimal number = {{0x8fb8b2, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_18) {
  // 24514609
  int check = 24514609;

  s21_decimal number = {{0x1761031, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_19) {
  // 19394530
  int check = 19394530;

  s21_decimal number = {{0x127efe2, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_20) {
  // 3535.234532549
  int check = 3535;

  s21_decimal number = {{0x1c6604c5, 0x337, 0x0, 0x90000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_21) {
  // 83459854.32234423
  int check = 83459854;

  s21_decimal number = {{0x28fd29b7, 0x1da6a1, 0x0, 0x80000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_22) {
  // 9426094
  int check = 9426094;

  s21_decimal number = {{0x8fd4ae, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_23) {
  // 4038903
  int check = 4038903;

  s21_decimal number = {{0x3da0f7, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_24) {
  // 1497217
  int check = 1497217;

  s21_decimal number = {{0x16d881, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_25) {
  // 5809800
  int check = 5809800;

  s21_decimal number = {{0x58a688, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_26) {
  // 693230
  int check = 693230;

  s21_decimal number = {{0xa93ee, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_27) {
  // 6983616
  int check = 6983616;

  s21_decimal number = {{0x6a8fc0, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_28) {
  // 5191365
  int check = 5191365;

  s21_decimal number = {{0x4f36c5, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_29) {
  // 4258.12123432
  int check = 4258;

  s21_decimal number = {{0x24615f28, 0x63, 0x0, 0x80000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_30) {
  // 9.5756
  int check = 9;

  s21_decimal number = {{0x1760c, 0x0, 0x0, 0x40000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_31) {
  // 3932504
  int check = 3932504;

  s21_decimal number = {{0x3c0158, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_32) {
  // 2842146
  int check = 2842146;

  s21_decimal number = {{0x2b5e22, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_33) {
  // 1151122
  int check = 1151122;

  s21_decimal number = {{0x119092, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_34) {
  // 435.345
  int check = 435;

  s21_decimal number = {{0x6a491, 0x0, 0x0, 0x30000}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_35) {
  // 4556571
  int check = 4556571;

  s21_decimal number = {{0x45871b, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_36) {
  // 2014347
  int check = 2014347;

  s21_decimal number = {{0x1ebc8b, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_37) {
  // 348255
  int check = 348255;

  s21_decimal number = {{0x5505f, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_int_true_38) {
  // 7922151
  int check = 7922151;

  s21_decimal number = {{0x78e1e7, 0x0, 0x0, 0x0}};
  int conversion = 0;
  int result = s21_from_decimal_to_int(number, &conversion);

  ck_assert_int_eq(result, S21_CONVERSION_OK);
  ck_assert_int_eq(conversion, check);
}
END_TEST

Suite *suite_s21_from_decimal_to_int() {
  Suite *suite = suite_create("s21_from_decimal_to_int");

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_from_decimal_to_int_false_1);
  tcase_add_test(testsFalse, s21_from_decimal_to_int_false_2);
  tcase_add_test(testsFalse, s21_from_decimal_to_int_false_3);
  tcase_add_test(testsFalse, s21_from_decimal_to_int_false_4);
  tcase_add_test(testsFalse, s21_from_decimal_to_int_false_5);
  tcase_add_test(testsFalse, s21_from_decimal_to_int_false_6);
  tcase_add_test(testsFalse, s21_from_decimal_to_int_false_7);
  tcase_add_test(testsFalse, s21_from_decimal_to_int_false_8);
  tcase_add_test(testsFalse, s21_from_decimal_to_int_false_9);
  tcase_add_test(testsFalse, s21_from_decimal_to_int_false_10);
  tcase_add_test(testsFalse, s21_from_decimal_to_int_false_11);
  tcase_add_test(testsFalse, s21_from_decimal_to_int_false_12);

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_1);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_2);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_3);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_4);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_5);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_6);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_7);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_8);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_9);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_10);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_11);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_12);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_13);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_14);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_15);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_16);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_17);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_18);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_19);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_20);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_21);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_22);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_23);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_24);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_25);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_26);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_27);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_28);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_29);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_30);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_31);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_32);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_33);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_34);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_35);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_36);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_37);
  tcase_add_test(testsTrue, s21_from_decimal_to_int_true_38);

  suite_add_tcase(suite, testsFalse);
  suite_add_tcase(suite, testsTrue);

  return suite;
}