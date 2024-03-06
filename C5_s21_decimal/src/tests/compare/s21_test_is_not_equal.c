#include "../s21_tests.h"

// Первое значение decimal не равно второму decimal
// Возвращаемое значение 1

START_TEST(s21_is_not_equal_true_1) {
  // 79228162514264337593543950335
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal value_2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_2) {
  // 88.4194214279263819
  s21_decimal value_1 = {{0x692364b, 0xc4549f4, 0x0, 0x100000}};
  // -293003639522350615342343
  s21_decimal value_2 = {{0x49a5ad07, 0xc25611c3, 0x3e0b, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_3) {
  // 3015715803664178196447
  s21_decimal value_1 = {{0x46ffafdf, 0x7b76c97c, 0xa3, 0x0}};
  // 1910849696382321279
  s21_decimal value_2 = {{0xbc08027f, 0x1a84b3ac, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_4) {
  // 552119.13395
  s21_decimal value_1 = {{0xdae2f0b3, 0xc, 0x0, 0x50000}};
  // 1579555993829641
  s21_decimal value_2 = {{0x9ea4109, 0x59c99, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_5) {
  // 7872077182689308705534
  s21_decimal value_1 = {{0x7e0e02fe, 0xbf04499a, 0x1aa, 0x0}};
  // -6673766479854518
  s21_decimal value_2 = {{0x58587bb6, 0x17b5c1, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_6) {
  // 5258.2832239
  s21_decimal value_1 = {{0x3e2e586f, 0xc, 0x0, 0x70000}};
  // 613058206255568
  s21_decimal value_2 = {{0xbc9c49d0, 0x22d92, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_7) {
  // 5.8499097
  s21_decimal value_1 = {{0x37ca019, 0x0, 0x0, 0x70000}};
  // -325858860816
  s21_decimal value_2 = {{0xdeb39f10, 0x4b, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_8) {
  // -63573618374.05570568
  s21_decimal value_1 = {{0x8b2f0608, 0x5839e2e8, 0x0, 0x80080000}};
  // 30428762510597163256584
  s21_decimal value_2 = {{0x13530b08, 0x8be8cce5, 0x671, 0x0}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_9) {
  // 48202648127
  s21_decimal value_1 = {{0x391a0a3f, 0xb, 0x0, 0x0}};
  // 15760.212113808040321
  s21_decimal value_2 = {{0x94562181, 0xdab7856a, 0x0, 0xf0000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_10) {
  // 5800345622935.77012
  s21_decimal value_1 = {{0x7af53534, 0x80cb25c, 0x0, 0x50000}};
  // 33510602.8514
  s21_decimal value_2 = {{0x5e033e2, 0x4e, 0x0, 0x40000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_11) {
  // -410661813993146.590
  s21_decimal value_1 = {{0x79e108de, 0x5b2f6be, 0x0, 0x80030000}};
  // -8585221094090175504554906
  s21_decimal value_2 = {{0x64c19b9a, 0xc4a08032, 0x719fd, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_12) {
  // 585
  s21_decimal value_1 = {{0x249, 0x0, 0x0, 0x0}};
  // 23858060149660
  s21_decimal value_2 = {{0xe333439c, 0x15b2, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_13) {
  // -357
  s21_decimal value_1 = {{0x165, 0x0, 0x0, 0x80000000}};
  // -984317783094.0
  s21_decimal value_2 = {{0xcb1e3a1c, 0x8f3, 0x0, 0x80010000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_14) {
  // -3724
  s21_decimal value_1 = {{0xe8c, 0x0, 0x0, 0x80000000}};
  // -440758197
  s21_decimal value_2 = {{0x1a456fb5, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_15) {
  // 5875671676.741479
  s21_decimal value_1 = {{0x6b1be767, 0x14dfe4, 0x0, 0x60000}};
  // 6973984131.88121
  s21_decimal value_2 = {{0xb8af5c19, 0x27a47, 0x0, 0x50000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_16) {
  // 53991743022948946.828650
  s21_decimal value_1 = {{0x872c5d6a, 0xe5f3fadb, 0xb6e, 0x60000}};
  // -2408874990993595257949499
  s21_decimal value_2 = {{0x30718d3b, 0x5ffb05fc, 0x1fe19, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_17) {
  // -624
  s21_decimal value_1 = {{0x270, 0x0, 0x0, 0x80000000}};
  // 253060623159244
  s21_decimal value_2 = {{0x448ccfcc, 0xe628, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_18) {
  // -840
  s21_decimal value_1 = {{0x348, 0x0, 0x0, 0x80000000}};
  // 0.1395978703282
  s21_decimal value_2 = {{0x6d091b2, 0x145, 0x0, 0xd0000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_19) {
  // -0.0832
  s21_decimal value_1 = {{0x340, 0x0, 0x0, 0x80040000}};
  // -189.31244967635
  s21_decimal value_2 = {{0xc621a6d3, 0x1137, 0x0, 0x800b0000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_20) {
  // -71881758183357538
  s21_decimal value_1 = {{0x6597c62, 0xff6014, 0x0, 0x80000000}};
  // 59873526387400495159886693921
  s21_decimal value_2 = {{0xd53b4621, 0x2dec7ac2, 0xc1763861, 0x0}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_21) {
  // 9.134421800650333279
  s21_decimal value_1 = {{0x4058dc5f, 0x7ec3fc3b, 0x0, 0x120000}};
  // -4382.508620824
  s21_decimal value_2 = {{0x61de9c18, 0x3fc, 0x0, 0x80090000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_22) {
  // 4071.43779082
  s21_decimal value_1 = {{0xcba90b0a, 0x5e, 0x0, 0x80000}};
  // -0.3288977339767584725166087261
  s21_decimal value_2 = {{0xc0965c5d, 0xda012e56, 0xaa0940a, 0x801c0000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_23) {
  // 9951.3671963
  s21_decimal value_1 = {{0x2b7a211b, 0x17, 0x0, 0x70000}};
  // 7815685499010976007
  s21_decimal value_2 = {{0x54b88907, 0x6c76e48d, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_24) {
  // 213500255396450.84
  s21_decimal value_1 = {{0x303c6e9c, 0x4bd9bc, 0x0, 0x20000}};
  // 7819493
  s21_decimal value_2 = {{0x7750e5, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_true_25) {
  // 5960875884
  s21_decimal value_1 = {{0x634bbf6c, 0x1, 0x0, 0x0}};
  // -872.2661361778392
  s21_decimal value_2 = {{0xdbf6fed8, 0x1efd36, 0x0, 0x800d0000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

// Первое значение decimal равно второму decimal
// Возвращаемое значение 0

START_TEST(s21_is_not_equal_false_1) {
  // -4801254685137730
  s21_decimal value_1 = {{0x37fbdb42, 0x110eb7, 0x0, 0x80000000}};
  // -4801254685137730
  s21_decimal value_2 = {{0x37fbdb42, 0x110eb7, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_2) {
  // -82767.09597598823362543678730
  s21_decimal value_1 = {{0xb0f2f50a, 0x5660babc, 0x1abe556e, 0x80170000}};
  // -82767.09597598823362543678730
  s21_decimal value_2 = {{0xb0f2f50a, 0x5660babc, 0x1abe556e, 0x80170000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_3) {
  // -215474513651174
  s21_decimal value_1 = {{0x11d825e6, 0xc3f9, 0x0, 0x80000000}};
  // -215474513651174
  s21_decimal value_2 = {{0x11d825e6, 0xc3f9, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_4) {
  // 3.1756
  s21_decimal value_1 = {{0x7c0c, 0x0, 0x0, 0x40000}};
  // 3.1756
  s21_decimal value_2 = {{0x7c0c, 0x0, 0x0, 0x40000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_5) {
  // -5.0569504055586910
  s21_decimal value_1 = {{0x2db3705e, 0xb3a8b2, 0x0, 0x80100000}};
  // -5.0569504055586910
  s21_decimal value_2 = {{0x2db3705e, 0xb3a8b2, 0x0, 0x80100000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_6) {
  // 1680611360598042658103.18333
  s21_decimal value_1 = {{0x54ed53fd, 0x70fa6b32, 0x8b0454, 0x50000}};
  // 1680611360598042658103.18333
  s21_decimal value_2 = {{0x54ed53fd, 0x70fa6b32, 0x8b0454, 0x50000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_7) {
  // -2868000137283
  s21_decimal value_1 = {{0xc2212043, 0x29b, 0x0, 0x80000000}};
  // -2868000137283
  s21_decimal value_2 = {{0xc2212043, 0x29b, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_8) {
  // 89990915915021.018737857394
  s21_decimal value_1 = {{0xf20ed372, 0x53b314b3, 0x4a7051, 0xc0000}};
  // 89990915915021.018737857394
  s21_decimal value_2 = {{0xf20ed372, 0x53b314b3, 0x4a7051, 0xc0000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_9) {
  // -882207000580283678793635
  s21_decimal value_1 = {{0x2fa71fa3, 0x898e7ec1, 0xbad0, 0x80000000}};
  // -882207000580283678793635
  s21_decimal value_2 = {{0x2fa71fa3, 0x898e7ec1, 0xbad0, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_10) {
  // -382730341753870
  s21_decimal value_1 = {{0x5a10a40e, 0x15c17, 0x0, 0x80000000}};
  // -382730341753870
  s21_decimal value_2 = {{0x5a10a40e, 0x15c17, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_11) {
  // 79890014166956989
  s21_decimal value_1 = {{0x6b85bbbd, 0x11bd38b, 0x0, 0x0}};
  // 79890014166956989
  s21_decimal value_2 = {{0x6b85bbbd, 0x11bd38b, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_12) {
  // -1664813123405809064
  s21_decimal value_1 = {{0x160305a8, 0x171a9ab7, 0x0, 0x80000000}};
  // -1664813123405809064
  s21_decimal value_2 = {{0x160305a8, 0x171a9ab7, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_13) {
  // -79228162514264337593284590484
  s21_decimal value_1 = {{0xf08a7b94, 0xffffffff, 0xffffffff, 0x80000000}};
  // -79228162514264337593284590484
  s21_decimal value_2 = {{0xf08a7b94, 0xffffffff, 0xffffffff, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_14) {
  // -31304042475685431615.457063
  s21_decimal value_1 = {{0x8bac8727, 0x8b011e99, 0x19e4e3, 0x80060000}};
  // -31304042475685431615.457063
  s21_decimal value_2 = {{0x8bac8727, 0x8b011e99, 0x19e4e3, 0x80060000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_15) {
  // -69046497569679606544.8
  s21_decimal value_1 = {{0xf0401ea8, 0x6e205d27, 0x25, 0x80010000}};
  // -69046497569679606544.8
  s21_decimal value_2 = {{0xf0401ea8, 0x6e205d27, 0x25, 0x80010000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_16) {
  // -451745281882883433
  s21_decimal value_1 = {{0xbf968569, 0x644ebf0, 0x0, 0x80000000}};
  // -451745281882883433
  s21_decimal value_2 = {{0xbf968569, 0x644ebf0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_17) {
  // 11779268507906268972
  s21_decimal value_1 = {{0x77b2df2c, 0xa3785e4c, 0x0, 0x0}};
  // 11779268507906268972
  s21_decimal value_2 = {{0x77b2df2c, 0xa3785e4c, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_18) {
  // 91314953.9720764591891
  s21_decimal value_1 = {{0x6ba00f13, 0x807edc4d, 0x31, 0xd0000}};
  // 91314953.9720764591891
  s21_decimal value_2 = {{0x6ba00f13, 0x807edc4d, 0x31, 0xd0000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_19) {
  // 91314953.9720764591891
  s21_decimal value_1 = {{0x6ba00f13, 0x807edc4d, 0x31, 0xd0000}};
  // 91314953.9720764591891
  s21_decimal value_2 = {{0x6ba00f13, 0x807edc4d, 0x31, 0xd0000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_20) {
  // -78113665259.582651
  s21_decimal value_1 = {{0xf5e6b4bb, 0x11583f6, 0x0, 0x80060000}};
  // -78113665259.582651
  s21_decimal value_2 = {{0xf5e6b4bb, 0x11583f6, 0x0, 0x80060000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_21) {
  // -78113665259.582651
  s21_decimal value_1 = {{0xf5e6b4bb, 0x11583f6, 0x0, 0x80060000}};
  // -78113665259.582651
  s21_decimal value_2 = {{0xf5e6b4bb, 0x11583f6, 0x0, 0x80060000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_22) {
  // 574610995979806190498360
  s21_decimal value_1 = {{0x5e7a7238, 0xb9796819, 0x79ad, 0x0}};
  // 574610995979806190498360
  s21_decimal value_2 = {{0x5e7a7238, 0xb9796819, 0x79ad, 0x0}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_23) {
  // -5986349.94663566945788490
  s21_decimal value_1 = {{0x1a3ba24a, 0x116e2661, 0x7ec4, 0x80110000}};
  // -5986349.94663566945788490
  s21_decimal value_2 = {{0x1a3ba24a, 0x116e2661, 0x7ec4, 0x80110000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_24) {
  // 258543.9803714
  s21_decimal value_1 = {{0xf8389942, 0x259, 0x0, 0x70000}};
  // 258543.9803714
  s21_decimal value_2 = {{0xf8389942, 0x259, 0x0, 0x70000}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_false_25) {
  // 12656142843143614
  s21_decimal value_1 = {{0xe26465be, 0x2cf6b1, 0x0, 0x0}};
  // 12656142843143614
  s21_decimal value_2 = {{0xe26465be, 0x2cf6b1, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

Suite *suite_s21_is_not_equal() {
  Suite *suite = suite_create("s21_is_not_equal");

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_is_not_equal_true_1);
  tcase_add_test(testsTrue, s21_is_not_equal_true_2);
  tcase_add_test(testsTrue, s21_is_not_equal_true_3);
  tcase_add_test(testsTrue, s21_is_not_equal_true_4);
  tcase_add_test(testsTrue, s21_is_not_equal_true_5);
  tcase_add_test(testsTrue, s21_is_not_equal_true_6);
  tcase_add_test(testsTrue, s21_is_not_equal_true_7);
  tcase_add_test(testsTrue, s21_is_not_equal_true_8);
  tcase_add_test(testsTrue, s21_is_not_equal_true_9);
  tcase_add_test(testsTrue, s21_is_not_equal_true_10);
  tcase_add_test(testsTrue, s21_is_not_equal_true_11);
  tcase_add_test(testsTrue, s21_is_not_equal_true_12);
  tcase_add_test(testsTrue, s21_is_not_equal_true_13);
  tcase_add_test(testsTrue, s21_is_not_equal_true_14);
  tcase_add_test(testsTrue, s21_is_not_equal_true_15);
  tcase_add_test(testsTrue, s21_is_not_equal_true_16);
  tcase_add_test(testsTrue, s21_is_not_equal_true_17);
  tcase_add_test(testsTrue, s21_is_not_equal_true_18);
  tcase_add_test(testsTrue, s21_is_not_equal_true_19);
  tcase_add_test(testsTrue, s21_is_not_equal_true_20);
  tcase_add_test(testsTrue, s21_is_not_equal_true_21);
  tcase_add_test(testsTrue, s21_is_not_equal_true_22);
  tcase_add_test(testsTrue, s21_is_not_equal_true_23);
  tcase_add_test(testsTrue, s21_is_not_equal_true_24);
  tcase_add_test(testsTrue, s21_is_not_equal_true_25);

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_is_not_equal_false_1);
  tcase_add_test(testsFalse, s21_is_not_equal_false_2);
  tcase_add_test(testsFalse, s21_is_not_equal_false_3);
  tcase_add_test(testsFalse, s21_is_not_equal_false_4);
  tcase_add_test(testsFalse, s21_is_not_equal_false_5);
  tcase_add_test(testsFalse, s21_is_not_equal_false_6);
  tcase_add_test(testsFalse, s21_is_not_equal_false_7);
  tcase_add_test(testsFalse, s21_is_not_equal_false_8);
  tcase_add_test(testsFalse, s21_is_not_equal_false_9);
  tcase_add_test(testsFalse, s21_is_not_equal_false_10);
  tcase_add_test(testsFalse, s21_is_not_equal_false_11);
  tcase_add_test(testsFalse, s21_is_not_equal_false_12);
  tcase_add_test(testsFalse, s21_is_not_equal_false_13);
  tcase_add_test(testsFalse, s21_is_not_equal_false_14);
  tcase_add_test(testsFalse, s21_is_not_equal_false_15);
  tcase_add_test(testsFalse, s21_is_not_equal_false_16);
  tcase_add_test(testsFalse, s21_is_not_equal_false_17);
  tcase_add_test(testsFalse, s21_is_not_equal_false_18);
  tcase_add_test(testsFalse, s21_is_not_equal_false_19);
  tcase_add_test(testsFalse, s21_is_not_equal_false_20);
  tcase_add_test(testsFalse, s21_is_not_equal_false_21);
  tcase_add_test(testsFalse, s21_is_not_equal_false_22);
  tcase_add_test(testsFalse, s21_is_not_equal_false_23);
  tcase_add_test(testsFalse, s21_is_not_equal_false_24);
  tcase_add_test(testsFalse, s21_is_not_equal_false_25);

  suite_add_tcase(suite, testsTrue);
  suite_add_tcase(suite, testsFalse);

  return suite;
}