#include "../s21_tests.h"

START_TEST(invalid_dec_s21_round_1) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_round(dec_1, NULL);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_round_2) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_round_3) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x380000}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_round_4) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_round_5) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_round_6) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_round_7) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(s21_round_1) {
  s21_decimal dec_1 = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x801B0000}};
  s21_decimal dec_check = {{0x1, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal dec_1 = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  s21_decimal dec_check = {{0x1, 0x0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal dec_1 = {{0xBC4FF2, 0x0, 0x0, 0x40000}};
  s21_decimal dec_check = {{0x4D2, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal dec_1 = {{0x499529D9, 0x0, 0x0, 0x50000}};  //
  s21_decimal dec_check = {{0x3039, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_5) {
  s21_decimal dec_1 = {{0x73593407, 0xB3A, 0x0, 0x70000}};
  s21_decimal dec_check = {{0x12D687, 0x0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_6) {
  s21_decimal dec_1 = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0x800A0000}};
  s21_decimal dec_check = {{0x499602D2, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_7) {
  s21_decimal dec_1 = {{0x63, 0x0, 0x0, 0x80000000}};  //
  s21_decimal dec_check = {{0x63, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_8) {
  s21_decimal dec_1 = {{0xB808F3ED, 0xB3E3CAED, 0x8FC5C492, 0x50000}};
  s21_decimal dec_check = {{0x2303D471, 0x72CC77C, 0x5E39, 0x0}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_9) {
  s21_decimal dec_1 = {{0xC9CC9900, 0xA1F6983A, 0x92BBC355, 0xD0000}};  //
  s21_decimal dec_check = {{0xEEA98118, 0x10222D, 0x0, 0x0}};           //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_10) {
  s21_decimal dec_1 = {{0x482071F2, 0x8D6510BE, 0x9C6C0C78, 0x801A0000}};
  s21_decimal dec_check = {{0x1E4, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_11) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  s21_decimal dec_check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_12) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  s21_decimal dec_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_13) {
  s21_decimal dec_1 = {{0b11001, 0x0, 0x0, 0b10000000000000000}};
  s21_decimal dec_check = {{0b10, 0x0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_14) {
  s21_decimal dec_1 = {{0b100011, 0x0, 0x0, 0b10000000000000000}};
  s21_decimal dec_check = {{0b100, 0x0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_15) {
  s21_decimal dec_1 = {{0x0, 0x1, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x0, 0x1, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_16) {
  s21_decimal dec_1 = {{0x0, 0x1, 0x0, 0x10000}};
  s21_decimal dec_check = {{0x1999999A, 0x0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_17) {
  s21_decimal dec_1 = {{0x0, 0x1, 0x0, 0x80020000}};  //
  s21_decimal dec_check = {{0x28F5C29, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_18) {
  s21_decimal dec_1 = {{0x0, 0x1, 0x0, 0x30000}};  //
  s21_decimal dec_check = {{0x418937, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_19) {
  s21_decimal dec_1 = {{0x0, 0x1, 0x0, 0x80000}};  //
  s21_decimal dec_check = {{0x2B, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_20) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0xD0000}};  //
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_21) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_22) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80010000}};
  s21_decimal dec_check = {{0x9999999A, 0x19999999, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_23) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0xB0000}};
  s21_decimal dec_check = {{0xAFEBFF1, 0x0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_24) {
  s21_decimal dec_1 = {{0x0, 0xFFFFFFFF, 0x0, 0x80010000}};
  s21_decimal dec_check = {{0x80000000, 0x19999999, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_25) {
  s21_decimal dec_1 = {{0x0, 0xFFFFFFFF, 0x0, 0x80110000}};
  s21_decimal dec_check = {{0xB8, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_26) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000000}};  //
  s21_decimal dec_check = {{0xFFFFFFFF, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_27) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0x0, 0x10000}};
  s21_decimal dec_check = {{0x1999999A, 0x0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_28) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0x0, 0x80010000}};
  s21_decimal dec_check = {{0x1999999A, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_29) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0x0, 0x20000}};  //
  s21_decimal dec_check = {{0x28F5C29, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_30) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0x0, 0x80020000}};
  s21_decimal dec_check = {{0x28F5C29, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_31) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  s21_decimal dec_check = {{0x2B, 0x0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_32) {
  s21_decimal dec_1 = {{0x97FFFFFF, 0x5D378391, 0x3077B58D, 0x1C0000}};
  s21_decimal dec_check = {{0x1, 0x0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_33) {
  s21_decimal dec_1 = {{0x98000001, 0x5D378391, 0x3077B58D, 0x1C0000}};  //
  s21_decimal dec_check = {{0x2, 0x0, 0x0, 0x0}};                        //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_34) {
  s21_decimal dec_1 = {{0x98000001, 0x5D378391, 0x3077B58D, 0x801C0000}};
  s21_decimal dec_check = {{0x2, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_35) {
  s21_decimal dec_1 = {{0x1E847F, 0x0, 0x0, 0x80060000}};  //
  s21_decimal dec_check = {{0x2, 0x0, 0x0, 0x80000000}};   //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_36) {
  s21_decimal dec_1 = {{0xEC25EE11, 0x79F56552, 0xA03CF9AA, 0x120000}};  //
  s21_decimal dec_check = {{0x8BDF6EA7, 0xB, 0x0, 0x0}};                 //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_37) {
  s21_decimal dec_1 = {{0x5FD8693A, 0xF38536E9, 0x2AD3F6DD, 0x80190000}};  //
  s21_decimal dec_check = {{0x52D, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_38) {
  s21_decimal dec_1 = {{0x256906D0, 0xA396C78B, 0x7E07AF5A, 0x80130000}};
  s21_decimal dec_check = {{0xE87BFE74, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_39) {
  s21_decimal dec_1 = {{0x27B442B8, 0x3DC44477, 0x1C2C6924, 0x800F0000}};
  s21_decimal dec_check = {{0x1CF6820B, 0x7EE, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_40) {
  s21_decimal dec_1 = {{0x8981396C, 0xD4F24636, 0x51B70968, 0x80140000}};
  s21_decimal dec_check = {{0xF12E195, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_round(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

Suite *suite_s21_round(void) {
  Suite *c = suite_create("s21_round_cases");
  TCase *tc_core = tcase_create("s21_round_tc");

  tcase_add_test(tc_core, invalid_dec_s21_round_1);
  tcase_add_test(tc_core, invalid_dec_s21_round_2);
  tcase_add_test(tc_core, invalid_dec_s21_round_3);
  tcase_add_test(tc_core, invalid_dec_s21_round_4);
  tcase_add_test(tc_core, invalid_dec_s21_round_5);
  tcase_add_test(tc_core, invalid_dec_s21_round_6);
  tcase_add_test(tc_core, invalid_dec_s21_round_7);

  tcase_add_test(tc_core, s21_round_1);
  tcase_add_test(tc_core, s21_round_2);
  tcase_add_test(tc_core, s21_round_3);
  tcase_add_test(tc_core, s21_round_4);
  tcase_add_test(tc_core, s21_round_5);
  tcase_add_test(tc_core, s21_round_6);
  tcase_add_test(tc_core, s21_round_7);
  tcase_add_test(tc_core, s21_round_8);
  tcase_add_test(tc_core, s21_round_9);
  tcase_add_test(tc_core, s21_round_10);
  tcase_add_test(tc_core, s21_round_11);
  tcase_add_test(tc_core, s21_round_12);
  tcase_add_test(tc_core, s21_round_13);
  tcase_add_test(tc_core, s21_round_14);
  tcase_add_test(tc_core, s21_round_15);
  tcase_add_test(tc_core, s21_round_16);
  tcase_add_test(tc_core, s21_round_17);
  tcase_add_test(tc_core, s21_round_18);
  tcase_add_test(tc_core, s21_round_19);
  tcase_add_test(tc_core, s21_round_20);
  tcase_add_test(tc_core, s21_round_21);
  tcase_add_test(tc_core, s21_round_22);
  tcase_add_test(tc_core, s21_round_23);
  tcase_add_test(tc_core, s21_round_24);
  tcase_add_test(tc_core, s21_round_25);
  tcase_add_test(tc_core, s21_round_26);
  tcase_add_test(tc_core, s21_round_27);
  tcase_add_test(tc_core, s21_round_28);
  tcase_add_test(tc_core, s21_round_29);
  tcase_add_test(tc_core, s21_round_30);
  tcase_add_test(tc_core, s21_round_31);
  tcase_add_test(tc_core, s21_round_32);
  tcase_add_test(tc_core, s21_round_33);
  tcase_add_test(tc_core, s21_round_34);
  tcase_add_test(tc_core, s21_round_35);
  tcase_add_test(tc_core, s21_round_36);
  tcase_add_test(tc_core, s21_round_37);
  tcase_add_test(tc_core, s21_round_38);
  tcase_add_test(tc_core, s21_round_39);
  tcase_add_test(tc_core, s21_round_40);

  suite_add_tcase(c, tc_core);
  return c;
}
