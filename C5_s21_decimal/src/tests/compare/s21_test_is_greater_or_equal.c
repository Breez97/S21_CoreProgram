#include "../s21_tests.h"

// Первое значение decimal больше или равно второму decimal
// Возвращаемое значение 1

START_TEST(s21_is_greater_or_equal_true_1) {
  // 79228162514264337593543950335
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_2) {
  // 974320.1823534
  s21_decimal value_1 = {{0x84156b2e, 0x8dc, 0x0, 0x70000}};
  // -608053221233417482
  s21_decimal value_2 = {{0xe0265d0a, 0x8703d2e, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_3) {
  // 211683240324434410676556811
  s21_decimal value_1 = {{0x3eea140b, 0x73b16e92, 0xaf19ab, 0x0}};
  // 61309562006215
  s21_decimal value_2 = {{0xbeaa2ac7, 0x37c2, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_4) {
  // 560355207208393913
  s21_decimal value_1 = {{0x91b25cb9, 0x7c6c817, 0x0, 0x0}};
  // -42.4061
  s21_decimal value_2 = {{0x6787d, 0x0, 0x0, 0x80040000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_5) {
  // -99.14927780166717
  s21_decimal value_1 = {{0x44f7c3d, 0x233993, 0x0, 0x800e0000}};
  // -45968739.245279934
  s21_decimal value_2 = {{0x257ccabe, 0xa35053, 0x0, 0x80090000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_6) {
  // 15985949.6409564208062
  s21_decimal value_1 = {{0x38e85bbe, 0xaa7f0503, 0x8, 0xd0000}};
  // -57325361
  s21_decimal value_2 = {{0x36ab731, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_7) {
  // 874712381634242874819950
  s21_decimal value_1 = {{0x50dc56e, 0x40d33f86, 0xb93a, 0x0}};
  // 874712381634242874819950
  s21_decimal value_2 = {{0x50dc56e, 0x40d33f86, 0xb93a, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_8) {
  // 9861458.8341635770367
  s21_decimal value_1 = {{0x3e93e7ff, 0x588d659d, 0x5, 0xd0000}};
  // -316739
  s21_decimal value_2 = {{0x4d543, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_9) {
  // 8
  s21_decimal value_1 = {{0x8, 0x0, 0x0, 0x0}};
  // -15505.28488000103913761
  s21_decimal value_2 = {{0xb9b81921, 0xde7c4c8, 0x54, 0x80110000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_10) {
  // 301473775
  s21_decimal value_1 = {{0x11f81fef, 0x0, 0x0, 0x0}};
  // -9211809404010202796748251
  s21_decimal value_2 = {{0xb1396ddb, 0x303c2150, 0x79ead, 0x80000000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_11) {
  // -173054087994096.6
  s21_decimal value_1 = {{0xf26b0d66, 0x625ea, 0x0, 0x80010000}};
  // -214738684034059079368111.7112
  s21_decimal value_2 = {{0xe7819fb8, 0xdf8a3449, 0x6f046d9, 0x80040000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_12) {
  // 43121188287483950650
  s21_decimal value_1 = {{0x1837363a, 0x566d3c48, 0x2, 0x0}};
  // -23941
  s21_decimal value_2 = {{0x5d85, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_13) {
  // 455473886154.2
  s21_decimal value_1 = {{0x7b9785e6, 0x424, 0x0, 0x10000}};
  // -76
  s21_decimal value_2 = {{0x4c, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_14) {
  // 213.654584108938
  s21_decimal value_1 = {{0x5597278a, 0xc251, 0x0, 0xc0000}};
  // -3619471449424993
  s21_decimal value_2 = {{0xde048461, 0xcdbe3, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_15) {
  // 7599100715932610640612068
  s21_decimal value_1 = {{0x3eca0ae4, 0x13441393, 0x6492c, 0x0}};
  // 7599100715932610640612068
  s21_decimal value_2 = {{0x3eca0ae4, 0x13441393, 0x6492c, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_16) {
  // 29917307409099
  s21_decimal value_1 = {{0xaa7b12cb, 0x1b35, 0x0, 0x0}};
  // 183856
  s21_decimal value_2 = {{0x2ce30, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_17) {
  // 87263
  s21_decimal value_1 = {{0x154df, 0x0, 0x0, 0x0}};
  // -40766814621041852292004068
  s21_decimal value_2 = {{0xbf3bf8e4, 0x72e94cb5, 0x21b8b5, 0x80000000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_18) {
  // 9.012088374330
  s21_decimal value_1 = {{0x4a53843a, 0x832, 0x0, 0xc0000}};
  // -7806.27
  s21_decimal value_2 = {{0xbe953, 0x0, 0x0, 0x80020000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_19) {
  // 50438519544857686253
  s21_decimal value_1 = {{0x93d6f0ed, 0xbbf99e4a, 0x2, 0x0}};
  // 2.47306459144
  s21_decimal value_2 = {{0x949d1808, 0x39, 0x0, 0xb0000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_20) {
  // 17783140283.8310
  s21_decimal value_1 = {{0x99989926, 0xa1bc, 0x0, 0x40000}};
  // 3072449.117598583022834
  s21_decimal value_2 = {{0x3deae4f2, 0x8ecc01ec, 0xa6, 0xf0000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_21) {
  // 231011779721947
  s21_decimal value_1 = {{0x9f11badb, 0xd21a, 0x0, 0x0}};
  // -863394
  s21_decimal value_2 = {{0xd2ca2, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_22) {
  // 5.9736511346516152012
  s21_decimal value_1 = {{0x722fcecc, 0x3d02b892, 0x3, 0x130000}};
  // -5715679809052595012891607
  s21_decimal value_2 = {{0x5a75f3d7, 0x9f9143d6, 0x4ba57, 0x80000000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_23) {
  // -3.04963673035309449
  s21_decimal value_1 = {{0x48ab0189, 0x43b72d8, 0x0, 0x80110000}};
  // -591707506977180221238.657
  s21_decimal value_2 = {{0x6cdced81, 0x8739e303, 0x7d4c, 0x80030000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_24) {
  // 71420507778337
  s21_decimal value_1 = {{0xe1feed21, 0x40f4, 0x0, 0x0}};
  // -979.2735987764
  s21_decimal value_2 = {{0xc8cc834, 0x8e8, 0x0, 0x800a0000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_true_25) {
  // 80059488748229307853
  s21_decimal value_1 = {{0xd9972dcd, 0x570c70d7, 0x4, 0x0}};
  // -857132136543723
  s21_decimal value_2 = {{0xa08635eb, 0x30b8e, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

// Первое значение decimal меньше второго decimal
// Возвращаемое значение 0

START_TEST(s21_is_greater_or_equal_false_1) {
  // -6828678416804510955288081
  s21_decimal value_1 = {{0xb69d3611, 0x661382d9, 0x5a607, 0x80000000}};
  // -956382.83988
  s21_decimal value_2 = {{0x447c66d4, 0x16, 0x0, 0x80050000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_2) {
  // -8388590.17327
  s21_decimal value_1 = {{0x4fe4cc6f, 0xc3, 0x0, 0x80050000}};
  // 913694914.29797344714
  s21_decimal value_2 = {{0xed2b35ca, 0xf401a45b, 0x4, 0xb0000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_3) {
  // -2959
  s21_decimal value_1 = {{0xb8f, 0x0, 0x0, 0x80000000}};
  // 602461
  s21_decimal value_2 = {{0x9315d, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_4) {
  // 99891406020784
  s21_decimal value_1 = {{0xc7c5a0b0, 0x5ad9, 0x0, 0x0}};
  // 457691556230946058716160737
  s21_decimal value_2 = {{0x601da2e1, 0xfacd2bb3, 0x17a97f4, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_5) {
  // 99891406020784
  s21_decimal value_1 = {{0xc7c5a0b0, 0x5ad9, 0x0, 0x0}};
  // 457691556230946058716160737
  s21_decimal value_2 = {{0x601da2e1, 0xfacd2bb3, 0x17a97f4, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_6) {
  // 461098
  s21_decimal value_1 = {{0x7092a, 0x0, 0x0, 0x0}};
  // 82569856.778401
  s21_decimal value_2 = {{0xcafb80a1, 0x4b18, 0x0, 0x60000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_7) {
  // -8138828616006920570965
  s21_decimal value_1 = {{0x6c9c0855, 0x34efc0e5, 0x1b9, 0x80000000}};
  // -0.28201339731541797010
  s21_decimal value_2 = {{0x98a8a892, 0x875f4911, 0x1, 0x80140000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_8) {
  // -365452
  s21_decimal value_1 = {{0x5938c, 0x0, 0x0, 0x80000000}};
  // 935871424206668046043719775
  s21_decimal value_2 = {{0xe5dc285f, 0x9089892a, 0x306227b, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_9) {
  // 856
  s21_decimal value_1 = {{0x358, 0x0, 0x0, 0x0}};
  // 85217253713372012840
  s21_decimal value_2 = {{0x7fe06128, 0x9ea080c0, 0x4, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_10) {
  // -5798293619354477799
  s21_decimal value_1 = {{0x7d09a4e7, 0x5077ad53, 0x0, 0x80000000}};
  // 15961515940096.2195083204325
  s21_decimal value_2 = {{0xbec796e5, 0x2113b883, 0x8407d3, 0xd0000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_11) {
  // 390.72422863756523709127628
  s21_decimal value_1 = {{0x72f3dbcc, 0x49a3f1fb, 0x2051e8, 0x170000}};
  // 2482.81576366507227
  s21_decimal value_2 = {{0x3b9984db, 0x37212c7, 0x0, 0xe0000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_12) {
  // 6247193676537797302715418818
  s21_decimal value_1 = {{0xc73408c2, 0xcd4fd312, 0x142f8eb7, 0x0}};
  // 37465294609497037904085415565
  s21_decimal value_2 = {{0xfa8e768d, 0x6bdacc64, 0x790e90ba, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_13) {
  // -53973140236347092.18
  s21_decimal value_1 = {{0x1ffb2ae2, 0x4ae71c82, 0x0, 0x80020000}};
  // -28489
  s21_decimal value_2 = {{0x6f49, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_14) {
  // 4927232592215
  s21_decimal value_1 = {{0x35f2c957, 0x47b, 0x0, 0x0}};
  // 3565787321705592457128
  s21_decimal value_2 = {{0x855f07a8, 0x4d3d64bd, 0xc1, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_15) {
  // -6126999511991113
  s21_decimal value_1 = {{0x3d738349, 0x15c479, 0x0, 0x80000000}};
  // 60.89741157812920
  s21_decimal value_2 = {{0x5a7c4ab8, 0x15a296, 0x0, 0xe0000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_16) {
  // -165844415255280
  s21_decimal value_1 = {{0xa97592f0, 0x96d5, 0x0, 0x80000000}};
  // 273632073428.515136
  s21_decimal value_2 = {{0xc7dc3940, 0x3cc22eb, 0x0, 0x60000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_17) {
  // -850606240063135.0
  s21_decimal value_1 = {{0xfbd3b236, 0x1e3837, 0x0, 0x80010000}};
  // 648194
  s21_decimal value_2 = {{0x9e402, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_18) {
  // 18707826088221
  s21_decimal value_1 = {{0xc154191d, 0x1103, 0x0, 0x0}};
  // 187429370373051.6
  s21_decimal value_2 = {{0x26a6554, 0x6a8a9, 0x0, 0x10000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_19) {
  // -4569400.9955
  s21_decimal value_1 = {{0xa3934263, 0xa, 0x0, 0x80040000}};
  // -0.884203939215741
  s21_decimal value_2 = {{0xc5b4b97d, 0x3242d, 0x0, 0x800f0000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_20) {
  // 781.105332278446299
  s21_decimal value_1 = {{0x469ec8db, 0xad70b29, 0x0, 0xf0000}};
  // 5448352251390906391747
  s21_decimal value_2 = {{0x5abcdcc3, 0x5b139208, 0x127, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_21) {
  // -7821278935650392979810322842
  s21_decimal value_1 = {{0xeafc899a, 0xaeaf5fbf, 0x19459c3c, 0x80000000}};
  // -5230500.1494625726127981273
  s21_decimal value_2 = {{0xc6a4c2d9, 0xd007a330, 0x2b4403, 0x80130000}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_22) {
  // -537439557
  s21_decimal value_1 = {{0x2008ad45, 0x0, 0x0, 0x80000000}};
  // 60087234383729985979389692
  s21_decimal value_2 = {{0x5bf96fc, 0x80bc5e8b, 0x31b3f7, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_23) {
  // -8714842
  s21_decimal value_1 = {{0x84fa5a, 0x0, 0x0, 0x80000000}};
  // 6193404726150120026985647956
  s21_decimal value_2 = {{0x5d3ecf54, 0xf56d33b2, 0x14031076, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_24) {
  // 99.30303
  s21_decimal value_1 = {{0x97863f, 0x0, 0x0, 0x50000}};
  // 97562584
  s21_decimal value_2 = {{0x5d0afd8, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_false_25) {
  // 0.52102568093822
  s21_decimal value_1 = {{0x1310287e, 0x2f63, 0x0, 0xe0000}};
  // 317997
  s21_decimal value_2 = {{0x4da2d, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_greater_or_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

Suite *suite_s21_is_greater_or_equal() {
  Suite *suite = suite_create("s21_is_greater_or_equal");

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_1);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_2);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_3);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_4);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_5);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_6);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_7);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_8);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_9);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_10);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_11);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_12);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_13);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_14);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_15);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_16);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_17);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_18);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_19);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_20);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_21);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_22);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_23);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_24);
  tcase_add_test(testsTrue, s21_is_greater_or_equal_true_25);

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_1);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_2);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_3);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_4);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_5);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_6);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_7);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_8);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_9);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_10);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_11);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_12);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_13);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_14);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_15);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_16);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_17);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_18);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_19);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_20);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_21);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_22);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_23);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_24);
  tcase_add_test(testsFalse, s21_is_greater_or_equal_false_25);

  suite_add_tcase(suite, testsTrue);
  suite_add_tcase(suite, testsFalse);

  return suite;
}