#include "../s21_tests.h"

START_TEST(invalid_dec_s21_truncate_1) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_truncate(dec_1, NULL);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_truncate_2) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_truncate_3) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_truncate_4) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_truncate_5) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_truncate_6) {
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x380000}};
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(invalid_dec_s21_truncate_7) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_ERROR);
}
END_TEST

START_TEST(s21_truncate_1) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  s21_decimal dec_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  s21_decimal dec_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_3) {
  s21_decimal dec_1 = {{0xA8B1DD68, 0xF858C391, 0x5F1B09D2, 0x140000}};
  s21_decimal dec_check = {{0x118B3C61, 0x0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_4) {
  s21_decimal dec_1 = {{0x9555C8F0, 0xE0B0D013, 0xF10A3BA0, 0x80030000}};
  s21_decimal dec_check = {{0x4480577F, 0xAE4E0035, 0x3DB4CB, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_5) {
  s21_decimal dec_1 = {{0x4155D537, 0xA999C35D, 0x415D26C6, 0xB0000}};
  s21_decimal dec_check = {{0x332CC94A, 0x2CEAEF2, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_6) {
  s21_decimal dec_1 = {{0x1C89A3E6, 0x1233D892, 0x706DE84D, 0x180000}};
  s21_decimal dec_check = {{0x87EB, 0x0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_7) {
  s21_decimal dec_1 = {{0x9B41E7D4, 0xCBC3B08B, 0x14590574, 0x800D0000}};
  s21_decimal dec_check = {{0xEA504E62, 0x23CBC, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_8) {
  s21_decimal dec_1 = {{0x64365EDD, 0xA98D0464, 0x4C71727C, 0x800A0000}};
  s21_decimal dec_check = {{0xE652472F, 0x20D50379, 0x0, 0x80000000}};
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_9) {
  s21_decimal dec_1 = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x140000}};
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_10) {
  s21_decimal dec_1 = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x80140000}};
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_11) {
  s21_decimal dec_1 = {{0xE6BF6481, 0x21096819, 0x97BC72CD, 0x90000}};
  s21_decimal dec_check = {{0xB264A84A, 0x8BB3A2BC, 0x2, 0x0}};
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_12) {
  s21_decimal dec_1 = {{0x29BD0E86, 0x789AE890, 0xF37BF67A, 0x80000000}};
  s21_decimal dec_check = {
      {0x29BD0E86, 0x789AE890, 0xF37BF67A, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_13) {
  s21_decimal dec_1 = {{0x3E55BD95, 0xA7D45A16, 0x9EC9011, 0x30000}};
  s21_decimal dec_check = {{0xC8411C17, 0x52580535, 0x28A62, 0x0}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_14) {
  s21_decimal dec_1 = {{0xD8415F6E, 0xF0B28E5E, 0x85F6D222, 0x150000}};
  s21_decimal dec_check = {{0x278A0B6, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_15) {
  s21_decimal dec_1 = {{0xD8415F6E, 0xF0B28E5E, 0x85F6D222, 0x80150000}};
  s21_decimal dec_check = {{0x278A0B6, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_16) {
  s21_decimal dec_1 = {{0x21D50F21, 0x99AB7C96, 0xBAC78E9E, 0x801C0000}};
  s21_decimal dec_check = {{0x5, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_17) {
  s21_decimal dec_1 = {{0x181A7DE, 0x5AF79424, 0x80172A0, 0x20000}};
  s21_decimal dec_check = {{0x3D747F1E, 0x1563C17B, 0x147E96, 0x0}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_18) {
  s21_decimal dec_1 = {{0xD3D886A2, 0x30680690, 0xE81C7418, 0x80150000}};
  s21_decimal dec_check = {{0x4481D28, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_19) {
  s21_decimal dec_1 = {{0xB3231627, 0x2B3B9762, 0x1FB13E98, 0x0}};
  s21_decimal dec_check = {{0xB3231627, 0x2B3B9762, 0x1FB13E98, 0x0}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_20) {
  s21_decimal dec_1 = {{0xCE3BC3D, 0xE49077A5, 0x406D23C5, 0x80020000}};
  s21_decimal dec_check = {{0x6916C1E1, 0xF15ECB7, 0xA4EE70, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_21) {
  s21_decimal dec_1 = {{0x2FEEE3CD, 0x4D7246A1, 0x8338B7AA, 0x800F0000}};
  s21_decimal dec_check = {{0x82656650, 0x24EF, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_22) {
  s21_decimal dec_1 = {{0x547899BF, 0x61506CE1, 0xBACA4FC7, 0x1B0000}};
  s21_decimal dec_check = {{0x39, 0x0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_23) {
  s21_decimal dec_1 = {{0xAE60C07F, 0x9A40295B, 0x27D2F744, 0x80120000}};
  s21_decimal dec_check = {{0xDE9FED37, 0x2, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_24) {
  s21_decimal dec_1 = {{0x9527ECA3, 0x6CB6E55B, 0x27D50173, 0x80070000}};
  s21_decimal dec_check = {{0x89008808, 0xD3BC95FD, 0x42, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_25) {
  s21_decimal dec_1 = {{0x64D661FB, 0x74903382, 0x36F0AA7F, 0x80150000}};
  s21_decimal dec_check = {{0x1037281, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_26) {
  s21_decimal dec_1 = {{0xB352B0D9, 0xB7F76AA2, 0x7CBD3518, 0x80040000}};
  s21_decimal dec_check = {{0xCC44891, 0x77D38EBB, 0x3317D, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_27) {
  s21_decimal dec_1 = {{0xC9E6AD18, 0xFF1C617D, 0x19D1FDA8, 0x800F0000}};
  s21_decimal dec_check = {{0x8C09B904, 0x744, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_28) {
  s21_decimal dec_1 = {{0x7B14DCC9, 0x672DB47A, 0xFE165EF1, 0xE0000}};
  s21_decimal dec_check = {{0x41DBD00A, 0x2CB31, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_29) {
  s21_decimal dec_1 = {{0x3899BBE7, 0x67C139A8, 0x8E3F22D2, 0x160000}};
  s21_decimal dec_check = {{0x432C8F, 0x0, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_30) {
  s21_decimal dec_1 = {{0x8AC1155B, 0xFDF19B7, 0xCCFE73A3, 0x801C0000}};
  s21_decimal dec_check = {{0x6, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_31) {
  s21_decimal dec_1 = {{0x17C17E76, 0x27C615EF, 0x3A4C3D4D, 0x80070000}};
  s21_decimal dec_check = {{0xE3D35D31, 0xCEB80A09, 0x61, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_32) {
  s21_decimal dec_1 = {{0x17C17E76, 0x27C615EF, 0x3A4C3D4D, 0x70000}};
  s21_decimal dec_check = {{0xE3D35D31, 0xCEB80A09, 0x61, 0x0}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_33) {
  s21_decimal dec_1 = {{0x16147FD3, 0x43F6BA66, 0x119E71C6, 0x80000}};
  s21_decimal dec_check = {{0x3A4734CB, 0xF4BA1CFD, 0x2, 0x0}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_34) {
  s21_decimal dec_1 = {{0x2734DF2C, 0x3345F96A, 0x27AA647A, 0xB0000}};
  s21_decimal dec_check = {{0xE531BBD3, 0x1B420B9, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_35) {
  s21_decimal dec_1 = {{0xEA88C01C, 0xFFCD6876, 0x6A493D48, 0x80160000}};
  s21_decimal dec_check = {{0x323133, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_36) {
  s21_decimal dec_1 = {{0x9977AD, 0x9BB9B0B7, 0x28396573, 0x90000}};
  s21_decimal dec_check = {{0x65DD3DD1, 0xACC2FAF6, 0x0, 0x0}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_37) {
  s21_decimal dec_1 = {{0x9B575401, 0x8A427AFE, 0xF39E6FB4, 0x800E0000}};
  s21_decimal dec_check = {{0xE9851D3D, 0x2ADB9, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_38) {
  s21_decimal dec_1 = {{0x6E6B2532, 0xF640C16B, 0x93BCCCDA, 0x80160000}};
  s21_decimal dec_check = {{0x45C45E, 0x0, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_39) {
  s21_decimal dec_1 = {{0xDF53C8B3, 0x33D782D, 0x2D2CEFFB, 0x80030000}};
  s21_decimal dec_check = {{0xDA976139, 0xBD2FEEF7, 0xB909F, 0x80000000}};
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_40) {
  s21_decimal dec_1 = {{0x38F8B5B0, 0xB3027414, 0xF73EA362, 0x80130000}};
  s21_decimal dec_check = {{0xC815FFCF, 0x1, 0x0, 0x80000000}};  //
  s21_decimal result;
  int result_value = s21_truncate(dec_1, &result);

  ck_assert_int_eq(result_value, OTHER_OK);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

Suite *suite_s21_truncate(void) {
  Suite *c = suite_create("s21_truncate_cases");
  TCase *tc_core = tcase_create("s21_truncate_tc");

  tcase_add_test(tc_core, invalid_dec_s21_truncate_1);
  tcase_add_test(tc_core, invalid_dec_s21_truncate_2);
  tcase_add_test(tc_core, invalid_dec_s21_truncate_3);
  tcase_add_test(tc_core, invalid_dec_s21_truncate_4);
  tcase_add_test(tc_core, invalid_dec_s21_truncate_5);
  tcase_add_test(tc_core, invalid_dec_s21_truncate_6);
  tcase_add_test(tc_core, invalid_dec_s21_truncate_7);

  tcase_add_test(tc_core, s21_truncate_1);
  tcase_add_test(tc_core, s21_truncate_2);
  tcase_add_test(tc_core, s21_truncate_3);
  tcase_add_test(tc_core, s21_truncate_4);
  tcase_add_test(tc_core, s21_truncate_5);
  tcase_add_test(tc_core, s21_truncate_6);
  tcase_add_test(tc_core, s21_truncate_7);
  tcase_add_test(tc_core, s21_truncate_8);
  tcase_add_test(tc_core, s21_truncate_9);
  tcase_add_test(tc_core, s21_truncate_10);
  tcase_add_test(tc_core, s21_truncate_11);
  tcase_add_test(tc_core, s21_truncate_12);
  tcase_add_test(tc_core, s21_truncate_13);
  tcase_add_test(tc_core, s21_truncate_14);
  tcase_add_test(tc_core, s21_truncate_15);
  tcase_add_test(tc_core, s21_truncate_16);
  tcase_add_test(tc_core, s21_truncate_17);
  tcase_add_test(tc_core, s21_truncate_18);
  tcase_add_test(tc_core, s21_truncate_19);
  tcase_add_test(tc_core, s21_truncate_20);
  tcase_add_test(tc_core, s21_truncate_21);
  tcase_add_test(tc_core, s21_truncate_22);
  tcase_add_test(tc_core, s21_truncate_23);
  tcase_add_test(tc_core, s21_truncate_24);
  tcase_add_test(tc_core, s21_truncate_25);
  tcase_add_test(tc_core, s21_truncate_26);
  tcase_add_test(tc_core, s21_truncate_27);
  tcase_add_test(tc_core, s21_truncate_28);
  tcase_add_test(tc_core, s21_truncate_29);
  tcase_add_test(tc_core, s21_truncate_30);
  tcase_add_test(tc_core, s21_truncate_31);
  tcase_add_test(tc_core, s21_truncate_32);
  tcase_add_test(tc_core, s21_truncate_33);
  tcase_add_test(tc_core, s21_truncate_34);
  tcase_add_test(tc_core, s21_truncate_35);
  tcase_add_test(tc_core, s21_truncate_36);
  tcase_add_test(tc_core, s21_truncate_37);
  tcase_add_test(tc_core, s21_truncate_38);
  tcase_add_test(tc_core, s21_truncate_39);
  tcase_add_test(tc_core, s21_truncate_40);

  suite_add_tcase(c, tc_core);
  return c;
}
