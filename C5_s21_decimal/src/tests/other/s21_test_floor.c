#include "../s21_tests.h"

START_TEST(invalid_dec_s21_floor_1) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_floor(dec_1, NULL);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_floor_2) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x380000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_floor_3) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_floor_4) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_floor_5) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_floor_6) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_floor_7) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(s21_floor_1) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  s21_decimal dec_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  s21_decimal dec_check = {{0x8, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal dec_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  s21_decimal dec_check = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_4) {
  s21_decimal dec_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal dec_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_5) {
  s21_decimal dec_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  s21_decimal dec_check = {{0x28F5C290, 0xF5C28F5C, 0x28F5C28, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_6) {
  s21_decimal dec_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  s21_decimal dec_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_7) {
  s21_decimal dec_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  s21_decimal dec_check = {{0x295E9E1C, 0xBAC710CB, 0x68DB8, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_8) {
  s21_decimal dec_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  s21_decimal dec_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_9) {
  s21_decimal dec_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  s21_decimal dec_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_10) {
  s21_decimal dec_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  s21_decimal dec_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_11) {
  s21_decimal dec_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  s21_decimal dec_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_12) {
  s21_decimal dec_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  s21_decimal dec_check = {{0x12DEA112, 0x1197998, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_13) {
  s21_decimal dec_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  s21_decimal dec_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_14) {
  s21_decimal dec_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  s21_decimal dec_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_15) {
  s21_decimal dec_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  s21_decimal dec_check = {{0xACA5F622, 0x734, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_16) {
  s21_decimal dec_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  s21_decimal dec_check = {{0x77AA3236, 0xB8, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_17) {
  s21_decimal dec_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  s21_decimal dec_check = {{0x77AA3237, 0xB8, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_18) {
  s21_decimal dec_1 = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};
  s21_decimal dec_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_19) {
  s21_decimal dec_1 = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x10000}};
  s21_decimal dec_check = {{0x11111111, 0x0, 0x11111111, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_20) {
  s21_decimal dec_1 = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0xD0000}};
  s21_decimal dec_check = {{0xF01E35D4, 0x12C3D6, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_21) {
  s21_decimal dec_1 = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};
  s21_decimal dec_check = {{0x6, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_22) {
  s21_decimal dec_1 = {{0x0, 0x55555555, 0x0, 0x10000}};
  s21_decimal dec_check = {{0x80000000, 0x8888888, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_23) {
  s21_decimal dec_1 = {{0x0, 0x55555555, 0x0, 0x80010000}};
  s21_decimal dec_check = {{0x80000000, 0x8888888, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_24) {
  s21_decimal dec_1 = {{0x0, 0x811800, 0x811800, 0x40000}};
  s21_decimal dec_check = {{0x27525460, 0x75F7320, 0x34E, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_25) {
  s21_decimal dec_1 = {{0x0, 0x55555555, 0x0, 0x120000}};
  s21_decimal dec_check = {{0x6, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_26) {
  s21_decimal dec_1 = {{0x0, 0x55555555, 0x0, 0x80120000}};
  s21_decimal dec_check = {{0x7, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_27) {
  s21_decimal dec_1 = {{0x55555555, 0x0, 0x0, 0x10000}};
  s21_decimal dec_check = {{0x8888888, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_28) {
  s21_decimal dec_1 = {{0x55555555, 0x0, 0x0, 0x80010000}};
  s21_decimal dec_check = {{0x8888889, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_29) {
  s21_decimal dec_1 = {{0x55555555, 0x0, 0x0, 0x40000}};
  s21_decimal dec_check = {{0x22F3D, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_30) {
  s21_decimal dec_1 = {{0x55555555, 0x0, 0x0, 0x90000}};
  s21_decimal dec_check = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_31) {
  s21_decimal dec_1 = {{0x1, 0x1, 0x1, 0x0}};  //
  s21_decimal dec_check = {{0x1, 0x1, 0x1, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_32) {
  s21_decimal dec_1 = {{0x1, 0x1, 0x1, 0x130000}};
  s21_decimal dec_check = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_33) {
  s21_decimal dec_1 = {{0x0, 0x1, 0x1, 0x80010000}};
  s21_decimal dec_check = {{0xB3333334, 0x19999999, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_34) {
  s21_decimal dec_1 = {{0x0, 0x0, 0x1, 0xB0000}};
  s21_decimal dec_check = {{0xAFEBFF0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_35) {
  s21_decimal dec_1 = {{0x0, 0x0, 0x1, 0x800B0000}};
  s21_decimal dec_check = {{0xAFEBFF1, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_36) {
  s21_decimal dec_1 = {{0x0, 0x0, 0x1, 0x130000}};
  s21_decimal dec_check = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_37) {
  s21_decimal dec_1 = {{0x0, 0x0, 0x1, 0x80130000}};
  s21_decimal dec_check = {{0x2, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_38) {
  s21_decimal dec_1 = {{0x1, 0x1, 0x0, 0x0}};  //
  s21_decimal dec_check = {{0x1, 0x1, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_39) {
  s21_decimal dec_1 = {{0x1, 0x1, 0x0, 0x80010000}};
  s21_decimal dec_check = {{0x1999999A, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_40) {
  s21_decimal dec_1 = {{0x1, 0x1, 0x0, 0x20000}};
  s21_decimal dec_check = {{0x28F5C28, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_41) {
  s21_decimal dec_1 = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x140000}};
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_42) {
  s21_decimal dec_1 = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x80140000}};
  s21_decimal dec_check = {{0x1, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_floor(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

Suite *suite_s21_floor(void) {
  Suite *c = suite_create("s21_floor_cases");
  TCase *tc_core = tcase_create("s21_floor_tc");

  tcase_add_test(tc_core, invalid_dec_s21_floor_1);
  tcase_add_test(tc_core, invalid_dec_s21_floor_2);
  tcase_add_test(tc_core, invalid_dec_s21_floor_3);
  tcase_add_test(tc_core, invalid_dec_s21_floor_4);
  tcase_add_test(tc_core, invalid_dec_s21_floor_5);
  tcase_add_test(tc_core, invalid_dec_s21_floor_6);
  tcase_add_test(tc_core, invalid_dec_s21_floor_7);

  tcase_add_test(tc_core, s21_floor_1);
  tcase_add_test(tc_core, s21_floor_2);
  tcase_add_test(tc_core, s21_floor_3);
  tcase_add_test(tc_core, s21_floor_4);
  tcase_add_test(tc_core, s21_floor_5);
  tcase_add_test(tc_core, s21_floor_6);
  tcase_add_test(tc_core, s21_floor_7);
  tcase_add_test(tc_core, s21_floor_8);
  tcase_add_test(tc_core, s21_floor_9);
  tcase_add_test(tc_core, s21_floor_10);
  tcase_add_test(tc_core, s21_floor_11);
  tcase_add_test(tc_core, s21_floor_12);
  tcase_add_test(tc_core, s21_floor_13);
  tcase_add_test(tc_core, s21_floor_14);
  tcase_add_test(tc_core, s21_floor_15);
  tcase_add_test(tc_core, s21_floor_16);
  tcase_add_test(tc_core, s21_floor_17);
  tcase_add_test(tc_core, s21_floor_18);
  tcase_add_test(tc_core, s21_floor_19);
  tcase_add_test(tc_core, s21_floor_20);
  tcase_add_test(tc_core, s21_floor_21);
  tcase_add_test(tc_core, s21_floor_22);
  tcase_add_test(tc_core, s21_floor_23);
  tcase_add_test(tc_core, s21_floor_24);
  tcase_add_test(tc_core, s21_floor_25);
  tcase_add_test(tc_core, s21_floor_26);
  tcase_add_test(tc_core, s21_floor_27);
  tcase_add_test(tc_core, s21_floor_28);
  tcase_add_test(tc_core, s21_floor_29);
  tcase_add_test(tc_core, s21_floor_30);
  tcase_add_test(tc_core, s21_floor_31);
  tcase_add_test(tc_core, s21_floor_32);
  tcase_add_test(tc_core, s21_floor_33);
  tcase_add_test(tc_core, s21_floor_34);
  tcase_add_test(tc_core, s21_floor_35);
  tcase_add_test(tc_core, s21_floor_36);
  tcase_add_test(tc_core, s21_floor_37);
  tcase_add_test(tc_core, s21_floor_38);
  tcase_add_test(tc_core, s21_floor_39);
  tcase_add_test(tc_core, s21_floor_40);
  tcase_add_test(tc_core, s21_floor_41);
  tcase_add_test(tc_core, s21_floor_42);

  suite_add_tcase(c, tc_core);
  return c;
}