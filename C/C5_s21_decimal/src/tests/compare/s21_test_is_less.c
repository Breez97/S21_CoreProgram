#include "../s21_tests.h"

// Первое значение decimal меньше второго decimal
// Возвращаемое значение 1

START_TEST(s21_is_less_true_1) {
  // 79228162514264337593543950334
  s21_decimal value_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_2) {
  // -10838969560289932153433702002
  s21_decimal value_1 = {{0xd2c13e72, 0x3d104af5, 0x2305c915, 0x80000000}};
  // 1078631865179277896361383704
  s21_decimal value_2 = {{0x4bf71718, 0x93b484b0, 0x37c392e, 0x0}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_3) {
  // 294.23994809988339
  s21_decimal value_1 = {{0xa685b4f3, 0x6888f7, 0x0, 0xe0000}};
  // 96504010.837069050202
  s21_decimal value_2 = {{0x5ff2b15a, 0x3b431e8e, 0x5, 0xc0000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_4) {
  // -96787669.55610703938434
  s21_decimal value_1 = {{0xa4f84382, 0xafdfc1d2, 0x20c, 0x800e0000}};
  // 261775241217709168659250
  s21_decimal value_2 = {{0x35640b32, 0xdd403ed6, 0x376e, 0x0}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_5) {
  // -585276396.45191579740673
  s21_decimal value_1 = {{0xb181aa01, 0xca29f493, 0xc64, 0x800e0000}};
  // 4587358643723
  s21_decimal value_2 = {{0x13e1e60b, 0x42c, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_6) {
  // 6289364.074381225553
  s21_decimal value_1 = {{0x9c98ae51, 0x57484f4d, 0x0, 0xc0000}};
  // 964109555900.59388227715
  s21_decimal value_2 = {{0x2ae2d083, 0x72c8b606, 0x146a, 0xb0000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_7) {
  // 23210
  s21_decimal value_1 = {{0x5aaa, 0x0, 0x0, 0x0}};
  // 8704937.81
  s21_decimal value_2 = {{0x33e2ae55, 0x0, 0x0, 0x20000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_8) {
  // 9591501.275220
  s21_decimal value_1 = {{0x3206c054, 0x8b9, 0x0, 0x60000}};
  // 76693610059202177588.7
  s21_decimal value_2 = {{0x3ab5a60f, 0x93606016, 0x29, 0x10000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_9) {
  // -28544354812417437438
  s21_decimal value_1 = {{0xa8da6efe, 0x8c21eb77, 0x1, 0x80000000}};
  // 7093902794275115773630
  s21_decimal value_2 = {{0xf3c2ebe, 0x8fad7e49, 0x180, 0x0}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_10) {
  // 84509321910589058
  s21_decimal value_1 = {{0xd0b09682, 0x12c3cc7, 0x0, 0x0}};
  // 1067656652183596071
  s21_decimal value_2 = {{0x877c6c27, 0xed11411, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_11) {
  // -343096688491
  s21_decimal value_1 = {{0xe227ff6b, 0x4f, 0x0, 0x80000000}};
  // -21.013306
  s21_decimal value_2 = {{0x140a33a, 0x0, 0x0, 0x80060000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_12) {
  // -3666150533.3568702
  s21_decimal value_1 = {{0xe256a4be, 0x823f71, 0x0, 0x80070000}};
  // -5158011
  s21_decimal value_2 = {{0x4eb47b, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_13) {
  // 0.03151268721271354646423731
  s21_decimal value_1 = {{0x306d68b3, 0x9ea3a30c, 0x29b4e, 0x1a0000}};
  // 0.294189254067
  s21_decimal value_2 = {{0x7f0bc5b3, 0x44, 0x0, 0xc0000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_14) {
  // -5649173542964115
  s21_decimal value_1 = {{0xb64d8b93, 0x1411e4, 0x0, 0x80000000}};
  // -98600357034388.0
  s21_decimal value_2 = {{0xd88ebfc8, 0x380c3, 0x0, 0x80010000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_15) {
  // 89258785612096188766520674
  s21_decimal value_1 = {{0x3bb08562, 0x76b53729, 0x49d548, 0x0}};
  // 98966615577344912182004965
  s21_decimal value_2 = {{0x5678cce5, 0xfb0a3958, 0x51dcfe, 0x0}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_16) {
  // 8.3384405
  s21_decimal value_1 = {{0x4f85855, 0x0, 0x0, 0x70000}};
  // 604932607867787.6
  s21_decimal value_2 = {{0x7c0cd374, 0x157dd4, 0x0, 0x10000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_17) {
  // -61257308210594768907042094
  s21_decimal value_1 = {{0xd8327d2e, 0x5506473c, 0x32abbd, 0x80000000}};
  // 248.778539267673851358023375
  s21_decimal value_2 = {{0x13a70ecf, 0xa31845bf, 0xcdc8e7, 0x180000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_18) {
  // 275722514047056
  s21_decimal value_1 = {{0xa681a050, 0xfac4, 0x0, 0x0}};
  // 7721771596396205
  s21_decimal value_2 = {{0xd0a36ad, 0x1b6ee9, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_19) {
  // -77665351631192428.141055571
  s21_decimal value_1 = {{0x8cff8e53, 0x25f4fcf6, 0x403e47, 0x80090000}};
  // 16982746619699176293.64729127
  s21_decimal value_2 = {{0x4e207527, 0xe634d2bf, 0x57cc7a5, 0x80000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_20) {
  // -1765896999117070121.38670
  s21_decimal value_1 = {{0x6dac86ae, 0xf262695e, 0x2564, 0x80050000}};
  // -69972289703160287
  s21_decimal value_2 = {{0x3fe0a9df, 0xf8976d, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_21) {
  // -6523046879
  s21_decimal value_1 = {{0x84cdcbdf, 0x1, 0x0, 0x80000000}};
  // 6399323865592366505.1230394
  s21_decimal value_2 = {{0xe7bea0ba, 0x6b33a51d, 0x34ef18, 0x70000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_22) {
  // 0.797883
  s21_decimal value_1 = {{0xc2cbb, 0x0, 0x0, 0x60000}};
  // 74028.83
  s21_decimal value_2 = {{0x70f583, 0x0, 0x0, 0x20000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_23) {
  // 29036834875
  s21_decimal value_1 = {{0xc2baf03b, 0x6, 0x0, 0x0}};
  // 3961903445724608181751
  s21_decimal value_2 = {{0x8b61b5f7, 0xc67490d2, 0xd6, 0x0}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_24) {
  // 57071869357834.14771061
  s21_decimal value_1 = {{0x688b2d75, 0x6321181f, 0x135, 0x80000}};
  // 230088047126047346310
  s21_decimal value_2 = {{0x6b63ce86, 0x791cf3cd, 0xc, 0x0}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_true_25) {
  // -54158965055
  s21_decimal value_1 = {{0x9c20393f, 0xc, 0x0, 0x80000000}};
  // -25603.38487010165
  s21_decimal value_2 = {{0x4205e375, 0x9189d, 0x0, 0x800b0000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

// Первое значение decimal больше или равно второму decimal
// Возвращаемое значение 0

START_TEST(s21_is_less_false_1) {
  // 96433
  s21_decimal value_1 = {{0x178b1, 0x0, 0x0, 0x0}};
  // -694219235357647195379
  s21_decimal value_2 = {{0x37dc4cf3, 0xa23a2c6d, 0x25, 0x80000000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_2) {
  // 2969071535152209774433
  s21_decimal value_1 = {{0xdf2ec761, 0xf4250e67, 0xa0, 0x0}};
  // -41564290716593
  s21_decimal value_2 = {{0x70c893b1, 0x25cd, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_3) {
  // 73293076177073802006645168738
  s21_decimal value_1 = {{0xf66fda62, 0xf76938d4, 0xecd29c94, 0x0}};
  // 932349085751781565619504010
  s21_decimal value_2 = {{0x7c4038a, 0x36df7edf, 0x3033899, 0x0}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_4) {
  // 24600.961911
  s21_decimal value_1 = {{0xba54e377, 0x5, 0x0, 0x60000}};
  // 388
  s21_decimal value_2 = {{0x184, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_5) {
  // 363777247384847126515
  s21_decimal value_1 = {{0x3f360ff3, 0xb86c671f, 0x13, 0x0}};
  // 0.7661162479
  s21_decimal value_2 = {{0xc8a40fef, 0x1, 0x0, 0xa0000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_6) {
  // 803902105991660.9797
  s21_decimal value_1 = {{0xba36b905, 0x6f90570f, 0x0, 0x40000}};
  // -43593.82882694843284
  s21_decimal value_2 = {{0x82f1cb94, 0x3c7fa3a2, 0x0, 0x800e0000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_7) {
  // 441579804024130940347
  s21_decimal value_1 = {{0x7ceeadbb, 0xf0269c2b, 0x17, 0x0}};
  // -164908.4627236
  s21_decimal value_2 = {{0xf51a7924, 0x17f, 0x0, 0x80070000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_8) {
  // 6.118502
  s21_decimal value_1 = {{0x5d5c66, 0x0, 0x0, 0x60000}};
  // -42009
  s21_decimal value_2 = {{0xa419, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_9) {
  // -6100098
  s21_decimal value_1 = {{0x5d1482, 0x0, 0x0, 0x80000000}};
  // -818122261284707.97981
  s21_decimal value_2 = {{0x3f6eee9d, 0x6f5f6a34, 0x4, 0x80050000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_10) {
  // 57742901909979960
  s21_decimal value_1 = {{0x4a50338, 0xcd24dd, 0x0, 0x0}};
  // 1539.6
  s21_decimal value_2 = {{0x3c24, 0x0, 0x0, 0x10000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_11) {
  // 7000819747888305444
  s21_decimal value_1 = {{0x16c1524, 0x6127e878, 0x0, 0x0}};
  // -6349.760120914189341
  s21_decimal value_2 = {{0x81c1d, 0x581ee130, 0x0, 0x800f0000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_12) {
  // 6429094507051211512825263089
  s21_decimal value_1 = {{0xfd2833f1, 0x953e00b1, 0x14c605b7, 0x0}};
  // -8670261
  s21_decimal value_2 = {{0x844c35, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_13) {
  // -54086290.7
  s21_decimal value_1 = {{0x203ce9bb, 0x0, 0x0, 0x80010000}};
  // -568099364186770.413442153303
  s21_decimal value_2 = {{0xe5d5bb57, 0x3df034e7, 0x1d5ebb8, 0x800c0000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_14) {
  // 659754.053
  s21_decimal value_1 = {{0x27530c45, 0x0, 0x0, 0x30000}};
  // -104460.00027839324021
  s21_decimal value_2 = {{0x17155f75, 0x90f7a5ae, 0x0, 0x800e0000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_15) {
  // 515.6882468556367111781430041
  s21_decimal value_1 = {{0x68813319, 0xc876b316, 0x10a9ac56, 0x190000}};
  // -742994290.55548593005
  s21_decimal value_2 = {{0x1e4f936d, 0x71c9912, 0x4, 0x800b0000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_16) {
  // 87495005043808
  s21_decimal value_1 = {{0x84b1fc60, 0x4f93, 0x0, 0x0}};
  // -21142563196
  s21_decimal value_2 = {{0xec31e97c, 0x4, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_17) {
  // -2557.8018145547655112
  s21_decimal value_1 = {{0x37dd17c8, 0x62f75ffc, 0x1, 0x80100000}};
  // -83078749149464759
  s21_decimal value_2 = {{0xa37008b7, 0x12727ae, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_18) {
  // 93.91
  s21_decimal value_1 = {{0x24af, 0x0, 0x0, 0x20000}};
  // -0.1860167924678074915919
  s21_decimal value_2 = {{0x143d5c4f, 0xd70407e7, 0x64, 0x80160000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_19) {
  // 30405166853200133071415
  s21_decimal value_1 = {{0xe385a237, 0x44742f81, 0x670, 0x0}};
  // 705022.89061
  s21_decimal value_2 = {{0x6a438ea5, 0x10, 0x0, 0x50000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_20) {
  // 3038118914886
  s21_decimal value_1 = {{0x5dffab46, 0x2c3, 0x0, 0x0}};
  // 774440581.228283623016226
  s21_decimal value_2 = {{0x2e628722, 0x820e5912, 0xa3fe, 0xf0000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_21) {
  // 5341.4144571417414343
  s21_decimal value_1 = {{0xc8b1cac7, 0xe545297c, 0x2, 0x100000}};
  // -50.4087611312250796217
  s21_decimal value_2 = {{0xc5e3b8b9, 0x539ef3b7, 0x1b, 0x80130000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_22) {
  // 67157.61
  s21_decimal value_1 = {{0x667971, 0x0, 0x0, 0x20000}};
  // 78.5267224618115249
  s21_decimal value_2 = {{0x591ea0b1, 0xae5d461, 0x0, 0x100000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_23) {
  // 277374880396444
  s21_decimal value_1 = {{0x5f37349c, 0xfc45, 0x0, 0x0}};
  // -75885417846871333076120751
  s21_decimal value_2 = {{0x67ab4af, 0xbe96124a, 0x3ec55c, 0x80000000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_24) {
  // -95355
  s21_decimal value_1 = {{0x1747b, 0x0, 0x0, 0x80000000}};
  // -77423622.31330
  s21_decimal value_2 = {{0xa8c02222, 0x70a, 0x0, 0x80050000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_false_25) {
  // 5767099.5602444
  s21_decimal value_1 = {{0x9334ec0c, 0x3473, 0x0, 0x70000}};
  // -9883592364936987001450904
  s21_decimal value_2 = {{0x35bf7198, 0x9d9e998e, 0x82cee, 0x80000000}};

  ck_assert_int_eq(s21_is_less(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

Suite *suite_s21_is_less() {
  Suite *suite = suite_create("s21_is_less");

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_is_less_true_1);
  tcase_add_test(testsTrue, s21_is_less_true_2);
  tcase_add_test(testsTrue, s21_is_less_true_3);
  tcase_add_test(testsTrue, s21_is_less_true_4);
  tcase_add_test(testsTrue, s21_is_less_true_5);
  tcase_add_test(testsTrue, s21_is_less_true_6);
  tcase_add_test(testsTrue, s21_is_less_true_7);
  tcase_add_test(testsTrue, s21_is_less_true_8);
  tcase_add_test(testsTrue, s21_is_less_true_9);
  tcase_add_test(testsTrue, s21_is_less_true_10);
  tcase_add_test(testsTrue, s21_is_less_true_11);
  tcase_add_test(testsTrue, s21_is_less_true_12);
  tcase_add_test(testsTrue, s21_is_less_true_13);
  tcase_add_test(testsTrue, s21_is_less_true_14);
  tcase_add_test(testsTrue, s21_is_less_true_15);
  tcase_add_test(testsTrue, s21_is_less_true_16);
  tcase_add_test(testsTrue, s21_is_less_true_17);
  tcase_add_test(testsTrue, s21_is_less_true_18);
  tcase_add_test(testsTrue, s21_is_less_true_19);
  tcase_add_test(testsTrue, s21_is_less_true_20);
  tcase_add_test(testsTrue, s21_is_less_true_21);
  tcase_add_test(testsTrue, s21_is_less_true_22);
  tcase_add_test(testsTrue, s21_is_less_true_23);
  tcase_add_test(testsTrue, s21_is_less_true_24);
  tcase_add_test(testsTrue, s21_is_less_true_25);

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_is_less_false_1);
  tcase_add_test(testsFalse, s21_is_less_false_2);
  tcase_add_test(testsFalse, s21_is_less_false_3);
  tcase_add_test(testsFalse, s21_is_less_false_4);
  tcase_add_test(testsFalse, s21_is_less_false_5);
  tcase_add_test(testsFalse, s21_is_less_false_6);
  tcase_add_test(testsFalse, s21_is_less_false_7);
  tcase_add_test(testsFalse, s21_is_less_false_8);
  tcase_add_test(testsFalse, s21_is_less_false_9);
  tcase_add_test(testsFalse, s21_is_less_false_10);
  tcase_add_test(testsFalse, s21_is_less_false_11);
  tcase_add_test(testsFalse, s21_is_less_false_12);
  tcase_add_test(testsFalse, s21_is_less_false_13);
  tcase_add_test(testsFalse, s21_is_less_false_14);
  tcase_add_test(testsFalse, s21_is_less_false_15);
  tcase_add_test(testsFalse, s21_is_less_false_16);
  tcase_add_test(testsFalse, s21_is_less_false_17);
  tcase_add_test(testsFalse, s21_is_less_false_18);
  tcase_add_test(testsFalse, s21_is_less_false_19);
  tcase_add_test(testsFalse, s21_is_less_false_20);
  tcase_add_test(testsFalse, s21_is_less_false_21);
  tcase_add_test(testsFalse, s21_is_less_false_22);
  tcase_add_test(testsFalse, s21_is_less_false_23);
  tcase_add_test(testsFalse, s21_is_less_false_24);
  tcase_add_test(testsFalse, s21_is_less_false_25);

  suite_add_tcase(suite, testsTrue);
  suite_add_tcase(suite, testsFalse);

  return suite;
}