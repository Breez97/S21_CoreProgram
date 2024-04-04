#include "../s21_tests.h"

START_TEST(invalid_dec_s21_negate_1) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_negate(dec_1, NULL);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_negate_2) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x380000}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_negate_3) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_negate_4) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_negate_5) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_negate_6) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(s21_negate_1) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  s21_decimal dec_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_2) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};  //
  s21_decimal dec_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_3) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  s21_decimal dec_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_4) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};  //
  s21_decimal dec_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_5) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  s21_decimal dec_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_6) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};    //
  s21_decimal dec_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_7) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};  //
  s21_decimal dec_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_8) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  s21_decimal dec_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_9) {
  s21_decimal dec_1 = {{0x63, 0x0, 0x0, 0x80020000}};
  s21_decimal dec_check = {{0x63, 0x0, 0x0, 0x20000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_10) {
  s21_decimal dec_1 = {{0x3E7, 0x0, 0x0, 0x80030000}};
  s21_decimal dec_check = {{0x3E7, 0x0, 0x0, 0x30000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_11) {
  s21_decimal dec_1 = {{0x6E41CDAA, 0xF41B262C, 0x19128D66, 0x80060000}};
  s21_decimal dec_check = {{0x6E41CDAA, 0xF41B262C, 0x19128D66, 0x60000}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_12) {
  s21_decimal dec_1 = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0xA0000}};  //
  s21_decimal dec_check = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x800A0000}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_13) {
  s21_decimal dec_1 = {{0x63, 0x0, 0x0, 0x20000}};
  s21_decimal dec_check = {{0x63, 0x0, 0x0, 0x80020000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_14) {
  s21_decimal dec_1 = {{0x3E7, 0x0, 0x0, 0x80030000}};
  s21_decimal dec_check = {{0x3E7, 0x0, 0x0, 0x30000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_15) {
  s21_decimal dec_1 = {{0xF423F, 0x0, 0x0, 0x60000}};         //
  s21_decimal dec_check = {{0xF423F, 0x0, 0x0, 0x80060000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_16) {
  s21_decimal dec_1 = {{0x5F5E0FF, 0x0, 0x0, 0x80000}};  //
  s21_decimal dec_check = {{0x5F5E0FF, 0x0, 0x0, 0x80080000}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_17) {
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x80010000}};  //
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_18) {
  s21_decimal dec_1 = {{0xB4B864E6, 0xE577A195, 0x164CDC47, 0x80020000}};
  s21_decimal dec_check = {{0xB4B864E6, 0xE577A195, 0x164CDC47, 0x20000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_19) {
  s21_decimal dec_1 = {{0xC039180E, 0x17BEB589, 0x30CBCBE7, 0x110000}};  //
  s21_decimal dec_check = {{0xC039180E, 0x17BEB589, 0x30CBCBE7, 0x80110000}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_20) {
  s21_decimal dec_1 = {{0x7166F92F, 0x636702FE, 0x50EEC429, 0x10000}};  //
  s21_decimal dec_check = {
      {0x7166F92F, 0x636702FE, 0x50EEC429, 0x80010000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_21) {
  s21_decimal dec_1 = {{0xD17CC169, 0xC8328AFD, 0xC7752474, 0x80060000}};
  s21_decimal dec_check = {{0xD17CC169, 0xC8328AFD, 0xC7752474, 0x60000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_22) {
  s21_decimal dec_1 = {{0x91B5F8B3, 0xCEB2D42A, 0xA0D2B36, 0x80070000}};   //
  s21_decimal dec_check = {{0x91B5F8B3, 0xCEB2D42A, 0xA0D2B36, 0x70000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_23) {
  s21_decimal dec_1 = {{0x8DBC44A, 0x995466F5, 0x79B97245, 0x1C0000}};
  s21_decimal dec_check = {{0x8DBC44A, 0x995466F5, 0x79B97245, 0x801C0000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_24) {
  s21_decimal dec_1 = {{0x8DBC44A, 0x995466F5, 0x79B97245, 0x801C0000}};
  s21_decimal dec_check = {{0x8DBC44A, 0x995466F5, 0x79B97245, 0x1C0000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_25) {
  s21_decimal dec_1 = {{0x48BC2FBD, 0xCADABF47, 0xC862CC84, 0x801C0000}};    //
  s21_decimal dec_check = {{0x48BC2FBD, 0xCADABF47, 0xC862CC84, 0x1C0000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_26) {
  s21_decimal dec_1 = {{0xC98CA81, 0xFB036440, 0x283C604B, 0x800F0000}};
  s21_decimal dec_check = {{0xC98CA81, 0xFB036440, 0x283C604B, 0xF0000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_27) {
  s21_decimal dec_1 = {{0x4B70A11, 0xECD258D0, 0xDA67C2C7, 0x30000}};         //
  s21_decimal dec_check = {{0x4B70A11, 0xECD258D0, 0xDA67C2C7, 0x80030000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_28) {
  s21_decimal dec_1 = {{0x3BB33CC9, 0xEF2DC0A1, 0x38061DC8, 0x800F0000}};
  s21_decimal dec_check = {{0x3BB33CC9, 0xEF2DC0A1, 0x38061DC8, 0xF0000}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_29) {
  s21_decimal dec_1 = {{0xA13B98EC, 0xEDD699C3, 0x7BF3F1D7, 0x160000}};
  s21_decimal dec_check = {
      {0xA13B98EC, 0xEDD699C3, 0x7BF3F1D7, 0x80160000}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_30) {
  s21_decimal dec_1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  s21_decimal dec_check = {{0x55555555, 0x0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_31) {
  s21_decimal dec_1 = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x140000}};
  s21_decimal dec_check = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x80140000}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_32) {
  s21_decimal dec_1 = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x80140000}};
  s21_decimal dec_check = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x140000}};
  s21_decimal result;
  int result_value = s21_negate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

Suite *suite_s21_negate(void) {
  Suite *c = suite_create("s21_negate_cases");
  TCase *tc_core = tcase_create("s21_negate_tc");

  tcase_add_test(tc_core, invalid_dec_s21_negate_1);
  tcase_add_test(tc_core, invalid_dec_s21_negate_2);
  tcase_add_test(tc_core, invalid_dec_s21_negate_3);
  tcase_add_test(tc_core, invalid_dec_s21_negate_4);
  tcase_add_test(tc_core, invalid_dec_s21_negate_5);
  tcase_add_test(tc_core, invalid_dec_s21_negate_6);

  tcase_add_test(tc_core, s21_negate_1);
  tcase_add_test(tc_core, s21_negate_2);
  tcase_add_test(tc_core, s21_negate_3);
  tcase_add_test(tc_core, s21_negate_4);
  tcase_add_test(tc_core, s21_negate_5);
  tcase_add_test(tc_core, s21_negate_6);
  tcase_add_test(tc_core, s21_negate_7);
  tcase_add_test(tc_core, s21_negate_8);
  tcase_add_test(tc_core, s21_negate_9);
  tcase_add_test(tc_core, s21_negate_10);
  tcase_add_test(tc_core, s21_negate_11);
  tcase_add_test(tc_core, s21_negate_12);
  tcase_add_test(tc_core, s21_negate_13);
  tcase_add_test(tc_core, s21_negate_14);
  tcase_add_test(tc_core, s21_negate_15);
  tcase_add_test(tc_core, s21_negate_16);
  tcase_add_test(tc_core, s21_negate_17);
  tcase_add_test(tc_core, s21_negate_18);
  tcase_add_test(tc_core, s21_negate_19);
  tcase_add_test(tc_core, s21_negate_20);
  tcase_add_test(tc_core, s21_negate_21);
  tcase_add_test(tc_core, s21_negate_22);
  tcase_add_test(tc_core, s21_negate_23);
  tcase_add_test(tc_core, s21_negate_24);
  tcase_add_test(tc_core, s21_negate_25);
  tcase_add_test(tc_core, s21_negate_26);
  tcase_add_test(tc_core, s21_negate_27);
  tcase_add_test(tc_core, s21_negate_28);
  tcase_add_test(tc_core, s21_negate_29);
  tcase_add_test(tc_core, s21_negate_30);
  tcase_add_test(tc_core, s21_negate_31);
  tcase_add_test(tc_core, s21_negate_32);

  suite_add_tcase(c, tc_core);
  return c;
}