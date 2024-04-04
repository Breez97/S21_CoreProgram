#include "../s21_tests.h"

START_TEST(invalid_dec_s21_mul_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_mul(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 4);
}
END_TEST
START_TEST(invalid_dec_s21_mul_2) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_3) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_4) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_5) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_6) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_7) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_8) {
  // Все биты имеют максимальное значение
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_9) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_10) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_11) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_12) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_13) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_14) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_15) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_mul_16) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_mul(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_mul_1) {
  // -385004967
  s21_decimal dec_1 = {{0x16f2b5a7, 0x0, 0x0, 0x80000000}};
  // -0.41
  s21_decimal dec_2 = {{0x29, 0x0, 0x0, 0x80020000}};
  // 157852036.47
  s21_decimal dec_check = {{0xacdf17bf, 0x3, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_2) {
  // -16822327873523.33
  s21_decimal dec_1 = {{0x57b83b0d, 0x5f9fb, 0x0, 0x80020000}};
  // 400.110128
  s21_decimal dec_2 = {{0x17d93230, 0x0, 0x0, 0x60000}};
  // -6730783758733387.37728624
  s21_decimal dec_check = {{0xa7189c70, 0xa6e0deba, 0x8e87, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_3) {
  // 2.15609
  s21_decimal dec_1 = {{0x34a39, 0x0, 0x0, 0x50000}};
  // 36804324394194037542
  s21_decimal dec_2 = {{0xf22deb26, 0xfec33a09, 0x1, 0x0}};
  // 79353435783077822403.93078
  s21_decimal dec_check = {{0xf3a45776, 0xd65ca2c1, 0x6905f, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_4) {
  // -5
  s21_decimal dec_1 = {{0x5, 0x0, 0x0, 0x80000000}};
  // -8592791490479
  s21_decimal dec_2 = {{0xaa48cfaf, 0x7d0, 0x0, 0x80000000}};
  // 42963957452395
  s21_decimal dec_check = {{0x536c0e6b, 0x2713, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_5) {
  // -789513827
  s21_decimal dec_1 = {{0x2f0f0663, 0x0, 0x0, 0x80000000}};
  // -51267348816
  s21_decimal dec_2 = {{0xefc5a950, 0xb, 0x0, 0x80000000}};
  // 40476280763864078832
  s21_decimal dec_check = {{0xf71859f0, 0x31b8a2e6, 0x2, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_6) {
  // -24536
  s21_decimal dec_1 = {{0x5fd8, 0x0, 0x0, 0x80000000}};
  // 535866802005.58676392
  s21_decimal dec_2 = {{0x5ec209a8, 0xe7aa21ba, 0x2, 0x80000}};
  // -13148027854009076.83954112
  s21_decimal dec_check = {{0xf54d7dc0, 0x9a109e69, 0x1166b, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_7) {
  // 87342
  s21_decimal dec_1 = {{0x1552e, 0x0, 0x0, 0x0}};
  // 32261995788555011
  s21_decimal dec_2 = {{0x3eb8d303, 0x729e1d, 0x0, 0x0}};
  // 2817827236163971770762
  s21_decimal dec_check = {{0x7648e98a, 0xc1355dcd, 0x98, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_8) {
  // -8009152326
  s21_decimal dec_1 = {{0xdd61f746, 0x1, 0x0, 0x80000000}};
  // -79
  s21_decimal dec_2 = {{0x4f, 0x0, 0x0, 0x80000000}};
  // 632723033754
  s21_decimal dec_check = {{0x513b4e9a, 0x93, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_9) {
  // -868755961490201968
  s21_decimal dec_1 = {{0xb1205d70, 0xc0e70f1, 0x0, 0x80000000}};
  // -3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x80000000}};
  // 2606267884470605904
  s21_decimal dec_check = {{0x13611850, 0x242b52d5, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_10) {
  // -0.08268282751272275555068675
  s21_decimal dec_1 = {{0xf5b72b03, 0x818ea29f, 0x6d6e0, 0x801a0000}};
  // 83313486103292991.86508297
  s21_decimal dec_2 = {{0xfed66209, 0x502ac5be, 0x6e43b, 0x80000}};
  // -6888594600962198.7461072928038
  s21_decimal dec_check = {{0xaac3bd26, 0xde18d179, 0xde951e77, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_11) {
  // -950.39529106081722457
  s21_decimal dec_1 = {{0x54663059, 0x26f03c2e, 0x5, 0x80110000}};
  // 220504002416851087697
  s21_decimal dec_2 = {{0xf848f151, 0xf41b95ea, 0xb, 0x0}};
  // -209565965557038334229026.29018
  s21_decimal dec_check = {{0x6f74929a, 0xae087912, 0x43b6e3ef, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_12) {
  // -484768876.50503845788
  s21_decimal dec_1 = {{0xcd679c, 0xa0c0807a, 0x2, 0x800b0000}};
  // -791784
  s21_decimal dec_2 = {{0xc14e8, 0x0, 0x0, 0x80000000}};
  // 383832240114665.37033405792
  s21_decimal dec_check = {{0xa18e1560, 0xbe360041, 0x1fbff6, 0xb0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_13) {
  // 0.31801
  s21_decimal dec_1 = {{0x7c39, 0x0, 0x0, 0x50000}};
  // 80
  s21_decimal dec_2 = {{0x50, 0x0, 0x0, 0x0}};
  // 25.44080
  s21_decimal dec_check = {{0x26d1d0, 0x0, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_14) {
  // -8664153348981816933
  s21_decimal dec_1 = {{0xf5927e65, 0x783d4190, 0x0, 0x80000000}};
  // -78284929
  s21_decimal dec_2 = {{0x4aa8881, 0x0, 0x0, 0x80000000}};
  // 678272629770153760890902757
  s21_decimal dec_check = {{0x150958e5, 0xefcc69c3, 0x2310dd0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_15) {
  // -3523212.2
  s21_decimal dec_1 = {{0x219997a, 0x0, 0x0, 0x80010000}};
  // -874.917467587713569
  s21_decimal dec_2 = {{0x1f599a21, 0xc2454cd, 0x0, 0x800f0000}};
  // 3082519895.7981370164063418
  s21_decimal dec_check = {{0xcd0a2cba, 0x6245c471, 0x197f7d, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_16) {
  // 28.638427173637983768
  s21_decimal dec_1 = {{0x12960e18, 0x8d7021c8, 0x1, 0x120000}};
  // 38786527602
  s21_decimal dec_2 = {{0x7db7172, 0x9, 0x0, 0x0}};
  // 1110785146048.1765041731599643
  s21_decimal dec_check = {{0xda2cfd1b, 0x4149b044, 0x23e4330a, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_17) {
  // -87561476
  s21_decimal dec_1 = {{0x5381504, 0x0, 0x0, 0x80000000}};
  // -4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x80000000}};
  // 350245904
  s21_decimal dec_check = {{0x14e05410, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_18) {
  // -4260227959.22417
  s21_decimal dec_1 = {{0x296acbf1, 0x18377, 0x0, 0x80050000}};
  // 5097.2964915059414727640849
  s21_decimal dec_2 = {{0x9147c711, 0xf706bfe5, 0x2a29f1, 0x160000}};
  // -21715645029568.878831388078402
  s21_decimal dec_check = {{0xb943142, 0xe62d76dc, 0x462ac2b3, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_19) {
  // -22586915626610.806461
  s21_decimal dec_1 = {{0x7fdb4ebd, 0x3974d817, 0x1, 0x80060000}};
  // -675736933625
  s21_decimal dec_2 = {{0x550f54f9, 0x9d, 0x0, 0x80000000}};
  // 15262813105572581809244478.151
  s21_decimal dec_check = {{0x39021ac7, 0x5d7743f7, 0x31511a64, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_20) {
  // -84.276075084
  s21_decimal dec_1 = {{0x9f3eda4c, 0x13, 0x0, 0x80090000}};
  // 604
  s21_decimal dec_2 = {{0x25c, 0x0, 0x0, 0x0}};
  // -50902.749350736
  s21_decimal dec_check = {{0xb84b0b50, 0x2e4b, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_21) {
  // -26008378402221597
  s21_decimal dec_1 = {{0x7bd92e1d, 0x5c667b, 0x0, 0x80000000}};
  // -488155
  s21_decimal dec_2 = {{0x772db, 0x0, 0x0, 0x80000000}};
  // 12696119958936483683535
  s21_decimal dec_check = {{0xec1e5ccf, 0x420f0bb9, 0x2b0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_22) {
  // 438014792637.4709967
  s21_decimal dec_1 = {{0xff3a7acf, 0x3cc96954, 0x0, 0x70000}};
  // -3383996
  s21_decimal dec_2 = {{0x33a2bc, 0x0, 0x0, 0x80000000}};
  // -1482240306226031302.9488132
  s21_decimal dec_check = {{0xe7e62e04, 0x147ffc94, 0xc42c4, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_23) {
  // 4.1605352053434114403
  s21_decimal dec_1 = {{0xc026163, 0x4163e742, 0x2, 0x130000}};
  // 3433351.050479857218
  s21_decimal dec_2 = {{0xf910ee42, 0x2fa5b696, 0x0, 0xc0000}};
  // 14284577.917824230128163165463
  s21_decimal dec_check = {{0xee2b1517, 0x93c1b863, 0x2e27ed08, 0x150000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_24) {
  // 55489044.9052272164789
  s21_decimal dec_1 = {{0x39abffb5, 0x14a6e37a, 0x1e, 0xd0000}};
  // 23122542285932586
  s21_decimal dec_2 = {{0x6741c82a, 0x5225d4, 0x0, 0x0}};
  // 1283047787227128436998200.2892
  s21_decimal dec_check = {{0x54a496cc, 0x283d569f, 0x29751f5f, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_25) {
  // -4078338358181
  s21_decimal dec_1 = {{0x8fe8bba5, 0x3b5, 0x0, 0x80000000}};
  // -336
  s21_decimal dec_2 = {{0x150, 0x0, 0x0, 0x80000000}};
  // 1370321688348816
  s21_decimal dec_check = {{0xe1764890, 0x4de4c, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_26) {
  // -7299.41448
  s21_decimal dec_1 = {{0x2b8205c8, 0x0, 0x0, 0x80050000}};
  // -7189425886
  s21_decimal dec_2 = {{0xac85eede, 0x1, 0x0, 0x80000000}};
  // 52478599415155.22928
  s21_decimal dec_check = {{0xfd08f370, 0x48d424cf, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_27) {
  // 86.9833090976
  s21_decimal dec_1 = {{0x8617a7a0, 0xca, 0x0, 0xa0000}};
  // -20930575934166
  s21_decimal dec_2 = {{0x478b22d6, 0x1309, 0x0, 0x80000000}};
  // -1820610756072349.0464686016
  s21_decimal dec_check = {{0x9fe95fc0, 0x1188b210, 0xf0f4b, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_28) {
  // -0.086
  s21_decimal dec_1 = {{0x56, 0x0, 0x0, 0x80030000}};
  // -738120208166222202215
  s21_decimal dec_2 = {{0x450e8567, 0x379c299, 0x28, 0x80000000}};
  // 63478337902295109390.490
  s21_decimal dec_check = {{0x32e0d09a, 0x2ae75f7d, 0xd71, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_29) {
  // -433216512563715.2748542076
  s21_decimal dec_1 = {{0x431f187c, 0x245cac71, 0x3955f, 0x800a0000}};
  // -0.24302
  s21_decimal dec_2 = {{0x5eee, 0x0, 0x0, 0x80050000}};
  // 105280276883234.08609506953095
  s21_decimal dec_check = {{0x2e970787, 0x9558fd98, 0x22049494, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_30) {
  // -4520.0475447081561964260057
  s21_decimal dec_1 = {{0xa70daad9, 0xaf112202, 0x256392, 0x80160000}};
  // -29.32324
  s21_decimal dec_2 = {{0x2cbe64, 0x0, 0x0, 0x80050000}};
  // 132542.43896488799410528690738
  s21_decimal dec_check = {{0x14dba232, 0x5c7dcef3, 0x2ad3a751, 0x170000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_31) {
  // -89836068500739439150172
  s21_decimal dec_1 = {{0x494f445c, 0x5e56988, 0x1306, 0x80000000}};
  // -567303
  s21_decimal dec_2 = {{0x8a807, 0x0, 0x0, 0x80000000}};
  // 50964271168674986048210026116
  s21_decimal dec_check = {{0x28e73e84, 0x2c99d50, 0xa4aca834, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_32) {
  // -1917025.0310
  s21_decimal dec_1 = {{0x76a2ce46, 0x4, 0x0, 0x80040000}};
  // 1
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  // -1917025.0310
  s21_decimal dec_check = {{0x76a2ce46, 0x4, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_33) {
  // -72774468892332964741160
  s21_decimal dec_1 = {{0x659c8028, 0x1ca319ea, 0xf69, 0x80000000}};
  // 758
  s21_decimal dec_2 = {{0x2f6, 0x0, 0x0, 0x0}};
  // -55163047420388387273799280
  s21_decimal dec_check = {{0xdd637670, 0xcaeebc08, 0x2da13a, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_34) {
  // -0.4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x80010000}};
  // 79092388707252945656241963868
  s21_decimal dec_2 = {{0x1b73c35c, 0x2c6fcefa, 0xff8fb0c7, 0x0}};
  // -31636955482901178262496785547
  s21_decimal dec_check = {{0xa494b48b, 0x44f985fd, 0x663979e9, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_35) {
  // -660
  s21_decimal dec_1 = {{0x294, 0x0, 0x0, 0x80000000}};
  // -2301638847347604623.21069
  s21_decimal dec_2 = {{0x563805ad, 0x358da9bd, 0x30bd, 0x80050000}};
  // 1519081639249419051319.05540
  s21_decimal dec_check = {{0x486ea204, 0x11399c22, 0x7da7ce, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_36) {
  // -1421866530782174659
  s21_decimal dec_1 = {{0x8d49ddc3, 0x13bb7c13, 0x0, 0x80000000}};
  // -9812.67
  s21_decimal dec_2 = {{0xef913, 0x0, 0x0, 0x80020000}};
  // 13952307050610321811129.53
  s21_decimal dec_check = {{0x75d82079, 0x9baaf3ea, 0x12773, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_37) {
  // -0.48835290349210
  s21_decimal dec_1 = {{0x5a223e9a, 0x2c6a, 0x0, 0x800e0000}};
  // -866954.3077379
  s21_decimal dec_2 = {{0x89091603, 0x7e2, 0x0, 0x80070000}};
  // 423379.653378787042961520590
  s21_decimal dec_check = {{0x9d31f7ce, 0xffbca1a6, 0x15e3620, 0x150000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_38) {
  // -0.61
  s21_decimal dec_1 = {{0x3d, 0x0, 0x0, 0x80020000}};
  // 9859179668602
  s21_decimal dec_2 = {{0x84e6e47a, 0x8f7, 0x0, 0x0}};
  // -6014099597847.22
  s21_decimal dec_check = {{0xab047112, 0x222fa, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_40) {
  // -24820649696448697688310945
  s21_decimal dec_1 = {{0x1b02c4a1, 0x1dbd49ee, 0x1487fa, 0x80000000}};
  // 96
  s21_decimal dec_2 = {{0x60, 0x0, 0x0, 0x0}};
  // -2382782370859074978077850720
  s21_decimal dec_check = {{0x2109bc60, 0x26fbb94a, 0x7b2fdcb, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_41) {
  // 5579039594942609760371355
  s21_decimal dec_1 = {{0xed9ec29b, 0x57ab85af, 0x49d68, 0x0}};
  // 48.0
  s21_decimal dec_2 = {{0x1e0, 0x0, 0x0, 0x10000}};
  // 267793900557245268497825040.0
  s21_decimal dec_check = {{0x89ace2a0, 0x619aa9dd, 0x8a723a4, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_42) {
  // 47178.5417
  s21_decimal dec_1 = {{0x1c1edfc9, 0x0, 0x0, 0x40000}};
  // 0.6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x10000}};
  // 28307.12502
  s21_decimal dec_check = {{0xa8b93eb6, 0x0, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_43) {
  // 4281616029370
  s21_decimal dec_1 = {{0xe433d6ba, 0x3e4, 0x0, 0x0}};
  // 257624245.9334055157042003
  s21_decimal dec_2 = {{0x1d680b53, 0x62312ec8, 0x2218a, 0x100000}};
  // 1103048100942828093591.4752679
  s21_decimal dec_check = {{0xfc694aa7, 0xb2f902cc, 0x23a43335, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_44) {
  // 16.7
  s21_decimal dec_1 = {{0xa7, 0x0, 0x0, 0x10000}};
  // -2912
  s21_decimal dec_2 = {{0xb60, 0x0, 0x0, 0x80000000}};
  // -48630.4
  s21_decimal dec_check = {{0x76ba0, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_45) {
  // -28.006
  s21_decimal dec_1 = {{0x6d66, 0x0, 0x0, 0x80030000}};
  // -8466388184883912740452
  s21_decimal dec_2 = {{0x9d38e64, 0xf6bd1d4e, 0x1ca, 0x80000000}};
  // 237109667505858860209098.712
  s21_decimal dec_check = {{0xfdeb4fd8, 0xd4d3e746, 0xc421ec, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_46) {
  // -678416853574555713383009
  s21_decimal dec_1 = {{0xd4dbaa61, 0xd239f84, 0x8fa9, 0x80000000}};
  // 28978
  s21_decimal dec_2 = {{0x7132, 0x0, 0x0, 0x0}};
  // -19659163582883475462412834802
  s21_decimal dec_check = {{0x891c17f2, 0x4a5ec9e6, 0x3f85add1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_47) {
  // 45909848
  s21_decimal dec_1 = {{0x2bc8758, 0x0, 0x0, 0x0}};
  // -7.698857
  s21_decimal dec_2 = {{0x7579a9, 0x0, 0x0, 0x80060000}};
  // -353453354.643736
  s21_decimal dec_check = {{0xc5a5f118, 0x14176, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_48) {
  // 177235.135100886063114
  s21_decimal dec_1 = {{0x9eae180a, 0x9ba1b057, 0x9, 0xf0000}};
  // 2700708
  s21_decimal dec_2 = {{0x2935a4, 0x0, 0x0, 0x0}};
  // 478660347248.043797740484712
  s21_decimal dec_check = {{0x8c1b7868, 0x6b1f85dd, 0x18bf045, 0xf0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_49) {
  // -84952407945281509681802
  s21_decimal dec_1 = {{0x8e6a8a, 0x477dc116, 0x11fd, 0x80000000}};
  // -325.9
  s21_decimal dec_2 = {{0xcbb, 0x0, 0x0, 0x80010000}};
  // 27685989749367244005299271.8
  s21_decimal dec_check = {{0x15064ace, 0x1de91319, 0xe5035d, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_50) {
  // -75027221.9883947
  s21_decimal dec_1 = {{0x5d26a9ab, 0x2aa5e, 0x0, 0x80070000}};
  // -790114
  s21_decimal dec_2 = {{0xc0e62, 0x0, 0x0, 0x80000000}};
  // 59280058474138.4899958
  s21_decimal dec_check = {{0xba184d76, 0x22c2bf07, 0x20, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_52) {
  // 9084067282193616
  s21_decimal dec_1 = {{0x3b788cd0, 0x2045e9, 0x0, 0x0}};
  // -4.02988508483284382
  s21_decimal dec_2 = {{0xd0b5ed9e, 0x597b3e9, 0x0, 0x80110000}};
  // -36607747250130081.214862893129
  s21_decimal dec_check = {{0x6f62a049, 0xeb689000, 0x76493802, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_53) {
  // 315319.742
  s21_decimal dec_1 = {{0x12cb65be, 0x0, 0x0, 0x30000}};
  // -1656
  s21_decimal dec_2 = {{0x678, 0x0, 0x0, 0x80000000}};
  // -522169492.752
  s21_decimal dec_check = {{0x93ba2510, 0x79, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_54) {
  // -1838045587216
  s21_decimal dec_1 = {{0xf40de710, 0x1ab, 0x0, 0x80000000}};
  // -9991.08994772
  s21_decimal dec_2 = {{0x9f8966d4, 0xe8, 0x0, 0x80080000}};
  // 18364078789884882.14034752
  s21_decimal dec_check = {{0x3d23b940, 0xdedf8a17, 0x184df, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_55) {
  // -0.305199
  s21_decimal dec_1 = {{0x4a82f, 0x0, 0x0, 0x80060000}};
  // -11809265328694
  s21_decimal dec_2 = {{0x8f10a236, 0xabd, 0x0, 0x80000000}};
  // 3604175969052.080106
  s21_decimal dec_check = {{0xb75937ea, 0x32049af2, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_56) {
  // 699305332690437
  s21_decimal dec_1 = {{0xb5f1ce05, 0x27c03, 0x0, 0x0}};
  // 8318295466
  s21_decimal dec_2 = {{0xefcf1daa, 0x1, 0x0, 0x0}};
  // 5817028378268483678658642
  s21_decimal dec_check = {{0x77f46052, 0xbd8171f4, 0x4cfcd, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_57) {
  // 4404717544514800811243
  s21_decimal dec_1 = {{0xdf8b7ceb, 0xc7bc458a, 0xee, 0x0}};
  // -10.86
  s21_decimal dec_2 = {{0x43e, 0x0, 0x0, 0x80020000}};
  // -47835232533430736810098.98
  s21_decimal dec_check = {{0x51bbecea, 0x50af0320, 0x3f4f3, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_58) {
  // 76140977738.0216115385501238
  s21_decimal dec_1 = {{0x34928636, 0xbd472356, 0x275d2ca, 0x100000}};
  // -8.366703230293
  s21_decimal dec_2 = {{0x65fbd55, 0x79c, 0x0, 0x800c0000}};
  // -637048964398.37281754663292250
  s21_decimal dec_check = {{0xf01b0d5a, 0xe6db3e68, 0xcdd7748b, 0x80110000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_59) {
  // -59153272
  s21_decimal dec_1 = {{0x3869b78, 0x0, 0x0, 0x80000000}};
  // 22358888273255434367
  s21_decimal dec_2 = {{0xc09887f, 0x364aba6c, 0x1, 0x0}};
  // -1322601399645489034589298824
  s21_decimal dec_check = {{0x5996e088, 0x8a993786, 0x44607bd, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_60) {
  // -184343319419096425436481.7230
  s21_decimal dec_1 = {{0xbb9e574e, 0xb2dd238a, 0x5f4da29, 0x80040000}};
  // -76.9
  s21_decimal dec_2 = {{0x301, 0x0, 0x0, 0x80010000}};
  // 14176001263328515116065444.499
  s21_decimal dec_check = {{0x22c95293, 0x57c865cc, 0x2dce1d08, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_61) {
  // -4.577
  s21_decimal dec_1 = {{0x11e1, 0x0, 0x0, 0x80030000}};
  // -53569453
  s21_decimal dec_2 = {{0x33167ad, 0x0, 0x0, 0x80000000}};
  // 245187386.381
  s21_decimal dec_check = {{0x164e9c0d, 0x39, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_62) {
  // -62171
  s21_decimal dec_1 = {{0xf2db, 0x0, 0x0, 0x80000000}};
  // -74256308656894279
  s21_decimal dec_2 = {{0x23d37147, 0x107cfb8, 0x0, 0x80000000}};
  // 4616588965507774219709
  s21_decimal dec_check = {{0x86f705bd, 0x440ac464, 0xfa, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_63) {
  // -506
  s21_decimal dec_1 = {{0x1fa, 0x0, 0x0, 0x80000000}};
  // -2345326196506404554
  s21_decimal dec_2 = {{0xe92ea6ca, 0x208c45bf, 0x0, 0x80000000}};
  // 1186735055432240704324
  s21_decimal dec_check = {{0xe635ab44, 0x5541dd52, 0x40, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_64) {
  // 2.6040
  s21_decimal dec_1 = {{0x65b8, 0x0, 0x0, 0x40000}};
  // 2596860821
  s21_decimal dec_2 = {{0x9ac8f395, 0x0, 0x0, 0x0}};
  // 6762225577.8840
  s21_decimal dec_check = {{0x8888dc18, 0x3d80, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_65) {
  // 458709108987141591
  s21_decimal dec_1 = {{0x186a1dd7, 0x65da981, 0x0, 0x0}};
  // -0.387412
  s21_decimal dec_2 = {{0x5e954, 0x0, 0x0, 0x80060000}};
  // -177709413330926498.052492
  s21_decimal dec_check = {{0x2d2d798c, 0xa58797a7, 0x25a1, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_66) {
  // 5
  s21_decimal dec_1 = {{0x5, 0x0, 0x0, 0x0}};
  // 5553492032126.2961709
  s21_decimal dec_2 = {{0xaa80442d, 0x2b3abcb, 0x3, 0x70000}};
  // 27767460160631.4808545
  s21_decimal dec_check = {{0x548154e1, 0xd825afa, 0xf, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_67) {
  // 75636279277.46469458148394114
  s21_decimal dec_1 = {{0x38990482, 0x8e865e73, 0x18707c83, 0x110000}};
  // -14
  s21_decimal dec_2 = {{0xe, 0x0, 0x0, 0x80000000}};
  // -1058907909884.5057241407751760
  s21_decimal dec_check = {{0xb5a30650, 0x2def5107, 0x223714b8, 0x80100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_68) {
  // -25054964448066217750827716
  s21_decimal dec_1 = {{0xe43412c4, 0x5824814d, 0x14b998, 0x80000000}};
  // -213
  s21_decimal dec_2 = {{0xd5, 0x0, 0x0, 0x80000000}};
  // 5336707427438104380926303508
  s21_decimal dec_check = {{0xdf539d14, 0x565f95ce, 0x113e6bc1, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_70) {
  // 2346.00
  s21_decimal dec_1 = {{0x39468, 0x0, 0x0, 0x20000}};
  // 84880820039004193405.7013114
  s21_decimal dec_2 = {{0x4e197f7a, 0xbe8bbd19, 0x2be1e20, 0x70000}};
  // 199130403811503837729775.27654
  s21_decimal dec_check = {{0xfa22fb66, 0x1a0bb589, 0x4057ae52, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_71) {
  // -427543192951
  s21_decimal dec_1 = {{0x8b8f6577, 0x63, 0x0, 0x80000000}};
  // -73648397.585833644874
  s21_decimal dec_2 = {{0xfc59d34a, 0xfe13ab65, 0x3, 0x800c0000}};
  // 31487871059572036614.552194083
  s21_decimal dec_check = {{0x8e528c23, 0x7c8fff52, 0x65be280e, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_72) {
  // -48282022591639500.758
  s21_decimal dec_1 = {{0xec0eb7d6, 0x9e0c33bc, 0x2, 0x80030000}};
  // -748529063383.8
  s21_decimal dec_2 = {{0xce16da6e, 0x6ce, 0x0, 0x80010000}};
  // 36140497148795387406844770145
  s21_decimal dec_check = {{0x8a3d3761, 0x2be7e028, 0x74c6b7f4, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_73) {
  // 94.9
  s21_decimal dec_1 = {{0x3b5, 0x0, 0x0, 0x10000}};
  // -296033001.124399
  s21_decimal dec_2 = {{0x8ddfb22f, 0x10d3d, 0x0, 0x80060000}};
  // -28093531806.7054651
  s21_decimal dec_check = {{0xee3f883b, 0x3e6152e, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_74) {
  // 600329.05148
  s21_decimal dec_1 = {{0xfa3d6fbc, 0xd, 0x0, 0x50000}};
  // -51341
  s21_decimal dec_2 = {{0xc88d, 0x0, 0x0, 0x80000000}};
  // -30821493832.03468
  s21_decimal dec_check = {{0xd3216a8c, 0xaf332, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_75) {
  // 6623516753947
  s21_decimal dec_1 = {{0x285d001b, 0x606, 0x0, 0x0}};
  // 7649
  s21_decimal dec_2 = {{0x1de1, 0x0, 0x0, 0x0}};
  // 50663279650940603
  s21_decimal dec_check = {{0x2c026bb, 0xb3fdfc, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_77) {
  // 9221
  s21_decimal dec_1 = {{0x2405, 0x0, 0x0, 0x0}};
  // -58672719114753337749706
  s21_decimal dec_2 = {{0xb83070ca, 0xa78bc57a, 0xc6c, 0x80000000}};
  // -541021142957140527390039026
  s21_decimal dec_check = {{0x68ce9bf2, 0xed801d4c, 0x1bf85ae, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_78) {
  // -556265970.018
  s21_decimal dec_1 = {{0x84091962, 0x81, 0x0, 0x80030000}};
  // 870015792
  s21_decimal dec_2 = {{0x33db6330, 0x0, 0x0, 0x0}};
  // -483960178467858524.256
  s21_decimal dec_check = {{0x835ba860, 0x3c4bf22f, 0x1a, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_79) {
  // -775581
  s21_decimal dec_1 = {{0xbd59d, 0x0, 0x0, 0x80000000}};
  // -2084763694427700040
  s21_decimal dec_2 = {{0xd6fe7b48, 0x1cee9188, 0x0, 0x80000000}};
  // 1616903110887930024723240
  s21_decimal dec_check = {{0xe2bc8328, 0x7e4758bc, 0x15664, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_80) {
  // 5287.49140
  s21_decimal dec_1 = {{0x1f841254, 0x0, 0x0, 0x50000}};
  // -894884468
  s21_decimal dec_2 = {{0x3556da74, 0x0, 0x0, 0x80000000}};
  // -4731693928543.57520
  s21_decimal dec_check = {{0x4babd610, 0x691090e, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_81) {
  // -6358649563049
  s21_decimal dec_1 = {{0x7d0c67a9, 0x5c8, 0x0, 0x80000000}};
  // 13437812
  s21_decimal dec_2 = {{0xcd0b74, 0x0, 0x0, 0x0}};
  // -85446337402134608788
  s21_decimal dec_check = {{0x34683b94, 0xa1ce5f27, 0x4, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_82) {
  // -56561596.6481710276481041
  s21_decimal dec_1 = {{0x274d1011, 0x1a5d114a, 0x77c6, 0x80100000}};
  // -7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x80000000}};
  // 395931176.5371971935367287
  s21_decimal dec_check = {{0x131b7077, 0xb88b7907, 0x3466a, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_83) {
  // -826749854
  s21_decimal dec_1 = {{0x3147339e, 0x0, 0x0, 0x80000000}};
  // -503268755865890462
  s21_decimal dec_2 = {{0x5bf06e9e, 0x6fbf844, 0x0, 0x80000000}};
  // 416077370434886583038492548
  s21_decimal dec_check = {{0x903fbf84, 0x72875d5c, 0x1582bcf, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_84) {
  // -4.39
  s21_decimal dec_1 = {{0x1b7, 0x0, 0x0, 0x80020000}};
  // -7732460840.151901783785
  s21_decimal dec_2 = {{0xe8a7c6e9, 0x2d7365c8, 0x1a3, 0x800c0000}};
  // 33945503088.26684883081615
  s21_decimal dec_check = {{0xf7b6198f, 0xf0e38b86, 0x2ced2, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_85) {
  // 134.6
  s21_decimal dec_1 = {{0x542, 0x0, 0x0, 0x10000}};
  // -166725865
  s21_decimal dec_2 = {{0x9f008e9, 0x0, 0x0, 0x80000000}};
  // -22441301429.0
  s21_decimal dec_check = {{0x400ed912, 0x34, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_86) {
  // -27377
  s21_decimal dec_1 = {{0x6af1, 0x0, 0x0, 0x80000000}};
  // -8843119076.8164115857849
  s21_decimal dec_2 = {{0xc8f041b9, 0xdd4d131d, 0x12b9, 0x800d0000}};
  // 242098070966002.8999840332073
  s21_decimal dec_check = {{0xa5647929, 0x3f79543d, 0x7d2969b, 0xd0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_87) {
  // -7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x80000000}};
  // 0.4412
  s21_decimal dec_2 = {{0x113c, 0x0, 0x0, 0x40000}};
  // -3.0884
  s21_decimal dec_check = {{0x78a4, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_88) {
  // -898.13389522567969
  s21_decimal dec_1 = {{0x4a910321, 0x13f14cd, 0x0, 0x800e0000}};
  // -493538411
  s21_decimal dec_2 = {{0x1d6acc6b, 0x0, 0x0, 0x80000000}};
  // 443263575514.92244059757259
  s21_decimal dec_check = {{0xc1c49acb, 0xa864969f, 0x24aa78, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_89) {
  // 65252408234202084579916
  s21_decimal dec_1 = {{0x557a9a4c, 0x57134eee, 0xdd1, 0x0}};
  // -211
  s21_decimal dec_2 = {{0xd3, 0x0, 0x0, 0x80000000}};
  // -13768258137416639846362276
  s21_decimal dec_check = {{0x740d2ca4, 0xc4ea0e70, 0xb638a, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_90) {
  // -7.31899
  s21_decimal dec_1 = {{0xb2afb, 0x0, 0x0, 0x80050000}};
  // -676373867209774630309549295
  s21_decimal dec_2 = {{0x9d4954ef, 0xcfe35c24, 0x22f7bbc, 0x80000000}};
  // 4950373570369668421489288194.6
  s21_decimal dec_check = {{0xc54be81a, 0xce07f39c, 0x9ff487c9, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_91) {
  // 48623527969722869772
  s21_decimal dec_1 = {{0xe99a280c, 0xa2c97911, 0x2, 0x0}};
  // -14893
  s21_decimal dec_2 = {{0x3a2d, 0x0, 0x0, 0x80000000}};
  // -724150202053082699514396
  s21_decimal dec_check = {{0xfd2bc21c, 0x42d85712, 0x9958, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_92) {
  // -0.8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x80010000}};
  // -0.9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x80010000}};
  // 0.72
  s21_decimal dec_check = {{0x48, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_93) {
  // -3370637455622
  s21_decimal dec_1 = {{0xc9a5f106, 0x310, 0x0, 0x80000000}};
  // -6.7077106366958373821
  s21_decimal dec_2 = {{0xdba58bbd, 0xa2e1c0d9, 0x3, 0x80130000}};
  // 22609260713521.082938720217407
  s21_decimal dec_check = {{0x45f3693f, 0x31cd2007, 0x490df12f, 0xf0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_94) {
  // -93
  s21_decimal dec_1 = {{0x5d, 0x0, 0x0, 0x80000000}};
  // 75.09113631515029378137
  s21_decimal dec_2 = {{0xb0d19459, 0x11e2b6df, 0x197, 0x140000}};
  // -6983.47567730897732166741
  s21_decimal dec_check = {{0x3c22e455, 0x7f5c6f43, 0x93e1, 0x80140000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_95) {
  // -0.2341
  s21_decimal dec_1 = {{0x925, 0x0, 0x0, 0x80040000}};
  // 35326281957335442168
  s21_decimal dec_2 = {{0x64522f8, 0xea402a46, 0x1, 0x0}};
  // -8269882606212227011.5288
  s21_decimal dec_check = {{0x5638c5d8, 0x1cc29257, 0x1183, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_96) {
  // 6.31456457256
  s21_decimal dec_1 = {{0x5bce228, 0x93, 0x0, 0xb0000}};
  // 92546
  s21_decimal dec_2 = {{0x16982, 0x0, 0x0, 0x0}};
  // 584387.69293213776
  s21_decimal dec_check = {{0x44d54050, 0xcf9dc0, 0x0, 0xb0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_97) {
  // 64002
  s21_decimal dec_1 = {{0xfa02, 0x0, 0x0, 0x0}};
  // 808344687314314.23251057812
  s21_decimal dec_2 = {{0xa8800c94, 0x549cba50, 0x42dd5d, 0xb0000}};
  // 51735676677490739509.142020836
  s21_decimal dec_check = {{0xc89ce2e4, 0x6fe966f8, 0xa72abfac, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_98) {
  // 537486473
  s21_decimal dec_1 = {{0x20096489, 0x0, 0x0, 0x0}};
  // -7.85283
  s21_decimal dec_2 = {{0xbfb83, 0x0, 0x0, 0x80050000}};
  // -4220789899.76859
  s21_decimal dec_check = {{0xec43c51b, 0x17fe0, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_99) {
  // 7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x0}};
  // 3233074535324198
  s21_decimal dec_2 = {{0xd335da26, 0xb7c76, 0x0, 0x0}};
  // 22631521747269386
  s21_decimal dec_check = {{0xc678f70a, 0x50673f, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_100) {
  // -88424.361106526872670623
  s21_decimal dec_1 = {{0xd8f2119f, 0x7e853e0a, 0x12b9, 0x80120000}};
  // -991
  s21_decimal dec_2 = {{0x3df, 0x0, 0x0, 0x80000000}};
  // 87628541.856568130816587393
  s21_decimal dec_check = {{0xd1123681, 0xc5cb2bfd, 0x487c10, 0x120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_101) {
  // 1380299034821
  s21_decimal dec_1 = {{0x603bd0c5, 0x141, 0x0, 0x0}};
  // 175
  s21_decimal dec_2 = {{0xaf, 0x0, 0x0, 0x0}};
  // 241552331093675
  s21_decimal dec_check = {{0xc8e3b6ab, 0xdbb0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_102) {
  // -668855.668
  s21_decimal dec_1 = {{0x27dded74, 0x0, 0x0, 0x80030000}};
  // -0.881
  s21_decimal dec_2 = {{0x371, 0x0, 0x0, 0x80030000}};
  // 589261.843508
  s21_decimal dec_check = {{0x32be2c34, 0x89, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_103) {
  // -78.969
  s21_decimal dec_1 = {{0x13479, 0x0, 0x0, 0x80030000}};
  // -56838420786038733970908994
  s21_decimal dec_2 = {{0xf5d8a742, 0xf6fffa80, 0x2f0400, 0x80000000}};
  // 4488473251052692782948712347.2
  s21_decimal dec_check = {{0x9190fc10, 0xf79a90c9, 0x9107c7d0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_104) {
  // 1.9977844802795159780
  s21_decimal dec_1 = {{0x407d40e4, 0x153f9000, 0x1, 0x130000}};
  // 2.5
  s21_decimal dec_2 = {{0x19, 0x0, 0x0, 0x10000}};
  // 4.99446120069878994500
  s21_decimal dec_check = {{0x4c3b5644, 0x13351006, 0x1b, 0x140000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_105) {
  // -4661.49464755105040887
  s21_decimal dec_1 = {{0xd68209f7, 0x451f946d, 0x19, 0x80110000}};
  // -580.78322674416391806079
  s21_decimal dec_2 = {{0x7fdbdc7f, 0x6ea3683d, 0xc4c, 0x80140000}};
  // 2707317.9028553481770931286515
  s21_decimal dec_check = {{0x53d371f3, 0xf13ccfed, 0x577a68a7, 0x160000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_106) {
  // 70626227.44907865671146004417
  s21_decimal dec_1 = {{0x49cddfc1, 0x2c79b71d, 0x16d2108a, 0x140000}};
  // 5664188880.818056
  s21_decimal dec_2 = {{0xbe2e8f88, 0x141f8c, 0x0, 0x60000}};
  // 400040292211198302.71247284035
  s21_decimal dec_check = {{0xac7c7743, 0x7c4f5ebb, 0x81428eb1, 0xb0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_107) {
  // -479
  s21_decimal dec_1 = {{0x1df, 0x0, 0x0, 0x80000000}};
  // -997225611301655713920.61
  s21_decimal dec_2 = {{0xcf8b923d, 0xf88b031c, 0x151d, 0x80020000}};
  // 477671067813493086967972.19
  s21_decimal dec_check = {{0x5626a023, 0xc1ad2e8, 0x278314, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_108) {
  // -916658901518.2815092
  s21_decimal dec_1 = {{0x83f82f74, 0x7f364424, 0x0, 0x80070000}};
  // -13.43650957057
  s21_decimal dec_2 = {{0xd7d68701, 0x138, 0x0, 0x800b0000}};
  // 12316696103198.572602185263504
  s21_decimal dec_check = {{0xff9ca990, 0xa5866525, 0x27cc21d9, 0xf0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_109) {
  // 5904
  s21_decimal dec_1 = {{0x1710, 0x0, 0x0, 0x0}};
  // -573728.6771956040
  s21_decimal dec_2 = {{0x2c045948, 0x146208, 0x0, 0x800a0000}};
  // -3387294110.1628460160
  s21_decimal dec_check = {{0x244b0c80, 0xd614dc77, 0x1, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_110) {
  // 608.949
  s21_decimal dec_1 = {{0x94ab5, 0x0, 0x0, 0x30000}};
  // 9780579.2474938
  s21_decimal dec_2 = {{0x2f84773a, 0x58f4, 0x0, 0x70000}};
  // 5955873952.1821020162
  s21_decimal dec_check = {{0x14291002, 0x3a8b260a, 0x3, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_111) {
  // -75871263914862
  s21_decimal dec_1 = {{0x27bbfb6e, 0x4501, 0x0, 0x80000000}};
  // -1970865
  s21_decimal dec_2 = {{0x1e12b1, 0x0, 0x0, 0x80000000}};
  // 149532018555564495630
  s21_decimal dec_check = {{0x278a930e, 0x1b2c729f, 0x8, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_112) {
  // -9663018006912461.2020071499
  s21_decimal dec_1 = {{0xd8c16c4b, 0x8ed488d7, 0x4fee3c, 0x800a0000}};
  // 24.2734
  s21_decimal dec_2 = {{0x3b42e, 0x0, 0x0, 0x40000}};
  // -234554301288988935.74080035238
  s21_decimal dec_check = {{0xfabf9a6, 0x1de07ef3, 0x4bc9e087, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_113) {
  // -619575604005624.8124149113036
  s21_decimal dec_1 = {{0x9e50a0cc, 0xf0e2a835, 0x1405025f, 0x800d0000}};
  // -820856904432.3
  s21_decimal dec_2 = {{0x34d78d63, 0x777, 0x0, 0x80010000}};
  // 508582912365829715716116462.51
  s21_decimal dec_check = {{0x8a20392b, 0x6153f76b, 0xa454fe14, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_114) {
  // 7048062.88321731597511666
  s21_decimal dec_1 = {{0x95bd2bf2, 0xa01d6cdb, 0x953f, 0x110000}};
  // 0.6752450596
  s21_decimal dec_2 = {{0x927a3824, 0x1, 0x0, 0xa0000}};
  // 4759169.6416426243653696811987
  s21_decimal dec_check = {{0xcadcf3d3, 0x59164c02, 0x99c6edb8, 0x160000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_115) {
  // 943820.7939552653450092
  s21_decimal dec_1 = {{0x1b619b6c, 0xa5727341, 0x1ff, 0x100000}};
  // 30588.3
  s21_decimal dec_2 = {{0x4aadb, 0x0, 0x0, 0x10000}};
  // 28869873591.74184295274491236
  s21_decimal dec_check = {{0xab65ad64, 0x56764267, 0x9540f5a, 0x110000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_116) {
  // 73949339961
  s21_decimal dec_1 = {{0x37b96139, 0x11, 0x0, 0x0}};
  // -262371393881548.4474411422
  s21_decimal dec_2 = {{0xc49fc99e, 0xd14fb076, 0x22b97, 0x800a0000}};
  // -19402191402188061504916765.086
  s21_decimal dec_check = {{0x3ae5399e, 0x762aff5b, 0x3eb11dd7, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_117) {
  // 45719861291
  s21_decimal dec_1 = {{0xa51db82b, 0xa, 0x0, 0x0}};
  // 2142056
  s21_decimal dec_2 = {{0x20af68, 0x0, 0x0, 0x0}};
  // 97934503197554296
  s21_decimal dec_check = {{0x6a583678, 0x15beee9, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_118) {
  // -5
  s21_decimal dec_1 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 72.891406
  s21_decimal dec_2 = {{0x4583c0e, 0x0, 0x0, 0x60000}};
  // -364.457030
  s21_decimal dec_check = {{0x15b92c46, 0x0, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_119) {
  // 8934718770915
  s21_decimal dec_1 = {{0x46bd0ee3, 0x820, 0x0, 0x0}};
  // -7099396
  s21_decimal dec_2 = {{0x6c5404, 0x0, 0x0, 0x80000000}};
  // -63431106703358867340
  s21_decimal dec_check = {{0x6b9ab78c, 0x70488f79, 0x3, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_120) {
  // -36409791738124
  s21_decimal dec_1 = {{0x50b3f10c, 0x211d, 0x0, 0x80000000}};
  // 29127
  s21_decimal dec_2 = {{0x71c7, 0x0, 0x0, 0x0}};
  // -1060508003956337748
  s21_decimal dec_check = {{0x2946ac54, 0xeb7ae69, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_121) {
  // 522
  s21_decimal dec_1 = {{0x20a, 0x0, 0x0, 0x0}};
  // 537458
  s21_decimal dec_2 = {{0x83372, 0x0, 0x0, 0x0}};
  // 280553076
  s21_decimal dec_check = {{0x10b8e674, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_122) {
  // 8141426283343314161
  s21_decimal dec_1 = {{0xcfb4fcf1, 0x70fc2811, 0x0, 0x0}};
  // -23757
  s21_decimal dec_2 = {{0x5ccd, 0x0, 0x0, 0x80000000}};
  // -193415864213387114522877
  s21_decimal dec_check = {{0x5ed528fd, 0x18527ce8, 0x28f5, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_123) {
  // 90338310212364.0568
  s21_decimal dec_1 = {{0x222b86f8, 0xc897625, 0x0, 0x40000}};
  // -52739
  s21_decimal dec_2 = {{0xce03, 0x0, 0x0, 0x80000000}};
  // -4764352142289867991.5752
  s21_decimal dec_check = {{0x6d1e24e8, 0xc2ae43ee, 0xa16, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_124) {
  // -13324768.8040514780
  s21_decimal dec_1 = {{0xf8cc04dc, 0x1d96410, 0x0, 0x800a0000}};
  // 74972887122
  s21_decimal dec_2 = {{0x74bb7852, 0x11, 0x0, 0x0}};
  // -998996387472898396.3712663160
  s21_decimal dec_check = {{0x9054ae78, 0xcd3883e6, 0x20478122, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_125) {
  // -0.97
  s21_decimal dec_1 = {{0x61, 0x0, 0x0, 0x80020000}};
  // 738027344522870.2786
  s21_decimal dec_2 = {{0x981aec42, 0x666bff98, 0x0, 0x40000}};
  // -715886524187184.170242
  s21_decimal dec_check = {{0xa2338502, 0xceebd8d1, 0x26, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_127) {
  // -80825
  s21_decimal dec_1 = {{0x13bb9, 0x0, 0x0, 0x80000000}};
  // -1702810043.333946664169
  s21_decimal dec_2 = {{0xb76864e9, 0x4f3c8889, 0x5c, 0x800c0000}};
  // 137629621752466.239131459425
  s21_decimal dec_check = {{0xfe9b9f61, 0xbec02032, 0x71d834, 0xc0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_128) {
  // 7998
  s21_decimal dec_1 = {{0x1f3e, 0x0, 0x0, 0x0}};
  // -623462550373245099800703
  s21_decimal dec_2 = {{0xc5e5787f, 0xf8faee4d, 0x8405, 0x80000000}};
  // -4986453477885214308206022594
  s21_decimal dec_check = {{0xb72a8fc2, 0xafa121cc, 0x101cb298, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_129) {
  // -54871.610410
  s21_decimal dec_1 = {{0xc69a542a, 0xc, 0x0, 0x80060000}};
  // -93336.5561120822276791080
  s21_decimal dec_2 = {{0x3e961b28, 0xd93450b4, 0xc5a5, 0x80130000}};
  // 5121527143.9932802910929326723
  s21_decimal dec_check = {{0x4e409283, 0xfb01e58d, 0xa57c4793, 0x130000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_130) {
  // -3096.5460702620940808752
  s21_decimal dec_1 = {{0xd6f8b230, 0xa417cefd, 0x68e, 0x80130000}};
  // 2119926366
  s21_decimal dec_2 = {{0x7e5b825e, 0x0, 0x0, 0x0}};
  // -6564449657882.3017724198728355
  s21_decimal dec_check = {{0xa87f32a3, 0x1fb53881, 0xd41bdada, 0x80100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_131) {
  // -3134.4292916152
  s21_decimal dec_1 = {{0xe971ebb8, 0x1c81, 0x0, 0x800a0000}};
  // -8997
  s21_decimal dec_2 = {{0x2325, 0x0, 0x0, 0x80000000}};
  // 28200460.3366619544
  s21_decimal dec_check = {{0x50b13998, 0x3e9e1b1, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_132) {
  // -6923
  s21_decimal dec_1 = {{0x1b0b, 0x0, 0x0, 0x80000000}};
  // 21.2
  s21_decimal dec_2 = {{0xd4, 0x0, 0x0, 0x10000}};
  // -146767.6
  s21_decimal dec_check = {{0x16651c, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_133) {
  // -831354907313
  s21_decimal dec_1 = {{0x909d2ab1, 0xc1, 0x0, 0x80000000}};
  // 168.59347264435033167440497
  s21_decimal dec_2 = {{0xf1892a71, 0xbea0192, 0xdf21b, 0x170000}};
  // -140161010823820.67100227575193
  s21_decimal dec_check = {{0x10959d99, 0x2a2d46cc, 0x2d49d8da, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_134) {
  // -81617668855876
  s21_decimal dec_1 = {{0x1828d844, 0x4a3b, 0x0, 0x80000000}};
  // -18537.1109024261384
  s21_decimal dec_2 = {{0xa102e508, 0x292920a, 0x0, 0x800d0000}};
  // 1512955779178865289.1781248292
  s21_decimal dec_check = {{0xbad0b524, 0x54823f8f, 0x30e2e07b, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_135) {
  // -5323399474676
  s21_decimal dec_1 = {{0x7355adf4, 0x4d7, 0x0, 0x80000000}};
  // -573.52
  s21_decimal dec_2 = {{0xe008, 0x0, 0x0, 0x80020000}};
  // 3053076066716179.52
  s21_decimal dec_check = {{0x92e2efa0, 0x43caba6, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_136) {
  // 1551181.9
  s21_decimal dec_1 = {{0xecb10b, 0x0, 0x0, 0x10000}};
  // 0.8134066041383
  s21_decimal dec_2 = {{0xdc1df227, 0x765, 0x0, 0xd0000}};
  // 1261741.60167979605677
  s21_decimal dec_check = {{0x65aa5ead, 0xd704aa2c, 0x6, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_137) {
  // 7282658442932172742726
  s21_decimal dec_1 = {{0x2f8de046, 0xcb3044ab, 0x18a, 0x0}};
  // -300
  s21_decimal dec_2 = {{0x12c, 0x0, 0x0, 0x80000000}};
  // -2184797532879651822817800
  s21_decimal dec_check = {{0xba42d208, 0x1c90789b, 0x1cea6, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_138) {
  // 2566161651522941469
  s21_decimal dec_1 = {{0xb41321d, 0x239cd66d, 0x0, 0x0}};
  // -84094495.611877582742963
  s21_decimal dec_2 = {{0xf900a5b3, 0xc590df44, 0x11ce, 0x800f0000}};
  // -215800069743364532011660357.68
  s21_decimal dec_check = {{0x45436b38, 0x30ff53f1, 0x45ba903a, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_139) {
  // -61675162844.46024
  s21_decimal dec_1 = {{0xc947e548, 0x15e952, 0x0, 0x80050000}};
  // 7.65
  s21_decimal dec_2 = {{0x2fd, 0x0, 0x0, 0x20000}};
  // -471814995760.1208360
  s21_decimal dec_check = {{0x7bd82828, 0x417a3c63, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_140) {
  // 8468.645327344154897851175
  s21_decimal dec_1 = {{0xb70a327, 0x2edf5d93, 0x7014e, 0x150000}};
  // 629.4
  s21_decimal dec_2 = {{0x1896, 0x0, 0x0, 0x10000}};
  // 5330165.3690304110927075295450
  s21_decimal dec_check = {{0x434b40da, 0x67a69d3b, 0xac3a1834, 0x160000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_141) {
  // 8766.09683713
  s21_decimal dec_1 = {{0x1a024101, 0xcc, 0x0, 0x80000}};
  // -94798
  s21_decimal dec_2 = {{0x1724e, 0x0, 0x0, 0x80000000}};
  // -831008447.96624974
  s21_decimal dec_check = {{0x2ea3404e, 0x1273bc7, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_142) {
  // -6843
  s21_decimal dec_1 = {{0x1abb, 0x0, 0x0, 0x80000000}};
  // 74187796300801.1298
  s21_decimal dec_2 = {{0xa3c86c22, 0xa4bae13, 0x0, 0x40000}};
  // -507667090086382131.2214
  s21_decimal dec_check = {{0xfe6270d6, 0x34f626fa, 0x113, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_143) {
  // -995.0198532601551487548
  s21_decimal dec_1 = {{0x6887823c, 0x66be6efd, 0x21b, 0x80130000}};
  // 0.01
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x20000}};
  // -9.950198532601551487548
  s21_decimal dec_check = {{0x6887823c, 0x66be6efd, 0x21b, 0x80150000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_144) {
  // 18.29555
  s21_decimal dec_1 = {{0x1beab3, 0x0, 0x0, 0x50000}};
  // 661.59
  s21_decimal dec_2 = {{0x1026f, 0x0, 0x0, 0x20000}};
  // 12104.1529245
  s21_decimal dec_check = {{0x2ea3299d, 0x1c, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_145) {
  // 1145412342345553241222
  s21_decimal dec_1 = {{0x66d16486, 0x17ca18b5, 0x3e, 0x0}};
  // -12.4102592878
  s21_decimal dec_2 = {{0xe517496e, 0x1c, 0x0, 0x800a0000}};
  // -14214864159954655348904.719322
  s21_decimal dec_check = {{0xf38073da, 0x30c1e558, 0x2dee4292, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_146) {
  // -521283
  s21_decimal dec_1 = {{0x7f443, 0x0, 0x0, 0x80000000}};
  // 1562900
  s21_decimal dec_2 = {{0x17d914, 0x0, 0x0, 0x0}};
  // -814713200700
  s21_decimal dec_check = {{0xb0b0e03c, 0xbd, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_147) {
  // 8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x0}};
  // -69016370484278.8328432687
  s21_decimal dec_2 = {{0xb4bbe42f, 0xd972ce7d, 0x9225, 0x800a0000}};
  // -552130963874230.6627461496
  s21_decimal dec_check = {{0xa5df2178, 0xcb9673ed, 0x4912e, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_148) {
  // -0.5834658
  s21_decimal dec_1 = {{0x5907a2, 0x0, 0x0, 0x80070000}};
  // 41341242777889803666886
  s21_decimal dec_2 = {{0xf8e505c6, 0x1cfeb732, 0x8c1, 0x0}};
  // -24121201290395696608342.573499
  s21_decimal dec_check = {{0x46fe01bb, 0x19b115de, 0x4df0970e, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_149) {
  // -51761159
  s21_decimal dec_1 = {{0x315d007, 0x0, 0x0, 0x80000000}};
  // -6842718201380.1
  s21_decimal dec_2 = {{0xf1e07d69, 0x3e3b, 0x0, 0x80010000}};
  // 354187024813829375535.9
  s21_decimal dec_check = {{0x87a5bddf, 0x152e10c, 0xc0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_150) {
  // -75381.0795783
  s21_decimal dec_1 = {{0x829fed07, 0xaf, 0x0, 0x80070000}};
  // -714008570762306204072698.62
  s21_decimal dec_2 = {{0x492609e6, 0x37cccdd7, 0x3b0fb8, 0x80020000}};
  // 53822736892221650663235894233
  s21_decimal dec_check = {{0xe0d7bbd9, 0x62143894, 0xade91fdd, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_151) {
  // 4915
  s21_decimal dec_1 = {{0x1333, 0x0, 0x0, 0x0}};
  // 2326027997325898
  s21_decimal dec_2 = {{0x9884aa4a, 0x84382, 0x0, 0x0}};
  // 11432427606856788670
  s21_decimal dec_check = {{0x3b116abe, 0x9ea82456, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_152) {
  // 3.3133
  s21_decimal dec_1 = {{0x816d, 0x0, 0x0, 0x40000}};
  // -9674591283509146.85048
  s21_decimal dec_2 = {{0xc150a878, 0x7231476a, 0x34, 0x80050000}};
  // -32054823299650856.259695384
  s21_decimal dec_check = {{0xf43c3318, 0x73f833dd, 0x1a83df, 0x80090000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_153) {
  // 5792135130683
  s21_decimal dec_1 = {{0x96282e3b, 0x544, 0x0, 0x0}};
  // -693393
  s21_decimal dec_2 = {{0xa9491, 0x0, 0x0, 0x80000000}};
  // -4016225954669677419
  s21_decimal dec_check = {{0x15ca4b6b, 0x37bc803a, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_155) {
  // 5.605227281792476
  s21_decimal dec_1 = {{0xad043ddc, 0x13e9ec, 0x0, 0xf0000}};
  // 1834620990
  s21_decimal dec_2 = {{0x6d5a183e, 0x0, 0x0, 0x0}};
  // 10283467624.897121293671240
  s21_decimal dec_check = {{0xb82b9b48, 0xe5a0795e, 0x8819b, 0xf0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_156) {
  // 154601755832.9864066705841962
  s21_decimal dec_1 = {{0xe6c2df2a, 0xc5a84267, 0x4fed5f3, 0x100000}};
  // 900344
  s21_decimal dec_2 = {{0xdbcf8, 0x0, 0x0, 0x0}};
  // 139194763253694313.32742045754
  s21_decimal dec_check = {{0x2f71203a, 0x975fb5f9, 0x2cf9ebc3, 0xb0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_157) {
  // 58389810038479375070
  s21_decimal dec_1 = {{0x1619cade, 0x2a5246de, 0x3, 0x0}};
  // -84.0024
  s21_decimal dec_2 = {{0xcd158, 0x0, 0x0, 0x80040000}};
  // -4904884178776359856380.1680
  s21_decimal dec_check = {{0x29e4fa50, 0xa8cb598, 0x28927f, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_159) {
  // 9405.0908131717723
  s21_decimal dec_1 = {{0x79fe725b, 0x14e22cd, 0x0, 0xd0000}};
  // 533.033
  s21_decimal dec_2 = {{0x82229, 0x0, 0x0, 0x30000}};
  // 5013223.7714173893043859
  s21_decimal dec_check = {{0xe7c86693, 0xac8ead0f, 0xa9d, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_160) {
  // 582926477227855234122
  s21_decimal dec_1 = {{0xd824c44a, 0x99bade8f, 0x1f, 0x0}};
  // 319970
  s21_decimal dec_2 = {{0x4e1e2, 0x0, 0x0, 0x0}};
  // 186518984918596839262016340
  s21_decimal dec_check = {{0x32225354, 0x6ed44888, 0x9a48ee, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_161) {
  // -0.4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x80010000}};
  // -9829.57337392632114
  s21_decimal dec_2 = {{0x8ca6d132, 0xda42a7d, 0x0, 0x800e0000}};
  // 3931.829349570528456
  s21_decimal dec_check = {{0x329b44c8, 0x3690a9f6, 0x0, 0xf0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_162) {
  // -80626.79
  s21_decimal dec_1 = {{0x7b06d7, 0x0, 0x0, 0x80020000}};
  // 95220902567479
  s21_decimal dec_2 = {{0x58129e37, 0x569a, 0x0, 0x0}};
  // -7677355714918590162.41
  s21_decimal dec_check = {{0x6bc52a31, 0x9e78aaa2, 0x29, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_163) {
  // -303506552
  s21_decimal dec_1 = {{0x12172478, 0x0, 0x0, 0x80000000}};
  // 106
  s21_decimal dec_2 = {{0x6a, 0x0, 0x0, 0x0}};
  // -32171694512
  s21_decimal dec_check = {{0x7d9519b0, 0x7, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_164) {
  // 6222.206280572776240
  s21_decimal dec_1 = {{0x40beaf30, 0x5659b7a5, 0x0, 0xf0000}};
  // -55655880541375552433
  s21_decimal dec_2 = {{0x9243dbb1, 0x4616879, 0x3, 0x80000000}};
  // -346302369455355128177460.13259
  s21_decimal dec_check = {{0x340f6c4b, 0x807a7e89, 0x6fe575ea, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_165) {
  // -0.76
  s21_decimal dec_1 = {{0x4c, 0x0, 0x0, 0x80020000}};
  // 9365119555783
  s21_decimal dec_2 = {{0x7c9fd8c7, 0x884, 0x0, 0x0}};
  // -7117490862395.08
  s21_decimal dec_check = {{0xff745b14, 0x28754, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_166) {
  // -840361.1462
  s21_decimal dec_1 = {{0xf4e4ef46, 0x1, 0x0, 0x80040000}};
  // -137934116156
  s21_decimal dec_2 = {{0x1d83953c, 0x20, 0x0, 0x80000000}};
  // 115914471952940098.0072
  s21_decimal dec_check = {{0x3bdd268, 0xd65d4d00, 0x3e, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_167) {
  // 0.00551
  s21_decimal dec_1 = {{0x227, 0x0, 0x0, 0x50000}};
  // 347529
  s21_decimal dec_2 = {{0x54d89, 0x0, 0x0, 0x0}};
  // 1914.88479
  s21_decimal dec_check = {{0xb69e1df, 0x0, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_168) {
  // 9667544650
  s21_decimal dec_1 = {{0x403b064a, 0x2, 0x0, 0x0}};
  // -652080746806
  s21_decimal dec_2 = {{0xd30a9136, 0x97, 0x0, 0x80000000}};
  // -6304019735152349887900
  s21_decimal dec_check = {{0x37e73d9c, 0xbdd924fe, 0x155, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_169) {
  // -71522537.2473291
  s21_decimal dec_1 = {{0x6242b7cb, 0x28a7e, 0x0, 0x80070000}};
  // -72394.73233878
  s21_decimal dec_2 = {{0x923affd6, 0x695, 0x0, 0x80080000}};
  // 5177854940210.813078951352498
  s21_decimal dec_check = {{0x2d6d8b2, 0xbfe3b49d, 0x10bb056e, 0xf0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_170) {
  // -681800.89
  s21_decimal dec_1 = {{0x4105879, 0x0, 0x0, 0x80020000}};
  // 6.932530085088982899
  s21_decimal dec_2 = {{0xdc6ff773, 0x60354b61, 0x0, 0x120000}};
  // -4726605.18196544426973298011
  s21_decimal dec_check = {{0xf12b7d5b, 0x8a9cbe4, 0x186f9c2, 0x80140000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_171) {
  // 59592
  s21_decimal dec_1 = {{0xe8c8, 0x0, 0x0, 0x0}};
  // -878395
  s21_decimal dec_2 = {{0xd673b, 0x0, 0x0, 0x80000000}};
  // -52345314840
  s21_decimal dec_check = {{0x30061e18, 0xc, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_172) {
  // -6200518
  s21_decimal dec_1 = {{0x5e9cc6, 0x0, 0x0, 0x80000000}};
  // 237307211108556.186105
  s21_decimal dec_2 = {{0x1c1fa1f9, 0xdd4c9332, 0xc, 0x60000}};
  // -1471427634008402585955.402390
  s21_decimal dec_check = {{0x80990296, 0xdf52b582, 0x4c122eb, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_173) {
  // 22433.7276715442
  s21_decimal dec_1 = {{0x97b041b2, 0xcc08, 0x0, 0xa0000}};
  // 554902.105182012318894
  s21_decimal dec_2 = {{0x6a4a24ae, 0x14d04caa, 0x1e, 0xf0000}};
  // 12448522712.019839975475255020
  s21_decimal dec_check = {{0x62ee16ec, 0x6e2b9830, 0x28392d38, 0x120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_174) {
  // 14011.0
  s21_decimal dec_1 = {{0x2234e, 0x0, 0x0, 0x10000}};
  // 8.27
  s21_decimal dec_2 = {{0x33b, 0x0, 0x0, 0x20000}};
  // 115870.970
  s21_decimal dec_check = {{0x6e80cfa, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_175) {
  // 0.23764921214798783426690019
  s21_decimal dec_1 = {{0x13997be3, 0xf5e36e8e, 0x13a86a, 0x1a0000}};
  // -3111954293.106
  s21_decimal dec_2 = {{0x8eee2172, 0x2d4, 0x0, 0x80030000}};
  // -739553485.99718930864633926451
  s21_decimal dec_check = {{0x40dd333, 0xefd8eafd, 0xeef66e38, 0x80140000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_176) {
  // 61510894923951.39986452
  s21_decimal dec_1 = {{0xea26f414, 0x7383c776, 0x14d, 0x80000}};
  // -5238944.235663997076669
  s21_decimal dec_2 = {{0x60e504bd, 0xf4d938, 0x11c, 0x800f0000}};
  // -322252148392369004153.20459562
  s21_decimal dec_check = {{0x61cd892a, 0xe029d255, 0x682012ac, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_177) {
  // 69655506
  s21_decimal dec_1 = {{0x426dbd2, 0x0, 0x0, 0x0}};
  // 54503
  s21_decimal dec_2 = {{0xd4e7, 0x0, 0x0, 0x0}};
  // 3796434043518
  s21_decimal dec_check = {{0xed1a427e, 0x373, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_178) {
  // 6535252.930355749452463512636
  s21_decimal dec_1 = {{0x24e89c3c, 0x3ddfedb4, 0x151dd5a3, 0x150000}};
  // -67238877629389
  s21_decimal dec_2 = {{0x456a8bcd, 0x3d27, 0x0, 0x80000000}};
  // -439423072061296110260.68626526
  s21_decimal dec_check = {{0xb2235c5e, 0xd8767e06, 0x8dfc397e, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_179) {
  // 0.2
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x10000}};
  // -1990928259
  s21_decimal dec_2 = {{0x76ab2783, 0x0, 0x0, 0x80000000}};
  // -398185651.8
  s21_decimal dec_check = {{0xed564f06, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_180) {
  // -9902293156
  s21_decimal dec_1 = {{0x4e3900a4, 0x2, 0x0, 0x80000000}};
  // -4922756
  s21_decimal dec_2 = {{0x4b1d84, 0x0, 0x0, 0x80000000}};
  // 48746573047457936
  s21_decimal dec_check = {{0xfa82e890, 0xad2ebf, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_181) {
  // 2532.67121381023
  s21_decimal dec_1 = {{0x58cd9e9f, 0xe658, 0x0, 0xb0000}};
  // 434485.99743963
  s21_decimal dec_2 = {{0x2a5a8ddb, 0x2784, 0x0, 0x80000}};
  // 1100410178.5189761960767014149
  s21_decimal dec_check = {{0x122a4505, 0x1674adc9, 0x238e6131, 0x130000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_182) {
  // 405632847.817
  s21_decimal dec_1 = {{0x719a0fc9, 0x5e, 0x0, 0x30000}};
  // -6563715.14130659604
  s21_decimal dec_2 = {{0x1c717914, 0x91be66a, 0x0, 0x800b0000}};
  // -2662458465027757.1220316148447
  s21_decimal dec_check = {{0xc3b8d2df, 0xf7befa80, 0x56075719, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_183) {
  // -669116225640472016159.03008
  s21_decimal dec_1 = {{0x73367920, 0x53d206d8, 0x375916, 0x80050000}};
  // 1018.950959
  s21_decimal dec_2 = {{0x3cbbf52f, 0x0, 0x0, 0x60000}};
  // -681796619798819350077907.19653
  s21_decimal dec_check = {{0xafe4e2a5, 0xe550fe7d, 0xdc4ce501, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_184) {
  // 508659696539344731
  s21_decimal dec_1 = {{0x8bc91f5b, 0x70f1f4c, 0x0, 0x0}};
  // -35853.527171717951871561026996
  s21_decimal dec_2 = {{0xa664cdb4, 0x8acfcddf, 0x73d957b2, 0x80180000}};
  // -18237244251031204164562.272597
  s21_decimal dec_check = {{0x64cb4155, 0xdb185b09, 0x3aed7eaf, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_185) {
  // 31963035308.0
  s21_decimal dec_1 = {{0x6b7422b8, 0x4a, 0x0, 0x10000}};
  // -657178655
  s21_decimal dec_2 = {{0x272bc01f, 0x0, 0x0, 0x80000000}};
  // -21005424553428950740.0
  s21_decimal dec_check = {{0xfa023448, 0x63169765, 0xb, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_186) {
  // 445.69300423171484
  s21_decimal dec_1 = {{0xe79c5d9c, 0x9e578a, 0x0, 0xe0000}};
  // 20
  s21_decimal dec_2 = {{0x14, 0x0, 0x0, 0x0}};
  // 8913.86008463429680
  s21_decimal dec_check = {{0x18375030, 0xc5ed6da, 0x0, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_187) {
  // -8570.07343173945456211
  s21_decimal dec_1 = {{0x484ef653, 0x755db5ff, 0x2e, 0x80110000}};
  // -0.8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x80010000}};
  // 6856.058745391563649688
  s21_decimal dec_check = {{0x4277b298, 0xaaedaffa, 0x173, 0x120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_188) {
  // -698387096.90
  s21_decimal dec_1 = {{0x42b623ba, 0x10, 0x0, 0x80020000}};
  // 89973382.0986261
  s21_decimal dec_2 = {{0x9acad395, 0x3324d, 0x0, 0x70000}};
  // -62836249122133911.457569090
  s21_decimal dec_check = {{0x8391942, 0xe3f4b89b, 0x33fa17, 0x80090000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_189) {
  // 23
  s21_decimal dec_1 = {{0x17, 0x0, 0x0, 0x0}};
  // 0.06531
  s21_decimal dec_2 = {{0x1983, 0x0, 0x0, 0x50000}};
  // 1.50213
  s21_decimal dec_check = {{0x24ac5, 0x0, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_190) {
  // -497891974914
  s21_decimal dec_1 = {{0xecac9f02, 0x73, 0x0, 0x80000000}};
  // -6679436.412
  s21_decimal dec_2 = {{0x8e201c7c, 0x1, 0x0, 0x80030000}};
  // 3325637786483162168.568
  s21_decimal dec_check = {{0x81413cf8, 0x487edad2, 0xb4, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_191) {
  // -7540306777.3648280401
  s21_decimal dec_1 = {{0x37029b51, 0x166d82a3, 0x4, 0x800a0000}};
  // 3188229899200
  s21_decimal dec_2 = {{0x514f83c0, 0x2e6, 0x0, 0x0}};
  // -24040231516734942543913.356558
  s21_decimal dec_check = {{0xbc370d0e, 0xdffb24d9, 0x4dad9d09, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_192) {
  // -52069228229
  s21_decimal dec_1 = {{0x1f915ec5, 0xc, 0x0, 0x80000000}};
  // -7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x80000000}};
  // 364484597603
  s21_decimal dec_check = {{0xdcf99763, 0x54, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_193) {
  // 8844006.8005804769965
  s21_decimal dec_1 = {{0x956202ad, 0xcb5a3d46, 0x4, 0xd0000}};
  // 0.6521755
  s21_decimal dec_2 = {{0x63839b, 0x0, 0x0, 0x70000}};
  // 5767844.55717197287543088575
  s21_decimal dec_check = {{0xa29d25bf, 0xff49fd14, 0x1dd1adb, 0x140000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_194) {
  // 14573542233102.0936326
  s21_decimal dec_1 = {{0x80088486, 0xe67c3a78, 0x7, 0x70000}};
  // 15084352200282
  s21_decimal dec_2 = {{0x19745e5a, 0xdb8, 0x0, 0x0}};
  // 219832443849796217821250592.12
  s21_decimal dec_check = {{0x974c9c8c, 0x6136859, 0x47081d12, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_195) {
  // 0.3037284828
  s21_decimal dec_1 = {{0xb50949dc, 0x0, 0x0, 0xa0000}};
  // -33986025682931626245686000
  s21_decimal dec_2 = {{0xaa4502f0, 0x24dbd0fa, 0x1c1cd2, 0x80000000}};
  // -10322524017078656695738868.825
  s21_decimal dec_check = {{0x77dca459, 0x3e160a10, 0x215a977c, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_196) {
  // 2715581581.6974142280
  s21_decimal dec_1 = {{0x9cad8b48, 0x78dcd69b, 0x1, 0xa0000}};
  // 53.2581279
  s21_decimal dec_2 = {{0x1fbe8b9f, 0x0, 0x0, 0x70000}};
  // 144626791200.92518605410376120
  s21_decimal dec_check = {{0xa1d999b8, 0x19271563, 0x2ebb3f6e, 0x110000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_197) {
  // 5.7205596333813476
  s21_decimal dec_1 = {{0xd0a42ee4, 0xcb3c2f, 0x0, 0x100000}};
  // 5799
  s21_decimal dec_2 = {{0x16a7, 0x0, 0x0, 0x0}};
  // 33173.5253139784347324
  s21_decimal dec_check = {{0x37222ebc, 0xfbc05f1f, 0x11, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_198) {
  // 23
  s21_decimal dec_1 = {{0x17, 0x0, 0x0, 0x0}};
  // -9404.06973
  s21_decimal dec_2 = {{0x380d78bd, 0x0, 0x0, 0x80050000}};
  // -216293.60379
  s21_decimal dec_check = {{0x935d8fb, 0x5, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_199) {
  // -8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -2413203099244132994413254686
  s21_decimal dec_2 = {{0xb80581e, 0x247864e2, 0x7cc27a2, 0x80000000}};
  // 19305624793953063955306037488
  s21_decimal dec_check = {{0x5c02c0f0, 0x23c32710, 0x3e613d11, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_200) {
  // -84264
  s21_decimal dec_1 = {{0x14928, 0x0, 0x0, 0x80000000}};
  // -837862174149334
  s21_decimal dec_2 = {{0xfd42cad6, 0x2fa07, 0x0, 0x80000000}};
  // 70601618242519480176
  s21_decimal dec_check = {{0x691cb770, 0xd3cb55ba, 0x3, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_201) {
  // -66.56
  s21_decimal dec_1 = {{0x1a00, 0x0, 0x0, 0x80020000}};
  // -899074029.7616
  s21_decimal dec_2 = {{0x51e1b790, 0x82d, 0x0, 0x80040000}};
  // 59842367420.932096
  s21_decimal dec_check = {{0xeca4a000, 0xd49a50, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_202) {
  // -5880037875617285
  s21_decimal dec_1 = {{0xd78e05, 0x14e3dd, 0x0, 0x80000000}};
  // 8.97992
  s21_decimal dec_2 = {{0xdb3c8, 0x0, 0x0, 0x50000}};
  // -52802269720013169.91720
  s21_decimal dec_check = {{0x96f572e8, 0x3dde9731, 0x11e, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_203) {
  // 61.20451138821
  s21_decimal dec_1 = {{0x750e505, 0x591, 0x0, 0xb0000}};
  // 52025074.17
  s21_decimal dec_2 = {{0x3617f699, 0x1, 0x0, 0x20000}};
  // 3184169244.5102349135357
  s21_decimal dec_check = {{0xbcdeadfd, 0x24404e4d, 0x6be, 0xd0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_204) {
  // -80626604
  s21_decimal dec_1 = {{0x4ce43ac, 0x0, 0x0, 0x80000000}};
  // -995.0
  s21_decimal dec_2 = {{0x26de, 0x0, 0x0, 0x80010000}};
  // 80223470980.0
  s21_decimal dec_check = {{0xc8ea3728, 0xba, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_205) {
  // 14620.7
  s21_decimal dec_1 = {{0x23b1f, 0x0, 0x0, 0x10000}};
  // 977785449518.7
  s21_decimal dec_2 = {{0x958b39d3, 0x8e4, 0x0, 0x10000}};
  // 14295907721778057.09
  s21_decimal dec_check = {{0xa5d5a18d, 0x13d6ed3b, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_206) {
  // 88
  s21_decimal dec_1 = {{0x58, 0x0, 0x0, 0x0}};
  // 5323125261013423496
  s21_decimal dec_2 = {{0xc59d1588, 0x49df8a38, 0x0, 0x0}};
  // 468435022969181267648
  s21_decimal dec_check = {{0xedff66c0, 0x64d78383, 0x19, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_207) {
  // -0.64793382976889270994048
  s21_decimal dec_1 = {{0xcef28480, 0x74d1ff6c, 0xdb8, 0x80170000}};
  // 7153.61231931
  s21_decimal dec_2 = {{0x8eda243b, 0xa6, 0x0, 0x80000}};
  // -4635.0674267324593000478682249
  s21_decimal dec_check = {{0xbea82c89, 0xd70e77c4, 0x95c4610e, 0x80190000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_208) {
  // -848857846.239
  s21_decimal dec_1 = {{0xa3ded1df, 0xc5, 0x0, 0x80030000}};
  // -2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // 1697715692.478
  s21_decimal dec_check = {{0x47bda3be, 0x18b, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_210) {
  // 4.9
  s21_decimal dec_1 = {{0x31, 0x0, 0x0, 0x10000}};
  // -6430032419904060637981
  s21_decimal dec_2 = {{0x82e7c31d, 0x92a02221, 0x15c, 0x80000000}};
  // -31507158857529897126106.9
  s21_decimal dec_check = {{0xe5c588d, 0x10a6886a, 0x42b8, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_211) {
  // 332744397.26
  s21_decimal dec_1 = {{0xbf4fa82e, 0x7, 0x0, 0x20000}};
  // -76.970590
  s21_decimal dec_2 = {{0x4967a5e, 0x0, 0x0, 0x80060000}};
  // -25611532576.29658340
  s21_decimal dec_check = {{0x7859ace4, 0x238b0b51, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_212) {
  // 26.439014213442
  s21_decimal dec_1 = {{0xd00ce742, 0x180b, 0x0, 0xc0000}};
  // -94320386777830581139116.92
  s21_decimal dec_2 = {{0xdd805b8c, 0xd75d8906, 0x7cd4f, 0x80020000}};
  // -2493738046636409618998963.0950
  s21_decimal dec_check = {{0x76efb3e6, 0xe2f023c3, 0x5093b7b7, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_213) {
  // -6371350.387678593497390248525
  s21_decimal dec_1 = {{0xf4c1f24d, 0x99709d1a, 0x149641ec, 0x80150000}};
  // 547140
  s21_decimal dec_2 = {{0x85944, 0x0, 0x0, 0x0}};
  // -3486020651114.4656461621005780
  s21_decimal dec_check = {{0x2be8dd4, 0xa241e87d, 0x70a3afdd, 0x80100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_214) {
  // 30
  s21_decimal dec_1 = {{0x1e, 0x0, 0x0, 0x0}};
  // -260251807228.3
  s21_decimal dec_2 = {{0xf22a4bdb, 0x25d, 0x0, 0x80010000}};
  // -7807554216849.0
  s21_decimal dec_check = {{0x60f4e3aa, 0x4702, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_215) {
  // -843922123244
  s21_decimal dec_1 = {{0x7dada9ec, 0xc4, 0x0, 0x80000000}};
  // 289
  s21_decimal dec_2 = {{0x121, 0x0, 0x0, 0x0}};
  // -243893493617516
  s21_decimal dec_check = {{0xe10cd36c, 0xddd1, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_216) {
  // -747.43480904671133
  s21_decimal dec_1 = {{0xc4995f9d, 0x1098acc, 0x0, 0x800e0000}};
  // -45077380114484157775220478
  s21_decimal dec_2 = {{0xe02a0efe, 0xac2937b1, 0x254981, 0x80000000}};
  // 33692402998195488978310890180
  s21_decimal dec_check = {{0xe8d182c4, 0x58541f77, 0x6cddb3da, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_217) {
  // -9.960
  s21_decimal dec_1 = {{0x26e8, 0x0, 0x0, 0x80030000}};
  // -787
  s21_decimal dec_2 = {{0x313, 0x0, 0x0, 0x80000000}};
  // 7838.520
  s21_decimal dec_check = {{0x779b38, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_218) {
  // 85551830.765
  s21_decimal dec_1 = {{0xeb4956ed, 0x13, 0x0, 0x30000}};
  // 797.383
  s21_decimal dec_2 = {{0xc2ac7, 0x0, 0x0, 0x30000}};
  // 68217575470.887995
  s21_decimal dec_check = {{0x161743b, 0xf25b86, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_219) {
  // 964
  s21_decimal dec_1 = {{0x3c4, 0x0, 0x0, 0x0}};
  // -2657.0610650726598704
  s21_decimal dec_2 = {{0x15c50830, 0x70bdc59c, 0x1, 0x80100000}};
  // -2561406.8667300441150656
  s21_decimal dec_check = {{0xf9f2d4c0, 0x8a9c1fc1, 0x56c, 0x80100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_220) {
  // 8563
  s21_decimal dec_1 = {{0x2173, 0x0, 0x0, 0x0}};
  // -117
  s21_decimal dec_2 = {{0x75, 0x0, 0x0, 0x80000000}};
  // -1001871
  s21_decimal dec_check = {{0xf498f, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_221) {
  // 0.197955
  s21_decimal dec_1 = {{0x30543, 0x0, 0x0, 0x60000}};
  // 880907116357275093735
  s21_decimal dec_2 = {{0xbd140ae7, 0xc10ac314, 0x2f, 0x0}};
  // 174379968218504391180.311925
  s21_decimal dec_check = {{0x12a5d75, 0x4dead5b, 0x903e65, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_222) {
  // 61190204920499430
  s21_decimal dec_1 = {{0xcc050ce6, 0xd9642a, 0x0, 0x0}};
  // 172936.4504139970702902021
  s21_decimal dec_2 = {{0x77a28305, 0x9a17d78, 0x16e35, 0x130000}};
  // 10582016839056269218767.372924
  s21_decimal dec_check = {{0x527027c, 0x4f247253, 0x22313d3a, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_223) {
  // 191868.2830068266675410151
  s21_decimal dec_1 = {{0xb1ab14e7, 0x12fa9c6, 0x1964c, 0x130000}};
  // 1561085963639234
  s21_decimal dec_2 = {{0xa65399c2, 0x58bcc, 0x0, 0x0}};
  // 299522883469517273891.93223738
  s21_decimal dec_check = {{0x4d073e3a, 0xd5783f04, 0x60c7f3c4, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_224) {
  // -284523
  s21_decimal dec_1 = {{0x4576b, 0x0, 0x0, 0x80000000}};
  // -8754
  s21_decimal dec_2 = {{0x2232, 0x0, 0x0, 0x80000000}};
  // 2490714342
  s21_decimal dec_check = {{0x947548e6, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_225) {
  // 12019.393488834585
  s21_decimal dec_1 = {{0x1f515019, 0x2ab393, 0x0, 0xc0000}};
  // 8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x0}};
  // 96155.147910676680
  s21_decimal dec_check = {{0xfa8a80c8, 0x1559c98, 0x0, 0xc0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_226) {
  // -79.2463081852139759233368660
  s21_decimal dec_1 = {{0x521b8254, 0xbf787f78, 0x28f8295, 0x80190000}};
  // 69044042829199075421865328
  s21_decimal dec_2 = {{0x91824570, 0xfc6fbb2, 0x391ca5, 0x0}};
  // -5471485496395823010413486664.3
  s21_decimal dec_check = {{0x3af756d3, 0xf527e4b3, 0xb0cb1136, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_227) {
  // 10952
  s21_decimal dec_1 = {{0x2ac8, 0x0, 0x0, 0x0}};
  // 284131361229764345741
  s21_decimal dec_2 = {{0x604cbf8d, 0x671d5fa5, 0xf, 0x0}};
  // 3111806668188379114555432
  s21_decimal dec_check = {{0xd362c828, 0x60a3daff, 0x292f3, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_228) {
  // 420.62289672
  s21_decimal dec_1 = {{0xcb1b9b08, 0x9, 0x0, 0x80000}};
  // -1579
  s21_decimal dec_2 = {{0x62b, 0x0, 0x0, 0x80000000}};
  // -664163.55392088
  s21_decimal dec_check = {{0xc3453a58, 0x3c67, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_229) {
  // 0.668542174
  s21_decimal dec_1 = {{0x27d924de, 0x0, 0x0, 0x90000}};
  // 9339.487
  s21_decimal dec_2 = {{0x8e825f, 0x0, 0x0, 0x30000}};
  // 6243.840943024738
  s21_decimal dec_check = {{0x81716a62, 0x162ebd, 0x0, 0xc0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_230) {
  // 419032932222073930
  s21_decimal dec_1 = {{0x52497c4a, 0x5d0b43b, 0x0, 0x0}};
  // 0.19
  s21_decimal dec_2 = {{0x13, 0x0, 0x0, 0x20000}};
  // 79616257122194046.70
  s21_decimal dec_check = {{0x1b74397e, 0x6e7d6067, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_231) {
  // -894872335.2
  s21_decimal dec_1 = {{0x1562ae98, 0x2, 0x0, 0x80010000}};
  // -60428546
  s21_decimal dec_2 = {{0x39a1102, 0x0, 0x0, 0x80000000}};
  // 54075834071760619.2
  s21_decimal dec_check = {{0x87cd7530, 0x78128d8, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_232) {
  // -8.46704718810302
  s21_decimal dec_1 = {{0xcdfe8cbe, 0x30212, 0x0, 0x800e0000}};
  // 583300
  s21_decimal dec_2 = {{0x8e684, 0x0, 0x0, 0x0}};
  // -4938828.62482049156600
  s21_decimal dec_check = {{0x4fa345f8, 0xc60066b9, 0x1a, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_233) {
  // 7855427197345.263631525905213
  s21_decimal dec_1 = {{0xc2ca833d, 0xa87e000a, 0x1961db69, 0xf0000}};
  // 6190864847462
  s21_decimal dec_2 = {{0x6c4cd266, 0x5a1, 0x0, 0x0}};
  // 48631888097841731703534799.351
  s21_decimal dec_check = {{0x504449f7, 0x63399818, 0x9d235ae0, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_234) {
  // -603334065240122542713405.8
  s21_decimal dec_1 = {{0x60d266a, 0xd58a623, 0x4fd9c, 0x80010000}};
  // -71
  s21_decimal dec_2 = {{0x47, 0x0, 0x0, 0x80000000}};
  // 42836718632048700532651811.8
  s21_decimal dec_check = {{0xada5a766, 0xb39613b6, 0x1625647, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_235) {
  // -373443328
  s21_decimal dec_1 = {{0x16424b00, 0x0, 0x0, 0x80000000}};
  // 516626
  s21_decimal dec_2 = {{0x7e212, 0x0, 0x0, 0x0}};
  // -192930532771328
  s21_decimal dec_check = {{0x23df4600, 0xaf78, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_236) {
  // -91891476.090
  s21_decimal dec_1 = {{0x6528a67a, 0x15, 0x0, 0x80030000}};
  // -76189.803592410
  s21_decimal dec_2 = {{0x522dbada, 0x454b, 0x0, 0x80090000}};
  // 7001193515113.739620476900
  s21_decimal dec_check = {{0x50467e4, 0x760112ee, 0x5ca8f, 0xc0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_237) {
  // 28514912242593932
  s21_decimal dec_1 = {{0x5f05708c, 0x654e29, 0x0, 0x0}};
  // 27361716720.03200
  s21_decimal dec_2 = {{0x9c8de280, 0x9b888, 0x0, 0x50000}};
  // 780216951078427562566706045.82
  s21_decimal dec_check = {{0xef42dd26, 0xd8a315ac, 0xfc1a0896, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_238) {
  // 1572554965.3155
  s21_decimal dec_1 = {{0x63cd0ca3, 0xe4d, 0x0, 0x40000}};
  // -23.406350735138
  s21_decimal dec_2 = {{0xb7389722, 0x1549, 0x0, 0x800c0000}};
  // -36807773068.4573655171060390
  s21_decimal dec_check = {{0x7c57d2a6, 0xc338ee83, 0x130777d, 0x80100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_239) {
  // -50.9727159120729809671028
  s21_decimal dec_1 = {{0xf1d0d374, 0x5d5aaa11, 0x6bf0, 0x80160000}};
  // -666232847387
  s21_decimal dec_2 = {{0x1e927c1b, 0x9b, 0x0, 0x80000000}};
  // 33959697661149.024839461955420
  s21_decimal dec_check = {{0xa8aae75c, 0xef584ef, 0x6dbacdb3, 0xf0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_240) {
  // 2133130258.00
  s21_decimal dec_1 = {{0xaa727708, 0x31, 0x0, 0x20000}};
  // 92660
  s21_decimal dec_2 = {{0x169f4, 0x0, 0x0, 0x0}};
  // 197655849706280.00
  s21_decimal dec_check = {{0xdef3bba0, 0x4638b1, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_241) {
  // 4504899597537203.2
  s21_decimal dec_1 = {{0xba999d00, 0xa00bd2, 0x0, 0x10000}};
  // 22
  s21_decimal dec_2 = {{0x16, 0x0, 0x0, 0x0}};
  // 99107791145818470.4
  s21_decimal dec_check = {{0x9337e00, 0xdc1041c, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_242) {
  // 0.4427410467549
  s21_decimal dec_1 = {{0xd63a6add, 0x406, 0x0, 0xd0000}};
  // -48852179401560148394930595756
  s21_decimal dec_2 = {{0x86dbe7ac, 0xe422cf0a, 0x9dd9935f, 0x80000000}};
  // -21628865044504904362524549086
  s21_decimal dec_check = {{0xb1a21fde, 0x7b7e943b, 0x45e2fa53, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_243) {
  // -8800
  s21_decimal dec_1 = {{0x2260, 0x0, 0x0, 0x80000000}};
  // -68958
  s21_decimal dec_2 = {{0x10d5e, 0x0, 0x0, 0x80000000}};
  // 606830400
  s21_decimal dec_check = {{0x242b7f40, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_244) {
  // -32.74052333972
  s21_decimal dec_1 = {{0x4cb9f194, 0x2fa, 0x0, 0x800b0000}};
  // -18549106333110756630.759817
  s21_decimal dec_2 = {{0xee5e8989, 0x11b72ae6, 0xf57ed, 0x80060000}};
  // 607307448830160792501.18053857
  s21_decimal dec_check = {{0x768fe1, 0xf102c09b, 0xc43b4b74, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_245) {
  // 0.5761084759647676210216191723
  s21_decimal dec_1 = {{0x5e6446eb, 0x9d39653b, 0x129d7526, 0x1c0000}};
  // -2.90070959068
  s21_decimal dec_2 = {{0x899393dc, 0x43, 0x0, 0x800b0000}};
  // -1.6711233815030397040749383127
  s21_decimal dec_check = {{0xbe130dd7, 0x5bc3f8c4, 0x35ff3568, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_246) {
  // -99525411804
  s21_decimal dec_1 = {{0x2c2d43dc, 0x17, 0x0, 0x80000000}};
  // 577033083746104717
  s21_decimal dec_2 = {{0x4c55b58d, 0x8020888, 0x0, 0x0}};
  // -57429455284363090940331879468
  s21_decimal dec_check = {{0x2df4ec2c, 0x32c2770c, 0xb9908831, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_247) {
  // 960942139259
  s21_decimal dec_1 = {{0xbc9d677b, 0xdf, 0x0, 0x0}};
  // 811845487243922
  s21_decimal dec_2 = {{0x81e13292, 0x2e25e, 0x0, 0x0}};
  // 780136539259939602625333798
  s21_decimal dec_check = {{0x3e160a26, 0x88f8df17, 0x2855056, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_249) {
  // -76.25566913420492
  s21_decimal dec_1 = {{0xa715dccc, 0x1b1769, 0x0, 0x800e0000}};
  // 8084.347630
  s21_decimal dec_2 = {{0xe1dd5aee, 0x1, 0x0, 0x60000}};
  // -616477.33803917369693633960
  s21_decimal dec_check = {{0xee0efda8, 0x58903ab1, 0x32fe6a, 0x80140000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_250) {
  // -6.652384608523783890
  s21_decimal dec_1 = {{0x3c560ed2, 0x5c52048e, 0x0, 0x80120000}};
  // -51
  s21_decimal dec_2 = {{0x33, 0x0, 0x0, 0x80000000}};
  // 339.271615034712978390
  s21_decimal dec_check = {{0x524f3d6, 0x6456e856, 0x12, 0x120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_251) {
  // 9127.2851273606596174
  s21_decimal dec_1 = {{0x2861864e, 0xf2aa4ea6, 0x4, 0x100000}};
  // -66054.426997616052
  s21_decimal dec_2 = {{0xc108edb4, 0xeaac26, 0x0, 0x800c0000}};
  // -602897589.13167142024459504003
  s21_decimal dec_check = {{0x6d56c983, 0x9d3953eb, 0xc2ce850b, 0x80140000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_252) {
  // -809576663.7
  s21_decimal dec_1 = {{0xe28b986d, 0x1, 0x0, 0x80010000}};
  // -7893281153754670942.5350557880
  s21_decimal dec_2 = {{0x9f04c0b8, 0x784831b2, 0xff0bb0ff, 0x800a0000}};
  // 6390216222102793229948864885.1
  s21_decimal dec_check = {{0x55bde93, 0x53f688d8, 0xce7aa133, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_253) {
  // 75917390937688291228205
  s21_decimal dec_1 = {{0x69fd3a2d, 0x7d713e40, 0x1013, 0x0}};
  // -795.38257073321
  s21_decimal dec_2 = {{0xf18f14a9, 0x4856, 0x0, 0x800b0000}};
  // -60383369567376613145420581.398
  s21_decimal dec_check = {{0xf0a54a16, 0x58e4c790, 0xc31bf3df, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_254) {
  // -43214.707701
  s21_decimal dec_1 = {{0xfcc1bf5, 0xa, 0x0, 0x80060000}};
  // 179684.91
  s21_decimal dec_2 = {{0x1122d6b, 0x0, 0x0, 0x20000}};
  // -7765030863.93049191
  s21_decimal dec_check = {{0x6773c067, 0xac6b171, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_255) {
  // 2.2
  s21_decimal dec_1 = {{0x16, 0x0, 0x0, 0x10000}};
  // -6371188756.46178725159
  s21_decimal dec_2 = {{0xbac18d27, 0x89ccf1cc, 0x22, 0x800b0000}};
  // -14016615264.215931953498
  s21_decimal dec_check = {{0xca2215a, 0xd79cc798, 0x2f7, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_256) {
  // 17063307371339.1083000962
  s21_decimal dec_1 = {{0x7351482, 0x997098f, 0x2422, 0xa0000}};
  // 35973.815216992
  s21_decimal dec_2 = {{0xce7a2b60, 0x20b7, 0x0, 0x90000}};
  // 613832266367290577.37424096926
  s21_decimal dec_check = {{0xd099ce9e, 0xaf82972f, 0xc65703d7, 0xb0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_257) {
  // 19681411161
  s21_decimal dec_1 = {{0x951a8059, 0x4, 0x0, 0x0}};
  // 27555
  s21_decimal dec_2 = {{0x6ba3, 0x0, 0x0, 0x0}};
  // 542321284541355
  s21_decimal dec_check = {{0x384ebab, 0x1ed3d, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_258) {
  // 93756
  s21_decimal dec_1 = {{0x16e3c, 0x0, 0x0, 0x0}};
  // 0.2421417474519750865176918
  s21_decimal dec_2 = {{0xe3dc956, 0x4de7d019, 0x200c1, 0x190000}};
  // 22702.241674107376211552712401
  s21_decimal dec_check = {{0x2ad536d1, 0x2afc0f39, 0x495adaab, 0x180000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_259) {
  // 7139825.9663
  s21_decimal dec_1 = {{0x9faafbcf, 0x10, 0x0, 0x40000}};
  // 49316460396454182.46
  s21_decimal dec_2 = {{0xaf06f306, 0x4470b9f1, 0x0, 0x20000}};
  // 352110944504609164376146.01110
  s21_decimal dec_check = {{0x3eb02396, 0xf068e7b2, 0x71c5ef46, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_261) {
  // -71513933408295194.79846074
  s21_decimal dec_1 = {{0x157434ba, 0xcf5072a6, 0x5ea5d, 0x80080000}};
  // 30763.9214165
  s21_decimal dec_2 = {{0xa0b9e055, 0x47, 0x0, 0x70000}};
  // -2200049027557607382014.4057605
  s21_decimal dec_check = {{0x34c2bd05, 0xa054850b, 0x47166107, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_262) {
  // 525536.31388966815
  s21_decimal dec_1 = {{0xd2989f9f, 0xbab53f, 0x0, 0xb0000}};
  // 3474005
  s21_decimal dec_2 = {{0x350255, 0x0, 0x0, 0x0}};
  // 1825715782134.27660144075
  s21_decimal dec_check = {{0x29d73dcb, 0x399f476f, 0x26a9, 0xb0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_263) {
  // 423346264891366
  s21_decimal dec_1 = {{0xfbbc5fe6, 0x18107, 0x0, 0x0}};
  // -959135474903
  s21_decimal dec_2 = {{0x50ede4d7, 0xdf, 0x0, 0x80000000}};
  // -406046420824991564114387498
  s21_decimal dec_check = {{0xd88b622a, 0x9454ee9e, 0x14fdfac, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_264) {
  // 0.910
  s21_decimal dec_1 = {{0x38e, 0x0, 0x0, 0x30000}};
  // -761214848394063572441058.1614
  s21_decimal dec_2 = {{0xeab4f26e, 0x2db4644d, 0x18989f24, 0x80040000}};
  // -692705512038597850921362.92687
  s21_decimal dec_check = {{0xa4a1d14f, 0x39832a5e, 0xdfd341c9, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_265) {
  // 1630422.4620100534572280412347
  s21_decimal dec_1 = {{0xe9b78bb, 0xb0b311e3, 0x34ae89db, 0x160000}};
  // 62149245287165.103465207402
  s21_decimal dec_2 = {{0xa3c2966a, 0x5682d6ca, 0x33689d, 0xc0000}};
  // 101329525513166439771.47774136
  s21_decimal dec_check = {{0x4164f4b8, 0x7dd3136e, 0x20bdc82a, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_266) {
  // -25846894.4306976291
  s21_decimal dec_1 = {{0xaae33623, 0x3964422, 0x0, 0x800a0000}};
  // -6713583981
  s21_decimal dec_2 = {{0x9029296d, 0x1, 0x0, 0x80000000}};
  // 173525296408529717.3804394471
  s21_decimal dec_check = {{0x8204a7e7, 0xac74f31b, 0x59b5e1b, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_267) {
  // -4860543712949193578777477
  s21_decimal dec_1 = {{0x14c60b85, 0x9a476702, 0x40542, 0x80000000}};
  // 16298.0485261359403
  s21_decimal dec_2 = {{0x4952f92b, 0x24305e3, 0x0, 0xd0000}};
  // -79217377297050915289984351162
  s21_decimal dec_check = {{0xdacb3bba, 0x340d0a3a, 0xfff71424, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_268) {
  // -3279875789.388587330641016
  s21_decimal dec_1 = {{0x87c31c78, 0x6c3dba38, 0x2b68a, 0x800f0000}};
  // 6.16963953693
  s21_decimal dec_2 = {{0xa5ead41d, 0x8f, 0x0, 0xb0000}};
  // -20235651346.431322146442902754
  s21_decimal dec_check = {{0x4384fce2, 0x92b05517, 0x416289d9, 0x80120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_269) {
  // 2227650909804
  s21_decimal dec_1 = {{0xaa57566c, 0x206, 0x0, 0x0}};
  // -3.91936340
  s21_decimal dec_2 = {{0x175c7954, 0x0, 0x0, 0x80080000}};
  // -8730973443862.49877360
  s21_decimal dec_check = {{0xef516770, 0x54a8e0d9, 0x2f, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_270) {
  // 949
  s21_decimal dec_1 = {{0x3b5, 0x0, 0x0, 0x0}};
  // -51658973256765538672369538
  s21_decimal dec_2 = {{0x2474df82, 0x8d3a19a6, 0x2abb36, 0x80000000}};
  // -49024365620670496200078691562
  s21_decimal dec_check = {{0x25408cea, 0x886114e5, 0x9e680139, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_271) {
  // 338845186307074179823153.1021
  s21_decimal dec_1 = {{0xa458de0d, 0x90b07761, 0xaf2dc97, 0x40000}};
  // 0.598616393139
  s21_decimal dec_2 = {{0x605145b3, 0x8b, 0x0, 0xc0000}};
  // 202838283259653216805852.59886
  s21_decimal dec_check = {{0xe3b87b6e, 0xdde21076, 0x418a63b8, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_272) {
  // -733610756769
  s21_decimal dec_1 = {{0xce9bcaa1, 0xaa, 0x0, 0x80000000}};
  // -194727524505.6928621825
  s21_decimal dec_2 = {{0xd9f5a501, 0x8fdf6645, 0x69, 0x800a0000}};
  // 142854206616375333274385.44599
  s21_decimal dec_check = {{0x5b267ed7, 0xcf92f790, 0x2e289f7d, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_273) {
  // 615509403397441533
  s21_decimal dec_1 = {{0x916ac7fd, 0x88aba8a, 0x0, 0x0}};
  // 36.651
  s21_decimal dec_2 = {{0x8f2b, 0x0, 0x0, 0x30000}};
  // 22559035143919629625.983
  s21_decimal dec_check = {{0x12a5ea7f, 0xed80bc81, 0x4c6, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_274) {
  // 450455452348273262445
  s21_decimal dec_1 = {{0xa4b9ff6d, 0x6b533f4b, 0x18, 0x0}};
  // 405.44469719909488088902520
  s21_decimal dec_2 = {{0x622ceb78, 0x1b8da299, 0x2189a0, 0x170000}};
  // 182634774479026965996305.93617
  s21_decimal dec_check = {{0x1fab3e51, 0x4ecc5f90, 0x3b0331c8, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_275) {
  // 7.9534044
  s21_decimal dec_1 = {{0x4bd97dc, 0x0, 0x0, 0x70000}};
  // 510408837
  s21_decimal dec_2 = {{0x1e6c3885, 0x0, 0x0, 0x0}};
  // 4059487889.9946828
  s21_decimal dec_check = {{0xc888054c, 0x9038d3, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_276) {
  // -1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -1
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 1
  s21_decimal dec_check = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_277) {
  // 51397457
  s21_decimal dec_1 = {{0x3104351, 0x0, 0x0, 0x0}};
  // -910
  s21_decimal dec_2 = {{0x38e, 0x0, 0x0, 0x80000000}};
  // -46771685870
  s21_decimal dec_check = {{0xe3cf49ee, 0xa, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_278) {
  // 9.3
  s21_decimal dec_1 = {{0x5d, 0x0, 0x0, 0x10000}};
  // -78259
  s21_decimal dec_2 = {{0x131b3, 0x0, 0x0, 0x80000000}};
  // -727808.7
  s21_decimal dec_check = {{0x6f0e07, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_279) {
  // -9416888.4720110859115550113
  s21_decimal dec_1 = {{0x10cbd5a1, 0x783e867c, 0x4de509, 0x80130000}};
  // 544947
  s21_decimal dec_2 = {{0x850b3, 0x0, 0x0, 0x0}};
  // -5131705122157.0252342441687429
  s21_decimal dec_check = {{0x5fc63985, 0xffb29761, 0xa5d07848, 0x80100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_280) {
  // 215768
  s21_decimal dec_1 = {{0x34ad8, 0x0, 0x0, 0x0}};
  // -9460250350829420098366
  s21_decimal dec_2 = {{0x5c1f333e, 0xd758d386, 0x200, 0x80000000}};
  // -2041219297697762315784235088
  s21_decimal dec_check = {{0x58dd2850, 0xdaaa645c, 0x69874ff, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_281) {
  // -7585732.181154969055624060
  s21_decimal dec_1 = {{0xd06b7b7c, 0x5d93b4d7, 0x64657, 0x80120000}};
  // -27640
  s21_decimal dec_2 = {{0x6bf8, 0x0, 0x0, 0x80000000}};
  // 209669637487.12334469744901840
  s21_decimal dec_check = {{0x48793ed0, 0x56c48a1e, 0x43bf7746, 0x110000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_282) {
  // -1649160.13094389668208
  s21_decimal dec_1 = {{0x98c3d970, 0xf0ab6025, 0x8, 0x800e0000}};
  // 737371487.0652
  s21_decimal dec_2 = {{0xd3a7d17c, 0x6b4, 0x0, 0x40000}};
  // -1216043658162741.0505772379166
  s21_decimal dec_check = {{0x735d2c1e, 0x235b4a1, 0x274ae09c, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_283) {
  // 409709905404.7070
  s21_decimal dec_1 = {{0x35b9df5e, 0xe8e4a, 0x0, 0x40000}};
  // 2061825801288
  s21_decimal dec_2 = {{0xe64fc48, 0x1e0, 0x0, 0x0}};
  // 844750454006690692201862.6160
  s21_decimal dec_check = {{0x78df5a70, 0xb89908d4, 0x1b4b9caa, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_284) {
  // 2.6801
  s21_decimal dec_1 = {{0x68b1, 0x0, 0x0, 0x40000}};
  // 53298208
  s21_decimal dec_2 = {{0x32d4420, 0x0, 0x0, 0x0}};
  // 142844527.2608
  s21_decimal dec_check = {{0x95f91a20, 0x14c, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_285) {
  // -888153857501644790771256700
  s21_decimal dec_1 = {{0x68bc8d7c, 0x1719863b, 0x2dea9e5, 0x80000000}};
  // -0.777480942703881927106268829
  s21_decimal dec_2 = {{0x2bf48e9d, 0x5b76ca33, 0x2831dfe, 0x801b0000}};
  // 690522698396468007263353777.05
  s21_decimal dec_check = {{0x308b5129, 0xc2907639, 0xdf1eb2e8, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_286) {
  // 35.0350
  s21_decimal dec_1 = {{0x5588e, 0x0, 0x0, 0x40000}};
  // 59788079.9562
  s21_decimal dec_2 = {{0x3479014a, 0x8b, 0x0, 0x40000}};
  // 2094675381.26546700
  s21_decimal dec_check = {{0xba02270c, 0x2e82d9d, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_287) {
  // 85299790664326845510758
  s21_decimal dec_1 = {{0x8f1f3466, 0x1c65178b, 0x1210, 0x0}};
  // 18
  s21_decimal dec_2 = {{0x12, 0x0, 0x0, 0x0}};
  // 1535396231957883219193644
  s21_decimal dec_check = {{0x1031af2c, 0xff1ba7d0, 0x14521, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_288) {
  // 73.2518
  s21_decimal dec_1 = {{0xb2d66, 0x0, 0x0, 0x40000}};
  // -419645742
  s21_decimal dec_2 = {{0x1903492e, 0x0, 0x0, 0x80000000}};
  // -30739805963.8356
  s21_decimal dec_check = {{0xb0263e54, 0x11793, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_289) {
  // -52043658
  s21_decimal dec_1 = {{0x31a1f8a, 0x0, 0x0, 0x80000000}};
  // 2.963
  s21_decimal dec_2 = {{0xb93, 0x0, 0x0, 0x30000}};
  // -154205358.654
  s21_decimal dec_check = {{0xe75b0a3e, 0x23, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_290) {
  // -42016.7286986307122835677307
  s21_decimal dec_1 = {{0xa026e07b, 0x4494bfbf, 0x15b8de2, 0x80160000}};
  // 9192024180145751030048
  s21_decimal dec_2 = {{0x44bb7920, 0x4cf60a69, 0x1f2, 0x0}};
  // -386218786168437421688250386.14
  s21_decimal dec_check = {{0x8d358716, 0x17b9556e, 0x7ccb44eb, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_291) {
  // -868230.6056291555375
  s21_decimal dec_1 = {{0x7c7b182f, 0x787dbf5b, 0x0, 0x800d0000}};
  // -13648
  s21_decimal dec_2 = {{0x3550, 0x0, 0x0, 0x80000000}};
  // 11849611305.6267147758000
  s21_decimal dec_check = {{0x627949b0, 0xafe9bd5c, 0x1917, 0xd0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_293) {
  // -304940109863211
  s21_decimal dec_1 = {{0x66ed192b, 0x11557, 0x0, 0x80000000}};
  // -86382645
  s21_decimal dec_2 = {{0x5261835, 0x0, 0x0, 0x80000000}};
  // 26341533256574754373095
  s21_decimal dec_check = {{0x1cd43de7, 0xfa35856e, 0x593, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_295) {
  // 356.203069381896345
  s21_decimal dec_1 = {{0xea696899, 0x4f17ccd, 0x0, 0xf0000}};
  // 891590346471
  s21_decimal dec_2 = {{0x96ed06e7, 0xcf, 0x0, 0x0}};
  // 317587218044238.61405355854850
  s21_decimal dec_check = {{0x58ebcc02, 0xc9346130, 0x669e32ee, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_296) {
  // 722.89885
  s21_decimal dec_1 = {{0x44f0e5d, 0x0, 0x0, 0x50000}};
  // 909553187966469
  s21_decimal dec_2 = {{0xdaac4e05, 0x33b3b, 0x0, 0x0}};
  // 657514953594794278.66065
  s21_decimal dec_check = {{0x4679dd1, 0x654cf718, 0xdec, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_297) {
  // -0.11
  s21_decimal dec_1 = {{0xb, 0x0, 0x0, 0x80020000}};
  // -3.09415512467327370817035458
  s21_decimal dec_2 = {{0x8dbddcc2, 0x8a77bdaa, 0xfff148, 0x801a0000}};
  // 0.3403570637140601078987390038
  s21_decimal dec_check = {{0x17287c56, 0xf3252654, 0xaff5e1d, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_298) {
  // -37464776207153921712531948.218
  s21_decimal dec_1 = {{0xed8bc2ba, 0xc623498b, 0x790e22f3, 0x80030000}};
  // 824
  s21_decimal dec_2 = {{0x338, 0x0, 0x0, 0x0}};
  // -30870975594694831491126325332
  s21_decimal dec_check = {{0xeebef054, 0x5364c1b8, 0x63bfdf5c, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_299) {
  // 2.347880155
  s21_decimal dec_1 = {{0x8bf1cedb, 0x0, 0x0, 0x90000}};
  // 74
  s21_decimal dec_2 = {{0x4a, 0x0, 0x0, 0x0}};
  // 173.743131470
  s21_decimal dec_check = {{0x73e5cb4e, 0x28, 0x0, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_300) {
  // 191452397477766479088
  s21_decimal dec_1 = {{0xd329bcf0, 0x60ef8d25, 0xa, 0x0}};
  // -87128205
  s21_decimal dec_2 = {{0x531788d, 0x0, 0x0, 0x80000000}};
  // -16680903735184320732107477040
  s21_decimal dec_check = {{0xb87d9030, 0x6f77b47e, 0x35e61ec3, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_301) {
  // 947.6124929641233
  s21_decimal dec_1 = {{0x44474b11, 0x21aa7c, 0x0, 0xd0000}};
  // -27
  s21_decimal dec_2 = {{0x1b, 0x0, 0x0, 0x80000000}};
  // -25585.5373100313291
  s21_decimal dec_check = {{0x3384eacb, 0x38cfb1b, 0x0, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_302) {
  // -15272047417971532.7092
  s21_decimal dec_1 = {{0x6325e474, 0x476c1e1e, 0x8, 0x80040000}};
  // 330.00556367419394279428040598
  s21_decimal dec_2 = {{0x69ffa796, 0x56ddda06, 0x6aa16ba1, 0x1a0000}};
  // -5039860616626713832.9358985839
  s21_decimal dec_check = {{0x52ed6a6f, 0xc910891e, 0xa2d8bffa, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_303) {
  // -39623
  s21_decimal dec_1 = {{0x9ac7, 0x0, 0x0, 0x80000000}};
  // 201643377144139413898.6
  s21_decimal dec_2 = {{0x1981bf6a, 0x4fa3d79a, 0x6d, 0x10000}};
  // -7989715532582235996904227.8
  s21_decimal dec_check = {{0xe1018f66, 0x780f4c21, 0x4216e1, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_304) {
  // -50178937537068582202
  s21_decimal dec_1 = {{0x9f7cc53a, 0xb85f65d4, 0x2, 0x80000000}};
  // 100349
  s21_decimal dec_2 = {{0x187fd, 0x0, 0x0, 0x0}};
  // -5035406202907295155388498
  s21_decimal dec_check = {{0x2f8a8052, 0xeacf62b9, 0x42a49, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_305) {
  // -6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x80000000}};
  // 4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x0}};
  // -24
  s21_decimal dec_check = {{0x18, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_306) {
  // 9174687528116155127478
  s21_decimal dec_1 = {{0x6a1d16b6, 0x5c5de13e, 0x1f1, 0x0}};
  // 25299
  s21_decimal dec_2 = {{0x62d3, 0x0, 0x0, 0x0}};
  // 232110419773810608570065922
  s21_decimal dec_check = {{0x98ab6402, 0x119a8b10, 0xbfff4b, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_307) {
  // -0.3950757263466223
  s21_decimal dec_1 = {{0x5b485eef, 0xe0931, 0x0, 0x80100000}};
  // -11331
  s21_decimal dec_2 = {{0x2c43, 0x0, 0x0, 0x80000000}};
  // 4476.6030552335772813
  s21_decimal dec_check = {{0x5441ec8d, 0x6d40e39b, 0x2, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_308) {
  // 9.60089366
  s21_decimal dec_1 = {{0x3939cd16, 0x0, 0x0, 0x80000}};
  // -3181309032826925.103388960616
  s21_decimal dec_2 = {{0x43fa2768, 0x3ca7cf04, 0xa478464, 0x800c0000}};
  // -30543409723768757.102421916492
  s21_decimal dec_check = {{0x1476bb4c, 0xe1997e31, 0x62b0ea96, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_309) {
  // -438758.97795
  s21_decimal dec_1 = {{0x373511c3, 0xa, 0x0, 0x80050000}};
  // -8270800930766393982.045716
  s21_decimal dec_2 = {{0x876bce14, 0x4515ea3, 0x6d769, 0x80060000}};
  // 3628888163210971733769409.0023
  s21_decimal dec_check = {{0x7e753327, 0x215070b4, 0x75417597, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_310) {
  // 0.419
  s21_decimal dec_1 = {{0x1a3, 0x0, 0x0, 0x30000}};
  // -298661.633
  s21_decimal dec_2 = {{0x11cd3701, 0x0, 0x0, 0x80030000}};
  // -125139.224227
  s21_decimal dec_check = {{0x22e106a3, 0x1d, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_311) {
  // 59863918591592584230
  s21_decimal dec_1 = {{0x52c75426, 0x3ec75cc9, 0x3, 0x0}};
  // -693686
  s21_decimal dec_2 = {{0xa95b6, 0x0, 0x0, 0x80000000}};
  // -41526762232127493384171780
  s21_decimal dec_check = {{0x272bf104, 0x4a9a6018, 0x2259a2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_312) {
  // 13733594643961308274325
  s21_decimal dec_1 = {{0xd9105e95, 0x7fe98cfa, 0x2e8, 0x0}};
  // -1.1976
  s21_decimal dec_2 = {{0x2ec8, 0x0, 0x0, 0x80040000}};
  // -16447352945608062789331.6200
  s21_decimal dec_check = {{0x85c8aa68, 0xe5cb36fa, 0x880c9f, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_313) {
  // -31.14
  s21_decimal dec_1 = {{0xc2a, 0x0, 0x0, 0x80020000}};
  // -14536.8116695924372
  s21_decimal dec_2 = {{0x2d53fe94, 0x2047388, 0x0, 0x800d0000}};
  // 452676.315391108494408
  s21_decimal dec_check = {{0x5fb6b448, 0x8a255677, 0x18, 0xf0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_314) {
  // 96.60349
  s21_decimal dec_1 = {{0x9367bd, 0x0, 0x0, 0x50000}};
  // -97393630602034024792
  s21_decimal dec_2 = {{0xdbda1158, 0x479baf04, 0x5, 0x80000000}};
  // -9408564619927287893653.72408
  s21_decimal dec_check = {{0x28135f8, 0x1256943, 0x30a421b, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_315) {
  // 88082312447775293
  s21_decimal dec_1 = {{0x8071d23d, 0x138ee65, 0x0, 0x0}};
  // -80
  s21_decimal dec_2 = {{0x50, 0x0, 0x0, 0x80000000}};
  // -7046584995822023440
  s21_decimal dec_check = {{0x2391b310, 0x61ca7fb8, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_316) {
  // -5435051497249628291264
  s21_decimal dec_1 = {{0x8f0d00c0, 0xa27dcc9c, 0x126, 0x80000000}};
  // 973253
  s21_decimal dec_2 = {{0xed9c5, 0x0, 0x0, 0x0}};
  // -5289680174852692483357561792
  s21_decimal dec_check = {{0x252453c0, 0xddcefc72, 0x11178558, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_317) {
  // -7817945257232
  s21_decimal dec_1 = {{0x41d99510, 0x71c, 0x0, 0x80000000}};
  // -97
  s21_decimal dec_2 = {{0x61, 0x0, 0x0, 0x80000000}};
  // 758340689951504
  s21_decimal dec_check = {{0xf3717b10, 0x2b1b4, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_318) {
  // -88690.40546935839821
  s21_decimal dec_1 = {{0x22a59c4d, 0x7b152963, 0x0, 0x800e0000}};
  // 65599220555.7214055
  s21_decimal dec_2 = {{0x73a9ab67, 0x91a8d6f, 0x0, 0x70000}};
  // -5818021469560801.6048221324365
  s21_decimal dec_check = {{0x2a34044d, 0x6ebc8565, 0xbbfd8bae, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_319) {
  // 1709100594902109723775
  s21_decimal dec_1 = {{0x450b1c7f, 0xa6890fdc, 0x5c, 0x0}};
  // -0.19531
  s21_decimal dec_2 = {{0x4c4b, 0x0, 0x0, 0x80050000}};
  // -333804437190331050150.49525
  s21_decimal dec_check = {{0x86b70d35, 0x7add0a07, 0x1b9c95, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_320) {
  // 69346105
  s21_decimal dec_1 = {{0x4222339, 0x0, 0x0, 0x0}};
  // -15.3
  s21_decimal dec_2 = {{0x99, 0x0, 0x0, 0x80010000}};
  // -1060995406.5
  s21_decimal dec_check = {{0x78670d11, 0x2, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_321) {
  // 432738823275740301530
  s21_decimal dec_1 = {{0x4f0a88da, 0x75752305, 0x17, 0x0}};
  // 5864
  s21_decimal dec_2 = {{0x16e8, 0x0, 0x0, 0x0}};
  // 2537580459688941128171920
  s21_decimal dec_check = {{0x894ec190, 0x832a319a, 0x2195a, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_322) {
  // 5235933266
  s21_decimal dec_1 = {{0x38160052, 0x1, 0x0, 0x0}};
  // 37
  s21_decimal dec_2 = {{0x25, 0x0, 0x0, 0x0}};
  // 193729530842
  s21_decimal dec_check = {{0x1b2e0bda, 0x2d, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_323) {
  // 442666848969
  s21_decimal dec_1 = {{0x110012c9, 0x67, 0x0, 0x0}};
  // -42842689168003164
  s21_decimal dec_2 = {{0xe514d05c, 0x983532, 0x0, 0x80000000}};
  // -18965038215358268865702137916
  s21_decimal dec_check = {{0x6ffe103c, 0xb7d58feb, 0x3d47830d, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_324) {
  // 76035671327749.3809
  s21_decimal dec_1 = {{0xf57d1231, 0xa8d5466, 0x0, 0x40000}};
  // 9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x0}};
  // 684321041949744.4281
  s21_decimal dec_check = {{0xa165a3b9, 0x5ef7f79e, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_325) {
  // -8671623493763.1909
  s21_decimal dec_1 = {{0xcbb784a5, 0x13413f4, 0x0, 0x80040000}};
  // -988239837
  s21_decimal dec_2 = {{0x3ae757dd, 0x0, 0x0, 0x80000000}};
  // 8569643788001906291615.8833
  s21_decimal dec_check = {{0x4e649571, 0x34c8d235, 0x46e2ed, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_326) {
  // 92.018
  s21_decimal dec_1 = {{0x16772, 0x0, 0x0, 0x30000}};
  // 94.19489
  s21_decimal dec_2 = {{0x8fbae1, 0x0, 0x0, 0x50000}};
  // 8667.62538802
  s21_decimal dec_check = {{0xcf12bf32, 0xc9, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_327) {
  // -959132905557497646
  s21_decimal dec_1 = {{0xc024972e, 0xd4f864b, 0x0, 0x80000000}};
  // -706
  s21_decimal dec_2 = {{0x2c2, 0x0, 0x0, 0x80000000}};
  // 677147831323593338076
  s21_decimal dec_check = {{0xe4e8ecdc, 0xb5505ce7, 0x24, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_328) {
  // 2069761195583351207
  s21_decimal dec_1 = {{0x60a229a7, 0x1cb944d7, 0x0, 0x0}};
  // 837.234640
  s21_decimal dec_2 = {{0x31e72fd0, 0x0, 0x0, 0x60000}};
  // 1732875769470196637786.210480
  s21_decimal dec_check = {{0xd61880b0, 0xb202b608, 0x59966b7, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_330) {
  // 13886
  s21_decimal dec_1 = {{0x363e, 0x0, 0x0, 0x0}};
  // -36.3477
  s21_decimal dec_2 = {{0x58bd5, 0x0, 0x0, 0x80040000}};
  // -504724.1622
  s21_decimal dec_check = {{0x2cd6cb96, 0x1, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_331) {
  // -75.41267
  s21_decimal dec_1 = {{0x731213, 0x0, 0x0, 0x80050000}};
  // -40.6
  s21_decimal dec_2 = {{0x196, 0x0, 0x0, 0x80010000}};
  // 3061.754402
  s21_decimal dec_check = {{0xb67eaa22, 0x0, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_332) {
  // 25.45054149601042
  s21_decimal dec_1 = {{0x98856712, 0x90ab6, 0x0, 0xe0000}};
  // 5056981967266272
  s21_decimal dec_2 = {{0x5dcb61e0, 0x11f74c, 0x0, 0x0}};
  // 128702929402486662.96932182655
  s21_decimal dec_check = {{0x8ff12a7f, 0x512ef476, 0x29960e8a, 0xb0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_333) {
  // 13075052.425002800995
  s21_decimal dec_1 = {{0xebe6d763, 0xb573eae7, 0x0, 0xc0000}};
  // 7174370.34
  s21_decimal dec_2 = {{0x2ac3386a, 0x0, 0x0, 0x20000}};
  // 93805268311885.16987545048830
  s21_decimal dec_check = {{0x7b1bd6fe, 0x78be8fce, 0x1e4f63d2, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_334) {
  // -136290823002998
  s21_decimal dec_1 = {{0xae175b76, 0x7bf4, 0x0, 0x80000000}};
  // -3996946182117
  s21_decimal dec_2 = {{0x9c8eafe5, 0x3a2, 0x0, 0x80000000}};
  // 544747084659416656944986766
  s21_decimal dec_check = {{0x55de7a8e, 0xa1d4343e, 0x1c29aae, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_335) {
  // 56313265468.4435
  s21_decimal dec_1 = {{0x89d80913, 0x2002a, 0x0, 0x40000}};
  // 839902.7
  s21_decimal dec_2 = {{0x8028b3, 0x0, 0x0, 0x10000}};
  // 47297663712762460.44745
  s21_decimal dec_check = {{0xacf95049, 0x66b1af4c, 0x100, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_336) {
  // 7447949043262.3692675730357412
  s21_decimal dec_1 = {{0x7ebbca4, 0xa2193b51, 0xf0a7fd92, 0x100000}};
  // 7.137216619438
  s21_decimal dec_2 = {{0xc342e3ae, 0x67d, 0x0, 0xc0000}};
  // 53157625692299.533594786046228
  s21_decimal dec_check = {{0x6f74a114, 0xfcf58044, 0xabc2f516, 0xf0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_337) {
  // 0.036893514682
  s21_decimal dec_1 = {{0x97065bba, 0x8, 0x0, 0xc0000}};
  // -8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -0.295148117456
  s21_decimal dec_check = {{0xb832ddd0, 0x44, 0x0, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_339) {
  // 818686
  s21_decimal dec_1 = {{0xc7dfe, 0x0, 0x0, 0x0}};
  // -910787685514567467243
  s21_decimal dec_2 = {{0x5ffbc0eb, 0x5fb7de6a, 0x31, 0x80000000}};
  // -745649127103179181487302698
  s21_decimal dec_check = {{0x3400282a, 0x2d051e36, 0x268c958, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_340) {
  // -597787.31920
  s21_decimal dec_1 = {{0xeb170f90, 0xd, 0x0, 0x80050000}};
  // 489463849
  s21_decimal dec_2 = {{0x1d2ca029, 0x0, 0x0, 0x0}};
  // -292595282139023.60080
  s21_decimal dec_check = {{0xd2b7e10, 0x960eb9e3, 0x1, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_341) {
  // -0.5345
  s21_decimal dec_1 = {{0x14e1, 0x0, 0x0, 0x80040000}};
  // 18145776.076827703193306
  s21_decimal dec_2 = {{0xc88d2eda, 0xaf3ae16e, 0x3d7, 0xf0000}};
  // -9698917.3130644073568220570
  s21_decimal dec_check = {{0x4bbf359a, 0x9c5cca09, 0x503a41, 0x80130000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_342) {
  // -8.077638224634121464
  s21_decimal dec_1 = {{0xb6f0cf8, 0x7019892b, 0x0, 0x80120000}};
  // -54105113967204959457395.7
  s21_decimal dec_2 = {{0x62ea485, 0x70e8d7ef, 0x7292, 0x80010000}};
  // 437041536729680277034200.66269
  s21_decimal dec_check = {{0x6f3719dd, 0xf190aaa0, 0x8d373a85, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_343) {
  // 67481844019
  s21_decimal dec_1 = {{0xb63b3933, 0xf, 0x0, 0x0}};
  // 355268284.6784
  s21_decimal dec_2 = {{0x2c662a40, 0x33b, 0x0, 0x40000}};
  // 23974158971565476378.4896
  s21_decimal dec_check = {{0xd482aac0, 0x6ae92901, 0x32c4, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_344) {
  // 12736.23147419687
  s21_decimal dec_1 = {{0x7f479827, 0x4865a, 0x0, 0xb0000}};
  // -832624846438706639
  s21_decimal dec_2 = {{0xeb24adcf, 0xb8e13e2, 0x0, 0x80000000}};
  // -10604502775410991161002.944062
  s21_decimal dec_check = {{0xc6e3e63e, 0x5c888133, 0x2243d6cf, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_345) {
  // -938556371
  s21_decimal dec_1 = {{0x37f13bd3, 0x0, 0x0, 0x80000000}};
  // 2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x0}};
  // -1877112742
  s21_decimal dec_check = {{0x6fe277a6, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_346) {
  // -0.5412
  s21_decimal dec_1 = {{0x1524, 0x0, 0x0, 0x80040000}};
  // 684050004299705619769238
  s21_decimal dec_2 = {{0xbf22e796, 0x6ccf4254, 0x90da, 0x0}};
  // -370207862327000681419111.6056
  s21_decimal dec_check = {{0xbde7df18, 0x4d964798, 0xbf649a4, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_347) {
  // -21648141468333
  s21_decimal dec_1 = {{0x59c842ad, 0x13b0, 0x0, 0x80000000}};
  // -41293936
  s21_decimal dec_2 = {{0x2761870, 0x0, 0x0, 0x80000000}};
  // 893936968312288928688
  s21_decimal dec_check = {{0x239b63b0, 0x75de1866, 0x30, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_348) {
  // 0.706785
  s21_decimal dec_1 = {{0xac8e1, 0x0, 0x0, 0x60000}};
  // -0.383712078
  s21_decimal dec_2 = {{0x16defb4e, 0x0, 0x0, 0x80090000}};
  // -0.271201941049230
  s21_decimal dec_check = {{0x1f5bcf8e, 0xf6a8, 0x0, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_349) {
  // -0.529
  s21_decimal dec_1 = {{0x211, 0x0, 0x0, 0x80030000}};
  // 20715507
  s21_decimal dec_2 = {{0x13c17f3, 0x0, 0x0, 0x0}};
  // -10958503.203
  s21_decimal dec_check = {{0x8d2d7d23, 0x2, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_350) {
  // -2487783181
  s21_decimal dec_1 = {{0x94488f0d, 0x0, 0x0, 0x80000000}};
  // 8617686757715344807.65892
  s21_decimal dec_2 = {{0x422bf3c4, 0x92d26015, 0xb67c, 0x50000}};
  // -21438936174970656798109541161
  s21_decimal dec_check = {{0x4f1b2329, 0xd5852459, 0x4545df52, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_351) {
  // 763999439.706445501637
  s21_decimal dec_1 = {{0xc26d4c5, 0x6a9f4292, 0x29, 0xc0000}};
  // -754.4
  s21_decimal dec_2 = {{0x1d78, 0x0, 0x0, 0x80010000}};
  // -576361177314.5424864349528
  s21_decimal dec_check = {{0x184e0d58, 0x531bfd6, 0x4c47e, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_352) {
  // 0.8639973335
  s21_decimal dec_1 = {{0x2fb87d7, 0x2, 0x0, 0xa0000}};
  // 1272956230983479323077
  s21_decimal dec_2 = {{0x1661e9c5, 0x1d103ab, 0x45, 0x0}};
  // 1099830789231936217690.9130152
  s21_decimal dec_check = {{0x25ad39a8, 0x869e813d, 0x23899649, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_353) {
  // -1866818438580.87412025770193
  s21_decimal dec_1 = {{0xdbf3c0d1, 0x8a25390, 0x9a6b6b, 0x800e0000}};
  // 203735233
  s21_decimal dec_2 = {{0xc24c0c1, 0x0, 0x0, 0x0}};
  // -380336689552970578234.37292275
  s21_decimal dec_check = {{0xc84702f3, 0x7245d0b2, 0x7ae4b6ad, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_354) {
  // 827226884
  s21_decimal dec_1 = {{0x314e7b04, 0x0, 0x0, 0x0}};
  // -894121.48527107517064501
  s21_decimal dec_2 = {{0xd5a22535, 0xad31f89, 0x12ef, 0x80110000}};
  // -739641330178243.40874243989245
  s21_decimal dec_check = {{0x89e9defd, 0x32544f93, 0xeefdb265, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_355) {
  // 622.7
  s21_decimal dec_1 = {{0x1853, 0x0, 0x0, 0x10000}};
  // 642.5
  s21_decimal dec_2 = {{0x1919, 0x0, 0x0, 0x10000}};
  // 400084.75
  s21_decimal dec_check = {{0x2627b1b, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_357) {
  // 93
  s21_decimal dec_1 = {{0x5d, 0x0, 0x0, 0x0}};
  // -1121099234649
  s21_decimal dec_2 = {{0x6b8bd59, 0x105, 0x0, 0x80000000}};
  // -104262228822357
  s21_decimal dec_check = {{0x711cc955, 0x5ed3, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_358) {
  // -0.018110423
  s21_decimal dec_1 = {{0x11457d7, 0x0, 0x0, 0x80090000}};
  // -69169353.425882186201426408592
  s21_decimal dec_2 = {{0xca69b490, 0xb01def0f, 0xdf7f8c52, 0x80150000}};
  // 1252686.2491792255402725954630
  s21_decimal dec_check = {{0xb4695446, 0x66c34608, 0x2879fa50, 0x160000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_359) {
  // 9
  s21_decimal dec_1 = {{0x9, 0x0, 0x0, 0x0}};
  // -28959402125614894776
  s21_decimal dec_2 = {{0xbcf7ceb8, 0x91e476cc, 0x1, 0x80000000}};
  // -260634619130534052984
  s21_decimal dec_check = {{0xa4b64478, 0x21082d32, 0xe, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_360) {
  // 34852588301401071520316
  s21_decimal dec_1 = {{0x89cb8a3c, 0x5cd33332, 0x761, 0x0}};
  // 90.8955
  s21_decimal dec_2 = {{0xdde9b, 0x0, 0x0, 0x40000}};
  // 3167943439950001096374882.9780
  s21_decimal dec_check = {{0xf528ba54, 0xf3d6d26d, 0x665c9d2b, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_361) {
  // 656254.9395
  s21_decimal dec_1 = {{0x87288e93, 0x1, 0x0, 0x40000}};
  // -4584075800960929
  s21_decimal dec_2 = {{0x51bd5fa1, 0x104931, 0x0, 0x80000000}};
  // -3008322387423028502758.7955
  s21_decimal dec_check = {{0xd2f13773, 0xd580654e, 0x18e25e, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_362) {
  // 825.65
  s21_decimal dec_1 = {{0x14285, 0x0, 0x0, 0x20000}};
  // -569
  s21_decimal dec_2 = {{0x239, 0x0, 0x0, 0x80000000}};
  // -469794.85
  s21_decimal dec_check = {{0x2ccd99d, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_363) {
  // -99944.807948593
  s21_decimal dec_1 = {{0x36c66131, 0x5ae6, 0x0, 0x80090000}};
  // -2.79386
  s21_decimal dec_2 = {{0x4435a, 0x0, 0x0, 0x80050000}};
  // 279231.80113525603898
  s21_decimal dec_check = {{0xb1f1fe3a, 0x8383105e, 0x1, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_364) {
  // -95173846.817
  s21_decimal dec_1 = {{0x28cda721, 0x16, 0x0, 0x80030000}};
  // -72244.152603
  s21_decimal dec_2 = {{0xd216491b, 0x10, 0x0, 0x80060000}};
  // 6875753913261.893814651
  s21_decimal dec_check = {{0x612f097b, 0xbc40face, 0x174, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_365) {
  // 2.154
  s21_decimal dec_1 = {{0x86a, 0x0, 0x0, 0x30000}};
  // -294278423
  s21_decimal dec_2 = {{0x118a5517, 0x0, 0x0, 0x80000000}};
  // -633875723.142
  s21_decimal dec_check = {{0x95eff386, 0x93, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_366) {
  // -0.273561
  s21_decimal dec_1 = {{0x42c99, 0x0, 0x0, 0x80060000}};
  // 0.664750416944
  s21_decimal dec_2 = {{0xc6366430, 0x9a, 0x0, 0xc0000}};
  // -0.181849788809617584
  s21_decimal dec_check = {{0x607a20b0, 0x2860f6b, 0x0, 0x80120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_367) {
  // 0.7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x10000}};
  // 2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x0}};
  // 1.4
  s21_decimal dec_check = {{0xe, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_368) {
  // 9238667042935
  s21_decimal dec_1 = {{0xb77a077, 0x867, 0x0, 0x0}};
  // 0.4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x10000}};
  // 3695466817174.0
  s21_decimal dec_check = {{0x2dde81dc, 0x219c, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_369) {
  // -64612918444887101491408.57
  s21_decimal dec_1 = {{0xe4107179, 0x552ea31c, 0x5583b, 0x80020000}};
  // -53714.1085707811731
  s21_decimal dec_2 = {{0xb7e1bb93, 0x7744ef8, 0x0, 0x800d0000}};
  // 3470625316423695204703768487.4
  s21_decimal dec_check = {{0xb2ab9c8a, 0xf991c9b2, 0x702456f9, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_370) {
  // 3054.1
  s21_decimal dec_1 = {{0x774d, 0x0, 0x0, 0x10000}};
  // 89196.312967503759459
  s21_decimal dec_2 = {{0xc6a14863, 0xd5d8f60f, 0x4, 0xf0000}};
  // 272414459.4340532317637319
  s21_decimal dec_check = {{0xb728cac7, 0x2ca35813, 0x240dc, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_371) {
  // -454072693
  s21_decimal dec_1 = {{0x1b109975, 0x0, 0x0, 0x80000000}};
  // -228537611
  s21_decimal dec_2 = {{0xd9f350b, 0x0, 0x0, 0x80000000}};
  // 103772688478556423
  s21_decimal dec_check = {{0xda26d107, 0x170acb5, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_372) {
  // -1743
  s21_decimal dec_1 = {{0x6cf, 0x0, 0x0, 0x80000000}};
  // 78653700404676.3984721
  s21_decimal dec_2 = {{0xcb588751, 0xa364c5ed, 0x2a, 0x70000}};
  // -137093399805350962.5368703
  s21_decimal dec_check = {{0x7fc1507f, 0x7b1f9e0b, 0x1224e, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_373) {
  // 976.189
  s21_decimal dec_1 = {{0xee53d, 0x0, 0x0, 0x30000}};
  // -4991505960506501732985113
  s21_decimal dec_2 = {{0x8de36919, 0x148fb4a7, 0x420fe, 0x80000000}};
  // -4872653212080881420221004474.4
  s21_decimal dec_check = {{0x7d654b48, 0x273d74f6, 0x9d71a487, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_374) {
  // 97
  s21_decimal dec_1 = {{0x61, 0x0, 0x0, 0x0}};
  // 982826195585352.4573967704
  s21_decimal dec_2 = {{0xbcfd5558, 0x25f16537, 0x82137, 0xa0000}};
  // 95334140971779188.3674867288
  s21_decimal dec_check = {{0x9bfd5658, 0x60775a1e, 0x31495e5, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_376) {
  // 8688795
  s21_decimal dec_1 = {{0x84949b, 0x0, 0x0, 0x0}};
  // -87413218
  s21_decimal dec_2 = {{0x535d1e2, 0x0, 0x0, 0x80000000}};
  // -759515531492310
  s21_decimal dec_check = {{0x7d74bbd6, 0x2b2c6, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_377) {
  // 49.64091198472930
  s21_decimal dec_1 = {{0x8c8482e2, 0x11a2d0, 0x0, 0xe0000}};
  // 6236259
  s21_decimal dec_2 = {{0x5f2863, 0x0, 0x0, 0x0}};
  // 309573584.13297595968870
  s21_decimal dec_check = {{0x9d8fed66, 0x33a6b1c7, 0x68e, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_378) {
  // 99911700.59
  s21_decimal dec_1 = {{0x5385280b, 0x2, 0x0, 0x20000}};
  // 513012715808
  s21_decimal dec_2 = {{0x71f0d120, 0x77, 0x0, 0x0}};
  // 51255972860671655926.72
  s21_decimal dec_check = {{0x8ba5fc60, 0xdbf39719, 0x115, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_379) {
  // 7632970
  s21_decimal dec_1 = {{0x74784a, 0x0, 0x0, 0x0}};
  // 498069.368377781560
  s21_decimal dec_2 = {{0x9fa92d38, 0x6e97f73, 0x0, 0xc0000}};
  // 3801748546746.555314033200
  s21_decimal dec_check = {{0xf1795230, 0x33a162eb, 0x3250d, 0xc0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_380) {
  // 7935978
  s21_decimal dec_1 = {{0x7917ea, 0x0, 0x0, 0x0}};
  // 2919
  s21_decimal dec_2 = {{0xb67, 0x0, 0x0, 0x0}};
  // 23165119782
  s21_decimal dec_check = {{0x64bfad26, 0x5, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_381) {
  // 3.5
  s21_decimal dec_1 = {{0x23, 0x0, 0x0, 0x10000}};
  // 5502
  s21_decimal dec_2 = {{0x157e, 0x0, 0x0, 0x0}};
  // 19257.0
  s21_decimal dec_check = {{0x2f03a, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_382) {
  // 67540497855040254
  s21_decimal dec_1 = {{0x969a4afe, 0xeff3b9, 0x0, 0x0}};
  // -25
  s21_decimal dec_2 = {{0x19, 0x0, 0x0, 0x80000000}};
  // -1688512446376006350
  s21_decimal dec_check = {{0xb51152ce, 0x176ecd1f, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_383) {
  // 42225309351606710519908
  s21_decimal dec_1 = {{0x59d14864, 0x9e22002, 0x8f1, 0x0}};
  // -347.78760470566
  s21_decimal dec_2 = {{0x8fa9e026, 0x1fa1, 0x0, 0x800b0000}};
  // -14685439197350803199095188.966
  s21_decimal dec_check = {{0xb577ade6, 0x15653f63, 0x2f7382b6, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_384) {
  // -2497446469056814406
  s21_decimal dec_1 = {{0xe1af5d46, 0x22a8b654, 0x0, 0x80000000}};
  // 813.963730787
  s21_decimal dec_2 = {{0x8404df63, 0xbd, 0x0, 0x90000}};
  // -2032830845394304606973.2073175
  s21_decimal dec_check = {{0xdda95ed7, 0x6f9f5296, 0x41af2ec1, 0x80070000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_385) {
  // -542
  s21_decimal dec_1 = {{0x21e, 0x0, 0x0, 0x80000000}};
  // -28519
  s21_decimal dec_2 = {{0x6f67, 0x0, 0x0, 0x80000000}};
  // 15457298
  s21_decimal dec_check = {{0xebdc12, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_386) {
  // 16.231056457805896717733209164
  s21_decimal dec_1 = {{0xcda8244c, 0xaa163704, 0x347203e5, 0x1b0000}};
  // 0.4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x10000}};
  // 6.4924225831223586870932836656
  s21_decimal dec_check = {{0x36a09130, 0xa858dc13, 0xd1c80f96, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_387) {
  // 97
  s21_decimal dec_1 = {{0x61, 0x0, 0x0, 0x0}};
  // 169758736915380898567
  s21_decimal dec_2 = {{0xe0450b07, 0x33e02fcd, 0x9, 0x0}};
  // 16466597480791947160999
  s21_decimal dec_check = {{0xfa292da7, 0xa7f21d01, 0x37c, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_388) {
  // 706443058538.8352505249
  s21_decimal dec_1 = {{0xd9985a1, 0xf6ab2c74, 0x17e, 0xa0000}};
  // -7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x80000000}};
  // -4945101409771.8467536743
  s21_decimal dec_check = {{0x5f32a767, 0xbeae372c, 0xa78, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_389) {
  // 126.0528267
  s21_decimal dec_1 = {{0x4b22228b, 0x0, 0x0, 0x70000}};
  // 0.03
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x20000}};
  // 3.781584801
  s21_decimal dec_check = {{0xe16667a1, 0x0, 0x0, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_390) {
  // 222243.35661795035747669519027
  s21_decimal dec_1 = {{0x34282ab3, 0x540901c3, 0x47cf8a22, 0x170000}};
  // -5359053.042755464
  s21_decimal dec_2 = {{0xc4f22788, 0x130a07, 0x0, 0x80090000}};
  // -1191013936515.6145502044940524
  s21_decimal dec_check = {{0x8f1de8ec, 0xb7228d67, 0x267bd61c, 0x80100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_391) {
  // -947282277303.5412
  s21_decimal dec_1 = {{0x6c683194, 0x21a77b, 0x0, 0x80040000}};
  // -53304571
  s21_decimal dec_2 = {{0x32d5cfb, 0x0, 0x0, 0x80000000}};
  // 50494475407568300446.8252
  s21_decimal dec_check = {{0x2efdcc1c, 0x1c26d7de, 0x6aed, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_392) {
  // -64568580.4918388920029157542
  s21_decimal dec_1 = {{0x6d2e18a6, 0x9f2cdf40, 0x2161949, 0x80130000}};
  // 7102461607249848
  s21_decimal dec_2 = {{0xb52187b8, 0x193ba6, 0x0, 0x0}};
  // -458595863977907237978853.43975
  s21_decimal dec_check = {{0x3bb58e7, 0x16ac7eb5, 0x942e2928, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_393) {
  // -109.15617462
  s21_decimal dec_1 = {{0x8a9f1ab6, 0x2, 0x0, 0x80080000}};
  // -52695.83241389
  s21_decimal dec_2 = {{0xeba320ad, 0x4ca, 0x0, 0x80080000}};
  // 5752075.4847168329534718
  s21_decimal dec_check = {{0xa4bdccfe, 0x34d48f7a, 0xc2e, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_394) {
  // 72
  s21_decimal dec_1 = {{0x48, 0x0, 0x0, 0x0}};
  // 32448827925606291168
  s21_decimal dec_2 = {{0xbb89d6e0, 0xc2516513, 0x1, 0x0}};
  // 2336315610643652964096
  s21_decimal dec_check = {{0xbec46f00, 0xa6e46d8c, 0x7e, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_395) {
  // 9384479542302989583104
  s21_decimal dec_1 = {{0xfa178300, 0xbbd0d69e, 0x1fc, 0x0}};
  // -6.5
  s21_decimal dec_2 = {{0x41, 0x0, 0x0, 0x80010000}};
  // -60999117024969432290176.0
  s21_decimal dec_check = {{0x7ff84300, 0xb0067e5d, 0x812b, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_396) {
  // 35.67
  s21_decimal dec_1 = {{0xdef, 0x0, 0x0, 0x20000}};
  // 6000835126761201940
  s21_decimal dec_2 = {{0x649a114, 0x53473fc1, 0x0, 0x0}};
  // 214049788971572073199.80
  s21_decimal dec_check = {{0x9beb65ac, 0x5dc15286, 0x488, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_399) {
  // 7.9619156710785249226
  s21_decimal dec_1 = {{0x26836fca, 0x50f01130, 0x4, 0x130000}};
  // -0.38
  s21_decimal dec_2 = {{0x26, 0x0, 0x0, 0x80020000}};
  // -3.025527955009839470588
  s21_decimal dec_check = {{0xb78297fc, 0x3a28d25, 0xa4, 0x80150000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_400) {
  // 16093423501041
  s21_decimal dec_1 = {{0xaca7ef1, 0xea3, 0x0, 0x0}};
  // -29
  s21_decimal dec_2 = {{0x1d, 0x0, 0x0, 0x80000000}};
  // -466709281530189
  s21_decimal dec_check = {{0x38f0614d, 0x1a878, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_401) {
  // -58983.9
  s21_decimal dec_1 = {{0x9000f, 0x0, 0x0, 0x80010000}};
  // 0.075335016
  s21_decimal dec_2 = {{0x47d8568, 0x0, 0x0, 0x90000}};
  // -4443.5530502424
  s21_decimal dec_check = {{0xf402d118, 0x2869, 0x0, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_403) {
  // -69960875.697931846358956868
  s21_decimal dec_1 = {{0x63747b44, 0xabc8e76d, 0x39deca, 0x80120000}};
  // 5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  // -349804378.489659231794784340
  s21_decimal dec_check = {{0xf1466854, 0x5aec8522, 0x12159f5, 0x80120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_404) {
  // 3389.77819537696
  s21_decimal dec_1 = {{0x6c853120, 0x1344c, 0x0, 0xb0000}};
  // -5287488711584681014132
  s21_decimal dec_2 = {{0xd4c3b374, 0xa2a578de, 0x11e, 0x80000000}};
  // -17923413942831567342454101.807
  s21_decimal dec_check = {{0x92e2d72f, 0xc23d5430, 0x39e9e688, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_405) {
  // -6461099033039.97613
  s21_decimal dec_1 = {{0xa84bf8ad, 0x8f77188, 0x0, 0x80050000}};
  // -6742736587344454.644583406
  s21_decimal dec_2 = {{0xb522cbee, 0x7b9a6841, 0x593d4, 0x80090000}};
  // 43565488844534524456401641468
  s21_decimal dec_check = {{0xc7441ffc, 0x88286f54, 0x8cc4871a, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_406) {
  // 4049611075402386004846671
  s21_decimal dec_1 = {{0xb555284f, 0xdb356770, 0x35989, 0x0}};
  // 292.6936990988067939851
  s21_decimal dec_2 = {{0x1280260b, 0xab6915ba, 0x9e, 0x130000}};
  // 1185295645571021360431466878.9
  s21_decimal dec_check = {{0x4c0f5ef5, 0xfb9c6136, 0x264c8928, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_407) {
  // 41389778107576706638
  s21_decimal dec_1 = {{0x7a59664e, 0x3e6607e5, 0x2, 0x0}};
  // -564970
  s21_decimal dec_2 = {{0x89eea, 0x0, 0x0, 0x80000000}};
  // -23383982937437611949270860
  s21_decimal dec_check = {{0x354ba74c, 0x414eac10, 0x1357c0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_408) {
  // -920667804
  s21_decimal dec_1 = {{0x36e0469c, 0x0, 0x0, 0x80000000}};
  // -63505
  s21_decimal dec_2 = {{0xf811, 0x0, 0x0, 0x80000000}};
  // 58467008893020
  s21_decimal dec_check = {{0xe94bd05c, 0x352c, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_409) {
  // 3.7
  s21_decimal dec_1 = {{0x25, 0x0, 0x0, 0x10000}};
  // 24743613911706771.221448023
  s21_decimal dec_2 = {{0x6acd0557, 0xff77143a, 0x1477a9, 0x90000}};
  // 91551371473315053.5193576851
  s21_decimal dec_check = {{0x6fa1c593, 0xec35ec71, 0x2f54b91, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_410) {
  // 6273783.28558939
  s21_decimal dec_1 = {{0xe669dd5b, 0x23a98, 0x0, 0x80000}};
  // 4905.379080320996229
  s21_decimal dec_2 = {{0xa32a5385, 0x44136848, 0x0, 0xf0000}};
  // 30775285283.597719952198624232
  s21_decimal dec_check = {{0xaca263e8, 0x2ab95f89, 0x6370b826, 0x120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_411) {
  // -3278396472588.2010048446
  s21_decimal dec_1 = {{0xddb197be, 0x38e7ed4c, 0x6f1, 0x800a0000}};
  // 53392.217319247017
  s21_decimal dec_2 = {{0x53158ca9, 0xbdaff0, 0x0, 0xc0000}};
  // -175040856923082074.10738637467
  s21_decimal dec_check = {{0x97a82a9b, 0xbfa78135, 0x388f0a52, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_412) {
  // 55187428017560360
  s21_decimal dec_1 = {{0x630ddb28, 0xc410ac, 0x0, 0x0}};
  // 9.94
  s21_decimal dec_2 = {{0x3e2, 0x0, 0x0, 0x20000}};
  // 548563034494549978.40
  s21_decimal dec_check = {{0x9bccf150, 0xf948bd58, 0x2, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_413) {
  // -397228.4232988613139839302753
  s21_decimal dec_1 = {{0x5c87bc61, 0xc1be33b2, 0xcd5cbe7, 0x80160000}};
  // -96215057715196
  s21_decimal dec_2 = {{0xd0564ffc, 0x5781, 0x0, 0x80000000}};
  // 38219355673816248789.711164838
  s21_decimal dec_check = {{0x7d795a6, 0xa09c85f5, 0x7b7e4f5e, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_414) {
  // -690466300977
  s21_decimal dec_1 = {{0xc2ffa431, 0xa0, 0x0, 0x80000000}};
  // -4224598
  s21_decimal dec_2 = {{0x407656, 0x0, 0x0, 0x80000000}};
  // 2916942554174832246
  s21_decimal dec_check = {{0x63cfbe76, 0x287b0fcc, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_415) {
  // 59.48509386960943059169746
  s21_decimal dec_1 = {{0xd051f1d2, 0x570b8781, 0x4eba5, 0x170000}};
  // 0.66
  s21_decimal dec_2 = {{0x42, 0x0, 0x0, 0x20000}};
  // 39.2601619539422241905203236
  s21_decimal dec_check = {{0xb5205824, 0x70f8ef77, 0x144c0a0, 0x190000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_416) {
  // -647724505981208158
  s21_decimal dec_1 = {{0xa353465e, 0x8fd2e01, 0x0, 0x80000000}};
  // -0.9631418
  s21_decimal dec_2 = {{0x92f6ba, 0x0, 0x0, 0x80070000}};
  // 623850546594851591.4708044
  s21_decimal dec_check = {{0xd1bb744c, 0xf1825a0, 0x5290e, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_417) {
  // 23.866990068
  s21_decimal dec_1 = {{0x8e955df4, 0x5, 0x0, 0x90000}};
  // -179927386258942798.7
  s21_decimal dec_2 = {{0x8949b113, 0x18f84e0b, 0x0, 0x80010000}};
  // -4294325140803387452.7530233116
  s21_decimal dec_check = {{0x399fad1c, 0x8252d15a, 0x8ac1d333, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_419) {
  // 3368.42444444703881
  s21_decimal dec_1 = {{0x26669c89, 0x4acb46b, 0x0, 0xe0000}};
  // 10793175
  s21_decimal dec_2 = {{0xa4b0d7, 0x0, 0x0, 0x0}};
  // 36355994503.19466810812175
  s21_decimal dec_check = {{0x138fa70f, 0x3db9ca20, 0x301de, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_420) {
  // -4225653.26768452091816
  s21_decimal dec_1 = {{0x4e733fa8, 0xe8459dd9, 0x16, 0x800e0000}};
  // 771.34302411300982712190
  s21_decimal dec_2 = {{0x6f9b677e, 0x757b4807, 0x1055, 0x140000}};
  // -3259428170.3488001882629104487
  s21_decimal dec_check = {{0xb106367, 0xad22b7a7, 0x69515b9f, 0x80130000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_421) {
  // 0.82
  s21_decimal dec_1 = {{0x52, 0x0, 0x0, 0x20000}};
  // -905.08724310893
  s21_decimal dec_2 = {{0x345c936d, 0x5251, 0x0, 0x800b0000}};
  // -742.1715393493226
  s21_decimal dec_check = {{0xc5a738ea, 0x1a5e02, 0x0, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_422) {
  // 831315
  s21_decimal dec_1 = {{0xcaf53, 0x0, 0x0, 0x0}};
  // 356.580535071
  s21_decimal dec_2 = {{0x5db2b1f, 0x53, 0x0, 0x90000}};
  // 296430747.512548365
  s21_decimal dec_check = {{0xbdfd2c0d, 0x41d2231, 0x0, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_423) {
  // -41942069430190481615
  s21_decimal dec_1 = {{0x9b4620cf, 0x461029ed, 0x2, 0x80000000}};
  // 3248261.11361475
  s21_decimal dec_2 = {{0x78fb41c3, 0x1276d, 0x0, 0x80000}};
  // -136238793154617696794955536.07
  s21_decimal dec_check = {{0xa8cce247, 0x93403bec, 0x2c0568a9, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_424) {
  // -8038192978356150965729
  s21_decimal dec_1 = {{0xad8f95e1, 0xc05625a4, 0x1b3, 0x80000000}};
  // -4553919
  s21_decimal dec_2 = {{0x457cbf, 0x0, 0x0, 0x80000000}};
  // 36605279729802664649701641951
  s21_decimal dec_check = {{0x705ecedf, 0x5fe4a1a2, 0x76472d7e, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_425) {
  // -0.427338
  s21_decimal dec_1 = {{0x6854a, 0x0, 0x0, 0x80060000}};
  // 643090937
  s21_decimal dec_2 = {{0x2654c9f9, 0x0, 0x0, 0x0}};
  // -274817194.835706
  s21_decimal dec_check = {{0xdd46befa, 0xf9f1, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_426) {
  // 776083000878782654146
  s21_decimal dec_1 = {{0x6f02a6c2, 0x1250b16f, 0x2a, 0x0}};
  // -3244489.28797
  s21_decimal dec_2 = {{0x8aa9c41d, 0x4b, 0x0, 0x80050000}};
  // -2517992982926822417830542308.4
  s21_decimal dec_check = {{0x4084d6ec, 0x323dfb64, 0x515c598b, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_427) {
  // -469154446519.638286
  s21_decimal dec_1 = {{0xc199190e, 0x682c57b, 0x0, 0x80060000}};
  // 33122214479453
  s21_decimal dec_2 = {{0xddd4065d, 0x1e1f, 0x0, 0x0}};
  // -15539434201612521358665339.138
  s21_decimal dec_check = {{0x9c5a5102, 0x7792553, 0x3235eb30, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_428) {
  // -69255.0506320095361202541
  s21_decimal dec_1 = {{0x1bfd796d, 0x3cf91049, 0x92a7, 0x80130000}};
  // -493575
  s21_decimal dec_2 = {{0x78807, 0x0, 0x0, 0x80000000}};
  // 34182561615.694106790554417408
  s21_decimal dec_check = {{0x130ab900, 0x3e2567ae, 0x6e7326fa, 0x120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_429) {
  // -176401972913.80
  s21_decimal dec_1 = {{0x2db17d74, 0x100b, 0x0, 0x80020000}};
  // 941.8030805589526058882
  s21_decimal dec_2 = {{0x61b41782, 0x8d6eded1, 0x1fe, 0x130000}};
  // -166135921506893.75694798818279
  s21_decimal dec_check = {{0xa8dd8be7, 0x20d6c732, 0x35ae70fb, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_430) {
  // 0.899516790
  s21_decimal dec_1 = {{0x359d8976, 0x0, 0x0, 0x90000}};
  // -799209193099442358
  s21_decimal dec_2 = {{0xd7eb38b6, 0xb175c86, 0x0, 0x80000000}};
  // -718902087915300540.658190820
  s21_decimal dec_check = {{0xdd6389e4, 0x46aeedb3, 0x252a970, 0x80090000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_431) {
  // -96.7051192965142728
  s21_decimal dec_1 = {{0xb44e18c8, 0xd6ba7ef, 0x0, 0x80100000}};
  // 39.6
  s21_decimal dec_2 = {{0x18c, 0x0, 0x0, 0x10000}};
  // -3829.52272414196520288
  s21_decimal dec_check = {{0xe8ce5560, 0xc287c6ca, 0x14, 0x80110000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_432) {
  // 15728.7306
  s21_decimal dec_1 = {{0x960038a, 0x0, 0x0, 0x40000}};
  // 9959887915.231173657321
  s21_decimal dec_2 = {{0xabffc2e9, 0xed360927, 0x21b, 0xc0000}};
  // 156656393824866.76717781872672
  s21_decimal dec_check = {{0xbd6f7020, 0x97e43fb8, 0x329e502c, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_433) {
  // -265
  s21_decimal dec_1 = {{0x109, 0x0, 0x0, 0x80000000}};
  // -52535.5432921991240
  s21_decimal dec_2 = {{0x98230848, 0x74a6ffb, 0x0, 0x800d0000}};
  // 13921918.9724327678600
  s21_decimal dec_check = {{0x7c439288, 0x8c0deb70, 0x7, 0xd0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_434) {
  // -282574082
  s21_decimal dec_1 = {{0x10d7bd02, 0x0, 0x0, 0x80000000}};
  // -735.842605999516
  s21_decimal dec_2 = {{0xb524259c, 0x29d3e, 0x0, 0x800c0000}};
  // 207930048886.800926144312
  s21_decimal dec_check = {{0x70107738, 0xe918e9ee, 0x2c07, 0xc0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_435) {
  // 29710
  s21_decimal dec_1 = {{0x740e, 0x0, 0x0, 0x0}};
  // 262822018581229507117
  s21_decimal dec_2 = {{0xad4c922d, 0x3f636168, 0xe, 0x0}};
  // 7808442172048328656446070
  s21_decimal dec_check = {{0x2c6c6276, 0x7f92c240, 0x67580, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_436) {
  // 3150594834590
  s21_decimal dec_1 = {{0x8e16009e, 0x2dd, 0x0, 0x0}};
  // -541.37658852452960611
  s21_decimal dec_2 = {{0x87bd8963, 0xef4f99e4, 0x2, 0x80110000}};
  // -1705658283373338.8465196933033
  s21_decimal dec_check = {{0xd2929fa9, 0x2cf66b5e, 0x371cdfe8, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_437) {
  // -983072175
  s21_decimal dec_1 = {{0x3a987daf, 0x0, 0x0, 0x80000000}};
  // -1992085217487256.3
  s21_decimal dec_2 = {{0xd5819ff3, 0x46c5e8, 0x0, 0x80010000}};
  // 1958363547540545085623452.5
  s21_decimal dec_check = {{0x44fdfe1d, 0x1a21d9e, 0x1032ff, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_438) {
  // 54152239401132278435
  s21_decimal dec_1 = {{0x1066c2a3, 0xef8366d3, 0x2, 0x0}};
  // -480652842.7
  s21_decimal dec_2 = {{0x1e7dcdab, 0x1, 0x0, 0x80010000}};
  // -26028427806725175228510657174
  s21_decimal dec_check = {{0xbd025a96, 0xb8bfd9df, 0x541a35fa, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_439) {
  // 451059637.6939
  s21_decimal dec_1 = {{0x347ea96b, 0x41a, 0x0, 0x40000}};
  // 1918840076949
  s21_decimal dec_2 = {{0xc3c7fa95, 0x1be, 0x0, 0x0}};
  // 865511309901151136907.9111
  s21_decimal dec_check = {{0x72581947, 0x9f0a6c70, 0x728ca, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_440) {
  // 967955.342159494
  s21_decimal dec_1 = {{0xaa53ee86, 0x37059, 0x0, 0x90000}};
  // 0.4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x10000}};
  // 387182.1368637976
  s21_decimal dec_check = {{0xa94fba18, 0xdc166, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_441) {
  // -691167.6065201799
  s21_decimal dec_1 = {{0xfcab3e87, 0x188e21, 0x0, 0x800a0000}};
  // -923741020812042588539
  s21_decimal dec_2 = {{0x2684517b, 0x137b5c3d, 0x32, 0x80000000}};
  // 638459870399167163722449900.14
  s21_decimal dec_check = {{0x578e883e, 0xa86f9f48, 0xce4c29a4, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_442) {
  // -313679255
  s21_decimal dec_1 = {{0x12b25d97, 0x0, 0x0, 0x80000000}};
  // 22722304593497413528.005850
  s21_decimal dec_2 = {{0x48732cda, 0x99a73091, 0x12cba2, 0x60000}};
  // -7127515576771346519891796663.6
  s21_decimal dec_check = {{0x1797db2c, 0x61400c0a, 0xe64d6d50, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_443) {
  // -5550324768480.7988363385
  s21_decimal dec_1 = {{0xfe444079, 0xd64b4485, 0xbc0, 0x800a0000}};
  // -6856
  s21_decimal dec_2 = {{0x1ac8, 0x0, 0x0, 0x80000000}};
  // 38053026612704356.8219367560
  s21_decimal dec_check = {{0x93dea888, 0xfc32481, 0x13ac46b, 0xa0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_444) {
  // 446780418719
  s21_decimal dec_1 = {{0x6302a9f, 0x68, 0x0, 0x0}};
  // -591829735.69032212088906
  s21_decimal dec_2 = {{0xb94a884a, 0x50bfc033, 0xc88, 0x800e0000}};
  // -264417937122077215686.80236335
  s21_decimal dec_check = {{0x9e1f552f, 0x5c0572cc, 0x5570239d, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_445) {
  // -1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -44264.936
  s21_decimal dec_2 = {{0x2a36de8, 0x0, 0x0, 0x80030000}};
  // 44264.936
  s21_decimal dec_check = {{0x2a36de8, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_446) {
  // 85
  s21_decimal dec_1 = {{0x55, 0x0, 0x0, 0x0}};
  // 1
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  // 85
  s21_decimal dec_check = {{0x55, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_447) {
  // 7917819154471150570692651.2404
  s21_decimal dec_1 = {{0xce49914, 0x4ffebb16, 0xffd6aa3c, 0x40000}};
  // -0.989
  s21_decimal dec_2 = {{0x3dd, 0x0, 0x0, 0x80030000}};
  // -7830723143771967914415032.0768
  s21_decimal dec_check = {{0xbe6a4680, 0x4e17521d, 0xfd063942, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_448) {
  // -885382.66400
  s21_decimal dec_1 = {{0x9d4abb20, 0x14, 0x0, 0x80050000}};
  // 6884622933610596
  s21_decimal dec_2 = {{0x305ed064, 0x187587, 0x0, 0x0}};
  // -6095525793595644625107.74400
  s21_decimal dec_check = {{0xdefb1880, 0x8a0eda40, 0x1f835c7, 0x80050000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_449) {
  // 15091922068
  s21_decimal dec_1 = {{0x838c7494, 0x3, 0x0, 0x0}};
  // -9847723
  s21_decimal dec_2 = {{0x9643ab, 0x0, 0x0, 0x80000000}};
  // -148621068063251164
  s21_decimal dec_check = {{0xf00c9adc, 0x2100212, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_450) {
  // 0.37
  s21_decimal dec_1 = {{0x25, 0x0, 0x0, 0x20000}};
  // 28717997
  s21_decimal dec_2 = {{0x1b633ad, 0x0, 0x0, 0x0}};
  // 10625658.89
  s21_decimal dec_check = {{0x3f557801, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_451) {
  // 2445578676008.7929026
  s21_decimal dec_1 = {{0x69be00c2, 0x5364687c, 0x1, 0x70000}};
  // 9.0493730786
  s21_decimal dec_2 = {{0x11d8bfe2, 0x15, 0x0, 0xa0000}};
  // 22130953832272.202189671191944
  s21_decimal dec_check = {{0x7f0f5588, 0x34cfd1d4, 0x47824bc3, 0xf0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_452) {
  // -56899432108465037.916
  s21_decimal dec_1 = {{0x5a83a25c, 0x15a36409, 0x3, 0x80030000}};
  // -7884297.277890819262
  s21_decimal dec_2 = {{0xf842f4be, 0x6d6aa699, 0x0, 0x800c0000}};
  // 448612037686304377209902.48376
  s21_decimal dec_check = {{0x6e816db8, 0x502df050, 0x90f45169, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_453) {
  // 9985323280584430405915
  s21_decimal dec_1 = {{0x7125491b, 0x4e329b2e, 0x21d, 0x0}};
  // -55.3147
  s21_decimal dec_2 = {{0x870bb, 0x0, 0x0, 0x80040000}};
  // -552335161668543592574066.4505
  s21_decimal dec_check = {{0x3f1036b9, 0x1c4f3597, 0x11d8cf33, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_454) {
  // -1443364349617426
  s21_decimal dec_1 = {{0x73572512, 0x520bb, 0x0, 0x80000000}};
  // -9349437618
  s21_decimal dec_2 = {{0x2d4518b2, 0x2, 0x0, 0x80000000}};
  // 13494644946793266552731268
  s21_decimal dec_check = {{0x85eb7684, 0x2b1d074b, 0xb299a, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_455) {
  // -9051044769476584913
  s21_decimal dec_1 = {{0x6acf25d1, 0x7d9bc543, 0x0, 0x80000000}};
  // -5.06
  s21_decimal dec_2 = {{0x1fa, 0x0, 0x0, 0x80020000}};
  // 45798286533551519659.78
  s21_decimal dec_check = {{0x1d70bf1a, 0x45e3e741, 0xf8, 0x20000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_456) {
  // 69706951253
  s21_decimal dec_1 = {{0x3adbaa55, 0x10, 0x0, 0x0}};
  // 279
  s21_decimal dec_2 = {{0x117, 0x0, 0x0, 0x0}};
  // 19448239399587
  s21_decimal dec_check = {{0x2566a2a3, 0x11b0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_457) {
  // -945.95
  s21_decimal dec_1 = {{0x17183, 0x0, 0x0, 0x80020000}};
  // 4973352773208.68808360
  s21_decimal dec_2 = {{0x64c546a8, 0xf5e9d7ba, 0x1a, 0x80000}};
  // -4704543055816758.4926814200
  s21_decimal dec_check = {{0xebcb4ff8, 0xe69d0fa1, 0x26ea41, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_458) {
  // 96957.34476263
  s21_decimal dec_1 = {{0x76cf2de7, 0x8d1, 0x0, 0x80000}};
  // -308707256477522244218
  s21_decimal dec_2 = {{0x481eb27a, 0xbc2c7e2a, 0x10, 0x80000000}};
  // -29931435897016767507749426.100
  s21_decimal dec_check = {{0x397053b4, 0x41ffcfc3, 0x60b6b417, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_459) {
  // -783368115781003574749203
  s21_decimal dec_1 = {{0x20efa813, 0x787c78aa, 0xa5e2, 0x80000000}};
  // -79.78257
  s21_decimal dec_2 = {{0x79bd11, 0x0, 0x0, 0x80050000}};
  // 62499121533066022372678520.792
  s21_decimal dec_check = {{0x468f4fd8, 0x3ab29782, 0xc9f20fc7, 0x30000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_460) {
  // -5130530.977
  s21_decimal dec_1 = {{0x31cdb0a1, 0x1, 0x0, 0x80030000}};
  // -0.2888065961847
  s21_decimal dec_2 = {{0x6e254f77, 0x2a0, 0x0, 0x800d0000}};
  // 1481731.1880875333634519
  s21_decimal dec_check = {{0x5563c9d7, 0x3f829a2c, 0x323, 0x100000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_461) {
  // -8694215372933619
  s21_decimal dec_1 = {{0xc2e789f3, 0x1ee357, 0x0, 0x80000000}};
  // 6753673061
  s21_decimal dec_2 = {{0x928cdf65, 0x1, 0x0, 0x0}};
  // -58717888150713851181537759
  s21_decimal dec_check = {{0x9d6819df, 0x184751a6, 0x3091ff, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_462) {
  // 441661822637
  s21_decimal dec_1 = {{0xd51896ad, 0x66, 0x0, 0x0}};
  // -9767269519871
  s21_decimal dec_2 = {{0x1ea151ff, 0x8e2, 0x0, 0x80000000}};
  // -4313830058333041749119827
  s21_decimal dec_check = {{0x13f7d353, 0x323042b4, 0x3917d, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_463) {
  // 50.886
  s21_decimal dec_1 = {{0xc6c6, 0x0, 0x0, 0x30000}};
  // -2858442374601742390154
  s21_decimal dec_2 = {{0x4ea938a, 0xf4db5306, 0x9a, 0x80000000}};
  // -145454698673984263265376.444
  s21_decimal dec_check = {{0x3b8ad8bc, 0x3d8de75, 0x78513b, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_464) {
  // 90740214081615277988212
  s21_decimal dec_1 = {{0x68e61974, 0x96fc8f8, 0x1337, 0x0}};
  // 516.6
  s21_decimal dec_2 = {{0x142e, 0x0, 0x0, 0x10000}};
  // 46876394594562452608710319.2
  s21_decimal dec_check = {{0xd355a2d8, 0x6dc984d4, 0x183c0a0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_465) {
  // 9837164594947753127790
  s21_decimal dec_1 = {{0xbe3a2f6e, 0x46153792, 0x215, 0x0}};
  // 0.390885302997953459
  s21_decimal dec_2 = {{0xb11d2bb3, 0x56cb41c, 0x0, 0x120000}};
  // 3845203063336892589858.0829007
  s21_decimal dec_check = {{0x1e5e234f, 0x7579ac2a, 0x7c3ec635, 0x70000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_466) {
  // -537580171
  s21_decimal dec_1 = {{0x200ad28b, 0x0, 0x0, 0x80000000}};
  // 1194298751831
  s21_decimal dec_2 = {{0x11c0bb57, 0x116, 0x0, 0x0}};
  // -642031327234395543101
  s21_decimal dec_check = {{0xeeb9163d, 0xcdf97a7d, 0x22, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_467) {
  // -0.873325028655284
  s21_decimal dec_1 = {{0xd41b40b4, 0x31a48, 0x0, 0x800f0000}};
  // 4856422813907508769181171412
  s21_decimal dec_2 = {{0x65ec7ed4, 0x447006a8, 0xfb12388, 0x0}};
  // -4241235593117950052443960036.8
  s21_decimal dec_check = {{0x48c3fcf0, 0xa68f7f1, 0x890aadb6, 0x80010000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_468) {
  // 0.0598312869
  s21_decimal dec_1 = {{0x23a987a5, 0x0, 0x0, 0xa0000}};
  // -1.089
  s21_decimal dec_2 = {{0x441, 0x0, 0x0, 0x80030000}};
  // -0.0651562714341
  s21_decimal dec_check = {{0xb42a04e5, 0x97, 0x0, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_469) {
  // -380436466062279521714350
  s21_decimal dec_1 = {{0x11e9c0ae, 0x808ce4dc, 0x508f, 0x80000000}};
  // 2.054
  s21_decimal dec_2 = {{0x806, 0x0, 0x0, 0x30000}};
  // -781416501291922137601274.900
  s21_decimal dec_check = {{0xb97ff414, 0x6a743db7, 0x2865f61, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_470) {
  // -860.5
  s21_decimal dec_1 = {{0x219d, 0x0, 0x0, 0x80010000}};
  // -17280202237
  s21_decimal dec_2 = {{0x5faf5fd, 0x4, 0x0, 0x80000000}};
  // 14869614024938.5
  s21_decimal dec_check = {{0x49e7929, 0x873d, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_471) {
  // -578746644.537649611
  s21_decimal dec_1 = {{0xc29da9cb, 0x8081f01, 0x0, 0x80090000}};
  // 17.8587695807423995
  s21_decimal dec_2 = {{0x29db65fb, 0x27a7890, 0x0, 0x100000}};
  // -10335702970.425711257157062182
  s21_decimal dec_check = {{0x7e634e26, 0xbc2a64c9, 0x21657e3c, 0x80120000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_472) {
  // -624693968084028136494
  s21_decimal dec_1 = {{0xb1b49c2e, 0xdd5ece33, 0x21, 0x80000000}};
  // -20278
  s21_decimal dec_2 = {{0x4f36, 0x0, 0x0, 0x80000000}};
  // 12667544284807922551825332
  s21_decimal dec_check = {{0x384b23b4, 0xf3a172be, 0xa7a74, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_473) {
  // -791212934836179339895
  s21_decimal dec_1 = {{0x2cc28a77, 0xe4490435, 0x2a, 0x80000000}};
  // 0.214361927685958152814651
  s21_decimal dec_2 = {{0xe495003b, 0x9558b435, 0x2d64, 0x180000}};
  // -169605929921547795880.76458898
  s21_decimal dec_check = {{0xd3475392, 0x6fd433dc, 0x36cd7944, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_474) {
  // 3953450708586728
  s21_decimal dec_1 = {{0x791f50e8, 0xe0ba4, 0x0, 0x0}};
  // 80
  s21_decimal dec_2 = {{0x50, 0x0, 0x0, 0x0}};
  // 316276056686938240
  s21_decimal dec_check = {{0xd9c94880, 0x463a365, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_475) {
  // 6004
  s21_decimal dec_1 = {{0x1774, 0x0, 0x0, 0x0}};
  // 1267914
  s21_decimal dec_2 = {{0x1358ca, 0x0, 0x0, 0x0}};
  // 7612555656
  s21_decimal dec_check = {{0xc5be6188, 0x1, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_476) {
  // 612729403
  s21_decimal dec_1 = {{0x2485823b, 0x0, 0x0, 0x0}};
  // -7836306037883102
  s21_decimal dec_2 = {{0x2dbd40de, 0x1bd714, 0x0, 0x80000000}};
  // -4801535120317408472248106
  s21_decimal dec_check = {{0x90e4af2a, 0xbd8d3152, 0x3f8c3, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_477) {
  // 82355
  s21_decimal dec_1 = {{0x141b3, 0x0, 0x0, 0x0}};
  // -8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -658840
  s21_decimal dec_check = {{0xa0d98, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_478) {
  // 1.26026534212337899894
  s21_decimal dec_1 = {{0x20039976, 0xd4f83126, 0x6, 0x140000}};
  // -5543083773180828
  s21_decimal dec_2 = {{0xc342bb9c, 0x13b167, 0x0, 0x80000000}};
  // -6985756367826286.7542387845782
  s21_decimal dec_check = {{0x84b9ea96, 0x39d18683, 0xe1b8d283, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_479) {
  // 4557136458478
  s21_decimal dec_1 = {{0xa7ff2ee, 0x425, 0x0, 0x0}};
  // -6819.92295035
  s21_decimal dec_2 = {{0xc9e8927b, 0x9e, 0x0, 0x80080000}};
  // -31079319521050832.03056730
  s21_decimal dec_check = {{0x9b5745a, 0x5427065e, 0x29221, 0x80080000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_480) {
  // 94420
  s21_decimal dec_1 = {{0x170d4, 0x0, 0x0, 0x0}};
  // 180870212.18449521307180
  s21_decimal dec_2 = {{0xcca2ee2c, 0x7fd7b108, 0x3d4, 0xe0000}};
  // 17077765434460.03801823935600
  s21_decimal dec_check = {{0xad4c7c70, 0xed1b4173, 0x584a3bf, 0xe0000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_481) {
  // 0.04082585
  s21_decimal dec_1 = {{0x3e4b99, 0x0, 0x0, 0x80000}};
  // -9363302941004.554408976136
  s21_decimal dec_2 = {{0xe36a5f08, 0xab654284, 0x7bec1, 0x800c0000}};
  // -382264801374.01078761769838192
  s21_decimal dec_check = {{0xd4c2a670, 0x927c76fa, 0x7b843408, 0x80110000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_482) {
  // -85935673779146.69716
  s21_decimal dec_1 = {{0xe1fd2a94, 0x77427bff, 0x0, 0x80050000}};
  // -26
  s21_decimal dec_2 = {{0x1a, 0x0, 0x0, 0x80000000}};
  // 2234327518257814.12616
  s21_decimal dec_check = {{0xf3b65308, 0x1cc097fc, 0xc, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_483) {
  // -5.690
  s21_decimal dec_1 = {{0x163a, 0x0, 0x0, 0x80030000}};
  // 421046942148798365577
  s21_decimal dec_2 = {{0xff92bf89, 0xd3333b14, 0x16, 0x0}};
  // -2395757100826662700133.130
  s21_decimal dec_check = {{0x83b52b0a, 0x40af30b8, 0x1fb52, 0x80030000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_484) {
  // 53196883024581723030595
  s21_decimal dec_1 = {{0xf93a0443, 0xcf0dfdb0, 0xb43, 0x0}};
  // 6778
  s21_decimal dec_2 = {{0x1a7a, 0x0, 0x0, 0x0}};
  // 360568473140614918701372910
  s21_decimal dec_check = {{0xaa14d5ee, 0x186edfa6, 0x12a4158, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_486) {
  // 97097621673103759
  s21_decimal dec_1 = {{0xc05c518f, 0x158f5c5, 0x0, 0x0}};
  // -4.57
  s21_decimal dec_2 = {{0x1c9, 0x0, 0x0, 0x80020000}};
  // -443736131046084178.63
  s21_decimal dec_check = {{0x64cd9847, 0x67cebe04, 0x2, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_487) {
  // 77330
  s21_decimal dec_1 = {{0x12e12, 0x0, 0x0, 0x0}};
  // -9766037.3280
  s21_decimal dec_2 = {{0xbd030920, 0x16, 0x0, 0x80040000}};
  // -755207666574.2400
  s21_decimal dec_check = {{0xdefa6440, 0x1ad492, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_488) {
  // -95.0003
  s21_decimal dec_1 = {{0xe7ef3, 0x0, 0x0, 0x80040000}};
  // -8491993640
  s21_decimal dec_2 = {{0xfa298a28, 0x1, 0x0, 0x80000000}};
  // 806741943398.0920
  s21_decimal dec_check = {{0x759dd3f8, 0x1ca946, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_489) {
  // -32650.8342681872322852715
  s21_decimal dec_1 = {{0x90f4f76b, 0xd7f49d2, 0x4524, 0x80130000}};
  // 483.53856150
  s21_decimal dec_2 = {{0x421d4a96, 0xb, 0x0, 0x80000}};
  // -15787937.433814159511886538747
  s21_decimal dec_check = {{0xb344a7fb, 0x3d860af4, 0x330379cb, 0x80150000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_490) {
  // 66019.5090
  s21_decimal dec_1 = {{0x2759c712, 0x0, 0x0, 0x40000}};
  // 418531148467133997.240352
  s21_decimal dec_2 = {{0x1465d020, 0x9e7829cc, 0x58a0, 0x60000}};
  // 27631220923006289135015.394027
  s21_decimal dec_check = {{0x80957aeb, 0xa8530bdb, 0x5948029f, 0x60000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_491) {
  // -1883452378497457496850351602
  s21_decimal dec_1 = {{0xa5c6c5f2, 0x6e94176, 0x615f48e, 0x80000000}};
  // 9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x0}};
  // -16951071406477117471653164418
  s21_decimal dec_check = {{0xd3fcf582, 0x3e334d2b, 0x36c598fe, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_492) {
  // 2080255048.975527842
  s21_decimal dec_1 = {{0x4662fa2, 0x1cde8cf2, 0x0, 0x90000}};
  // 726281190
  s21_decimal dec_2 = {{0x2b4a2be6, 0x0, 0x0, 0x0}};
  // 1510850112473454641.965891980
  s21_decimal dec_check = {{0x18a3018c, 0xb651b7b7, 0x4e1bef4, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_493) {
  // 7617330
  s21_decimal dec_1 = {{0x743b32, 0x0, 0x0, 0x0}};
  // 893000120414068560
  s21_decimal dec_2 = {{0xd1a95f50, 0xc6492e0, 0x0, 0x0}};
  // 6802276607233696864144800
  s21_decimal dec_check = {{0x2c4c0da0, 0x275d80fa, 0x5a070, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_494) {
  // 3456808107237781.26145225312
  s21_decimal dec_1 = {{0xed7d8260, 0x4c7536a3, 0x11df0c2, 0xb0000}};
  // -5753386263527
  s21_decimal dec_2 = {{0x908b63e7, 0x53b, 0x0, 0x80000000}};
  // -19888352279830619456752515256
  s21_decimal dec_check = {{0xf93ef8b8, 0x728d5ea7, 0x40434269, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_495) {
  // -394917
  s21_decimal dec_1 = {{0x606a5, 0x0, 0x0, 0x80000000}};
  // 8377333261131
  s21_decimal dec_2 = {{0x7ff9234b, 0x79e, 0x0, 0x0}};
  // -3308351319486071127
  s21_decimal dec_check = {{0x26298157, 0x2de99fff, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_496) {
  // 861013170228993917958
  s21_decimal dec_1 = {{0xe01f0406, 0xacf5447a, 0x2e, 0x0}};
  // 672.3508287562049399198212928
  s21_decimal dec_2 = {{0xf30a6340, 0x9ade398c, 0x15b98e42, 0x190000}};
  // 578902918573471423009216.57834
  s21_decimal dec_check = {{0x2c9679ea, 0xe0b6731e, 0xbb0dba21, 0x50000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_497) {
  // -12493528.51806760436
  s21_decimal dec_1 = {{0xa3102df4, 0x115697cc, 0x0, 0x800b0000}};
  // -5671579321202.575567428
  s21_decimal dec_2 = {{0x929a6a44, 0x74f96f51, 0x133, 0x80090000}};
  // 70858037991926883396.910884463
  s21_decimal dec_check = {{0x1850a66f, 0x720437ad, 0xe4f46530, 0x90000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_498) {
  // -9.5232504803197
  s21_decimal dec_1 = {{0xb9eaf7d, 0x569d, 0x0, 0x800d0000}};
  // -0.284202756
  s21_decimal dec_2 = {{0x10f09704, 0x0, 0x0, 0x80090000}};
  // 2.7065340325851825010932
  s21_decimal dec_check = {{0x1d2d78f4, 0x370ccc0b, 0x5bb, 0x160000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_499) {
  // 7592718605969683564
  s21_decimal dec_1 = {{0x1c52746c, 0x695ec158, 0x0, 0x0}};
  // -1564535.01
  s21_decimal dec_2 = {{0x9534a7d, 0x0, 0x0, 0x80020000}};
  // -11879074080117964934499575.64
  s21_decimal dec_check = {{0x34ee10bc, 0x9fb7f509, 0x3d69d2d, 0x80020000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_500) {
  // -20604984962848743
  s21_decimal dec_1 = {{0xe95017e7, 0x49341f, 0x0, 0x80000000}};
  // -2.4
  s21_decimal dec_2 = {{0x18, 0x0, 0x0, 0x80010000}};
  // 49451963910836983.2
  s21_decimal dec_check = {{0xdf823da8, 0x6dce2fd, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_501) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // -718426857994283616
  s21_decimal dec_2 = {{0xc3d96a60, 0x9f85d6b, 0x0, 0x80000000}};
  // 0
  s21_decimal dec_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(fail_s21_mul_1) {
  // -1379642392299.987919
  s21_decimal dec_1 = {{0x361c63cf, 0x13257972, 0x0, 0x80060000}};
  // -1130965219032422494424270
  s21_decimal dec_2 = {{0x9346ccce, 0xbf53e772, 0xef7d, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_2) {
  // -50971396313118062046933617
  s21_decimal dec_1 = {{0xb6a0f271, 0xee4d2d0b, 0x2a299c, 0x80000000}};
  // 613330049485462.498
  s21_decimal dec_2 = {{0x31a75be2, 0x882fc6e, 0x0, 0x30000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_3) {
  // 642711670378293531953380595
  s21_decimal dec_1 = {{0xb100bcf3, 0x771daea1, 0x213a37d, 0x0}};
  // -32080100232
  s21_decimal dec_2 = {{0x781f7b88, 0x7, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_4) {
  // 762808742655.6482674179698556
  s21_decimal dec_1 = {{0xb6ebef7c, 0xfd3553d7, 0x18a5ce57, 0x100000}};
  // -346603758447950232215367
  s21_decimal dec_2 = {{0x9b02df47, 0x6d69c2fe, 0x4965, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_5) {
  // -96590786026934796514.3953562
  s21_decimal dec_1 = {{0x1131309a, 0x6b7d5de, 0x31efaf2, 0x80070000}};
  // -523270578893843742471523
  s21_decimal dec_2 = {{0x9b463563, 0x8e0f599a, 0x6ece, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_6) {
  // 689681449916347559.79
  s21_decimal dec_1 = {{0x406918b, 0xbd201276, 0x3, 0x20000}};
  // -751061542285847657370612
  s21_decimal dec_2 = {{0xee8ad3f4, 0x20b6e661, 0x9f0b, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_7) {
  // -41255176482838484321169
  s21_decimal dec_1 = {{0x450b8391, 0x7295cfd9, 0x8bc, 0x80000000}};
  // 685604733477498704250277
  s21_decimal dec_2 = {{0xc31245a5, 0xb502e039, 0x912e, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_8) {
  // 481354851194214806
  s21_decimal dec_1 = {{0xd4579996, 0x6ae1daf, 0x0, 0x0}};
  // -1877724496386
  s21_decimal dec_2 = {{0x311a0202, 0x1b5, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_9) {
  // -26365436911
  s21_decimal dec_1 = {{0x2380a3ef, 0x6, 0x0, 0x80000000}};
  // 6999834810495626500469853814
  s21_decimal dec_2 = {{0xbc6e8e76, 0x6dcfb978, 0x169e20ad, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_10) {
  // 178675478.69544
  s21_decimal dec_1 = {{0x1cd80168, 0x1040, 0x0, 0x50000}};
  // 2231944365548913407086144.191
  s21_decimal dec_2 = {{0x9065aabf, 0x7fef5486, 0x736389a, 0x30000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_11) {
  // -96068423324867032.5583
  s21_decimal dec_1 = {{0x69819b4f, 0x142c0437, 0x34, 0x80040000}};
  // 26686780960349427212
  s21_decimal dec_2 = {{0xc49160c, 0x725a7de4, 0x1, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_12) {
  // 95875498835597245846234
  s21_decimal dec_1 = {{0xef5492da, 0x6bd42ccf, 0x144d, 0x0}};
  // 69299468211284339277002808914
  s21_decimal dec_2 = {{0x685d9e52, 0x56965ad4, 0xdfeb2d33, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_13) {
  // -179026011125667.0928142940
  s21_decimal dec_1 = {{0xf1e0825c, 0x31f1df5a, 0x17b1a, 0x800a0000}};
  // 97512927667085960323799
  s21_decimal dec_2 = {{0xdb1ca2d7, 0x2fb7fb94, 0x14a6, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_14) {
  // 54282786.972383011961
  s21_decimal dec_1 = {{0x1b176479, 0xf1533326, 0x2, 0xc0000}};
  // -9663959436450952070784329673
  s21_decimal dec_2 = {{0x1483a7c9, 0xca647a4b, 0x1f39d702, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_15) {
  // -28076866637506544775075
  s21_decimal dec_1 = {{0x81d1afa3, 0xccc2932, 0x5f2, 0x80000000}};
  // -359805189921310.565
  s21_decimal dec_2 = {{0xf59a0765, 0x4fe48e9, 0x0, 0x80030000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_16) {
  // -3647485568822350906.3455
  s21_decimal dec_1 = {{0x1666271f, 0x4e4ebc5f, 0x7b9, 0x80040000}};
  // -95989666180527563974
  s21_decimal dec_2 = {{0xeeac24c6, 0x341fccd0, 0x5, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_17) {
  // 525082205240762357707730
  s21_decimal dec_1 = {{0xf9eaf3d2, 0xc36d0db7, 0x6f30, 0x0}};
  // -45136674294550
  s21_decimal dec_2 = {{0x33700b16, 0x290d, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_18) {
  // -1142947120711.00
  s21_decimal dec_1 = {{0x4fb673bc, 0x67f3, 0x0, 0x80020000}};
  // -371426288223032299.8736785
  s21_decimal dec_2 = {{0x1202f791, 0x98245c53, 0x31286, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_19) {
  // -953479386083343409048318
  s21_decimal dec_1 = {{0x4f536afe, 0x38996481, 0xc9e8, 0x80000000}};
  // -182917
  s21_decimal dec_2 = {{0x2ca85, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_20) {
  // 6277547.60236
  s21_decimal dec_1 = {{0x2919782c, 0x92, 0x0, 0x50000}};
  // 77835131942832968862226761
  s21_decimal dec_2 = {{0x389b5949, 0xf5188b64, 0x40623a, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_21) {
  // -7290891306949075839097534
  s21_decimal dec_1 = {{0x16d21abe, 0x27cd87c, 0x607e8, 0x80000000}};
  // -13061095353653
  s21_decimal dec_2 = {{0x5f2ed35, 0xbe1, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_22) {
  // 318751214250967171306390082
  s21_decimal dec_1 = {{0xaf88242, 0xf2dbae24, 0x107aa31, 0x0}};
  // 334760066
  s21_decimal dec_2 = {{0x13f40882, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_23) {
  // -83192949222170520148147005
  s21_decimal dec_1 = {{0xe5b27b3d, 0xd0695c56, 0x44d0ca, 0x80000000}};
  // -25549326773
  s21_decimal dec_2 = {{0xf2dbc9b5, 0x5, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_24) {
  // -79193508846718174749012062
  s21_decimal dec_1 = {{0x4ed8305e, 0xb787f1b3, 0x4181e0, 0x80000000}};
  // -28201087430872259.448208
  s21_decimal dec_2 = {{0xa714d90, 0xc8b5129d, 0x5f8, 0x80060000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_25) {
  // -19311911294.534528
  s21_decimal dec_1 = {{0xbca50380, 0x449c14, 0x0, 0x80060000}};
  // 466754275424305575627912553
  s21_decimal dec_2 = {{0xdd30f569, 0xf8ba8c01, 0x182170f, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_26) {
  // -23980575145939042605
  s21_decimal dec_1 = {{0x6b42012d, 0x4ccc1e0a, 0x1, 0x80000000}};
  // -6647657145
  s21_decimal dec_2 = {{0x8c3b32b9, 0x1, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_27) {
  // 79228162514264337592077334192
  s21_decimal dec_1 = {{0xa89536b0, 0xffffffff, 0xffffffff, 0x0}};
  // 16300372874880
  s21_decimal dec_2 = {{0x39ef5680, 0xed3, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_28) {
  // 846713149.4563833896751053
  s21_decimal dec_1 = {{0x9437cfcd, 0x1e38f080, 0x700fc, 0x100000}};
  // 39578789287392348454025484585
  s21_decimal dec_2 = {{0xbc98d929, 0x7ca186e3, 0x7fe2cea2, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_29) {
  // 45539303
  s21_decimal dec_1 = {{0x2b6dfe7, 0x0, 0x0, 0x0}};
  // 6886821002845090803967888
  s21_decimal dec_2 = {{0x6a2d6790, 0x508c4222, 0x5b257, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_30) {
  // -18493128094029447343965
  s21_decimal dec_1 = {{0x55e2af5d, 0x83b524ba, 0x3ea, 0x80000000}};
  // 3456304839297265724
  s21_decimal dec_2 = {{0x65c6f03c, 0x2ff742f0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_31) {
  // 32316220384075
  s21_decimal dec_1 = {{0x34d6234b, 0x1d64, 0x0, 0x0}};
  // -79327151305837847312.82525
  s21_decimal dec_2 = {{0x10218c5d, 0x595273e5, 0x68fd1, 0x80050000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_32) {
  // 731470085161
  s21_decimal dec_1 = {{0x4f03bc29, 0xaa, 0x0, 0x0}};
  // -3094322120241025057
  s21_decimal dec_2 = {{0xed999021, 0x2af13d92, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_33) {
  // -3788835598263.14641
  s21_decimal dec_1 = {{0x1aaed591, 0x5421097, 0x0, 0x80050000}};
  // 65423251347648556518279217636
  s21_decimal dec_2 = {{0xb33801e4, 0x1bfa5558, 0xd364d85a, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_34) {
  // 31366238.00650
  s21_decimal dec_1 = {{0x4d58f14a, 0x2da, 0x0, 0x50000}};
  // -867497083690878867757474.78
  s21_decimal dec_2 = {{0x9edb0396, 0x1d22d015, 0x47c1f7, 0x80020000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_35) {
  // -85454675591159314905.970
  s21_decimal dec_1 = {{0x3ed3fb72, 0x81dae3e2, 0x1218, 0x80030000}};
  // 19783600519465
  s21_decimal dec_2 = {{0x3a7b3929, 0x11fe, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_36) {
  // -29622580926022798206552.4
  s21_decimal dec_1 = {{0x4b9cff74, 0x6eec9293, 0x3eba, 0x80010000}};
  // -4880692367987481483750383
  s21_decimal dec_2 = {{0x6ff12bef, 0xdd09c42e, 0x40986, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_37) {
  // 77624657796362798
  s21_decimal dec_1 = {{0x9c3722e, 0x113c737, 0x0, 0x0}};
  // 2155833516573
  s21_decimal dec_2 = {{0xf1b0e21d, 0x1f5, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_38) {
  // -5388657672434
  s21_decimal dec_1 = {{0xa506c0f2, 0x4e6, 0x0, 0x80000000}};
  // 3144208441634614686.109712
  s21_decimal dec_2 = {{0xb721d010, 0xe1939865, 0x299cf, 0x60000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_39) {
  // 5865436790458.635
  s21_decimal dec_1 = {{0x6c59090b, 0x14d695, 0x0, 0x30000}};
  // -405473882497310555
  s21_decimal dec_2 = {{0xbf35f5b, 0x5a08859, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_40) {
  // 125825941521054983
  s21_decimal dec_1 = {{0xf3e43d07, 0x1bf0606, 0x0, 0x0}};
  // -92167507649990010914
  s21_decimal dec_2 = {{0x1ec0a822, 0xff14c3e2, 0x4, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_41) {
  // 50581423857024131926781674
  s21_decimal dec_1 = {{0x8ccaeeea, 0x7b4e0e3d, 0x29d708, 0x0}};
  // -9380611817
  s21_decimal dec_2 = {{0x2f20c6e9, 0x2, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_42) {
  // 7239880255746799
  s21_decimal dec_1 = {{0xfadc32ef, 0x19b8a1, 0x0, 0x0}};
  // -60237973583302049215062682150
  s21_decimal dec_2 = {{0xf05b2a26, 0x41cc6a9e, 0xc2a3af13, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_43) {
  // -6622064318501525652467544
  s21_decimal dec_1 = {{0xc0af6f58, 0xd3763cb1, 0x57a46, 0x80000000}};
  // 517766921040365917133106
  s21_decimal dec_2 = {{0xb0a15932, 0x3376cf7e, 0x6da4, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_44) {
  // 90283032884473
  s21_decimal dec_1 = {{0xa81ab4f9, 0x521c, 0x0, 0x0}};
  // -85997751234226247662005521
  s21_decimal dec_2 = {{0x89736d11, 0x6f93eb12, 0x4722bb, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_45) {
  // -38704679773628117
  s21_decimal dec_1 = {{0x810d66d5, 0x8981b3, 0x0, 0x80000000}};
  // 461640984796925610073
  s21_decimal dec_2 = {{0x46414859, 0x68e3dcb, 0x19, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_46) {
  // 91882344838634562406775598
  s21_decimal dec_1 = {{0x213efb2e, 0xe4f47b4b, 0x4c00d7, 0x0}};
  // 8356214709.451954610015
  s21_decimal dec_2 = {{0xa1bc5f5f, 0xfdc64d1f, 0x1c4, 0xc0000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_47) {
  // -88091481
  s21_decimal dec_1 = {{0x5402b59, 0x0, 0x0, 0x80000000}};
  // -400846050682098446679264
  s21_decimal dec_2 = {{0xa0dabce0, 0xe86f59f8, 0x54e1, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_48) {
  // -774052957.20149
  s21_decimal dec_1 = {{0x5327b6d5, 0x4666, 0x0, 0x80050000}};
  // -74523266028994014205133
  s21_decimal dec_2 = {{0x3bb7d4cd, 0xea129c2f, 0xfc7, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_49) {
  // -45475281733255685460079632
  s21_decimal dec_1 = {{0x52063410, 0xf6650b45, 0x259dc3, 0x80000000}};
  // -85474904206195
  s21_decimal dec_2 = {{0x2d4d6b73, 0x4dbd, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_50) {
  // 68552491688175369831176
  s21_decimal dec_1 = {{0x6b4dc308, 0x3ceeefba, 0xe84, 0x0}};
  // 524229277627.54718817823409612
  s21_decimal dec_2 = {{0xcb2c5cc, 0x6be53b1c, 0xa9633ac0, 0x110000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_51) {
  // 16824127355799235912
  s21_decimal dec_1 = {{0x2a586d48, 0xe97b4eb1, 0x0, 0x0}};
  // 639570025914925
  s21_decimal dec_2 = {{0x8034222d, 0x245af, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_52) {
  // -20541.360372733
  s21_decimal dec_1 = {{0xa87cfbfd, 0x12ae, 0x0, 0x80090000}};
  // 166563924456426561304126857
  s21_decimal dec_2 = {{0x3965e589, 0x700b0a39, 0x89c748, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_53) {
  // -160458338559817691233154
  s21_decimal dec_1 = {{0xe19cfb82, 0x76c64770, 0x21fa, 0x80000000}};
  // -6692894872822378235925541
  s21_decimal dec_2 = {{0x3c7b9425, 0x8edd7326, 0x58946, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_54) {
  // -400229057111213586307
  s21_decimal dec_1 = {{0x2f69b783, 0xb24b3ef0, 0x15, 0x80000000}};
  // -78091078420803
  s21_decimal dec_2 = {{0xfefd4943, 0x4705, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_55) {
  // -50117208016063912
  s21_decimal dec_1 = {{0xccee8da8, 0xb20d55, 0x0, 0x80000000}};
  // 45037054972969664545046268
  s21_decimal dec_2 = {{0x9a83efc, 0xa4675c05, 0x2540f7, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_56) {
  // 5172528404781
  s21_decimal dec_1 = {{0x52b7d92d, 0x4b4, 0x0, 0x0}};
  // -370049131517239716.764
  s21_decimal dec_2 = {{0xb6e16b9c, 0xf769c82, 0x14, 0x80030000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_57) {
  // -66291459334054982359423659528
  s21_decimal dec_1 = {{0x82b42e08, 0x5c604826, 0xd633028b, 0x80000000}};
  // 51
  s21_decimal dec_2 = {{0x33, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_58) {
  // 9741294801393340069098
  s21_decimal dec_1 = {{0x816734ea, 0x139f4a46, 0x210, 0x0}};
  // 9711119971764025488509
  s21_decimal dec_2 = {{0xc42cf47d, 0x70dcc299, 0x20e, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_59) {
  // -8230678110027150496766815919
  s21_decimal dec_1 = {{0x11faeeaf, 0x65614fdf, 0x1a9841e2, 0x80000000}};
  // -332796921424
  s21_decimal dec_2 = {{0x7c3e0650, 0x4d, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_60) {
  // -665182784773164957562694167
  s21_decimal dec_1 = {{0xd94dea17, 0x47e3b92, 0x22639ef, 0x80000000}};
  // 6783578.610473386462824
  s21_decimal dec_2 = {{0x24214e68, 0xbd108549, 0x16f, 0xf0000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_61) {
  // -135057074
  s21_decimal dec_1 = {{0x80cceb2, 0x0, 0x0, 0x80000000}};
  // -441430451348835344772818512.78
  s21_decimal dec_2 = {{0x98a9f78e, 0xc4b0a2f3, 0x8ea24567, 0x80020000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_62) {
  // 69834407460469287251098051
  s21_decimal dec_1 = {{0x52d039c3, 0xd06bbcab, 0x39c402, 0x0}};
  // -350699581010413046799122365
  s21_decimal dec_2 = {{0x4651bfbd, 0x618d4c80, 0x1221786, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_63) {
  // -82824317589209634
  s21_decimal dec_1 = {{0x2cab4222, 0x1264047, 0x0, 0x80000000}};
  // 81655218874363266658996
  s21_decimal dec_2 = {{0x9a6ef2b4, 0x89cd0a57, 0x114a, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_64) {
  // 16006649356731164
  s21_decimal dec_1 = {{0x78f3c31c, 0x38ddf6, 0x0, 0x0}};
  // 36543947568797556.2194
  s21_decimal dec_2 = {{0xf6c82bd2, 0xcf7dd2f4, 0x13, 0x40000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_65) {
  // -4896
  s21_decimal dec_1 = {{0x1320, 0x0, 0x0, 0x80000000}};
  // 72108246107277921721001798
  s21_decimal dec_2 = {{0x9e042746, 0xdaaba3a5, 0x3ba583, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_66) {
  // -904377194709016656760.59531476
  s21_decimal dec_1 = {{0xb1a8d8d4, 0x3fd2bfc6, 0x24385404, 0x80080000}};
  // -84751851505258547639
  s21_decimal dec_2 = {{0xd39749b7, 0x982b0fe8, 0x4, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_67) {
  // 39859908852.48368691
  s21_decimal dec_1 = {{0x692c8033, 0x37511597, 0x0, 0x80000}};
  // -30827763930851987211040428.064
  s21_decimal dec_2 = {{0xa6659020, 0x55c28e09, 0x639c20ef, 0x80030000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_68) {
  // -2720363864192
  s21_decimal dec_1 = {{0x62526080, 0x279, 0x0, 0x80000000}};
  // 3045896452004933273
  s21_decimal dec_2 = {{0x6c606e99, 0x2a4532af, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_69) {
  // -8497846899549754007277521726
  s21_decimal dec_1 = {{0xb78bcb3e, 0x7f3ed662, 0x1b754113, 0x80000000}};
  // 3543
  s21_decimal dec_2 = {{0xdd7, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_70) {
  // 63988.67592444304205775837229
  s21_decimal dec_1 = {{0x29b182d, 0x423e1bc4, 0x14ad04eb, 0x170000}};
  // -5899221197369799190323679
  s21_decimal dec_2 = {{0xd45521df, 0x6c022a61, 0x4e135, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_71) {
  // 440748008020753
  s21_decimal dec_1 = {{0xa4741b11, 0x190db, 0x0, 0x0}};
  // 5590527514021385478277559
  s21_decimal dec_2 = {{0xd8ff09b7, 0x1a92c63a, 0x49fd7, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_72) {
  // 9201465732
  s21_decimal dec_1 = {{0x24733984, 0x2, 0x0, 0x0}};
  // 13069654306860013031
  s21_decimal dec_2 = {{0x998b95e7, 0xb560bd58, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_73) {
  // 131505443874161576
  s21_decimal dec_1 = {{0x242643a8, 0x1d33381, 0x0, 0x0}};
  // -3557417449894810609262313
  s21_decimal dec_2 = {{0x43ac1ee9, 0xfc8371e4, 0x2f14f, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_74) {
  // -8472782.148
  s21_decimal dec_1 = {{0xf9046544, 0x1, 0x0, 0x80030000}};
  // -41718407287203917276389.57568
  s21_decimal dec_2 = {{0x4d6cce00, 0x112dfc4a, 0xd7adda3, 0x80050000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_75) {
  // 37420369850390728446367513
  s21_decimal dec_1 = {{0x73f8d719, 0x507941ca, 0x1ef412, 0x0}};
  // -74425529560.74513121
  s21_decimal dec_2 = {{0x30dad2e1, 0x6749427b, 0x0, 0x80080000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_76) {
  // 2305804877725886
  s21_decimal dec_1 = {{0x8a880be, 0x8311e, 0x0, 0x0}};
  // -4341480844989768.06708879600
  s21_decimal dec_2 = {{0xa65aa0f0, 0xd1d88cf5, 0x1671e6e, 0x800b0000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_77) {
  // 397737219638317568633649
  s21_decimal dec_1 = {{0xfec22b31, 0x60bcc6f1, 0x5439, 0x0}};
  // 274569213312.655404
  s21_decimal dec_2 = {{0xa9c2602c, 0x3cf773e, 0x0, 0x60000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_78) {
  // 580897575395336496766
  s21_decimal dec_1 = {{0x44b9a67e, 0x7d92c318, 0x1f, 0x0}};
  // -9373182435144475168
  s21_decimal dec_2 = {{0x75b7a220, 0x82143bc3, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_79) {
  // -5688
  s21_decimal dec_1 = {{0x1638, 0x0, 0x0, 0x80000000}};
  // 64650663770902178166955970455
  s21_decimal dec_2 = {{0x22ae0f97, 0xa6f024a9, 0xd0e5c691, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_80) {
  // 27700276604070086568967
  s21_decimal dec_1 = {{0xdd3fec07, 0xa28f990b, 0x5dd, 0x0}};
  // -549125880659583378207986703
  s21_decimal dec_2 = {{0xdeb6d40f, 0xa392ac5d, 0x1c639ed, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_81) {
  // -968839711910591418
  s21_decimal dec_1 = {{0xb8b8fbba, 0xd720295, 0x0, 0x80000000}};
  // 720942594574823
  s21_decimal dec_2 = {{0x8740c9e7, 0x28fb1, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_82) {
  // 260635653272632381
  s21_decimal dec_1 = {{0xe91dfc3d, 0x39df6be, 0x0, 0x0}};
  // -70609419139922.474365206834
  s21_decimal dec_2 = {{0x5dedc132, 0x480e8f7b, 0x3a6820, 0x800c0000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_83) {
  // -43932591576140653847113113443
  s21_decimal dec_1 = {{0x71d81f63, 0x7d0e8f4c, 0x8df43021, 0x80000000}};
  // -2085509730063460052875842
  s21_decimal dec_2 = {{0x4ee5ba42, 0xb581449b, 0x1b99f, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_84) {
  // -6295092889496252114
  s21_decimal dec_1 = {{0x5282eed2, 0x575ca9a1, 0x0, 0x80000000}};
  // 36886481179660847879
  s21_decimal dec_2 = {{0x2fd10b07, 0xffe71b33, 0x1, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_85) {
  // -3977086392698832
  s21_decimal dec_1 = {{0x95ad87d0, 0xe2123, 0x0, 0x80000000}};
  // -499600079629988.562360
  s21_decimal dec_2 = {{0xc65685b8, 0x1558096d, 0x1b, 0x80060000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_86) {
  // 2221744902
  s21_decimal dec_1 = {{0x846d2306, 0x0, 0x0, 0x0}};
  // 9012927381958677407136426662
  s21_decimal dec_2 = {{0xbbc32aa6, 0x66102e2e, 0x1d1f519c, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_87) {
  // -5232318870874512040586506
  s21_decimal dec_1 = {{0x256ed0a, 0x930866e1, 0x453fc, 0x80000000}};
  // 8850076.10
  s21_decimal dec_2 = {{0x34c024fa, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_88) {
  // 25022840293122340920
  s21_decimal dec_1 = {{0x7ee37838, 0x5b42fcab, 0x1, 0x0}};
  // -2431067921266985737170165
  s21_decimal dec_2 = {{0x24b4acf5, 0x74c1fa73, 0x202cc, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_89) {
  // -94974540725620279956782547
  s21_decimal dec_1 = {{0xe54bdd3, 0x2b55b4d8, 0x4e8fa4, 0x80000000}};
  // 342080011847
  s21_decimal dec_2 = {{0xa58ebe47, 0x4f, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_90) {
  // -8126848187974
  s21_decimal dec_1 = {{0x2de63e46, 0x764, 0x0, 0x80000000}};
  // 39588614430328453039070
  s21_decimal dec_2 = {{0x3ebb83de, 0x1a6402ea, 0x862, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_91) {
  // 802501905433456012.8
  s21_decimal dec_1 = {{0xc15a4780, 0x6f5e984f, 0x0, 0x10000}};
  // -6885867411532192825.4
  s21_decimal dec_2 = {{0x6c261a3e, 0xbb9b2747, 0x3, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_92) {
  // 3463.035577
  s21_decimal dec_1 = {{0xce69bab9, 0x0, 0x0, 0x60000}};
  // 39333383480623334130810777140
  s21_decimal dec_2 = {{0x953a6e34, 0xb7c2d5a, 0x7f17cfef, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_93) {
  // -39060887224986468556
  s21_decimal dec_1 = {{0x48e980cc, 0x1e1425fa, 0x2, 0x80000000}};
  // -4815592972351836
  s21_decimal dec_2 = {{0x9c7ff95c, 0x111bc1, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_94) {
  // -4550821871912736229232072
  s21_decimal dec_1 = {{0x39890dc8, 0x8c4a20fe, 0x3c3ac, 0x80000000}};
  // -1039488412028
  s21_decimal dec_2 = {{0x656697c, 0xf2, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_95) {
  // -92729601314214.780428
  s21_decimal dec_1 = {{0xc15e1e0c, 0x6e1b917, 0x5, 0x80060000}};
  // -8201648790570106043822
  s21_decimal dec_2 = {{0x6b4f3dae, 0x9cbdd8d3, 0x1bc, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_96) {
  // 83104298314965188.97516101374
  s21_decimal dec_1 = {{0x24733efe, 0xe13d6cb9, 0x1ada39f7, 0xb0000}};
  // -4837111512739359125976616557
  s21_decimal dec_2 = {{0x85a78e6d, 0x88888132, 0xfa12a34, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_97) {
  // 524342657820767497354130
  s21_decimal dec_1 = {{0x3a5fb92, 0xac24d186, 0x6f08, 0x0}};
  // 860816307849.06818767886562
  s21_decimal dec_2 = {{0x492918e2, 0x8e2efe25, 0x47347e, 0xe0000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_98) {
  // -35307136483867836274832
  s21_decimal dec_1 = {{0xf8bfd890, 0xf2bed9, 0x77a, 0x80000000}};
  // -11842844266919532186455
  s21_decimal dec_2 = {{0x6a1c4b57, 0x7ad2af, 0x282, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_99) {
  // -1014841053654166
  s21_decimal dec_1 = {{0x1881ac96, 0x39afe, 0x0, 0x80000000}};
  // 840406744772492403011206
  s21_decimal dec_2 = {{0xbdc1ee86, 0x8a79e8d0, 0xb1f6, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_100) {
  // -9042051.1352
  s21_decimal dec_1 = {{0xd7b8278, 0x15, 0x0, 0x80040000}};
  // -32542056084919164344973399905
  s21_decimal dec_2 = {{0x8e281761, 0x3881640d, 0x6926286b, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_101) {
  // 72807926656896073735680457515
  s21_decimal dec_1 = {{0xa1ca7b2b, 0xc7524ea0, 0xeb414e2c, 0x0}};
  // -323364.07305149961821468034
  s21_decimal dec_2 = {{0x7793b582, 0x270c454d, 0x1abf80, 0x80140000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_102) {
  // -520157631566
  s21_decimal dec_1 = {{0x1bcf944e, 0x79, 0x0, 0x80000000}};
  // -2864065188867021698457586
  s21_decimal dec_2 = {{0x58835ff2, 0x48f576d6, 0x25e7d, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_103) {
  // -88600737338404252
  s21_decimal dec_1 = {{0xb3e4ad9c, 0x13ac5e6, 0x0, 0x80000000}};
  // -727134442483733815603678283
  s21_decimal dec_2 = {{0x664ecc4b, 0x1c8aefed, 0x25978b5, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_104) {
  // 4772349451759273
  s21_decimal dec_1 = {{0x31d0eea9, 0x10f46d, 0x0, 0x0}};
  // -1669251373025793049481225
  s21_decimal dec_2 = {{0x6f1d009, 0x4c5a4e25, 0x1617a, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_105) {
  // -9178.946912
  s21_decimal dec_1 = {{0x231b9d60, 0x2, 0x0, 0x80060000}};
  // 55856013242117628179119664
  s21_decimal dec_2 = {{0xb38dfe30, 0x8b908880, 0x2e33f8, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_106) {
  // -1269341849803218724115.92
  s21_decimal dec_1 = {{0xb13c7bc8, 0x1daf4977, 0x1ae1, 0x80020000}};
  // -438854888486481329824
  s21_decimal dec_2 = {{0xf4627ea0, 0xca55c3ec, 0x17, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_107) {
  // -4380727183568
  s21_decimal dec_1 = {{0xf7b008d0, 0x3fb, 0x0, 0x80000000}};
  // 9723543557177429151141
  s21_decimal dec_2 = {{0xed34da5, 0x1d4633b6, 0x20f, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_108) {
  // -38988394063864856
  s21_decimal dec_1 = {{0xe28a2418, 0x8a83bc, 0x0, 0x80000000}};
  // -23254462014921025321419657
  s21_decimal dec_2 = {{0x5e2fc389, 0xe96d8e7c, 0x133c52, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_109) {
  // -63029100434.739926
  s21_decimal dec_1 = {{0x5ecd2d6, 0xdfeca2, 0x0, 0x80060000}};
  // 9759028372879704794
  s21_decimal dec_2 = {{0x7e7402da, 0x876f0899, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_110) {
  // -80093707991.44097
  s21_decimal dec_1 = {{0xf55b7ca1, 0x1c747a, 0x0, 0x80050000}};
  // -48886389866361383036
  s21_decimal dec_2 = {{0x7fb9e87c, 0xa66f5892, 0x2, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_111) {
  // 4546317076085291650225583344
  s21_decimal dec_1 = {{0x31d0b4f0, 0x88f4836d, 0xeb0a016, 0x0}};
  // 301.01332271608475501191159
  s21_decimal dec_2 = {{0xf50bdff7, 0x7dff765e, 0x18e634, 0x170000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_112) {
  // -65029856269271549143
  s21_decimal dec_1 = {{0xe4a3c4d7, 0x867875bb, 0x3, 0x80000000}};
  // -181075659192452883229978468
  s21_decimal dec_2 = {{0xa1382f64, 0x276ed853, 0x95c843, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_113) {
  // 7522523427
  s21_decimal dec_1 = {{0xc0609923, 0x1, 0x0, 0x0}};
  // -18801835073525466732923
  s21_decimal dec_2 = {{0xd5eb197b, 0x3fe0a6fa, 0x3fb, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_114) {
  // 77975202877377631
  s21_decimal dec_1 = {{0xaccb8c5f, 0x1150608, 0x0, 0x0}};
  // 783961648454209136.573432
  s21_decimal dec_2 = {{0x2e753bf8, 0xa5681e46, 0xa602, 0x60000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_115) {
  // -624
  s21_decimal dec_1 = {{0x270, 0x0, 0x0, 0x80000000}};
  // 954892079049847278947173784
  s21_decimal dec_2 = {{0x62068598, 0x546aa444, 0x315de43, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_116) {
  // -3885275252220481005
  s21_decimal dec_1 = {{0xbf37cded, 0x35eb4541, 0x0, 0x80000000}};
  // -94926318569497950
  s21_decimal dec_2 = {{0xda2ba55e, 0x1513efb, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_117) {
  // -5661014484
  s21_decimal dec_1 = {{0x516c39d4, 0x1, 0x0, 0x80000000}};
  // 9975122708414700072885586
  s21_decimal dec_2 = {{0xe98a5d52, 0x7c4de5fd, 0x84050, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_118) {
  // 570711334795.900235046752
  s21_decimal dec_1 = {{0x88c05f60, 0x52cdc6a0, 0x78da, 0xc0000}};
  // -285825377906412956937
  s21_decimal dec_2 = {{0x8f872d09, 0x7e9fbad6, 0xf, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_119) {
  // -691100687761432786683180.8
  s21_decimal dec_1 = {{0xc403b3c0, 0x6efc627f, 0x5b776, 0x80010000}};
  // 69658691196144737736
  s21_decimal dec_2 = {{0x48d65dc8, 0xc6b56293, 0x3, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_120) {
  // -95189367917002998010.9
  s21_decimal dec_1 = {{0x354989cd, 0x9a2db1db, 0x33, 0x80010000}};
  // -6315714370815
  s21_decimal dec_2 = {{0x7de95cff, 0x5be, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_121) {
  // -87685417.8
  s21_decimal dec_1 = {{0x3443bba2, 0x0, 0x0, 0x80010000}};
  // -33358570510288787376127023
  s21_decimal dec_2 = {{0x99d33c2f, 0xbb1d224c, 0x1b97f3, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_122) {
  // 6361416487534179152050
  s21_decimal dec_1 = {{0xebe470b2, 0xda635f2e, 0x158, 0x0}};
  // -5168518375590149821873359
  s21_decimal dec_2 = {{0x479cbccf, 0xf14c1743, 0x44679, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_123) {
  // -17754630648.6656563847699
  s21_decimal dec_1 = {{0x74caa213, 0xcdf7acf7, 0x2598, 0x800d0000}};
  // -879063395051121647393373
  s21_decimal dec_2 = {{0x86e59a5d, 0x1f442184, 0xba26, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_124) {
  // -6132893571
  s21_decimal dec_1 = {{0x6d8c8783, 0x1, 0x0, 0x80000000}};
  // -15573207596583586844
  s21_decimal dec_2 = {{0x77c78c1c, 0xd81f25cc, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_125) {
  // -7049394546777420494873233437
  s21_decimal dec_1 = {{0x48f081d, 0x1dbdccac, 0x16c71f5c, 0x80000000}};
  // 4713711156492257753548431627
  s21_decimal dec_2 = {{0xf27fa10b, 0xd12092a1, 0xf3b1729, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_126) {
  // -5266227347630212083393622
  s21_decimal dec_1 = {{0xed58a456, 0xc1ad9960, 0x45b2a, 0x80000000}};
  // 9647490002576842395981.08
  s21_decimal dec_2 = {{0xdba4c21c, 0x25e9d317, 0xcc4b, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_127) {
  // -355331931515798271914377
  s21_decimal dec_1 = {{0x8d57189, 0x95259c5c, 0x4b3e, 0x80000000}};
  // -592440899567885884
  s21_decimal dec_2 = {{0xf9281e3c, 0x838c5db, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_128) {
  // -7289765046439286234441657.268
  s21_decimal dec_1 = {{0x27b52bb4, 0x34e9f00, 0x178df3cb, 0x80030000}};
  // -9788513072018181
  s21_decimal dec_2 = {{0xcc897305, 0x22c699, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_129) {
  // 2667761628764203347083031904
  s21_decimal dec_1 = {{0xe4fc7560, 0xadd1b06a, 0x89eb87f, 0x0}};
  // 122340652250251755405
  s21_decimal dec_2 = {{0x75d97f8d, 0xa1d14f08, 0x6, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_130) {
  // 68448968909.583797584246534730
  s21_decimal dec_1 = {{0xd8d2f24a, 0xcee490f1, 0xdd2ba8f7, 0x120000}};
  // 134199579999641735699020922
  s21_decimal dec_2 = {{0xaa8abc7a, 0xcf220262, 0x6f01dd, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_131) {
  // 52089439749.4590734
  s21_decimal dec_1 = {{0xd827fd0e, 0x73a96b1, 0x0, 0x70000}};
  // -960586348656403746337197
  s21_decimal dec_2 = {{0xe8df31ad, 0x7d848a66, 0xcb69, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_132) {
  // -50141311373421361759810956
  s21_decimal dec_1 = {{0x6dd8758c, 0xefa55965, 0x2979d5, 0x80000000}};
  // -2131507639479
  s21_decimal dec_2 = {{0x47c174b7, 0x1f0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_133) {
  // 5592166133599297464667849257
  s21_decimal dec_1 = {{0x9b05c229, 0x8c232237, 0x1211bb3d, 0x0}};
  // -781.971299402209139109
  s21_decimal dec_2 = {{0xab4d99a5, 0x640821be, 0x2a, 0x80120000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_134) {
  // 673
  s21_decimal dec_1 = {{0x2a1, 0x0, 0x0, 0x0}};
  // 376407417043539735446625515
  s21_decimal dec_2 = {{0xb32d1ceb, 0xf7048c65, 0x1375b5e, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_135) {
  // 29933680697934652454322862798
  s21_decimal dec_1 = {{0xada07ace, 0x28cef720, 0x60b88f72, 0x0}};
  // -9796189866505443.6635
  s21_decimal dec_2 = {{0xbd61fd1b, 0x4f7e93cf, 0x5, 0x80040000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_136) {
  // 3418823625973522918976336
  s21_decimal dec_1 = {{0xc71eab50, 0xccd56707, 0x2d3f6, 0x0}};
  // 192737
  s21_decimal dec_2 = {{0x2f0e1, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_137) {
  // 5291883333181627910827806
  s21_decimal dec_1 = {{0x741baf1e, 0x92006927, 0x46099, 0x0}};
  // -76803714032684
  s21_decimal dec_2 = {{0x4217a42c, 0x45da, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_138) {
  // -93816675112969265.7421
  s21_decimal dec_1 = {{0x2fa1d70d, 0xdbadd988, 0x32, 0x80040000}};
  // -249047244622322171543
  s21_decimal dec_2 = {{0xa3537e97, 0x80398d79, 0xd, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_139) {
  // 53913651.660
  s21_decimal dec_1 = {{0x8d8109cc, 0xc, 0x0, 0x30000}};
  // -19050960016180025106292
  s21_decimal dec_2 = {{0x546e1f74, 0xc12e3e67, 0x408, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_140) {
  // -235349167237
  s21_decimal dec_1 = {{0xcbe74c85, 0x36, 0x0, 0x80000000}};
  // -464047898880575567700
  s21_decimal dec_2 = {{0x97187754, 0x27f55166, 0x19, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_141) {
  // -79063580422263811.4595
  s21_decimal dec_1 = {{0xf3a1c723, 0xdc46a2f8, 0x2a, 0x80040000}};
  // 6242195728323089754726
  s21_decimal dec_2 = {{0xe6876a66, 0x63de2656, 0x152, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_142) {
  // 6459087647.2303931575376601
  s21_decimal dec_1 = {{0x82821ad9, 0x6e00de1c, 0x356da6, 0x100000}};
  // -377575611995674987201
  s21_decimal dec_2 = {{0xf4ed4ac1, 0x77ea0aa0, 0x14, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_143) {
  // 84370077908
  s21_decimal dec_1 = {{0xa4d938d4, 0x13, 0x0, 0x0}};
  // 77437388381594956437819
  s21_decimal dec_2 = {{0x7081993b, 0xe3a4f431, 0x1065, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_144) {
  // -3751959943140632424
  s21_decimal dec_1 = {{0x86646768, 0x3411a3b0, 0x0, 0x80000000}};
  // 419302608444842.4339549763218
  s21_decimal dec_2 = {{0x2590b692, 0x809b38b5, 0xd8c63cf, 0xd0000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_145) {
  // 7925891503205752584296
  s21_decimal dec_1 = {{0x21b53868, 0xa9d728fe, 0x1ad, 0x0}};
  // -8467235147205
  s21_decimal dec_2 = {{0x6e8b0dc5, 0x7b3, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_146) {
  // 9544433809847013
  s21_decimal dec_1 = {{0xaad172e5, 0x21e89c, 0x0, 0x0}};
  // 83917013865866398393612444
  s21_decimal dec_2 = {{0x166b89c, 0x6fe55ad8, 0x456a1e, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_147) {
  // 67945987572190092029141
  s21_decimal dec_1 = {{0xd8816cd5, 0x5bff77a2, 0xe63, 0x0}};
  // 2605875
  s21_decimal dec_2 = {{0x27c333, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_148) {
  // -44912406695534590
  s21_decimal dec_1 = {{0x8f185ffe, 0x9f8f98, 0x0, 0x80000000}};
  // 133267654919832
  s21_decimal dec_2 = {{0xcb3b4698, 0x7934, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_149) {
  // -972448742392695451200818
  s21_decimal dec_1 = {{0x56b6ad32, 0x8d4d07e7, 0xcdec, 0x80000000}};
  // 6944526615660877507041395339
  s21_decimal dec_2 = {{0x53b828b, 0x2ddc8c6d, 0x167060b6, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_150) {
  // 3482194017896
  s21_decimal dec_1 = {{0xc2effe68, 0x32a, 0x0, 0x0}};
  // 28036591275859947806.3720
  s21_decimal dec_2 = {{0x6026b268, 0xaaa553ad, 0x3b5e, 0x40000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_151) {
  // 339624820820752242
  s21_decimal dec_1 = {{0xa1ed3772, 0x4b696f9, 0x0, 0x0}};
  // 5845235371609266414771
  s21_decimal dec_2 = {{0x26bd64b3, 0xdeefa918, 0x13c, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_152) {
  // 768135376028515259660025227.5
  s21_decimal dec_1 = {{0x27a36773, 0xb9feb9c3, 0x18d1dded, 0x10000}};
  // -4907
  s21_decimal dec_2 = {{0x132b, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_153) {
  // -132820341702
  s21_decimal dec_1 = {{0xecb593c6, 0x1e, 0x0, 0x80000000}};
  // -4173308407890660086195433182
  s21_decimal dec_2 = {{0x8ac82ede, 0x1d4649d9, 0xd7c146e, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_154) {
  // 42179422258027385456498
  s21_decimal dec_1 = {{0xdf0a0772, 0x8d126b84, 0x8ee, 0x0}};
  // -30482556508
  s21_decimal dec_2 = {{0x18e6e65c, 0x7, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_155) {
  // -181098765688151392907
  s21_decimal dec_1 = {{0x17f6c28b, 0xd1400fe4, 0x9, 0x80000000}};
  // -114845088316
  s21_decimal dec_2 = {{0xbd4cfa3c, 0x1a, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_156) {
  // -786
  s21_decimal dec_1 = {{0x312, 0x0, 0x0, 0x80000000}};
  // -28102579430239733681022103747
  s21_decimal dec_2 = {{0x75dcf0c3, 0x891e4a24, 0x5acde8ab, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_157) {
  // 16410048366124115
  s21_decimal dec_1 = {{0x1f9c1c53, 0x3a4cda, 0x0, 0x0}};
  // 89577449963414211.69
  s21_decimal dec_2 = {{0x2f769471, 0x7c504d9d, 0x0, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_158) {
  // 10511374966358982028630075695
  s21_decimal dec_1 = {{0x1956a92f, 0xb780b5f3, 0x21f6ce3a, 0x0}};
  // 30319
  s21_decimal dec_2 = {{0x766f, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_159) {
  // -95563096824176525196
  s21_decimal dec_1 = {{0x214d3f8c, 0x2e34523f, 0x5, 0x80000000}};
  // 7773366408397492554837498.8
  s21_decimal dec_2 = {{0xffd9cbcc, 0x5fae6bc1, 0x404cbe, 0x10000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_160) {
  // -872.93610
  s21_decimal dec_1 = {{0x533feaa, 0x0, 0x0, 0x80050000}};
  // -79228162514264337593240159583
  s21_decimal dec_2 = {{0xede4855f, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_161) {
  // -6062610032663238
  s21_decimal dec_1 = {{0x65689ac6, 0x1589e9, 0x0, 0x80000000}};
  // 5140321082996576287992
  s21_decimal dec_2 = {{0xa628fcf8, 0xa8490665, 0x116, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_162) {
  // -527774349993876699565566779
  s21_decimal dec_1 = {{0x6638ab3b, 0xd79f49f0, 0x1b49090, 0x80000000}};
  // 2035968.031
  s21_decimal dec_2 = {{0x795a681f, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_163) {
  // -2290228559308189215584
  s21_decimal dec_1 = {{0x33422b60, 0x274e548a, 0x7c, 0x80000000}};
  // 300901116.8
  s21_decimal dec_2 = {{0xb359dde0, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_164) {
  // -3289955892661
  s21_decimal dec_1 = {{0xa6fdb5, 0x2fe, 0x0, 0x80000000}};
  // -25188042170723852416512
  s21_decimal dec_2 = {{0x7234f600, 0x724df64e, 0x555, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_165) {
  // 19225189779922466099459226903
  s21_decimal dec_1 = {{0x22077d17, 0x4aba232b, 0x3e1eb44a, 0x0}};
  // -884851599424
  s21_decimal dec_2 = {{0x543e840, 0xce, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_166) {
  // -8728583310036
  s21_decimal dec_1 = {{0x481b8ad4, 0x7f0, 0x0, 0x80000000}};
  // -71806288188973254842
  s21_decimal dec_2 = {{0x6f1408ba, 0xe4832ea9, 0x3, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

Suite *suite_s21_mul(void) {
  Suite *c = suite_create("s21_mul_cases");
  TCase *tc = tcase_create("s21_mul_tc");

  tcase_add_test(tc, invalid_dec_s21_mul_1);
  tcase_add_test(tc, invalid_dec_s21_mul_2);
  tcase_add_test(tc, invalid_dec_s21_mul_3);
  tcase_add_test(tc, invalid_dec_s21_mul_4);
  tcase_add_test(tc, invalid_dec_s21_mul_5);
  tcase_add_test(tc, invalid_dec_s21_mul_6);
  tcase_add_test(tc, invalid_dec_s21_mul_7);
  tcase_add_test(tc, invalid_dec_s21_mul_8);
  tcase_add_test(tc, invalid_dec_s21_mul_9);
  tcase_add_test(tc, invalid_dec_s21_mul_10);
  tcase_add_test(tc, invalid_dec_s21_mul_11);
  tcase_add_test(tc, invalid_dec_s21_mul_12);
  tcase_add_test(tc, invalid_dec_s21_mul_13);
  tcase_add_test(tc, invalid_dec_s21_mul_14);
  tcase_add_test(tc, invalid_dec_s21_mul_15);
  tcase_add_test(tc, invalid_dec_s21_mul_16);
  tcase_add_test(tc, s21_mul_1);
  tcase_add_test(tc, s21_mul_2);
  tcase_add_test(tc, s21_mul_3);
  tcase_add_test(tc, s21_mul_4);
  tcase_add_test(tc, s21_mul_5);
  tcase_add_test(tc, s21_mul_6);
  tcase_add_test(tc, s21_mul_7);
  tcase_add_test(tc, s21_mul_8);
  tcase_add_test(tc, s21_mul_9);
  tcase_add_test(tc, s21_mul_10);
  tcase_add_test(tc, s21_mul_11);
  tcase_add_test(tc, s21_mul_12);
  tcase_add_test(tc, s21_mul_13);
  tcase_add_test(tc, s21_mul_14);
  tcase_add_test(tc, s21_mul_15);
  tcase_add_test(tc, s21_mul_16);
  tcase_add_test(tc, s21_mul_17);
  tcase_add_test(tc, s21_mul_18);
  tcase_add_test(tc, s21_mul_19);
  tcase_add_test(tc, s21_mul_20);
  tcase_add_test(tc, s21_mul_21);
  tcase_add_test(tc, s21_mul_22);
  tcase_add_test(tc, s21_mul_23);
  tcase_add_test(tc, s21_mul_24);
  tcase_add_test(tc, s21_mul_25);
  tcase_add_test(tc, s21_mul_26);
  tcase_add_test(tc, s21_mul_27);
  tcase_add_test(tc, s21_mul_28);
  tcase_add_test(tc, s21_mul_29);
  tcase_add_test(tc, s21_mul_30);
  tcase_add_test(tc, s21_mul_31);
  tcase_add_test(tc, s21_mul_32);
  tcase_add_test(tc, s21_mul_33);
  tcase_add_test(tc, s21_mul_34);
  tcase_add_test(tc, s21_mul_35);
  tcase_add_test(tc, s21_mul_36);
  tcase_add_test(tc, s21_mul_37);
  tcase_add_test(tc, s21_mul_38);
  tcase_add_test(tc, s21_mul_40);
  tcase_add_test(tc, s21_mul_41);
  tcase_add_test(tc, s21_mul_42);
  tcase_add_test(tc, s21_mul_43);
  tcase_add_test(tc, s21_mul_44);
  tcase_add_test(tc, s21_mul_45);
  tcase_add_test(tc, s21_mul_46);
  tcase_add_test(tc, s21_mul_47);
  tcase_add_test(tc, s21_mul_48);
  tcase_add_test(tc, s21_mul_49);
  tcase_add_test(tc, s21_mul_50);
  tcase_add_test(tc, s21_mul_52);
  tcase_add_test(tc, s21_mul_53);
  tcase_add_test(tc, s21_mul_54);
  tcase_add_test(tc, s21_mul_55);
  tcase_add_test(tc, s21_mul_56);
  tcase_add_test(tc, s21_mul_57);
  tcase_add_test(tc, s21_mul_58);
  tcase_add_test(tc, s21_mul_59);
  tcase_add_test(tc, s21_mul_60);
  tcase_add_test(tc, s21_mul_61);
  tcase_add_test(tc, s21_mul_62);
  tcase_add_test(tc, s21_mul_63);
  tcase_add_test(tc, s21_mul_64);
  tcase_add_test(tc, s21_mul_65);
  tcase_add_test(tc, s21_mul_66);
  tcase_add_test(tc, s21_mul_67);
  tcase_add_test(tc, s21_mul_68);
  tcase_add_test(tc, s21_mul_70);
  tcase_add_test(tc, s21_mul_71);
  tcase_add_test(tc, s21_mul_72);
  tcase_add_test(tc, s21_mul_73);
  tcase_add_test(tc, s21_mul_74);
  tcase_add_test(tc, s21_mul_75);
  tcase_add_test(tc, s21_mul_77);
  tcase_add_test(tc, s21_mul_78);
  tcase_add_test(tc, s21_mul_79);
  tcase_add_test(tc, s21_mul_80);
  tcase_add_test(tc, s21_mul_81);
  tcase_add_test(tc, s21_mul_82);
  tcase_add_test(tc, s21_mul_83);
  tcase_add_test(tc, s21_mul_84);
  tcase_add_test(tc, s21_mul_85);
  tcase_add_test(tc, s21_mul_86);
  tcase_add_test(tc, s21_mul_87);
  tcase_add_test(tc, s21_mul_88);
  tcase_add_test(tc, s21_mul_89);
  tcase_add_test(tc, s21_mul_90);
  tcase_add_test(tc, s21_mul_91);
  tcase_add_test(tc, s21_mul_92);
  tcase_add_test(tc, s21_mul_93);
  tcase_add_test(tc, s21_mul_94);
  tcase_add_test(tc, s21_mul_95);
  tcase_add_test(tc, s21_mul_96);
  tcase_add_test(tc, s21_mul_97);
  tcase_add_test(tc, s21_mul_98);
  tcase_add_test(tc, s21_mul_99);
  tcase_add_test(tc, s21_mul_100);
  tcase_add_test(tc, s21_mul_101);
  tcase_add_test(tc, s21_mul_102);
  tcase_add_test(tc, s21_mul_103);
  tcase_add_test(tc, s21_mul_104);
  tcase_add_test(tc, s21_mul_105);
  tcase_add_test(tc, s21_mul_106);
  tcase_add_test(tc, s21_mul_107);
  tcase_add_test(tc, s21_mul_108);
  tcase_add_test(tc, s21_mul_109);
  tcase_add_test(tc, s21_mul_110);
  tcase_add_test(tc, s21_mul_111);
  tcase_add_test(tc, s21_mul_112);
  tcase_add_test(tc, s21_mul_113);
  tcase_add_test(tc, s21_mul_114);
  tcase_add_test(tc, s21_mul_115);
  tcase_add_test(tc, s21_mul_116);
  tcase_add_test(tc, s21_mul_117);
  tcase_add_test(tc, s21_mul_118);
  tcase_add_test(tc, s21_mul_119);
  tcase_add_test(tc, s21_mul_120);
  tcase_add_test(tc, s21_mul_121);
  tcase_add_test(tc, s21_mul_122);
  tcase_add_test(tc, s21_mul_123);
  tcase_add_test(tc, s21_mul_124);
  tcase_add_test(tc, s21_mul_125);
  tcase_add_test(tc, s21_mul_127);
  tcase_add_test(tc, s21_mul_128);
  tcase_add_test(tc, s21_mul_129);
  tcase_add_test(tc, s21_mul_130);
  tcase_add_test(tc, s21_mul_131);
  tcase_add_test(tc, s21_mul_132);
  tcase_add_test(tc, s21_mul_133);
  tcase_add_test(tc, s21_mul_134);
  tcase_add_test(tc, s21_mul_135);
  tcase_add_test(tc, s21_mul_136);
  tcase_add_test(tc, s21_mul_137);
  tcase_add_test(tc, s21_mul_138);
  tcase_add_test(tc, s21_mul_139);
  tcase_add_test(tc, s21_mul_140);
  tcase_add_test(tc, s21_mul_141);
  tcase_add_test(tc, s21_mul_142);
  tcase_add_test(tc, s21_mul_143);
  tcase_add_test(tc, s21_mul_144);
  tcase_add_test(tc, s21_mul_145);
  tcase_add_test(tc, s21_mul_146);
  tcase_add_test(tc, s21_mul_147);
  tcase_add_test(tc, s21_mul_148);
  tcase_add_test(tc, s21_mul_149);
  tcase_add_test(tc, s21_mul_150);
  tcase_add_test(tc, s21_mul_151);
  tcase_add_test(tc, s21_mul_152);
  tcase_add_test(tc, s21_mul_153);
  tcase_add_test(tc, s21_mul_155);
  tcase_add_test(tc, s21_mul_156);
  tcase_add_test(tc, s21_mul_157);
  tcase_add_test(tc, s21_mul_159);
  tcase_add_test(tc, s21_mul_160);
  tcase_add_test(tc, s21_mul_161);
  tcase_add_test(tc, s21_mul_162);
  tcase_add_test(tc, s21_mul_163);
  tcase_add_test(tc, s21_mul_164);
  tcase_add_test(tc, s21_mul_165);
  tcase_add_test(tc, s21_mul_166);
  tcase_add_test(tc, s21_mul_167);
  tcase_add_test(tc, s21_mul_168);
  tcase_add_test(tc, s21_mul_169);
  tcase_add_test(tc, s21_mul_170);
  tcase_add_test(tc, s21_mul_171);
  tcase_add_test(tc, s21_mul_172);
  tcase_add_test(tc, s21_mul_173);
  tcase_add_test(tc, s21_mul_174);
  tcase_add_test(tc, s21_mul_175);
  tcase_add_test(tc, s21_mul_176);
  tcase_add_test(tc, s21_mul_177);
  tcase_add_test(tc, s21_mul_178);
  tcase_add_test(tc, s21_mul_179);
  tcase_add_test(tc, s21_mul_180);
  tcase_add_test(tc, s21_mul_181);
  tcase_add_test(tc, s21_mul_182);
  tcase_add_test(tc, s21_mul_183);
  tcase_add_test(tc, s21_mul_184);
  tcase_add_test(tc, s21_mul_185);
  tcase_add_test(tc, s21_mul_186);
  tcase_add_test(tc, s21_mul_187);
  tcase_add_test(tc, s21_mul_188);
  tcase_add_test(tc, s21_mul_189);
  tcase_add_test(tc, s21_mul_190);
  tcase_add_test(tc, s21_mul_191);
  tcase_add_test(tc, s21_mul_192);
  tcase_add_test(tc, s21_mul_193);
  tcase_add_test(tc, s21_mul_194);
  tcase_add_test(tc, s21_mul_195);
  tcase_add_test(tc, s21_mul_196);
  tcase_add_test(tc, s21_mul_197);
  tcase_add_test(tc, s21_mul_198);
  tcase_add_test(tc, s21_mul_199);
  tcase_add_test(tc, s21_mul_200);
  tcase_add_test(tc, s21_mul_201);
  tcase_add_test(tc, s21_mul_202);
  tcase_add_test(tc, s21_mul_203);
  tcase_add_test(tc, s21_mul_204);
  tcase_add_test(tc, s21_mul_205);
  tcase_add_test(tc, s21_mul_206);
  tcase_add_test(tc, s21_mul_207);
  tcase_add_test(tc, s21_mul_208);
  tcase_add_test(tc, s21_mul_210);
  tcase_add_test(tc, s21_mul_211);
  tcase_add_test(tc, s21_mul_212);
  tcase_add_test(tc, s21_mul_213);
  tcase_add_test(tc, s21_mul_214);
  tcase_add_test(tc, s21_mul_215);
  tcase_add_test(tc, s21_mul_216);
  tcase_add_test(tc, s21_mul_217);
  tcase_add_test(tc, s21_mul_218);
  tcase_add_test(tc, s21_mul_219);
  tcase_add_test(tc, s21_mul_220);
  tcase_add_test(tc, s21_mul_221);
  tcase_add_test(tc, s21_mul_222);
  tcase_add_test(tc, s21_mul_223);
  tcase_add_test(tc, s21_mul_224);
  tcase_add_test(tc, s21_mul_225);
  tcase_add_test(tc, s21_mul_226);
  tcase_add_test(tc, s21_mul_227);
  tcase_add_test(tc, s21_mul_228);
  tcase_add_test(tc, s21_mul_229);
  tcase_add_test(tc, s21_mul_230);
  tcase_add_test(tc, s21_mul_231);
  tcase_add_test(tc, s21_mul_232);
  tcase_add_test(tc, s21_mul_233);
  tcase_add_test(tc, s21_mul_234);
  tcase_add_test(tc, s21_mul_235);
  tcase_add_test(tc, s21_mul_236);
  tcase_add_test(tc, s21_mul_237);
  tcase_add_test(tc, s21_mul_238);
  tcase_add_test(tc, s21_mul_239);
  tcase_add_test(tc, s21_mul_240);
  tcase_add_test(tc, s21_mul_241);
  tcase_add_test(tc, s21_mul_242);
  tcase_add_test(tc, s21_mul_243);
  tcase_add_test(tc, s21_mul_244);
  tcase_add_test(tc, s21_mul_245);
  tcase_add_test(tc, s21_mul_246);
  tcase_add_test(tc, s21_mul_247);
  tcase_add_test(tc, s21_mul_249);
  tcase_add_test(tc, s21_mul_250);
  tcase_add_test(tc, s21_mul_251);
  tcase_add_test(tc, s21_mul_252);
  tcase_add_test(tc, s21_mul_253);
  tcase_add_test(tc, s21_mul_254);
  tcase_add_test(tc, s21_mul_255);
  tcase_add_test(tc, s21_mul_256);
  tcase_add_test(tc, s21_mul_257);
  tcase_add_test(tc, s21_mul_258);
  tcase_add_test(tc, s21_mul_259);
  tcase_add_test(tc, s21_mul_261);
  tcase_add_test(tc, s21_mul_262);
  tcase_add_test(tc, s21_mul_263);
  tcase_add_test(tc, s21_mul_264);
  tcase_add_test(tc, s21_mul_265);
  tcase_add_test(tc, s21_mul_266);
  tcase_add_test(tc, s21_mul_267);
  tcase_add_test(tc, s21_mul_268);
  tcase_add_test(tc, s21_mul_269);
  tcase_add_test(tc, s21_mul_270);
  tcase_add_test(tc, s21_mul_271);
  tcase_add_test(tc, s21_mul_272);
  tcase_add_test(tc, s21_mul_273);
  tcase_add_test(tc, s21_mul_274);
  tcase_add_test(tc, s21_mul_275);
  tcase_add_test(tc, s21_mul_276);
  tcase_add_test(tc, s21_mul_277);
  tcase_add_test(tc, s21_mul_278);
  tcase_add_test(tc, s21_mul_279);
  tcase_add_test(tc, s21_mul_280);
  tcase_add_test(tc, s21_mul_281);
  tcase_add_test(tc, s21_mul_282);
  tcase_add_test(tc, s21_mul_283);
  tcase_add_test(tc, s21_mul_284);
  tcase_add_test(tc, s21_mul_285);
  tcase_add_test(tc, s21_mul_286);
  tcase_add_test(tc, s21_mul_287);
  tcase_add_test(tc, s21_mul_288);
  tcase_add_test(tc, s21_mul_289);
  tcase_add_test(tc, s21_mul_290);
  tcase_add_test(tc, s21_mul_291);
  tcase_add_test(tc, s21_mul_293);
  tcase_add_test(tc, s21_mul_295);
  tcase_add_test(tc, s21_mul_296);
  tcase_add_test(tc, s21_mul_297);
  tcase_add_test(tc, s21_mul_298);
  tcase_add_test(tc, s21_mul_299);
  tcase_add_test(tc, s21_mul_300);
  tcase_add_test(tc, s21_mul_301);
  tcase_add_test(tc, s21_mul_302);
  tcase_add_test(tc, s21_mul_303);
  tcase_add_test(tc, s21_mul_304);
  tcase_add_test(tc, s21_mul_305);
  tcase_add_test(tc, s21_mul_306);
  tcase_add_test(tc, s21_mul_307);
  tcase_add_test(tc, s21_mul_308);
  tcase_add_test(tc, s21_mul_309);
  tcase_add_test(tc, s21_mul_310);
  tcase_add_test(tc, s21_mul_311);
  tcase_add_test(tc, s21_mul_312);
  tcase_add_test(tc, s21_mul_313);
  tcase_add_test(tc, s21_mul_314);
  tcase_add_test(tc, s21_mul_315);
  tcase_add_test(tc, s21_mul_316);
  tcase_add_test(tc, s21_mul_317);
  tcase_add_test(tc, s21_mul_318);
  tcase_add_test(tc, s21_mul_319);
  tcase_add_test(tc, s21_mul_320);
  tcase_add_test(tc, s21_mul_321);
  tcase_add_test(tc, s21_mul_322);
  tcase_add_test(tc, s21_mul_323);
  tcase_add_test(tc, s21_mul_324);
  tcase_add_test(tc, s21_mul_325);
  tcase_add_test(tc, s21_mul_326);
  tcase_add_test(tc, s21_mul_327);
  tcase_add_test(tc, s21_mul_328);
  tcase_add_test(tc, s21_mul_330);
  tcase_add_test(tc, s21_mul_331);
  tcase_add_test(tc, s21_mul_332);
  tcase_add_test(tc, s21_mul_333);
  tcase_add_test(tc, s21_mul_334);
  tcase_add_test(tc, s21_mul_335);
  tcase_add_test(tc, s21_mul_336);
  tcase_add_test(tc, s21_mul_337);
  tcase_add_test(tc, s21_mul_339);
  tcase_add_test(tc, s21_mul_340);
  tcase_add_test(tc, s21_mul_341);
  tcase_add_test(tc, s21_mul_342);
  tcase_add_test(tc, s21_mul_343);
  tcase_add_test(tc, s21_mul_344);
  tcase_add_test(tc, s21_mul_345);
  tcase_add_test(tc, s21_mul_346);
  tcase_add_test(tc, s21_mul_347);
  tcase_add_test(tc, s21_mul_348);
  tcase_add_test(tc, s21_mul_349);
  tcase_add_test(tc, s21_mul_350);
  tcase_add_test(tc, s21_mul_351);
  tcase_add_test(tc, s21_mul_352);
  tcase_add_test(tc, s21_mul_353);
  tcase_add_test(tc, s21_mul_354);
  tcase_add_test(tc, s21_mul_355);
  tcase_add_test(tc, s21_mul_357);
  tcase_add_test(tc, s21_mul_358);
  tcase_add_test(tc, s21_mul_359);
  tcase_add_test(tc, s21_mul_360);
  tcase_add_test(tc, s21_mul_361);
  tcase_add_test(tc, s21_mul_362);
  tcase_add_test(tc, s21_mul_363);
  tcase_add_test(tc, s21_mul_364);
  tcase_add_test(tc, s21_mul_365);
  tcase_add_test(tc, s21_mul_366);
  tcase_add_test(tc, s21_mul_367);
  tcase_add_test(tc, s21_mul_368);
  tcase_add_test(tc, s21_mul_369);
  tcase_add_test(tc, s21_mul_370);
  tcase_add_test(tc, s21_mul_371);
  tcase_add_test(tc, s21_mul_372);
  tcase_add_test(tc, s21_mul_373);
  tcase_add_test(tc, s21_mul_374);
  tcase_add_test(tc, s21_mul_376);
  tcase_add_test(tc, s21_mul_377);
  tcase_add_test(tc, s21_mul_378);
  tcase_add_test(tc, s21_mul_379);
  tcase_add_test(tc, s21_mul_380);
  tcase_add_test(tc, s21_mul_381);
  tcase_add_test(tc, s21_mul_382);
  tcase_add_test(tc, s21_mul_383);
  tcase_add_test(tc, s21_mul_384);
  tcase_add_test(tc, s21_mul_385);
  tcase_add_test(tc, s21_mul_386);
  tcase_add_test(tc, s21_mul_387);
  tcase_add_test(tc, s21_mul_388);
  tcase_add_test(tc, s21_mul_389);
  tcase_add_test(tc, s21_mul_390);
  tcase_add_test(tc, s21_mul_391);
  tcase_add_test(tc, s21_mul_392);
  tcase_add_test(tc, s21_mul_393);
  tcase_add_test(tc, s21_mul_394);
  tcase_add_test(tc, s21_mul_395);
  tcase_add_test(tc, s21_mul_396);
  tcase_add_test(tc, s21_mul_399);
  tcase_add_test(tc, s21_mul_400);
  tcase_add_test(tc, s21_mul_401);
  tcase_add_test(tc, s21_mul_403);
  tcase_add_test(tc, s21_mul_404);
  tcase_add_test(tc, s21_mul_405);
  tcase_add_test(tc, s21_mul_406);
  tcase_add_test(tc, s21_mul_407);
  tcase_add_test(tc, s21_mul_408);
  tcase_add_test(tc, s21_mul_409);
  tcase_add_test(tc, s21_mul_410);
  tcase_add_test(tc, s21_mul_411);
  tcase_add_test(tc, s21_mul_412);
  tcase_add_test(tc, s21_mul_413);
  tcase_add_test(tc, s21_mul_414);
  tcase_add_test(tc, s21_mul_415);
  tcase_add_test(tc, s21_mul_416);
  tcase_add_test(tc, s21_mul_417);
  tcase_add_test(tc, s21_mul_419);
  tcase_add_test(tc, s21_mul_420);
  tcase_add_test(tc, s21_mul_421);
  tcase_add_test(tc, s21_mul_422);
  tcase_add_test(tc, s21_mul_423);
  tcase_add_test(tc, s21_mul_424);
  tcase_add_test(tc, s21_mul_425);
  tcase_add_test(tc, s21_mul_426);
  tcase_add_test(tc, s21_mul_427);
  tcase_add_test(tc, s21_mul_428);
  tcase_add_test(tc, s21_mul_429);
  tcase_add_test(tc, s21_mul_430);
  tcase_add_test(tc, s21_mul_431);
  tcase_add_test(tc, s21_mul_432);
  tcase_add_test(tc, s21_mul_433);
  tcase_add_test(tc, s21_mul_434);
  tcase_add_test(tc, s21_mul_435);
  tcase_add_test(tc, s21_mul_436);
  tcase_add_test(tc, s21_mul_437);
  tcase_add_test(tc, s21_mul_438);
  tcase_add_test(tc, s21_mul_439);
  tcase_add_test(tc, s21_mul_440);
  tcase_add_test(tc, s21_mul_441);
  tcase_add_test(tc, s21_mul_442);
  tcase_add_test(tc, s21_mul_443);
  tcase_add_test(tc, s21_mul_444);
  tcase_add_test(tc, s21_mul_445);
  tcase_add_test(tc, s21_mul_446);
  tcase_add_test(tc, s21_mul_447);
  tcase_add_test(tc, s21_mul_448);
  tcase_add_test(tc, s21_mul_449);
  tcase_add_test(tc, s21_mul_450);
  tcase_add_test(tc, s21_mul_451);
  tcase_add_test(tc, s21_mul_452);
  tcase_add_test(tc, s21_mul_453);
  tcase_add_test(tc, s21_mul_454);
  tcase_add_test(tc, s21_mul_455);
  tcase_add_test(tc, s21_mul_456);
  tcase_add_test(tc, s21_mul_457);
  tcase_add_test(tc, s21_mul_458);
  tcase_add_test(tc, s21_mul_459);
  tcase_add_test(tc, s21_mul_460);
  tcase_add_test(tc, s21_mul_461);
  tcase_add_test(tc, s21_mul_462);
  tcase_add_test(tc, s21_mul_463);
  tcase_add_test(tc, s21_mul_464);
  tcase_add_test(tc, s21_mul_465);
  tcase_add_test(tc, s21_mul_466);
  tcase_add_test(tc, s21_mul_467);
  tcase_add_test(tc, s21_mul_468);
  tcase_add_test(tc, s21_mul_469);
  tcase_add_test(tc, s21_mul_470);
  tcase_add_test(tc, s21_mul_471);
  tcase_add_test(tc, s21_mul_472);
  tcase_add_test(tc, s21_mul_473);
  tcase_add_test(tc, s21_mul_474);
  tcase_add_test(tc, s21_mul_475);
  tcase_add_test(tc, s21_mul_476);
  tcase_add_test(tc, s21_mul_477);
  tcase_add_test(tc, s21_mul_478);
  tcase_add_test(tc, s21_mul_479);
  tcase_add_test(tc, s21_mul_480);
  tcase_add_test(tc, s21_mul_481);
  tcase_add_test(tc, s21_mul_482);
  tcase_add_test(tc, s21_mul_483);
  tcase_add_test(tc, s21_mul_484);
  tcase_add_test(tc, s21_mul_486);
  tcase_add_test(tc, s21_mul_487);
  tcase_add_test(tc, s21_mul_488);
  tcase_add_test(tc, s21_mul_489);
  tcase_add_test(tc, s21_mul_490);
  tcase_add_test(tc, s21_mul_491);
  tcase_add_test(tc, s21_mul_492);
  tcase_add_test(tc, s21_mul_493);
  tcase_add_test(tc, s21_mul_494);
  tcase_add_test(tc, s21_mul_495);
  tcase_add_test(tc, s21_mul_496);
  tcase_add_test(tc, s21_mul_497);
  tcase_add_test(tc, s21_mul_498);
  tcase_add_test(tc, s21_mul_499);
  tcase_add_test(tc, s21_mul_500);
  tcase_add_test(tc, s21_mul_501);
  tcase_add_test(tc, fail_s21_mul_1);
  tcase_add_test(tc, fail_s21_mul_2);
  tcase_add_test(tc, fail_s21_mul_3);
  tcase_add_test(tc, fail_s21_mul_4);
  tcase_add_test(tc, fail_s21_mul_5);
  tcase_add_test(tc, fail_s21_mul_6);
  tcase_add_test(tc, fail_s21_mul_7);
  tcase_add_test(tc, fail_s21_mul_8);
  tcase_add_test(tc, fail_s21_mul_9);
  tcase_add_test(tc, fail_s21_mul_10);
  tcase_add_test(tc, fail_s21_mul_11);
  tcase_add_test(tc, fail_s21_mul_12);
  tcase_add_test(tc, fail_s21_mul_13);
  tcase_add_test(tc, fail_s21_mul_14);
  tcase_add_test(tc, fail_s21_mul_15);
  tcase_add_test(tc, fail_s21_mul_16);
  tcase_add_test(tc, fail_s21_mul_17);
  tcase_add_test(tc, fail_s21_mul_18);
  tcase_add_test(tc, fail_s21_mul_19);
  tcase_add_test(tc, fail_s21_mul_20);
  tcase_add_test(tc, fail_s21_mul_21);
  tcase_add_test(tc, fail_s21_mul_22);
  tcase_add_test(tc, fail_s21_mul_23);
  tcase_add_test(tc, fail_s21_mul_24);
  tcase_add_test(tc, fail_s21_mul_25);
  tcase_add_test(tc, fail_s21_mul_26);
  tcase_add_test(tc, fail_s21_mul_27);
  tcase_add_test(tc, fail_s21_mul_28);
  tcase_add_test(tc, fail_s21_mul_29);
  tcase_add_test(tc, fail_s21_mul_30);
  tcase_add_test(tc, fail_s21_mul_31);
  tcase_add_test(tc, fail_s21_mul_32);
  tcase_add_test(tc, fail_s21_mul_33);
  tcase_add_test(tc, fail_s21_mul_34);
  tcase_add_test(tc, fail_s21_mul_35);
  tcase_add_test(tc, fail_s21_mul_36);
  tcase_add_test(tc, fail_s21_mul_37);
  tcase_add_test(tc, fail_s21_mul_38);
  tcase_add_test(tc, fail_s21_mul_39);
  tcase_add_test(tc, fail_s21_mul_40);
  tcase_add_test(tc, fail_s21_mul_41);
  tcase_add_test(tc, fail_s21_mul_42);
  tcase_add_test(tc, fail_s21_mul_43);
  tcase_add_test(tc, fail_s21_mul_44);
  tcase_add_test(tc, fail_s21_mul_45);
  tcase_add_test(tc, fail_s21_mul_46);
  tcase_add_test(tc, fail_s21_mul_47);
  tcase_add_test(tc, fail_s21_mul_48);
  tcase_add_test(tc, fail_s21_mul_49);
  tcase_add_test(tc, fail_s21_mul_50);
  tcase_add_test(tc, fail_s21_mul_51);
  tcase_add_test(tc, fail_s21_mul_52);
  tcase_add_test(tc, fail_s21_mul_53);
  tcase_add_test(tc, fail_s21_mul_54);
  tcase_add_test(tc, fail_s21_mul_55);
  tcase_add_test(tc, fail_s21_mul_56);
  tcase_add_test(tc, fail_s21_mul_57);
  tcase_add_test(tc, fail_s21_mul_58);
  tcase_add_test(tc, fail_s21_mul_59);
  tcase_add_test(tc, fail_s21_mul_60);
  tcase_add_test(tc, fail_s21_mul_61);
  tcase_add_test(tc, fail_s21_mul_62);
  tcase_add_test(tc, fail_s21_mul_63);
  tcase_add_test(tc, fail_s21_mul_64);
  tcase_add_test(tc, fail_s21_mul_65);
  tcase_add_test(tc, fail_s21_mul_66);
  tcase_add_test(tc, fail_s21_mul_67);
  tcase_add_test(tc, fail_s21_mul_68);
  tcase_add_test(tc, fail_s21_mul_69);
  tcase_add_test(tc, fail_s21_mul_70);
  tcase_add_test(tc, fail_s21_mul_71);
  tcase_add_test(tc, fail_s21_mul_72);
  tcase_add_test(tc, fail_s21_mul_73);
  tcase_add_test(tc, fail_s21_mul_74);
  tcase_add_test(tc, fail_s21_mul_75);
  tcase_add_test(tc, fail_s21_mul_76);
  tcase_add_test(tc, fail_s21_mul_77);
  tcase_add_test(tc, fail_s21_mul_78);
  tcase_add_test(tc, fail_s21_mul_79);
  tcase_add_test(tc, fail_s21_mul_80);
  tcase_add_test(tc, fail_s21_mul_81);
  tcase_add_test(tc, fail_s21_mul_82);
  tcase_add_test(tc, fail_s21_mul_83);
  tcase_add_test(tc, fail_s21_mul_84);
  tcase_add_test(tc, fail_s21_mul_85);
  tcase_add_test(tc, fail_s21_mul_86);
  tcase_add_test(tc, fail_s21_mul_87);
  tcase_add_test(tc, fail_s21_mul_88);
  tcase_add_test(tc, fail_s21_mul_89);
  tcase_add_test(tc, fail_s21_mul_90);
  tcase_add_test(tc, fail_s21_mul_91);
  tcase_add_test(tc, fail_s21_mul_92);
  tcase_add_test(tc, fail_s21_mul_93);
  tcase_add_test(tc, fail_s21_mul_94);
  tcase_add_test(tc, fail_s21_mul_95);
  tcase_add_test(tc, fail_s21_mul_96);
  tcase_add_test(tc, fail_s21_mul_97);
  tcase_add_test(tc, fail_s21_mul_98);
  tcase_add_test(tc, fail_s21_mul_99);
  tcase_add_test(tc, fail_s21_mul_100);
  tcase_add_test(tc, fail_s21_mul_101);
  tcase_add_test(tc, fail_s21_mul_102);
  tcase_add_test(tc, fail_s21_mul_103);
  tcase_add_test(tc, fail_s21_mul_104);
  tcase_add_test(tc, fail_s21_mul_105);
  tcase_add_test(tc, fail_s21_mul_106);
  tcase_add_test(tc, fail_s21_mul_107);
  tcase_add_test(tc, fail_s21_mul_108);
  tcase_add_test(tc, fail_s21_mul_109);
  tcase_add_test(tc, fail_s21_mul_110);
  tcase_add_test(tc, fail_s21_mul_111);
  tcase_add_test(tc, fail_s21_mul_112);
  tcase_add_test(tc, fail_s21_mul_113);
  tcase_add_test(tc, fail_s21_mul_114);
  tcase_add_test(tc, fail_s21_mul_115);
  tcase_add_test(tc, fail_s21_mul_116);
  tcase_add_test(tc, fail_s21_mul_117);
  tcase_add_test(tc, fail_s21_mul_118);
  tcase_add_test(tc, fail_s21_mul_119);
  tcase_add_test(tc, fail_s21_mul_120);
  tcase_add_test(tc, fail_s21_mul_121);
  tcase_add_test(tc, fail_s21_mul_122);
  tcase_add_test(tc, fail_s21_mul_123);
  tcase_add_test(tc, fail_s21_mul_124);
  tcase_add_test(tc, fail_s21_mul_125);
  tcase_add_test(tc, fail_s21_mul_126);
  tcase_add_test(tc, fail_s21_mul_127);
  tcase_add_test(tc, fail_s21_mul_128);
  tcase_add_test(tc, fail_s21_mul_129);
  tcase_add_test(tc, fail_s21_mul_130);
  tcase_add_test(tc, fail_s21_mul_131);
  tcase_add_test(tc, fail_s21_mul_132);
  tcase_add_test(tc, fail_s21_mul_133);
  tcase_add_test(tc, fail_s21_mul_134);
  tcase_add_test(tc, fail_s21_mul_135);
  tcase_add_test(tc, fail_s21_mul_136);
  tcase_add_test(tc, fail_s21_mul_137);
  tcase_add_test(tc, fail_s21_mul_138);
  tcase_add_test(tc, fail_s21_mul_139);
  tcase_add_test(tc, fail_s21_mul_140);
  tcase_add_test(tc, fail_s21_mul_141);
  tcase_add_test(tc, fail_s21_mul_142);
  tcase_add_test(tc, fail_s21_mul_143);
  tcase_add_test(tc, fail_s21_mul_144);
  tcase_add_test(tc, fail_s21_mul_145);
  tcase_add_test(tc, fail_s21_mul_146);
  tcase_add_test(tc, fail_s21_mul_147);
  tcase_add_test(tc, fail_s21_mul_148);
  tcase_add_test(tc, fail_s21_mul_149);
  tcase_add_test(tc, fail_s21_mul_150);
  tcase_add_test(tc, fail_s21_mul_151);
  tcase_add_test(tc, fail_s21_mul_152);
  tcase_add_test(tc, fail_s21_mul_153);
  tcase_add_test(tc, fail_s21_mul_154);
  tcase_add_test(tc, fail_s21_mul_155);
  tcase_add_test(tc, fail_s21_mul_156);
  tcase_add_test(tc, fail_s21_mul_157);
  tcase_add_test(tc, fail_s21_mul_158);
  tcase_add_test(tc, fail_s21_mul_159);
  tcase_add_test(tc, fail_s21_mul_160);
  tcase_add_test(tc, fail_s21_mul_161);
  tcase_add_test(tc, fail_s21_mul_162);
  tcase_add_test(tc, fail_s21_mul_163);
  tcase_add_test(tc, fail_s21_mul_164);
  tcase_add_test(tc, fail_s21_mul_165);
  tcase_add_test(tc, fail_s21_mul_166);

  suite_add_tcase(c, tc);
  return c;
}
