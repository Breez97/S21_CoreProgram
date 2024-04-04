#include "../s21_tests.h"

// Проверка на некорректные значения
// 1. Указатель на float, куда будет записываться результат равен NULL
// 2. В изначальном decimal неверно записаны биты в bits[3]
// Возвращаемое значение 1

START_TEST(s21_from_decimal_to_float_false_1) {
  // Указатель на float, куда будет записываться результат равен NULL
  s21_decimal number = {{0x2bf949e0, 0xe, 0x0, 0x70000}};
  int result = s21_from_decimal_to_float(number, NULL);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_float_false_2) {
  // В изначальном decimal неверно записаны биты в bits[3]
  s21_decimal number = {{0x0, 0x0, 0x0, 0b01000000100000110000001000100100}};
  int result = s21_from_decimal_to_float(number, NULL);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_float_false_3) {
  // В изначальном decimal неверно записаны биты в bits[3]
  s21_decimal number = {{0x0, 0x0, 0x0, 0b01010000100000000000001000000010}};
  int result = s21_from_decimal_to_float(number, NULL);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_float_false_4) {
  // В изначальном decimal неверно записаны биты в bits[3]
  s21_decimal number = {{0x0, 0x0, 0x0, 0b11111000100000000100000001000000}};
  int result = s21_from_decimal_to_float(number, NULL);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_float_false_5) {
  // В изначальном decimal неверно записаны биты в bits[3]
  s21_decimal number = {{0x0, 0x0, 0x0, 0b10000000100000000100111101000000}};
  int result = s21_from_decimal_to_float(number, NULL);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

// Проверка на корректные значения
// Возвращаемое значение 1

START_TEST(s21_from_decimal_to_float_true_1) {
  // 161773.50328061
  float check = 161773.50328061;

  s21_decimal number = {{0x95383efd, 0xeb6, 0x0, 0x80000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_2) {
  // -0.55
  float check = -0.55;

  s21_decimal number = {{0x37, 0x0, 0x0, 0x80020000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_3) {
  // -80.6244
  float check = -80.6244;

  s21_decimal number = {{0xc4d64, 0x0, 0x0, 0x80040000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_4) {
  // 58.6095411165688598835
  float check = 58.6095411165688598835;

  s21_decimal number = {{0x49619133, 0xc5b52f30, 0x1f, 0x130000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_5) {
  // -4730621.175921281337311364
  float check = -4730621.175921281337311364;

  s21_decimal number = {{0x905ec084, 0x7ce0eb39, 0x3e9bf, 0x80120000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_6) {
  // -5004.603131084899454220
  float check = -5004.603131084899454220;

  s21_decimal number = {{0xab1d8d0c, 0x4cd20032, 0x10f, 0x80120000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_7) {
  // -0.8
  float check = -0.8;

  s21_decimal number = {{0x8, 0x0, 0x0, 0x80010000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_8) {
  // 552.521108567310430499
  float check = 552.521108567310430499;

  s21_decimal number = {{0x13937123, 0xf3c54cdc, 0x1d, 0x120000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_9) {
  // -3090.1587565
  float check = -3090.1587565;

  s21_decimal number = {{0x31e0ce6d, 0x7, 0x0, 0x80070000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_10) {
  // 19613863877.831699005087
  float check = 19613863877.831699005087;

  s21_decimal number = {{0xf014fe9f, 0x450a7e2e, 0x427, 0xc0000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_11) {
  // 8150140.21
  float check = 8150140.21;

  s21_decimal number = {{0x30942085, 0x0, 0x0, 0x20000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_12) {
  // 1516.632293818086007662170
  float check = 1516.632293818086007662170;

  s21_decimal number = {{0xaf72665a, 0xcd27f545, 0x14128, 0x150000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_13) {
  // -6885417910117461.209608890119
  float check = -6885417910117461.209608890119;

  s21_decimal number = {{0xb6b82707, 0xd4bc4330, 0x163f7bf4, 0x800c0000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_14) {
  // -75964.36
  float check = -75964.36;

  s21_decimal number = {{0x73e994, 0x0, 0x0, 0x80020000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_15) {
  // 89.6271913
  float check = 89.6271913;

  s21_decimal number = {{0x356c0629, 0x0, 0x0, 0x70000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_16) {
  // 56.5
  float check = 56.5;

  s21_decimal number = {{0x235, 0x0, 0x0, 0x10000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_17) {
  // 23866995673366568910.41
  float check = 23866995673366568910.41;

  s21_decimal number = {{0x67ee6ca1, 0x621c3337, 0x81, 0x20000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_18) {
  // 68616283.85398
  float check = 68616283.85398;

  s21_decimal number = {{0x98ec2876, 0x63d, 0x0, 0x50000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_19) {
  // -54878656878.292092
  float check = -54878656878.292092;

  s21_decimal number = {{0xfb2c7c, 0xc2f7d9, 0x0, 0x80060000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_20) {
  // 276026.966998385126317402
  float check = 276026.966998385126317402;

  s21_decimal number = {{0x707c9d5a, 0x73ad5f7b, 0x3a73, 0x120000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_21) {
  // 3705275090.530614175
  float check = 3705275090.530614175;

  s21_decimal number = {{0x3e2e3b9f, 0x336bc810, 0x0, 0x90000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_22) {
  // 0.496532431
  float check = 0.496532431;

  s21_decimal number = {{0x1d987bcf, 0x0, 0x0, 0x90000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_23) {
  // 783083203707.92389
  float check = 783083203707.92389;

  s21_decimal number = {{0xa2a897c5, 0x1163500, 0x0, 0x50000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_24) {
  // 0
  float check = 0;

  s21_decimal number = {{0x0, 0x0, 0x0, 0x0}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_25) {
  // 54188117.205991
  float check = 54188117.205991;

  s21_decimal number = {{0xa77a23e7, 0x3148, 0x0, 0x60000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_26) {
  // -2970.716514120
  float check = -2970.716514120;

  s21_decimal number = {{0xac80a748, 0x2b3, 0x0, 0x80090000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_27) {
  // -461586862999754162081794278.01
  float check = -461586862999754162081794278.01;

  s21_decimal number = {{0xb53d79d9, 0x4687f189, 0x95259206, 0x80020000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_28) {
  // -5.6
  float check = -5.6;

  s21_decimal number = {{0x38, 0x0, 0x0, 0x80010000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_29) {
  // -6151628.897
  float check = -6151628.897;

  s21_decimal number = {{0x6eaa6861, 0x1, 0x0, 0x80030000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_30) {
  // 7685.600098
  float check = 7685.600098;

  s21_decimal number = {{0x12c38, 0x0, 0x0, 0x10000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_31) {
  // 573147016927
  float check = 573147016927;

  s21_decimal number = {{0x72396edf, 0x85, 0x0, 0x0}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_32) {
  // -2066135646.7
  float check = -2066135646.7;

  s21_decimal number = {{0xcf8347b3, 0x4, 0x0, 0x80010000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_33) {
  // 167644720.12078949459245273
  float check = 167644720.12078949459245273;

  s21_decimal number = {{0xa9a738d9, 0xd94b2e58, 0xdde03, 0x110000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_34) {
  // 6330640609932018.2771260
  float check = 6330640609932018.2771260;

  s21_decimal number = {{0xf9ed8e3c, 0xd8dee79d, 0xd67, 0x70000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_35) {
  // -78774212404545621
  float check = -78774212404545621;

  s21_decimal number = {{0x93d58855, 0x117dcba, 0x0, 0x80000000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_36) {
  // -0.25413762545
  float check = -0.25413762545;

  s21_decimal number = {{0xeac73df1, 0x5, 0x0, 0x800b0000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_37) {
  // 6809424069891.87246221
  float check = 6809424069891.87246221;

  s21_decimal number = {{0x81f9e88d, 0xe9f9675e, 0x24, 0x80000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_38) {
  // -8048191525834818555.61812
  float check = -8048191525834818555.61812;

  s21_decimal number = {{0xfe03d054, 0x556c580d, 0xaa6d, 0x80050000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_39) {
  // -90367354592.2
  float check = -90367354592.2;

  s21_decimal number = {{0x672404c2, 0xd2, 0x0, 0x80010000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_40) {
  // 4934823882577734
  float check = 4934823882577734;

  s21_decimal number = {{0x388cd746, 0x118832, 0x0, 0x0}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_41) {
  // 0.337027224611840536424589397
  float check = 0.337027224611840536424589397;

  s21_decimal number = {{0xcc25a855, 0x749ea79b, 0x116c84a, 0x1b0000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_42) {
  // 819608833608.66289845
  float check = 819608833608.66289845;

  s21_decimal number = {{0x59a8c8b5, 0x716f8d2b, 0x4, 0x80000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_43) {
  // 4.678111
  float check = 4.678111;

  s21_decimal number = {{0x4761df, 0x0, 0x0, 0x60000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_44) {
  // -407.498361790938035483519
  float check = -407.498361790938035483519;

  s21_decimal number = {{0x8977737f, 0x87cc0601, 0x564a, 0x80150000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

START_TEST(s21_from_decimal_to_float_true_45) {
  // 3727984664.37288
  float check = 3727984664.37288;

  s21_decimal number = {{0xe82a30a8, 0x1530e, 0x0, 0x50000}};
  float conversion = 0.0;
  int result = s21_from_decimal_to_float(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_float_eq(conversion, check);
}
END_TEST

Suite *suite_s21_from_decimal_to_float() {
  Suite *suite = suite_create("s21_from_decimal_to_float");

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_from_decimal_to_float_false_1);
  tcase_add_test(testsFalse, s21_from_decimal_to_float_false_2);
  tcase_add_test(testsFalse, s21_from_decimal_to_float_false_3);
  tcase_add_test(testsFalse, s21_from_decimal_to_float_false_4);
  tcase_add_test(testsFalse, s21_from_decimal_to_float_false_5);

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_1);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_2);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_3);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_4);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_5);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_6);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_7);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_8);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_9);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_10);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_11);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_12);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_13);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_14);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_15);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_16);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_17);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_18);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_19);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_20);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_21);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_22);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_23);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_24);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_25);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_26);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_27);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_28);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_29);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_30);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_31);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_32);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_33);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_34);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_35);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_36);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_37);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_38);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_39);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_40);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_41);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_42);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_43);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_44);
  tcase_add_test(testsTrue, s21_from_decimal_to_float_true_45);

  suite_add_tcase(suite, testsFalse);
  suite_add_tcase(suite, testsTrue);

  return suite;
}