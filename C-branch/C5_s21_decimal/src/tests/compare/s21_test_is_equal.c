#include "../s21_tests.h"

// Первое значение decimal равно второму decimal
// Возвращаемое значение 1

START_TEST(s21_is_equal_true_1) {
  // 79228162514264337593543950335
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_2) {
  // 0
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x0}};
  // 0
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_3) {
  // -56430341769823427952269757
  s21_decimal value_1 = {{0x5bd259bd, 0xf50109f9, 0x2ead96, 0x80000000}};
  // -56430341769823427952269757
  s21_decimal value_2 = {{0x5bd259bd, 0xf50109f9, 0x2ead96, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_4) {
  // -128240
  s21_decimal value_1 = {{0x1f4f0, 0x0, 0x0, 0x80000000}};
  // -128240
  s21_decimal value_2 = {{0x1f4f0, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_5) {
  // -9.76093494505748137297
  s21_decimal value_1 = {{0x20d18551, 0xea04b5b0, 0x34, 0x80140000}};
  // -9.76093494505748137297
  s21_decimal value_2 = {{0x20d18551, 0xea04b5b0, 0x34, 0x80140000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_6) {
  // -592532960216
  s21_decimal value_1 = {{0xf5b773d8, 0x89, 0x0, 0x80000000}};
  // -592532960216
  s21_decimal value_2 = {{0xf5b773d8, 0x89, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_7) {
  // -22792227673989808621417
  s21_decimal value_1 = {{0x96438769, 0x91b30718, 0x4d3, 0x80000000}};
  // -22792227673989808621417
  s21_decimal value_2 = {{0x96438769, 0x91b30718, 0x4d3, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_8) {
  // 4230557.072677419
  s21_decimal value_1 = {{0x5384da2b, 0xf07ab, 0x0, 0x90000}};
  // 4230557.072677419
  s21_decimal value_2 = {{0x5384da2b, 0xf07ab, 0x0, 0x90000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_9) {
  // -74297357321296686140746085134
  s21_decimal value_1 = {{0x4f77b30e, 0xe25347f8, 0xf0115562, 0x80000000}};
  // -74297357321296686140746085134
  s21_decimal value_2 = {{0x4f77b30e, 0xe25347f8, 0xf0115562, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_10) {
  // 3814205016
  s21_decimal value_1 = {{0xe3582658, 0x0, 0x0, 0x0}};
  // 3814205016
  s21_decimal value_2 = {{0xe3582658, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_11) {
  // 620323974084540753504835769
  s21_decimal value_1 = {{0xbc0b18b9, 0x472090e, 0x2011eb6, 0x0}};
  // 620323974084540753504835769
  s21_decimal value_2 = {{0xbc0b18b9, 0x472090e, 0x2011eb6, 0x0}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_12) {
  // -379586054505476979429
  s21_decimal value_1 = {{0x8b04fae5, 0x93d09170, 0x14, 0x80000000}};
  // -379586054505476979429
  s21_decimal value_2 = {{0x8b04fae5, 0x93d09170, 0x14, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_13) {
  // 37790.96585636
  s21_decimal value_1 = {{0xe3b5a5a4, 0x36f, 0x0, 0x80000}};
  // 37790.96585636
  s21_decimal value_2 = {{0xe3b5a5a4, 0x36f, 0x0, 0x80000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_14) {
  // 17146775063669562
  s21_decimal value_1 = {{0xacb6ab3a, 0x3ceae6, 0x0, 0x0}};
  // 17146775063669562
  s21_decimal value_2 = {{0xacb6ab3a, 0x3ceae6, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_15) {
  // -64436881917175077.7802191
  s21_decimal value_1 = {{0xa9654dcf, 0x4dbe1062, 0x8873, 0x80070000}};
  // -64436881917175077.7802191
  s21_decimal value_2 = {{0xa9654dcf, 0x4dbe1062, 0x8873, 0x80070000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_16) {
  // -49493282986883028237910610874
  s21_decimal value_1 = {{0x67b513ba, 0xe41372b2, 0x9febe256, 0x80000000}};
  // -49493282986883028237910610874
  s21_decimal value_2 = {{0x67b513ba, 0xe41372b2, 0x9febe256, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_17) {
  // 9002985492657
  s21_decimal value_1 = {{0x2bc090b1, 0x830, 0x0, 0x0}};
  // 9002985492657
  s21_decimal value_2 = {{0x2bc090b1, 0x830, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_18) {
  // 0.740419784349691282
  s21_decimal value_1 = {{0xf6d5ad92, 0xa467fde, 0x0, 0x120000}};
  // 0.740419784349691282
  s21_decimal value_2 = {{0xf6d5ad92, 0xa467fde, 0x0, 0x120000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_19) {
  // -46683483545
  s21_decimal value_1 = {{0xde8d6d99, 0xa, 0x0, 0x80000000}};
  // -46683483545
  s21_decimal value_2 = {{0xde8d6d99, 0xa, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_20) {
  // -6054337269136
  s21_decimal value_1 = {{0xa29f4d90, 0x581, 0x0, 0x80000000}};
  // -6054337269136
  s21_decimal value_2 = {{0xa29f4d90, 0x581, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_21) {
  // -0.6
  s21_decimal value_1 = {{0x6, 0x0, 0x0, 0x80010000}};
  // -0.6
  s21_decimal value_2 = {{0x6, 0x0, 0x0, 0x80010000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_22) {
  // -5865533489854726733099570888
  s21_decimal value_1 = {{0x349216c8, 0x9fd553b0, 0x12f3db07, 0x80000000}};
  // -5865533489854726733099570888
  s21_decimal value_2 = {{0x349216c8, 0x9fd553b0, 0x12f3db07, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_23) {
  // -1022246.339780043473421070
  s21_decimal value_1 = {{0xd5d8030e, 0x15ca70b7, 0xd878, 0x80120000}};
  // -1022246.339780043473421070
  s21_decimal value_2 = {{0xd5d8030e, 0x15ca70b7, 0xd878, 0x80120000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_24) {
  // 2.25008
  s21_decimal value_1 = {{0x36ef0, 0x0, 0x0, 0x50000}};
  // 2.25008
  s21_decimal value_2 = {{0x36ef0, 0x0, 0x0, 0x50000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_equal_true_25) {
  // 4651628346504.8123729
  s21_decimal value_1 = {{0x8d91e951, 0x858b095b, 0x2, 0x70000}};
  // 4651628346504.8123729
  s21_decimal value_2 = {{0x8d91e951, 0x858b095b, 0x2, 0x70000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_TRUE);
}
END_TEST

// Первое значение decimal не равно второму decimal
// Возвращаемое значение 0

START_TEST(s21_is_equal_false_1) {
  // -859055926563086670
  s21_decimal value_1 = {{0x50fca14e, 0xbebfad0, 0x0, 0x80000000}};
  // 0.2
  s21_decimal value_2 = {{0x2, 0x0, 0x0, 0x10000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_2) {
  // 7595519233
  s21_decimal value_1 = {{0xc4ba6d01, 0x1, 0x0, 0x0}};
  // -8278775532087765
  s21_decimal value_2 = {{0xa2c3e9d5, 0x1d6980, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_3) {
  // 11692220416373761830590263
  s21_decimal value_1 = {{0x85249737, 0x89f0cd32, 0x9abec, 0x0}};
  // 41881774679913807
  s21_decimal value_2 = {{0x8e5bf54f, 0x94cb40, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_4) {
  // -0.7
  s21_decimal value_1 = {{0x7, 0x0, 0x0, 0x80010000}};
  // 54727115
  s21_decimal value_2 = {{0x34311cb, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_5) {
  // -5745001544016194082254129
  s21_decimal value_1 = {{0x4c592d31, 0x28622805, 0x4c08d, 0x80000000}};
  // -56491444006.1583200
  s21_decimal value_2 = {{0xb05bff60, 0x7d6fab0, 0x0, 0x80070000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_6) {
  // -8.07674
  s21_decimal value_1 = {{0xc52fa, 0x0, 0x0, 0x80050000}};
  // -3
  s21_decimal value_2 = {{0x3, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_7) {
  // -11846795990.88454696190405027
  s21_decimal value_1 = {{0x9e80e9a3, 0xc065724a, 0x3d3f1a9, 0x80110000}};
  // -43600.47135411554312
  s21_decimal value_2 = {{0xe62a4808, 0x3c81ffc4, 0x0, 0x800e0000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_8) {
  // 34.8215
  s21_decimal value_1 = {{0x55037, 0x0, 0x0, 0x40000}};
  // 267911502
  s21_decimal value_2 = {{0xff8014e, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_9) {
  // -6796404472242909596
  s21_decimal value_1 = {{0xcdea319c, 0x5e51addb, 0x0, 0x80000000}};
  // 401.08729
  s21_decimal value_2 = {{0x26402b9, 0x0, 0x0, 0x50000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_10) {
  // 350598064.338343
  s21_decimal value_1 = {{0xf91575a7, 0x13edd, 0x0, 0x60000}};
  // -2679211214084150.884518
  s21_decimal value_2 = {{0xe0db78a6, 0x3d865423, 0x91, 0x80060000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_11) {
  // 3440792186095
  s21_decimal value_1 = {{0x1f322cef, 0x321, 0x0, 0x0}};
  // -0.2929
  s21_decimal value_2 = {{0xb71, 0x0, 0x0, 0x80040000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_12) {
  // 0.0422721
  s21_decimal value_1 = {{0x67341, 0x0, 0x0, 0x70000}};
  // 5988822
  s21_decimal value_2 = {{0x5b61d6, 0x0, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_13) {
  // 53
  s21_decimal value_1 = {{0x35, 0x0, 0x0, 0x0}};
  // -42.53745
  s21_decimal value_2 = {{0x40e831, 0x0, 0x0, 0x80050000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_14) {
  // 950312995798
  s21_decimal value_1 = {{0x43118bd6, 0xdd, 0x0, 0x0}};
  // 69532.7452859087556305
  s21_decimal value_2 = {{0x63158ed1, 0xb19b5a5f, 0x25, 0x100000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_15) {
  // 66.422663681434459404062981048
  s21_decimal value_1 = {{0xbfe47bb8, 0x48c5714d, 0xd69f8a25, 0x1b0000}};
  // 9815082436
  s21_decimal value_2 = {{0x490645c4, 0x2, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_16) {
  // 74570
  s21_decimal value_1 = {{0x1234a, 0x0, 0x0, 0x0}};
  // 8.029
  s21_decimal value_2 = {{0x1f5d, 0x0, 0x0, 0x30000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_17) {
  // 70196932131.218873
  s21_decimal value_1 = {{0xe400e5b9, 0xf963bc, 0x0, 0x60000}};
  // 91542390884443
  s21_decimal value_2 = {{0xdfb0c85b, 0x5341, 0x0, 0x0}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_18) {
  // -107495648365396490
  s21_decimal value_1 = {{0xffb8420a, 0x17de6b8, 0x0, 0x80000000}};
  // -399401179517.672
  s21_decimal value_2 = {{0xd56d92e8, 0x16b40, 0x0, 0x80030000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_19) {
  // -19679
  s21_decimal value_1 = {{0x4cdf, 0x0, 0x0, 0x80000000}};
  // -1379898334017.997981015
  s21_decimal value_2 = {{0x50174557, 0xcdefafc6, 0x4a, 0x80090000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_20) {
  // -8690878325576032528118.427434
  s21_decimal value_1 = {{0x8645af2a, 0x11e0c3a0, 0x1c14ed12, 0x80060000}};
  // -3293840271
  s21_decimal value_2 = {{0xc454038f, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_21) {
  // 43354280095
  s21_decimal value_1 = {{0x181dd09f, 0xa, 0x0, 0x0}};
  // -82280351
  s21_decimal value_2 = {{0x4e77f9f, 0x0, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_22) {
  // 681003465330880140
  s21_decimal value_1 = {{0x29db6e8c, 0x973690b, 0x0, 0x0}};
  // 647841.4585488
  s21_decimal value_2 = {{0x5f999e90, 0x5e4, 0x0, 0x70000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_23) {
  // 866380201616746547264256.3
  s21_decimal value_1 = {{0x64124e03, 0xa5fd41ec, 0x72aa1, 0x10000}};
  // -0.925658865
  s21_decimal value_2 = {{0x372c6ef1, 0x0, 0x0, 0x80090000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_24) {
  // -282.460
  s21_decimal value_1 = {{0x44f5c, 0x0, 0x0, 0x80030000}};
  // -66069.028204636
  s21_decimal value_2 = {{0xe4f4f05c, 0x3c16, 0x0, 0x80090000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_equal_false_25) {
  // -3134905957078744
  s21_decimal value_1 = {{0x2bf9d6d8, 0xb232e, 0x0, 0x80000000}};
  // -141457840135
  s21_decimal value_2 = {{0xef8b5807, 0x20, 0x0, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(value_1, value_2), COMPARISON_FALSE);
}
END_TEST

Suite *suite_s21_is_equal() {
  Suite *suite = suite_create("s21_is_equal");

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_is_equal_true_1);
  tcase_add_test(testsTrue, s21_is_equal_true_2);
  tcase_add_test(testsTrue, s21_is_equal_true_3);
  tcase_add_test(testsTrue, s21_is_equal_true_4);
  tcase_add_test(testsTrue, s21_is_equal_true_5);
  tcase_add_test(testsTrue, s21_is_equal_true_6);
  tcase_add_test(testsTrue, s21_is_equal_true_7);
  tcase_add_test(testsTrue, s21_is_equal_true_8);
  tcase_add_test(testsTrue, s21_is_equal_true_9);
  tcase_add_test(testsTrue, s21_is_equal_true_10);
  tcase_add_test(testsTrue, s21_is_equal_true_11);
  tcase_add_test(testsTrue, s21_is_equal_true_12);
  tcase_add_test(testsTrue, s21_is_equal_true_13);
  tcase_add_test(testsTrue, s21_is_equal_true_14);
  tcase_add_test(testsTrue, s21_is_equal_true_15);
  tcase_add_test(testsTrue, s21_is_equal_true_16);
  tcase_add_test(testsTrue, s21_is_equal_true_17);
  tcase_add_test(testsTrue, s21_is_equal_true_18);
  tcase_add_test(testsTrue, s21_is_equal_true_19);
  tcase_add_test(testsTrue, s21_is_equal_true_20);
  tcase_add_test(testsTrue, s21_is_equal_true_21);
  tcase_add_test(testsTrue, s21_is_equal_true_22);
  tcase_add_test(testsTrue, s21_is_equal_true_23);
  tcase_add_test(testsTrue, s21_is_equal_true_24);
  tcase_add_test(testsTrue, s21_is_equal_true_25);

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_is_equal_false_1);
  tcase_add_test(testsFalse, s21_is_equal_false_2);
  tcase_add_test(testsFalse, s21_is_equal_false_3);
  tcase_add_test(testsFalse, s21_is_equal_false_4);
  tcase_add_test(testsFalse, s21_is_equal_false_5);
  tcase_add_test(testsFalse, s21_is_equal_false_6);
  tcase_add_test(testsFalse, s21_is_equal_false_7);
  tcase_add_test(testsFalse, s21_is_equal_false_8);
  tcase_add_test(testsFalse, s21_is_equal_false_9);
  tcase_add_test(testsFalse, s21_is_equal_false_10);
  tcase_add_test(testsFalse, s21_is_equal_false_11);
  tcase_add_test(testsFalse, s21_is_equal_false_12);
  tcase_add_test(testsFalse, s21_is_equal_false_13);
  tcase_add_test(testsFalse, s21_is_equal_false_14);
  tcase_add_test(testsFalse, s21_is_equal_false_15);
  tcase_add_test(testsFalse, s21_is_equal_false_16);
  tcase_add_test(testsFalse, s21_is_equal_false_17);
  tcase_add_test(testsFalse, s21_is_equal_false_18);
  tcase_add_test(testsFalse, s21_is_equal_false_19);
  tcase_add_test(testsFalse, s21_is_equal_false_20);
  tcase_add_test(testsFalse, s21_is_equal_false_21);
  tcase_add_test(testsFalse, s21_is_equal_false_22);
  tcase_add_test(testsFalse, s21_is_equal_false_23);
  tcase_add_test(testsFalse, s21_is_equal_false_24);
  tcase_add_test(testsFalse, s21_is_equal_false_25);

  suite_add_tcase(suite, testsTrue);
  suite_add_tcase(suite, testsFalse);

  return suite;
}