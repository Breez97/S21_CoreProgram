#include "../s21_tests.h"

START_TEST(invalid_dec_s21_div_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_div(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 4);
}
END_TEST
START_TEST(invalid_dec_s21_div_2) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_3) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_4) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_5) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_6) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_7) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_8) {
  // Все биты имеют максимальное значение
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_9) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_10) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_11) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_12) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_13) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_14) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_15) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_16) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_div_1) {
  // -5100517454379037327752501909
  s21_decimal dec_1 = {{0xddc51a95, 0x3ded1da9, 0x107b0c95, 0x80000000}};
  // -714402130.51097
  s21_decimal dec_2 = {{0x788586d9, 0x40f9, 0x0, 0x80050000}};
  // 7139560811123191836.0782107082
  s21_decimal dec_check = {{0x4aaaf1ca, 0x18da1e7, 0xe6b11017, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_2) {
  // 7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x0}};
  // 56
  s21_decimal dec_2 = {{0x38, 0x0, 0x0, 0x0}};
  // 0.125
  s21_decimal dec_check = {{0x7d, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_3) {
  // -731453
  s21_decimal dec_1 = {{0xb293d, 0x0, 0x0, 0x80000000}};
  // -46463
  s21_decimal dec_2 = {{0xb57f, 0x0, 0x0, 0x80000000}};
  // 15.742698491272625529991606224
  s21_decimal dec_check = {{0xeae62fd0, 0x404843de, 0x32de0e13, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_4) {
  // 1026615223.033993108262
  s21_decimal dec_1 = {{0xdd941b26, 0xa725f21b, 0x37, 0xc0000}};
  // 7.337158
  s21_decimal dec_2 = {{0x6ff4c6, 0x0, 0x0, 0x60000}};
  // 139920010.31380176197132459189
  s21_decimal dec_check = {{0x79df9cb5, 0xc83711ab, 0x2d35e977, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_5) {
  // -1436751478791.684
  s21_decimal dec_1 = {{0xc5861e04, 0x51ab7, 0x0, 0x80030000}};
  // -0.313
  s21_decimal dec_2 = {{0x139, 0x0, 0x0, 0x80030000}};
  // 4590260315628.3833865814696486
  s21_decimal dec_check = {{0x1cec6226, 0x3d389fed, 0x9451be4f, 0x100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_6) {
  // -4987410761316199.72392831
  s21_decimal dec_1 = {{0xac55277f, 0xced35a3c, 0x699c, 0x80080000}};
  // 7.5
  s21_decimal dec_2 = {{0x4b, 0x0, 0x0, 0x10000}};
  // -664988101508826.629857108
  s21_decimal dec_check = {{0xe5c6df54, 0x13c47850, 0x8cd1, 0x80090000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_7) {
  // -3709456918915431622
  s21_decimal dec_1 = {{0x991bcc6, 0x337aa36a, 0x0, 0x80000000}};
  // 5551666
  s21_decimal dec_2 = {{0x54b632, 0x0, 0x0, 0x0}};
  // -668170044616.41453610501784509
  s21_decimal dec_check = {{0x8c6dc3bd, 0xd073b157, 0xd7e5bb0d, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_8) {
  // -742783.419
  s21_decimal dec_1 = {{0x2c45f9bb, 0x0, 0x0, 0x80030000}};
  // -394803
  s21_decimal dec_2 = {{0x60633, 0x0, 0x0, 0x80000000}};
  // 1.8814026717122210317550778490
  s21_decimal dec_check = {{0x92d4787a, 0xfec628c5, 0x3cca991f, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_9) {
  // 3547154.189668518795
  s21_decimal dec_1 = {{0x1ebb0b8b, 0x313a05f1, 0x0, 0xc0000}};
  // 902238
  s21_decimal dec_2 = {{0xdc45e, 0x0, 0x0, 0x0}};
  // 3.9315060878266253416504292659
  s21_decimal dec_check = {{0x1070f533, 0xc7e2f447, 0x7f08a7f8, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_10) {
  // -32702.13
  s21_decimal dec_1 = {{0x31e645, 0x0, 0x0, 0x80020000}};
  // 4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x0}};
  // -8175.5325
  s21_decimal dec_check = {{0x4df7cbd, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_11) {
  // -53090953226694
  s21_decimal dec_1 = {{0x336869c6, 0x3049, 0x0, 0x80000000}};
  // -83
  s21_decimal dec_2 = {{0x53, 0x0, 0x0, 0x80000000}};
  // 639650038875.83132530120481928
  s21_decimal dec_check = {{0xe72a5c88, 0xe5e7d079, 0xceae9c70, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_12) {
  // 784922183805403224.1504864
  s21_decimal dec_1 = {{0xf74ab260, 0x2b1ffe81, 0x67e23, 0x70000}};
  // 3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x0}};
  // 261640727935134408.05016213333
  s21_decimal dec_check = {{0xf1f29755, 0x30973c43, 0x548a69ec, 0xb0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_13) {
  // -90041096477221121
  s21_decimal dec_1 = {{0x72b62101, 0x13fe3e6, 0x0, 0x80000000}};
  // -877824223407.4
  s21_decimal dec_2 = {{0xd80296da, 0x7fb, 0x0, 0x80010000}};
  // 102573.03692043693553739401933
  s21_decimal dec_check = {{0xe84c8acd, 0x567e82d0, 0x2124a48b, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_14) {
  // -32439080.2859330
  s21_decimal dec_1 = {{0x1e92a542, 0x12708, 0x0, 0x80070000}};
  // 4535256.6044467103
  s21_decimal dec_2 = {{0x24bb9f9f, 0xa11feb, 0x0, 0xa0000}};
  // -7.1526449581986739167382254067
  s21_decimal dec_check = {{0xf85cb1f3, 0x5926a8f6, 0xe71d4ad9, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_15) {
  // 7768584585603897615507078372
  s21_decimal dec_1 = {{0x3d853ce4, 0x3e11b029, 0x191a05c6, 0x0}};
  // -76927674838
  s21_decimal dec_2 = {{0xe93f29d6, 0x11, 0x0, 0x80000000}};
  // -100985563413473225.18833099860
  s21_decimal dec_check = {{0xcb3e7454, 0x367a2c63, 0x20a1547c, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_16) {
  // 52602
  s21_decimal dec_1 = {{0xcd7a, 0x0, 0x0, 0x0}};
  // -0.11
  s21_decimal dec_2 = {{0xb, 0x0, 0x0, 0x80020000}};
  // -478200
  s21_decimal dec_check = {{0x74BF8, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_17) {
  // -7456
  s21_decimal dec_1 = {{0x1d20, 0x0, 0x0, 0x80000000}};
  // 0.441036430510
  s21_decimal dec_2 = {{0xafd1dcae, 0x66, 0x0, 0xc0000}};
  // -16905.632923289641196130403536
  s21_decimal dec_check = {{0xe93804d0, 0x22373538, 0x36a00305, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_18) {
  // 78374291925
  s21_decimal dec_1 = {{0x3f78c9d5, 0x12, 0x0, 0x0}};
  // 1.40
  s21_decimal dec_2 = {{0x8c, 0x0, 0x0, 0x20000}};
  // 55981637089.285714285714285714
  s21_decimal dec_check = {{0xfe252492, 0x932ed120, 0xb4e2ecc3, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_19) {
  // -30540840000.240323
  s21_decimal dec_1 = {{0x6f5b3ac3, 0x6c80bb, 0x0, 0x80060000}};
  // -9267.7
  s21_decimal dec_2 = {{0x16a05, 0x0, 0x0, 0x80010000}};
  // 3295406.6273444676672745125544
  s21_decimal dec_check = {{0xcfc436a8, 0x4b8526d3, 0x6a7af6f8, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_20) {
  // -56731684570845025243234138958
  s21_decimal dec_1 = {{0x4c5d7b4e, 0x60c728a, 0xb74f597f, 0x80000000}};
  // -87.08658
  s21_decimal dec_2 = {{0x84e232, 0x0, 0x0, 0x80050000}};
  // 651440033250186483878849519.16
  s21_decimal dec_check = {{0xbd58296c, 0x782b1122, 0xd27ddb48, 0x20000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_21) {
  // 2206273890184301.3
  s21_decimal dec_1 = {{0xb3043c45, 0x4e61f1, 0x0, 0x10000}};
  // 46
  s21_decimal dec_2 = {{0x2e, 0x0, 0x0, 0x0}};
  // 47962475873571.767391304347826
  s21_decimal dec_check = {{0x3dbcf0b2, 0xfed96c59, 0x9af9a152, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_22) {
  // 733467050980153106698846
  s21_decimal dec_1 = {{0xa811125e, 0x5418f776, 0x9b51, 0x0}};
  // -4157.3524521495612
  s21_decimal dec_2 = {{0x792a2c3c, 0x93b2e6, 0x0, 0x800d0000}};
  // -176426478010281181456.07124824
  s21_decimal dec_check = {{0x80ebc758, 0xb6ac2c7b, 0x3901a7fd, 0x80080000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_23) {
  // 39015369
  s21_decimal dec_1 = {{0x25353c9, 0x0, 0x0, 0x0}};
  // -6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x80000000}};
  // -6502561.5
  s21_decimal dec_check = {{0x3e0364f, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_24) {
  // -402953711440
  s21_decimal dec_1 = {{0xd1e9af50, 0x5d, 0x0, 0x80000000}};
  // -1752900.7194352
  s21_decimal dec_2 = {{0x4a3f40f0, 0xff1, 0x0, 0x80070000}};
  // 229878.22811199211740734132844
  s21_decimal dec_check = {{0x9c17926c, 0xa1759fe9, 0x4a4714d3, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_25) {
  // 69.554
  s21_decimal dec_1 = {{0x10fb2, 0x0, 0x0, 0x30000}};
  // -4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x80000000}};
  // -17.3885
  s21_decimal dec_check = {{0x2a73d, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_26) {
  // 6741980134382531463.9
  s21_decimal dec_1 = {{0xe61c834f, 0xa7a3401d, 0x3, 0x10000}};
  // 29140350267520
  s21_decimal dec_2 = {{0xc439f080, 0x1a80, 0x0, 0x0}};
  // 231362.35743525639200696662910
  s21_decimal dec_check = {{0xfda77b7e, 0xd0389dd5, 0x4ac1d87c, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_27) {
  // 3477045171.538
  s21_decimal dec_1 = {{0x900ad552, 0x329, 0x0, 0x30000}};
  // -623207.5014275
  s21_decimal dec_2 = {{0x49e1083, 0x5ab, 0x0, 0x80070000}};
  // -5579.2736184554693415191850467
  s21_decimal dec_check = {{0x2fa22de3, 0x29f20f9, 0xb446ab71, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_28) {
  // -23386584739100770039965830868
  s21_decimal dec_1 = {{0xf0d64ed4, 0xeb65996, 0x4b90edf3, 0x80000000}};
  // -64123114511031860788
  s21_decimal dec_2 = {{0xb1bffe34, 0x79e310e8, 0x3, 0x80000000}};
  // 364713799.65608654543280741334
  s21_decimal dec_check = {{0x7d011bd6, 0x9ce468ff, 0x75d86b1d, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_29) {
  // 8765220672190454739816160442
  s21_decimal dec_1 = {{0xbd881cba, 0xc153f337, 0x1c526bac, 0x0}};
  // -46243418722706444870685
  s21_decimal dec_2 = {{0x25b5641d, 0xdc5a402b, 0x9ca, 0x80000000}};
  // -189545.25669371749580876958708
  s21_decimal dec_check = {{0x7a064bf4, 0x75503c5e, 0x3d3ed0ef, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_30) {
  // 788026919110837130923336.7917
  s21_decimal dec_1 = {{0x486eeb6d, 0xd6a8de9a, 0x197667e8, 0x40000}};
  // -3444.4
  s21_decimal dec_2 = {{0x868c, 0x0, 0x0, 0x80010000}};
  // -228784960838124820265.74636851
  s21_decimal dec_check = {{0xedcae733, 0xdd104bf1, 0x49eca5fd, 0x80080000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_32) {
  // -552965453580044352
  s21_decimal dec_1 = {{0x79b38840, 0x7ac8726, 0x0, 0x80000000}};
  // -9160.618835321698567
  s21_decimal dec_2 = {{0xb21a3907, 0x7f210e4b, 0x0, 0x800f0000}};
  // 60363329543623.081593533816175
  s21_decimal dec_check = {{0x4c66dd6f, 0x7b941efd, 0xc30b603b, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_33) {
  // -326548623449786811749
  s21_decimal dec_1 = {{0x19560565, 0xb3c5c2e6, 0x11, 0x80000000}};
  // 9848235537939
  s21_decimal dec_2 = {{0xf894b613, 0x8f4, 0x0, 0x0}};
  // -33158084.226540099927372283985
  s21_decimal dec_check = {{0xd3054051, 0xb190240f, 0x6b23b973, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_34) {
  // 355362481912
  s21_decimal dec_1 = {{0xbd4126f8, 0x52, 0x0, 0x0}};
  // 906129
  s21_decimal dec_2 = {{0xdd391, 0x0, 0x0, 0x0}};
  // 392176.48029364472387485667052
  s21_decimal dec_check = {{0xded98eec, 0xa912ab9e, 0x7eb813ff, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_35) {
  // 33243186259002801400
  s21_decimal dec_1 = {{0xca023cf8, 0xcd5785c5, 0x1, 0x0}};
  // 83503.76935
  s21_decimal dec_2 = {{0xf1b8a3e7, 0x1, 0x0, 0x50000}};
  // 398104019947487.57290679118307
  s21_decimal dec_check = {{0x5ad1a9e3, 0x82eaa872, 0x80a26488, 0xe0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_36) {
  // 9232978
  s21_decimal dec_1 = {{0x8ce252, 0x0, 0x0, 0x0}};
  // -1753.00430256327874
  s21_decimal dec_2 = {{0x266ccc2, 0x26ecad0, 0x0, 0x800e0000}};
  // -5266.9454299110109169549359489
  s21_decimal dec_check = {{0xcb981, 0xbc6e55cf, 0xaa2f26c6, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_37) {
  // -407348971030840714170553
  s21_decimal dec_1 = {{0x230790b9, 0x6e956d34, 0x5642, 0x80000000}};
  // 58486489853869243913
  s21_decimal dec_2 = {{0xbb5d3e09, 0x2ba9c0a5, 0x3, 0x0}};
  // -6964.8387524814340387789180632
  s21_decimal dec_check = {{0xe0fd8ed8, 0x39ce1208, 0xe10bcbbd, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_38) {
  // -69582312691167388816555
  s21_decimal dec_1 = {{0x5314d4ab, 0x109219b9, 0xebc, 0x80000000}};
  // -599414
  s21_decimal dec_2 = {{0x92576, 0x0, 0x0, 0x80000000}};
  // 116083896424119871.76901940896
  s21_decimal dec_check = {{0xfd2996a0, 0x77d31f58, 0x25823c1f, 0xb0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_39) {
  // 181461778213170707999913
  s21_decimal dec_1 = {{0x45c8aca9, 0x100da32c, 0x266d, 0x0}};
  // -156494683001505775763
  s21_decimal dec_2 = {{0xa61d0093, 0x7bcccd0b, 0x8, 0x80000000}};
  // -1159.5395749734494264682376365
  s21_decimal dec_check = {{0xd3686cad, 0x2272ed7e, 0x25777c8f, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_40) {
  // 36590812115604416
  s21_decimal dec_1 = {{0x563193c0, 0x81ff26, 0x0, 0x0}};
  // 8575210388221774
  s21_decimal dec_2 = {{0xc1106f4e, 0x1e771b, 0x0, 0x0}};
  // 4.2670454086890557432622367226
  s21_decimal dec_check = {{0xb8e241fa, 0x18f4d270, 0x89e02c1f, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_41) {
  // 571822736944903098432.68
  s21_decimal dec_1 = {{0xea9e5944, 0xdb75f077, 0xc1b, 0x20000}};
  // 5090466550
  s21_decimal dec_2 = {{0x2f6a5af6, 0x1, 0x0, 0x0}};
  // 112332088096.11038470190517213
  s21_decimal dec_check = {{0xadd1cbdd, 0xc4a76da6, 0x244be47d, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_44) {
  // -27038829050066426727607558141
  s21_decimal dec_1 = {{0xba4bdffd, 0xe097594c, 0x575dfec3, 0x80000000}};
  // 528423174152005
  s21_decimal dec_2 = {{0x1b961f45, 0x1e099, 0x0, 0x0}};
  // -51168893365544.371624356478227
  s21_decimal dec_check = {{0xcd45fd13, 0x87b5b08e, 0xa555eaa3, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_45) {
  // 7347865267562302508707215500
  s21_decimal dec_1 = {{0x6ab9f88c, 0x4fa3b1df, 0x17be02fe, 0x0}};
  // -1463.57155443
  s21_decimal dec_2 = {{0x1390f673, 0x22, 0x0, 0x80080000}};
  // -5020502923359964573117434.8402
  s21_decimal dec_check = {{0x5cddf672, 0x3d047dba, 0xa238a078, 0x80040000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_46) {
  // -73707773318451
  s21_decimal dec_1 = {{0x6da55533, 0x4309, 0x0, 0x80000000}};
  // 4006.4780
  s21_decimal dec_2 = {{0x263570c, 0x0, 0x0, 0x40000}};
  // -18397149146.569880079211716625
  s21_decimal dec_check = {{0xad246011, 0x9ccfc654, 0x3b71c3dd, 0x80120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_47) {
  // -3755389092.3736
  s21_decimal dec_1 = {{0xb25414d8, 0x2227, 0x0, 0x80040000}};
  // 6085.535
  s21_decimal dec_2 = {{0x5cdb9f, 0x0, 0x0, 0x30000}};
  // -617100.89455957446633697776777
  s21_decimal dec_check = {{0xb34f1489, 0x9f06954c, 0xc76563bc, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_48) {
  // -572255998377818491
  s21_decimal dec_1 = {{0x6fe5797b, 0x7f10fcc, 0x0, 0x80000000}};
  // 9190697599341.73025
  s21_decimal dec_2 = {{0xc4ae0f61, 0xcc13113, 0x0, 0x50000}};
  // -62264.696688399959685638973625
  s21_decimal dec_check = {{0x62bce8b9, 0xef8ac9cc, 0xc9302662, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_49) {
  // -18427830170170
  s21_decimal dec_1 = {{0x9045723a, 0x10c2, 0x0, 0x80000000}};
  // -32322.404225676470889083
  s21_decimal dec_2 = {{0xceebaa7b, 0x33779fd0, 0x6d8, 0x80120000}};
  // 570125602.09030448838973985820
  s21_decimal dec_check = {{0xa182141c, 0xe12b9f44, 0xb837af39, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_50) {
  // -467236.36
  s21_decimal dec_1 = {{0x2c8f234, 0x0, 0x0, 0x80020000}};
  // -401461.407137534439905
  s21_decimal dec_2 = {{0x535f1e1, 0xc3656ec2, 0x15, 0x800f0000}};
  // 1.1638387941980487387178932571
  s21_decimal dec_check = {{0x8001195b, 0x8bd4e368, 0x259b0c82, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_52) {
  // 6472606420907616
  s21_decimal dec_1 = {{0x1e7d3660, 0x16fecd, 0x0, 0x0}};
  // -5527157
  s21_decimal dec_2 = {{0x545675, 0x0, 0x0, 0x80000000}};
  // -1171055285.9105713841673033713
  s21_decimal dec_check = {{0x4f57f1, 0x8add2f53, 0x25d6be06, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_53) {
  // -90132437974872.13363329132891
  s21_decimal dec_1 = {{0xc442695b, 0x51a09850, 0x1d1f949d, 0x800e0000}};
  // -58281516341789.373
  s21_decimal dec_2 = {{0xf68602bd, 0xcf0eba, 0x0, 0x80030000}};
  // 1.5465012517226635021519858993
  s21_decimal dec_check = {{0x74cead31, 0x6f4408a4, 0x31f85bc8, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_54) {
  // 7369500
  s21_decimal dec_1 = {{0x70731c, 0x0, 0x0, 0x0}};
  // 51.90408
  s21_decimal dec_2 = {{0x4f3308, 0x0, 0x0, 0x50000}};
  // 141983.05797925712198347413151
  s21_decimal dec_check = {{0x8fb2569f, 0x96132384, 0x2de09033, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_56) {
  // -86246
  s21_decimal dec_1 = {{0x150e6, 0x0, 0x0, 0x80000000}};
  // 54
  s21_decimal dec_2 = {{0x36, 0x0, 0x0, 0x0}};
  // -1597.1481481481481481481481481
  s21_decimal dec_check = {{0x4e25ed09, 0x702613, 0x339b4cc2, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_57) {
  // -35546600950327316925181111429
  s21_decimal dec_1 = {{0x6c7cac85, 0xbdb2be98, 0x72db758a, 0x80000000}};
  // 3184794567517975363738
  s21_decimal dec_2 = {{0x8ebc409a, 0xa5e73964, 0xac, 0x0}};
  // -11161348.148753612702964651207
  s21_decimal dec_check = {{0x52be14c7, 0x898b9baa, 0x24107367, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_58) {
  // 75875205774271402621.436211
  s21_decimal dec_1 = {{0x2bf28133, 0x259c0e88, 0x3ec333, 0x60000}};
  // -6318017560.966
  s21_decimal dec_2 = {{0x7314186, 0x5bf, 0x0, 0x80030000}};
  // -12009337587.638864129997300649
  s21_decimal dec_check = {{0x42663a9, 0x21a99a2b, 0x26cde427, 0x80120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_59) {
  // -286717623
  s21_decimal dec_1 = {{0x1116f6b7, 0x0, 0x0, 0x80000000}};
  // -0.553840785378318241987967632
  s21_decimal dec_2 = {{0x59623a90, 0x22cb29e7, 0x1ca2059, 0x801b0000}};
  // 517689615.08341891962003719704
  s21_decimal dec_check = {{0xabdb0618, 0xbbaeda3b, 0xa7464802, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_60) {
  // -184272712998038881607629.21193
  s21_decimal dec_1 = {{0xed9680e9, 0xcfb528f4, 0x3b8aae7a, 0x80050000}};
  // 71372604
  s21_decimal dec_2 = {{0x4410f3c, 0x0, 0x0, 0x0}};
  // -2581840967971952.9584156578052
  s21_decimal dec_check = {{0xf6e59104, 0x3e5ed538, 0x536c7ce9, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_61) {
  // 2626569281650
  s21_decimal dec_1 = {{0x8bbaa072, 0x263, 0x0, 0x0}};
  // 715044
  s21_decimal dec_2 = {{0xae924, 0x0, 0x0, 0x0}};
  // 3673297.4217670520974933011115
  s21_decimal dec_check = {{0x11d8aaab, 0x6ec0306d, 0x76b0cdda, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_62) {
  // -93038212892907121377968249
  s21_decimal dec_1 = {{0xf2b68079, 0xa08bc8c4, 0x4cf59b, 0x80000000}};
  // -0.26
  s21_decimal dec_2 = {{0x1a, 0x0, 0x0, 0x80020000}};
  // 357839280357335082222954803.85
  s21_decimal dec_check = {{0x936c1841, 0xd2032cd1, 0x739fc581, 0x20000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_63) {
  // 8793259538.088327153600905896
  s21_decimal dec_1 = {{0x36f42a8, 0xb8a15fd1, 0x1c699d22, 0x120000}};
  // 8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x0}};
  // 1099157442.261040894200113237
  s21_decimal dec_check = {{0x206de855, 0x57142bfa, 0x38d33a4, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_64) {
  // -8133907030015728311055
  s21_decimal dec_1 = {{0x4c0e5b0f, 0xf0a2c483, 0x1b8, 0x80000000}};
  // 7784547190369238026
  s21_decimal dec_2 = {{0xe3393c0a, 0x6c08446c, 0x0, 0x0}};
  // -1044.8786334134766015907253120
  s21_decimal dec_check = {{0xf5aa4b80, 0x2a50531e, 0x21c30892, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_65) {
  // -9697110264984601636680
  s21_decimal dec_1 = {{0xe93c2f48, 0xae704882, 0x20d, 0x80000000}};
  // -2878367111938879890.6324101
  s21_decimal dec_2 = {{0x2b74d485, 0xf01ff290, 0x17cf2d, 0x80070000}};
  // 3368.9622928093381371541300377
  s21_decimal dec_check = {{0xc39ba499, 0x715c5746, 0x6cdb6726, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_66) {
  // -99050068433661411278059
  s21_decimal dec_1 = {{0x38813ceb, 0x83d502a9, 0x14f9, 0x80000000}};
  // 79820303552510306729706
  s21_decimal dec_2 = {{0x3b32beea, 0x113c46ea, 0x10e7, 0x0}};
  // -1.2409132015953895544551969490
  s21_decimal dec_check = {{0x503512d2, 0x8490a400, 0x281897ea, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_67) {
  // 3117548418286
  s21_decimal dec_1 = {{0xdc5db4ee, 0x2d5, 0x0, 0x0}};
  // -0.15033196425
  s21_decimal dec_2 = {{0x800c5f89, 0x3, 0x0, 0x800b0000}};
  // -20737761485651.578586355097133
  s21_decimal dec_check = {{0x32065e2d, 0xc2f08fb3, 0x4301dfce, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_68) {
  // -48798193460057073
  s21_decimal dec_1 = {{0xcade13f1, 0xad5db2, 0x0, 0x80000000}};
  // -942.5477515073425581900275250
  s21_decimal dec_2 = {{0x7de39e32, 0xed83e9eb, 0x1e74927f, 0x80190000}};
  // 51772648528435.781129257849983
  s21_decimal dec_check = {{0x507b947f, 0x7e306cc1, 0xa74954c4, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_69) {
  // -6903104029262728987816643141
  s21_decimal dec_1 = {{0x15564a45, 0x45608cfc, 0x164e1d23, 0x80000000}};
  // 5823740111846219100162508
  s21_decimal dec_2 = {{0xe55f89cc, 0x9585229d, 0x4d139, 0x0}};
  // -1185.3386134489325966002078172
  s21_decimal dec_check = {{0x5785c1dc, 0xea886c2a, 0x264ce425, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_70) {
  // 2173032971169
  s21_decimal dec_1 = {{0xf2dbbba1, 0x1f9, 0x0, 0x0}};
  // 60173.39089
  s21_decimal dec_2 = {{0x66a94ed1, 0x1, 0x0, 0x50000}};
  // 36112855.516841557206782168762
  s21_decimal dec_check = {{0x1e5bceba, 0x4cfd2251, 0x74afda9c, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_74) {
  // -7829813.2
  s21_decimal dec_1 = {{0x4aabc14, 0x0, 0x0, 0x80010000}};
  // 3.6955513146811062955
  s21_decimal dec_2 = {{0x87f39aab, 0xdc5b68, 0x2, 0x130000}};
  // -2118713.1589527513536992626551
  s21_decimal dec_check = {{0xa9bc777, 0xe7b498f1, 0x447595a0, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_75) {
  // -11493295162859885350965408
  s21_decimal dec_1 = {{0x77dd50a0, 0xc77b957d, 0x981cc, 0x80000000}};
  // 77.9387
  s21_decimal dec_2 = {{0xbe47b, 0x0, 0x0, 0x40000}};
  // -147465831003851557069407.21362
  s21_decimal dec_check = {{0x62da88d2, 0xb572a4aa, 0x2fa6166f, 0x80050000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_76) {
  // 448490589125952713180329687
  s21_decimal dec_1 = {{0x46f036d7, 0x8db11141, 0x172fb93, 0x0}};
  // 8644837.7473229235
  s21_decimal dec_2 = {{0x5eb361b3, 0x1332057, 0x0, 0xa0000}};
  // 51879584352504282602.664997166
  s21_decimal dec_check = {{0x3c1b12e, 0x21aa64d3, 0xa7a1c94f, 0x90000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_77) {
  // 753255944627106
  s21_decimal dec_1 = {{0x110123a2, 0x2ad15, 0x0, 0x0}};
  // 7465056966.082825
  s21_decimal dec_2 = {{0x4b10109, 0x1a856e, 0x0, 0x60000}};
  // 100904.24601573611164104633794
  s21_decimal dec_check = {{0xe86badc2, 0xb763a9b8, 0x209a9a85, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_78) {
  // -9399489344653135284
  s21_decimal dec_1 = {{0x221e8db4, 0x8271b1c2, 0x0, 0x80000000}};
  // -904446731903163
  s21_decimal dec_2 = {{0xea2c60bb, 0x33696, 0x0, 0x80000000}};
  // 10392.529502400276972225198577
  s21_decimal dec_check = {{0xf3f879f1, 0x34c33a33, 0x21947fb9, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_80) {
  // -733585967175817265246
  s21_decimal dec_1 = {{0xfdf4805e, 0xc48ce670, 0x27, 0x80000000}};
  // 978896762999519.399378751084
  s21_decimal dec_2 = {{0x9bbd0e6c, 0xdaa9ecb5, 0x329b973, 0xc0000}};
  // -749400.74878578123126496726325
  s21_decimal dec_check = {{0x567e8d35, 0x7aa2496c, 0xf224fa1f, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_81) {
  // 18493737697408947798203288576
  s21_decimal dec_1 = {{0x1a79cc00, 0x72053f8b, 0x3bc1a949, 0x0}};
  // 902443431855789
  s21_decimal dec_2 = {{0x7c2f86ad, 0x334c4, 0x0, 0x0}};
  // 20492960605163.181175476133441
  s21_decimal dec_check = {{0x199d1e41, 0x705b0673, 0x42376134, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_82) {
  // -932603.757896935
  s21_decimal dec_1 = {{0xbbb4a4e7, 0x35032, 0x0, 0x80090000}};
  // -1
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 932603.757896935
  s21_decimal dec_check = {{0xbbb4a4e7, 0x35032, 0x0, 0x90000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_83) {
  // -933572674691383317379
  s21_decimal dec_1 = {{0xf365383, 0x9bec695a, 0x32, 0x80000000}};
  // -4786255670.03879443808251
  s21_decimal dec_2 = {{0x8e683ffb, 0x580eeb17, 0x655a, 0x800e0000}};
  // 195052821882.33299136685420341
  s21_decimal dec_check = {{0x233a2f35, 0x2bd83582, 0x3f06642a, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_84) {
  // 2348770021338226743940087
  s21_decimal dec_1 = {{0x6f7d93f7, 0x13f72a34, 0x1f15f, 0x0}};
  // 9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x0}};
  // 260974446815358527104454.11111
  s21_decimal dec_check = {{0x718b6b27, 0x87ce83, 0x54534cdf, 0x50000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_85) {
  // 392598937601293936
  s21_decimal dec_1 = {{0x56ebbe70, 0x572caa7, 0x0, 0x0}};
  // -133.6962215866
  s21_decimal dec_2 = {{0x49286fba, 0x137, 0x0, 0x800a0000}};
  // -2936499872189679.2503472042919
  s21_decimal dec_check = {{0x571333a7, 0x7739f62b, 0x5ee2285a, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_87) {
  // -2326130
  s21_decimal dec_1 = {{0x237e72, 0x0, 0x0, 0x80000000}};
  // 3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x0}};
  // -775376.66666666666666666666667
  s21_decimal dec_check = {{0x41aaaaab, 0x790c4ebc, 0xfa89a794, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_88) {
  // -30153553392.464
  s21_decimal dec_1 = {{0xabd6b350, 0x1b6c, 0x0, 0x80030000}};
  // -63868048.01643155840265
  s21_decimal dec_2 = {{0x337c5d09, 0x3ab8c85a, 0x15a, 0x800e0000}};
  // 472.12267055204644371797559154
  s21_decimal dec_check = {{0xe1a2c772, 0x75ffc8e8, 0x988d126d, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_90) {
  // 89164
  s21_decimal dec_1 = {{0x15c4c, 0x0, 0x0, 0x0}};
  // 0.375923709716297821130
  s21_decimal dec_2 = {{0xfefe2bca, 0x60fd4e41, 0x14, 0x150000}};
  // 237186.42292418933879422990437
  s21_decimal dec_check = {{0x6cb23865, 0x17a4d13a, 0x4ca399df, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_92) {
  // -4532306299768342620740273
  s21_decimal dec_1 = {{0x66d91ab1, 0xd11bb35f, 0x3bfc0, 0x80000000}};
  // -83
  s21_decimal dec_2 = {{0x53, 0x0, 0x0, 0x80000000}};
  // 54606099997208947237834.614458
  s21_decimal dec_check = {{0xee4266ba, 0x659038f3, 0xb0711b74, 0x60000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_94) {
  // 3518165.655
  s21_decimal dec_1 = {{0xd1b2f297, 0x0, 0x0, 0x30000}};
  // 0.315777
  s21_decimal dec_2 = {{0x4d181, 0x0, 0x0, 0x60000}};
  // 11141297.988770556436979260681
  s21_decimal dec_check = {{0x241a1d09, 0x2fc9aa68, 0x23ffdd9e, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_95) {
  // 975835384313712421
  s21_decimal dec_1 = {{0xa1468f25, 0xd8add1c, 0x0, 0x0}};
  // 6.1895
  s21_decimal dec_2 = {{0xf1c7, 0x0, 0x0, 0x40000}};
  // 157659808435853044.83399305275
  s21_decimal dec_check = {{0xc241883b, 0x19582c0f, 0x32f1504e, 0xb0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_96) {
  // -291021301483
  s21_decimal dec_1 = {{0xc238a6eb, 0x43, 0x0, 0x80000000}};
  // -75731
  s21_decimal dec_2 = {{0x127d3, 0x0, 0x0, 0x80000000}};
  // 3842829.2440744213069944936684
  s21_decimal dec_check = {{0x55a558ec, 0x7549daa5, 0x7c2b2373, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_97) {
  // 22247445476407810502701
  s21_decimal dec_1 = {{0x6698b02d, 0x953dcc6, 0x4b6, 0x0}};
  // 990582355989.420
  s21_decimal dec_2 = {{0xed7313ac, 0x384ed, 0x0, 0x30000}};
  // 22458955928.188797920019925614
  s21_decimal dec_check = {{0x807eca6e, 0x7475f177, 0x48919ce8, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_99) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // -31780058059681411076157020601
  s21_decimal dec_2 = {{0x1ca719b9, 0x80484166, 0x66afd90f, 0x80000000}};
  // 0
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_100) {
  // -50213631876303
  s21_decimal dec_1 = {{0x45b0dccf, 0x2dab, 0x0, 0x80000000}};
  // -439792.7118736078700947501197
  s21_decimal dec_2 = {{0x532cf08d, 0xd40d5774, 0xe35e14a, 0x80160000}};
  // 114175679.86150236014160059334
  s21_decimal dec_check = {{0xe5031bc6, 0xc116a1bf, 0x24e46410, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_102) {
  // -83
  s21_decimal dec_1 = {{0x53, 0x0, 0x0, 0x80000000}};
  // -74
  s21_decimal dec_2 = {{0x4a, 0x0, 0x0, 0x80000000}};
  // 1.1216216216216216216216216216
  s21_decimal dec_check = {{0xad9f2298, 0x6f375927, 0x243dd62b, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_103) {
  // 710683803082936091
  s21_decimal dec_1 = {{0x4e61cf1b, 0x9dcdb27, 0x0, 0x0}};
  // -472841592719264160
  s21_decimal dec_2 = {{0x610fc9a0, 0x68fdeec, 0x0, 0x80000000}};
  // -1.5030061103463116323466165275
  s21_decimal dec_check = {{0x893ebc1b, 0xc58c3b0, 0x3090933d, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_104) {
  // -547798281620399
  s21_decimal dec_1 = {{0x39fc0baf, 0x1f238, 0x0, 0x80000000}};
  // 1422129741.536
  s21_decimal dec_2 = {{0x1d89bee0, 0x14b, 0x0, 0x30000}};
  // -385195.71430152243552185438372
  s21_decimal dec_check = {{0xcf3350a4, 0x639ad99a, 0x7c76a487, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_105) {
  // 988594426.9820228531
  s21_decimal dec_1 = {{0x77f173b3, 0x8931edef, 0x0, 0xa0000}};
  // -6201983.31119773492556904
  s21_decimal dec_2 = {{0x9ff9b468, 0x4d689d8, 0x8355, 0x80110000}};
  // -159.39972382658737544181440856
  s21_decimal dec_check = {{0x9adde158, 0x54f5e8da, 0x33813c72, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_106) {
  // 7380693928072191.023775099853
  s21_decimal dec_1 = {{0x4db62bcd, 0x9035dfa2, 0x17d92abb, 0xc0000}};
  // 576097.995623575613
  s21_decimal dec_2 = {{0x20f5303d, 0x7feb613, 0x0, 0xc0000}};
  // 12811525094.933261153316821273
  s21_decimal dec_check = {{0xf5f6d919, 0x9f9487b, 0x296571f7, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_107) {
  // 866802286
  s21_decimal dec_1 = {{0x33aa5a6e, 0x0, 0x0, 0x0}};
  // -43483235
  s21_decimal dec_2 = {{0x2978063, 0x0, 0x0, 0x80000000}};
  // -19.934172009051304485510335190
  s21_decimal dec_check = {{0x763e4ad6, 0xf216a1e9, 0x4069291d, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_108) {
  // -49373165016510
  s21_decimal dec_1 = {{0x95f655be, 0x2ce7, 0x0, 0x80000000}};
  // 0.31980644551808401963170399
  s21_decimal dec_2 = {{0x3a273a5f, 0x370c1101, 0x1a742a, 0x1a0000}};
  // -154384521351737.75690847966536
  s21_decimal dec_check = {{0x59d35548, 0x3d0aac4f, 0x31e26367, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_109) {
  // 62335115455161
  s21_decimal dec_1 = {{0x8669eab9, 0x38b1, 0x0, 0x0}};
  // 93487.432546305146092
  s21_decimal dec_2 = {{0x4dcf7cec, 0x11661495, 0x5, 0xf0000}};
  // 666775348.91426042808460802788
  s21_decimal dec_check = {{0xe1367ae4, 0x435af9d1, 0xd7725d39, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_110) {
  // 1396496.8545593153865035723856
  s21_decimal dec_1 = {{0x637eb450, 0xca8b88df, 0x2d1f8d1d, 0x160000}};
  // -529044.7729642828985045761698
  s21_decimal dec_2 = {{0xa81e3ea2, 0x18512206, 0x111827e2, 0x80160000}};
  // -2.6396572198126533448176591595
  s21_decimal dec_check = {{0xaf9d62eb, 0x2b412455, 0x554abb96, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_111) {
  // -149776772011.8547463346881622
  s21_decimal dec_1 = {{0x75708456, 0xcd3300f9, 0x4d6eca6, 0x80100000}};
  // -79328353
  s21_decimal dec_2 = {{0x4ba7461, 0x0, 0x0, 0x80000000}};
  // 1888.0610317455443242933350980
  s21_decimal dec_check = {{0xe678f244, 0x33add24b, 0x3d01acc0, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_112) {
  // 38870686406439196994658720
  s21_decimal dec_1 = {{0xdf6161a0, 0x21e4856e, 0x202730, 0x0}};
  // 3323895026217
  s21_decimal dec_2 = {{0xe7951229, 0x305, 0x0, 0x0}};
  // 11694318292199.138158116882425
  s21_decimal dec_check = {{0x6e9847f9, 0xe82eca9f, 0x25c95038, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_113) {
  // -5852150359571
  s21_decimal dec_1 = {{0x8f57e613, 0x552, 0x0, 0x80000000}};
  // 3378867893980
  s21_decimal dec_2 = {{0xb43876dc, 0x312, 0x0, 0x0}};
  // -1.7319855475846075534528406606
  s21_decimal dec_check = {{0x6ea2e44e, 0xb3ce1c90, 0x37f6a60e, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_115) {
  // 190003
  s21_decimal dec_1 = {{0x2e633, 0x0, 0x0, 0x0}};
  // 3066.16517
  s21_decimal dec_2 = {{0x124698c5, 0x0, 0x0, 0x50000}};
  // 61.967633661431226811568014779
  s21_decimal dec_check = {{0x36f6c5bb, 0xf9b916c1, 0xc83a6cd7, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_116) {
  // -558706881616
  s21_decimal dec_1 = {{0x15867450, 0x82, 0x0, 0x80000000}};
  // -48921.44948151489435532
  s21_decimal dec_2 = {{0x2350978c, 0x342646a6, 0x109, 0x80110000}};
  // 11420489.121588863550056684981
  s21_decimal dec_check = {{0xdc31ddb5, 0xd2dd12a1, 0x24e6cea3, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_117) {
  // -79228162514264337592066231285
  s21_decimal dec_1 = {{0xa7ebcbf5, 0xffffffff, 0xffffffff, 0x80000000}};
  // 1567
  s21_decimal dec_2 = {{0x61f, 0x0, 0x0, 0x0}};
  // -50560410028247822330610230.558
  s21_decimal dec_check = {{0x1a9ea51e, 0xb81e0f5b, 0xa35e9747, 0x80030000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_118) {
  // -65959662046787276622558
  s21_decimal dec_1 = {{0x328bcade, 0xae319a49, 0xdf7, 0x80000000}};
  // -3153886609920468304
  s21_decimal dec_2 = {{0x662ba550, 0x2bc4db29, 0x0, 0x80000000}};
  // 20913.770913422465842251049689
  s21_decimal dec_check = {{0xe3002ad9, 0xf5b80a8e, 0x43937740, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_120) {
  // -79228162514264337592049248305
  s21_decimal dec_1 = {{0xa6e8a831, 0xffffffff, 0xffffffff, 0x80000000}};
  // 619
  s21_decimal dec_2 = {{0x26b, 0x0, 0x0, 0x0}};
  // -127993800507696829712518979.49
  s21_decimal dec_check = {{0x212af65d, 0xe027b3e7, 0x295b6626, 0x80020000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_121) {
  // 2756399100550162267
  s21_decimal dec_1 = {{0xbf7fa75b, 0x2640b260, 0x0, 0x0}};
  // -0.47055
  s21_decimal dec_2 = {{0xb7cf, 0x0, 0x0, 0x80050000}};
  // -5857824036872090674.7423228137
  s21_decimal dec_check = {{0x6c1800e9, 0x684276f1, 0xbd46c8e5, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_122) {
  // -848179921724.895208722516
  s21_decimal dec_1 = {{0x1c78d054, 0xecf9fef8, 0xb39b, 0x800c0000}};
  // 562.574582711384
  s21_decimal dec_2 = {{0x9a298458, 0x1ffa8, 0x0, 0xc0000}};
  // -1507675511.4619788717661041115
  s21_decimal dec_check = {{0x906331db, 0x7713233b, 0x30b73314, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_124) {
  // 8966214861070245
  s21_decimal dec_1 = {{0x93c61fa5, 0x1fdab9, 0x0, 0x0}};
  // -78139.5
  s21_decimal dec_2 = {{0xbec53, 0x0, 0x0, 0x80010000}};
  // -114746253317.08348530512736836
  s21_decimal dec_check = {{0x4f4db244, 0xa79efc34, 0x2513966d, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_125) {
  // 942889666495674903932285
  s21_decimal dec_1 = {{0x75ffad7d, 0x26b7c242, 0xc7aa, 0x0}};
  // 2044582914863775.20638042642
  s21_decimal dec_2 = {{0xd49a212, 0x30cbd55b, 0xa91fba, 0xb0000}};
  // 461164797.78884241695606775658
  s21_decimal dec_check = {{0x9831f6a, 0x2eb8bef8, 0x9502a872, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_126) {
  // 39423058182094113960785234372
  s21_decimal dec_1 = {{0xe15a49c4, 0x5a39c49f, 0x7f61fd4a, 0x0}};
  // -65271834298207961
  s21_decimal dec_2 = {{0x312eced9, 0xe7e463, 0x0, 0x80000000}};
  // -603982691860.34617844229876771
  s21_decimal dec_check = {{0x2efe2c23, 0x4b0bfbe8, 0xc32846fd, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_127) {
  // 723686720823564605135275
  s21_decimal dec_1 = {{0xcddd19ab, 0x22c03c74, 0x993f, 0x0}};
  // -119691191744121081030254
  s21_decimal dec_2 = {{0x7019e66e, 0x78f6242a, 0x1958, 0x80000000}};
  // -6.0462821890075316105511895146
  s21_decimal dec_check = {{0x29af006a, 0x6424eedf, 0xc35dac8e, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_128) {
  // -7300611201394919554582749064
  s21_decimal dec_1 = {{0xdf269f88, 0x404fe3b1, 0x1796ec8e, 0x80000000}};
  // -35489209408010
  s21_decimal dec_2 = {{0xf9b85a0a, 0x2046, 0x0, 0x80000000}};
  // 205713548517289.70978314491527
  s21_decimal dec_check = {{0x9bad1687, 0xf8c90d9, 0x427839d5, 0xe0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_129) {
  // 570766724077244
  s21_decimal dec_1 = {{0xfbd696bc, 0x2071b, 0x0, 0x0}};
  // 9681
  s21_decimal dec_2 = {{0x25d1, 0x0, 0x0, 0x0}};
  // 58957413911.501291188926763764
  s21_decimal dec_check = {{0x6eff52f4, 0x594d9556, 0xbe806e04, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_130) {
  // -41639750.7
  s21_decimal dec_1 = {{0x18d1b8c3, 0x0, 0x0, 0x80010000}};
  // -0.35577494
  s21_decimal dec_2 = {{0x21ede96, 0x0, 0x0, 0x80080000}};
  // 117039583.22640712131101757757
  s21_decimal dec_check = {{0x9f22913d, 0x11c9fe4, 0x25d14994, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_131) {
  // -9591544429152.6
  s21_decimal dec_1 = {{0xdfc47c6, 0x573c, 0x0, 0x80010000}};
  // 0.7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x10000}};
  // -13702206327360.857142857142857
  s21_decimal dec_check = {{0x12259249, 0x6601b114, 0x2c46330d, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_132) {
  // 472775878630114332079
  s21_decimal dec_1 = {{0x79280daf, 0xa11554bd, 0x19, 0x0}};
  // 7898160751183268365.193415
  s21_decimal dec_2 = {{0xd2dfd0c7, 0x26fa1812, 0x68880, 0x60000}};
  // 59.858984075410859401658788761
  s21_decimal dec_check = {{0xc3cc6b99, 0xdde5841b, 0xc16a30ec, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_133) {
  // -79209478844221817973482980
  s21_decimal dec_1 = {{0x4049a5e4, 0x73c48697, 0x418542, 0x80000000}};
  // -7857425938.27794078016
  s21_decimal dec_2 = {{0x2fb44940, 0x985e760b, 0x2a, 0x800b0000}};
  // 10080843200614580.269383066270
  s21_decimal dec_check = {{0xf18aa29e, 0xedfa7111, 0x2092ad94, 0xc0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_134) {
  // -2984759776496294987523
  s21_decimal dec_1 = {{0xcffa8703, 0xcddce2c9, 0xa1, 0x80000000}};
  // -65109078993989071
  s21_decimal dec_2 = {{0xc516edcf, 0xe7505c, 0x0, 0x80000000}};
  // 45842.451200574511380749498040
  s21_decimal dec_check = {{0xdcfe36b8, 0x2fa98348, 0x941ffca3, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_135) {
  // 7082233822139283294185801386
  s21_decimal dec_1 = {{0xdcf46aa, 0xccf9c926, 0x16e24958, 0x0}};
  // -4908888445975247397
  s21_decimal dec_2 = {{0x805fba25, 0x441fe008, 0x0, 0x80000000}};
  // -1442736762.1168783806768922278
  s21_decimal dec_check = {{0xce40bea6, 0xe7e9c821, 0x2e9e09ed, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_136) {
  // 48045385931605940.338
  s21_decimal dec_1 = {{0xdec1872, 0x9ac37ff3, 0x2, 0x30000}};
  // 4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x0}};
  // 12011346482901485.0845
  s21_decimal dec_check = {{0xa2ce3d1d, 0x82e8bfdf, 0x6, 0x40000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_137) {
  // -953088
  s21_decimal dec_1 = {{0xe8b00, 0x0, 0x0, 0x80000000}};
  // 62680
  s21_decimal dec_2 = {{0xf4d8, 0x0, 0x0, 0x0}};
  // -15.205615826419910657306955967
  s21_decimal dec_check = {{0xe3690bf, 0xa6336664, 0x3121ca65, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_138) {
  // -7069233072016043265177
  s21_decimal dec_1 = {{0xb7abcc99, 0x39510898, 0x17f, 0x80000000}};
  // -971
  s21_decimal dec_2 = {{0x3cb, 0x0, 0x0, 0x80000000}};
  // 7280363616906326740.6560247168
  s21_decimal dec_check = {{0xd7663d80, 0xf795f80e, 0xeb3dc1a0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_139) {
  // -39483.046403154479542338818910
  s21_decimal dec_1 = {{0xe457935e, 0x5511d64f, 0x7f939c4a, 0x80180000}};
  // -91
  s21_decimal dec_2 = {{0x5b, 0x0, 0x0, 0x80000000}};
  // 433.87963080389537958614086714
  s21_decimal dec_check = {{0xbfd9343a, 0x92ef07a3, 0x8c31ae8f, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_140) {
  // -759535544680597671
  s21_decimal dec_1 = {{0xbef848a7, 0xa8a698d, 0x0, 0x80000000}};
  // -2970453854
  s21_decimal dec_2 = {{0xb10d875e, 0x0, 0x0, 0x80000000}};
  // 255696799.88726654394948227329
  s21_decimal dec_check = {{0x7ead9101, 0xad449f9b, 0x529ebe59, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_142) {
  // -8412658103364050310145590.0
  s21_decimal dec_1 = {{0x4a217e1c, 0x1894eef3, 0x45967f, 0x80010000}};
  // -74774
  s21_decimal dec_2 = {{0x12416, 0x0, 0x0, 0x80000000}};
  // 112507798210127187393.28630273
  s21_decimal dec_check = {{0xba407e01, 0x34748991, 0x245a6d4c, 0x80000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_143) {
  // 157997049915996428
  s21_decimal dec_1 = {{0xd3cd790c, 0x231517a, 0x0, 0x0}};
  // 8065
  s21_decimal dec_2 = {{0x1f81, 0x0, 0x0, 0x0}};
  // 19590458762057.833601983880967
  s21_decimal dec_check = {{0x963c9f07, 0x7d93fe49, 0x3f4cd901, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_144) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // -313552042876651
  s21_decimal dec_2 = {{0x86225eeb, 0x11d2c, 0x0, 0x80000000}};
  // 0
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_146) {
  // 661692341027.343847878392926
  s21_decimal dec_1 = {{0x29497c5e, 0xaed55ed2, 0x22356cd, 0xf0000}};
  // 309327953
  s21_decimal dec_2 = {{0x126ff851, 0x0, 0x0, 0x0}};
  // 2139.1288262504483320277004710
  s21_decimal dec_check = {{0xdf9071a6, 0x52d4474f, 0x451e757c, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_147) {
  // 43329199589
  s21_decimal dec_1 = {{0x169f1de5, 0xa, 0x0, 0x0}};
  // -3432
  s21_decimal dec_2 = {{0xd68, 0x0, 0x0, 0x80000000}};
  // -12625058.155303030303030303030
  s21_decimal dec_check = {{0x3b18d936, 0xfc9ce510, 0x28cb340d, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_148) {
  // 1442440369086343
  s21_decimal dec_1 = {{0x51cf1f87, 0x51fe4, 0x0, 0x0}};
  // 49862
  s21_decimal dec_2 = {{0xc2c6, 0x0, 0x0, 0x0}};
  // 28928650456.988147286510769724
  s21_decimal dec_check = {{0x2a9d963c, 0xa0842733, 0x5d793803, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_149) {
  // 973056540126843516111
  s21_decimal dec_1 = {{0x572434cf, 0xbfdf47c5, 0x34, 0x0}};
  // 42772185
  s21_decimal dec_2 = {{0x28ca6d9, 0x0, 0x0, 0x0}};
  // 22749750571004.112044100622870
  s21_decimal dec_check = {{0x71b71a16, 0xa119d0c6, 0x49822711, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_150) {
  // 261405053178323657191667422
  s21_decimal dec_1 = {{0xe1c936de, 0x53e633eb, 0xd83aac, 0x0}};
  // 0.7432
  s21_decimal dec_2 = {{0x1d08, 0x0, 0x0, 0x40000}};
  // 351729081241016761560370589.34
  s21_decimal dec_check = {{0x72a75176, 0xa094abf, 0x71a65902, 0x20000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_151) {
  // 7304640.023660222
  s21_decimal dec_1 = {{0x9d286be, 0x19f388, 0x0, 0x90000}};
  // 2.3162
  s21_decimal dec_2 = {{0x5a7a, 0x0, 0x0, 0x40000}};
  // 3153717.3057854339003540281496
  s21_decimal dec_check = {{0xa02b9898, 0x2b39bb5a, 0x65e6f029, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_152) {
  // 78320730211070195
  s21_decimal dec_1 = {{0x6c7b0f3, 0x116404a, 0x0, 0x0}};
  // 42
  s21_decimal dec_2 = {{0x2a, 0x0, 0x0, 0x0}};
  // 1864779290739766.5476190476190
  s21_decimal dec_check = {{0xcd11179e, 0x1ceea629, 0x3c4117bf, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_153) {
  // 6008435461.9611582
  s21_decimal dec_1 = {{0xf5a919be, 0xd57666, 0x0, 0x70000}};
  // 9203.14
  s21_decimal dec_2 = {{0xe0afa, 0x0, 0x0, 0x20000}};
  // 652867.98440110203691348822250
  s21_decimal dec_check = {{0xd46888ea, 0x2b66ba30, 0xd2f3f953, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_154) {
  // -97386395.39
  s21_decimal dec_1 = {{0x4477d8b3, 0x2, 0x0, 0x80020000}};
  // 656054.9074051615228552104
  s21_decimal dec_2 = {{0xfa31e3a8, 0x13f3d33b, 0x56d40, 0x130000}};
  // -148.44244634215781025117534091
  s21_decimal dec_check = {{0x318e778b, 0x10ef57fb, 0x2ff6df12, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_155) {
  // -6523625032825356082107257149
  s21_decimal dec_1 = {{0xa356113d, 0xa74c026a, 0x15143755, 0x80000000}};
  // -85135297323193
  s21_decimal dec_2 = {{0x1b27a0b9, 0x4d6e, 0x0, 0x80000000}};
  // 76626560756112.567877186920474
  s21_decimal dec_check = {{0x3028a01a, 0x17eec66d, 0xf7980166, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_156) {
  // 16121155844102
  s21_decimal dec_1 = {{0x7fc47806, 0xea9, 0x0, 0x0}};
  // -6609328
  s21_decimal dec_2 = {{0x64d9b0, 0x0, 0x0, 0x80000000}};
  // -2439152.0354417272073651058020
  s21_decimal dec_check = {{0xd0f17564, 0xec9715bd, 0x4ed03157, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_157) {
  // -91830961240777371.569
  s21_decimal dec_1 = {{0xb332fb1, 0xfa691cb5, 0x4, 0x80030000}};
  // -230089336.44828
  s21_decimal dec_2 = {{0x2f510a1c, 0x14ed, 0x0, 0x80050000}};
  // 399110026.81960162093869915538
  s21_decimal dec_check = {{0xa12d5d92, 0xb15b58b1, 0x80f59b8e, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_158) {
  // -2477884866.507068847773034
  s21_decimal dec_1 = {{0xa979556a, 0x6863bb7f, 0x20cb6, 0x800f0000}};
  // 8659796.7982106
  s21_decimal dec_2 = {{0xa91eae1a, 0x4ec2, 0x0, 0x70000}};
  // -286.13660623296399875875837865
  s21_decimal dec_check = {{0x16e897a9, 0x86ec6320, 0x5c74aa52, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_159) {
  // -4898653044.663
  s21_decimal dec_1 = {{0x8e797fb7, 0x474, 0x0, 0x80030000}};
  // 894512035
  s21_decimal dec_2 = {{0x35512ba3, 0x0, 0x0, 0x0}};
  // -5.4763411256540556215098883494
  s21_decimal dec_check = {{0x17f93da6, 0xda58f66f, 0xb0f33b68, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_160) {
  // 726401486666839536705.82395
  s21_decimal dec_1 = {{0xa9ccf07b, 0x59863ae4, 0x3c1626, 0x50000}};
  // -5548
  s21_decimal dec_2 = {{0x15ac, 0x0, 0x0, 0x80000000}};
  // -130930332852710803.29953567952
  s21_decimal dec_check = {{0x66e64d0, 0x9da4d40e, 0x2a4e4da4, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_161) {
  // -5940143341159683788940
  s21_decimal dec_1 = {{0x74f5108c, 0x40c808e, 0x142, 0x80000000}};
  // -15735
  s21_decimal dec_2 = {{0x3d77, 0x0, 0x0, 0x80000000}};
  // 377511492924034559.19542421354
  s21_decimal dec_check = {{0xc70ac76a, 0xd5199c03, 0x79fb04cf, 0xb0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_162) {
  // -56531234877938
  s21_decimal dec_1 = {{0x342c71f2, 0x336a, 0x0, 0x80000000}};
  // -7649732202.34
  s21_decimal dec_2 = {{0x1bf5018a, 0xb2, 0x0, 0x80020000}};
  // 7389.9626003437724937868507821
  s21_decimal dec_check = {{0xeb677aad, 0xf08e6652, 0xeec85680, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_163) {
  // -129859.45133
  s21_decimal dec_1 = {{0x605cc2d, 0x3, 0x0, 0x80050000}};
  // -459
  s21_decimal dec_2 = {{0x1cb, 0x0, 0x0, 0x80000000}};
  // 282.91819461873638344226579521
  s21_decimal dec_check = {{0xdbd2441, 0x34e0b3c5, 0x5b6a71ce, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_164) {
  // -29934543484755866
  s21_decimal dec_1 = {{0x6ec1f9a, 0x6a594f, 0x0, 0x80000000}};
  // -8.6241045807
  s21_decimal dec_2 = {{0x145ded2f, 0x14, 0x0, 0x800a0000}};
  // 3471032059577151.3195513677405
  s21_decimal dec_check = {{0x918a865d, 0xe1543531, 0x7027b449, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_165) {
  // -53111943691506561
  s21_decimal dec_1 = {{0x9101381, 0xbcb108, 0x0, 0x80000000}};
  // 19248246
  s21_decimal dec_2 = {{0x125b476, 0x0, 0x0, 0x0}};
  // -2759313429.9876758121233487976
  s21_decimal dec_check = {{0x249b9868, 0xae377123, 0x59288177, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_166) {
  // -93105675082382448
  s21_decimal dec_1 = {{0x41dbbc70, 0x14ac71e, 0x0, 0x80000000}};
  // 45.374
  s21_decimal dec_2 = {{0xb13e, 0x0, 0x0, 0x30000}};
  // -2051960926574303.5218407017235
  s21_decimal dec_check = {{0x90e54b13, 0x393ec8ca, 0x424d6c47, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_167) {
  // -802818411340740976913
  s21_decimal dec_1 = {{0xa44c6111, 0x8557f399, 0x2b, 0x80000000}};
  // 435066131461
  s21_decimal dec_2 = {{0x4bf65405, 0x65, 0x0, 0x0}};
  // -1845279035.2693929687985982099
  s21_decimal dec_check = {{0xa6c08a93, 0x70c5a4db, 0x3b9fca59, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_168) {
  // -26684399668864251300142483
  s21_decimal dec_1 = {{0x380fdd93, 0x34622751, 0x1612a4, 0x80000000}};
  // -8141
  s21_decimal dec_2 = {{0x1fcd, 0x0, 0x0, 0x80000000}};
  // 3277779101936402321599.6171232
  s21_decimal dec_check = {{0xa53e73e0, 0x9f9ec7c2, 0x69e9273b, 0x70000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_169) {
  // 2308413.2938504441933241860
  s21_decimal dec_1 = {{0x1c9e9e04, 0x5aa5dfba, 0x131841, 0x130000}};
  // -76955.498021849126
  s21_decimal dec_2 = {{0x231b0826, 0x111669e, 0x0, 0x800c0000}};
  // -29.996729969768266077970711900
  s21_decimal dec_check = {{0xa991455c, 0x8c0a7d5, 0x60ecb6a6, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_170) {
  // -772961.9433
  s21_decimal dec_1 = {{0xccb8a1e9, 0x1, 0x0, 0x80040000}};
  // -13093
  s21_decimal dec_2 = {{0x3325, 0x0, 0x0, 0x80000000}};
  // 59.036274597112961124264874360
  s21_decimal dec_check = {{0x4b09178, 0xae99bfbd, 0xbec1a96a, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_171) {
  // 78692943746867
  s21_decimal dec_1 = {{0x20f55733, 0x4792, 0x0, 0x0}};
  // 43.431622038962716547652689736
  s21_decimal dec_2 = {{0x3ad29f48, 0x75ec2554, 0x8c55cbb4, 0x1b0000}};
  // 1811881298752.1208058664789424
  s21_decimal dec_check = {{0xced525b0, 0x324ac40c, 0x3a8b87e4, 0x100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_172) {
  // -4658441077.3629168
  s21_decimal dec_1 = {{0x583ba8f0, 0xa58046, 0x0, 0x80070000}};
  // -818.7000015318890482
  s21_decimal dec_2 = {{0x293337f2, 0x719e1123, 0x0, 0x80100000}};
  // 5690046.4988962952053157591150
  s21_decimal dec_check = {{0xa420f86e, 0xd2cdac84, 0xb7daf623, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_173) {
  // -53765901673789427515451016
  s21_decimal dec_1 = {{0xd48ce688, 0x5eb983b2, 0x2c795f, 0x80000000}};
  // 389436.3890956
  s21_decimal dec_2 = {{0xba2d250c, 0x38a, 0x0, 0x70000}};
  // -138060805767667526529.11949752
  s21_decimal dec_check = {{0x9467b7b8, 0xbdf526c8, 0x2c9c1f47, 0x80080000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_175) {
  // 651027.601
  s21_decimal dec_1 = {{0x26cde491, 0x0, 0x0, 0x30000}};
  // -11.8
  s21_decimal dec_2 = {{0x76, 0x0, 0x0, 0x80010000}};
  // -55171.830593220338983050847458
  s21_decimal dec_check = {{0x2b4ea4e2, 0x7565daa2, 0xb2451191, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_176) {
  // 33277641275394265
  s21_decimal dec_1 = {{0xa32ec8d9, 0x7639d6, 0x0, 0x0}};
  // -62690230293
  s21_decimal dec_2 = {{0x98a10015, 0xe, 0x0, 0x80000000}};
  // -530826.59163735838343955658884
  s21_decimal dec_check = {{0x8422b884, 0x54dd128c, 0xab84f24f, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_177) {
  // -79228162514264337593521961009
  s21_decimal dec_1 = {{0xfeb07831, 0xffffffff, 0xffffffff, 0x80000000}};
  // -636167646611771569824274
  s21_decimal dec_2 = {{0x3fbd6212, 0xb79c20c2, 0x86b6, 0x80000000}};
  // 124539.75447546487847094499792
  s21_decimal dec_check = {{0x201eb9d0, 0xd0c7ff72, 0x283dafe1, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_178) {
  // 8848733
  s21_decimal dec_1 = {{0x87055d, 0x0, 0x0, 0x0}};
  // -5382.25
  s21_decimal dec_2 = {{0x83671, 0x0, 0x0, 0x80020000}};
  // -1644.0583399136049050118444888
  s21_decimal dec_check = {{0x392d758, 0xe9e313bf, 0x351f54f3, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_179) {
  // -69167584552040.014153282
  s21_decimal dec_1 = {{0xed220642, 0x950fc482, 0xea5, 0x80090000}};
  // 0.90790639645698
  s21_decimal dec_2 = {{0xd7d33402, 0x5292, 0x0, 0xe0000}};
  // -76183607497380.852463042784910
  s21_decimal dec_check = {{0xe9036e8e, 0xd2795a31, 0xf6299a65, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_180) {
  // -83376792724232328769
  s21_decimal dec_1 = {{0xc73dd641, 0x8515df3b, 0x4, 0x80000000}};
  // 693.8560152055300
  s21_decimal dec_2 = {{0x6d1dae04, 0x18a695, 0x0, 0xd0000}};
  // -120164401398948655.57874292236
  s21_decimal dec_check = {{0x4920360c, 0x42c3e4d3, 0x26d3c42d, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_181) {
  // -607903048148963992301761272
  s21_decimal dec_1 = {{0x9d9872f8, 0x45ef580a, 0x1f6d87a, 0x80000000}};
  // -0.5288403053441204
  s21_decimal dec_2 = {{0x496df0b4, 0x12c9c6, 0x0, 0x80100000}};
  // 1149502112463604425082427731.7
  s21_decimal dec_check = {{0xee5f7d45, 0xce0b3138, 0x25247567, 0x10000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_182) {
  // -279326300376961.930
  s21_decimal dec_1 = {{0x4e64938a, 0x3e05dca, 0x0, 0x80030000}};
  // 432621229
  s21_decimal dec_2 = {{0x19c946ad, 0x0, 0x0, 0x0}};
  // -645660.17951227707783151806450
  s21_decimal dec_check = {{0x4a76e7f2, 0x92ad5f28, 0xd09fc21e, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_183) {
  // 12508041646181
  s21_decimal dec_1 = {{0x41611065, 0xb60, 0x0, 0x0}};
  // 466
  s21_decimal dec_2 = {{0x1d2, 0x0, 0x0, 0x0}};
  // 26841291086.225321888412017167
  s21_decimal dec_check = {{0x1363220f, 0x666aa82c, 0x56ba9879, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_184) {
  // 318851140.32473767513670439
  s21_decimal dec_1 = {{0xd9d3c327, 0x7ec54889, 0x1a5fef, 0x110000}};
  // 0.443922437
  s21_decimal dec_2 = {{0x1a75b805, 0x0, 0x0, 0x90000}};
  // 718258672.57242885233283306651
  s21_decimal dec_check = {{0x674e149b, 0xc43d101, 0xe814f702, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_185) {
  // -385678856341918952892839
  s21_decimal dec_1 = {{0x4eeea9a7, 0xb1548cd1, 0x51ab, 0x80000000}};
  // 360502
  s21_decimal dec_2 = {{0x58036, 0x0, 0x0, 0x0}};
  // -1069838326394635682.7225341330
  s21_decimal dec_check = {{0x48a43d92, 0xd7b89268, 0x22917ec6, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_187) {
  // 36320628
  s21_decimal dec_1 = {{0x22a3574, 0x0, 0x0, 0x0}};
  // 0.683430414376741028343
  s21_decimal dec_2 = {{0xf7aac1f7, 0xc8094e7, 0x25, 0x150000}};
  // 53144588.294512531242222399011
  s21_decimal dec_check = {{0x314cae23, 0x3ce7a787, 0xabb82c50, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_188) {
  // -5088286198280685684239147141
  s21_decimal dec_1 = {{0x94b4a085, 0x852b9706, 0x1070ee83, 0x80000000}};
  // 1919.7644691352125
  s21_decimal dec_2 = {{0xf85a2a3d, 0x443427, 0x0, 0xd0000}};
  // -2650474201438253851377628.1595
  s21_decimal dec_check = {{0x55c287fb, 0xa877301b, 0x55a4356f, 0x80040000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_189) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // 685428.77084183266866124650
  s21_decimal dec_2 = {{0xc1ea576a, 0xcfe951bc, 0x38b284, 0x140000}};
  // 0
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_190) {
  // 6898844839583909931465787
  s21_decimal dec_1 = {{0xb7893c3b, 0x20cd8312, 0x5b4e3, 0x0}};
  // 61.05232256222610958
  s21_decimal dec_2 = {{0xdf67c60e, 0x54ba2463, 0x0, 0x110000}};
  // 112998892590080065483779.34065
  s21_decimal dec_check = {{0x46bd98f1, 0x2c5099f7, 0x24830ca0, 0x50000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_192) {
  // -134051033073952402574735705
  s21_decimal dec_1 = {{0xb184f959, 0x106b2b47, 0x6ee269, 0x80000000}};
  // 5760.95600
  s21_decimal dec_2 = {{0x22568570, 0x0, 0x0, 0x50000}};
  // -23268886808708902233368.160597
  s21_decimal dec_check = {{0x7dc3e955, 0x7750a6e9, 0x4b2f9271, 0x80060000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_193) {
  // -337728018643975789464.93672
  s21_decimal dec_1 = {{0x89343ce8, 0x41f31078, 0x1befab, 0x80050000}};
  // -499
  s21_decimal dec_2 = {{0x1f3, 0x0, 0x0, 0x80000000}};
  // 676809656601153886.70328
  s21_decimal dec_check = {{0x1d012178, 0xfe147ec0, 0xe54, 0x50000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_194) {
  // 70394.45
  s21_decimal dec_1 = {{0x6b69d5, 0x0, 0x0, 0x20000}};
  // -6.5925246473526269719995
  s21_decimal dec_2 = {{0x1ecc35bb, 0xd094ecbf, 0xdf5, 0x80160000}};
  // -10677.919881311090295116800312
  s21_decimal dec_check = {{0xba062138, 0xa5adbb5a, 0x2280917c, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_195) {
  // 599470019134395745
  s21_decimal dec_1 = {{0x68009561, 0x851bece, 0x0, 0x0}};
  // 12
  s21_decimal dec_2 = {{0xc, 0x0, 0x0, 0x0}};
  // 49955834927866312.083333333333
  s21_decimal dec_check = {{0x63124155, 0xdb227b8a, 0xa16a7f85, 0xc0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_196) {
  // -5579569129
  s21_decimal dec_1 = {{0x4c9177e9, 0x1, 0x0, 0x80000000}};
  // 38679
  s21_decimal dec_2 = {{0x9717, 0x0, 0x0, 0x0}};
  // -144253.18981876470436153985367
  s21_decimal dec_check = {{0xc10b0957, 0xf2850d47, 0x2e9c581c, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_197) {
  // 75830792249045025
  s21_decimal dec_1 = {{0x2b0a7021, 0x10d67b4, 0x0, 0x0}};
  // -58051963989854
  s21_decimal dec_2 = {{0x46b12f5e, 0x34cc, 0x0, 0x80000000}};
  // -1306.2571364906501683015261397
  s21_decimal dec_check = {{0xab7b1cd5, 0x9a9b0ee8, 0x2a351b14, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_198) {
  // 58656570167398
  s21_decimal dec_1 = {{0xc075066, 0x3559, 0x0, 0x0}};
  // -4047866176.2374843594326055
  s21_decimal dec_2 = {{0x96164027, 0xa6aeba57, 0x217bb0, 0x80100000}};
  // -14490.738481359487575621110523
  s21_decimal dec_check = {{0xc4340afb, 0x1ed6a62f, 0x2ed2753b, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_199) {
  // 620066050887647426789515389
  s21_decimal dec_1 = {{0xba5c207d, 0xf90c5a3d, 0x200e817, 0x0}};
  // 3920190190722178.4614507519
  s21_decimal dec_2 = {{0x820593ff, 0x5c54c843, 0x206d53, 0xa0000}};
  // 158172440805.33212518569424460
  s21_decimal dec_check = {{0xcfdf364c, 0xbe0c98a2, 0x331bb7b7, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_200) {
  // 327626666752248.4336018368
  s21_decimal dec_1 = {{0x83d743c0, 0xc59d1af2, 0x2b5c6, 0xa0000}};
  // -206.7890
  s21_decimal dec_2 = {{0x1f8db2, 0x0, 0x0, 0x80040000}};
  // -1584352488537.8256754558356586
  s21_decimal dec_check = {{0xc08bcc6a, 0x71b78ab, 0x333174e5, 0x80100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_201) {
  // 884929332927133.71157627
  s21_decimal dec_1 = {{0x6722c47b, 0x36269611, 0x12bd, 0x80000}};
  // -77891.234936
  s21_decimal dec_2 = {{0x22adec78, 0x12, 0x0, 0x80060000}};
  // -11361090033.483786381346146693
  s21_decimal dec_check = {{0x68730985, 0xce29e395, 0x24b5ac64, 0x80120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_202) {
  // -7398175541053450243520127515
  s21_decimal dec_1 = {{0x2de0e21b, 0xb3b3e3bd, 0x17e7a09b, 0x80000000}};
  // -96.6141469061707958437708509
  s21_decimal dec_2 = {{0x7cd282dd, 0xfbf7f0da, 0x31f2c69, 0x80190000}};
  // 76574453927936354023559621.715
  s21_decimal dec_check = {{0xf0836c53, 0x472a3b97, 0xf76ce759, 0x30000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_203) {
  // 57.6
  s21_decimal dec_1 = {{0x240, 0x0, 0x0, 0x10000}};
  // -1.11670986959577235177819736
  s21_decimal dec_2 = {{0x7a3b4e58, 0x55507141, 0x5c5f40, 0x801a0000}};
  // -51.580093960170782834201548013
  s21_decimal dec_check = {{0xc97154ed, 0x6e61d72d, 0xa6aa0dc0, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_204) {
  // 5682237438400771.331
  s21_decimal dec_1 = {{0x2d4db503, 0x4edb5cd8, 0x0, 0x30000}};
  // -196
  s21_decimal dec_2 = {{0xc4, 0x0, 0x0, 0x80000000}};
  // -28991007338779.445566326530612
  s21_decimal dec_check = {{0x9e0d6234, 0xf65f71c4, 0x5daccc98, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_205) {
  // -7676979888505443330264023
  s21_decimal dec_1 = {{0xab9f8bd7, 0xe9e5c506, 0x659a9, 0x80000000}};
  // -54
  s21_decimal dec_2 = {{0x36, 0x0, 0x0, 0x80000000}};
  // 142166294231582283893778.20370
  s21_decimal dec_check = {{0xdb9b46d2, 0x4cebe9bb, 0x2defb861, 0x50000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_206) {
  // 56908990169993282143630.2
  s21_decimal dec_1 = {{0xc134b78e, 0x6ce63c90, 0x7882, 0x10000}};
  // -109.99543804026877
  s21_decimal dec_2 = {{0xdd215ffd, 0x271406, 0x0, 0x800e0000}};
  // -517375912891580017199.06901367
  s21_decimal dec_check = {{0xc9379d77, 0xbe5d4695, 0xa72c551b, 0x80080000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_207) {
  // -108102955345338.285
  s21_decimal dec_1 = {{0xac875fad, 0x1800f10, 0x0, 0x80030000}};
  // 7.13019140932437699681911208
  s21_decimal dec_2 = {{0x424901a8, 0x14c540ea, 0x24dcbad, 0x1a0000}};
  // -15161297802464.128596713311934
  s21_decimal dec_check = {{0x711a8ebe, 0xc1ae48e5, 0x30fd21b0, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_208) {
  // 442274990
  s21_decimal dec_1 = {{0x1a5c94ae, 0x0, 0x0, 0x0}};
  // 73
  s21_decimal dec_2 = {{0x49, 0x0, 0x0, 0x0}};
  // 6058561.5068493150684931506849
  s21_decimal dec_check = {{0xf60542a1, 0xee795d4c, 0xc3c33f05, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_209) {
  // 6931788814054835067108
  s21_decimal dec_1 = {{0x14b398e4, 0xc5e4f031, 0x177, 0x0}};
  // 29162261061381305654.66777939
  s21_decimal dec_2 = {{0x33ed6953, 0xfc980ed4, 0x96c3ee5, 0x80000}};
  // 237.69723477424018824058381501
  s21_decimal dec_check = {{0xd64824bd, 0xae1db8bb, 0x4ccddabb, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_210) {
  // -9051862607582145
  s21_decimal dec_1 = {{0xff47d3c1, 0x20289e, 0x0, 0x80000000}};
  // 32305372658
  s21_decimal dec_2 = {{0x858cddf2, 0x7, 0x0, 0x0}};
  // -280196.81752039998398956094779
  s21_decimal dec_check = {{0x39bcc53b, 0x654d49ba, 0x5a895667, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_211) {
  // -989132
  s21_decimal dec_1 = {{0xf17cc, 0x0, 0x0, 0x80000000}};
  // -934536.769634
  s21_decimal dec_2 = {{0x96bb7062, 0xd9, 0x0, 0x80060000}};
  // 1.0584195637239416061959366541
  s21_decimal dec_check = {{0x3e50678d, 0x32010edc, 0x22330a9b, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_213) {
  // 678057844454514179352.761
  s21_decimal dec_1 = {{0xf3a6a8b9, 0x96e302f3, 0x8f95, 0x30000}};
  // 9075704279467
  s21_decimal dec_2 = {{0x1a2131ab, 0x841, 0x0, 0x0}};
  // 74711319.758243082903082928919
  s21_decimal dec_check = {{0xbb28b17, 0x8eac55b4, 0xf167c157, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_214) {
  // -6398415490363510620455
  s21_decimal dec_1 = {{0x39de0127, 0xdbda3c3a, 0x15a, 0x80000000}};
  // -131634
  s21_decimal dec_2 = {{0x20232, 0x0, 0x0, 0x80000000}};
  // 48607620298429817.679740796451
  s21_decimal dec_check = {{0x4c09fe23, 0x586c801b, 0x9d0f47f8, 0xc0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_215) {
  // -91487696977956.33087
  s21_decimal dec_1 = {{0x60f76fbf, 0x7ef6f591, 0x0, 0x80050000}};
  // 5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  // -18297539395591.266174
  s21_decimal dec_check = {{0xc1eedf7e, 0xfdedeb22, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_216) {
  // 64879.2
  s21_decimal dec_1 = {{0x9e658, 0x0, 0x0, 0x10000}};
  // 945.7794422093
  s21_decimal dec_2 = {{0x107a154d, 0x89a, 0x0, 0xa0000}};
  // 68.598657471814978392339728000
  s21_decimal dec_check = {{0xaea34680, 0x6cb4324, 0xdda77ac1, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_217) {
  // 63373
  s21_decimal dec_1 = {{0xf78d, 0x0, 0x0, 0x0}};
  // -11527
  s21_decimal dec_2 = {{0x2d07, 0x0, 0x0, 0x80000000}};
  // -5.4977878025505335299731066192
  s21_decimal dec_check = {{0x5b738d50, 0xb1de47b0, 0xb1a4a283, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_218) {
  // -3729786194472218
  s21_decimal dec_1 = {{0x8535ad1a, 0xd4038, 0x0, 0x80000000}};
  // -6296.898534798824166356717310
  s21_decimal dec_2 = {{0x81888efe, 0x91469d5e, 0x1458ac21, 0x80180000}};
  // 592321152049.71755218986572570
  s21_decimal dec_check = {{0xe1e39b1a, 0x4e9e4aa8, 0xbf63a847, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_219) {
  // -9877496851.4856400
  s21_decimal dec_1 = {{0x7f0745d0, 0x15eeb4f, 0x0, 0x80070000}};
  // 95186
  s21_decimal dec_2 = {{0x173d2, 0x0, 0x0, 0x0}};
  // -103770.47939282709642174269325
  s21_decimal dec_check = {{0xf88c078d, 0xfce23b89, 0x2187b15f, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_220) {
  // -6.80
  s21_decimal dec_1 = {{0x2a8, 0x0, 0x0, 0x80020000}};
  // -2.685337541466646056
  s21_decimal dec_2 = {{0x3523e628, 0x25443c44, 0x0, 0x80120000}};
  // 2.5322701131590541224134525638
  s21_decimal dec_check = {{0xc00f42c6, 0xeaa3b5, 0x51d2728b, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_222) {
  // -255684637647001943
  s21_decimal dec_1 = {{0xc1795957, 0x38c5fd2, 0x0, 0x80000000}};
  // 0.41574631579
  s21_decimal dec_2 = {{0xae0a889b, 0x9, 0x0, 0xb0000}};
  // -615001571718442534.70395858490
  s21_decimal dec_check = {{0xff41fe3a, 0xb217cf0a, 0xc6b7bcd8, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_223) {
  // -2885348690900394823488007658
  s21_decimal dec_1 = {{0x7da26dea, 0xf3def37d, 0x952b459, 0x80000000}};
  // 3668.86250495470652038
  s21_decimal dec_2 = {{0x9d82ca86, 0xe391ccfa, 0x13, 0x110000}};
  // -786442306574259460310065.41383
  s21_decimal dec_check = {{0xdf05e647, 0x9c92ded6, 0xfe1cfb9e, 0x80050000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_224) {
  // 2565690104005600339336177
  s21_decimal dec_1 = {{0xa3889bf1, 0x56d81053, 0x21f4e, 0x0}};
  // 13115811603450884737
  s21_decimal dec_2 = {{0xaca2f281, 0xb604b929, 0x0, 0x0}};
  // 195618.09681152669460182633028
  s21_decimal dec_check = {{0x87e08a44, 0xb3e32788, 0x3f352653, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_225) {
  // 79228162514264337591781454474
  s21_decimal dec_1 = {{0x96f2728a, 0xffffffff, 0xffffffff, 0x0}};
  // -492210710698869.81681856
  s21_decimal dec_2 = {{0xa5b932c0, 0x479479a6, 0xa6c, 0x80080000}};
  // -160963914015141.02870622502520
  s21_decimal dec_check = {{0x5f7a7e78, 0x55bdeb61, 0x34029f76, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_226) {
  // -20276051021
  s21_decimal dec_1 = {{0xb88bfc4d, 0x4, 0x0, 0x80000000}};
  // -6.8890
  s21_decimal dec_2 = {{0x10d1a, 0x0, 0x0, 0x80040000}};
  // 2943250257.0764987661489330817
  s21_decimal dec_check = {{0xd708da81, 0x7207ae24, 0x5f19fed9, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_227) {
  // -44448675260752444815722101
  s21_decimal dec_1 = {{0x303a4675, 0x839b6fc7, 0x24c45f, 0x80000000}};
  // -321003
  s21_decimal dec_2 = {{0x4e5eb, 0x0, 0x0, 0x80000000}};
  // 138468099241291965544.62762342
  s21_decimal dec_check = {{0x79851566, 0x163452b3, 0x2cbdd00e, 0x80000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_228) {
  // 989911337992291850.5
  s21_decimal dec_1 = {{0xd99f3c69, 0x8960b72b, 0x0, 0x10000}};
  // 0.7964267117543660308036
  s21_decimal dec_2 = {{0xa15c644, 0xbe68bae9, 0x1af, 0x160000}};
  // 1242940905148345097.8326228389
  s21_decimal dec_check = {{0x28ff2da5, 0xd1040417, 0x28295dbe, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_229) {
  // -64757961243213243
  s21_decimal dec_1 = {{0xcc47bdbb, 0xe61105, 0x0, 0x80000000}};
  // -307717.814
  s21_decimal dec_2 = {{0x125766b6, 0x0, 0x0, 0x80030000}};
  // 210445929019.93396781377109354
  s21_decimal dec_check = {{0xabf3bd6a, 0x2bb3ded1, 0x43ffade3, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_230) {
  // 27365221884264020380915275505
  s21_decimal dec_1 = {{0x745b16f1, 0xdf939a8d, 0x586bfb22, 0x0}};
  // 7.0220634
  s21_decimal dec_2 = {{0x42f7b5a, 0x0, 0x0, 0x70000}};
  // 3897034293974620106807249206.1
  s21_decimal dec_check = {{0xd9065c1d, 0xe38edaa7, 0x7deb831b, 0x10000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_231) {
  // -4391755819577923086825751853
  s21_decimal dec_1 = {{0xe78b052d, 0x7d63130, 0xe30c678, 0x80000000}};
  // 0.329
  s21_decimal dec_2 = {{0x149, 0x0, 0x0, 0x30000}};
  // -13348801883215571692479488915
  s21_decimal dec_check = {{0x7e6aa393, 0x17d1d936, 0x2b21dec0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_232) {
  // 757854.9388308934
  s21_decimal dec_1 = {{0x8833f1c6, 0x1aeca6, 0x0, 0xa0000}};
  // -4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x80000000}};
  // -189463.73470772335
  s21_decimal dec_check = {{0x5481dc6f, 0x434fa0, 0x0, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_233) {
  // 18934434108948764800490283
  s21_decimal dec_1 = {{0x5dee9b2b, 0xbad33584, 0xfa985, 0x0}};
  // -418.3122225666425
  s21_decimal dec_2 = {{0xa501979, 0xedc87, 0x0, 0x800d0000}};
  // -45263879675264010960692.168514
  s21_decimal dec_check = {{0xdbe9c742, 0xf3c26d80, 0x92416759, 0x80060000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_234) {
  // 45386578319999107400804.91
  s21_decimal dec_1 = {{0xb4b5b76b, 0x2253241f, 0x3c119, 0x20000}};
  // -91.179017507859483
  s21_decimal dec_2 = {{0x55866c1b, 0x143eed5, 0x0, 0x800f0000}};
  // -497774373540347242435.78190601
  s21_decimal dec_check = {{0x8bfa7b09, 0x122d9c, 0xa0d6ee5e, 0x80080000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_235) {
  // 9017297308337930743820
  s21_decimal dec_1 = {{0xa063b00c, 0xd4237e3e, 0x1e8, 0x0}};
  // 67432
  s21_decimal dec_2 = {{0x10768, 0x0, 0x0, 0x0}};
  // 133724304608167201.68199074623
  s21_decimal dec_check = {{0xe6d7333f, 0xd9f80c3c, 0x2b356a4b, 0xb0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_236) {
  // 84825969374572155081420915
  s21_decimal dec_1 = {{0xd5857073, 0x3928e0b, 0x462a99, 0x0}};
  // -60.2
  s21_decimal dec_2 = {{0x25a, 0x0, 0x0, 0x80010000}};
  // -1409069258713823174109981.9767
  s21_decimal dec_check = {{0x25bc42f7, 0xbd72d0b7, 0x2d878c37, 0x80040000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_237) {
  // 57747.71
  s21_decimal dec_1 = {{0x581db3, 0x0, 0x0, 0x20000}};
  // 170
  s21_decimal dec_2 = {{0xaa, 0x0, 0x0, 0x0}};
  // 339.69241176470588235294117647
  s21_decimal dec_check = {{0xb28f0f0f, 0xf88479b, 0x6dc2b29e, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_239) {
  // -30737879
  s21_decimal dec_1 = {{0x1d505d7, 0x0, 0x0, 0x80000000}};
  // 20407668.2952
  s21_decimal dec_2 = {{0x83eb0ec8, 0x2f, 0x0, 0x40000}};
  // -1.5061926014952783453059816764
  s21_decimal dec_check = {{0x6b81d3c, 0x5c83df40, 0x30aaeee5, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_240) {
  // 3027504130608460461508911
  s21_decimal dec_1 = {{0xd538092f, 0x53e9700c, 0x28119, 0x0}};
  // -24625043716935717226.81
  s21_decimal dec_2 = {{0xe1d2cdb9, 0x7e1cf725, 0x85, 0x80020000}};
  // -122944.11191344662456138083721
  s21_decimal dec_check = {{0x96022d89, 0x27802525, 0x27b9b2d6, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_241) {
  // 13925.05
  s21_decimal dec_1 = {{0x153f79, 0x0, 0x0, 0x20000}};
  // 9223
  s21_decimal dec_2 = {{0x2407, 0x0, 0x0, 0x0}};
  // 1.5098178466876287542014528895
  s21_decimal dec_check = {{0x28284d7f, 0xb7d29005, 0x30c8eba6, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_242) {
  // 921970621239454926
  s21_decimal dec_1 = {{0x2c52ecce, 0xccb7f65, 0x0, 0x0}};
  // -164
  s21_decimal dec_2 = {{0xa4, 0x0, 0x0, 0x80000000}};
  // -5621772080728383.6951219512195
  s21_decimal dec_check = {{0x12cda383, 0x9270d3cb, 0xb5a6356f, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_243) {
  // -3410019110282593
  s21_decimal dec_1 = {{0xf1bee561, 0xc1d64, 0x0, 0x80000000}};
  // 19878614
  s21_decimal dec_2 = {{0x12f52d6, 0x0, 0x0, 0x0}};
  // -171542095.95712221184032246916
  s21_decimal dec_check = {{0xc3cc0c84, 0x8c119e7b, 0x376da12d, 0x80140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_244) {
  // -131133273355862678370532
  s21_decimal dec_1 = {{0x570af8e4, 0xbfbdff4c, 0x1bc4, 0x80000000}};
  // -966621143064539572039
  s21_decimal dec_2 = {{0x27ec2747, 0x6690283d, 0x34, 0x80000000}};
  // 135.66149912686851220128415302
  s21_decimal dec_check = {{0x52ac3e46, 0x6144cc34, 0x2bd5a7fc, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_245) {
  // 27035399576862
  s21_decimal dec_1 = {{0xab635d1e, 0x1896, 0x0, 0x0}};
  // 17686798419.698153358431698
  s21_decimal dec_2 = {{0x3b4915d2, 0x4377d945, 0xea153, 0xf0000}};
  // 1528.5637872568342329536427133
  s21_decimal dec_check = {{0x5c96347d, 0x769889c1, 0x3163fbb9, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_246) {
  // -1260730975307429
  s21_decimal dec_1 = {{0xcdf0c6a5, 0x47aa0, 0x0, 0x80000000}};
  // 496313579216277
  s21_decimal dec_2 = {{0x2961d95, 0x1c365, 0x0, 0x0}};
  // -2.5401903717771224771651054947
  s21_decimal dec_check = {{0xeeb22d63, 0xcdc32123, 0x5213f657, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_247) {
  // 8747943226372157720528623267
  s21_decimal dec_1 = {{0x7d2f16a3, 0x8a668d3e, 0x1c442108, 0x0}};
  // 19117.65613
  s21_decimal dec_2 = {{0x71f33a6d, 0x0, 0x0, 0x50000}};
  // 457584505489907968154704.08124
  s21_decimal dec_check = {{0x6c03b1bc, 0xbd43e527, 0x93da80ce, 0x50000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_248) {
  // -672250546723
  s21_decimal dec_1 = {{0x85414a23, 0x9c, 0x0, 0x80000000}};
  // 0.5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -1344501093446
  s21_decimal dec_check = {{0xa829446, 0x139, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_249) {
  // 3209652279002980890253028988
  s21_decimal dec_1 = {{0x2f216e7c, 0xb0df1790, 0xa5ef64e, 0x0}};
  // -294654
  s21_decimal dec_2 = {{0x47efe, 0x0, 0x0, 0x80000000}};
  // -10892953358864908978846.474129
  s21_decimal dec_check = {{0x22a89f91, 0xd2bf3956, 0x23327098, 0x80060000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_250) {
  // 2087585785649
  s21_decimal dec_1 = {{0xdcf2731, 0x1e6, 0x0, 0x0}};
  // -703513639.887722
  s21_decimal dec_2 = {{0x8899a36a, 0x27fd7, 0x0, 0x80060000}};
  // -2967.3707335399644152178771184
  s21_decimal dec_check = {{0x97e984f0, 0xefdd1465, 0x5fe183f1, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_251) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // -147894010
  s21_decimal dec_2 = {{0x8d0aefa, 0x0, 0x0, 0x80000000}};
  // 0
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_253) {
  // -91
  s21_decimal dec_1 = {{0x5b, 0x0, 0x0, 0x80000000}};
  // -0.36
  s21_decimal dec_2 = {{0x24, 0x0, 0x0, 0x80020000}};
  // 252.77777777777777777777777778
  s21_decimal dec_check = {{0x3dc71c72, 0x1d1670ae, 0x51ad49a7, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_254) {
  // 403115848426860263010
  s21_decimal dec_1 = {{0x4d373662, 0xda5b3058, 0x15, 0x0}};
  // 245
  s21_decimal dec_2 = {{0xf5, 0x0, 0x0, 0x0}};
  // 1645370809905552093.9183673469
  s21_decimal dec_check = {{0xd4cf907d, 0x52692301, 0x352a3037, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_257) {
  // -77974275662524607194212281655
  s21_decimal dec_1 = {{0xa1b2d37, 0x908c2a04, 0xfbf2cf21, 0x80000000}};
  // -73494734569575375345
  s21_decimal dec_2 = {{0x12961f1, 0xfbf1bfb3, 0x3, 0x80000000}};
  // 1060950503.7222575132272829088
  s21_decimal dec_check = {{0xbb0922a0, 0x848375df, 0x2247fa14, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_258) {
  // -654939429035804.8
  s21_decimal dec_1 = {{0xb02bb720, 0x1744a3, 0x0, 0x80010000}};
  // -5708681369110
  s21_decimal dec_2 = {{0x27ecd616, 0x531, 0x0, 0x80000000}};
  // 114.72691970158281202764145561
  s21_decimal dec_check = {{0x4c28e399, 0xea45fe79, 0x2511fd05, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_259) {
  // 9754536862833406454060288821
  s21_decimal dec_1 = {{0x3b800b35, 0xe9e7f801, 0x1f84c386, 0x0}};
  // 24801660944611247893527872
  s21_decimal dec_2 = {{0x11f83d40, 0xbbdee47d, 0x1483f4, 0x0}};
  // 393.30175848375236068892400104
  s21_decimal dec_check = {{0xfdded9e8, 0xf3c7cc2d, 0x7f1528b0, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_260) {
  // 16418433364
  s21_decimal dec_1 = {{0xd29d6954, 0x3, 0x0, 0x0}};
  // 0.4245698320378871993369470
  s21_decimal dec_2 = {{0xf47c837e, 0xc462decd, 0x3830f, 0x190000}};
  // 38670748897.050400010588666020
  s21_decimal dec_check = {{0xb6b438a4, 0x4a8a5724, 0x7cf3b19a, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_261) {
  // 2450979524074099435773526722
  s21_decimal dec_1 = {{0x23e682c2, 0x3c65fea7, 0x7eb671a, 0x0}};
  // 901
  s21_decimal dec_2 = {{0x385, 0x0, 0x0, 0x0}};
  // 2720288040037846210625445.8624
  s21_decimal dec_check = {{0x207e3f00, 0x65ce9c18, 0x57e5b1fd, 0x40000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_262) {
  // 5500059594602181
  s21_decimal dec_1 = {{0x6a6136c5, 0x138a46, 0x0, 0x0}};
  // -70
  s21_decimal dec_2 = {{0x46, 0x0, 0x0, 0x80000000}};
  // -78572279922888.3
  s21_decimal dec_check = {{0x585707d3, 0x2ca9c, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_264) {
  // -65530109031444591837381.8391
  s21_decimal dec_1 = {{0x1c063017, 0x499d03b4, 0x21e0d67, 0x80040000}};
  // 1036876759896345
  s21_decimal dec_2 = {{0xaef31119, 0x3af08, 0x0, 0x0}};
  // -63199515.666640592498000890400
  s21_decimal dec_check = {{0x36278a20, 0x4a4897a1, 0xcc356a01, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_265) {
  // 33809765012
  s21_decimal dec_1 = {{0xdf381294, 0x7, 0x0, 0x0}};
  // -7942879152
  s21_decimal dec_2 = {{0xd96eb7b0, 0x1, 0x0, 0x80000000}};
  // -4.2566132966390119893391524182
  s21_decimal dec_check = {{0x55424156, 0xd2c71f4a, 0x8989e143, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_266) {
  // -55797636025359444534277796
  s21_decimal dec_1 = {{0x56bab6a4, 0xe8f006af, 0x2e279b, 0x80000000}};
  // 44007153539769279
  s21_decimal dec_2 = {{0xe25063bf, 0x9c5845, 0x0, 0x0}};
  // -1267921952.1647793618010769905
  s21_decimal dec_check = {{0xdb009f1, 0x8a2075e3, 0x28f8012b, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_267) {
  // 68168253425142284626511
  s21_decimal dec_1 = {{0xfb272a4f, 0x688e6747, 0xe6f, 0x0}};
  // -2.5882330428907919698879
  s21_decimal dec_2 = {{0xc43aebbf, 0x157d5aa0, 0x57b, 0x80160000}};
  // -26337757186271491089372.710388
  s21_decimal dec_check = {{0x848685f4, 0xfcd0eb58, 0x551a1505, 0x80060000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_268) {
  // -14108632286956349595390
  s21_decimal dec_1 = {{0xd0449efe, 0xd49aea3f, 0x2fc, 0x80000000}};
  // -0.951
  s21_decimal dec_2 = {{0x3b7, 0x0, 0x0, 0x80030000}};
  // 14835575485758516924700.315457
  s21_decimal dec_check = {{0xc9b64f41, 0x962bab53, 0x2fefb34e, 0x60000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_269) {
  // -8968204066477417422
  s21_decimal dec_1 = {{0x3799a3ce, 0x7c757615, 0x0, 0x80000000}};
  // 66006047407900
  s21_decimal dec_2 = {{0x3b023f1c, 0x3c08, 0x0, 0x0}};
  // -135869.43043349159734075239265
  s21_decimal dec_check = {{0x1e98ab61, 0x4075de04, 0x2be6db1a, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_270) {
  // -83645483446.511
  s21_decimal dec_1 = {{0x3b53f0ef, 0x4c13, 0x0, 0x80030000}};
  // 3146.7
  s21_decimal dec_2 = {{0x7aeb, 0x0, 0x0, 0x10000}};
  // -26581969.506629484857151936950
  s21_decimal dec_check = {{0xf24f59b6, 0x66cc5fb2, 0x55e416fe, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_271) {
  // -4827884306210241016077503
  s21_decimal dec_1 = {{0x3a899cbf, 0x21f656e2, 0x3fe58, 0x80000000}};
  // -2377548.9769755373191341941
  s21_decimal dec_2 = {{0x2a68a775, 0xe20d30f8, 0x13aaa7, 0x80130000}};
  // 2030614028549585281.1698103561
  s21_decimal dec_check = {{0xf9f8e509, 0x9dd30684, 0x419cd876, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_272) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // 266795986493009165663613570
  s21_decimal dec_2 = {{0xba6c3282, 0x6886c98f, 0xdcb03f, 0x0}};
  // 0
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_273) {
  // 931893753277452798595398
  s21_decimal dec_1 = {{0xb7131146, 0xfc47521, 0xc556, 0x0}};
  // -379.38008992140658355372866223
  s21_decimal dec_2 = {{0x7530baaf, 0x73e285dc, 0x7a9595e4, 0x801a0000}};
  // -2456359144915871720662.4577288
  s21_decimal dec_check = {{0xbd5da708, 0xa94531a9, 0x4f5e86d0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_274) {
  // 78516636454828189783429506.09
  s21_decimal dec_1 = {{0x5946d6d1, 0x1a576afe, 0x195ebe73, 0x20000}};
  // 36672779363190
  s21_decimal dec_2 = {{0x8bfca376, 0x215a, 0x0, 0x0}};
  // 2141005885516.2370493598909462
  s21_decimal dec_check = {{0xea33c416, 0x30c32585, 0x452dfc50, 0x100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_275) {
  // -62489189902118490784269487047
  s21_decimal dec_1 = {{0x71024bc7, 0x6fd27f7b, 0xc9e9d8ac, 0x80000000}};
  // -18384002964.254391828067435206
  s21_decimal dec_2 = {{0xf388c2c6, 0xa42788cc, 0x3b66e40d, 0x80120000}};
  // 3399106822579480181.6959172864
  s21_decimal dec_check = {{0x713c100, 0xc686443c, 0x6dd4c0ac, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_276) {
  // 199216055954634
  s21_decimal dec_1 = {{0x9a3facca, 0xb52f, 0x0, 0x0}};
  // -8181314404.18
  s21_decimal dec_2 = {{0x7c6f1322, 0xbe, 0x0, 0x80020000}};
  // -24350.128367252389594621251995
  s21_decimal dec_check = {{0xeac3919b, 0xcdc5ac13, 0x4eadf43f, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_277) {
  // 4211356
  s21_decimal dec_1 = {{0x40429c, 0x0, 0x0, 0x0}};
  // 951727.3
  s21_decimal dec_2 = {{0x9138d9, 0x0, 0x0, 0x10000}};
  // 4.4249608054744252896811933418
  s21_decimal dec_check = {{0x859fdeea, 0x3ab2bb80, 0x8efa6afb, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_278) {
  // 9001305661706847707266574
  s21_decimal dec_1 = {{0x38ccfe0e, 0xc1f7690a, 0x77219, 0x0}};
  // -1226791.0428982598
  s21_decimal dec_2 = {{0x7b417d46, 0x2b9599, 0x0, 0x800a0000}};
  // -7337276966451852170.3037725310
  s21_decimal dec_check = {{0xe3e4ea7e, 0x93d564c5, 0xed148855, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_279) {
  // -91989398879096371577203
  s21_decimal dec_1 = {{0x8fc28173, 0xc15bb3d0, 0x137a, 0x80000000}};
  // -7433874653754122844474.5139517
  s21_decimal dec_2 = {{0xa863053d, 0xcae61935, 0xf03391e4, 0x80070000}};
  // 12.374354312342558179618496449
  s21_decimal dec_check = {{0x64309fc1, 0x6d675f6f, 0x27fbd373, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_280) {
  // 62743406726682558849470
  s21_decimal dec_1 = {{0x893e1be, 0x53af551a, 0xd49, 0x0}};
  // 1847621988785930212.194733
  s21_decimal dec_2 = {{0xd327b9ad, 0xc9e8cff6, 0x1873f, 0x60000}};
  // 33959.006283482890567965042288
  s21_decimal dec_check = {{0xb3d6670, 0x6669d3af, 0x6dba3b4b, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_281) {
  // -0.5270493
  s21_decimal dec_1 = {{0x506bdd, 0x0, 0x0, 0x80070000}};
  // -0.508712859819
  s21_decimal dec_2 = {{0x71a638ab, 0x76, 0x0, 0x800c0000}};
  // 1.0360447742318212756327010308
  s21_decimal dec_check = {{0x3d169004, 0x81d7ae93, 0x2179f625, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_282) {
  // -91
  s21_decimal dec_1 = {{0x5b, 0x0, 0x0, 0x80000000}};
  // 86.7636935
  s21_decimal dec_2 = {{0x33b716c7, 0x0, 0x0, 0x70000}};
  // -1.0488257971636488711721337681
  s21_decimal dec_check = {{0xcc9e4351, 0xebfd5988, 0x21e3af03, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_283) {
  // 7416715647464
  s21_decimal dec_1 = {{0xd6b399e8, 0x6be, 0x0, 0x0}};
  // 33
  s21_decimal dec_2 = {{0x21, 0x0, 0x0, 0x0}};
  // 224748959014.06060606060606061
  s21_decimal dec_check = {{0xc3d9b26d, 0x226ea041, 0x489ecc54, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_284) {
  // -26191940917503683688322
  s21_decimal dec_1 = {{0x81df7782, 0xde32c59e, 0x58b, 0x80000000}};
  // -384905031248334731931.3998
  s21_decimal dec_2 = {{0xc859564e, 0x6f7f8d09, 0x32f11, 0x80040000}};
  // 68.047800862870642245566655262
  s21_decimal dec_check = {{0xf32aeb1e, 0x6b550f95, 0xdbdfd254, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_285) {
  // -482184114
  s21_decimal dec_1 = {{0x1cbd8bb2, 0x0, 0x0, 0x80000000}};
  // 77.19067106445
  s21_decimal dec_2 = {{0x3c40bc8d, 0x705, 0x0, 0xb0000}};
  // -6246663.0662842996322441203899
  s21_decimal dec_check = {{0x566990bb, 0xa00d1d84, 0xc9d72f91, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_287) {
  // 742863.1486
  s21_decimal dec_1 = {{0xbac7ebbe, 0x1, 0x0, 0x40000}};
  // -9.9
  s21_decimal dec_2 = {{0x63, 0x0, 0x0, 0x80010000}};
  // -75036.681676767676767676767677
  s21_decimal dec_check = {{0xc7619dbd, 0x80b36ef9, 0xf274e368, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_289) {
  // 833737
  s21_decimal dec_1 = {{0xcb8c9, 0x0, 0x0, 0x0}};
  // 0.61930201501354454252
  s21_decimal dec_2 = {{0x2c986cec, 0x5b744625, 0x3, 0x140000}};
  // 1346252.6841314501831180340076
  s21_decimal dec_check = {{0x72facb6c, 0x6cc4ee70, 0x2b7ff0f2, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_290) {
  // -49057545531852221
  s21_decimal dec_1 = {{0xe6fa85bd, 0xae4993, 0x0, 0x80000000}};
  // 642.4
  s21_decimal dec_2 = {{0x1918, 0x0, 0x0, 0x10000}};
  // -76366042235137.330323785803238
  s21_decimal dec_check = {{0xeb3065e6, 0xc5d52c65, 0xf6c08274, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_291) {
  // 1388765.213
  s21_decimal dec_1 = {{0x52c6e01d, 0x0, 0x0, 0x30000}};
  // -0.270288772
  s21_decimal dec_2 = {{0x101c4784, 0x0, 0x0, 0x80090000}};
  // -5138079.5536708420873657304566
  s21_decimal dec_check = {{0x610c5f6, 0x3f23bb86, 0xa60532ab, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_294) {
  // -954603295
  s21_decimal dec_1 = {{0x38e6171f, 0x0, 0x0, 0x80000000}};
  // 932
  s21_decimal dec_2 = {{0x3a4, 0x0, 0x0, 0x0}};
  // -1024252.4624463519313304721030
  s21_decimal dec_check = {{0x54f9686, 0x7a9e824b, 0x21186af4, 0x80160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_295) {
  // 652032061200641304465596184
  s21_decimal dec_1 = {{0xd2c55f18, 0xdd3c00f4, 0x21b5928, 0x0}};
  // 134.6
  s21_decimal dec_2 = {{0x542, 0x0, 0x0, 0x10000}};
  // 4844220365532253376416019.1976
  s21_decimal dec_check = {{0x34927de8, 0x277ffe04, 0x9c8673a2, 0x40000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_296) {
  // -31756485187711281738680905470
  s21_decimal dec_1 = {{0xa0782efe, 0x8d0f5d32, 0x669c594f, 0x80000000}};
  // -8.593365024899008
  s21_decimal dec_2 = {{0xb5bbffc0, 0x1e879e, 0x0, 0x800f0000}};
  // 3695465640723727339240878591.8
  s21_decimal dec_check = {{0xe12973fe, 0x2546fa8, 0x77682ce2, 0x10000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_298) {
  // -266592294504768627160151255
  s21_decimal dec_1 = {{0xb47c74d7, 0x3e55e732, 0xdc851d, 0x80000000}};
  // 958030331736604401
  s21_decimal dec_2 = {{0xc735bef1, 0xd4b9b82, 0x0, 0x0}};
  // -278271246.40356799140582496905
  s21_decimal dec_check = {{0x71159a89, 0x747a11fb, 0x59ea0ed9, 0x80140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_299) {
  // -701463683039963639636809647
  s21_decimal dec_1 = {{0x8a7d7af, 0x741ddb97, 0x2443cb6, 0x80000000}};
  // -563665.3140576073225185963652
  s21_decimal dec_2 = {{0xbca2ae84, 0x72a6b10, 0x123687bb, 0x80160000}};
  // 1244468420436232742851.6053898
  s21_decimal dec_check = {{0xb844838a, 0x836691b6, 0x28360062, 0x70000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_300) {
  // 1245755561
  s21_decimal dec_1 = {{0x4a40b8a9, 0x0, 0x0, 0x0}};
  // -5236033
  s21_decimal dec_2 = {{0x4fe541, 0x0, 0x0, 0x80000000}};
  // -237.91973064340885552096405810
  s21_decimal dec_check = {{0xcfe4e932, 0x3428ef48, 0x4ce04244, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_301) {
  // -59397048993508911939668
  s21_decimal dec_1 = {{0x1bf30054, 0xeba4708b, 0xc93, 0x80000000}};
  // -2140747195051733632
  s21_decimal dec_2 = {{0x52f8f280, 0x1db5763b, 0x0, 0x80000000}};
  // 27745.942692721133543706301948
  s21_decimal dec_check = {{0xd04b95fc, 0x415d2cd2, 0x59a6e7e7, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_303) {
  // 276969762690952
  s21_decimal dec_1 = {{0xc519788, 0xfbe7, 0x0, 0x0}};
  // -55
  s21_decimal dec_2 = {{0x37, 0x0, 0x0, 0x80000000}};
  // -5035813867108.2181818181818182
  s21_decimal dec_check = {{0xd7151746, 0x79c625af, 0xa2b746a7, 0x80100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_304) {
  // 789.656687406941318
  s21_decimal dec_1 = {{0xcb670486, 0xaf56c92, 0x0, 0xf0000}};
  // -306
  s21_decimal dec_2 = {{0x132, 0x0, 0x0, 0x80000000}};
  // -2.5805774098266056143790849673
  s21_decimal dec_check = {{0x4dfebe89, 0x217ada, 0x53620939, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_305) {
  // -395876166150
  s21_decimal dec_1 = {{0x2c0eea06, 0x5c, 0x0, 0x80000000}};
  // -95930.70788050
  s21_decimal dec_2 = {{0x8f939dd2, 0x8b9, 0x0, 0x80080000}};
  // 4126688.6786985799907208055724
  s21_decimal dec_check = {{0xc987cbac, 0x4ee41add, 0x85572b2f, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_306) {
  // 46943140893347519349508
  s21_decimal dec_1 = {{0x64374304, 0xcaf2c714, 0x9f0, 0x0}};
  // -12473418576805
  s21_decimal dec_2 = {{0x31aef3a5, 0xb58, 0x0, 0x80000000}};
  // -3763454309.2012355018239071576
  s21_decimal dec_check = {{0x78a55558, 0xaff3164, 0x799a907d, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_307) {
  // -37455697139532.1523270864
  s21_decimal dec_1 = {{0xbecef4d0, 0xc62bc428, 0x4f50, 0x800a0000}};
  // 342.35272827255
  s21_decimal dec_2 = {{0x5469177, 0x1f23, 0x0, 0xb0000}};
  // -109406743531.81536318147908190
  s21_decimal dec_check = {{0xfb2dd25e, 0x1bd9ddeb, 0x2359e9e9, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_308) {
  // 0.6110244479014574
  s21_decimal dec_1 = {{0x27a996ae, 0x15b53c, 0x0, 0x100000}};
  // -0.3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x80010000}};
  // -2.0367481596715246666666666667
  s21_decimal dec_check = {{0xb3e2eaab, 0xc2c7b982, 0x41cf95fd, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_309) {
  // -95329701870203376311
  s21_decimal dec_1 = {{0xc55d12b7, 0x2af722c5, 0x5, 0x80000000}};
  // -5095420248
  s21_decimal dec_2 = {{0x2fb5f158, 0x1, 0x0, 0x80000000}};
  // 18708898820.979716825704304498
  s21_decimal dec_check = {{0xce240f72, 0x536d3447, 0x3c73a36d, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_310) {
  // 8083393807
  s21_decimal dec_1 = {{0xe1cecd0f, 0x1, 0x0, 0x0}};
  // -0.512
  s21_decimal dec_2 = {{0x200, 0x0, 0x0, 0x80030000}};
  // -15787878529.296875
  s21_decimal dec_check = {{0xeb7ee9eb, 0x3816fd, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_311) {
  // 182016015403.047768194295439
  s21_decimal dec_1 = {{0x7998268f, 0xf7632ba4, 0x968f63, 0xf0000}};
  // 69132.8424145509530113840
  s21_decimal dec_2 = {{0x5e9e9730, 0xfd2d015e, 0x9264, 0x130000}};
  // 2632844.3767956136196890390583
  s21_decimal dec_check = {{0xc0077037, 0x91ab911e, 0x551260d4, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_312) {
  // -57898
  s21_decimal dec_1 = {{0xe22a, 0x0, 0x0, 0x80000000}};
  // 3025.9
  s21_decimal dec_2 = {{0x7633, 0x0, 0x0, 0x10000}};
  // -19.134141908192603853398988731
  s21_decimal dec_check = {{0xfb07d7bb, 0x4681c847, 0x3dd36427, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_314) {
  // 97048655648829522716
  s21_decimal dec_1 = {{0x75b0c31c, 0x42d21620, 0x5, 0x0}};
  // -5.28368582229
  s21_decimal dec_2 = {{0x538be55, 0x7b, 0x0, 0x800b0000}};
  // -18367605287849553970.418423064
  s21_decimal dec_check = {{0xa88c1518, 0xd27785cf, 0x3b5953b5, 0x80090000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_315) {
  // -54514679466
  s21_decimal dec_1 = {{0xb153feaa, 0xc, 0x0, 0x80000000}};
  // -79.49
  s21_decimal dec_2 = {{0x1f0d, 0x0, 0x0, 0x80020000}};
  // 685805503.40923386589508114228
  s21_decimal dec_check = {{0xfa8d9734, 0x7e78df7a, 0xdd98806b, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_316) {
  // -5404238922
  s21_decimal dec_1 = {{0x421e244a, 0x1, 0x0, 0x80000000}};
  // 0.8934035
  s21_decimal dec_2 = {{0x885293, 0x0, 0x0, 0x70000}};
  // -6049046060.3747354918578223613
  s21_decimal dec_check = {{0x950af9fd, 0xfc4092a, 0xc3748948, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_317) {
  // -391014284.74083906059288942
  s21_decimal dec_1 = {{0x35b4c16e, 0xaf58846d, 0x20580c, 0x80110000}};
  // 0.16
  s21_decimal dec_2 = {{0x10, 0x0, 0x0, 0x20000}};
  // -2443839279.630244128705558875
  s21_decimal dec_check = {{0x9ca1395b, 0xcf1c54a9, 0x7e57f18, 0x80120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_319) {
  // -938967.517836
  s21_decimal dec_1 = {{0x9ed34a8c, 0xda, 0x0, 0x80060000}};
  // 87937.2600015996
  s21_decimal dec_2 = {{0xe372fc7c, 0x31fc8, 0x0, 0xa0000}};
  // -10.677698143186630491445363045
  s21_decimal dec_check = {{0xc8f78165, 0x3309da18, 0x22806288, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_320) {
  // -539998953593741315758932850
  s21_decimal dec_1 = {{0xb84cc372, 0xee6a7112, 0x1bead39, 0x80000000}};
  // -8825391691
  s21_decimal dec_2 = {{0xe08ca4b, 0x2, 0x0, 0x80000000}};
  // 61186967389155545.612931011381
  s21_decimal dec_check = {{0xb8739335, 0x8e5d147c, 0xc5b4ac54, 0xc0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_321) {
  // 920943
  s21_decimal dec_1 = {{0xe0d6f, 0x0, 0x0, 0x0}};
  // -68.0348
  s21_decimal dec_2 = {{0xa619c, 0x0, 0x0, 0x80040000}};
  // -13536.351984572601080623445648
  s21_decimal dec_check = {{0xae50b690, 0x75c9631e, 0x2bbd0207, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_322) {
  // 4284347028.439273626734235970
  s21_decimal dec_1 = {{0x8e811142, 0xcbb87c76, 0xdd7edc5, 0x120000}};
  // 5.9
  s21_decimal dec_2 = {{0x3b, 0x0, 0x0, 0x10000}};
  // 726160513.29479214012444677458
  s21_decimal dec_check = {{0x188b9552, 0x6fe01ad5, 0xeaa296fe, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_323) {
  // -4711682257533890579
  s21_decimal dec_1 = {{0xb6d17013, 0x4163420c, 0x0, 0x80000000}};
  // 9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x0}};
  // -523520250837098953.22222222222
  s21_decimal dec_check = {{0x4fd05b8e, 0x7d1b15b7, 0xa9289486, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_324) {
  // -3317687440424
  s21_decimal dec_1 = {{0x7594d428, 0x304, 0x0, 0x80000000}};
  // -4379551764.054734100458232467
  s21_decimal dec_2 = {{0x8ab9da93, 0xdae41e2a, 0xe26ae28, 0x80120000}};
  // 757.54041033468116055348236702
  s21_decimal dec_check = {{0xde34519e, 0x26f09ca7, 0xf4c64629, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_325) {
  // -47561624698111532946490704
  s21_decimal dec_1 = {{0xfe410550, 0xd75af4e2, 0x275790, 0x80000000}};
  // -10
  s21_decimal dec_2 = {{0xa, 0x0, 0x0, 0x80000000}};
  // 4756162469811153294649070.4
  s21_decimal dec_check = {{0xfe410550, 0xd75af4e2, 0x275790, 0x10000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_326) {
  // 7086467394704857116340
  s21_decimal dec_1 = {{0x4ae02eb4, 0x287da5c5, 0x180, 0x0}};
  // 428487963.11117300
  s21_decimal dec_2 = {{0xd32d5df4, 0x983ac0, 0x0, 0x80000}};
  // 16538311469128.115077021708688
  s21_decimal dec_check = {{0xd0d43190, 0x341aa9b1, 0x35702bad, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_327) {
  // -625342532502476913
  s21_decimal dec_1 = {{0x58c0d871, 0x8ada9b8, 0x0, 0x80000000}};
  // -30743160593.2
  s21_decimal dec_2 = {{0x945a06ac, 0x47, 0x0, 0x80010000}};
  // 20340866.730559733236009774024
  s21_decimal dec_check = {{0xfdbfabc8, 0xf9bd966b, 0x41b99212, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_328) {
  // -840123997441374532953249
  s21_decimal dec_1 = {{0x275c64a1, 0x36919939, 0xb1e7, 0x80000000}};
  // -704819281.1793
  s21_decimal dec_2 = {{0x9076311, 0x669, 0x0, 0x80040000}};
  // 1191970792904080.8544304668402
  s21_decimal dec_check = {{0xd7d89ef2, 0x9a5a123a, 0x2683c055, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_329) {
  // -61846521016
  s21_decimal dec_1 = {{0x665704b8, 0xe, 0x0, 0x80000000}};
  // 0.1233575
  s21_decimal dec_2 = {{0x12d2a7, 0x0, 0x0, 0x70000}};
  // -501360039040.99872322315222017
  s21_decimal dec_check = {{0xa37dfc01, 0xa0daef34, 0xa1ff87c9, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_330) {
  // -17101959467685367689558376
  s21_decimal dec_1 = {{0xc584b968, 0x14972335, 0xe257b, 0x80000000}};
  // 90625112366647898325093
  s21_decimal dec_2 = {{0xe3f8c065, 0xcc14590a, 0x1330, 0x0}};
  // -188.71104290050268207505890204
  s21_decimal dec_check = {{0x432a5b9c, 0x6c746758, 0x3cf9cfc5, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_331) {
  // 1686703110987544308979995683
  s21_decimal dec_1 = {{0xb50e1423, 0xdd10cee3, 0x5733546, 0x0}};
  // -797993228871028
  s21_decimal dec_2 = {{0x46f0a574, 0x2d5c5, 0x0, 0x80000000}};
  // -2113680981195.5810122378270923
  s21_decimal dec_check = {{0x628058cb, 0xe0740cea, 0x444bf593, 0x80100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_332) {
  // -517.457
  s21_decimal dec_1 = {{0x7e551, 0x0, 0x0, 0x80030000}};
  // -342.9
  s21_decimal dec_2 = {{0xd65, 0x0, 0x0, 0x80010000}};
  // 1.5090609507144940215806357539
  s21_decimal dec_check = {{0xc7a7023, 0x96beb6fb, 0x30c2a8dc, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_333) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // 27587429848
  s21_decimal dec_2 = {{0x6c56c5d8, 0x6, 0x0, 0x0}};
  // 0
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_334) {
  // -8360756525051350653102049151
  s21_decimal dec_1 = {{0xfdb5c77f, 0x677679fa, 0x1b03db0f, 0x80000000}};
  // 165270564588864.3491
  s21_decimal dec_2 = {{0x4d79a1a3, 0x16ef9707, 0x0, 0x40000}};
  // -50588297715627.724527592900628
  s21_decimal dec_check = {{0xb3e58814, 0x4806c028, 0xa375a8ba, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_336) {
  // 53562278516407528
  s21_decimal dec_1 = {{0xc854bce8, 0xbe4a9b, 0x0, 0x0}};
  // -1.0317407424148069414750599
  s21_decimal dec_2 = {{0x17be4987, 0xc6f58758, 0x888cb, 0x80190000}};
  // -51914474552050832.546049600303
  s21_decimal dec_check = {{0x9830ab2f, 0xa38b8038, 0xa7bea598, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_338) {
  // 6459082619942262702892391
  s21_decimal dec_1 = {{0x9a906567, 0x92085f17, 0x557c3, 0x0}};
  // -599.4021242
  s21_decimal dec_2 = {{0x6545817a, 0x1, 0x0, 0x80070000}};
  // -10775875425137945653767.489601
  s21_decimal dec_check = {{0xa402c841, 0x5181be2b, 0x22d19861, 0x80060000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_341) {
  // 314690522064331353699033920.29
  s21_decimal dec_1 = {{0xeeb7c51d, 0x69ea15cc, 0x65ae9702, 0x20000}};
  // -2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -157345261032165676849516960.14
  s21_decimal dec_check = {{0x775be28e, 0x34f50ae6, 0x32d74b81, 0x80020000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_342) {
  // -891255818079379707
  s21_decimal dec_1 = {{0xc89f20fb, 0xc5e6071, 0x0, 0x80000000}};
  // 2401.735628018846
  s21_decimal dec_2 = {{0xa6f3d49e, 0x8885d, 0x0, 0xc0000}};
  // -371088227897323.83411895117834
  s21_decimal dec_check = {{0x6259a80a, 0x59b200ee, 0x77e7b2e2, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_343) {
  // 186804
  s21_decimal dec_1 = {{0x2d9b4, 0x0, 0x0, 0x0}};
  // 93
  s21_decimal dec_2 = {{0x5d, 0x0, 0x0, 0x0}};
  // 2008.6451612903225806451612903
  s21_decimal dec_check = {{0x76739ce7, 0xcfcdacbf, 0x40e71f93, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_344) {
  // -9886425314578652346862
  s21_decimal dec_1 = {{0x421639ee, 0xf1b67315, 0x217, 0x80000000}};
  // -57468690568296
  s21_decimal dec_2 = {{0x78e31468, 0x3444, 0x0, 0x80000000}};
  // 172031504.75178460345001455571
  s21_decimal dec_check = {{0x199a2fd3, 0xf06dda7f, 0x37961ccf, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_345) {
  // 2928958
  s21_decimal dec_1 = {{0x2cb13e, 0x0, 0x0, 0x0}};
  // 0.184151156832
  s21_decimal dec_2 = {{0xe043a860, 0x2a, 0x0, 0xc0000}};
  // 15905183.819573128621115780491
  s21_decimal dec_check = {{0x2a832d8b, 0x8c51da44, 0x336475ae, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_346) {
  // -198529660
  s21_decimal dec_1 = {{0xbd5527c, 0x0, 0x0, 0x80000000}};
  // -943955
  s21_decimal dec_2 = {{0xe6753, 0x0, 0x0, 0x80000000}};
  // 210.31686891853954902511242591
  s21_decimal dec_check = {{0x4b2ecd5f, 0xf58abcbd, 0x43f500ee, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_347) {
  // -50.53852414306109035374697667
  s21_decimal dec_1 = {{0x3943dcc3, 0x59c04000, 0x105472e0, 0x801a0000}};
  // -0.111443
  s21_decimal dec_2 = {{0x1b353, 0x0, 0x0, 0x80060000}};
  // 453.49213627649193178348551879
  s21_decimal dec_check = {{0xc1e7ec7, 0xc7c36010, 0x9287fd84, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_349) {
  // 731234868009185960
  s21_decimal dec_1 = {{0xfb1132a8, 0xa25de3c, 0x0, 0x0}};
  // 516018739.11281
  s21_decimal dec_2 = {{0x7f5d3df1, 0x2eee, 0x0, 0x50000}};
  // 1417070374.7433603395267424970
  s21_decimal dec_check = {{0x7d72ca, 0x6e48e1b7, 0x2dc9bb3d, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_350) {
  // 48413463880649728510567238235
  s21_decimal dec_1 = {{0x98edca5b, 0xd8f245d8, 0x9c6eadbf, 0x0}};
  // -618669631548564440
  s21_decimal dec_2 = {{0x85c623d8, 0x895f4c0, 0x0, 0x80000000}};
  // -78254146335.691538976236829611
  s21_decimal dec_check = {{0x640afbab, 0x28636d4e, 0xfcda500d, 0x80120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_351) {
  // 25358344319556
  s21_decimal dec_1 = {{0x331af244, 0x1710, 0x0, 0x0}};
  // -2034038
  s21_decimal dec_2 = {{0x1f0976, 0x0, 0x0, 0x80000000}};
  // -12466996.348915801966334945561
  s21_decimal dec_check = {{0xec6fa919, 0x4b0d1280, 0x2848752a, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_352) {
  // 247694443319117507881922
  s21_decimal dec_1 = {{0xeaa6bc2, 0x8aecf155, 0x3473, 0x0}};
  // 0.09316028
  s21_decimal dec_2 = {{0x8e26bc, 0x0, 0x0, 0x80000}};
  // 2658798828418264821465993.8764
  s21_decimal dec_check = {{0x11a39cc, 0xfc8b279a, 0x55e91184, 0x40000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_353) {
  // -838106720301837
  s21_decimal dec_1 = {{0xed58f30d, 0x2fa40, 0x0, 0x80000000}};
  // -7529592525
  s21_decimal dec_2 = {{0xc0cc76cd, 0x1, 0x0, 0x80000000}};
  // 111308.37658467275425372370997
  s21_decimal dec_check = {{0xe7bef835, 0x8b706d84, 0x23f7368e, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_354) {
  // 52246366549813912244081940
  s21_decimal dec_1 = {{0x6985514, 0x34b52619, 0x2b3799, 0x0}};
  // 3305444893747103896732350
  s21_decimal dec_2 = {{0xe7dc82be, 0x86d8895e, 0x2bbf4, 0x0}};
  // 15.806152644882430962597788944
  s21_decimal dec_check = {{0xc5027d10, 0xcf9a8770, 0x33128b03, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_355) {
  // 25268564801047679352316200
  s21_decimal dec_1 = {{0x58c22128, 0xa48456c5, 0x14e6d3, 0x0}};
  // 40925453431051
  s21_decimal dec_2 = {{0xb31d310b, 0x2538, 0x0, 0x0}};
  // 617429073659.96070274693059892
  s21_decimal dec_check = {{0x86dbd534, 0x16d67218, 0xc7808933, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_356) {
  // -35081189647407.428
  s21_decimal dec_1 = {{0xf73b5944, 0x7ca227, 0x0, 0x80030000}};
  // 0.18441250867068141
  s21_decimal dec_2 = {{0x4f253ced, 0x418438, 0x0, 0x110000}};
  // -190232158871903.93539058348053
  s21_decimal dec_check = {{0xe1f63015, 0xa0ac516f, 0x3d77a2a7, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_357) {
  // -583432603
  s21_decimal dec_1 = {{0x22c6799b, 0x0, 0x0, 0x80000000}};
  // 3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x0}};
  // -194477534.33333333333333333333
  s21_decimal dec_check = {{0xd8e55555, 0x1e7ebd39, 0x3ed6cdfa, 0x80140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_358) {
  // -749990972019573295351
  s21_decimal dec_1 = {{0xe89888f7, 0xa8372f6d, 0x28, 0x80000000}};
  // -342263457973907987103
  s21_decimal dec_2 = {{0x439f9a9f, 0x8ddc11a3, 0x12, 0x80000000}};
  // 2.1912680262721703961551081062
  s21_decimal dec_check = {{0x26968e66, 0x4a8926ef, 0x46cdbe89, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_359) {
  // 859229195508
  s21_decimal dec_1 = {{0xe0d0cf4, 0xc8, 0x0, 0x0}};
  // 8022088740.93
  s21_decimal dec_2 = {{0xc75ffe6d, 0xba, 0x0, 0x20000}};
  // 107.10791456644864283229092803
  s21_decimal dec_check = {{0xc2b4fbc3, 0x5111c078, 0x229bc250, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_360) {
  // 582907765366140543308
  s21_decimal dec_1 = {{0x98da14c, 0x99786439, 0x1f, 0x0}};
  // -8436.2817380
  s21_decimal dec_2 = {{0xa46a6f64, 0x13, 0x0, 0x80070000}};
  // -69095341226042460.947977410946
  s21_decimal dec_check = {{0x716d1982, 0x4b8d39c6, 0xdf4253a1, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_361) {
  // -26801473
  s21_decimal dec_1 = {{0x198f541, 0x0, 0x0, 0x80000000}};
  // 8937037.64588
  s21_decimal dec_2 = {{0x14e53a6c, 0xd0, 0x0, 0x50000}};
  // -2.9989213497780840121095054500
  s21_decimal dec_check = {{0x758264a4, 0x45729b4b, 0x60e67ef9, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_363) {
  // -888107058135013931359171
  s21_decimal dec_1 = {{0xe8301bc3, 0x614dacef, 0xbc10, 0x80000000}};
  // -31773178220154.63
  s21_decimal dec_2 = {{0xf41ea7e7, 0xb49c0, 0x0, 0x80020000}};
  // 27951470639.209217750525369969
  s21_decimal dec_check = {{0xa0215e71, 0x8f4d2b52, 0x5a50ea23, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_364) {
  // 51
  s21_decimal dec_1 = {{0x33, 0x0, 0x0, 0x0}};
  // 4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x0}};
  // 12.75
  s21_decimal dec_check = {{0x4fb, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_365) {
  // -29914933621104.65303851
  s21_decimal dec_1 = {{0x7547e52b, 0x2b4f633a, 0xa2, 0x80080000}};
  // -7182.6322391660157311992867410
  s21_decimal dec_2 = {{0x5e322a52, 0xef21c078, 0xe8155762, 0x80190000}};
  // 4164898413.9800693452909428761
  s21_decimal dec_check = {{0x4cf1c019, 0x4f2f09d0, 0x86933b72, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_366) {
  // 968866322680258944592476
  s21_decimal dec_1 = {{0x6fb46a5c, 0x593d83ea, 0xcd2a, 0x0}};
  // 8.6
  s21_decimal dec_2 = {{0x56, 0x0, 0x0, 0x10000}};
  // 112658874730262667975869.30233
  s21_decimal dec_check = {{0xa8b25a39, 0xa95fa0a3, 0x2466ec77, 0x50000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_367) {
  // 83579775698608595282443
  s21_decimal dec_1 = {{0x17222a0b, 0xde646541, 0x11b2, 0x0}};
  // -73251384
  s21_decimal dec_2 = {{0x45dba38, 0x0, 0x0, 0x80000000}};
  // -1140999270383868.7236604703605
  s21_decimal dec_check = {{0xa8163375, 0xe0959df4, 0x24de1fef, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_368) {
  // 84223178699011714809.3891996
  s21_decimal dec_1 = {{0x3f90c59c, 0xa8d86104, 0x2b8ad84, 0x70000}};
  // -442489
  s21_decimal dec_2 = {{0x6c079, 0x0, 0x0, 0x80000000}};
  // -190339598722254.59798862615703
  s21_decimal dec_check = {{0x35565497, 0x393339d4, 0x3d8085c8, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_369) {
  // 38160862205377760569397
  s21_decimal dec_1 = {{0xbb19a835, 0xb45926e0, 0x814, 0x0}};
  // 3.009379852660445728210104
  s21_decimal dec_2 = {{0xed53fcb8, 0xcf0740de, 0x27d42, 0x180000}};
  // 12680639890521499418456.076928
  s21_decimal dec_check = {{0x6eadb280, 0xe3f7047e, 0x28f92df1, 0x60000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_370) {
  // 200962343204137179837484843
  s21_decimal dec_1 = {{0x9de5cf2b, 0x74592398, 0xa63b6e, 0x0}};
  // 4393803740187199739530
  s21_decimal dec_2 = {{0x90c3168a, 0x3046a654, 0xee, 0x0}};
  // 45737.669474416510926171873156
  s21_decimal dec_check = {{0x7d31f84, 0x6de7a807, 0x93c9503e, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_371) {
  // -10849996898805027728312
  s21_decimal dec_1 = {{0x43946bb8, 0x2df465b7, 0x24c, 0x80000000}};
  // -50.620
  s21_decimal dec_2 = {{0xc5bc, 0x0, 0x0, 0x80030000}};
  // 214342095985875695936.62583959
  s21_decimal dec_check = {{0x6d4c3497, 0x9d6b0d7c, 0x4541f66e, 0x80000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_373) {
  // 34842008304519458819808993675
  s21_decimal dec_1 = {{0x73e8a18b, 0xe03aee3b, 0x7094a23e, 0x0}};
  // 921558916822116630
  s21_decimal dec_2 = {{0xc4c6a916, 0xcca08f3, 0x0, 0x0}};
  // 37807683989.069162313449417180
  s21_decimal dec_check = {{0xa63329dc, 0xe134b39c, 0x7a29c87f, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_374) {
  // 417771
  s21_decimal dec_1 = {{0x65feb, 0x0, 0x0, 0x0}};
  // -57
  s21_decimal dec_2 = {{0x39, 0x0, 0x0, 0x80000000}};
  // -7329.3157894736842105263157895
  s21_decimal dec_check = {{0x281af287, 0xe3cc8111, 0xecd2ade2, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_375) {
  // -5739570553904294960.7826486562
  s21_decimal dec_1 = {{0x6ee97522, 0xd6a390d3, 0xb9749d67, 0x800a0000}};
  // -0.9332973207273608581352693710
  s21_decimal dec_2 = {{0x8f029fce, 0x5a8f8832, 0x1e280df3, 0x801c0000}};
  // 6149777167935281076.9590081265
  s21_decimal dec_check = {{0xe17556f1, 0xe37ac8cd, 0xc6b5c3b2, 0xa0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_376) {
  // 2850154688
  s21_decimal dec_1 = {{0xa9e1e8c0, 0x0, 0x0, 0x0}};
  // -88.2
  s21_decimal dec_2 = {{0x372, 0x0, 0x0, 0x80010000}};
  // -32314679.002267573696145124717
  s21_decimal dec_check = {{0x291fed6d, 0xdf1b5529, 0x686a1372, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_377) {
  // 2388191840285589603
  s21_decimal dec_1 = {{0x57b58063, 0x21248fd3, 0x0, 0x0}};
  // -13.7770018659725247
  s21_decimal dec_2 = {{0x1ee96fbf, 0x1e9751a, 0x0, 0x80100000}};
  // -173346266736315497.83826241729
  s21_decimal dec_check = {{0x921418c1, 0xf056d567, 0x3802ddfa, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_378) {
  // 11374447840
  s21_decimal dec_1 = {{0xa5f84ce0, 0x2, 0x0, 0x0}};
  // 0.50186
  s21_decimal dec_2 = {{0xc40a, 0x0, 0x0, 0x50000}};
  // 22664583429.641732754154545092
  s21_decimal dec_check = {{0x3d115fc4, 0xa5135acd, 0x493bb439, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_379) {
  // 237837618575501624004
  s21_decimal dec_1 = {{0x99f02c4, 0xe4a8f5fa, 0xc, 0x0}};
  // -364234.542218608148479352869
  s21_decimal dec_2 = {{0xbb162025, 0x192fb00e, 0x12d49aa, 0x80150000}};
  // -652979305935116.46388054891831
  s21_decimal dec_check = {{0xb839d37, 0x6a2689ce, 0xd2fd2ea6, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_380) {
  // 38198890293462
  s21_decimal dec_1 = {{0xdf4968d6, 0x22bd, 0x0, 0x0}};
  // -0.9762813380
  s21_decimal dec_2 = {{0x45e8b5c4, 0x2, 0x0, 0x800a0000}};
  // -39126928690162.056544401548317
  s21_decimal dec_check = {{0x501ce41d, 0x6d8e814e, 0x7e6d096e, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_381) {
  // -913092241
  s21_decimal dec_1 = {{0x366cae91, 0x0, 0x0, 0x80000000}};
  // 387910.3592616586656313831495
  s21_decimal dec_2 = {{0x3f74f047, 0x1edd1cfe, 0xc88b823, 0x160000}};
  // -2353.8743402933675742721919361
  s21_decimal dec_check = {{0x53bec981, 0xc0818567, 0x4c0ecacc, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_382) {
  // -61905232447867425
  s21_decimal dec_1 = {{0x1dcb0a21, 0xdbee7b, 0x0, 0x80000000}};
  // -146547259901619
  s21_decimal dec_2 = {{0xb15e86b3, 0x8548, 0x0, 0x80000000}};
  // 422.42504219748648372157157872
  s21_decimal dec_check = {{0x1ba611f0, 0x5060e799, 0x887e2e36, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_384) {
  // -123777198589921693184
  s21_decimal dec_1 = {{0x5d438e00, 0xb5c0f251, 0x6, 0x80000000}};
  // -9.17
  s21_decimal dec_2 = {{0x395, 0x0, 0x0, 0x80020000}};
  // 13498058733906400565.321701200
  s21_decimal dec_check = {{0xbbca9750, 0x2e91d718, 0x2b9d551e, 0x90000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_385) {
  // 76340481247941168.5494
  s21_decimal dec_1 = {{0xb068876, 0x625eb842, 0x29, 0x40000}};
  // 157887257
  s21_decimal dec_2 = {{0x9692b19, 0x0, 0x0, 0x0}};
  // 483512619.69128495626090964390
  s21_decimal dec_check = {{0x25fbe5a6, 0x779d4013, 0x9c3b39fb, 0x140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_386) {
  // -128234.96647
  s21_decimal dec_1 = {{0xfc5707c7, 0x2, 0x0, 0x80050000}};
  // -0.2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x80010000}};
  // 641174.83235
  s21_decimal dec_check = {{0xedb326e3, 0xe, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_387) {
  // 84095906903358608137666
  s21_decimal dec_1 = {{0xe20e5dc2, 0xd926c964, 0x11ce, 0x0}};
  // 2622.656
  s21_decimal dec_2 = {{0x2804c0, 0x0, 0x0, 0x30000}};
  // 32065168631859690381.684063789
  s21_decimal dec_check = {{0x7a953e2d, 0x96bcaa77, 0x679baf92, 0x90000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_388) {
  // 357113258274847
  s21_decimal dec_1 = {{0xe8e7701f, 0x144ca, 0x0, 0x0}};
  // 55791486
  s21_decimal dec_2 = {{0x3534f7e, 0x0, 0x0, 0x0}};
  // 6400855.8272645220455321803044
  s21_decimal dec_check = {{0xc459924, 0xd7e5a36a, 0xced2a370, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_389) {
  // 20142432679
  s21_decimal dec_1 = {{0xb09521a7, 0x4, 0x0, 0x0}};
  // 3747
  s21_decimal dec_2 = {{0xea3, 0x0, 0x0, 0x0}};
  // 5375615.8737656792100346944222
  s21_decimal dec_check = {{0x421a5ade, 0x64645a9f, 0xadb20d64, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_390) {
  // 29944714740955662243757
  s21_decimal dec_1 = {{0x398bd7ad, 0x4e65ab00, 0x657, 0x0}};
  // 793796205661082664
  s21_decimal dec_2 = {{0x7e7b5428, 0xb042171, 0x0, 0x0}};
  // 37723.428919665038406589754889
  s21_decimal dec_check = {{0x99422e09, 0x6a486291, 0x79e416cb, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_391) {
  // 969954
  s21_decimal dec_1 = {{0xecce2, 0x0, 0x0, 0x0}};
  // 921010
  s21_decimal dec_2 = {{0xe0db2, 0x0, 0x0, 0x0}};
  // 1.0531416596996775279312928198
  s21_decimal dec_check = {{0x58267dc6, 0xb0d110e7, 0x22076235, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_392) {
  // -319975456
  s21_decimal dec_1 = {{0x13127020, 0x0, 0x0, 0x80000000}};
  // -21
  s21_decimal dec_2 = {{0x15, 0x0, 0x0, 0x80000000}};
  // 15236926.476190476190476190476
  s21_decimal dec_check = {{0x9030c30c, 0x5fd76b7e, 0x313bb0af, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_393) {
  // 333215.82
  s21_decimal dec_1 = {{0x1fc726e, 0x0, 0x0, 0x20000}};
  // -73324.47901698954829813689
  s21_decimal dec_2 = {{0x6f14d7b9, 0xcc177539, 0x610b4, 0x80140000}};
  // -4.5444007849383107567419521034
  s21_decimal dec_check = {{0xbfd1f80a, 0xd664b35c, 0x92d666f9, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_394) {
  // -713149639954
  s21_decimal dec_1 = {{0xb07ed12, 0xa6, 0x0, 0x80000000}};
  // 58.92498192165
  s21_decimal dec_2 = {{0xf442f725, 0x55b, 0x0, 0xb0000}};
  // -12102670492.156352853199857508
  s21_decimal dec_check = {{0xd388a764, 0x60b10c2, 0x271b182a, 0x80120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_395) {
  // 32022.9990
  s21_decimal dec_1 = {{0x13165266, 0x0, 0x0, 0x40000}};
  // 5.223379256604604846880772
  s21_decimal dec_2 = {{0x330cb804, 0xf4f68081, 0x45217, 0x180000}};
  // 6130.7053206043030332785204045
  s21_decimal dec_check = {{0x38d29b4d, 0xbbdb2ddf, 0xc618017d, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_396) {
  // -2630239184591999267.3688
  s21_decimal dec_1 = {{0xd8117598, 0xdb034bd1, 0x591, 0x80040000}};
  // -5774781915806
  s21_decimal dec_2 = {{0x8bd3229e, 0x540, 0x0, 0x80000000}};
  // 455469.87279170533834760156433
  s21_decimal dec_check = {{0x6dec7511, 0xe98d90d1, 0x932b95b7, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_397) {
  // -9706194719
  s21_decimal dec_1 = {{0x4288c71f, 0x2, 0x0, 0x80000000}};
  // 2979612770
  s21_decimal dec_2 = {{0xb1994862, 0x0, 0x0, 0x0}};
  // -3.2575356156095411015438761192
  s21_decimal dec_check = {{0x5952fce8, 0xb24645cd, 0x6941b3fb, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_398) {
  // -37462118342272051928573833
  s21_decimal dec_1 = {{0x59972789, 0x812f6edd, 0x1efce9, 0x80000000}};
  // 35467891
  s21_decimal dec_2 = {{0x21d3273, 0x0, 0x0, 0x0}};
  // -1056226273568734378.0484109698
  s21_decimal dec_check = {{0xc4305582, 0x384139e2, 0x2220e622, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_399) {
  // 6841442.44489124470
  s21_decimal dec_1 = {{0xcbe6fa76, 0x97e9190, 0x0, 0xb0000}};
  // 3260
  s21_decimal dec_2 = {{0xcbc, 0x0, 0x0, 0x0}};
  // 2098.6019769605045092024539877
  s21_decimal dec_check = {{0xca7b5ae5, 0x4d2d94a7, 0x43cf3a8b, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_400) {
  // -63083.27248506468707
  s21_decimal dec_1 = {{0xa6253963, 0x578bae35, 0x0, 0x800e0000}};
  // 8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x0}};
  // -7885.40906063308588375
  s21_decimal dec_check = {{0x202d0557, 0xbf341032, 0x2a, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_401) {
  // 1934321446943244453836380589
  s21_decimal dec_1 = {{0x641e59ad, 0xc0c87125, 0x640087f, 0x0}};
  // -7375.32
  s21_decimal dec_2 = {{0xb40fc, 0x0, 0x0, 0x80020000}};
  // -262269494332889210751042.74648
  s21_decimal dec_check = {{0xfafad8d8, 0xa9769887, 0x54be6c91, 0x80050000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_402) {
  // -2472982564775632
  s21_decimal dec_1 = {{0x1f4f26d0, 0x8c92a, 0x0, 0x80000000}};
  // 71698534
  s21_decimal dec_2 = {{0x4460866, 0x0, 0x0, 0x0}};
  // -34491396.501574662600493337841
  s21_decimal dec_check = {{0xb94f8cf1, 0xf40c0c1c, 0x6f729d4e, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_403) {
  // 565552065561640465837
  s21_decimal dec_1 = {{0x7e0275ad, 0xa89c8f34, 0x1e, 0x0}};
  // 76996223
  s21_decimal dec_2 = {{0x496de7f, 0x0, 0x0, 0x0}};
  // 7345192316272.9744007962572398
  s21_decimal dec_check = {{0x76bc366e, 0x50415069, 0xed5601bd, 0x100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_404) {
  // 979898219
  s21_decimal dec_1 = {{0x3a680f6b, 0x0, 0x0, 0x0}};
  // 0.8502
  s21_decimal dec_2 = {{0x2136, 0x0, 0x0, 0x40000}};
  // 1152550245.8245118795577511174
  s21_decimal dec_check = {{0x1dd34d06, 0x35f83b9c, 0x253dac14, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_405) {
  // 3892240152718527617770418501
  s21_decimal dec_1 = {{0x87e37145, 0x787ba9ef, 0xc9395e9, 0x0}};
  // 970900823017.7459
  s21_decimal dec_2 = {{0xa2ae5ab3, 0x227e4a, 0x0, 0x40000}};
  // 4008895718741589.8969067019947
  s21_decimal dec_check = {{0xc3dcdeab, 0xc3841f08, 0x8188cee3, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_406) {
  // -143000517233349685260440568
  s21_decimal dec_1 = {{0x6659d3f8, 0x929277db, 0x764989, 0x80000000}};
  // -589495519176761102421084
  s21_decimal dec_2 = {{0x55a1cc5c, 0x9dba9225, 0x7cd4, 0x80000000}};
  // 242.58117760259135893584586985
  s21_decimal dec_check = {{0x97a9a8e9, 0xcdda00b2, 0x4e61d83e, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_408) {
  // -24213893403852254201840107321
  s21_decimal dec_1 = {{0x2a8f7f39, 0xa3b32025, 0x4e3d435f, 0x80000000}};
  // -231743730449122716866617
  s21_decimal dec_2 = {{0x1ba4d839, 0xda512492, 0x3112, 0x80000000}};
  // 104485.64609245469965997797801
  s21_decimal dec_check = {{0xabb771a9, 0x6f59312c, 0x21c2d99e, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_409) {
  // 46232
  s21_decimal dec_1 = {{0xb498, 0x0, 0x0, 0x0}};
  // 8227
  s21_decimal dec_2 = {{0x2023, 0x0, 0x0, 0x0}};
  // 5.6195453992950042542846724201
  s21_decimal dec_check = {{0xb7834869, 0x25f5d848, 0xb593ca41, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_410) {
  // -336600986521455118720559351
  s21_decimal dec_1 = {{0xbbcde8f7, 0xad88442, 0x1166e08, 0x80000000}};
  // 5744.4596
  s21_decimal dec_2 = {{0x36c88f4, 0x0, 0x0, 0x40000}};
  // -58595761822653451809559.136076
  s21_decimal dec_check = {{0x7253c74c, 0x5405171d, 0xbd554735, 0x80060000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_411) {
  // 53.7649736541
  s21_decimal dec_1 = {{0x2e6beb5d, 0x7d, 0x0, 0xa0000}};
  // -33
  s21_decimal dec_2 = {{0x21, 0x0, 0x0, 0x80000000}};
  // -1.6292416258818181818181818182
  s21_decimal dec_check = {{0xf5311746, 0x24770979, 0x34a4c557, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_412) {
  // 78209287376
  s21_decimal dec_1 = {{0x35a304d0, 0x12, 0x0, 0x0}};
  // 52741643630.13
  s21_decimal dec_2 = {{0xfcb17f05, 0x4cb, 0x0, 0x20000}};
  // 1.4828754280862222380904739944
  s21_decimal dec_check = {{0x1fd7f468, 0x5406b3e2, 0x2fea0edc, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_413) {
  // -5.37
  s21_decimal dec_1 = {{0x219, 0x0, 0x0, 0x80020000}};
  // -0.427930848
  s21_decimal dec_2 = {{0x1981b4e0, 0x0, 0x0, 0x80090000}};
  // 12.548756475719179749341183275
  s21_decimal dec_check = {{0x7c2ebd2b, 0xa5f7e560, 0x288c168b, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_414) {
  // 997152868.9162867
  s21_decimal dec_1 = {{0x71629a73, 0x236d0d, 0x0, 0x70000}};
  // -72734.45
  s21_decimal dec_2 = {{0x6efbe5, 0x0, 0x0, 0x80020000}};
  // -13709.498991417226637446217026
  s21_decimal dec_check = {{0x482bfd42, 0x8255a701, 0x2c4c3b55, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_415) {
  // 378299221.49061
  s21_decimal dec_1 = {{0xf71252c5, 0x2267, 0x0, 0x50000}};
  // -679466.699
  s21_decimal dec_2 = {{0x287fd6cb, 0x0, 0x0, 0x80030000}};
  // -556.75903182211730438315417721
  s21_decimal dec_check = {{0xde65a079, 0x4327f408, 0xb3e60717, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_417) {
  // -482266.7124824146321702
  s21_decimal dec_1 = {{0x29ae2126, 0x6ff37671, 0x105, 0x80100000}};
  // 94622
  s21_decimal dec_2 = {{0x1719e, 0x0, 0x0, 0x0}};
  // -5.0967714958721505798883980470
  s21_decimal dec_check = {{0x575534b6, 0x3e4ecd5f, 0xa4af8174, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_418) {
  // 831037639290222581030135018
  s21_decimal dec_1 = {{0xf6d524ea, 0xb260734b, 0x2af6b10, 0x0}};
  // 1507874.7
  s21_decimal dec_2 = {{0xe6155b, 0x0, 0x0, 0x10000}};
  // 551131761339468445906.10547282
  s21_decimal dec_check = {{0x66cb8252, 0xd99e437c, 0xb2148d00, 0x80000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_419) {
  // 389.8710043625920
  s21_decimal dec_1 = {{0x2b3b89c0, 0xdd9db, 0x0, 0xd0000}};
  // 5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  // 77.9742008725184
  s21_decimal dec_check = {{0xd5724ec0, 0x2c52b, 0x0, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_420) {
  // 82
  s21_decimal dec_1 = {{0x52, 0x0, 0x0, 0x0}};
  // -6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x80000000}};
  // -13.666666666666666666666666667
  s21_decimal dec_check = {{0x62aaaaab, 0x88218340, 0x2c28cd3c, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_421) {
  // -1545144164
  s21_decimal dec_1 = {{0x5c190764, 0x0, 0x0, 0x80000000}};
  // -39.870517127159451135081486345
  s21_decimal dec_2 = {{0x8b4c9809, 0x5e8d0889, 0x80d41e68, 0x801b0000}};
  // 38754053.755361531810806068184
  s21_decimal dec_check = {{0x9b2573d8, 0xb58ad600, 0x7d389a17, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_423) {
  // 526985165988.85100793330085
  s21_decimal dec_1 = {{0x97df79a5, 0x4f255ab6, 0x2b9758, 0xe0000}};
  // 4836858
  s21_decimal dec_2 = {{0x49cdfa, 0x0, 0x0, 0x0}};
  // 108951.96137427458237006355159
  s21_decimal dec_check = {{0x6b181ad7, 0x17bce9ca, 0x23344b86, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_424) {
  // -54959887779641379550714451365
  s21_decimal dec_1 = {{0x6734d5a5, 0x83286b99, 0xb195c0ee, 0x80000000}};
  // -0.922037495015405185705109
  s21_decimal dec_2 = {{0x6624a495, 0xc0b4e87e, 0xc33f, 0x80180000}};
  // 59606998713998200980103434658
  s21_decimal dec_check = {{0x60c711a2, 0xd8946cc, 0xc099c0f3, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_425) {
  // 1956173260886935065549798
  s21_decimal dec_1 = {{0x20335be6, 0x5d6e0e8a, 0x19e3c, 0x0}};
  // 33391
  s21_decimal dec_2 = {{0x826f, 0x0, 0x0, 0x0}};
  // 58583847769966010767.865532629
  s21_decimal dec_check = {{0x7997d0d5, 0x3ce477f8, 0xbd4b6c4f, 0x90000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_426) {
  // -6694659788515745179.2600857282
  s21_decimal dec_1 = {{0xd10cfac2, 0x614b90e4, 0xd850ed87, 0x800a0000}};
  // -952.5
  s21_decimal dec_2 = {{0x2535, 0x0, 0x0, 0x80010000}};
  // 7028514213664824.3351811923656
  s21_decimal dec_check = {{0xefa21ec8, 0xe67bae4a, 0xe31a81c5, 0xd0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_427) {
  // 59522885392071127
  s21_decimal dec_1 = {{0xb7ccf9d7, 0xd377bf, 0x0, 0x0}};
  // -1
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -59522885392071127
  s21_decimal dec_check = {{0xb7ccf9d7, 0xd377bf, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_428) {
  // 40282983038828882975
  s21_decimal dec_1 = {{0x3a7b2c1f, 0x2f09e7a5, 0x2, 0x0}};
  // 2211
  s21_decimal dec_2 = {{0x8a3, 0x0, 0x0, 0x0}};
  // 18219350085404288.998190863863
  s21_decimal dec_check = {{0xa9b7d5f7, 0x3186e471, 0x3adeb173, 0xc0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_429) {
  // -58193432667539841
  s21_decimal dec_1 = {{0x6268c981, 0xcebe9e, 0x0, 0x80000000}};
  // -148.23359478976191479987
  s21_decimal dec_2 = {{0xb75940b3, 0x936ffc9a, 0x323, 0x80140000}};
  // 392579244604267.67410528431732
  s21_decimal dec_check = {{0x2c72ae74, 0x5d02f389, 0x7ed964dd, 0xe0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_430) {
  // 31117382702712120.9844273456
  s21_decimal dec_1 = {{0x87d19130, 0xf6d3f45c, 0x101659e, 0xa0000}};
  // -52632.3948332805702958043343
  s21_decimal dec_2 = {{0x9839d0cf, 0x69223f36, 0x1b35d6e, 0x80160000}};
  // -591221106341.06934831094133481
  s21_decimal dec_check = {{0xf5e372e9, 0x924443e3, 0xbf08a9e7, 0x80110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_431) {
  // -23017728122
  s21_decimal dec_1 = {{0x5bf6a87a, 0x5, 0x0, 0x80000000}};
  // -4856487.0
  s21_decimal dec_2 = {{0x2e50a86, 0x0, 0x0, 0x80010000}};
  // 4739.5840083583050876075648921
  s21_decimal dec_check = {{0x87e42799, 0x45129506, 0x9924eb87, 0x190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_433) {
  // -906146931343739305328937
  s21_decimal dec_1 = {{0xa25c0129, 0x52d5fced, 0xbfe2, 0x80000000}};
  // -8960015
  s21_decimal dec_2 = {{0x88b80f, 0x0, 0x0, 0x80000000}};
  // 101132300709735341.43959993371
  s21_decimal dec_check = {{0x458b0c1b, 0xb0943c50, 0x20ad77c4, 0xb0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_434) {
  // 394317229157743
  s21_decimal dec_1 = {{0x225f6d6f, 0x166a1, 0x0, 0x0}};
  // -2589587.5465691
  s21_decimal dec_2 = {{0x5a7551db, 0x178d, 0x0, 0x80070000}};
  // -152270283.22721396877438973070
  s21_decimal dec_check = {{0x8e1b748e, 0x664ef487, 0x313380ab, 0x80140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_435) {
  // -722573904779
  s21_decimal dec_1 = {{0x3cc2cb8b, 0xa8, 0x0, 0x80000000}};
  // -32
  s21_decimal dec_2 = {{0x20, 0x0, 0x0, 0x80000000}};
  // 22580434524.34375
  s21_decimal dec_check = {{0xb5dea7c7, 0x805ad, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_436) {
  // 522886177691379146.38209875
  s21_decimal dec_1 = {{0x514f9353, 0xa629fcb9, 0x2b408b, 0x80000}};
  // -0.011
  s21_decimal dec_2 = {{0xb, 0x0, 0x0, 0x80030000}};
  // -47535107062852649671.099886364
  s21_decimal dec_check = {{0x61db2b1c, 0x5802e95c, 0x99981e75, 0x80090000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_437) {
  // -6913012407068.4158
  s21_decimal dec_1 = {{0x488305fe, 0xf5997b, 0x0, 0x80040000}};
  // 1405143652.22717
  s21_decimal dec_2 = {{0xcd32f3d, 0x7fcc, 0x0, 0x50000}};
  // -4919.7905111774201642807019287
  s21_decimal dec_check = {{0xb5054717, 0x32314b35, 0x9ef78da4, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_438) {
  // 404548748299960145735904
  s21_decimal dec_1 = {{0x47cf0e0, 0xa1afd3af, 0x55aa, 0x0}};
  // -767329044.3918022164
  s21_decimal dec_2 = {{0x221614, 0x6a7d0101, 0x0, 0x800a0000}};
  // -527216780410823.91591014908488
  s21_decimal dec_check = {{0x26b04248, 0x760d692a, 0xaa5a5995, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_439) {
  // -3855838678281184132
  s21_decimal dec_1 = {{0x4a296384, 0x3582b0d9, 0x0, 0x80000000}};
  // 189.8280362311687125127
  s21_decimal dec_2 = {{0x87ecb887, 0xe7ee9c00, 0x66, 0x130000}};
  // -20312271858439405.643308739103
  s21_decimal dec_check = {{0xca402a1f, 0xda10260e, 0x41a1eadf, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_440) {
  // -906480271640901873010593.057
  s21_decimal dec_1 = {{0x589cd21, 0xfdcd6d07, 0x2edd2a9, 0x80030000}};
  // -2.92211776
  s21_decimal dec_2 = {{0x116acc40, 0x0, 0x0, 0x80080000}};
  // 310213463690423575883058.54484
  s21_decimal dec_check = {{0x4e74014, 0x56490942, 0x643c419c, 0x50000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_441) {
  // -893928249
  s21_decimal dec_1 = {{0x35484339, 0x0, 0x0, 0x80000000}};
  // 29
  s21_decimal dec_2 = {{0x1d, 0x0, 0x0, 0x0}};
  // -30825112.034482758620689655172
  s21_decimal dec_check = {{0xcbee584, 0xbea8d5c5, 0x6399ef5f, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_442) {
  // -73694.532
  s21_decimal dec_1 = {{0x4647d44, 0x0, 0x0, 0x80030000}};
  // 3985
  s21_decimal dec_2 = {{0xf91, 0x0, 0x0, 0x0}};
  // -18.492981681304893350062735257
  s21_decimal dec_check = {{0x11023f99, 0xbaf2fb03, 0x3bc10931, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_443) {
  // -5597369910518294115538
  s21_decimal dec_1 = {{0xc6edf4d2, 0x6f1ca57a, 0x12f, 0x80000000}};
  // 2958
  s21_decimal dec_2 = {{0xb8e, 0x0, 0x0, 0x0}};
  // -1892281917010917550.8918187965
  s21_decimal dec_check = {{0x8f85b7bd, 0xb06b35fe, 0x3d2496d2, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_444) {
  // -9804901.1772372
  s21_decimal dec_1 = {{0xd0846bd4, 0x592c, 0x0, 0x80070000}};
  // 47900.1
  s21_decimal dec_2 = {{0x74f19, 0x0, 0x0, 0x10000}};
  // -204.69479556905309174719885762
  s21_decimal dec_check = {{0xaa4b1c2, 0x4320b56b, 0x4223f4e6, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_445) {
  // 602158405201033633249
  s21_decimal dec_1 = {{0x8b571de1, 0xa4a06728, 0x20, 0x0}};
  // 520409574397
  s21_decimal dec_2 = {{0x2ad3ebfd, 0x79, 0x0, 0x0}};
  // 1157085562.6527552409630653131
  s21_decimal dec_check = {{0x6557bacb, 0x63ce2cff, 0x25632ffc, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_446) {
  // 5323446
  s21_decimal dec_1 = {{0x513ab6, 0x0, 0x0, 0x0}};
  // -5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // -1064689.2
  s21_decimal dec_check = {{0xa2756c, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_447) {
  // 453860773097328642456.329
  s21_decimal dec_1 = {{0xe7997b09, 0xd780da95, 0x601b, 0x30000}};
  // 85871425397.191
  s21_decimal dec_2 = {{0x7fcea1c7, 0x4e19, 0x0, 0x30000}};
  // 5285352735.1855882700820442821
  s21_decimal dec_check = {{0x8249eec5, 0xeb92cf98, 0xaac769c2, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_448) {
  // 7063294438
  s21_decimal dec_1 = {{0xa50151e6, 0x1, 0x0, 0x0}};
  // 9621886.74447203930946
  s21_decimal dec_2 = {{0x1909342, 0x290cdd84, 0x34, 0xe0000}};
  // 734.08621672438617608127989064
  s21_decimal dec_check = {{0x35534548, 0xd23b950f, 0xed32304a, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_449) {
  // 76780871364934916470
  s21_decimal dec_1 = {{0x33e85976, 0x298c73b4, 0x4, 0x0}};
  // -46.7500
  s21_decimal dec_2 = {{0x7222c, 0x0, 0x0, 0x80040000}};
  // -1642371579998607838.9304812834
  s21_decimal dec_check = {{0xd42fe522, 0x880e73e1, 0x35116119, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_451) {
  // 145850433715444910549.607
  s21_decimal dec_1 = {{0x16266a67, 0x915eeb7b, 0x1ee2, 0x30000}};
  // -9000999110108060
  s21_decimal dec_2 = {{0x6a94e39c, 0x1ffa5c, 0x0, 0x80000000}};
  // -16203.804925572748711153867537
  s21_decimal dec_check = {{0x3fb79b11, 0x24513cbb, 0x345b7929, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_452) {
  // -138398232797538
  s21_decimal dec_1 = {{0x5980e162, 0x7ddf, 0x0, 0x80000000}};
  // -62702
  s21_decimal dec_2 = {{0xf4ee, 0x0, 0x0, 0x80000000}};
  // 2207237931.7651430576377149054
  s21_decimal dec_check = {{0x7a7db67e, 0x67f58120, 0x4751d820, 0x130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_454) {
  // 8569
  s21_decimal dec_1 = {{0x2179, 0x0, 0x0, 0x0}};
  // 52.52831
  s21_decimal dec_2 = {{0x5026df, 0x0, 0x0, 0x50000}};
  // 163.13108112558732614850925149
  s21_decimal dec_check = {{0xd8dd525d, 0xc806d4c5, 0x34b5e302, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_455) {
  // 456923709326079.010
  s21_decimal dec_1 = {{0x57d5b422, 0x65751b1, 0x0, 0x30000}};
  // 23.5909581507564471
  s21_decimal dec_2 = {{0xb4de93b7, 0x3461e83, 0x0, 0x100000}};
  // 19368594798318.002723163546537
  s21_decimal dec_check = {{0xb8bd23a9, 0xea989909, 0x3e95537b, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_457) {
  // -780921654030313613
  s21_decimal dec_1 = {{0x59e3288d, 0xad6641b, 0x0, 0x80000000}};
  // -30076786070
  s21_decimal dec_2 = {{0xb75596, 0x7, 0x0, 0x80000000}};
  // 25964265.337819507687843856117
  s21_decimal dec_check = {{0x2ae67ef5, 0x500d12fe, 0x53e5230c, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_458) {
  // 60543082161983758292.13296240
  s21_decimal dec_1 = {{0x7b283670, 0xb823af6, 0x139001a2, 0x80000}};
  // 0.506670
  s21_decimal dec_2 = {{0x7bb2e, 0x0, 0x0, 0x60000}};
  // 119492139187210133404.64792153
  s21_decimal dec_check = {{0x6d70c259, 0x82317b30, 0x269c2878, 0x80000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_459) {
  // 4515106751656932
  s21_decimal dec_1 = {{0x360e33e4, 0x100a77, 0x0, 0x0}};
  // -103.968964329889
  s21_decimal dec_2 = {{0x292fc1a1, 0x5e8f, 0x0, 0x800c0000}};
  // -43427447611488.123849092064739
  s21_decimal dec_check = {{0xb79365e3, 0x4b35ffec, 0x8c5257bc, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_460) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // 8360212.52
  s21_decimal dec_2 = {{0x31d4ac04, 0x0, 0x0, 0x20000}};
  // 0
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_461) {
  // -567
  s21_decimal dec_1 = {{0x237, 0x0, 0x0, 0x80000000}};
  // -0.6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x80010000}};
  // 945
  s21_decimal dec_check = {{0x3b1, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_462) {
  // 387.97978
  s21_decimal dec_1 = {{0x250029a, 0x0, 0x0, 0x50000}};
  // 51.35872872377338141
  s21_decimal dec_2 = {{0x999dc91d, 0x4746492a, 0x0, 0x110000}};
  // 7.5543104286459586156044987145
  s21_decimal dec_check = {{0x7077ab09, 0x2f15ba24, 0xf417ca91, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_463) {
  // -1466113987775353376608925
  s21_decimal dec_1 = {{0x134a129d, 0x32d30cdd, 0x13676, 0x80000000}};
  // 5401431787.4543275639648
  s21_decimal dec_2 = {{0xa04d8360, 0x1f3df6c6, 0xb70, 0xd0000}};
  // -271430621632699.87871034260628
  s21_decimal dec_check = {{0xb1153c94, 0x442d9a02, 0x57b436fc, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_464) {
  // 132525934205.913029819824
  s21_decimal dec_1 = {{0x1bca3db0, 0x3ecb3fc9, 0x1c10, 0xc0000}};
  // 0.0271849550496
  s21_decimal dec_2 = {{0x4b7ef2a0, 0x3f, 0x0, 0xd0000}};
  // 4874973453666.3513519876333414
  s21_decimal dec_check = {{0x3d05df66, 0xa319aa2e, 0x9d84d5d4, 0x100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_465) {
  // 0.48
  s21_decimal dec_1 = {{0x30, 0x0, 0x0, 0x20000}};
  // -2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -0.24
  s21_decimal dec_check = {{0x18, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_468) {
  // 998078422.186283323937
  s21_decimal dec_1 = {{0xabc55221, 0x1b1edcee, 0x36, 0xc0000}};
  // 3443784.74
  s21_decimal dec_2 = {{0x1486cc6a, 0x0, 0x0, 0x20000}};
  // 289.82021163909429598581704616
  s21_decimal dec_check = {{0x997c47a8, 0x7252a536, 0x5da55db3, 0x1a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_469) {
  // 41989193652023918854292893999
  s21_decimal dec_1 = {{0x8bdff12f, 0xec048995, 0x87aca59c, 0x0}};
  // 350782282934703617
  s21_decimal dec_2 = {{0xb7d2d601, 0x4de3aa0, 0x0, 0x0}};
  // 119701580424.00333854764243719
  s21_decimal dec_check = {{0xf3f11b07, 0xba6f7e1f, 0x26ad7b8f, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_472) {
  // 70062683822444982
  s21_decimal dec_1 = {{0xc53f51b6, 0xf8e9a3, 0x0, 0x0}};
  // 692653
  s21_decimal dec_2 = {{0xa91ad, 0x0, 0x0, 0x0}};
  // 101151202438.22661852327211461
  s21_decimal dec_check = {{0x382671c5, 0x2a4ca101, 0x20af0807, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_473) {
  // 46900357808234914046.400198
  s21_decimal dec_1 = {{0x49c1d6c6, 0x7dc5f43d, 0x26cb89, 0x60000}};
  // 4327116588
  s21_decimal dec_2 = {{0x1ea8f2c, 0x1, 0x0, 0x0}};
  // 10838709069.753152222299261515
  s21_decimal dec_check = {{0x75058a4b, 0x4ab13a0, 0x230591ec, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_474) {
  // 6799449557511503267092438413.0
  s21_decimal dec_1 = {{0x1aff2782, 0xfad34f55, 0xdbb3ba7e, 0x10000}};
  // 551143371012595269106709
  s21_decimal dec_2 = {{0x771fc15, 0x8ac12d3a, 0x74b5, 0x0}};
  // 12336.988731297133888697927498
  s21_decimal dec_check = {{0xea9e074a, 0x3856f716, 0x27dceafb, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_475) {
  // 5020719025364785302
  s21_decimal dec_1 = {{0x47e9d896, 0x45ad2d5a, 0x0, 0x0}};
  // 33.372
  s21_decimal dec_2 = {{0x825c, 0x0, 0x0, 0x30000}};
  // 150447052180414278.49694354549
  s21_decimal dec_check = {{0xce9f1c75, 0x17190db8, 0x309cb040, 0xb0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_476) {
  // 739469043867
  s21_decimal dec_1 = {{0x2bca289b, 0xac, 0x0, 0x0}};
  // -2846221746.44941
  s21_decimal dec_2 = {{0xc39d6acd, 0x102dc, 0x0, 0x80050000}};
  // -259.80724965982324552529043717
  s21_decimal dec_check = {{0x6c176105, 0x8b171568, 0x53f2c082, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_477) {
  // -4988725465362907.26497748565
  s21_decimal dec_1 = {{0x8f840655, 0xeff984ff, 0x19ca85e, 0x800b0000}};
  // 0.986978248989805765410358077
  s21_decimal dec_2 = {{0x360b033d, 0x1668a64e, 0x33068c6, 0x1b0000}};
  // -5054544485118065.1268866615658
  s21_decimal dec_check = {{0xd4f0a96a, 0xd845d98b, 0xa3523647, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_478) {
  // 392928827733
  s21_decimal dec_1 = {{0x7c621955, 0x5b, 0x0, 0x0}};
  // -7330232
  s21_decimal dec_2 = {{0x6fd9b8, 0x0, 0x0, 0x80000000}};
  // -53603.873347119163486230722302
  s21_decimal dec_check = {{0x8a26b6fe, 0xd447d82d, 0xad3415b4, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_479) {
  // -7443728584127
  s21_decimal dec_1 = {{0x20cc4dbf, 0x6c5, 0x0, 0x80000000}};
  // 3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x0}};
  // -2481242861375.6666666666666667
  s21_decimal dec_check = {{0x79ffaaab, 0x624242c3, 0x502c5c22, 0x80100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_480) {
  // -48115948047842966288944958
  s21_decimal dec_1 = {{0xb2d74f3e, 0xc52e06a5, 0x27ccf2, 0x80000000}};
  // 1
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  // -48115948047842966288944958
  s21_decimal dec_check = {{0xb2d74f3e, 0xc52e06a5, 0x27ccf2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_481) {
  // 49
  s21_decimal dec_1 = {{0x31, 0x0, 0x0, 0x0}};
  // -45
  s21_decimal dec_2 = {{0x2d, 0x0, 0x0, 0x80000000}};
  // -1.0888888888888888888888888889
  s21_decimal dec_check = {{0x88e38e39, 0x76de57ec, 0x232f13e9, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_482) {
  // 757896649671132152848350181
  s21_decimal dec_1 = {{0xc1627be5, 0xb463b3ce, 0x272eadb, 0x0}};
  // 33243589323477.441069027939
  s21_decimal dec_2 = {{0x3b99263, 0x9699f1d1, 0x1b7f9a, 0xc0000}};
  // 22798279761442.212356831104901
  s21_decimal dec_check = {{0xb2d8cf85, 0x507c5e75, 0x49aa4b86, 0xf0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_483) {
  // 4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x0}};
  // -0.58944160649239658029
  s21_decimal dec_2 = {{0x997cfe2d, 0x3203b9cf, 0x3, 0x80140000}};
  // -6.7860835678073184023754069458
  s21_decimal dec_check = {{0x65d055d2, 0x7143aae7, 0xdb452ae9, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_484) {
  // 7381728491245640460359258.5
  s21_decimal dec_1 = {{0x15fd5f89, 0x89065d0, 0x3d0f6b, 0x10000}};
  // -5836982
  s21_decimal dec_2 = {{0x5910b6, 0x0, 0x0, 0x80000000}};
  // -1264648150576040916.4118132453
  s21_decimal dec_check = {{0xc41a86e5, 0x24648fc6, 0x28dceca0, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_485) {
  // -20444142859487043030465
  s21_decimal dec_1 = {{0x7ee8dc1, 0x4779fcfe, 0x454, 0x80000000}};
  // -983489976408825
  s21_decimal dec_2 = {{0x9aaf1af9, 0x37e7a, 0x0, 0x80000000}};
  // 20787342.372454091779219573793
  s21_decimal dec_check = {{0xf5decc21, 0x54ee8bf, 0x432ae2f8, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_486) {
  // 6044419493902170
  s21_decimal dec_1 = {{0x14ceb75a, 0x15795e, 0x0, 0x0}};
  // 162947363883
  s21_decimal dec_2 = {{0xf06b742b, 0x25, 0x0, 0x0}};
  // 37094.306712701433362162690176
  s21_decimal dec_check = {{0x80b0a880, 0x3cdba029, 0x77dbb0fc, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_487) {
  // 28449645254298093
  s21_decimal dec_1 = {{0x375e49ed, 0x6512cd, 0x0, 0x0}};
  // -99.2
  s21_decimal dec_2 = {{0x3e0, 0x0, 0x0, 0x80010000}};
  // -286790778773166.26008064516129
  s21_decimal dec_check = {{0x1009e021, 0xf92f9c95, 0x5caac6f6, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_489) {
  // 114753.30
  s21_decimal dec_1 = {{0xaf1982, 0x0, 0x0, 0x20000}};
  // -87532.0344
  s21_decimal dec_2 = {{0x342c5418, 0x0, 0x0, 0x80040000}};
  // -1.3109863238823568346081991669
  s21_decimal dec_check = {{0x8dd11bf5, 0x39dc5460, 0x2a5c3986, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_490) {
  // -546437712437
  s21_decimal dec_1 = {{0x3a39ca35, 0x7f, 0x0, 0x80000000}};
  // -994658.96004
  s21_decimal dec_2 = {{0x28a12044, 0x17, 0x0, 0x80050000}};
  // 549371.92986732369334440726525
  s21_decimal dec_check = {{0x6fe28ffd, 0x52d308fc, 0xb182fb1f, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_491) {
  // -7313603.0619400237
  s21_decimal dec_1 = {{0x1559f82d, 0x103d4d5, 0x0, 0x800a0000}};
  // -9.640363
  s21_decimal dec_2 = {{0x9319ab, 0x0, 0x0, 0x80060000}};
  // 758643.94960438976208675959609
  s21_decimal dec_check = {{0xe83a7339, 0x8533569c, 0xf5218e83, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_492) {
  // 6167294626772.7801619
  s21_decimal dec_1 = {{0x8bab2d13, 0x57e251df, 0x3, 0x70000}};
  // 215.0
  s21_decimal dec_2 = {{0x866, 0x0, 0x0, 0x10000}};
  // 28685091287.315256566976744186
  s21_decimal dec_check = {{0x60be0afa, 0x9525fb6d, 0x5cafc05a, 0x120000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_493) {
  // 23044482953792615
  s21_decimal dec_1 = {{0xcc7e4c67, 0x51ded5, 0x0, 0x0}};
  // -80482607.2580
  s21_decimal dec_2 = {{0x635f4604, 0xbb, 0x0, 0x80040000}};
  // -286328732.86422993133197931469
  s21_decimal dec_check = {{0x800933cd, 0x15046bcb, 0x5c848ec3, 0x80140000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_494) {
  // -8619045
  s21_decimal dec_1 = {{0x838425, 0x0, 0x0, 0x80000000}};
  // 2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x0}};
  // -4309522.5
  s21_decimal dec_check = {{0x29194b9, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_495) {
  // 9938064343062607072275
  s21_decimal dec_1 = {{0xd67c8c13, 0xbe5921e4, 0x21a, 0x0}};
  // -890914016673669
  s21_decimal dec_2 = {{0x157d3f85, 0x32a48, 0x0, 0x80000000}};
  // -11154908.506398322297443964128
  s21_decimal dec_check = {{0x326bd4e0, 0xd3616280, 0x240b1fc1, 0x80150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_496) {
  // 66774863857006522820310.0037
  s21_decimal dec_1 = {{0x23910785, 0x3b084852, 0x2285946, 0x40000}};
  // 86415359161
  s21_decimal dec_2 = {{0x1ec1bcb9, 0x14, 0x0, 0x0}};
  // 772719855652.03317688389933347
  s21_decimal dec_check = {{0x7d5d1923, 0x1a64af11, 0xf9ade36b, 0x110000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_497) {
  // -277352.04078544189505178742519
  s21_decimal dec_1 = {{0xe1a4aef7, 0xd0776290, 0x599e05e9, 0x80170000}};
  // 89073.7
  s21_decimal dec_2 = {{0xd9771, 0x0, 0x0, 0x10000}};
  // -3.1137366112044508654270275647
  s21_decimal dec_check = {{0x64b5e03f, 0x352fb26b, 0x649c39bf, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_498) {
  // 39360712647855737283643034
  s21_decimal dec_1 = {{0x749d869a, 0x82175f7a, 0x208ef4, 0x0}};
  // 0.051303
  s21_decimal dec_2 = {{0xc867, 0x0, 0x0, 0x60000}};
  // 767220487064221142694248562.46
  s21_decimal dec_check = {{0x5d792cb6, 0x40881f83, 0xf7e6fdc2, 0x20000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_499) {
  // 826232319
  s21_decimal dec_1 = {{0x313f4dff, 0x0, 0x0, 0x0}};
  // 22.283
  s21_decimal dec_2 = {{0x570b, 0x0, 0x0, 0x30000}};
  // 37079043.171924785711080195665
  s21_decimal dec_check = {{0xc5f6c651, 0x8c38013, 0x77cf10ce, 0x150000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_500) {
  // -39957782197975031422613
  s21_decimal dec_1 = {{0xa8fb1e95, 0x1d9f63a7, 0x876, 0x80000000}};
  // -9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x80000000}};
  // 4439753577552781269179.2222222
  s21_decimal dec_check = {{0x4f53d80e, 0xaa04437, 0x8f74c7e5, 0x70000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(fail_s21_div_1) {
  // -909748
  s21_decimal dec_1 = {{0xde1b4, 0x0, 0x0, 0x80000000}};
  // -730830993352357
  s21_decimal dec_2 = {{0xd9bfe6a5, 0x298af, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_2) {
  // 138
  s21_decimal dec_1 = {{0x8a, 0x0, 0x0, 0x0}};
  // 63909
  s21_decimal dec_2 = {{0xf9a5, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_3) {
  // -75192205.82555812786
  s21_decimal dec_1 = {{0x30b83b2, 0x6859a348, 0x0, 0x800b0000}};
  // 38554513060656962199884759942
  s21_decimal dec_2 = {{0xf0d8386, 0xf9688e8b, 0x7c938bb4, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_4) {
  // 1.8087189962529433
  s21_decimal dec_1 = {{0x14b39a99, 0x404234, 0x0, 0x100000}};
  // -7873.5731194
  s21_decimal dec_2 = {{0x5503e9fa, 0x12, 0x0, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_5) {
  // -983
  s21_decimal dec_1 = {{0x3d7, 0x0, 0x0, 0x80000000}};
  // 19311255876637007
  s21_decimal dec_2 = {{0x22b1914f, 0x449b7c, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_6) {
  // -3.406540
  s21_decimal dec_1 = {{0x33facc, 0x0, 0x0, 0x80060000}};
  // -5449460042345
  s21_decimal dec_2 = {{0xcd214a69, 0x4f4, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_7) {
  // 1.99097
  s21_decimal dec_1 = {{0x309b9, 0x0, 0x0, 0x50000}};
  // 35011762.6998503921450302
  s21_decimal dec_2 = {{0x1c647d3e, 0xea22a073, 0x4a23, 0x100000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_8) {
  // -7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x80000000}};
  // 28760498407920151.892612
  s21_decimal dec_2 = {{0x24451284, 0x1c181a5a, 0x617, 0x60000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_9) {
  // 570.6
  s21_decimal dec_1 = {{0x164a, 0x0, 0x0, 0x10000}};
  // -2443400004.00
  s21_decimal dec_2 = {{0xe3cc8690, 0x38, 0x0, 0x80020000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_10) {
  // 1.6865824744992278493166577600
  s21_decimal dec_1 = {{0xce1427c0, 0x76ca09c6, 0x367f154f, 0x1c0000}};
  // -7.249850947887682031404
  s21_decimal dec_2 = {{0x4e4c0f2c, 0x3e4a1bf, 0x189, 0x80150000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_11) {
  // 4522747592
  s21_decimal dec_1 = {{0xd93a6c8, 0x1, 0x0, 0x0}};
  // -72061295328738.5220728
  s21_decimal dec_2 = {{0x37c10678, 0x10837f0b, 0x27, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_12) {
  // -6942969490979890914
  s21_decimal dec_1 = {{0x743b26e2, 0x605a61f7, 0x0, 0x80000000}};
  // 15113571793482841482
  s21_decimal dec_2 = {{0x95e87d8a, 0xd1be3178, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_13) {
  // 7167021049.91032
  s21_decimal dec_1 = {{0x3660b538, 0x28bd6, 0x0, 0x50000}};
  // 30851572367609304711745635
  s21_decimal dec_2 = {{0xf6c8d063, 0x16dae8bc, 0x198513, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_14) {
  // -3019374.06
  s21_decimal dec_1 = {{0x11ff32fe, 0x0, 0x0, 0x80020000}};
  // 7628682233068520039
  s21_decimal dec_2 = {{0x8e620267, 0x69de8612, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_15) {
  // -31754113176542
  s21_decimal dec_1 = {{0x54a2d3de, 0x1ce1, 0x0, 0x80000000}};
  // 78230603460330827607511677413
  s21_decimal dec_2 = {{0x4c3039e5, 0x53bf21e6, 0xfcc6d6a7, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_16) {
  // 34
  s21_decimal dec_1 = {{0x22, 0x0, 0x0, 0x0}};
  // 97930202464181.744
  s21_decimal dec_2 = {{0x12a8ddf0, 0x15beb00, 0x0, 0x30000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_17) {
  // -3.64
  s21_decimal dec_1 = {{0x16c, 0x0, 0x0, 0x80020000}};
  // -36749
  s21_decimal dec_2 = {{0x8f8d, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_18) {
  // -227483.99053320632446622
  s21_decimal dec_1 = {{0xb8acae9e, 0x31747ccf, 0x4d1, 0x80110000}};
  // 79228162514264337591544195856
  s21_decimal dec_2 = {{0x88ce2b10, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_19) {
  // -2572
  s21_decimal dec_1 = {{0xa0c, 0x0, 0x0, 0x80000000}};
  // 583579487162876410
  s21_decimal dec_2 = {{0x9e8c41fa, 0x8194a73, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_20) {
  // -8719931501
  s21_decimal dec_1 = {{0x7bf986d, 0x2, 0x0, 0x80000000}};
  // -87911690797745169
  s21_decimal dec_2 = {{0x8d9a8411, 0x1385337, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_21) {
  // -7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x80000000}};
  // -61208080
  s21_decimal dec_2 = {{0x3a5f610, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_22) {
  // -80945915.5717959215842613427
  s21_decimal dec_1 = {{0xa2f058b3, 0xc2257f98, 0x29d91a4, 0x80130000}};
  // -1620518937747798324841816012
  s21_decimal dec_2 = {{0x44981fcc, 0xa49bdc4c, 0x53c763b, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_23) {
  // -3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x80000000}};
  // 995701380
  s21_decimal dec_2 = {{0x3b593284, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_24) {
  // -34
  s21_decimal dec_1 = {{0x22, 0x0, 0x0, 0x80000000}};
  // -6931636.1432899120735058
  s21_decimal dec_2 = {{0x2acb2352, 0xa5c16d66, 0xead, 0x80100000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_25) {
  // 83.9896
  s21_decimal dec_1 = {{0xcd0d8, 0x0, 0x0, 0x40000}};
  // 3240199655.35649045413
  s21_decimal dec_2 = {{0x5eac9ba5, 0x90ae29ec, 0x11, 0xb0000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_26) {
  // -14728
  s21_decimal dec_1 = {{0x3988, 0x0, 0x0, 0x80000000}};
  // 732513247952750
  s21_decimal dec_2 = {{0x87efff6e, 0x29a37, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_27) {
  // -917760704.17
  s21_decimal dec_1 = {{0x5e47b311, 0x15, 0x0, 0x80020000}};
  // -2805494806835441
  s21_decimal dec_2 = {{0x296170f1, 0x9f795, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_28) {
  // -2868
  s21_decimal dec_1 = {{0xb34, 0x0, 0x0, 0x80000000}};
  // 41743.43
  s21_decimal dec_2 = {{0x3fb207, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_29) {
  // 210577228820441
  s21_decimal dec_1 = {{0xd4ebefd9, 0xbf84, 0x0, 0x0}};
  // -2746704860665226314081
  s21_decimal dec_2 = {{0xe59dc161, 0xe62fee1b, 0x94, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_30) {
  // 0.2118772340158970218242
  s21_decimal dec_1 = {{0x3a884702, 0xdbdf79a3, 0x72, 0x160000}};
  // 12083.74
  s21_decimal dec_2 = {{0x127036, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_31) {
  // 28982753905480
  s21_decimal dec_1 = {{0x12c04b48, 0x1a5c, 0x0, 0x0}};
  // -326070947936020603
  s21_decimal dec_2 = {{0xaf4d287b, 0x4866fcc, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_32) {
  // 824597164982451942.1733862
  s21_decimal dec_1 = {{0x1de4abe6, 0x4d3552c, 0x6d227, 0x70000}};
  // -45290160620425326690467
  s21_decimal dec_2 = {{0xc4ad00a3, 0x2f3d26b8, 0x997, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_33) {
  // -48.62063392
  s21_decimal dec_1 = {{0x21cd3320, 0x1, 0x0, 0x80080000}};
  // -679.17827091810369360178
  s21_decimal dec_2 = {{0x6ec75132, 0xd53157ee, 0xe61, 0x80140000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_34) {
  // -3.1657027396700250558715
  s21_decimal dec_1 = {{0xe777d0fb, 0x2182432d, 0x6b4, 0x80160000}};
  // 53293.18
  s21_decimal dec_2 = {{0x5151a6, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_35) {
  // 74883749774703.7
  s21_decimal dec_1 = {{0x510c365d, 0x2a910, 0x0, 0x10000}};
  // -34717695158934175808840300868
  s21_decimal dec_2 = {{0x4cc87944, 0xc01360a6, 0x702dcde9, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_36) {
  // -0.86
  s21_decimal dec_1 = {{0x56, 0x0, 0x0, 0x80020000}};
  // -39760001648004694134472
  s21_decimal dec_2 = {{0xd9a1cec8, 0x64ddb957, 0x86b, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_37) {
  // -0.999113030468039820
  s21_decimal dec_1 = {{0xf782f48c, 0xddd9001, 0x0, 0x80120000}};
  // 335515753279863
  s21_decimal dec_2 = {{0x594a7177, 0x13126, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_38) {
  // -5088553
  s21_decimal dec_1 = {{0x4da529, 0x0, 0x0, 0x80000000}};
  // 88928528185438082982047165
  s21_decimal dec_2 = {{0xd2396dbd, 0x2c380073, 0x498f59, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_39) {
  // -14
  s21_decimal dec_1 = {{0xe, 0x0, 0x0, 0x80000000}};
  // 8633738412602
  s21_decimal dec_2 = {{0x32e9423a, 0x7da, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_40) {
  // 3294.6
  s21_decimal dec_1 = {{0x80b2, 0x0, 0x0, 0x10000}};
  // 811414
  s21_decimal dec_2 = {{0xc6196, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_41) {
  // -0.9586
  s21_decimal dec_1 = {{0x2572, 0x0, 0x0, 0x80040000}};
  // 442291719913
  s21_decimal dec_2 = {{0xfaa40ee9, 0x66, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_42) {
  // 410875614694505798
  s21_decimal dec_1 = {{0xd4bc7d46, 0x5b3b931, 0x0, 0x0}};
  // 337891719190754645006595
  s21_decimal dec_2 = {{0xfa085903, 0x2594b8ef, 0x478d, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_43) {
  // 628.79367
  s21_decimal dec_1 = {{0x3bf7687, 0x0, 0x0, 0x50000}};
  // -78702331617
  s21_decimal dec_2 = {{0x530646e1, 0x12, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_44) {
  // 1585748780733483334348
  s21_decimal dec_1 = {{0x84123acc, 0xf6af626b, 0x55, 0x0}};
  // -65567449059970726998897760993
  s21_decimal dec_2 = {{0x80da9ae1, 0xc1f50c49, 0xd3dc1f67, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_45) {
  // -32940
  s21_decimal dec_1 = {{0x80ac, 0x0, 0x0, 0x80000000}};
  // 759003
  s21_decimal dec_2 = {{0xb94db, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_46) {
  // -714062122081749987670383
  s21_decimal dec_1 = {{0xe20ab96f, 0x629ca215, 0x9735, 0x80000000}};
  // -89675924695182681739379859
  s21_decimal dec_2 = {{0x64e44493, 0x9e63a8be, 0x4a2d9d, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_47) {
  // 6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x0}};
  // 925530101333021
  s21_decimal dec_2 = {{0xc4eb3c1d, 0x349c3, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_48) {
  // 122209516013577
  s21_decimal dec_1 = {{0x1eca4809, 0x6f26, 0x0, 0x0}};
  // 3958073249454808.055164447
  s21_decimal dec_2 = {{0x3ee82e1f, 0x94af084e, 0x34627, 0x90000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_49) {
  // 3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x0}};
  // 6726212723.1548083
  s21_decimal dec_2 = {{0x60793ab3, 0xeef68c, 0x0, 0x70000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_50) {
  // -61651.836
  s21_decimal dec_1 = {{0x3acbb7c, 0x0, 0x0, 0x80030000}};
  // -5113595384715.205
  s21_decimal dec_2 = {{0xb46e57c5, 0x122ac9, 0x0, 0x80030000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_51) {
  // 0.03
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x20000}};
  // -5711022341218925059
  s21_decimal dec_2 = {{0xa0ac7a03, 0x4f41a08f, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_52) {
  // -169156662618
  s21_decimal dec_1 = {{0x6285d55a, 0x27, 0x0, 0x80000000}};
  // -3260031074069771.9458979
  s21_decimal dec_2 = {{0xcf334ca3, 0x4431e6d0, 0x6e7, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_53) {
  // 129
  s21_decimal dec_1 = {{0x81, 0x0, 0x0, 0x0}};
  // -477
  s21_decimal dec_2 = {{0x1dd, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_54) {
  // -17.28361112187556711790187
  s21_decimal dec_1 = {{0xce0a766b, 0xa4c52cf2, 0x16dfe, 0x80170000}};
  // -70.0326956
  s21_decimal dec_2 = {{0x29be242c, 0x0, 0x0, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_55) {
  // 21.6219318
  s21_decimal dec_1 = {{0xce33eb6, 0x0, 0x0, 0x70000}};
  // 1712450519084578.905
  s21_decimal dec_2 = {{0x95783859, 0x17c3d8ac, 0x0, 0x30000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_56) {
  // -83.2622102890104
  s21_decimal dec_1 = {{0xf0acc678, 0x2f543, 0x0, 0x800d0000}};
  // 900558760426948988286305
  s21_decimal dec_2 = {{0x828cb561, 0x6362bb81, 0xbeb3, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_57) {
  // -457175264.5867282257644820011
  s21_decimal dec_1 = {{0xb6df162b, 0x8929137a, 0xec5aa47, 0x80130000}};
  // -9654858145021
  s21_decimal dec_2 = {{0xf263dcfd, 0x8c7, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_58) {
  // 8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x0}};
  // 106532
  s21_decimal dec_2 = {{0x1a024, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_59) {
  // 943063.5189468257141496170
  s21_decimal dec_1 = {{0x11ed996a, 0xc20d66b7, 0x7cd03, 0x130000}};
  // 58972865720
  s21_decimal dec_2 = {{0xbb0e84b8, 0xd, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_60) {
  // 27276190.286718500335
  s21_decimal dec_1 = {{0xe1d0fdef, 0x7a887e8c, 0x1, 0xc0000}};
  // 904106155416328979.77436346
  s21_decimal dec_2 = {{0x8a1848ba, 0x4a0f8848, 0x4ac931, 0x80000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_61) {
  // 8.5201880
  s21_decimal dec_1 = {{0x51413d8, 0x0, 0x0, 0x70000}};
  // 300250481979829636082
  s21_decimal dec_2 = {{0xbf91cbf2, 0x46cffe90, 0x10, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_62) {
  // 84274104382463065374
  s21_decimal dec_1 = {{0xb8e6bd1e, 0x9189c36e, 0x4, 0x0}};
  // 63418936434937452192473756389
  s21_decimal dec_2 = {{0x18d732e5, 0xf955c2d3, 0xcceaea28, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_63) {
  // 98241905.84381362911797244270
  s21_decimal dec_1 = {{0xaf0ef16e, 0xb992c13f, 0x1fbe6146, 0x140000}};
  // -116213376943117408
  s21_decimal dec_2 = {{0x5ad7d460, 0x19cdf73, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_64) {
  // -67.58790315309862688895
  s21_decimal dec_1 = {{0x22c3187f, 0x650ece2b, 0x16e, 0x80140000}};
  // -6244674242
  s21_decimal dec_2 = {{0x74362ac2, 0x1, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_65) {
  // 108576865
  s21_decimal dec_1 = {{0x678c061, 0x0, 0x0, 0x0}};
  // -44233510584674807549831390
  s21_decimal dec_2 = {{0x89f8a8de, 0x69e38a7a, 0x2496cf, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_66) {
  // -4907934.1557
  s21_decimal dec_1 = {{0x6d5b51f5, 0xb, 0x0, 0x80040000}};
  // 679406520.10708977512564
  s21_decimal dec_2 = {{0xf16af074, 0x11f3bebc, 0xe63, 0xe0000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_67) {
  // 8960.853530372278456
  s21_decimal dec_1 = {{0x2a2508b8, 0x7c5b58cf, 0x0, 0xf0000}};
  // 75280956081
  s21_decimal dec_2 = {{0x87183ab1, 0x11, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_68) {
  // -60.719
  s21_decimal dec_1 = {{0xed2f, 0x0, 0x0, 0x80030000}};
  // -509409573919
  s21_decimal dec_2 = {{0x9b2d3c1f, 0x76, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_69) {
  // 551031205815566
  s21_decimal dec_1 = {{0xf348650e, 0x1f528, 0x0, 0x0}};
  // -54287619609722980543963
  s21_decimal dec_2 = {{0x3c7e2ddb, 0xf010c6e8, 0xb7e, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_70) {
  // -2923.1613281
  s21_decimal dec_1 = {{0xce570561, 0x6, 0x0, 0x80070000}};
  // -3130125130515973612766861
  s21_decimal dec_2 = {{0xd0c8068d, 0x6c5f8a92, 0x296d4, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_71) {
  // 21
  s21_decimal dec_1 = {{0x15, 0x0, 0x0, 0x0}};
  // -5561.56836615
  s21_decimal dec_2 = {{0x7d87db07, 0x81, 0x0, 0x80080000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_72) {
  // -1.719
  s21_decimal dec_1 = {{0x6b7, 0x0, 0x0, 0x80030000}};
  // 3915122892746
  s21_decimal dec_2 = {{0x8f825fca, 0x38f, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_73) {
  // 897.008525
  s21_decimal dec_1 = {{0x3577438d, 0x0, 0x0, 0x60000}};
  // 7055676055
  s21_decimal dec_2 = {{0xa48d1297, 0x1, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_74) {
  // -2.71220870943
  s21_decimal dec_1 = {{0x26060f1f, 0x3f, 0x0, 0x800b0000}};
  // 31.176
  s21_decimal dec_2 = {{0x79c8, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_75) {
  // 459068
  s21_decimal dec_1 = {{0x7013c, 0x0, 0x0, 0x0}};
  // -882856116866239119566
  s21_decimal dec_2 = {{0xb8ef40ce, 0xdc1700b7, 0x2f, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_76) {
  // -0.700762661136412
  s21_decimal dec_1 = {{0x57d281c, 0x27d57, 0x0, 0x800f0000}};
  // -24888332009.64845095824949
  s21_decimal dec_2 = {{0x8bab2e35, 0xeb0d5215, 0x20f07, 0x800e0000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_77) {
  // 8031878364.72939476366436
  s21_decimal dec_1 = {{0x7ba33464, 0xe65d4899, 0xaa14, 0xe0000}};
  // 72535816260339745280
  s21_decimal dec_2 = {{0xda8dc200, 0xeea2fc93, 0x3, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_78) {
  // -18615
  s21_decimal dec_1 = {{0x48b7, 0x0, 0x0, 0x80000000}};
  // 4064737567
  s21_decimal dec_2 = {{0xf246f91f, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_79) {
  // 0.2785704180962402995270446
  s21_decimal dec_1 = {{0x1dbf32e, 0x5384cc00, 0x24de5, 0x190000}};
  // -5185353488
  s21_decimal dec_2 = {{0x35123710, 0x1, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_80) {
  // 336220170.58246034068
  s21_decimal dec_1 = {{0x9ce10294, 0xd2996660, 0x1, 0xb0000}};
  // -6184442008398540
  s21_decimal dec_2 = {{0x9d0b6acc, 0x15f8b7, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_81) {
  // 607766.816600427965254304
  s21_decimal dec_1 = {{0xfae50aa0, 0x1aeadb7c, 0x80b3, 0x120000}};
  // 2139497891312846837719093821
  s21_decimal dec_2 = {{0xa005d23d, 0x16e7fa77, 0x6e9c04d, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_82) {
  // -97284589616298938235.81324686
  s21_decimal dec_1 = {{0x96b058e, 0xe87d766, 0x1f6f3151, 0x80080000}};
  // 319112657693840483653362529
  s21_decimal dec_2 = {{0x395a361, 0xd64349fc, 0x107f6bb, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_83) {
  // -3.85040608331779
  s21_decimal dec_1 = {{0x40af0803, 0x15e31, 0x0, 0x800e0000}};
  // -69.7248372692250505440001
  s21_decimal dec_2 = {{0xdc6aeb01, 0xe8f72f65, 0x93a5, 0x80160000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_84) {
  // 536709572
  s21_decimal dec_1 = {{0x1ffd89c4, 0x0, 0x0, 0x0}};
  // 5629711136077193061297.4
  s21_decimal dec_2 = {{0x1ada64ee, 0xdf5d9bbe, 0xbeb, 0x10000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_85) {
  // 729
  s21_decimal dec_1 = {{0x2d9, 0x0, 0x0, 0x0}};
  // -1396442750
  s21_decimal dec_2 = {{0x533c067e, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_86) {
  // -2.49
  s21_decimal dec_1 = {{0xf9, 0x0, 0x0, 0x80020000}};
  // 97092963329965148032964
  s21_decimal dec_2 = {{0x58b34fc4, 0x6b8af009, 0x148f, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_87) {
  // 6921.67
  s21_decimal dec_1 = {{0xa8fc7, 0x0, 0x0, 0x20000}};
  // -53747.534223226
  s21_decimal dec_2 = {{0x12af577a, 0x30e2, 0x0, 0x80090000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_88) {
  // 4211312462084067
  s21_decimal dec_1 = {{0x975737e3, 0xef62a, 0x0, 0x0}};
  // -99990781336124014722
  s21_decimal dec_2 = {{0xf16e4082, 0x6ba69dd9, 0x5, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_89) {
  // -19008226.2007308945479497774
  s21_decimal dec_1 = {{0x9894f82e, 0x122ab50e, 0x9d3b7c, 0x80130000}};
  // 9279673133411996260788389146
  s21_decimal dec_2 = {{0x6da8c51a, 0x8f5e4e0d, 0x1dfbf738, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_90) {
  // 66
  s21_decimal dec_1 = {{0x42, 0x0, 0x0, 0x0}};
  // 93273692308347442070
  s21_decimal dec_2 = {{0x20225396, 0xe6eb8f8, 0x5, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_91) {
  // -66736
  s21_decimal dec_1 = {{0x104b0, 0x0, 0x0, 0x80000000}};
  // -8484286959632
  s21_decimal dec_2 = {{0x66e91010, 0x7b7, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_92) {
  // -9058334.922818931176
  s21_decimal dec_1 = {{0x832349e8, 0x7db5ab9e, 0x0, 0x800c0000}};
  // -78719769718606059653
  s21_decimal dec_2 = {{0xde10d885, 0x4474cd7b, 0x4, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_93) {
  // -4528919512724089
  s21_decimal dec_1 = {{0x3ec5b279, 0x101707, 0x0, 0x80000000}};
  // -5681493317769016
  s21_decimal dec_2 = {{0xbeffd738, 0x142f49, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_94) {
  // -478278562354
  s21_decimal dec_1 = {{0x5b9fb232, 0x6f, 0x0, 0x80000000}};
  // -722879540152622088674.6646
  s21_decimal dec_2 = {{0xf501a616, 0xc8b0409a, 0x5fac1, 0x80040000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_95) {
  // -0.32
  s21_decimal dec_1 = {{0x20, 0x0, 0x0, 0x80020000}};
  // 1731396380904624
  s21_decimal dec_2 = {{0x223fccb0, 0x626b2, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_96) {
  // -401.757384101383548
  s21_decimal dec_1 = {{0x5540cd7c, 0x5935436, 0x0, 0x800f0000}};
  // -20424
  s21_decimal dec_2 = {{0x4fc8, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_97) {
  // 970
  s21_decimal dec_1 = {{0x3ca, 0x0, 0x0, 0x0}};
  // -25816236017471597
  s21_decimal dec_2 = {{0xd942506d, 0x5bb7ba, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_98) {
  // 5847002967416
  s21_decimal dec_1 = {{0x5c88ed78, 0x551, 0x0, 0x0}};
  // 462876736465299
  s21_decimal dec_2 = {{0xe373a993, 0x1a4fb, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_99) {
  // 914307942458973
  s21_decimal dec_1 = {{0xe820265d, 0x33f8e, 0x0, 0x0}};
  // 156168155680263305052264752
  s21_decimal dec_2 = {{0xb9eb9930, 0xaede514d, 0x812de4, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_100) {
  // -12619020866
  s21_decimal dec_1 = {{0xf026fa42, 0x2, 0x0, 0x80000000}};
  // 79228162514264337592534919228
  s21_decimal dec_2 = {{0xc3db683c, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_101) {
  // -44
  s21_decimal dec_1 = {{0x2c, 0x0, 0x0, 0x80000000}};
  // -95600976631.667647063037593714
  s21_decimal dec_2 = {{0x352c4872, 0xca1cb035, 0x34e7463f, 0x80120000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_102) {
  // -3280314
  s21_decimal dec_1 = {{0x320dba, 0x0, 0x0, 0x80000000}};
  // -44826487574722289050058902694
  s21_decimal dec_2 = {{0x9c824ca6, 0xaba0917d, 0x90d799f8, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_103) {
  // -0.458036888181147
  s21_decimal dec_1 = {{0x603999b, 0x1a095, 0x0, 0x800f0000}};
  // -77070156287731103485527
  s21_decimal dec_2 = {{0xc2a4ce57, 0xfb467880, 0x1051, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_104) {
  // -68824358775225331
  s21_decimal dec_1 = {{0xc0b0fbf3, 0xf48363, 0x0, 0x80000000}};
  // 170661424780174660733821
  s21_decimal dec_2 = {{0x85bc0b7d, 0x930a4296, 0x2423, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_105) {
  // 472400628480739406836048.7
  s21_decimal dec_1 = {{0xedb16d27, 0xe4d2c656, 0x3e858, 0x10000}};
  // -5093532203149149532618066492
  s21_decimal dec_2 = {{0x13e98a3c, 0x392d5e2, 0x10754566, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_106) {
  // -8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -183725485470
  s21_decimal dec_2 = {{0xc6e46d9e, 0x2a, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_107) {
  // 197674
  s21_decimal dec_1 = {{0x3042a, 0x0, 0x0, 0x0}};
  // 84116875
  s21_decimal dec_2 = {{0x503858b, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_108) {
  // 157592
  s21_decimal dec_1 = {{0x26798, 0x0, 0x0, 0x0}};
  // -95543564520.5
  s21_decimal dec_2 = {{0x7466f915, 0xde, 0x0, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_109) {
  // 5074248070990536391046
  s21_decimal dec_1 = {{0x22083986, 0x1356880c, 0x113, 0x0}};
  // 433357374635780460329709566
  s21_decimal dec_2 = {{0x1f4e2ffe, 0x5a259c49, 0x16676fe, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_110) {
  // 8.021
  s21_decimal dec_1 = {{0x1f55, 0x0, 0x0, 0x30000}};
  // 9.550
  s21_decimal dec_2 = {{0x254e, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_111) {
  // 81.73407998
  s21_decimal dec_1 = {{0xe72c4efe, 0x1, 0x0, 0x80000}};
  // 1550783327.53680
  s21_decimal dec_2 = {{0xfcefa710, 0x8d0a, 0x0, 0x50000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_112) {
  // 6.290315325931
  s21_decimal dec_1 = {{0x9402b1eb, 0x5b8, 0x0, 0xc0000}};
  // -157895174221475034
  s21_decimal dec_2 = {{0xb382cda, 0x230f4d3, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_113) {
  // -142880245598
  s21_decimal dec_1 = {{0x4453875e, 0x21, 0x0, 0x80000000}};
  // -73585516349991820340864467570
  s21_decimal dec_2 = {{0x590fc272, 0x81a5d97b, 0xedc48332, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_114) {
  // -5083936.402359551
  s21_decimal dec_1 = {{0x2f52c4ff, 0x120fd0, 0x0, 0x80090000}};
  // -4236356119016969
  s21_decimal dec_2 = {{0x859db609, 0xf0cf1, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_115) {
  // 53
  s21_decimal dec_1 = {{0x35, 0x0, 0x0, 0x0}};
  // 15261
  s21_decimal dec_2 = {{0x3b9d, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_116) {
  // 50.0
  s21_decimal dec_1 = {{0x1f4, 0x0, 0x0, 0x10000}};
  // 5059825283250785
  s21_decimal dec_2 = {{0x60a23a61, 0x11f9e2, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_117) {
  // -769362881460556.0160429412
  s21_decimal dec_1 = {{0x94dba564, 0x7429434a, 0x65d30, 0x800a0000}};
  // 45648427028034728261795286
  s21_decimal dec_2 = {{0xd9373dd6, 0x300e39b8, 0x25c26e, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_118) {
  // 3749
  s21_decimal dec_1 = {{0xea5, 0x0, 0x0, 0x0}};
  // -122149907177737480882624
  s21_decimal dec_2 = {{0xc24c9c0, 0xc27e1835, 0x19dd, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_119) {
  // 4714627405686
  s21_decimal dec_1 = {{0xb5b11776, 0x449, 0x0, 0x0}};
  // -52362228798605459973483658872
  s21_decimal dec_2 = {{0x2f6dfe78, 0xfb472346, 0xa931053e, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_120) {
  // 34.045175268
  s21_decimal dec_1 = {{0xed4025e4, 0x7, 0x0, 0x90000}};
  // -1966179376630091339.1431066
  s21_decimal dec_2 = {{0x30a4ed9a, 0xf9cf4aab, 0x10438b, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_121) {
  // 480331
  s21_decimal dec_1 = {{0x7544b, 0x0, 0x0, 0x0}};
  // 717796
  s21_decimal dec_2 = {{0xaf3e4, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_122) {
  // 40.842
  s21_decimal dec_1 = {{0x9f8a, 0x0, 0x0, 0x30000}};
  // 143.414355002548693621
  s21_decimal dec_2 = {{0x72ae2a75, 0xc6462408, 0x7, 0x120000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_123) {
  // 21912
  s21_decimal dec_1 = {{0x5598, 0x0, 0x0, 0x0}};
  // -40526622201.117947489326579
  s21_decimal dec_2 = {{0x73c695f3, 0x97797de6, 0x2185d8, 0x800f0000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_124) {
  // 78557459.073479132716542
  s21_decimal dec_1 = {{0xaad61dfe, 0x9bbf6c12, 0x10a2, 0xf0000}};
  // 15492094782175976910385487352
  s21_decimal dec_2 = {{0x666a9df8, 0xf59675c5, 0x320ec2ac, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_125) {
  // -8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -24508661364786286.8613355
  s21_decimal dec_2 = {{0x2e2e18eb, 0x2c04cc33, 0x33e6, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_126) {
  // -71097.7084760909821659818113
  s21_decimal dec_1 = {{0x9d93a881, 0xfe87c999, 0x24c1b40, 0x80160000}};
  // -1174338.9661731
  s21_decimal dec_2 = {{0x3891ba23, 0xaae, 0x0, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_127) {
  // -168888781688859
  s21_decimal dec_1 = {{0x7bd6d01b, 0x999a, 0x0, 0x80000000}};
  // -53529874062163291935480951
  s21_decimal dec_2 = {{0x1eea1c77, 0x499d1d9c, 0x2c4764, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_128) {
  // -6.414718849708812
  s21_decimal dec_1 = {{0x1e5ef30c, 0x16ca27, 0x0, 0x800f0000}};
  // 978790445934084923888
  s21_decimal dec_2 = {{0x1750a1f0, 0xf7234b9, 0x35, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_129) {
  // 526374199.3162148
  s21_decimal dec_1 = {{0x6fb115a4, 0x12b358, 0x0, 0x70000}};
  // -9233897082
  s21_decimal dec_2 = {{0x2662167a, 0x2, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_130) {
  // 0.22
  s21_decimal dec_1 = {{0x16, 0x0, 0x0, 0x20000}};
  // -99188401.2
  s21_decimal dec_2 = {{0x3b1ef2ec, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_131) {
  // -473215233322
  s21_decimal dec_1 = {{0x2dd36d2a, 0x6e, 0x0, 0x80000000}};
  // -30630742095577218378354089
  s21_decimal dec_2 = {{0x2da7cda9, 0xdb32c47b, 0x19564f, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_132) {
  // 9.161886980
  s21_decimal dec_1 = {{0x22174d04, 0x2, 0x0, 0x90000}};
  // -4987247101007934654871179
  s21_decimal dec_2 = {{0xc8f5768b, 0x35034f1c, 0x42017, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_133) {
  // 1059013013.10176075
  s21_decimal dec_1 = {{0x25d83b4b, 0x1783cac, 0x0, 0x80000}};
  // -831805714568.27
  s21_decimal dec_2 = {{0xfc69f53b, 0x4ba6, 0x0, 0x80020000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_134) {
  // -79979377902214486
  s21_decimal dec_1 = {{0x937dd56, 0x11c24d2, 0x0, 0x80000000}};
  // -8038417724724169041
  s21_decimal dec_2 = {{0xce634951, 0x6f8e3254, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_135) {
  // -41435676
  s21_decimal dec_1 = {{0x278421c, 0x0, 0x0, 0x80000000}};
  // 990214146569287287939506
  s21_decimal dec_2 = {{0x5c1fa1b2, 0x9dcf755e, 0xd1af, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_136) {
  // 6.1
  s21_decimal dec_1 = {{0x3d, 0x0, 0x0, 0x10000}};
  // 68557920543655280983908505462
  s21_decimal dec_2 = {{0x4b0b5776, 0xb9d9fdf2, 0xdd85c85f, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_137) {
  // 7709385952159445909828292
  s21_decimal dec_1 = {{0x5c80f2c4, 0xa65f63a8, 0x66086, 0x0}};
  // -254139260893802320918358028
  s21_decimal dec_2 = {{0x4e32280c, 0xf051a925, 0xd23814, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_138) {
  // 510.27706208628904697069
  s21_decimal dec_1 = {{0xa09a1ced, 0x37add85f, 0xace, 0x140000}};
  // -6192997659586606
  s21_decimal dec_2 = {{0xa198302e, 0x16007f, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_139) {
  // -3.4
  s21_decimal dec_1 = {{0x22, 0x0, 0x0, 0x80010000}};
  // 5763852844
  s21_decimal dec_2 = {{0x578d6a2c, 0x1, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_140) {
  // -1101019965695.137
  s21_decimal dec_1 = {{0x2ff224a1, 0x3e95f, 0x0, 0x80030000}};
  // -266730319472990498711
  s21_decimal dec_2 = {{0xe60e2f97, 0x75a0745c, 0xe, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_141) {
  // -95836.507
  s21_decimal dec_1 = {{0x5b6595b, 0x0, 0x0, 0x80030000}};
  // -6120372644140764
  s21_decimal dec_2 = {{0x4d58d6dc, 0x15be72, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_142) {
  // -9822808.29697188286
  s21_decimal dec_1 = {{0xd3c6e1be, 0xda1c335, 0x0, 0x800b0000}};
  // 13630114853535326909964693383
  s21_decimal dec_2 = {{0xe49b2f87, 0xc580d798, 0x2c0a9116, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_143) {
  // -88.4835586439721886
  s21_decimal dec_1 = {{0x1e5d339e, 0xc479147, 0x0, 0x80100000}};
  // -154410405387320236217691400
  s21_decimal dec_2 = {{0x1d876d08, 0xd948a9c5, 0x7fb9ac, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_144) {
  // 44.221
  s21_decimal dec_1 = {{0xacbd, 0x0, 0x0, 0x30000}};
  // -9450607346.760073910925141379
  s21_decimal dec_2 = {{0x2c442583, 0xd54f0606, 0x1e895bf2, 0x80120000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_145) {
  // 990.4
  s21_decimal dec_1 = {{0x26b0, 0x0, 0x0, 0x10000}};
  // -45946
  s21_decimal dec_2 = {{0xb37a, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_146) {
  // 144.3
  s21_decimal dec_1 = {{0x5a3, 0x0, 0x0, 0x10000}};
  // 856.1660690007932722933
  s21_decimal dec_2 = {{0x949edef5, 0x20e90bf0, 0x1d0, 0x130000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_147) {
  // 85898538521.1
  s21_decimal dec_1 = {{0xff84ccfb, 0xc7, 0x0, 0x10000}};
  // 755742746631
  s21_decimal dec_2 = {{0xf5c72807, 0xaf, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_148) {
  // -703710658645975
  s21_decimal dec_1 = {{0x67d54fd7, 0x28005, 0x0, 0x80000000}};
  // -54527790978012366497
  s21_decimal dec_2 = {{0x6f2d46a1, 0xf4b9a0fe, 0x2, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_149) {
  // 870613.097023271179156
  s21_decimal dec_1 = {{0x6ac59394, 0x322f0f09, 0x2f, 0xf0000}};
  // 928140048081
  s21_decimal dec_2 = {{0x197536d1, 0xd8, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_150) {
  // -5
  s21_decimal dec_1 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 85.90506
  s21_decimal dec_2 = {{0x8314aa, 0x0, 0x0, 0x50000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_151) {
  // 165521
  s21_decimal dec_1 = {{0x28691, 0x0, 0x0, 0x0}};
  // 817440925
  s21_decimal dec_2 = {{0x30b9289d, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_152) {
  // 944193827446660554
  s21_decimal dec_1 = {{0x94131dca, 0xd1a7348, 0x0, 0x0}};
  // 16721470205238275414983096717
  s21_decimal dec_2 = {{0xf29ab98d, 0x2efd0a6e, 0x3607ad0c, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_153) {
  // -4693936
  s21_decimal dec_1 = {{0x479fb0, 0x0, 0x0, 0x80000000}};
  // 649340319532106.955158118
  s21_decimal dec_2 = {{0xd5d4f266, 0xcf2b65fd, 0x8980, 0x90000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_154) {
  // 63659152633485
  s21_decimal dec_1 = {{0xcd2dee8d, 0x39e5, 0x0, 0x0}};
  // 86717909086531.86
  s21_decimal dec_2 = {{0xa8ad3e82, 0x1ecef2, 0x0, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_155) {
  // 1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  // -929.0407003620012158984838033
  s21_decimal dec_2 = {{0x7d42db91, 0xd478caca, 0x1e04d834, 0x80190000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_156) {
  // 31857481325485735
  s21_decimal dec_1 = {{0xe1d81ea7, 0x712e35, 0x0, 0x0}};
  // 40131661594722199533220494323
  s21_decimal dec_2 = {{0x6b77bf3, 0x52924886, 0x81ac21e6, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_157) {
  // 876804417460.53348682
  s21_decimal dec_1 = {{0x96d73d4a, 0xc0cf8137, 0x4, 0x80000}};
  // -3959854479736585404068
  s21_decimal dec_2 = {{0xba6d3ea4, 0xaa052d1c, 0xd6, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_158) {
  // 196045901341540567
  s21_decimal dec_1 = {{0x652240d7, 0x2b87eb5, 0x0, 0x0}};
  // -77984992366833025381
  s21_decimal dec_2 = {{0x1ca1c165, 0x3a425960, 0x4, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_159) {
  // 4944877.140
  s21_decimal dec_1 = {{0x26bcd654, 0x1, 0x0, 0x30000}};
  // -709207127357440.99188
  s21_decimal dec_2 = {{0xa78c8374, 0xd838fc7a, 0x3, 0x80050000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_160) {
  // 0.23
  s21_decimal dec_1 = {{0x17, 0x0, 0x0, 0x20000}};
  // -18518
  s21_decimal dec_2 = {{0x4856, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_161) {
  // -0.6742410543749388
  s21_decimal dec_1 = {{0xc963d90c, 0x17f42f, 0x0, 0x80100000}};
  // -69182476414451758676267.650464
  s21_decimal dec_2 = {{0x25a4da0, 0x52e3cbed, 0xdf8a6739, 0x80060000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_162) {
  // -5791148835238
  s21_decimal dec_1 = {{0x5b5e81a6, 0x544, 0x0, 0x80000000}};
  // 797910258820689204
  s21_decimal dec_2 = {{0x23a5ad34, 0xb12bf27, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_163) {
  // -40030853734878850676211025
  s21_decimal dec_1 = {{0xce74bd51, 0xede5f759, 0x211cdc, 0x80000000}};
  // 855945076780517066585028778
  s21_decimal dec_2 = {{0x343e38aa, 0x96b41688, 0x2c4056b, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_164) {
  // -72.1767
  s21_decimal dec_1 = {{0xb0367, 0x0, 0x0, 0x80040000}};
  // -282.59000
  s21_decimal dec_2 = {{0x1af32b8, 0x0, 0x0, 0x80050000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_165) {
  // -95823
  s21_decimal dec_1 = {{0x1764f, 0x0, 0x0, 0x80000000}};
  // -29173702921908100068154
  s21_decimal dec_2 = {{0xa3d8f33a, 0x82756e92, 0x62d, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_166) {
  // 43594.86636628210
  s21_decimal dec_1 = {{0x146118f2, 0xf7cee, 0x0, 0xb0000}};
  // 906801
  s21_decimal dec_2 = {{0xdd631, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_167) {
  // -6140808742671619.3851618830
  s21_decimal dec_1 = {{0x216ab60e, 0x16fddf26, 0x32cbab, 0x800a0000}};
  // 0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // 0 division
  int check = 3;  // Деление на 0.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

Suite *suite_s21_div(void) {
  Suite *c = suite_create("s21_div_cases");
  TCase *tc = tcase_create("s21_div_tc");

  tcase_add_test(tc, invalid_dec_s21_div_1);
  tcase_add_test(tc, invalid_dec_s21_div_2);
  tcase_add_test(tc, invalid_dec_s21_div_3);
  tcase_add_test(tc, invalid_dec_s21_div_4);
  tcase_add_test(tc, invalid_dec_s21_div_5);
  tcase_add_test(tc, invalid_dec_s21_div_6);
  tcase_add_test(tc, invalid_dec_s21_div_7);
  tcase_add_test(tc, invalid_dec_s21_div_8);
  tcase_add_test(tc, invalid_dec_s21_div_9);
  tcase_add_test(tc, invalid_dec_s21_div_10);
  tcase_add_test(tc, invalid_dec_s21_div_11);
  tcase_add_test(tc, invalid_dec_s21_div_12);
  tcase_add_test(tc, invalid_dec_s21_div_13);
  tcase_add_test(tc, invalid_dec_s21_div_14);
  tcase_add_test(tc, invalid_dec_s21_div_15);
  tcase_add_test(tc, invalid_dec_s21_div_16);
  tcase_add_test(tc, s21_div_1);
  tcase_add_test(tc, s21_div_2);
  tcase_add_test(tc, s21_div_3);
  tcase_add_test(tc, s21_div_4);
  tcase_add_test(tc, s21_div_5);
  tcase_add_test(tc, s21_div_6);
  tcase_add_test(tc, s21_div_7);
  tcase_add_test(tc, s21_div_8);
  tcase_add_test(tc, s21_div_9);
  tcase_add_test(tc, s21_div_10);
  tcase_add_test(tc, s21_div_11);
  tcase_add_test(tc, s21_div_12);
  tcase_add_test(tc, s21_div_13);
  tcase_add_test(tc, s21_div_14);
  tcase_add_test(tc, s21_div_15);
  tcase_add_test(tc, s21_div_16);
  tcase_add_test(tc, s21_div_17);
  tcase_add_test(tc, s21_div_18);
  tcase_add_test(tc, s21_div_19);
  tcase_add_test(tc, s21_div_20);
  tcase_add_test(tc, s21_div_21);
  tcase_add_test(tc, s21_div_22);
  tcase_add_test(tc, s21_div_23);
  tcase_add_test(tc, s21_div_24);
  tcase_add_test(tc, s21_div_25);
  tcase_add_test(tc, s21_div_26);
  tcase_add_test(tc, s21_div_27);
  tcase_add_test(tc, s21_div_28);
  tcase_add_test(tc, s21_div_29);
  tcase_add_test(tc, s21_div_30);
  tcase_add_test(tc, s21_div_32);
  tcase_add_test(tc, s21_div_33);
  tcase_add_test(tc, s21_div_34);
  tcase_add_test(tc, s21_div_35);
  tcase_add_test(tc, s21_div_36);
  tcase_add_test(tc, s21_div_37);
  tcase_add_test(tc, s21_div_38);
  tcase_add_test(tc, s21_div_39);
  tcase_add_test(tc, s21_div_40);
  tcase_add_test(tc, s21_div_41);
  tcase_add_test(tc, s21_div_44);
  tcase_add_test(tc, s21_div_45);
  tcase_add_test(tc, s21_div_46);
  tcase_add_test(tc, s21_div_47);
  tcase_add_test(tc, s21_div_48);
  tcase_add_test(tc, s21_div_49);
  tcase_add_test(tc, s21_div_50);
  tcase_add_test(tc, s21_div_52);
  tcase_add_test(tc, s21_div_53);
  tcase_add_test(tc, s21_div_54);
  tcase_add_test(tc, s21_div_56);
  tcase_add_test(tc, s21_div_57);
  tcase_add_test(tc, s21_div_58);
  tcase_add_test(tc, s21_div_59);
  tcase_add_test(tc, s21_div_60);
  tcase_add_test(tc, s21_div_61);
  tcase_add_test(tc, s21_div_62);
  tcase_add_test(tc, s21_div_63);
  tcase_add_test(tc, s21_div_64);
  tcase_add_test(tc, s21_div_65);
  tcase_add_test(tc, s21_div_66);
  tcase_add_test(tc, s21_div_67);
  tcase_add_test(tc, s21_div_68);
  tcase_add_test(tc, s21_div_69);
  tcase_add_test(tc, s21_div_70);
  tcase_add_test(tc, s21_div_74);
  tcase_add_test(tc, s21_div_75);
  tcase_add_test(tc, s21_div_76);
  tcase_add_test(tc, s21_div_77);
  tcase_add_test(tc, s21_div_78);
  tcase_add_test(tc, s21_div_80);
  tcase_add_test(tc, s21_div_81);
  tcase_add_test(tc, s21_div_82);
  tcase_add_test(tc, s21_div_83);
  tcase_add_test(tc, s21_div_84);
  tcase_add_test(tc, s21_div_85);
  tcase_add_test(tc, s21_div_87);
  tcase_add_test(tc, s21_div_88);
  tcase_add_test(tc, s21_div_90);
  tcase_add_test(tc, s21_div_92);
  tcase_add_test(tc, s21_div_94);
  tcase_add_test(tc, s21_div_95);
  tcase_add_test(tc, s21_div_96);
  tcase_add_test(tc, s21_div_97);
  tcase_add_test(tc, s21_div_99);
  tcase_add_test(tc, s21_div_100);
  tcase_add_test(tc, s21_div_102);
  tcase_add_test(tc, s21_div_103);
  tcase_add_test(tc, s21_div_104);
  tcase_add_test(tc, s21_div_105);
  tcase_add_test(tc, s21_div_106);
  tcase_add_test(tc, s21_div_107);
  tcase_add_test(tc, s21_div_108);
  tcase_add_test(tc, s21_div_109);
  tcase_add_test(tc, s21_div_110);
  tcase_add_test(tc, s21_div_111);
  tcase_add_test(tc, s21_div_112);
  tcase_add_test(tc, s21_div_113);
  tcase_add_test(tc, s21_div_115);
  tcase_add_test(tc, s21_div_116);
  tcase_add_test(tc, s21_div_117);
  tcase_add_test(tc, s21_div_118);
  tcase_add_test(tc, s21_div_120);
  tcase_add_test(tc, s21_div_121);
  tcase_add_test(tc, s21_div_122);
  tcase_add_test(tc, s21_div_124);
  tcase_add_test(tc, s21_div_125);
  tcase_add_test(tc, s21_div_126);
  tcase_add_test(tc, s21_div_127);
  tcase_add_test(tc, s21_div_128);
  tcase_add_test(tc, s21_div_129);
  tcase_add_test(tc, s21_div_130);
  tcase_add_test(tc, s21_div_131);
  tcase_add_test(tc, s21_div_132);
  tcase_add_test(tc, s21_div_133);
  tcase_add_test(tc, s21_div_134);
  tcase_add_test(tc, s21_div_135);
  tcase_add_test(tc, s21_div_136);
  tcase_add_test(tc, s21_div_137);
  tcase_add_test(tc, s21_div_138);
  tcase_add_test(tc, s21_div_139);
  tcase_add_test(tc, s21_div_140);
  tcase_add_test(tc, s21_div_142);
  tcase_add_test(tc, s21_div_143);
  tcase_add_test(tc, s21_div_144);
  tcase_add_test(tc, s21_div_146);
  tcase_add_test(tc, s21_div_147);
  tcase_add_test(tc, s21_div_148);
  tcase_add_test(tc, s21_div_149);
  tcase_add_test(tc, s21_div_150);
  tcase_add_test(tc, s21_div_151);
  tcase_add_test(tc, s21_div_152);
  tcase_add_test(tc, s21_div_153);
  tcase_add_test(tc, s21_div_154);
  tcase_add_test(tc, s21_div_155);
  tcase_add_test(tc, s21_div_156);
  tcase_add_test(tc, s21_div_157);
  tcase_add_test(tc, s21_div_158);
  tcase_add_test(tc, s21_div_159);
  tcase_add_test(tc, s21_div_160);
  tcase_add_test(tc, s21_div_161);
  tcase_add_test(tc, s21_div_162);
  tcase_add_test(tc, s21_div_163);
  tcase_add_test(tc, s21_div_164);
  tcase_add_test(tc, s21_div_165);
  tcase_add_test(tc, s21_div_166);
  tcase_add_test(tc, s21_div_167);
  tcase_add_test(tc, s21_div_168);
  tcase_add_test(tc, s21_div_169);
  tcase_add_test(tc, s21_div_170);
  tcase_add_test(tc, s21_div_171);
  tcase_add_test(tc, s21_div_172);
  tcase_add_test(tc, s21_div_173);
  tcase_add_test(tc, s21_div_175);
  tcase_add_test(tc, s21_div_176);
  tcase_add_test(tc, s21_div_177);
  tcase_add_test(tc, s21_div_178);
  tcase_add_test(tc, s21_div_179);
  tcase_add_test(tc, s21_div_180);
  tcase_add_test(tc, s21_div_181);
  tcase_add_test(tc, s21_div_182);
  tcase_add_test(tc, s21_div_183);
  tcase_add_test(tc, s21_div_184);
  tcase_add_test(tc, s21_div_185);
  tcase_add_test(tc, s21_div_187);
  tcase_add_test(tc, s21_div_188);
  tcase_add_test(tc, s21_div_189);
  tcase_add_test(tc, s21_div_190);
  tcase_add_test(tc, s21_div_192);
  tcase_add_test(tc, s21_div_193);
  tcase_add_test(tc, s21_div_194);
  tcase_add_test(tc, s21_div_195);
  tcase_add_test(tc, s21_div_196);
  tcase_add_test(tc, s21_div_197);
  tcase_add_test(tc, s21_div_198);
  tcase_add_test(tc, s21_div_199);
  tcase_add_test(tc, s21_div_200);
  tcase_add_test(tc, s21_div_201);
  tcase_add_test(tc, s21_div_202);
  tcase_add_test(tc, s21_div_203);
  tcase_add_test(tc, s21_div_204);
  tcase_add_test(tc, s21_div_205);
  tcase_add_test(tc, s21_div_206);
  tcase_add_test(tc, s21_div_207);
  tcase_add_test(tc, s21_div_208);
  tcase_add_test(tc, s21_div_209);
  tcase_add_test(tc, s21_div_210);
  tcase_add_test(tc, s21_div_211);
  tcase_add_test(tc, s21_div_213);
  tcase_add_test(tc, s21_div_214);
  tcase_add_test(tc, s21_div_215);
  tcase_add_test(tc, s21_div_216);
  tcase_add_test(tc, s21_div_217);
  tcase_add_test(tc, s21_div_218);
  tcase_add_test(tc, s21_div_219);
  tcase_add_test(tc, s21_div_220);
  tcase_add_test(tc, s21_div_222);
  tcase_add_test(tc, s21_div_223);
  tcase_add_test(tc, s21_div_224);
  tcase_add_test(tc, s21_div_225);
  tcase_add_test(tc, s21_div_226);
  tcase_add_test(tc, s21_div_227);
  tcase_add_test(tc, s21_div_228);
  tcase_add_test(tc, s21_div_229);
  tcase_add_test(tc, s21_div_230);
  tcase_add_test(tc, s21_div_231);
  tcase_add_test(tc, s21_div_232);
  tcase_add_test(tc, s21_div_233);
  tcase_add_test(tc, s21_div_234);
  tcase_add_test(tc, s21_div_235);
  tcase_add_test(tc, s21_div_236);
  tcase_add_test(tc, s21_div_237);
  tcase_add_test(tc, s21_div_239);
  tcase_add_test(tc, s21_div_240);
  tcase_add_test(tc, s21_div_241);
  tcase_add_test(tc, s21_div_242);
  tcase_add_test(tc, s21_div_243);
  tcase_add_test(tc, s21_div_244);
  tcase_add_test(tc, s21_div_245);
  tcase_add_test(tc, s21_div_246);
  tcase_add_test(tc, s21_div_247);
  tcase_add_test(tc, s21_div_248);
  tcase_add_test(tc, s21_div_249);
  tcase_add_test(tc, s21_div_250);
  tcase_add_test(tc, s21_div_251);
  tcase_add_test(tc, s21_div_253);
  tcase_add_test(tc, s21_div_254);
  tcase_add_test(tc, s21_div_257);
  tcase_add_test(tc, s21_div_258);
  tcase_add_test(tc, s21_div_259);
  tcase_add_test(tc, s21_div_260);
  tcase_add_test(tc, s21_div_261);
  tcase_add_test(tc, s21_div_262);
  tcase_add_test(tc, s21_div_264);
  tcase_add_test(tc, s21_div_265);
  tcase_add_test(tc, s21_div_266);
  tcase_add_test(tc, s21_div_267);
  tcase_add_test(tc, s21_div_268);
  tcase_add_test(tc, s21_div_269);
  tcase_add_test(tc, s21_div_270);
  tcase_add_test(tc, s21_div_271);
  tcase_add_test(tc, s21_div_272);
  tcase_add_test(tc, s21_div_273);
  tcase_add_test(tc, s21_div_274);
  tcase_add_test(tc, s21_div_275);
  tcase_add_test(tc, s21_div_276);
  tcase_add_test(tc, s21_div_277);
  tcase_add_test(tc, s21_div_278);
  tcase_add_test(tc, s21_div_279);
  tcase_add_test(tc, s21_div_280);
  tcase_add_test(tc, s21_div_281);
  tcase_add_test(tc, s21_div_282);
  tcase_add_test(tc, s21_div_283);
  tcase_add_test(tc, s21_div_284);
  tcase_add_test(tc, s21_div_285);
  tcase_add_test(tc, s21_div_287);
  tcase_add_test(tc, s21_div_289);
  tcase_add_test(tc, s21_div_290);
  tcase_add_test(tc, s21_div_291);
  tcase_add_test(tc, s21_div_294);
  tcase_add_test(tc, s21_div_295);
  tcase_add_test(tc, s21_div_296);
  tcase_add_test(tc, s21_div_298);
  tcase_add_test(tc, s21_div_299);
  tcase_add_test(tc, s21_div_300);
  tcase_add_test(tc, s21_div_301);
  tcase_add_test(tc, s21_div_303);
  tcase_add_test(tc, s21_div_304);
  tcase_add_test(tc, s21_div_305);
  tcase_add_test(tc, s21_div_306);
  tcase_add_test(tc, s21_div_307);
  tcase_add_test(tc, s21_div_308);
  tcase_add_test(tc, s21_div_309);
  tcase_add_test(tc, s21_div_310);
  tcase_add_test(tc, s21_div_311);
  tcase_add_test(tc, s21_div_312);
  tcase_add_test(tc, s21_div_314);
  tcase_add_test(tc, s21_div_315);
  tcase_add_test(tc, s21_div_316);
  tcase_add_test(tc, s21_div_317);
  tcase_add_test(tc, s21_div_319);
  tcase_add_test(tc, s21_div_320);
  tcase_add_test(tc, s21_div_321);
  tcase_add_test(tc, s21_div_322);
  tcase_add_test(tc, s21_div_323);
  tcase_add_test(tc, s21_div_324);
  tcase_add_test(tc, s21_div_325);
  tcase_add_test(tc, s21_div_326);
  tcase_add_test(tc, s21_div_327);
  tcase_add_test(tc, s21_div_328);
  tcase_add_test(tc, s21_div_329);
  tcase_add_test(tc, s21_div_330);
  tcase_add_test(tc, s21_div_331);
  tcase_add_test(tc, s21_div_332);
  tcase_add_test(tc, s21_div_333);
  tcase_add_test(tc, s21_div_334);
  tcase_add_test(tc, s21_div_336);
  tcase_add_test(tc, s21_div_338);
  tcase_add_test(tc, s21_div_341);
  tcase_add_test(tc, s21_div_342);
  tcase_add_test(tc, s21_div_343);
  tcase_add_test(tc, s21_div_344);
  tcase_add_test(tc, s21_div_345);
  tcase_add_test(tc, s21_div_346);
  tcase_add_test(tc, s21_div_347);
  tcase_add_test(tc, s21_div_349);
  tcase_add_test(tc, s21_div_350);
  tcase_add_test(tc, s21_div_351);
  tcase_add_test(tc, s21_div_352);
  tcase_add_test(tc, s21_div_353);
  tcase_add_test(tc, s21_div_354);
  tcase_add_test(tc, s21_div_355);
  tcase_add_test(tc, s21_div_356);
  tcase_add_test(tc, s21_div_357);
  tcase_add_test(tc, s21_div_358);
  tcase_add_test(tc, s21_div_359);
  tcase_add_test(tc, s21_div_360);
  tcase_add_test(tc, s21_div_361);
  tcase_add_test(tc, s21_div_363);
  tcase_add_test(tc, s21_div_364);
  tcase_add_test(tc, s21_div_365);
  tcase_add_test(tc, s21_div_366);
  tcase_add_test(tc, s21_div_367);
  tcase_add_test(tc, s21_div_368);
  tcase_add_test(tc, s21_div_369);
  tcase_add_test(tc, s21_div_370);
  tcase_add_test(tc, s21_div_371);
  tcase_add_test(tc, s21_div_373);
  tcase_add_test(tc, s21_div_374);
  tcase_add_test(tc, s21_div_375);
  tcase_add_test(tc, s21_div_376);
  tcase_add_test(tc, s21_div_377);
  tcase_add_test(tc, s21_div_378);
  tcase_add_test(tc, s21_div_379);
  tcase_add_test(tc, s21_div_380);
  tcase_add_test(tc, s21_div_381);
  tcase_add_test(tc, s21_div_382);
  tcase_add_test(tc, s21_div_384);
  tcase_add_test(tc, s21_div_385);
  tcase_add_test(tc, s21_div_386);
  tcase_add_test(tc, s21_div_387);
  tcase_add_test(tc, s21_div_388);
  tcase_add_test(tc, s21_div_389);
  tcase_add_test(tc, s21_div_390);
  tcase_add_test(tc, s21_div_391);
  tcase_add_test(tc, s21_div_392);
  tcase_add_test(tc, s21_div_393);
  tcase_add_test(tc, s21_div_394);
  tcase_add_test(tc, s21_div_395);
  tcase_add_test(tc, s21_div_396);
  tcase_add_test(tc, s21_div_397);
  tcase_add_test(tc, s21_div_398);
  tcase_add_test(tc, s21_div_399);
  tcase_add_test(tc, s21_div_400);
  tcase_add_test(tc, s21_div_401);
  tcase_add_test(tc, s21_div_402);
  tcase_add_test(tc, s21_div_403);
  tcase_add_test(tc, s21_div_404);
  tcase_add_test(tc, s21_div_405);
  tcase_add_test(tc, s21_div_406);
  tcase_add_test(tc, s21_div_408);
  tcase_add_test(tc, s21_div_409);
  tcase_add_test(tc, s21_div_410);
  tcase_add_test(tc, s21_div_411);
  tcase_add_test(tc, s21_div_412);
  tcase_add_test(tc, s21_div_413);
  tcase_add_test(tc, s21_div_414);
  tcase_add_test(tc, s21_div_415);
  tcase_add_test(tc, s21_div_417);
  tcase_add_test(tc, s21_div_418);
  tcase_add_test(tc, s21_div_419);
  tcase_add_test(tc, s21_div_420);
  tcase_add_test(tc, s21_div_421);
  tcase_add_test(tc, s21_div_423);
  tcase_add_test(tc, s21_div_424);
  tcase_add_test(tc, s21_div_425);
  tcase_add_test(tc, s21_div_426);
  tcase_add_test(tc, s21_div_427);
  tcase_add_test(tc, s21_div_428);
  tcase_add_test(tc, s21_div_429);
  tcase_add_test(tc, s21_div_430);
  tcase_add_test(tc, s21_div_431);
  tcase_add_test(tc, s21_div_433);
  tcase_add_test(tc, s21_div_434);
  tcase_add_test(tc, s21_div_435);
  tcase_add_test(tc, s21_div_436);
  tcase_add_test(tc, s21_div_437);
  tcase_add_test(tc, s21_div_438);
  tcase_add_test(tc, s21_div_439);
  tcase_add_test(tc, s21_div_440);
  tcase_add_test(tc, s21_div_441);
  tcase_add_test(tc, s21_div_442);
  tcase_add_test(tc, s21_div_443);
  tcase_add_test(tc, s21_div_444);
  tcase_add_test(tc, s21_div_445);
  tcase_add_test(tc, s21_div_446);
  tcase_add_test(tc, s21_div_447);
  tcase_add_test(tc, s21_div_448);
  tcase_add_test(tc, s21_div_449);
  tcase_add_test(tc, s21_div_451);
  tcase_add_test(tc, s21_div_452);
  tcase_add_test(tc, s21_div_454);
  tcase_add_test(tc, s21_div_455);
  tcase_add_test(tc, s21_div_457);
  tcase_add_test(tc, s21_div_458);
  tcase_add_test(tc, s21_div_459);
  tcase_add_test(tc, s21_div_460);
  tcase_add_test(tc, s21_div_461);
  tcase_add_test(tc, s21_div_462);
  tcase_add_test(tc, s21_div_463);
  tcase_add_test(tc, s21_div_464);
  tcase_add_test(tc, s21_div_465);
  tcase_add_test(tc, s21_div_468);
  tcase_add_test(tc, s21_div_469);
  tcase_add_test(tc, s21_div_472);
  tcase_add_test(tc, s21_div_473);
  tcase_add_test(tc, s21_div_474);
  tcase_add_test(tc, s21_div_475);
  tcase_add_test(tc, s21_div_476);
  tcase_add_test(tc, s21_div_477);
  tcase_add_test(tc, s21_div_478);
  tcase_add_test(tc, s21_div_479);
  tcase_add_test(tc, s21_div_480);
  tcase_add_test(tc, s21_div_481);
  tcase_add_test(tc, s21_div_482);
  tcase_add_test(tc, s21_div_483);
  tcase_add_test(tc, s21_div_484);
  tcase_add_test(tc, s21_div_485);
  tcase_add_test(tc, s21_div_486);
  tcase_add_test(tc, s21_div_487);
  tcase_add_test(tc, s21_div_489);
  tcase_add_test(tc, s21_div_490);
  tcase_add_test(tc, s21_div_491);
  tcase_add_test(tc, s21_div_492);
  tcase_add_test(tc, s21_div_493);
  tcase_add_test(tc, s21_div_494);
  tcase_add_test(tc, s21_div_495);
  tcase_add_test(tc, s21_div_496);
  tcase_add_test(tc, s21_div_497);
  tcase_add_test(tc, s21_div_498);
  tcase_add_test(tc, s21_div_499);
  tcase_add_test(tc, s21_div_500);
  tcase_add_test(tc, fail_s21_div_1);
  tcase_add_test(tc, fail_s21_div_2);
  tcase_add_test(tc, fail_s21_div_3);
  tcase_add_test(tc, fail_s21_div_4);
  tcase_add_test(tc, fail_s21_div_5);
  tcase_add_test(tc, fail_s21_div_6);
  tcase_add_test(tc, fail_s21_div_7);
  tcase_add_test(tc, fail_s21_div_8);
  tcase_add_test(tc, fail_s21_div_9);
  tcase_add_test(tc, fail_s21_div_10);
  tcase_add_test(tc, fail_s21_div_11);
  tcase_add_test(tc, fail_s21_div_12);
  tcase_add_test(tc, fail_s21_div_13);
  tcase_add_test(tc, fail_s21_div_14);
  tcase_add_test(tc, fail_s21_div_15);
  tcase_add_test(tc, fail_s21_div_16);
  tcase_add_test(tc, fail_s21_div_17);
  tcase_add_test(tc, fail_s21_div_18);
  tcase_add_test(tc, fail_s21_div_19);
  tcase_add_test(tc, fail_s21_div_20);
  tcase_add_test(tc, fail_s21_div_21);
  tcase_add_test(tc, fail_s21_div_22);
  tcase_add_test(tc, fail_s21_div_23);
  tcase_add_test(tc, fail_s21_div_24);
  tcase_add_test(tc, fail_s21_div_25);
  tcase_add_test(tc, fail_s21_div_26);
  tcase_add_test(tc, fail_s21_div_27);
  tcase_add_test(tc, fail_s21_div_28);
  tcase_add_test(tc, fail_s21_div_29);
  tcase_add_test(tc, fail_s21_div_30);
  tcase_add_test(tc, fail_s21_div_31);
  tcase_add_test(tc, fail_s21_div_32);
  tcase_add_test(tc, fail_s21_div_33);
  tcase_add_test(tc, fail_s21_div_34);
  tcase_add_test(tc, fail_s21_div_35);
  tcase_add_test(tc, fail_s21_div_36);
  tcase_add_test(tc, fail_s21_div_37);
  tcase_add_test(tc, fail_s21_div_38);
  tcase_add_test(tc, fail_s21_div_39);
  tcase_add_test(tc, fail_s21_div_40);
  tcase_add_test(tc, fail_s21_div_41);
  tcase_add_test(tc, fail_s21_div_42);
  tcase_add_test(tc, fail_s21_div_43);
  tcase_add_test(tc, fail_s21_div_44);
  tcase_add_test(tc, fail_s21_div_45);
  tcase_add_test(tc, fail_s21_div_46);
  tcase_add_test(tc, fail_s21_div_47);
  tcase_add_test(tc, fail_s21_div_48);
  tcase_add_test(tc, fail_s21_div_49);
  tcase_add_test(tc, fail_s21_div_50);
  tcase_add_test(tc, fail_s21_div_51);
  tcase_add_test(tc, fail_s21_div_52);
  tcase_add_test(tc, fail_s21_div_53);
  tcase_add_test(tc, fail_s21_div_54);
  tcase_add_test(tc, fail_s21_div_55);
  tcase_add_test(tc, fail_s21_div_56);
  tcase_add_test(tc, fail_s21_div_57);
  tcase_add_test(tc, fail_s21_div_58);
  tcase_add_test(tc, fail_s21_div_59);
  tcase_add_test(tc, fail_s21_div_60);
  tcase_add_test(tc, fail_s21_div_61);
  tcase_add_test(tc, fail_s21_div_62);
  tcase_add_test(tc, fail_s21_div_63);
  tcase_add_test(tc, fail_s21_div_64);
  tcase_add_test(tc, fail_s21_div_65);
  tcase_add_test(tc, fail_s21_div_66);
  tcase_add_test(tc, fail_s21_div_67);
  tcase_add_test(tc, fail_s21_div_68);
  tcase_add_test(tc, fail_s21_div_69);
  tcase_add_test(tc, fail_s21_div_70);
  tcase_add_test(tc, fail_s21_div_71);
  tcase_add_test(tc, fail_s21_div_72);
  tcase_add_test(tc, fail_s21_div_73);
  tcase_add_test(tc, fail_s21_div_74);
  tcase_add_test(tc, fail_s21_div_75);
  tcase_add_test(tc, fail_s21_div_76);
  tcase_add_test(tc, fail_s21_div_77);
  tcase_add_test(tc, fail_s21_div_78);
  tcase_add_test(tc, fail_s21_div_79);
  tcase_add_test(tc, fail_s21_div_80);
  tcase_add_test(tc, fail_s21_div_81);
  tcase_add_test(tc, fail_s21_div_82);
  tcase_add_test(tc, fail_s21_div_83);
  tcase_add_test(tc, fail_s21_div_84);
  tcase_add_test(tc, fail_s21_div_85);
  tcase_add_test(tc, fail_s21_div_86);
  tcase_add_test(tc, fail_s21_div_87);
  tcase_add_test(tc, fail_s21_div_88);
  tcase_add_test(tc, fail_s21_div_89);
  tcase_add_test(tc, fail_s21_div_90);
  tcase_add_test(tc, fail_s21_div_91);
  tcase_add_test(tc, fail_s21_div_92);
  tcase_add_test(tc, fail_s21_div_93);
  tcase_add_test(tc, fail_s21_div_94);
  tcase_add_test(tc, fail_s21_div_95);
  tcase_add_test(tc, fail_s21_div_96);
  tcase_add_test(tc, fail_s21_div_97);
  tcase_add_test(tc, fail_s21_div_98);
  tcase_add_test(tc, fail_s21_div_99);
  tcase_add_test(tc, fail_s21_div_100);
  tcase_add_test(tc, fail_s21_div_101);
  tcase_add_test(tc, fail_s21_div_102);
  tcase_add_test(tc, fail_s21_div_103);
  tcase_add_test(tc, fail_s21_div_104);
  tcase_add_test(tc, fail_s21_div_105);
  tcase_add_test(tc, fail_s21_div_106);
  tcase_add_test(tc, fail_s21_div_107);
  tcase_add_test(tc, fail_s21_div_108);
  tcase_add_test(tc, fail_s21_div_109);
  tcase_add_test(tc, fail_s21_div_110);
  tcase_add_test(tc, fail_s21_div_111);
  tcase_add_test(tc, fail_s21_div_112);
  tcase_add_test(tc, fail_s21_div_113);
  tcase_add_test(tc, fail_s21_div_114);
  tcase_add_test(tc, fail_s21_div_115);
  tcase_add_test(tc, fail_s21_div_116);
  tcase_add_test(tc, fail_s21_div_117);
  tcase_add_test(tc, fail_s21_div_118);
  tcase_add_test(tc, fail_s21_div_119);
  tcase_add_test(tc, fail_s21_div_120);
  tcase_add_test(tc, fail_s21_div_121);
  tcase_add_test(tc, fail_s21_div_122);
  tcase_add_test(tc, fail_s21_div_123);
  tcase_add_test(tc, fail_s21_div_124);
  tcase_add_test(tc, fail_s21_div_125);
  tcase_add_test(tc, fail_s21_div_126);
  tcase_add_test(tc, fail_s21_div_127);
  tcase_add_test(tc, fail_s21_div_128);
  tcase_add_test(tc, fail_s21_div_129);
  tcase_add_test(tc, fail_s21_div_130);
  tcase_add_test(tc, fail_s21_div_131);
  tcase_add_test(tc, fail_s21_div_132);
  tcase_add_test(tc, fail_s21_div_133);
  tcase_add_test(tc, fail_s21_div_134);
  tcase_add_test(tc, fail_s21_div_135);
  tcase_add_test(tc, fail_s21_div_136);
  tcase_add_test(tc, fail_s21_div_137);
  tcase_add_test(tc, fail_s21_div_138);
  tcase_add_test(tc, fail_s21_div_139);
  tcase_add_test(tc, fail_s21_div_140);
  tcase_add_test(tc, fail_s21_div_141);
  tcase_add_test(tc, fail_s21_div_142);
  tcase_add_test(tc, fail_s21_div_143);
  tcase_add_test(tc, fail_s21_div_144);
  tcase_add_test(tc, fail_s21_div_145);
  tcase_add_test(tc, fail_s21_div_146);
  tcase_add_test(tc, fail_s21_div_147);
  tcase_add_test(tc, fail_s21_div_148);
  tcase_add_test(tc, fail_s21_div_149);
  tcase_add_test(tc, fail_s21_div_150);
  tcase_add_test(tc, fail_s21_div_151);
  tcase_add_test(tc, fail_s21_div_152);
  tcase_add_test(tc, fail_s21_div_153);
  tcase_add_test(tc, fail_s21_div_154);
  tcase_add_test(tc, fail_s21_div_155);
  tcase_add_test(tc, fail_s21_div_156);
  tcase_add_test(tc, fail_s21_div_157);
  tcase_add_test(tc, fail_s21_div_158);
  tcase_add_test(tc, fail_s21_div_159);
  tcase_add_test(tc, fail_s21_div_160);
  tcase_add_test(tc, fail_s21_div_161);
  tcase_add_test(tc, fail_s21_div_162);
  tcase_add_test(tc, fail_s21_div_163);
  tcase_add_test(tc, fail_s21_div_164);
  tcase_add_test(tc, fail_s21_div_165);
  tcase_add_test(tc, fail_s21_div_166);
  tcase_add_test(tc, fail_s21_div_167);

  suite_add_tcase(c, tc);
  return c;
}
