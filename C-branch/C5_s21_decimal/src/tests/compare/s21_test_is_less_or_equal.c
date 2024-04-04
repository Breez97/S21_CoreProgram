#include "../s21_tests.h"

// Первое значение decimal меньше или равно второму decimal
// Возвращаемое значение 1

START_TEST(s21_is_less_or_equal_true_1) {
  // 79228162514264337593543950333
  s21_decimal value_1 = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_2) {
  // 79228162514264337593543950335
  s21_decimal value_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_3) {
  // 671297938181780.442360392
  s21_decimal value_1 = {{0x8666aa48, 0x2257876b, 0x8e27, 0x90000}};
  // 6282439911676157.5
  s21_decimal value_2 = {{0x4894f9e7, 0xdf3275, 0x0, 0x10000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_4) {
  // -760397
  s21_decimal value_1 = {{0xb9a4d, 0x0, 0x0, 0x80000000}};
  // -0.09
  s21_decimal value_2 = {{0x9, 0x0, 0x0, 0x80020000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_5) {
  // -8.62722936140420703
  s21_decimal value_1 = {{0x843b565f, 0xbf901f0, 0x0, 0x80110000}};
  // -8.62722936140420703
  s21_decimal value_2 = {{0x843b565f, 0xbf901f0, 0x0, 0x80110000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_6) {
  // 2.4893548336153082114
  s21_decimal value_1 = {{0xef6bb902, 0x5977a651, 0x1, 0x130000}};
  // 279090148310.5874
  s21_decimal value_2 = {{0x6380ee52, 0x9ea4f, 0x0, 0x40000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_7) {
  // -650
  s21_decimal value_1 = {{0x28a, 0x0, 0x0, 0x80000000}};
  // 32383656402822
  s21_decimal value_2 = {{0xe8561f86, 0x1d73, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_8) {
  // -78.3909904528898578867138
  s21_decimal value_1 = {{0xf25263c2, 0xd750c45a, 0xa5ff, 0x80160000}};
  // 1538164340947367928.248
  s21_decimal value_2 = {{0x34b2a1b8, 0x62517e8c, 0x53, 0x30000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_9) {
  // 5223838232926722583
  s21_decimal value_1 = {{0x1db39a17, 0x487ecd32, 0x0, 0x0}};
  // 9542823849247110219621
  s21_decimal value_2 = {{0xb3d24765, 0x5148d2d7, 0x205, 0x0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_10) {
  // 8015.017344751544361920
  s21_decimal value_1 = {{0x6e60e3c0, 0x7eb5c1ab, 0x1b2, 0x120000}};
  // 39468393846217904732640171809
  s21_decimal value_2 = {{0xc3fcd721, 0xa10fdd5a, 0x7f877d7d, 0x0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_11) {
  // -43.341160869472316858416799455
  s21_decimal value_1 = {{0xeed09edf, 0xa2e34ff2, 0x8c0af7ce, 0x801b0000}};
  // -43.341160869472316858416799455
  s21_decimal value_2 = {{0xeed09edf, 0xa2e34ff2, 0x8c0af7ce, 0x801b0000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_12) {
  // -3183133160375.283
  s21_decimal value_1 = {{0xf14c03f3, 0xb4f0a, 0x0, 0x80030000}};
  // 9894.031
  s21_decimal value_2 = {{0x96f88f, 0x0, 0x0, 0x30000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_13) {
  // 5.30386116
  s21_decimal value_1 = {{0x1f9d0cc4, 0x0, 0x0, 0x80000}};
  // 45395483951304234870094510
  s21_decimal value_2 = {{0xf04dbaae, 0x1db59131, 0x258cde, 0x0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_14) {
  // -97485488281885424113
  s21_decimal value_1 = {{0x954939f1, 0x48e20717, 0x5, 0x80000000}};
  // 217469988069574
  s21_decimal value_2 = {{0xad6360c6, 0xc5c9, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_15) {
  // -80
  s21_decimal value_1 = {{0x50, 0x0, 0x0, 0x80000000}};
  // 38.159300137020105627777356
  s21_decimal value_2 = {{0xb797b94c, 0xce323ec2, 0x1f908b, 0x180000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_16) {
  // 8765185246503754606688809
  s21_decimal value_1 = {{0x1c85ba29, 0xa4f27967, 0x74019, 0x0}};
  // 8765185246503754606688809
  s21_decimal value_2 = {{0x1c85ba29, 0xa4f27967, 0x74019, 0x0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_17) {
  // -0.06
  s21_decimal value_1 = {{0x6, 0x0, 0x0, 0x80020000}};
  // 0.2428117212044074
  s21_decimal value_2 = {{0x17e59b2a, 0x8a05c, 0x0, 0x100000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_18) {
  // 1.3371733414988689453397098
  s21_decimal value_1 = {{0xc4e0b46a, 0x1ef4b43c, 0xb0f93, 0x190000}};
  // 69710539993778352430177
  s21_decimal value_2 = {{0x3c161c61, 0x414fe12, 0xec3, 0x0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_19) {
  // -11748
  s21_decimal value_1 = {{0x2de4, 0x0, 0x0, 0x80000000}};
  // 4
  s21_decimal value_2 = {{0x4, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_20) {
  // -292781203
  s21_decimal value_1 = {{0x11737c93, 0x0, 0x0, 0x80000000}};
  // 90899712569200707.96607
  s21_decimal value_2 = {{0xdfd9b53f, 0xc4b1396f, 0x1ec, 0x50000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_21) {
  // -0.8
  s21_decimal value_1 = {{0x8, 0x0, 0x0, 0x80010000}};
  // -0.7
  s21_decimal value_2 = {{0x7, 0x0, 0x0, 0x80010000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_22) {
  // -53509970729398940
  s21_decimal value_1 = {{0xed44729c, 0xbe1b08, 0x0, 0x80000000}};
  // 5.6761382
  s21_decimal value_2 = {{0x3621c26, 0x0, 0x0, 0x70000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_23) {
  // -8008372116239
  s21_decimal value_1 = {{0x982cdb0f, 0x748, 0x0, 0x80000000}};
  // 92914530941818097
  s21_decimal value_2 = {{0xb4254f1, 0x14a1946, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_24) {
  // 5847.559811
  s21_decimal value_1 = {{0x5c8aae83, 0x1, 0x0, 0x60000}};
  // 5847.559811
  s21_decimal value_2 = {{0x5c8aae83, 0x1, 0x0, 0x60000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_true_25) {
  // 3084.1416
  s21_decimal value_1 = {{0x1d69a48, 0x0, 0x0, 0x40000}};
  // 59384
  s21_decimal value_2 = {{0xe7f8, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

// Первое значение decimal больше или равно второму decimal
// Возвращаемое значение 0

START_TEST(s21_is_less_or_equal_false_1) {
  // 5662188.8474169766103383
  s21_decimal value_1 = {{0x9198c957, 0x7a8db3a2, 0xbfd, 0x100000}};
  // 5284
  s21_decimal value_2 = {{0x14a4, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_2) {
  // 37789299803665
  s21_decimal value_1 = {{0x81ca8611, 0x225e, 0x0, 0x0}};
  // -606580.4
  s21_decimal value_2 = {{0x5c8e8c, 0x0, 0x0, 0x80010000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_3) {
  // -8455.86803
  s21_decimal value_1 = {{0x3266a173, 0x0, 0x0, 0x80050000}};
  // -920847422732692393
  s21_decimal value_2 = {{0x2450eba9, 0xcc781da, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_4) {
  // 5700239039331789561847629
  s21_decimal value_1 = {{0xa12df4d, 0x93d77778, 0x4b712, 0x0}};
  // 4.9
  s21_decimal value_2 = {{0x31, 0x0, 0x0, 0x10000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_5) {
  // -6902955.8927175779
  s21_decimal value_1 = {{0xa2db3063, 0xf53e04, 0x0, 0x800a0000}};
  // -7392647505096613868716936775
  s21_decimal value_2 = {{0xf7e3ce47, 0x45b322d0, 0x17e30e00, 0x80000000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_6) {
  // -130652419.353057571
  s21_decimal value_1 = {{0xe4959923, 0x1d02bae, 0x0, 0x80090000}};
  // -38724675889991652
  s21_decimal value_2 = {{0x36770fe4, 0x8993e3, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_7) {
  // -52540716338.5
  s21_decimal value_1 = {{0x54b513f9, 0x7a, 0x0, 0x80010000}};
  // -1824600891181175727461
  s21_decimal value_2 = {{0x2324e565, 0xe96c8b61, 0x62, 0x80000000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_8) {
  // 43
  s21_decimal value_1 = {{0x2b, 0x0, 0x0, 0x0}};
  // 22.110566648577548297
  s21_decimal value_2 = {{0x57106009, 0x32d88338, 0x1, 0x120000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_9) {
  // 3157141520
  s21_decimal value_1 = {{0xbc2e2810, 0x0, 0x0, 0x0}};
  // -7750270148351061.34989
  s21_decimal value_2 = {{0x31e6bbcd, 0x3a913b9, 0x2a, 0x80050000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_10) {
  // 72537931034637995.68939799
  s21_decimal value_1 = {{0xfc4f3b17, 0xe97ddd54, 0x6000c, 0x80000}};
  // 645062.43
  s21_decimal value_2 = {{0x3d84983, 0x0, 0x0, 0x20000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_11) {
  // 9727376631068080600832538
  s21_decimal value_1 = {{0x218cda1a, 0x24d00a37, 0x80bda, 0x0}};
  // 255661836
  s21_decimal value_2 = {{0xf3d170c, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_12) {
  // 544
  s21_decimal value_1 = {{0x220, 0x0, 0x0, 0x0}};
  // -687030337085
  s21_decimal value_2 = {{0xf632fe3d, 0x9f, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_13) {
  // 19019851329686975
  s21_decimal value_1 = {{0x3a2fcdbf, 0x439274, 0x0, 0x0}};
  // -79.87581328640320603
  s21_decimal value_2 = {{0xfc26245b, 0x6ed996e5, 0x0, 0x80110000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_14) {
  // -906770005883452979961.1395434
  s21_decimal value_1 = {{0x5978ad6a, 0x29698a84, 0x1d4ca02d, 0x80070000}};
  // -1304808725498790238461437296
  s21_decimal value_2 = {{0x14212570, 0xbe41ccd0, 0x4374ffe, 0x80000000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_15) {
  // 58799610152292172
  s21_decimal value_1 = {{0x140f0f4c, 0xd0e5ef, 0x0, 0x0}};
  // -0.25500422679717989009
  s21_decimal value_2 = {{0xf6e7ca91, 0x61e3b351, 0x1, 0x80140000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_16) {
  // 72198290912663659430217
  s21_decimal value_1 = {{0xce6d4149, 0xe08fb620, 0xf49, 0x0}};
  // 61.221
  s21_decimal value_2 = {{0xef25, 0x0, 0x0, 0x30000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_17) {
  // -0.45454043899503496
  s21_decimal value_1 = {{0x4c3c2388, 0xa17c36, 0x0, 0x80110000}};
  // -1152444306
  s21_decimal value_2 = {{0x44b0e792, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_18) {
  // 4487330484741.42866
  s21_decimal value_1 = {{0x81478892, 0x63a3854, 0x0, 0x50000}};
  // -7333390
  s21_decimal value_2 = {{0x6fe60e, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_19) {
  // 303508632824663479131.18
  s21_decimal value_1 = {{0x3cf58f9e, 0x52d725a3, 0x66d, 0x20000}};
  // 0.63
  s21_decimal value_2 = {{0x3f, 0x0, 0x0, 0x20000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_20) {
  // 35.24205
  s21_decimal value_1 = {{0x35c66d, 0x0, 0x0, 0x50000}};
  // 5
  s21_decimal value_2 = {{0x5, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_21) {
  // 73.767005848854706741222091
  s21_decimal value_1 = {{0xec8e9acb, 0x666361f6, 0x3d04c5, 0x180000}};
  // -94798394133424161.498584
  s21_decimal value_2 = {{0x5db925d8, 0x7ff90ee, 0x1413, 0x80060000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_22) {
  // 440776807403583374866691742
  s21_decimal value_1 = {{0x296ab69e, 0x9bc0b97d, 0x16c9a1e, 0x0}};
  // 565.2450
  s21_decimal value_2 = {{0x563fe2, 0x0, 0x0, 0x40000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_23) {
  // 5918342461679.932212334
  s21_decimal value_1 = {{0xf743046e, 0xd580382c, 0x140, 0x90000}};
  // -7339249
  s21_decimal value_2 = {{0x6ffcf1, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_24) {
  // 314171366554001687388914
  s21_decimal value_1 = {{0x59f22f2, 0x438f71a0, 0x4287, 0x0}};
  // -974994072616139703.033
  s21_decimal value_2 = {{0xec6b42f9, 0xdac2c74d, 0x34, 0x80030000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_false_25) {
  // 5270778521664449986
  s21_decimal value_1 = {{0xc1916dc2, 0x49259123, 0x0, 0x0}};
  // -0.985496715270579
  s21_decimal value_2 = {{0xd5a419b3, 0x3804d, 0x0, 0x800f0000}};

  ck_assert_int_eq(s21_is_less_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

Suite *suite_s21_is_less_or_equal() {
  Suite *suite = suite_create("s21_is_less_or_equal");

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_1);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_2);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_3);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_4);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_5);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_6);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_7);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_8);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_9);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_10);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_11);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_12);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_13);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_14);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_15);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_16);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_17);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_18);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_19);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_20);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_21);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_22);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_23);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_24);
  tcase_add_test(testsTrue, s21_is_less_or_equal_true_25);

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_1);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_2);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_3);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_4);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_5);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_6);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_7);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_8);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_9);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_10);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_11);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_12);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_13);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_14);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_15);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_16);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_17);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_18);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_19);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_20);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_21);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_22);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_23);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_24);
  tcase_add_test(testsFalse, s21_is_less_or_equal_false_25);

  suite_add_tcase(suite, testsTrue);
  suite_add_tcase(suite, testsFalse);

  return suite;
}