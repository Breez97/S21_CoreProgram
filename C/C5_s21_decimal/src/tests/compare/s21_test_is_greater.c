#include "../s21_tests.h"

// Первое значение decimal больше второго decimal
// Возвращаемое значение 1

START_TEST(s21_is_greater_true_1) {
  // 79228162514264337593543950335
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal value_2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_2) {
  // 167931024233
  s21_decimal value_1 = {{0x19781369, 0x27, 0x0, 0x0}};
  // 1
  s21_decimal value_2 = {{0x1, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_3) {
  // 696.3
  s21_decimal value_1 = {{0x1b33, 0x0, 0x0, 0x10000}};
  // -8
  s21_decimal value_2 = {{0x8, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_4) {
  // -0.774956041933
  s21_decimal value_1 = {{0x6efac6cd, 0xb4, 0x0, 0x800c0000}};
  // -413608233
  s21_decimal value_2 = {{0x18a72929, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_5) {
  // 0.0359795
  s21_decimal value_1 = {{0x57d73, 0x0, 0x0, 0x70000}};
  // -10730117211885071
  s21_decimal value_2 = {{0x18d00e0f, 0x261efc, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_6) {
  // 655278660872346694091961360
  s21_decimal value_1 = {{0x84e67410, 0x629342bc, 0x21e08a7, 0x0}};
  // -2.2814151
  s21_decimal value_2 = {{0x15c1dc7, 0x0, 0x0, 0x80070000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_7) {
  // -6.5781804
  s21_decimal value_1 = {{0x3ebc02c, 0x0, 0x0, 0x80070000}};
  // -50.973275730328751
  s21_decimal value_2 = {{0x98f1bcaf, 0xb517ec, 0x0, 0x800f0000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_8) {
  // 3656275731.64
  s21_decimal value_1 = {{0x211a03ac, 0x55, 0x0, 0x20000}};
  // 90430
  s21_decimal value_2 = {{0x1613e, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_9) {
  // -640425158.481148
  s21_decimal value_1 = {{0x9a1394fc, 0x24676, 0x0, 0x80060000}};
  // -59203305808399
  s21_decimal value_2 = {{0x5803220f, 0x35d8, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_10) {
  // 590517782.9621065767151
  s21_decimal value_1 = {{0x3bced8ef, 0x1ece0d11, 0x140, 0xd0000}};
  // 672513
  s21_decimal value_2 = {{0xa4301, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_11) {
  // 228329771480525416
  s21_decimal value_1 = {{0xa8be2a68, 0x32b30b7, 0x0, 0x0}};
  // -7630015.3639029698172577
  s21_decimal value_2 = {{0x6d7b96a1, 0x3d578728, 0x1028, 0x80100000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_12) {
  // -7950743227851.982844378011
  s21_decimal value_1 = {{0x32cabb9b, 0xa76e385e, 0x693a2, 0x800c0000}};
  // -5525917437759431692
  s21_decimal value_2 = {{0xcfc9a40c, 0x4cb000a1, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_13) {
  // 4101154010263923889898388
  s21_decimal value_1 = {{0xcbd8394, 0x11f21d6, 0x36474, 0x0}};
  // 577.916
  s21_decimal value_2 = {{0x8d17c, 0x0, 0x0, 0x30000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_14) {
  // 1604554
  s21_decimal value_1 = {{0x187bca, 0x0, 0x0, 0x0}};
  // -59
  s21_decimal value_2 = {{0x3b, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_15) {
  // 6116212512550073460423135
  s21_decimal value_1 = {{0xc78579df, 0x8b6fc994, 0x50f28, 0x0}};
  // 407245694.8258996645843011
  s21_decimal value_2 = {{0xd544d043, 0x556267e7, 0x35e60, 0x100000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_16) {
  // 752922063620.4165670938
  s21_decimal value_1 = {{0x69e6a81a, 0x28ed251b, 0x198, 0xa0000}};
  // -30735198194373688051374659229
  s21_decimal value_2 = {{0xff86969d, 0xb4a3dbe0, 0x634f8f60, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_17) {
  // 813780.57
  s21_decimal value_1 = {{0x4d9bb09, 0x0, 0x0, 0x20000}};
  // -17150266719826989
  s21_decimal value_2 = {{0xa3a3742d, 0x3cee13, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_18) {
  // 337911872980032096505368
  s21_decimal value_1 = {{0x829b0e18, 0x3d455d81, 0x478e, 0x0}};
  // -8102506
  s21_decimal value_2 = {{0x7ba26a, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_19) {
  // 6.7393420075624226526
  s21_decimal value_1 = {{0x3e42dede, 0xa745867e, 0x3, 0x130000}};
  // -2704908028.401938203
  s21_decimal value_2 = {{0x46ffef1b, 0x2589c385, 0x0, 0x80090000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_20) {
  // 790493637405673591946598374
  s21_decimal value_1 = {{0x9aafd7e6, 0xf357e65f, 0x28de189, 0x0}};
  // -5707098
  s21_decimal value_2 = {{0x57155a, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_21) {
  // -177.3
  s21_decimal value_1 = {{0x6ed, 0x0, 0x0, 0x80010000}};
  // -56556842728
  s21_decimal value_2 = {{0x2b0ceee8, 0xd, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_22) {
  // 7906
  s21_decimal value_1 = {{0x1ee2, 0x0, 0x0, 0x0}};
  // -416021475245015521
  s21_decimal value_2 = {{0xdae9c1e1, 0x5c60153, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_23) {
  // 81
  s21_decimal value_1 = {{0x51, 0x0, 0x0, 0x0}};
  // -19249866724606.27348146
  s21_decimal value_2 = {{0x20ea8ab2, 0x5a8e7b96, 0x68, 0x80080000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_24) {
  // 915026926793025
  s21_decimal value_1 = {{0x4eee7141, 0x34036, 0x0, 0x0}};
  // -52939627634553217718387460
  s21_decimal value_2 = {{0x5ffb8304, 0xf6efe1d9, 0x2bca66, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_true_25) {
  // 440111598894425.66
  s21_decimal value_1 = {{0xaf5cf706, 0x9c5bea, 0x0, 0x20000}};
  // -1517892132464
  s21_decimal value_2 = {{0x696bde70, 0x161, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

// Первое значение decimal меньше или равно второму decimal
// Возвращаемое значение 0

START_TEST(s21_is_greater_false_1) {
  // 0.2
  s21_decimal value_1 = {{0x2, 0x0, 0x0, 0x10000}};
  // 0.2
  s21_decimal value_2 = {{0x2, 0x0, 0x0, 0x10000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_2) {
  // -9836116197786596483470762
  s21_decimal value_1 = {{0x158b15aa, 0xed7225ca, 0x822e0, 0x80000000}};
  // 210121230
  s21_decimal value_2 = {{0xc86320e, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_3) {
  // -936642649
  s21_decimal value_1 = {{0x37d40859, 0x0, 0x0, 0x80000000}};
  // 66260596842433657012542983
  s21_decimal value_2 = {{0xea60de07, 0x26ff996d, 0x36cf3a, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_4) {
  // -311871234818864
  s21_decimal value_1 = {{0x2e2ac330, 0x11ba5, 0x0, 0x80000000}};
  // 200551419614117442542564470
  s21_decimal value_2 = {{0x582af476, 0x3df5ef22, 0xa5e46a, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_5) {
  // 190679144
  s21_decimal value_1 = {{0xb5d8868, 0x0, 0x0, 0x0}};
  // 10406665755517768453523
  s21_decimal value_2 = {{0xe2b04d93, 0x257fc7c3, 0x234, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_6) {
  // 6968965
  s21_decimal value_1 = {{0x6a5685, 0x0, 0x0, 0x0}};
  // 6968965
  s21_decimal value_2 = {{0x6a5685, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_7) {
  // -6351
  s21_decimal value_1 = {{0x18cf, 0x0, 0x0, 0x80000000}};
  // 5.9321181668576
  s21_decimal value_2 = {{0xc9f604e0, 0x35f3, 0x0, 0xd0000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_8) {
  // -9062.172
  s21_decimal value_1 = {{0x8a471c, 0x0, 0x0, 0x80030000}};
  // -74
  s21_decimal value_2 = {{0x4a, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_9) {
  // -8
  s21_decimal value_1 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 4109260.23
  s21_decimal value_2 = {{0x187e3bc7, 0x0, 0x0, 0x20000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_10) {
  // 4.32565
  s21_decimal value_1 = {{0x699b5, 0x0, 0x0, 0x50000}};
  // 15
  s21_decimal value_2 = {{0xf, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_11) {
  // -8685.495665519909
  s21_decimal value_1 = {{0x8bd76d25, 0x1edb69, 0x0, 0x800c0000}};
  // 56742037096
  s21_decimal value_2 = {{0x3616c668, 0xd, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_12) {
  // -1798252212.9
  s21_decimal value_1 = {{0x2fd78311, 0x4, 0x0, 0x80010000}};
  // 0.4
  s21_decimal value_2 = {{0x4, 0x0, 0x0, 0x10000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_13) {
  // 597
  s21_decimal value_1 = {{0x255, 0x0, 0x0, 0x0}};
  // 178558530
  s21_decimal value_2 = {{0xaa49642, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_14) {
  // -1879219778469144057879572003
  s21_decimal value_1 = {{0xd62dae23, 0x51d7c671, 0x6127444, 0x80000000}};
  // 19017
  s21_decimal value_2 = {{0x4a49, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_15) {
  // -7449959481310.80286135219249
  s21_decimal value_1 = {{0x72557431, 0x45d83cc7, 0x2683f07, 0x800e0000}};
  // -7449959481310.80286135219249
  s21_decimal value_2 = {{0x72557431, 0x45d83cc7, 0x2683f07, 0x800e0000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_16) {
  // -777647344.3942386
  s21_decimal value_1 = {{0x513b3ff2, 0x1ba0a9, 0x0, 0x80070000}};
  // 834454723792
  s21_decimal value_2 = {{0x49609cd0, 0xc2, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_17) {
  // -19754693
  s21_decimal value_1 = {{0x12d6ec5, 0x0, 0x0, 0x80000000}};
  // 22426363634575480760095307434
  s21_decimal value_2 = {{0xdd1576aa, 0xad866ddc, 0x4876a738, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_18) {
  // 95693591036
  s21_decimal value_1 = {{0x47c851fc, 0x16, 0x0, 0x0}};
  // 32707157933587963736313476.8
  s21_decimal value_2 = {{0x24dd1130, 0xd7fd767d, 0x10e8c19, 0x10000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_19) {
  // -185934466767255680071324
  s21_decimal value_1 = {{0x2c10369c, 0x871371cb, 0x275f, 0x80000000}};
  // 547913447009036
  s21_decimal value_2 = {{0xa606b0c, 0x1f253, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_20) {
  // 56710516124.03946495920331991
  s21_decimal value_1 = {{0xb1885cd7, 0xec1b2323, 0x1252fbe3, 0x110000}};
  // 63834403509232655
  s21_decimal value_2 = {{0x419de40f, 0xe2c90d, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_21) {
  // 4
  s21_decimal value_1 = {{0x4, 0x0, 0x0, 0x0}};
  // 354952140329520.603885
  s21_decimal value_2 = {{0x3dae22ed, 0x3df35303, 0x13, 0x60000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_22) {
  // 9.8
  s21_decimal value_1 = {{0x62, 0x0, 0x0, 0x10000}};
  // 7281347417795
  s21_decimal value_2 = {{0x522056c3, 0x69f, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_23) {
  // -459.35908561321504
  s21_decimal value_1 = {{0x283b7e20, 0xa33277, 0x0, 0x800e0000}};
  // -459.35908561321504
  s21_decimal value_2 = {{0x283b7e20, 0xa33277, 0x0, 0x800e0000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_24) {
  // -9348190108500557003411412.22
  s21_decimal value_1 = {{0x3e92ee6, 0x1f49bf2d, 0x30543a0, 0x80020000}};
  // 4004.98
  s21_decimal value_2 = {{0x61c72, 0x0, 0x0, 0x20000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_false_25) {
  // -74191950775290963
  s21_decimal value_1 = {{0xa7278c53, 0x107952f, 0x0, 0x80000000}};
  // 4118914333729.955616483390
  s21_decimal value_2 = {{0x2435683e, 0xcb1f3ff7, 0x36836, 0xc0000}};

  ck_assert_int_eq(s21_is_greater(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

Suite *suite_s21_is_greater() {
  Suite *suite = suite_create("s21_is_greater");

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_is_greater_true_1);
  tcase_add_test(testsTrue, s21_is_greater_true_2);
  tcase_add_test(testsTrue, s21_is_greater_true_3);
  tcase_add_test(testsTrue, s21_is_greater_true_4);
  tcase_add_test(testsTrue, s21_is_greater_true_5);
  tcase_add_test(testsTrue, s21_is_greater_true_6);
  tcase_add_test(testsTrue, s21_is_greater_true_7);
  tcase_add_test(testsTrue, s21_is_greater_true_8);
  tcase_add_test(testsTrue, s21_is_greater_true_9);
  tcase_add_test(testsTrue, s21_is_greater_true_10);
  tcase_add_test(testsTrue, s21_is_greater_true_11);
  tcase_add_test(testsTrue, s21_is_greater_true_12);
  tcase_add_test(testsTrue, s21_is_greater_true_13);
  tcase_add_test(testsTrue, s21_is_greater_true_14);
  tcase_add_test(testsTrue, s21_is_greater_true_15);
  tcase_add_test(testsTrue, s21_is_greater_true_16);
  tcase_add_test(testsTrue, s21_is_greater_true_17);
  tcase_add_test(testsTrue, s21_is_greater_true_18);
  tcase_add_test(testsTrue, s21_is_greater_true_19);
  tcase_add_test(testsTrue, s21_is_greater_true_20);
  tcase_add_test(testsTrue, s21_is_greater_true_21);
  tcase_add_test(testsTrue, s21_is_greater_true_22);
  tcase_add_test(testsTrue, s21_is_greater_true_23);
  tcase_add_test(testsTrue, s21_is_greater_true_24);
  tcase_add_test(testsTrue, s21_is_greater_true_25);

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_is_greater_false_1);
  tcase_add_test(testsFalse, s21_is_greater_false_2);
  tcase_add_test(testsFalse, s21_is_greater_false_3);
  tcase_add_test(testsFalse, s21_is_greater_false_4);
  tcase_add_test(testsFalse, s21_is_greater_false_5);
  tcase_add_test(testsFalse, s21_is_greater_false_6);
  tcase_add_test(testsFalse, s21_is_greater_false_7);
  tcase_add_test(testsFalse, s21_is_greater_false_8);
  tcase_add_test(testsFalse, s21_is_greater_false_9);
  tcase_add_test(testsFalse, s21_is_greater_false_10);
  tcase_add_test(testsFalse, s21_is_greater_false_11);
  tcase_add_test(testsFalse, s21_is_greater_false_12);
  tcase_add_test(testsFalse, s21_is_greater_false_13);
  tcase_add_test(testsFalse, s21_is_greater_false_14);
  tcase_add_test(testsFalse, s21_is_greater_false_15);
  tcase_add_test(testsFalse, s21_is_greater_false_16);
  tcase_add_test(testsFalse, s21_is_greater_false_17);
  tcase_add_test(testsFalse, s21_is_greater_false_18);
  tcase_add_test(testsFalse, s21_is_greater_false_19);
  tcase_add_test(testsFalse, s21_is_greater_false_20);
  tcase_add_test(testsFalse, s21_is_greater_false_21);
  tcase_add_test(testsFalse, s21_is_greater_false_22);
  tcase_add_test(testsFalse, s21_is_greater_false_23);
  tcase_add_test(testsFalse, s21_is_greater_false_24);
  tcase_add_test(testsFalse, s21_is_greater_false_25);

  suite_add_tcase(suite, testsTrue);
  suite_add_tcase(suite, testsFalse);

  return suite;
}