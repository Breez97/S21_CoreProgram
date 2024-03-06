#include "../s21_tests.h"

START_TEST(invalid_dec_s21_add_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_add(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 4);
}

START_TEST(invalid_dec_s21_add_2) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_3) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_4) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_5) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_6) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_7) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_8) {
  // Все биты имеют максимальное значение
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_9) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_10) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_11) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_12) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_13) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_14) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_15) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_add_16) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_add(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_add_1) {
  // 9440524361.316307
  s21_decimal dec_1 = {{0x5d0cb7d3, 0x218a1b, 0x0, 0x60000}};
  // 6194722922405
  s21_decimal dec_2 = {{0x52425fa5, 0x5a2, 0x0, 0x0}};
  // 6204163446766.316307
  s21_decimal dec_check = {{0xa4f82b13, 0x56199dc8, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_2) {
  // 78390804338546
  s21_decimal dec_1 = {{0xc80bd772, 0x474b, 0x0, 0x0}};
  // -2717549.9076069392956
  s21_decimal dec_2 = {{0x7f12823c, 0x7922c46d, 0x1, 0x800d0000}};
  // 78390801620996.0923930607044
  s21_decimal dec_check = {{0x9458bdc4, 0xb5ce7e34, 0x2886efa, 0xd0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_3) {
  // 10001082.4898741553862
  s21_decimal dec_1 = {{0x87484ac6, 0x6bedd35d, 0x5, 0xd0000}};
  // 4699069512.6532576
  s21_decimal dec_2 = {{0xcac401e0, 0xa6f1c9, 0x0, 0x70000}};
  // 4709070595.1431317553862
  s21_decimal dec_check = {{0xdce482c6, 0xcad32d92, 0x9f8, 0xd0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_4) {
  // -4609.61882398
  s21_decimal dec_1 = {{0x5378211e, 0x6b, 0x0, 0x80080000}};
  // -5498450323192940.38360125
  s21_decimal dec_2 = {{0xfac0403d, 0x28af8a8f, 0x746f, 0x80080000}};
  // -5498450323197550.00242523
  s21_decimal dec_check = {{0x4e38615b, 0x28af8afb, 0x746f, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_5) {
  // -30
  s21_decimal dec_1 = {{0x1e, 0x0, 0x0, 0x80000000}};
  // 998366366
  s21_decimal dec_2 = {{0x3b81dc9e, 0x0, 0x0, 0x0}};
  // 998366336
  s21_decimal dec_check = {{0x3b81dc80, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_6) {
  // 910572167.1302824814854724541
  s21_decimal dec_1 = {{0x7f52dbbd, 0xe75bb457, 0x1d6c1390, 0x130000}};
  // 99.8719568221
  s21_decimal dec_2 = {{0x8853395d, 0xe8, 0x0, 0xa0000}};
  // 910572267.0022393035854724541
  s21_decimal dec_check = {{0x1b883dbd, 0xb606032, 0x1d6c13c7, 0x130000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_7) {
  // -59409669897336923959
  s21_decimal dec_1 = {{0x75fc2737, 0x38798c01, 0x3, 0x80000000}};
  // -533741792044737830747216
  s21_decimal dec_2 = {{0x24327c50, 0x33558b7a, 0x7106, 0x80000000}};
  // -533801201714635167671175
  s21_decimal dec_check = {{0x9a2ea387, 0x6bcf177b, 0x7109, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_8) {
  // 725711224845
  s21_decimal dec_1 = {{0xf7c2800d, 0xa8, 0x0, 0x0}};
  // 24651041411404046366
  s21_decimal dec_2 = {{0x8e2ea01e, 0x561a178e, 0x1, 0x0}};
  // 24651042137115271211
  s21_decimal dec_check = {{0x85f1202b, 0x561a1837, 0x1, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_9) {
  // -928892936741739639.17516999
  s21_decimal dec_1 = {{0x7f32e0c7, 0xb33a5acc, 0x4cd612, 0x80080000}};
  // -424456233313739265875753241
  s21_decimal dec_2 = {{0xc5a1b919, 0x83a1dbbd, 0x15f1a1a, 0x80000000}};
  // -424456234242632202617492880.18
  s21_decimal dec_check = {{0xe9406c52, 0x7452e693, 0x89263260, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_10) {
  // 9151.27967813
  s21_decimal dec_1 = {{0x11e0a045, 0xd5, 0x0, 0x80000}};
  // 75125637214717
  s21_decimal dec_2 = {{0x8ceb71fd, 0x4453, 0x0, 0x0}};
  // 75125637223868.27967813
  s21_decimal dec_check = {{0x930fd45, 0x41c3e63e, 0x197, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_11) {
  // -464968893056613269102191
  s21_decimal dec_1 = {{0x8a57de6f, 0x3a29436, 0x6276, 0x80000000}};
  // -0.2764766
  s21_decimal dec_2 = {{0x2a2fde, 0x0, 0x0, 0x80070000}};
  // -464968893056613269102191.27648
  s21_decimal dec_check = {{0x53c88b60, 0xf367b8d8, 0x963d534b, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_13) {
  // -3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x80000000}};
  // 426478641923447886
  s21_decimal dec_2 = {{0xb4235c4e, 0x5eb2810, 0x0, 0x0}};
  // 426478641923447883
  s21_decimal dec_check = {{0xb4235c4b, 0x5eb2810, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_14) {
  // -32122.1840030354487883767755
  s21_decimal dec_1 = {{0x44e69fcb, 0xd72d4e84, 0x109b55e, 0x80160000}};
  // -6.49
  s21_decimal dec_2 = {{0x289, 0x0, 0x0, 0x80020000}};
  // -32128.6740030354487883767755
  s21_decimal dec_check = {{0x68769fcb, 0x139b0f94, 0x109c31d, 0x80160000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_15) {
  // 8.0753098965192
  s21_decimal dec_1 = {{0xcbc740c8, 0x4971, 0x0, 0xd0000}};
  // 5964643136576457305223441974
  s21_decimal dec_2 = {{0x4f05ae36, 0x56beb44f, 0x1345d650, 0x0}};
  // 5964643136576457305223441982.1
  s21_decimal dec_check = {{0x1638ce6d, 0x63730b19, 0xc0ba5f23, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_16) {
  // 827164508579419725
  s21_decimal dec_1 = {{0xf0afd64d, 0xb7aadbc, 0x0, 0x0}};
  // 446445183
  s21_decimal dec_2 = {{0x1a9c367f, 0x0, 0x0, 0x0}};
  // 827164509025864908
  s21_decimal dec_check = {{0xb4c0ccc, 0xb7aadbd, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_17) {
  // 68037386151.30795
  s21_decimal dec_1 = {{0xd74caaab, 0x182bf6, 0x0, 0x50000}};
  // 344522374.351544742845
  s21_decimal dec_2 = {{0x6df973bd, 0xad355a1d, 0x12, 0xc0000}};
  // 68381908525.659494742845
  s21_decimal dec_check = {{0x55d6fb3d, 0xfd9dcd35, 0xe7a, 0xc0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_18) {
  // -4.3041893208426848847
  s21_decimal dec_1 = {{0xcc94a24f, 0x555385d3, 0x2, 0x80130000}};
  // 3131806.1655
  s21_decimal dec_2 = {{0x4ab3b257, 0x7, 0x0, 0x40000}};
  // 3131801.8613106791573151153
  s21_decimal dec_check = {{0xb7e0ddb1, 0x30dfb693, 0x19e7d9, 0x130000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_19) {
  // 458679863619888.962491130
  s21_decimal dec_1 = {{0xe30e52fa, 0x15d1ac37, 0x6121, 0x90000}};
  // -855396474.604385660054
  s21_decimal dec_2 = {{0x63daec96, 0x5f02c191, 0x2e, 0x800c0000}};
  // 458679008223414.358105469946
  s21_decimal dec_check = {{0x8c1933fa, 0xdc05f8bd, 0x17b690e, 0xc0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_20) {
  // -66560783809539135676
  s21_decimal dec_1 = {{0x7b26d8bc, 0x9bb76838, 0x3, 0x80000000}};
  // 3.13
  s21_decimal dec_2 = {{0x139, 0x0, 0x0, 0x20000}};
  // -66560783809539135672.87
  s21_decimal dec_check = {{0x1b2ca837, 0xd3a4b610, 0x168, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_21) {
  // 64500514217195523.20009371
  s21_decimal dec_1 = {{0x430af49b, 0xfcfae8e0, 0x555d9, 0x80000}};
  // -4313638879.22098
  s21_decimal dec_2 = {{0xbb4efbb2, 0x18852, 0x0, 0x80050000}};
  // 64500509903556643.97911371
  s21_decimal dec_check = {{0x9683c54b, 0xf6fe65b4, 0x555d9, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_22) {
  // 12999827646233961.821
  s21_decimal dec_1 = {{0x4313e55d, 0xb468aa5e, 0x0, 0x30000}};
  // -9984767696750208
  s21_decimal dec_2 = {{0xe3bac680, 0x237917, 0x0, 0x80000000}};
  // 3015059949483753.821
  s21_decimal dec_check = {{0xb17c815d, 0x29d7a50c, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_23) {
  // -6125477566208673729
  s21_decimal dec_1 = {{0x6d7e07c1, 0x55021164, 0x0, 0x80000000}};
  // -1061167300038
  s21_decimal dec_2 = {{0x127ffdc6, 0xf7, 0x0, 0x80000000}};
  // -6125478627375973767
  s21_decimal dec_check = {{0x7ffe0587, 0x5502125b, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_24) {
  // 2680543620947535598
  s21_decimal dec_1 = {{0x9b8466ee, 0x25333438, 0x0, 0x0}};
  // 6916617969.480402868886417231
  s21_decimal dec_2 = {{0xda31af4f, 0x702a5f78, 0x16594ad3, 0x120000}};
  // 2680543627864153567.4804028689
  s21_decimal dec_check = {{0xdb874511, 0x62e0facd, 0x569cefec, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_25) {
  // 977806
  s21_decimal dec_1 = {{0xeeb8e, 0x0, 0x0, 0x0}};
  // 0.8663914334653972238506
  s21_decimal dec_2 = {{0x78d450aa, 0xabf6f7fb, 0x1d5, 0x160000}};
  // 977806.8663914334653972238506
  s21_decimal dec_check = {{0x185450aa, 0x680afeab, 0x1f983a94, 0x160000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_26) {
  // -39238472968.59108173489244
  s21_decimal dec_1 = {{0x9cc1245c, 0x302d1362, 0x33ee8, 0x800e0000}};
  // -131630
  s21_decimal dec_2 = {{0x2022e, 0x0, 0x0, 0x80000000}};
  // -39238604598.59108173489244
  s21_decimal dec_check = {{0x738a45c, 0xe6d97225, 0x33ee8, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_28) {
  // -1009
  s21_decimal dec_1 = {{0x3f1, 0x0, 0x0, 0x80000000}};
  // -8026394145536.0
  s21_decimal dec_2 = {{0xe7b7fe00, 0x48ff, 0x0, 0x80010000}};
  // -8026394146545.0
  s21_decimal dec_check = {{0xe7b8256a, 0x48ff, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_29) {
  // -28340.85868728857
  s21_decimal dec_1 = {{0x977f219, 0xa1196, 0x0, 0x800b0000}};
  // 5.106606
  s21_decimal dec_2 = {{0x4debae, 0x0, 0x0, 0x60000}};
  // -28335.75208128857
  s21_decimal dec_check = {{0x23b99159, 0xa111f, 0x0, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_30) {
  // 356452287562432364
  s21_decimal dec_1 = {{0x8b88bf6c, 0x4f25f77, 0x0, 0x0}};
  // 1375667.247
  s21_decimal dec_2 = {{0x51ff042f, 0x0, 0x0, 0x30000}};
  // 356452287563808031.247
  s21_decimal dec_check = {{0x602ac20f, 0x52c4eaf9, 0x13, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_31) {
  // -63
  s21_decimal dec_1 = {{0x3f, 0x0, 0x0, 0x80000000}};
  // 96157.10580
  s21_decimal dec_2 = {{0x3d241974, 0x2, 0x0, 0x50000}};
  // 96094.10580
  s21_decimal dec_check = {{0x3cc3f814, 0x2, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_32) {
  // 8505551148258481997
  s21_decimal dec_1 = {{0x7adcd74d, 0x7609c9b4, 0x0, 0x0}};
  // -57208326660332568
  s21_decimal dec_2 = {{0x84c89c18, 0xcb3eab, 0x0, 0x80000000}};
  // 8448342821598149429
  s21_decimal dec_check = {{0xf6143b35, 0x753e8b08, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_33) {
  // 4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x0}};
  // -7053716334357816118455
  s21_decimal dec_2 = {{0x581d8cb7, 0x61fa81e8, 0x17e, 0x80000000}};
  // -7053716334357816118451
  s21_decimal dec_check = {{0x581d8cb3, 0x61fa81e8, 0x17e, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_34) {
  // -3662128518178
  s21_decimal dec_1 = {{0xa7de9422, 0x354, 0x0, 0x80000000}};
  // -0.7638894260340034999699947364
  s21_decimal dec_2 = {{0xe2a0bf64, 0x9f54ad5e, 0x18aebec7, 0x801c0000}};
  // -3662128518178.7638894260340035
  s21_decimal dec_check = {{0x167f4543, 0xaa4f08b5, 0x76546ac7, 0x80100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_35) {
  // 8.8610233007585475699
  s21_decimal dec_1 = {{0x79b9bc73, 0xcdb6c971, 0x4, 0x130000}};
  // -430817938582559719613484.487
  s21_decimal dec_2 = {{0xbb0b4dc7, 0x3f72e4dd, 0x1645d3f, 0x80030000}};
  // -430817938582559719613475.62598
  s21_decimal dec_check = {{0x105cdc66, 0xc8e1669d, 0x8b346cb4, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_36) {
  // -8735977713953092
  s21_decimal dec_1 = {{0x5067e944, 0x1f0953, 0x0, 0x80000000}};
  // -67347576801552
  s21_decimal dec_2 = {{0x94644910, 0x3d40, 0x0, 0x80000000}};
  // -8803325290754644
  s21_decimal dec_check = {{0xe4cc3254, 0x1f4693, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_37) {
  // -5.647
  s21_decimal dec_1 = {{0x160f, 0x0, 0x0, 0x80030000}};
  // 11834
  s21_decimal dec_2 = {{0x2e3a, 0x0, 0x0, 0x0}};
  // 11828.353
  s21_decimal dec_check = {{0xb47c81, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_38) {
  // -14553591212152023884950492
  s21_decimal dec_1 = {{0x6b86ebdc, 0xc2af1550, 0xc09d7, 0x80000000}};
  // -0.732150535826719816
  s21_decimal dec_2 = {{0x82104448, 0xa291f08, 0x0, 0x80120000}};
  // -14553591212152023884950492.732
  s21_decimal dec_check = {{0x709563c, 0x7beb4224, 0x2f0672d0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_39) {
  // 53199
  s21_decimal dec_1 = {{0xcfcf, 0x0, 0x0, 0x0}};
  // -122956073218344654009988
  s21_decimal dec_2 = {{0x81d4f684, 0x764b36e3, 0x1a09, 0x80000000}};
  // -122956073218344653956789
  s21_decimal dec_check = {{0x81d426b5, 0x764b36e3, 0x1a09, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_40) {
  // 61424980628036
  s21_decimal dec_1 = {{0x9e269244, 0x37dd, 0x0, 0x0}};
  // 37670432310321.194410
  s21_decimal dec_2 = {{0x8817a5aa, 0xac84299, 0x2, 0x60000}};
  // 99095412938357.194410
  s21_decimal dec_check = {{0x956dbeaa, 0x5f39a109, 0x5, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_41) {
  // 156932801937995054566554.6
  s21_decimal dec_1 = {{0x46c9fe0a, 0x7140f9de, 0x14c51, 0x10000}};
  // 65557624154399335280684886803
  s21_decimal dec_2 = {{0xfca8eb13, 0x8f34a431, 0xd3d3fee6, 0x0}};
  // 65557781087201273275739453358
  s21_decimal dec_check = {{0x9d56b7ae, 0xe754bd2e, 0xd3d42021, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_42) {
  // 743741.44249
  s21_decimal dec_1 = {{0x510b60f9, 0x11, 0x0, 0x50000}};
  // 7.0713058821488443
  s21_decimal dec_2 = {{0x93f3b, 0xfb3927, 0x0, 0x100000}};
  // 743748.5137958821488443
  s21_decimal dec_check = {{0xab0e73b, 0x2fd72f7d, 0x193, 0x100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_43) {
  // 75.013766388
  s21_decimal dec_1 = {{0x772b3cf4, 0x11, 0x0, 0x90000}};
  // 736695055
  s21_decimal dec_2 = {{0x2be9130f, 0x0, 0x0, 0x0}};
  // 736695130.013766388
  s21_decimal dec_check = {{0x4c3b12f4, 0xa394451, 0x0, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_44) {
  // 2441900474890658429343282
  s21_decimal dec_1 = {{0xea051632, 0xb0a369d9, 0x20517, 0x0}};
  // -75522
  s21_decimal dec_2 = {{0x12702, 0x0, 0x0, 0x80000000}};
  // 2441900474890658429267760
  s21_decimal dec_check = {{0xea03ef30, 0xb0a369d9, 0x20517, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_45) {
  // -168916064589
  s21_decimal dec_1 = {{0x542e994d, 0x27, 0x0, 0x80000000}};
  // 7464099296
  s21_decimal dec_2 = {{0xbce51de0, 0x1, 0x0, 0x0}};
  // -161451965293
  s21_decimal dec_check = {{0x97497b6d, 0x25, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_46) {
  // 3971033143868383813658
  s21_decimal dec_1 = {{0xb9abe01a, 0x4527c4e9, 0xd7, 0x0}};
  // 9520402140.250773740
  s21_decimal dec_2 = {{0x288418ec, 0x841f434e, 0x0, 0x90000}};
  // 3971033143877904215798.2507737
  s21_decimal dec_check = {{0x2f91e2d9, 0xcd5be142, 0x804f9dc4, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_47) {
  // 615.552458
  s21_decimal dec_1 = {{0x24b095ca, 0x0, 0x0, 0x60000}};
  // 761827661798
  s21_decimal dec_2 = {{0x607797e6, 0xb1, 0x0, 0x0}};
  // 761827662413.552458
  s21_decimal dec_check = {{0xfe39db4a, 0xa928e38, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_48) {
  // -11
  s21_decimal dec_1 = {{0xb, 0x0, 0x0, 0x80000000}};
  // -6103258303864724
  s21_decimal dec_2 = {{0x8f2c9f94, 0x15aee1, 0x0, 0x80000000}};
  // -6103258303864735
  s21_decimal dec_check = {{0x8f2c9f9f, 0x15aee1, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_50) {
  // -92170.97977598
  s21_decimal dec_1 = {{0x5d9cefe, 0x862, 0x0, 0x80080000}};
  // -50642135
  s21_decimal dec_2 = {{0x304bcd7, 0x0, 0x0, 0x80000000}};
  // -50734305.97977598
  s21_decimal dec_check = {{0x1c95c5fe, 0x120642, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_51) {
  // 6876635564700566778852502
  s21_decimal dec_1 = {{0x35dcb496, 0x2932d674, 0x5b02f, 0x0}};
  // 8439.813
  s21_decimal dec_2 = {{0x80c805, 0x0, 0x0, 0x30000}};
  // 6876635564700566778860941.813
  s21_decimal dec_check = {{0x66a231f5, 0xee95b5f2, 0x16383838, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_52) {
  // 80057795332.8977689486
  s21_decimal dec_1 = {{0xaef83b8e, 0x66403ee8, 0x2b, 0xa0000}};
  // -5003600247296678078
  s21_decimal dec_2 = {{0x2a2cd8be, 0x45705bea, 0x0, 0x80000000}};
  // -5003600167238882745.1022310514
  s21_decimal dec_check = {{0xea3afc72, 0xc8dc872e, 0xa1accf7d, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_53) {
  // 7570
  s21_decimal dec_1 = {{0x1d92, 0x0, 0x0, 0x0}};
  // 85999631078467047896.2006268
  s21_decimal dec_2 = {{0xc0dc18fc, 0x6c92aa62, 0x2c75f4d, 0x70000}};
  // 85999631078467055466.2006268
  s21_decimal dec_check = {{0x60ee6dfc, 0x6c92aa74, 0x2c75f4d, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_54) {
  // 32.38403
  s21_decimal dec_1 = {{0x316a03, 0x0, 0x0, 0x50000}};
  // -72337723.115
  s21_decimal dec_2 = {{0xd7aa0eeb, 0x10, 0x0, 0x80030000}};
  // -72337690.73097
  s21_decimal dec_check = {{0x3e3c69c9, 0x694, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_56) {
  // 761369050124217229983061
  s21_decimal dec_1 = {{0xd3673d55, 0xe61efddc, 0xa139, 0x0}};
  // 657481.1622188429247839482552
  s21_decimal dec_2 = {{0x769c32b8, 0x391557fc, 0x153e8e84, 0x160000}};
  // 761369050124217230640542.16222
  s21_decimal dec_check = {{0xb6da761e, 0xa1d1422, 0xf602f8c3, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_57) {
  // 651883
  s21_decimal dec_1 = {{0x9f26b, 0x0, 0x0, 0x0}};
  // 0.7368383688705656826
  s21_decimal dec_2 = {{0xee1547fa, 0x6641c1ec, 0x0, 0x130000}};
  // 651883.7368383688705656826
  s21_decimal dec_check = {{0xe20d47fa, 0xe1c08857, 0x5646a, 0x130000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_58) {
  // -6.330
  s21_decimal dec_1 = {{0x18ba, 0x0, 0x0, 0x80030000}};
  // 98011892959731
  s21_decimal dec_2 = {{0x2c1049f3, 0x5924, 0x0, 0x0}};
  // 98011892959724.670
  s21_decimal dec_check = {{0x1fa0c47e, 0x15c354c, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_59) {
  // -2.67648148889986
  s21_decimal dec_1 = {{0xb0d6e182, 0xf36c, 0x0, 0x800e0000}};
  // -9481
  s21_decimal dec_2 = {{0x2509, 0x0, 0x0, 0x80000000}};
  // -9483.67648148889986
  s21_decimal dec_check = {{0xf0632182, 0xd294759, 0x0, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_61) {
  // 0.296860548734837100749493
  s21_decimal dec_1 = {{0xe35a2b5, 0xd7b42fbd, 0x3edc, 0x180000}};
  // -58289.8685799928998335
  s21_decimal dec_2 = {{0xcacca9bf, 0x99582267, 0x1f, 0x80100000}};
  // -58289.571719444164996399250507
  s21_decimal dec_check = {{0x1c63c4b, 0x92d41eb0, 0xbc5800ee, 0x80180000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_62) {
  // -8195848
  s21_decimal dec_1 = {{0x7d0f08, 0x0, 0x0, 0x80000000}};
  // 467370
  s21_decimal dec_2 = {{0x721aa, 0x0, 0x0, 0x0}};
  // -7728478
  s21_decimal dec_check = {{0x75ed5e, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_63) {
  // -68188548233476734633248.8370
  s21_decimal dec_1 = {{0xcaf452b2, 0x1112348d, 0x2340ade, 0x80040000}};
  // 356053861411871.22534
  s21_decimal dec_2 = {{0xcc132566, 0xee1fbe0c, 0x1, 0x50000}};
  // -68188547877422873221377.61166
  s21_decimal dec_check = {{0x2178158e, 0xbc964f7d, 0x16086caa, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_64) {
  // 94010986423725.88427
  s21_decimal dec_1 = {{0xf506738b, 0x82776967, 0x0, 0x50000}};
  // -6766574988488412.4458234
  s21_decimal dec_2 = {{0x53505cfa, 0x2aeb33cb, 0xe54, 0x80070000}};
  // -6672564002064686.5615534
  s21_decimal dec_check = {{0x9ccb3aae, 0x3446072f, 0xe21, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_65) {
  // 355772512991865
  s21_decimal dec_1 = {{0xbe41fa79, 0x14392, 0x0, 0x0}};
  // -447849.99819
  s21_decimal dec_2 = {{0x6d64dd8b, 0xa, 0x0, 0x80050000}};
  // 355772512544015.00181
  s21_decimal dec_check = {{0xff6c0415, 0xedbbc984, 0x1, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_66) {
  // -38691748.2
  s21_decimal dec_1 = {{0x170fe46a, 0x0, 0x0, 0x80010000}};
  // 0.43
  s21_decimal dec_2 = {{0x2b, 0x0, 0x0, 0x20000}};
  // -38691747.77
  s21_decimal dec_check = {{0xe69eebf9, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_67) {
  // -1685
  s21_decimal dec_1 = {{0x695, 0x0, 0x0, 0x80000000}};
  // -15629306479597923741145
  s21_decimal dec_2 = {{0x613a2dd9, 0x4432eb94, 0x34f, 0x80000000}};
  // -15629306479597923742830
  s21_decimal dec_check = {{0x613a346e, 0x4432eb94, 0x34f, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_68) {
  // 66623173548982195656
  s21_decimal dec_1 = {{0xac48d5c8, 0x9c950f5b, 0x3, 0x0}};
  // 69830.434980921058246791207164
  s21_decimal dec_2 = {{0x2d7f18fc, 0x989b3da3, 0xe1a261c9, 0x180000}};
  // 66623173548982265486.434980921
  s21_decimal dec_check = {{0xd5455439, 0xfbf90289, 0xd74565c2, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_69) {
  // 0.7694
  s21_decimal dec_1 = {{0x1e0e, 0x0, 0x0, 0x40000}};
  // 489144871473486273982580.81301
  s21_decimal dec_2 = {{0x7af03e15, 0x8ef8c32d, 0x9e0d1d8d, 0x50000}};
  // 489144871473486273982581.58241
  s21_decimal dec_check = {{0x7af16aa1, 0x8ef8c32d, 0x9e0d1d8d, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_70) {
  // -3751633590
  s21_decimal dec_1 = {{0xdf9d62b6, 0x0, 0x0, 0x80000000}};
  // 26293710.546
  s21_decimal dec_2 = {{0x1f3a2ed2, 0x6, 0x0, 0x30000}};
  // -3725339879.454
  s21_decimal dec_check = {{0x5f8f681e, 0x363, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_71) {
  // 2249326
  s21_decimal dec_1 = {{0x22526e, 0x0, 0x0, 0x0}};
  // 237205610178
  s21_decimal dec_2 = {{0x3a8e5ec2, 0x37, 0x0, 0x0}};
  // 237207859504
  s21_decimal dec_check = {{0x3ab0b130, 0x37, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_72) {
  // 498537.83310981
  s21_decimal dec_1 = {{0x7d0b8285, 0x2d57, 0x0, 0x80000}};
  // -6683119274149
  s21_decimal dec_2 = {{0x8f348a5, 0x614, 0x0, 0x80000000}};
  // -6683118775611.16689019
  s21_decimal dec_check = {{0x14b6827b, 0x3ab0bfc6, 0x24, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_73) {
  // 391968037237079276
  s21_decimal dec_1 = {{0x66d2bcec, 0x5708cda, 0x0, 0x0}};
  // -46017
  s21_decimal dec_2 = {{0xb3c1, 0x0, 0x0, 0x80000000}};
  // 391968037237033259
  s21_decimal dec_check = {{0x66d2092b, 0x5708cda, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_74) {
  // -8.36430334616129
  s21_decimal dec_1 = {{0x9cf96241, 0x2f8ba, 0x0, 0x800e0000}};
  // -64954875550280261847233475
  s21_decimal dec_2 = {{0x915c33c3, 0xdbf843d0, 0x35baba, 0x80000000}};
  // -64954875550280261847233483.364
  s21_decimal dec_check = {{0xd02a5264, 0x41c8e6b7, 0xd1e169eb, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_75) {
  // -47.371429731839005223377
  s21_decimal dec_1 = {{0x21e0e9d1, 0x2a66484, 0xa08, 0x80150000}};
  // 9499426
  s21_decimal dec_2 = {{0x90f322, 0x0, 0x0, 0x0}};
  // 9499378.628570268160994776623
  s21_decimal dec_check = {{0x4f5f162f, 0x5162bc15, 0x1eb1b3ab, 0x150000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_76) {
  // -0.355
  s21_decimal dec_1 = {{0x163, 0x0, 0x0, 0x80030000}};
  // 0.737986
  s21_decimal dec_2 = {{0xb42c2, 0x0, 0x0, 0x60000}};
  // 0.382986
  s21_decimal dec_check = {{0x5d80a, 0x0, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_77) {
  // -5982830
  s21_decimal dec_1 = {{0x5b4a6e, 0x0, 0x0, 0x80000000}};
  // -87505365320331205563995
  s21_decimal dec_2 = {{0xb760565b, 0xace4578b, 0x1287, 0x80000000}};
  // -87505365320331211546825
  s21_decimal dec_check = {{0xb7bba0c9, 0xace4578b, 0x1287, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_78) {
  // -910.4369
  s21_decimal dec_1 = {{0x8aebf1, 0x0, 0x0, 0x80040000}};
  // 9403972831
  s21_decimal dec_2 = {{0x30853cdf, 0x2, 0x0, 0x0}};
  // 9403971920.5631
  s21_decimal dec_check = {{0x540edaff, 0x5587, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_79) {
  // 125
  s21_decimal dec_1 = {{0x7d, 0x0, 0x0, 0x0}};
  // 217483077356915.3327
  s21_decimal dec_2 = {{0xd92d692f, 0x1e2e8d10, 0x0, 0x40000}};
  // 217483077357040.3327
  s21_decimal dec_check = {{0xd9407bff, 0x1e2e8d10, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_80) {
  // -988941048251980734594582005
  s21_decimal dec_1 = {{0xb0a085f5, 0xa6141e40, 0x3320869, 0x80000000}};
  // 58516829405058
  s21_decimal dec_2 = {{0x82d47f82, 0x3538, 0x0, 0x0}};
  // -988941048251922217765176947
  s21_decimal dec_check = {{0x2dcc0673, 0xa613e908, 0x3320869, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_81) {
  // 384220.148752858027853763535
  s21_decimal dec_1 = {{0xcbd653cf, 0xffe10abc, 0x13dd1c7, 0x150000}};
  // 0.39146591994224
  s21_decimal dec_2 = {{0x86b5c170, 0x239a, 0x0, 0xe0000}};
  // 384220.540218777970093763535
  s21_decimal dec_check = {{0x808eabcf, 0x388f5ed9, 0x13dd1dd, 0x150000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_82) {
  // 5314854361119305462831237504
  s21_decimal dec_1 = {{0x6b95c980, 0x3d0d0dc3, 0x112c5830, 0x0}};
  // 0.1507541890482627540511294
  s21_decimal dec_2 = {{0x9b696a3e, 0x277aeb1, 0x13f3c, 0x190000}};
  // 5314854361119305462831237504.2
  s21_decimal dec_check = {{0x33d9df02, 0x628289a2, 0xabbb71e2, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_83) {
  // -613796688260994900864725490
  s21_decimal dec_1 = {{0x5d7af1f2, 0x24d3488f, 0x1fbb881, 0x80000000}};
  // 899662088728976.04
  s21_decimal dec_2 = {{0x51a85c44, 0x13f9fca, 0x0, 0x20000}};
  // -613796688260095238775996513.96
  s21_decimal dec_check = {{0x325e2644, 0x6148b836, 0xc6541272, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_84) {
  // -5728898.67206281
  s21_decimal dec_1 = {{0x5107be89, 0x2090a, 0x0, 0x80080000}};
  // -178.457
  s21_decimal dec_2 = {{0x2b919, 0x0, 0x0, 0x80030000}};
  // -5729077.12906281
  s21_decimal dec_check = {{0x78b78429, 0x2090e, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_85) {
  // 85188
  s21_decimal dec_1 = {{0x14cc4, 0x0, 0x0, 0x0}};
  // 68077492975327196151
  s21_decimal dec_2 = {{0xc98733f7, 0xb0c3d72b, 0x3, 0x0}};
  // 68077492975327281339
  s21_decimal dec_check = {{0xc98880bb, 0xb0c3d72b, 0x3, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_86) {
  // -657
  s21_decimal dec_1 = {{0x291, 0x0, 0x0, 0x80000000}};
  // 91464528566810164916
  s21_decimal dec_2 = {{0xb549beb4, 0xf5534821, 0x4, 0x0}};
  // 91464528566810164259
  s21_decimal dec_check = {{0xb549bc23, 0xf5534821, 0x4, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_87) {
  // -7981212709807747
  s21_decimal dec_1 = {{0xe471e683, 0x1c5ade, 0x0, 0x80000000}};
  // 390403693694836049284950
  s21_decimal dec_2 = {{0xd7698f56, 0xd39ed808, 0x52ab, 0x0}};
  // 390403685713623339477203
  s21_decimal dec_check = {{0xf2f7a8d3, 0xd3827d29, 0x52ab, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_88) {
  // -28920026004352676415654
  s21_decimal dec_1 = {{0x14c448a6, 0xc1fbfa18, 0x61f, 0x80000000}};
  // 27587214132286010.24
  s21_decimal dec_2 = {{0x4dc11ec0, 0x2648f282, 0x0, 0x20000}};
  // -28919998417138544129643.76
  s21_decimal dec_check = {{0xceeb4218, 0xa024bee5, 0x26467, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_89) {
  // -73799320.982
  s21_decimal dec_1 = {{0x2ec84596, 0x11, 0x0, 0x80030000}};
  // 9461
  s21_decimal dec_2 = {{0x24f5, 0x0, 0x0, 0x0}};
  // -73789859.982
  s21_decimal dec_check = {{0x2e37e88e, 0x11, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_90) {
  // 32679145108.196974326786
  s21_decimal dec_1 = {{0xb4e2f402, 0x8a3dd65f, 0x6eb, 0xc0000}};
  // 471.982113000
  s21_decimal dec_2 = {{0xe45380e8, 0x6d, 0x0, 0x90000}};
  // 32679145580.179087326786
  s21_decimal dec_check = {{0x9b127e42, 0x8a3f83a3, 0x6eb, 0xc0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_91) {
  // -34.62191576418339
  s21_decimal dec_1 = {{0x4b0e8823, 0xc4cd8, 0x0, 0x800e0000}};
  // -20
  s21_decimal dec_2 = {{0x14, 0x0, 0x0, 0x80000000}};
  // -54.62191576418339
  s21_decimal dec_check = {{0x949b8823, 0x1367d5, 0x0, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_92) {
  // 181691304351341.94569
  s21_decimal dec_1 = {{0xd7e98389, 0xfc25b7dd, 0x0, 0x50000}};
  // -8714.805375637044523650645
  s21_decimal dec_2 = {{0x2b034e55, 0x8bca1c20, 0x7356e, 0x80150000}};
  // 181691304342627.14031436295548
  s21_decimal dec_check = {{0x770d6d7c, 0x7333a139, 0x3ab52706, 0xe0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_93) {
  // 5281182311692.468549900
  s21_decimal dec_1 = {{0xc9e0f90c, 0x4b20a394, 0x11e, 0x90000}};
  // -79
  s21_decimal dec_2 = {{0x4f, 0x0, 0x0, 0x80000000}};
  // 5281182311613.468549900
  s21_decimal dec_check = {{0x651ca30c, 0x4b20a382, 0x11e, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_94) {
  // -3397.55918286039834927063
  s21_decimal dec_1 = {{0x305b9fd7, 0x348a5926, 0x47f2, 0x80140000}};
  // -41.83476
  s21_decimal dec_2 = {{0x3fd5b4, 0x0, 0x0, 0x80050000}};
  // -3439.39394286039834927063
  s21_decimal dec_check = {{0xb46d9fd7, 0xfdeec224, 0x48d4, 0x80140000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_95) {
  // -821.96215289501103858
  s21_decimal dec_1 = {{0xc43eb6f2, 0x74b39e4f, 0x4, 0x80110000}};
  // 346998668833162.28691
  s21_decimal dec_2 = {{0x2567a253, 0xe18eb115, 0x1, 0x50000}};
  // 346998668832340.32475710498896
  s21_decimal dec_check = {{0xd6cd2850, 0xfcee0d3e, 0x701f0ea0, 0xe0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_96) {
  // -5567482024978789995.39329778
  s21_decimal dec_1 = {{0x29132af2, 0x88a5ce52, 0x1cc8804, 0x80080000}};
  // -340309943926
  s21_decimal dec_2 = {{0x3c0da676, 0x4f, 0x0, 0x80000000}};
  // -5567482365288733921.39329778
  s21_decimal dec_check = {{0xc54ee0f2, 0x60ec2f6a, 0x1cc8806, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_97) {
  // -0.7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x80010000}};
  // 871
  s21_decimal dec_2 = {{0x367, 0x0, 0x0, 0x0}};
  // 870.3
  s21_decimal dec_check = {{0x21ff, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_98) {
  // -780771737646532743868409
  s21_decimal dec_1 = {{0x73ab2ff9, 0xb8805b90, 0xa555, 0x80000000}};
  // -250205.5619097081
  s21_decimal dec_2 = {{0x386271f9, 0x8e39b, 0x0, 0x800a0000}};
  // -780771737646532744118614.56191
  s21_decimal dec_check = {{0xe96ab53f, 0xdbb74a84, 0xfc47eca6, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_99) {
  // -39115877068376.9655384366143
  s21_decimal dec_1 = {{0xc1e85c3f, 0x72b7044e, 0x1438f17, 0x800d0000}};
  // -83
  s21_decimal dec_2 = {{0x53, 0x0, 0x0, 0x80000000}};
  // -39115877068459.9655384366143
  s21_decimal dec_check = {{0x31123c3f, 0x72b9f730, 0x1438f17, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_100) {
  // -5823301954450552.8048506
  s21_decimal dec_1 = {{0x97935b7a, 0xd17d17f7, 0xc54, 0x80070000}};
  // 3179
  s21_decimal dec_2 = {{0xc6b, 0x0, 0x0, 0x0}};
  // -5823301954447373.8048506
  s21_decimal dec_check = {{0x30be73fa, 0xd17d17f0, 0xc54, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_101) {
  // -7749138810372.45060
  s21_decimal dec_1 = {{0xb2be8a84, 0xac10c11, 0x0, 0x80050000}};
  // -7181236443670345120.79101
  s21_decimal dec_2 = {{0x36dc78fd, 0x8f8e69af, 0x9811, 0x80050000}};
  // -7181244192809155493.24161
  s21_decimal dec_check = {{0xe99b0381, 0x9a4f75c0, 0x9811, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_102) {
  // 454418618243534113944950.0448
  s21_decimal dec_1 = {{0x36585320, 0x8f0a43dc, 0xeaedcda, 0x40000}};
  // 4152134522
  s21_decimal dec_2 = {{0xf77c8b7a, 0x0, 0x0, 0x0}};
  // 454418618243538266079472.0448
  s21_decimal dec_check = {{0xa760a0c0, 0x8f0a699f, 0xeaedcda, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_103) {
  // -206589833382402134333
  s21_decimal dec_1 = {{0xc537113d, 0x330286e6, 0xb, 0x80000000}};
  // 4510757016759592
  s21_decimal dec_2 = {{0x75a6ed28, 0x100682, 0x0, 0x0}};
  // -206585322625385374741
  s21_decimal dec_check = {{0x4f902415, 0x32f28064, 0xb, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_105) {
  // 0.19
  s21_decimal dec_1 = {{0x13, 0x0, 0x0, 0x20000}};
  // 5512250948613665458828.53652
  s21_decimal dec_2 = {{0xf518b114, 0x44d414a4, 0x1c7f674, 0x50000}};
  // 5512250948613665458828.72652
  s21_decimal dec_check = {{0xf518fb4c, 0x44d414a4, 0x1c7f674, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_106) {
  // 454758
  s21_decimal dec_1 = {{0x6f066, 0x0, 0x0, 0x0}};
  // 5447
  s21_decimal dec_2 = {{0x1547, 0x0, 0x0, 0x0}};
  // 460205
  s21_decimal dec_check = {{0x705ad, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_107) {
  // -884048514773981754
  s21_decimal dec_1 = {{0xb7509a3a, 0xc44c570, 0x0, 0x80000000}};
  // -340116885135692058364020
  s21_decimal dec_2 = {{0x6cf88874, 0xc5f6366c, 0x4805, 0x80000000}};
  // -340117769184206832345774
  s21_decimal dec_check = {{0x244922ae, 0xd23afbdd, 0x4805, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_108) {
  // -0.222196263
  s21_decimal dec_1 = {{0xd3e7227, 0x0, 0x0, 0x80090000}};
  // -55682316
  s21_decimal dec_2 = {{0x351a50c, 0x0, 0x0, 0x80000000}};
  // -55682316.222196263
  s21_decimal dec_check = {{0x86b1ea27, 0xc5d2c5, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_109) {
  // -2569565966773925641394
  s21_decimal dec_1 = {{0xd06fcb2, 0x4be428a3, 0x8b, 0x80000000}};
  // 85404024790873292005288513.7
  s21_decimal dec_2 = {{0xff0a691, 0x9bcf86bf, 0x2c2720e, 0x10000}};
  // 85401455224906518079647119.7
  s21_decimal dec_check = {{0x8daac79d, 0xa4e5f060, 0x2c26c9d, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_110) {
  // -0.2
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x80010000}};
  // -117508440473983941720942
  s21_decimal dec_2 = {{0x1b35bb6e, 0x2533d8b0, 0x18e2, 0x80000000}};
  // -117508440473983941720942.2
  s21_decimal dec_check = {{0x1019524e, 0x740676e1, 0xf8d5, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_111) {
  // 4309276.09263284461945
  s21_decimal dec_1 = {{0xfe66a179, 0x5c526978, 0x17, 0xe0000}};
  // -71
  s21_decimal dec_2 = {{0x47, 0x0, 0x0, 0x80000000}};
  // 4309205.09263284461945
  s21_decimal dec_check = {{0x6c7ee179, 0x5c39300f, 0x17, 0xe0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_112) {
  // 24035348862069149
  s21_decimal dec_1 = {{0xbef9e99d, 0x556405, 0x0, 0x0}};
  // 42761850452
  s21_decimal dec_2 = {{0xf4ce0e54, 0x9, 0x0, 0x0}};
  // 24035391623919601
  s21_decimal dec_check = {{0xb3c7f7f1, 0x55640f, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_113) {
  // -2313286266084164223
  s21_decimal dec_1 = {{0x49bc827f, 0x201a719a, 0x0, 0x80000000}};
  // 9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x0}};
  // -2313286266084164214
  s21_decimal dec_check = {{0x49bc8276, 0x201a719a, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_114) {
  // 7596.7702
  s21_decimal dec_1 = {{0x4872cd6, 0x0, 0x0, 0x40000}};
  // 6088828577704002352.9213616690
  s21_decimal dec_2 = {{0xd0136232, 0xeb54144c, 0xc4bd9c09, 0xa0000}};
  // 6088828577704009949.6915616690
  s21_decimal dec_check = {{0x6bf7c3b2, 0xeb545964, 0xc4bd9c09, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_115) {
  // 4.074252579101
  s21_decimal dec_1 = {{0x9c60b11d, 0x3b4, 0x0, 0xc0000}};
  // -5.53695
  s21_decimal dec_2 = {{0x872df, 0x0, 0x0, 0x80050000}};
  // -1.462697420899
  s21_decimal dec_check = {{0x8f8f6863, 0x154, 0x0, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_116) {
  // 6845.6908245456693428833382
  s21_decimal dec_1 = {{0xf3414c66, 0x6e9c0658, 0x38a050, 0x160000}};
  // 2485936.470720722
  s21_decimal dec_2 = {{0x304580d2, 0x8d4f2, 0x0, 0x90000}};
  // 2492782.1615452676693428833382
  s21_decimal dec_check = {{0xbd488c66, 0x8a4d8667, 0x508bcf8d, 0x160000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_117) {
  // -811954169
  s21_decimal dec_1 = {{0x30656ff9, 0x0, 0x0, 0x80000000}};
  // -0.5046
  s21_decimal dec_2 = {{0x13b6, 0x0, 0x0, 0x80040000}};
  // -811954169.5046
  s21_decimal dec_check = {{0x7a660246, 0x762, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_118) {
  // 14241435822482281408925946
  s21_decimal dec_1 = {{0xcafa90fa, 0xc86c4ad1, 0xbc7bd, 0x0}};
  // 74735196847201981171
  s21_decimal dec_2 = {{0x885e12f3, 0xd28c191, 0x4, 0x0}};
  // 14241510557679128610907117
  s21_decimal dec_check = {{0x5358a3ed, 0xd5950c63, 0xbc7c1, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_119) {
  // -4897159290187600897192345
  s21_decimal dec_1 = {{0x6f6f3199, 0x897d83b2, 0x40d03, 0x80000000}};
  // 203743009676.72
  s21_decimal dec_2 = {{0xc2f8c2f8, 0x1287, 0x0, 0x20000}};
  // -4897159290187397154182668.28
  s21_decimal dec_check = {{0xc4769ccc, 0xb5075f2b, 0x1951561, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_120) {
  // -89244684322764477
  s21_decimal dec_1 = {{0x4b2676bd, 0x13d0f91, 0x0, 0x80000000}};
  // 8257811288679808138
  s21_decimal dec_2 = {{0x83f87c8a, 0x7299a39d, 0x0, 0x0}};
  // 8168566604357043661
  s21_decimal dec_check = {{0x38d205cd, 0x715c940c, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_121) {
  // -34419874.5465
  s21_decimal dec_1 = {{0x23d80d79, 0x50, 0x0, 0x80040000}};
  // -792131084391218
  s21_decimal dec_2 = {{0x63e69332, 0x2d070, 0x0, 0x80000000}};
  // -792131118811092.5465
  s21_decimal dec_check = {{0x82adde99, 0x6dee268e, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_122) {
  // -59718.4334
  s21_decimal dec_1 = {{0x23984f4e, 0x0, 0x0, 0x80040000}};
  // 94.6291
  s21_decimal dec_2 = {{0xe7073, 0x0, 0x0, 0x40000}};
  // -59623.8043
  s21_decimal dec_check = {{0x2389dedb, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_123) {
  // -4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x80000000}};
  // 4.138
  s21_decimal dec_2 = {{0x102a, 0x0, 0x0, 0x30000}};
  // 0.138
  s21_decimal dec_check = {{0x8a, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_124) {
  // 31635748.900215
  s21_decimal dec_1 = {{0xc5934d77, 0x1cc5, 0x0, 0x60000}};
  // 85273476.9439635
  s21_decimal dec_2 = {{0xc9052393, 0x3078e, 0x0, 0x70000}};
  // 116909225.8441785
  s21_decimal dec_check = {{0x80c62a39, 0x42748, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_125) {
  // -6493921623941309737
  s21_decimal dec_1 = {{0x8a3fe529, 0x5a1f0b4f, 0x0, 0x80000000}};
  // 6747247320777
  s21_decimal dec_2 = {{0xf7479ec9, 0x622, 0x0, 0x0}};
  // -6493914876693988960
  s21_decimal dec_check = {{0x92f84660, 0x5a1f052c, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_126) {
  // 356137440402897943841684601
  s21_decimal dec_1 = {{0x52eb3c79, 0x54545fab, 0x1269709, 0x0}};
  // 3757647809415180140319
  s21_decimal dec_2 = {{0xb08b3f1f, 0xb3d6c5ca, 0xcb, 0x0}};
  // 356141198050707359021824920
  s21_decimal dec_check = {{0x3767b98, 0x82b2576, 0x12697d5, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_127) {
  // 89.7
  s21_decimal dec_1 = {{0x381, 0x0, 0x0, 0x10000}};
  // 31565281406157989639091759
  s21_decimal dec_2 = {{0xba03f62f, 0x5572d837, 0x1a1c35, 0x0}};
  // 31565281406157989639091848.7
  s21_decimal dec_check = {{0x4427a157, 0x567c722d, 0x1051a15, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_128) {
  // 4102285822658077161454
  s21_decimal dec_1 = {{0x9fca77ee, 0x62a6f4dd, 0xde, 0x0}};
  // -2741358209324152370741
  s21_decimal dec_2 = {{0xc309b635, 0x9bfccf0a, 0x94, 0x80000000}};
  // 1360927613333924790713
  s21_decimal dec_check = {{0xdcc0c1b9, 0xc6aa25d2, 0x49, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_129) {
  // -89
  s21_decimal dec_1 = {{0x59, 0x0, 0x0, 0x80000000}};
  // -70936551383493417801
  s21_decimal dec_2 = {{0x345e9b49, 0xd87141a5, 0x3, 0x80000000}};
  // -70936551383493417890
  s21_decimal dec_check = {{0x345e9ba2, 0xd87141a5, 0x3, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_130) {
  // -0.54708
  s21_decimal dec_1 = {{0xd5b4, 0x0, 0x0, 0x80050000}};
  // -0.3819
  s21_decimal dec_2 = {{0xeeb, 0x0, 0x0, 0x80040000}};
  // -0.92898
  s21_decimal dec_check = {{0x16ae2, 0x0, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_131) {
  // 3.14
  s21_decimal dec_1 = {{0x13a, 0x0, 0x0, 0x20000}};
  // 77298218398352
  s21_decimal dec_2 = {{0x64d97290, 0x464d, 0x0, 0x0}};
  // 77298218398355.14
  s21_decimal dec_check = {{0x64f0c17a, 0x1b763b, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_133) {
  // -0.4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x80010000}};
  // 8142898133924740321
  s21_decimal dec_2 = {{0xbac67ce1, 0x710162b5, 0x0, 0x0}};
  // 8142898133924740320.6
  s21_decimal dec_check = {{0x4bc0e0c6, 0x6a0ddb19, 0x4, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_134) {
  // 7586864044793084168988
  s21_decimal dec_1 = {{0x9316cb1c, 0x48e3abcf, 0x19b, 0x0}};
  // -0.854375124
  s21_decimal dec_2 = {{0x32ecbad4, 0x0, 0x0, 0x80090000}};
  // 7586864044793084168987.1456249
  s21_decimal dec_check = {{0x7e8597f9, 0xdbc0dd81, 0xf5251187, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_136) {
  // 9484
  s21_decimal dec_1 = {{0x250c, 0x0, 0x0, 0x0}};
  // 581960408
  s21_decimal dec_2 = {{0x22b002d8, 0x0, 0x0, 0x0}};
  // 581969892
  s21_decimal dec_check = {{0x22b027e4, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_137) {
  // 7.490765
  s21_decimal dec_1 = {{0x724ccd, 0x0, 0x0, 0x60000}};
  // 7.8582294757020681
  s21_decimal dec_2 = {{0x44a09409, 0x1172e2e, 0x0, 0x100000}};
  // 15.3489944757020681
  s21_decimal dec_check = {{0xa1d62809, 0x2214e4a, 0x0, 0x100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_138) {
  // 894019593197588177105.40
  s21_decimal dec_1 = {{0x839bd1cc, 0x7d6bc970, 0x12ee, 0x20000}};
  // -67.32337
  s21_decimal dec_2 = {{0x66ba31, 0x0, 0x0, 0x80050000}};
  // 894019593197588177038.07663
  s21_decimal dec_check = {{0x1844caaf, 0xed0adf82, 0x49f399, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_139) {
  // -6734463275261
  s21_decimal dec_1 = {{0xfd4a90fd, 0x61f, 0x0, 0x80000000}};
  // -0.774536187589
  s21_decimal dec_2 = {{0x55f44ec5, 0xb4, 0x0, 0x800c0000}};
  // -6734463275261.774536187589
  s21_decimal dec_check = {{0xf6151ec5, 0xfc5566f1, 0x59213, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_140) {
  // -2146360
  s21_decimal dec_1 = {{0x20c038, 0x0, 0x0, 0x80000000}};
  // -9045
  s21_decimal dec_2 = {{0x2355, 0x0, 0x0, 0x80000000}};
  // -2155405
  s21_decimal dec_check = {{0x20e38d, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_141) {
  // -28175410413918736391
  s21_decimal dec_1 = {{0xe277d007, 0x87032a7d, 0x1, 0x80000000}};
  // -883895
  s21_decimal dec_2 = {{0xd7cb7, 0x0, 0x0, 0x80000000}};
  // -28175410413919620286
  s21_decimal dec_check = {{0xe2854cbe, 0x87032a7d, 0x1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_142) {
  // 57449570184341184
  s21_decimal dec_1 = {{0x675626c0, 0xcc1a14, 0x0, 0x0}};
  // -319350256.85461302
  s21_decimal dec_2 = {{0x95dff936, 0x7174bc, 0x0, 0x80080000}};
  // 57449569864990927.14538698
  s21_decimal dec_check = {{0xf7eec6ca, 0xbe060e4a, 0x4c08a, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_143) {
  // 9778149171977002957
  s21_decimal dec_1 = {{0x74781fcd, 0x87b2f6dd, 0x0, 0x0}};
  // -22.184621
  s21_decimal dec_2 = {{0x15282ad, 0x0, 0x0, 0x80060000}};
  // 9778149171977002934.815379
  s21_decimal dec_check = {{0xf1eb4a93, 0x875ca26d, 0x8169a, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_144) {
  // 417
  s21_decimal dec_1 = {{0x1a1, 0x0, 0x0, 0x0}};
  // 0.4653631044730177
  s21_decimal dec_2 = {{0xe9563d41, 0x108873, 0x0, 0x100000}};
  // 417.4653631044730177
  s21_decimal dec_check = {{0xf2b73d41, 0x39ef595b, 0x0, 0x100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_145) {
  // -0.97198790470504225994
  s21_decimal dec_1 = {{0xa0071cca, 0x44e778f3, 0x5, 0x80140000}};
  // 92.65428297764
  s21_decimal dec_2 = {{0x468ff824, 0x86d, 0x0, 0xb0000}};
  // 91.68229507293495774006
  s21_decimal dec_check = {{0x8b6d4b36, 0x2be6185, 0x1f1, 0x140000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_146) {
  // -2151953613
  s21_decimal dec_1 = {{0x804434cd, 0x0, 0x0, 0x80000000}};
  // -1727440853198964
  s21_decimal dec_2 = {{0x2a6ce874, 0x62319, 0x0, 0x80000000}};
  // -1727443005152577
  s21_decimal dec_check = {{0xaab11d41, 0x62319, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_147) {
  // -803892449
  s21_decimal dec_1 = {{0x2fea6ce1, 0x0, 0x0, 0x80000000}};
  // -55399522
  s21_decimal dec_2 = {{0x34d5462, 0x0, 0x0, 0x80000000}};
  // -859291971
  s21_decimal dec_check = {{0x3337c143, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_148) {
  // -9556304136.975000161858556
  s21_decimal dec_1 = {{0x6701b3fc, 0x490a357a, 0x7e7a0, 0x800f0000}};
  // 54656500007195310311579
  s21_decimal dec_2 = {{0x39c489b, 0xef4f35ff, 0xb92, 0x0}};
  // 54656500007185754007442.025000
  s21_decimal dec_check = {{0x16bea28, 0x6988816f, 0xb09acc12, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_149) {
  // 888.15261910196088911749
  s21_decimal dec_1 = {{0xf74ab785, 0xaf5bdfe5, 0x12ce, 0x140000}};
  // -485068
  s21_decimal dec_2 = {{0x766cc, 0x0, 0x0, 0x80000000}};
  // -484179.84738089803911088251
  s21_decimal dec_check = {{0x5975487b, 0x3646f72d, 0x280ce8, 0x80140000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_150) {
  // 449446802.58570
  s21_decimal dec_1 = {{0x7fb38c0a, 0x28e0, 0x0, 0x50000}};
  // -6636.581228745193342276318
  s21_decimal dec_2 = {{0x5ab292de, 0xca0fd56c, 0x57d59, 0x80150000}};
  // 449440166.00447125480665772368
  s21_decimal dec_check = {{0x417bf150, 0xebe54a69, 0x9138d1b5, 0x140000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_151) {
  // -67.1665
  s21_decimal dec_1 = {{0xa3fb1, 0x0, 0x0, 0x80040000}};
  // -784309830060381403276
  s21_decimal dec_2 = {{0x405788c, 0x847c42fd, 0x2a, 0x80000000}};
  // -784309830060381403343.1665
  s21_decimal dec_check = {{0x15bf1c71, 0x35f8bb6d, 0x67cd7, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_152) {
  // 9330.12598
  s21_decimal dec_1 = {{0x379ca476, 0x0, 0x0, 0x50000}};
  // 665051436300
  s21_decimal dec_2 = {{0xd827950c, 0x9a, 0x0, 0x0}};
  // 665051445630.12598
  s21_decimal dec_check = {{0x9d6a13f6, 0xec4613, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_153) {
  // -1.8446
  s21_decimal dec_1 = {{0x480e, 0x0, 0x0, 0x80040000}};
  // -6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x80000000}};
  // -7.8446
  s21_decimal dec_check = {{0x1326e, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_154) {
  // -0.799
  s21_decimal dec_1 = {{0x31f, 0x0, 0x0, 0x80030000}};
  // 3495138309440.832
  s21_decimal dec_2 = {{0x4d600540, 0xc6acf, 0x0, 0x30000}};
  // 3495138309440.033
  s21_decimal dec_check = {{0x4d600221, 0xc6acf, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_155) {
  // 6999240141959885
  s21_decimal dec_1 = {{0x965bf2cd, 0x18ddc5, 0x0, 0x0}};
  // 582388782268207739387616124
  s21_decimal dec_2 = {{0x5c2d9b7c, 0x25f83a6f, 0x1e1bd9f, 0x0}};
  // 582388782275206979529576009
  s21_decimal dec_check = {{0xf2898e49, 0x26111834, 0x1e1bd9f, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_156) {
  // -283126982355985610613
  s21_decimal dec_1 = {{0xb8cfb775, 0x592d1a61, 0xf, 0x80000000}};
  // -426674242290966.4
  s21_decimal dec_2 = {{0x627732e0, 0xf2894, 0x0, 0x80010000}};
  // -283127409030227901579.4
  s21_decimal dec_check = {{0x9a945d72, 0x7bd23065, 0x99, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_157) {
  // 75954969151980133880
  s21_decimal dec_1 = {{0x5d875df8, 0x1e164204, 0x4, 0x0}};
  // 8.8
  s21_decimal dec_2 = {{0x58, 0x0, 0x0, 0x10000}};
  // 75954969151980133888.8
  s21_decimal dec_check = {{0xa749ac08, 0x2cde942b, 0x29, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_158) {
  // -5008329.1445358321665
  s21_decimal dec_1 = {{0x86f16001, 0xb70b9837, 0x2, 0x800d0000}};
  // -6872946406133577.6
  s21_decimal dec_2 = {{0x5afa98e0, 0xf42d15, 0x0, 0x80010000}};
  // -6872946411141906.7445358321665
  s21_decimal dec_check = {{0x38df6001, 0x2b12a305, 0xde13ae23, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_159) {
  // 99952
  s21_decimal dec_1 = {{0x18670, 0x0, 0x0, 0x0}};
  // -0.19
  s21_decimal dec_2 = {{0x13, 0x0, 0x0, 0x80020000}};
  // 99951.81
  s21_decimal dec_check = {{0x9883ad, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_160) {
  // 71431252870239219
  s21_decimal dec_1 = {{0x953113f3, 0xfdc658, 0x0, 0x0}};
  // 87336
  s21_decimal dec_2 = {{0x15528, 0x0, 0x0, 0x0}};
  // 71431252870326555
  s21_decimal dec_check = {{0x9532691b, 0xfdc658, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_161) {
  // -56207354411539987402.029287648
  s21_decimal dec_1 = {{0xe6f048e0, 0x21f9cb31, 0xb59da244, 0x80090000}};
  // 732382484403017636
  s21_decimal dec_2 = {{0x3e8f57a4, 0xa29f1fd, 0x0, 0x0}};
  // -55474971927136969766.029287648
  s21_decimal dec_check = {{0x4720e0e0, 0x19454c67, 0xb33fd23e, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_162) {
  // -685507337.09
  s21_decimal dec_1 = {{0xf5f12f8d, 0xf, 0x0, 0x80020000}};
  // -0.051
  s21_decimal dec_2 = {{0x33, 0x0, 0x0, 0x80030000}};
  // -685507337.141
  s21_decimal dec_check = {{0x9b6bdbb5, 0x9f, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_163) {
  // -9.8
  s21_decimal dec_1 = {{0x62, 0x0, 0x0, 0x80010000}};
  // 3.21
  s21_decimal dec_2 = {{0x141, 0x0, 0x0, 0x20000}};
  // -6.59
  s21_decimal dec_check = {{0x293, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_164) {
  // -1023944718453869
  s21_decimal dec_1 = {{0xb5368c6d, 0x3a345, 0x0, 0x80000000}};
  // -53670335374
  s21_decimal dec_2 = {{0x7f00538e, 0xc, 0x0, 0x80000000}};
  // -1023998388789243
  s21_decimal dec_check = {{0x3436dffb, 0x3a352, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_165) {
  // -23371.8757880237578022
  s21_decimal dec_1 = {{0x3d16d726, 0xab7fd3ff, 0xc, 0x80100000}};
  // 113628616076779
  s21_decimal dec_2 = {{0x394c2deb, 0x6758, 0x0, 0x0}};
  // 113628616053407.12421197624220
  s21_decimal dec_check = {{0x4d80339c, 0xe87af7d8, 0x24b72389, 0xe0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_166) {
  // -2
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x80000000}};
  // 6503.0
  s21_decimal dec_2 = {{0xfe06, 0x0, 0x0, 0x10000}};
  // 6501.0
  s21_decimal dec_check = {{0xfdf2, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_167) {
  // 6565859069453629558479.0990
  s21_decimal dec_1 = {{0x9eaa79ce, 0x556b3e0c, 0x364fbf, 0x40000}};
  // 5427037997203.2343193346
  s21_decimal dec_2 = {{0x5d9e3702, 0xd147c4, 0xb7e, 0xa0000}};
  // 6565859074880667555682.3333193
  s21_decimal dec_check = {{0x461f949, 0x9c118058, 0xd4278368, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_168) {
  // 1.61153330297504
  s21_decimal dec_1 = {{0x6f01baa0, 0x9291, 0x0, 0xe0000}};
  // 301274603220133017
  s21_decimal dec_2 = {{0xc8c86499, 0x42e57a7, 0x0, 0x0}};
  // 301274603220133018.61153330298
  s21_decimal dec_check = {{0x872d547a, 0xa1400083, 0x6158d9e0, 0xb0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_169) {
  // 1079697203815774837184
  s21_decimal dec_1 = {{0xb5ca59c0, 0x87cf0663, 0x3a, 0x0}};
  // 7201639523139762900.4
  s21_decimal dec_2 = {{0x5b974c4c, 0xe76da1e7, 0x3, 0x10000}};
  // 1086898843338914600084.4
  s21_decimal dec_check = {{0x757ecdcc, 0x3583e1cc, 0x24d, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_170) {
  // 125764262611
  s21_decimal dec_1 = {{0x48225ad3, 0x1d, 0x0, 0x0}};
  // -0.8364104062
  s21_decimal dec_2 = {{0xf28a197e, 0x1, 0x0, 0x800a0000}};
  // 125764262610.1635895938
  s21_decimal dec_check = {{0xc96ad282, 0x2d4c2929, 0x44, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_171) {
  // -8876409068.55645
  s21_decimal dec_1 = {{0xf0f4dd, 0x3274e, 0x0, 0x80050000}};
  // -22143.36525
  s21_decimal dec_2 = {{0x83fc180d, 0x0, 0x0, 0x80050000}};
  // -8876431211.92170
  s21_decimal dec_check = {{0x84ed0cea, 0x3274e, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_172) {
  // 825441
  s21_decimal dec_1 = {{0xc9861, 0x0, 0x0, 0x0}};
  // 0.685739559
  s21_decimal dec_2 = {{0x28df8e27, 0x0, 0x0, 0x90000}};
  // 825441.685739559
  s21_decimal dec_check = {{0x1e761827, 0x2eebc, 0x0, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_173) {
  // 4.99196590040397066544
  s21_decimal dec_1 = {{0xec2b3130, 0xfbe8dc8, 0x1b, 0x140000}};
  // 42575.993042
  s21_decimal dec_2 = {{0xe9ba18d2, 0x9, 0x0, 0x60000}};
  // 42580.98500790040397066544
  s21_decimal dec_check = {{0x6673b130, 0xfb756fca, 0x385af, 0x140000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_174) {
  // 93931631801447264501845698
  s21_decimal dec_1 = {{0x27334ec2, 0xf6950dc8, 0x4db2cb, 0x0}};
  // 8462212912731044
  s21_decimal dec_2 = {{0x7aad53a4, 0x1e1056, 0x0, 0x0}};
  // 93931631809909477414576742
  s21_decimal dec_check = {{0xa1e0a266, 0xf6b31e1e, 0x4db2cb, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_175) {
  // 6288349
  s21_decimal dec_1 = {{0x5ff3dd, 0x0, 0x0, 0x0}};
  // 5400364111.72834901802
  s21_decimal dec_2 = {{0xe59dff2a, 0x4682beb9, 0x1d, 0xb0000}};
  // 5406652460.72834901802
  s21_decimal dec_check = {{0x6a7c472a, 0x4f3cd0bc, 0x1d, 0xb0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_176) {
  // 71927474200152733086353394
  s21_decimal dec_1 = {{0x67f787f2, 0x308073e6, 0x3b7f3c, 0x0}};
  // -192790723312341.0449878
  s21_decimal dec_2 = {{0x131515d6, 0x83166609, 0x68, 0x80070000}};
  // 71927474199959942363041052.955
  s21_decimal dec_check = {{0xebe5391b, 0x7317cde1, 0xe869031d, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_177) {
  // 653
  s21_decimal dec_1 = {{0x28d, 0x0, 0x0, 0x0}};
  // 624837541979657342677937.84
  s21_decimal dec_2 = {{0x5f233178, 0x1a31ebcc, 0x33af73, 0x20000}};
  // 624837541979657342678590.84
  s21_decimal dec_check = {{0x5f24308c, 0x1a31ebcc, 0x33af73, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_178) {
  // 218779
  s21_decimal dec_1 = {{0x3569b, 0x0, 0x0, 0x0}};
  // 52936667060
  s21_decimal dec_2 = {{0x53456fb4, 0xc, 0x0, 0x0}};
  // 52936885839
  s21_decimal dec_check = {{0x5348c64f, 0xc, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_179) {
  // -33323425231485183
  s21_decimal dec_1 = {{0x8b9f38ff, 0x76637a, 0x0, 0x80000000}};
  // 784
  s21_decimal dec_2 = {{0x310, 0x0, 0x0, 0x0}};
  // -33323425231484399
  s21_decimal dec_check = {{0x8b9f35ef, 0x76637a, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_180) {
  // -577892961697075
  s21_decimal dec_1 = {{0x30b33d33, 0x20d97, 0x0, 0x80000000}};
  // -7.92
  s21_decimal dec_2 = {{0x318, 0x0, 0x0, 0x80020000}};
  // -577892961697082.92
  s21_decimal dec_check = {{0x603eb04, 0xcd4f0f, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_181) {
  // -95.07745188
  s21_decimal dec_1 = {{0x36b4ada4, 0x2, 0x0, 0x80080000}};
  // 1545395820.386260
  s21_decimal dec_2 = {{0x80e957d4, 0x57d87, 0x0, 0x60000}};
  // 1545395725.30880812
  s21_decimal dec_check = {{0x2471a12c, 0x22508ec, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_182) {
  // 29
  s21_decimal dec_1 = {{0x1d, 0x0, 0x0, 0x0}};
  // 9782
  s21_decimal dec_2 = {{0x2636, 0x0, 0x0, 0x0}};
  // 9811
  s21_decimal dec_check = {{0x2653, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_183) {
  // -2188839487469.568
  s21_decimal dec_1 = {{0xe81ef800, 0x7c6bc, 0x0, 0x80030000}};
  // -464527144970290472876
  s21_decimal dec_2 = {{0x208c27ac, 0x2e9bf12e, 0x19, 0x80000000}};
  // -464527147159129960345.568
  s21_decimal dec_check = {{0xb99efe0, 0x112de2ec, 0x625e, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_184) {
  // -19001
  s21_decimal dec_1 = {{0x4a39, 0x0, 0x0, 0x80000000}};
  // -8689.62920
  s21_decimal dec_2 = {{0x33cb5268, 0x0, 0x0, 0x80050000}};
  // -27690.62920
  s21_decimal dec_check = {{0xa50c8c08, 0x0, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_185) {
  // -4628405402543160338
  s21_decimal dec_1 = {{0xf7157c12, 0x403b6630, 0x0, 0x80000000}};
  // 1734687881034989981
  s21_decimal dec_2 = {{0xe144019d, 0x1812d96f, 0x0, 0x0}};
  // -2893717521508170357
  s21_decimal dec_check = {{0x15d17a75, 0x28288cc1, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_187) {
  // 88718119337
  s21_decimal dec_1 = {{0xa80311a9, 0x14, 0x0, 0x0}};
  // -8.7357991577
  s21_decimal dec_2 = {{0x56f12a99, 0x14, 0x0, 0x800a0000}};
  // 88718119328.2642008423
  s21_decimal dec_check = {{0x9b0c5967, 0x181cc2cd, 0x30, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_188) {
  // -9890227827.2757
  s21_decimal dec_1 = {{0x7b29f6f5, 0x59f3, 0x0, 0x80040000}};
  // 8314150256
  s21_decimal dec_2 = {{0xef8fdd70, 0x1, 0x0, 0x0}};
  // -1576077571.2757
  s21_decimal dec_check = {{0x97700ff5, 0xe55, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_189) {
  // -4309550118567870135495597
  s21_decimal dec_1 = {{0x612b6bad, 0x2e17b65f, 0x39095, 0x80000000}};
  // 0.73
  s21_decimal dec_2 = {{0x49, 0x0, 0x0, 0x20000}};
  // -4309550118567870135495596.27
  s21_decimal dec_check = {{0xf4f60f4b, 0x1433d41, 0x1647a46, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_190) {
  // -75466619687358188520
  s21_decimal dec_1 = {{0x307c4be8, 0x174f4ac4, 0x4, 0x80000000}};
  // 9193203052865458118.538
  s21_decimal dec_2 = {{0x62459f8a, 0x5d523ce7, 0x1f2, 0x30000}};
  // -66273416634492730401.462
  s21_decimal dec_check = {{0x342e2b6, 0xb069d176, 0xe08, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_191) {
  // -691.32
  s21_decimal dec_1 = {{0x10e0c, 0x0, 0x0, 0x80020000}};
  // -562083231390045264.22732
  s21_decimal dec_2 = {{0x1e1eeacc, 0xf2e7a77, 0xbe7, 0x80050000}};
  // -562083231390045955.54732
  s21_decimal dec_check = {{0x223dc9ac, 0xf2e7a77, 0xbe7, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_192) {
  // 141432907090991494242.421688
  s21_decimal dec_1 = {{0x9632cbb8, 0x41a6af93, 0x74fd95, 0x60000}};
  // -0.853
  s21_decimal dec_2 = {{0x355, 0x0, 0x0, 0x80030000}};
  // 141432907090991494241.568688
  s21_decimal dec_check = {{0x9625c7b0, 0x41a6af93, 0x74fd95, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_193) {
  // 485300
  s21_decimal dec_1 = {{0x767b4, 0x0, 0x0, 0x0}};
  // -58068459953902
  s21_decimal dec_2 = {{0x1ded9eee, 0x34d0, 0x0, 0x80000000}};
  // -58068459468602
  s21_decimal dec_check = {{0x1de6373a, 0x34d0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_194) {
  // -79228162514264337593347695957
  s21_decimal dec_1 = {{0xf44d6555, 0xffffffff, 0xffffffff, 0x80000000}};
  // -55
  s21_decimal dec_2 = {{0x37, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593347696012
  s21_decimal dec_check = {{0xf44d658c, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_195) {
  // 9994911091101982200262
  s21_decimal dec_1 = {{0x799311c6, 0xd3415a0c, 0x21d, 0x0}};
  // 8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x0}};
  // 9994911091101982200270
  s21_decimal dec_check = {{0x799311ce, 0xd3415a0c, 0x21d, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_196) {
  // 792189651566314598
  s21_decimal dec_1 = {{0x7859c466, 0xafe6c4a, 0x0, 0x0}};
  // 382061.8737595
  s21_decimal dec_2 = {{0x8e9f67bb, 0x379, 0x0, 0x70000}};
  // 792189651566696659.8737595
  s21_decimal dec_check = {{0xf1255ebb, 0xdee14086, 0x68d86, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_197) {
  // 867845787336262263
  s21_decimal dec_1 = {{0x41ff4277, 0xc0b3525, 0x0, 0x0}};
  // 343072912642202597420844728
  s21_decimal dec_2 = {{0xc55a46b8, 0xdc41e1e9, 0x11bc883, 0x0}};
  // 343072913510048384757106991
  s21_decimal dec_check = {{0x759892f, 0xe84d170f, 0x11bc883, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_198) {
  // 6027.0015
  s21_decimal dec_1 = {{0x397a5bf, 0x0, 0x0, 0x40000}};
  // 227.0612
  s21_decimal dec_2 = {{0x22a594, 0x0, 0x0, 0x40000}};
  // 6254.0627
  s21_decimal dec_check = {{0x3ba4b53, 0x0, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_199) {
  // 71573409730890844
  s21_decimal dec_1 = {{0xe5f8c5c, 0xfe47a3, 0x0, 0x0}};
  // 2742860760621
  s21_decimal dec_2 = {{0x9f3dc62d, 0x27e, 0x0, 0x0}};
  // 71576152591651465
  s21_decimal dec_check = {{0xad9d5289, 0xfe4a21, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_200) {
  // -261
  s21_decimal dec_1 = {{0x105, 0x0, 0x0, 0x80000000}};
  // -2166240698041162178131
  s21_decimal dec_2 = {{0x21b29e53, 0x6ea0f5a2, 0x75, 0x80000000}};
  // -2166240698041162178392
  s21_decimal dec_check = {{0x21b29f58, 0x6ea0f5a2, 0x75, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_201) {
  // 5.6
  s21_decimal dec_1 = {{0x38, 0x0, 0x0, 0x10000}};
  // -7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x80000000}};
  // -1.4
  s21_decimal dec_check = {{0xe, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_202) {
  // 94122231266435
  s21_decimal dec_1 = {{0x8a28fc83, 0x559a, 0x0, 0x0}};
  // -727646.0032602850
  s21_decimal dec_2 = {{0xdf7732e2, 0x19d9e6, 0x0, 0x800a0000}};
  // 94122230538788.9967397150
  s21_decimal dec_check = {{0x770e791e, 0xc36f24c9, 0xc74f, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_203) {
  // -85437322
  s21_decimal dec_1 = {{0x517ab8a, 0x0, 0x0, 0x80000000}};
  // -4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x80000000}};
  // -85437326
  s21_decimal dec_check = {{0x517ab8e, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_204) {
  // 4595573123
  s21_decimal dec_1 = {{0x11eae183, 0x1, 0x0, 0x0}};
  // 14313923638376254203937674268
  s21_decimal dec_2 = {{0xda0bd41c, 0x46a52737, 0x2e40333b, 0x0}};
  // 14313923638376254208533247391
  s21_decimal dec_check = {{0xebf6b59f, 0x46a52738, 0x2e40333b, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_205) {
  // -88983615919
  s21_decimal dec_1 = {{0xb7d639af, 0x14, 0x0, 0x80000000}};
  // 438717145523557961.0327
  s21_decimal dec_2 = {{0x624684d7, 0xd43c0a4e, 0xed, 0x40000}};
  // 438717056539942042.0327
  s21_decimal dec_check = {{0x421940e7, 0xd438e101, 0xed, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_206) {
  // 251278083556961005155651
  s21_decimal dec_1 = {{0x10b13543, 0xcfeca2b6, 0x3535, 0x0}};
  // -56.15724706
  s21_decimal dec_2 = {{0x4eb928a2, 0x1, 0x0, 0x80080000}};
  // 251278083556961005155594.84275
  s21_decimal dec_check = {{0x658fab73, 0x73c70f38, 0x51313c64, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_207) {
  // 6.53182140
  s21_decimal dec_1 = {{0x26eec4bc, 0x0, 0x0, 0x80000}};
  // 8.87001
  s21_decimal dec_2 = {{0xd88d9, 0x0, 0x0, 0x50000}};
  // 15.40183140
  s21_decimal dec_check = {{0x5bcd5464, 0x0, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_208) {
  // -826185681623
  s21_decimal dec_1 = {{0x5c810ad7, 0xc0, 0x0, 0x80000000}};
  // -5592644615833
  s21_decimal dec_2 = {{0x23987e99, 0x516, 0x0, 0x80000000}};
  // -6418830297456
  s21_decimal dec_check = {{0x80198970, 0x5d6, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_209) {
  // 23426095792012544
  s21_decimal dec_1 = {{0xf6283d00, 0x5339e8, 0x0, 0x0}};
  // -51874551671
  s21_decimal dec_2 = {{0x13f6d777, 0xc, 0x0, 0x80000000}};
  // 23426043917460873
  s21_decimal dec_check = {{0xe2316589, 0x5339dc, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_210) {
  // -149790
  s21_decimal dec_1 = {{0x2491e, 0x0, 0x0, 0x80000000}};
  // 395441963
  s21_decimal dec_2 = {{0x1791f72b, 0x0, 0x0, 0x0}};
  // 395292173
  s21_decimal dec_check = {{0x178fae0d, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_211) {
  // 3914311595275220024804430
  s21_decimal dec_1 = {{0xb5e7c44e, 0x41bb9f26, 0x33ce3, 0x0}};
  // 196420
  s21_decimal dec_2 = {{0x2ff44, 0x0, 0x0, 0x0}};
  // 3914311595275220025000850
  s21_decimal dec_check = {{0xb5eac392, 0x41bb9f26, 0x33ce3, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_212) {
  // -48535245
  s21_decimal dec_1 = {{0x2e496cd, 0x0, 0x0, 0x80000000}};
  // 0.136
  s21_decimal dec_2 = {{0x88, 0x0, 0x0, 0x30000}};
  // -48535244.864
  s21_decimal dec_check = {{0x4ced1040, 0xb, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_213) {
  // 98759696835371044286248.21
  s21_decimal dec_1 = {{0x2ba86bb5, 0x63aa1f0f, 0x82b51, 0x20000}};
  // -7959310
  s21_decimal dec_2 = {{0x79730e, 0x0, 0x0, 0x80000000}};
  // 98759696835371036326938.21
  s21_decimal dec_check = {{0xfc377a3d, 0x63aa1f0e, 0x82b51, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_214) {
  // 8.67820
  s21_decimal dec_1 = {{0xd3dec, 0x0, 0x0, 0x50000}};
  // -58.19066
  s21_decimal dec_2 = {{0x58caba, 0x0, 0x0, 0x80050000}};
  // -49.51246
  s21_decimal dec_check = {{0x4b8cce, 0x0, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_215) {
  // -5217116145726374044207.147
  s21_decimal dec_1 = {{0x2b3f882b, 0x6ed6d023, 0x450c4, 0x80030000}};
  // 3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x0}};
  // -5217116145726374044204.147
  s21_decimal dec_check = {{0x2b3f7c73, 0x6ed6d023, 0x450c4, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_216) {
  // -378745116875175799537212131
  s21_decimal dec_1 = {{0x2a5f1ae3, 0xed3d54dd, 0x1394a65, 0x80000000}};
  // -2.2
  s21_decimal dec_2 = {{0x16, 0x0, 0x0, 0x80010000}};
  // -378745116875175799537212133.2
  s21_decimal dec_check = {{0xa7b70cf4, 0x446550a3, 0xc3ce7fb, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_217) {
  // 38
  s21_decimal dec_1 = {{0x26, 0x0, 0x0, 0x0}};
  // -5441032284
  s21_decimal dec_2 = {{0x444f905c, 0x1, 0x0, 0x80000000}};
  // -5441032246
  s21_decimal dec_check = {{0x444f9036, 0x1, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_218) {
  // 0.9192537790089910412043522636
  s21_decimal dec_1 = {{0x8fae924c, 0x222ef3de, 0x1db3e398, 0x1c0000}};
  // -0.95903712061538
  s21_decimal dec_2 = {{0x52b0a862, 0x5739, 0x0, 0x800e0000}};
  // -0.0397833416063889587956477364
  s21_decimal dec_check = {{0xf91dedb4, 0xb2fe1c89, 0x1491480, 0x801c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_219) {
  // 97679883
  s21_decimal dec_1 = {{0x5d27a0b, 0x0, 0x0, 0x0}};
  // 42532885944638.8902887481
  s21_decimal dec_2 = {{0xf9cc8039, 0x1fa8f19c, 0x5a11, 0xa0000}};
  // 42532983624521.8902887481
  s21_decimal dec_check = {{0x48f74c39, 0x2d373af9, 0x5a11, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_220) {
  // 0.690746
  s21_decimal dec_1 = {{0xa8a3a, 0x0, 0x0, 0x60000}};
  // 970.22626789
  s21_decimal dec_2 = {{0x96ffcbe5, 0x16, 0x0, 0x80000}};
  // 970.91701389
  s21_decimal dec_check = {{0x9b1dca8d, 0x16, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_221) {
  // -2892548628956973919557277
  s21_decimal dec_1 = {{0x5b0ad69d, 0x6018b0ea, 0x26485, 0x80000000}};
  // 87.1
  s21_decimal dec_2 = {{0x367, 0x0, 0x0, 0x10000}};
  // -2892548628956973919557189.9
  s21_decimal dec_check = {{0x8e6c5ebb, 0xc0f6e927, 0x17ed35, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_222) {
  // 12.816758
  s21_decimal dec_1 = {{0xc39176, 0x0, 0x0, 0x60000}};
  // 105565
  s21_decimal dec_2 = {{0x19c5d, 0x0, 0x0, 0x0}};
  // 105577.816758
  s21_decimal dec_check = {{0x94eda2b6, 0x18, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_223) {
  // -154689196
  s21_decimal dec_1 = {{0x9385eac, 0x0, 0x0, 0x80000000}};
  // 5.5628824400400794
  s21_decimal dec_2 = {{0xfda8919a, 0xc5a21e, 0x0, 0x100000}};
  // -154689190.4371175599599206
  s21_decimal dec_check = {{0xf6036e66, 0x2d9c4904, 0x14791, 0x80100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_224) {
  // 23390768527761492517039574
  s21_decimal dec_1 = {{0xca5badd6, 0x1a4a3c08, 0x135930, 0x0}};
  // 489549269
  s21_decimal dec_2 = {{0x1d2dedd5, 0x0, 0x0, 0x0}};
  // 23390768527761493006588843
  s21_decimal dec_check = {{0xe7899bab, 0x1a4a3c08, 0x135930, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_226) {
  // 45859672345434279003415298671
  s21_decimal dec_1 = {{0xe0bec26f, 0x51d56a08, 0x942e3b5b, 0x0}};
  // -69947184793849
  s21_decimal dec_2 = {{0xd91a48f9, 0x3f9d, 0x0, 0x80000000}};
  // 45859672345434209056230504822
  s21_decimal dec_check = {{0x7a47976, 0x51d52a6b, 0x942e3b5b, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_227) {
  // -1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // -803
  s21_decimal dec_2 = {{0x323, 0x0, 0x0, 0x80000000}};
  // -804
  s21_decimal dec_check = {{0x324, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_228) {
  // -8257551644013060902305.0529
  s21_decimal dec_1 = {{0xfe886321, 0xb746de1e, 0x444e0b, 0x80040000}};
  // 774540846304
  s21_decimal dec_2 = {{0x563b64e0, 0xb4, 0x0, 0x0}};
  // -8257551643238520056001.0529
  s21_decimal dec_check = {{0x8e73f521, 0xb72b59b6, 0x444e0b, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_229) {
  // -5829.18216216535
  s21_decimal dec_1 = {{0x3935efd7, 0x21229, 0x0, 0x800b0000}};
  // 8927.066
  s21_decimal dec_2 = {{0x88375a, 0x0, 0x0, 0x30000}};
  // 3097.88383783465
  s21_decimal dec_check = {{0x3a922a29, 0x119c0, 0x0, 0xb0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_230) {
  // 1768730205480.7165952
  s21_decimal dec_1 = {{0xebd15c00, 0xf575eb81, 0x0, 0x70000}};
  // 889277.22
  s21_decimal dec_2 = {{0x54cedea, 0x0, 0x0, 0x20000}};
  // 1768731094757.9365952
  s21_decimal dec_check = {{0x6e588a40, 0xf575f398, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_231) {
  // 27231488165.73194677
  s21_decimal dec_1 = {{0xba5ee1b5, 0x25ca916b, 0x0, 0x80000}};
  // -8057825697487707731.70
  s21_decimal dec_2 = {{0xace6d8b2, 0xae7ac1f7, 0x2b, 0x80020000}};
  // -8057825670256219565.96805323
  s21_decimal dec_check = {{0xb5a32ecb, 0x7c6ae899, 0x29a8718, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_232) {
  // -635.096554698
  s21_decimal dec_1 = {{0xdeb45cca, 0x93, 0x0, 0x80090000}};
  // -58303410695265
  s21_decimal dec_2 = {{0xd2156c61, 0x3506, 0x0, 0x80000000}};
  // -58303410695900.096554698
  s21_decimal dec_check = {{0x5392e6ca, 0xa25cb336, 0xc58, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_233) {
  // 7394079388367923811700746694
  s21_decimal dec_1 = {{0x6dc4a9c6, 0xd1e7907f, 0x17e43d36, 0x0}};
  // -69.49385080
  s21_decimal dec_2 = {{0x9e373378, 0x1, 0x0, 0x80080000}};
  // 7394079388367923811700746624.5
  s21_decimal dec_check = {{0x49ae9f05, 0x330ba4fa, 0xeeea6424, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_234) {
  // -22155271755
  s21_decimal dec_1 = {{0x288e9e4b, 0x5, 0x0, 0x80000000}};
  // -58342704391
  s21_decimal dec_2 = {{0x957f0507, 0xd, 0x0, 0x80000000}};
  // -80497976146
  s21_decimal dec_check = {{0xbe0da352, 0x12, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_235) {
  // 3596667
  s21_decimal dec_1 = {{0x36e17b, 0x0, 0x0, 0x0}};
  // 3422106887.0871
  s21_decimal dec_2 = {{0xb6a764d7, 0x1f1f, 0x0, 0x40000}};
  // 3425703554.0871
  s21_decimal dec_check = {{0x166f3987, 0x1f28, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_236) {
  // 539305.4
  s21_decimal dec_1 = {{0x524a9e, 0x0, 0x0, 0x10000}};
  // 332.2530900174361663
  s21_decimal dec_2 = {{0xc26d43f, 0x2e1c0040, 0x0, 0x100000}};
  // 539637.6530900174361663
  s21_decimal dec_check = {{0x1fa9d43f, 0x89c4b7a0, 0x124, 0x100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_237) {
  // -98777522245689775133899
  s21_decimal dec_1 = {{0x604a94cb, 0xbd7e70b6, 0x14ea, 0x80000000}};
  // 1122926546524352273152082379
  s21_decimal dec_2 = {{0x2e6e01cb, 0x106d45ff, 0x3a0dcf2, 0x0}};
  // 1122827769002106583376948480
  s21_decimal dec_check = {{0xce236d00, 0x52eed548, 0x3a0c807, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_238) {
  // 775.0788493144214
  s21_decimal dec_1 = {{0x12dcf096, 0x1b894d, 0x0, 0xd0000}};
  // -33979703886836997775927085074
  s21_decimal dec_2 = {{0x30650812, 0xb9e459c7, 0x6dcb5a2e, 0x80000000}};
  // -33979703886836997775927084299
  s21_decimal dec_check = {{0x3065050b, 0xb9e459c7, 0x6dcb5a2e, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_239) {
  // -258795
  s21_decimal dec_1 = {{0x3f2eb, 0x0, 0x0, 0x80000000}};
  // -259058331577
  s21_decimal dec_2 = {{0x51146fb9, 0x3c, 0x0, 0x80000000}};
  // -259058590372
  s21_decimal dec_check = {{0x511862a4, 0x3c, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_242) {
  // -30935688947777.2694516638
  s21_decimal dec_1 = {{0xd33ff39e, 0x4544e0fc, 0x4182, 0x800a0000}};
  // 0.6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x10000}};
  // -30935688947776.6694516638
  s21_decimal dec_check = {{0x6d9f379e, 0x4544e0fb, 0x4182, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_243) {
  // 16544417807.3
  s21_decimal dec_1 = {{0x853dd099, 0x26, 0x0, 0x10000}};
  // 2592520322439459086999463
  s21_decimal dec_2 = {{0xe3931fa7, 0xceec1954, 0x224fc, 0x0}};
  // 2592520322439475631417270.3
  s21_decimal dec_check = {{0x68fd0d1f, 0x1538fd77, 0x1571e0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_246) {
  // 3142
  s21_decimal dec_1 = {{0xc46, 0x0, 0x0, 0x0}};
  // -14601020355
  s21_decimal dec_2 = {{0x6649e3c3, 0x3, 0x0, 0x80000000}};
  // -14601017213
  s21_decimal dec_check = {{0x6649d77d, 0x3, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_247) {
  // -31
  s21_decimal dec_1 = {{0x1f, 0x0, 0x0, 0x80000000}};
  // 8843724769494577054921765356
  s21_decimal dec_2 = {{0xe38fb1ec, 0x65c230e1, 0x1c935b90, 0x0}};
  // 8843724769494577054921765325
  s21_decimal dec_check = {{0xe38fb1cd, 0x65c230e1, 0x1c935b90, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_248) {
  // 6824661655725299035874977434
  s21_decimal dec_1 = {{0x213ee69a, 0xae488b7e, 0x160d3a51, 0x0}};
  // 55406534169.4006557860
  s21_decimal dec_2 = {{0xeab07ca4, 0x93384b4, 0x1e, 0xa0000}};
  // 6824661655725299091281511603.4
  s21_decimal dec_check = {{0x4d532f02, 0xced5736e, 0xdc844730, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_249) {
  // 8.7
  s21_decimal dec_1 = {{0x57, 0x0, 0x0, 0x10000}};
  // 27003543
  s21_decimal dec_2 = {{0x19c0a97, 0x0, 0x0, 0x0}};
  // 27003551.7
  s21_decimal dec_check = {{0x10186a3d, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_250) {
  // 4215544325.00269106
  s21_decimal dec_1 = {{0xdaab8032, 0x5d9a985, 0x0, 0x80000}};
  // -54634480.76642870715
  s21_decimal dec_2 = {{0x4116e5bb, 0x4bd21114, 0x0, 0x800b0000}};
  // 4160909844.23626235285
  s21_decimal dec_check = {{0xecd5dd95, 0x8e6c21c9, 0x16, 0xb0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_251) {
  // 69430961113248730231745696.60
  s21_decimal dec_1 = {{0xa6c96ebc, 0x623a7125, 0x166f31ca, 0x20000}};
  // 3388879717
  s21_decimal dec_2 = {{0xc9fe3365, 0x0, 0x0, 0x0}};
  // 69430961113248733620625413.60
  s21_decimal dec_check = {{0x8e158230, 0x623a7174, 0x166f31ca, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_253) {
  // 191720
  s21_decimal dec_1 = {{0x2ece8, 0x0, 0x0, 0x0}};
  // 61976021.0
  s21_decimal dec_2 = {{0x24f0ca52, 0x0, 0x0, 0x10000}};
  // 62167741.0
  s21_decimal dec_check = {{0x250e0b62, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_254) {
  // 9786649581827465560911790
  s21_decimal dec_1 = {{0xda16efae, 0x563efc52, 0x81867, 0x0}};
  // -54723673021445388565
  s21_decimal dec_2 = {{0xafe13915, 0xf7718aac, 0x2, 0x80000000}};
  // 9786594858154444115523225
  s21_decimal dec_check = {{0x2a35b699, 0x5ecd71a6, 0x81864, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_255) {
  // 69249463029983
  s21_decimal dec_1 = {{0x65a510df, 0x3efb, 0x0, 0x0}};
  // 2907108822308870986
  s21_decimal dec_2 = {{0x451fdb4a, 0x28582012, 0x0, 0x0}};
  // 2907178071771900969
  s21_decimal dec_check = {{0xaac4ec29, 0x28585f0d, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_256) {
  // 15058852130791963147
  s21_decimal dec_1 = {{0x4cfd3a0b, 0xd0fbca3a, 0x0, 0x0}};
  // -521320.0644068720546954460902
  s21_decimal dec_2 = {{0xaf8dbee6, 0x31f28667, 0x10d8422d, 0x80160000}};
  // 15058852130791441826.935593128
  s21_decimal dec_check = {{0xfa29d8a8, 0xc460d351, 0x30a863f9, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_257) {
  // 3250725066994321442002375924
  s21_decimal dec_1 = {{0xec0314f4, 0xfd4a668b, 0xa80efce, 0x0}};
  // 6033270371200521372
  s21_decimal dec_2 = {{0xdd4bd49c, 0x53ba7b6f, 0x0, 0x0}};
  // 3250725073027591813202897296
  s21_decimal dec_check = {{0xc94ee990, 0x5104e1fb, 0xa80efcf, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_258) {
  // -501
  s21_decimal dec_1 = {{0x1f5, 0x0, 0x0, 0x80000000}};
  // 238078.26907494313
  s21_decimal dec_2 = {{0xa9b1f7a9, 0x549517, 0x0, 0xb0000}};
  // 237577.26907494313
  s21_decimal dec_check = {{0xd8fdefa9, 0x546786, 0x0, 0xb0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_259) {
  // -438506263785990484460686649
  s21_decimal dec_1 = {{0xdd19cd39, 0x3138306a, 0x16ab950, 0x80000000}};
  // 4684.659282219464533542
  s21_decimal dec_2 = {{0x3b9a2626, 0xf4b51cca, 0xfd, 0x120000}};
  // -438506263785990484460681964.34
  s21_decimal dec_check = {{0x5e0d0452, 0x39f2e9be, 0x8db06353, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_260) {
  // -877.25685032742
  s21_decimal dec_1 = {{0x3a4b4726, 0x4fc9, 0x0, 0x800b0000}};
  // 39662446645689
  s21_decimal dec_2 = {{0xa20b11b9, 0x2412, 0x0, 0x0}};
  // 39662446644811.74314967258
  s21_decimal dec_check = {{0x10a60da, 0x8dd8f8c6, 0x347e2, 0xb0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_261) {
  // -0.15888041
  s21_decimal dec_1 = {{0xf26ea9, 0x0, 0x0, 0x80080000}};
  // 25875.009
  s21_decimal dec_2 = {{0x18ad241, 0x0, 0x0, 0x30000}};
  // 25874.85011959
  s21_decimal dec_check = {{0x721ffff7, 0x25a, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_262) {
  // 16803
  s21_decimal dec_1 = {{0x41a3, 0x0, 0x0, 0x0}};
  // 338983.73612101893211696029
  s21_decimal dec_2 = {{0x5a2e2b9d, 0x8404cde9, 0x1c0a42, 0x140000}};
  // 355786.73612101893211696029
  s21_decimal dec_check = {{0x7d5e2b9d, 0xc2df4af6, 0x1d6e13, 0x140000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_263) {
  // 9469162.00141777643131767767
  s21_decimal dec_1 = {{0x34960bd7, 0x11597c7c, 0x30f454e, 0x140000}};
  // 9766.5486
  s21_decimal dec_2 = {{0x5d241ce, 0x0, 0x0, 0x40000}};
  // 9478928.55001777643131767767
  s21_decimal dec_check = {{0x22e40bd7, 0xa2421344, 0x310141e, 0x140000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_264) {
  // -776870.678586998555597528
  s21_decimal dec_1 = {{0x58f2dad8, 0x3e6e799d, 0xa482, 0x80120000}};
  // 20381.808880932812788405650
  s21_decimal dec_2 = {{0xcfd1592, 0x12c9fccf, 0x10dc04, 0x150000}};
  // -756488.869706065742809122350
  s21_decimal dec_check = {{0x67a9c62e, 0xccc111d4, 0x271c0bf, 0x80150000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_265) {
  // 93250685
  s21_decimal dec_1 = {{0x58ee47d, 0x0, 0x0, 0x0}};
  // 6154788
  s21_decimal dec_2 = {{0x5dea24, 0x0, 0x0, 0x0}};
  // 99405473
  s21_decimal dec_check = {{0x5eccea1, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_266) {
  // -66680739
  s21_decimal dec_1 = {{0x3f977a3, 0x0, 0x0, 0x80000000}};
  // -2534416441963468440500
  s21_decimal dec_2 = {{0x4df243b4, 0x6417f60d, 0x89, 0x80000000}};
  // -2534416441963535121239
  s21_decimal dec_check = {{0x51ebbb57, 0x6417f60d, 0x89, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_267) {
  // 413470.64675
  s21_decimal dec_1 = {{0xa07a2363, 0x9, 0x0, 0x50000}};
  // -30669015493083105
  s21_decimal dec_2 = {{0x9e137fe1, 0x6cf54e, 0x0, 0x80000000}};
  // -30669015492669634.35325
  s21_decimal dec_check = {{0xe0868f3d, 0x41cf15ea, 0xa6, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_268) {
  // 76477
  s21_decimal dec_1 = {{0x12abd, 0x0, 0x0, 0x0}};
  // -13069912.29
  s21_decimal dec_2 = {{0x4de71a7d, 0x0, 0x0, 0x80020000}};
  // -12993435.29
  s21_decimal dec_check = {{0x4d7268a9, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_269) {
  // -9956968314278752952
  s21_decimal dec_1 = {{0x7467b2b8, 0x8a2e41ed, 0x0, 0x80000000}};
  // 1
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  // -9956968314278752951
  s21_decimal dec_check = {{0x7467b2b7, 0x8a2e41ed, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_270) {
  // -398
  s21_decimal dec_1 = {{0x18e, 0x0, 0x0, 0x80000000}};
  // -36324099925534017595763
  s21_decimal dec_2 = {{0x902c2973, 0x2226acf1, 0x7b1, 0x80000000}};
  // -36324099925534017596161
  s21_decimal dec_check = {{0x902c2b01, 0x2226acf1, 0x7b1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_271) {
  // -4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x80000000}};
  // -7101061090.08072
  s21_decimal dec_2 = {{0x766158c8, 0x285d6, 0x0, 0x80050000}};
  // -7101061094.08072
  s21_decimal dec_check = {{0x76677348, 0x285d6, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_272) {
  // -3810918163047983788.300
  s21_decimal dec_1 = {{0xaf3eb10c, 0x971d162e, 0xce, 0x80030000}};
  // 3713567131251761850728
  s21_decimal dec_2 = {{0x33ada968, 0x5018be8d, 0xc9, 0x0}};
  // 3709756213088713866939.700
  s21_decimal dec_check = {{0x2f1f0d34, 0x498b4163, 0x31192, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_273) {
  // -208
  s21_decimal dec_1 = {{0xd0, 0x0, 0x0, 0x80000000}};
  // 80242380.625
  s21_decimal dec_2 = {{0xaed18f51, 0x12, 0x0, 0x30000}};
  // 80242172.625
  s21_decimal dec_check = {{0xaece62d1, 0x12, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_274) {
  // 4043144373125
  s21_decimal dec_1 = {{0x5e2f2385, 0x3ad, 0x0, 0x0}};
  // 490784393308122609053004
  s21_decimal dec_2 = {{0x17e36d4c, 0x79ab7294, 0x67ed, 0x0}};
  // 490784393312165753426129
  s21_decimal dec_check = {{0x761290d1, 0x79ab7641, 0x67ed, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_275) {
  // 811.950
  s21_decimal dec_1 = {{0xc63ae, 0x0, 0x0, 0x30000}};
  // -9.1
  s21_decimal dec_2 = {{0x5b, 0x0, 0x0, 0x80010000}};
  // 802.850
  s21_decimal dec_check = {{0xc4022, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_276) {
  // -5205463556308788295125.718325
  s21_decimal dec_1 = {{0x27545535, 0xd3c3bbd9, 0x10d1dbc8, 0x80060000}};
  // -3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x80000000}};
  // -5205463556308788295128.718325
  s21_decimal dec_check = {{0x27821bf5, 0xd3c3bbd9, 0x10d1dbc8, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_277) {
  // -568383
  s21_decimal dec_1 = {{0x8ac3f, 0x0, 0x0, 0x80000000}};
  // -7236628822805351236048079482
  s21_decimal dec_2 = {{0x7a94a7a, 0x8ece89ab, 0x1761ffc2, 0x80000000}};
  // -7236628822805351236048647865
  s21_decimal dec_check = {{0x7b1f6b9, 0x8ece89ab, 0x1761ffc2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_278) {
  // -21517.956875
  s21_decimal dec_1 = {{0x291f70b, 0x5, 0x0, 0x80060000}};
  // -445724407
  s21_decimal dec_2 = {{0x1a9136f7, 0x0, 0x0, 0x80000000}};
  // -445745924.956875
  s21_decimal dec_check = {{0x4f8462cb, 0x19567, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_279) {
  // 649184985501620735
  s21_decimal dec_1 = {{0x65759ff, 0x9025e4e, 0x0, 0x0}};
  // 71.633285
  s21_decimal dec_2 = {{0x4450985, 0x0, 0x0, 0x60000}};
  // 649184985501620806.633285
  s21_decimal dec_check = {{0x65404745, 0x637a1042, 0x8978, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_280) {
  // 50801589.4734737895923838882
  s21_decimal dec_1 = {{0x5026efa2, 0xd6202dbf, 0x1a4388c, 0x130000}};
  // 32969713462465800890339263732
  s21_decimal dec_2 = {{0xa7d384f4, 0x1c8b46d5, 0x6a87e864, 0x0}};
  // 32969713462465800890390065321
  s21_decimal dec_check = {{0xaadab0a9, 0x1c8b46d5, 0x6a87e864, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_281) {
  // 509
  s21_decimal dec_1 = {{0x1fd, 0x0, 0x0, 0x0}};
  // 5933617018
  s21_decimal dec_2 = {{0x61abcf7a, 0x1, 0x0, 0x0}};
  // 5933617527
  s21_decimal dec_check = {{0x61abd177, 0x1, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_282) {
  // -5
  s21_decimal dec_1 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 55737542316693709210596300810
  s21_decimal dec_2 = {{0x5232580a, 0x702780bc, 0xb41903af, 0x0}};
  // 55737542316693709210596300805
  s21_decimal dec_check = {{0x52325805, 0x702780bc, 0xb41903af, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_283) {
  // 72.3
  s21_decimal dec_1 = {{0x2d3, 0x0, 0x0, 0x10000}};
  // -8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 64.3
  s21_decimal dec_check = {{0x283, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_284) {
  // 51400232551737
  s21_decimal dec_1 = {{0x8c9a4539, 0x2ebf, 0x0, 0x0}};
  // 356338704302887964107
  s21_decimal dec_2 = {{0xa0988dcb, 0x51316399, 0x13, 0x0}};
  // 356338755703120515844
  s21_decimal dec_check = {{0x2d32d304, 0x51319259, 0x13, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_285) {
  // 0.0194641563
  s21_decimal dec_1 = {{0xb99fe9b, 0x0, 0x0, 0xa0000}};
  // -576352962029707806540
  s21_decimal dec_2 = {{0x30ef474c, 0x3e810d51, 0x1f, 0x80000000}};
  // -576352962029707806539.98053584
  s21_decimal dec_check = {{0x54818d0, 0xc15cdd66, 0xba3accb3, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_286) {
  // -471727046616483323292100591
  s21_decimal dec_1 = {{0x7a1f27ef, 0x70268ab7, 0x1863416, 0x80000000}};
  // -94.540838042321
  s21_decimal dec_2 = {{0x1117ad1, 0x55fc, 0x0, 0x800c0000}};
  // -471727046616483323292100685.54
  s21_decimal dec_check = {{0xb42bbe4a, 0xcf0e2fab, 0x986c58c3, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_287) {
  // 5495724604968410877312
  s21_decimal dec_1 = {{0x34190d80, 0xec7ffa9f, 0x129, 0x0}};
  // -22496239030558266632616077.843
  s21_decimal dec_2 = {{0xbc20ea13, 0x7bf612f7, 0x48b073e9, 0x80030000}};
  // -22490743305953298221738765.843
  s21_decimal dec_check = {{0x3a442e13, 0xa80b1514, 0x48abe825, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_288) {
  // -6.9585508
  s21_decimal dec_1 = {{0x425ca64, 0x0, 0x0, 0x80070000}};
  // 3219.05455
  s21_decimal dec_2 = {{0x132fe32f, 0x0, 0x0, 0x50000}};
  // 3212.0959992
  s21_decimal dec_check = {{0x7a8ef3f8, 0x7, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_289) {
  // 71818489760819279630611223
  s21_decimal dec_1 = {{0x54eab317, 0x21940e6e, 0x3b6828, 0x0}};
  // -47726
  s21_decimal dec_2 = {{0xba6e, 0x0, 0x0, 0x80000000}};
  // 71818489760819279630563497
  s21_decimal dec_check = {{0x54e9f8a9, 0x21940e6e, 0x3b6828, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_290) {
  // 460.8856544
  s21_decimal dec_1 = {{0x12b591e0, 0x1, 0x0, 0x70000}};
  // -5737489492185547864.9202870558
  s21_decimal dec_2 = {{0xe2f091e, 0x5295b5a, 0xb9636696, 0x800a0000}};
  // -5737489492185547404.0346326558
  s21_decimal dec_check = {{0xf8ed361e, 0x5295728, 0xb9636696, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_292) {
  // -42390777864041438514174431363
  s21_decimal dec_1 = {{0xe8831083, 0xad5d8002, 0x88f8d460, 0x80000000}};
  // -81570752606253448638309.7888
  s21_decimal dec_2 = {{0x96b7820, 0x97eee1e4, 0x2a2bcc9, 0x80040000}};
  // -42390859434794044767623069673
  s21_decimal dec_check = {{0x76563fe9, 0xa2f61307, 0x88f8e5a6, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_293) {
  // -79808199599887011203658
  s21_decimal dec_1 = {{0x3182ca4a, 0x69426622, 0x10e6, 0x80000000}};
  // 1698
  s21_decimal dec_2 = {{0x6a2, 0x0, 0x0, 0x0}};
  // -79808199599887011201960
  s21_decimal dec_check = {{0x3182c3a8, 0x69426622, 0x10e6, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_294) {
  // 96419134297
  s21_decimal dec_1 = {{0x73073b59, 0x16, 0x0, 0x0}};
  // -5950081434442594830216039600
  s21_decimal dec_2 = {{0x689b8cb0, 0xe2691cd8, 0x1339cac0, 0x80000000}};
  // -5950081434442594733796905303
  s21_decimal dec_check = {{0xf5945157, 0xe2691cc1, 0x1339cac0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_295) {
  // 62
  s21_decimal dec_1 = {{0x3e, 0x0, 0x0, 0x0}};
  // -907026309
  s21_decimal dec_2 = {{0x36101f85, 0x0, 0x0, 0x80000000}};
  // -907026247
  s21_decimal dec_check = {{0x36101f47, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_296) {
  // 33928
  s21_decimal dec_1 = {{0x8488, 0x0, 0x0, 0x0}};
  // -715519362401754288741895
  s21_decimal dec_2 = {{0xdaf7de07, 0x61e24056, 0x9784, 0x80000000}};
  // -715519362401754288707967
  s21_decimal dec_check = {{0xdaf7597f, 0x61e24056, 0x9784, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_297) {
  // -41269236
  s21_decimal dec_1 = {{0x275b7f4, 0x0, 0x0, 0x80000000}};
  // -849020200.405
  s21_decimal dec_2 = {{0xad8c25d5, 0xc5, 0x0, 0x80030000}};
  // -890289436.405
  s21_decimal dec_check = {{0x4962b6f5, 0xcf, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_298) {
  // -84859.0209237
  s21_decimal dec_1 = {{0x93eb00d5, 0xc5, 0x0, 0x80070000}};
  // -0.11
  s21_decimal dec_2 = {{0xb, 0x0, 0x0, 0x80020000}};
  // -84859.1309237
  s21_decimal dec_check = {{0x93fbc9b5, 0xc5, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_300) {
  // -3674456556143417408670778
  s21_decimal dec_1 = {{0x530cc3a, 0xb0652b3d, 0x30a18, 0x80000000}};
  // 3831516269290487851967758
  s21_decimal dec_2 = {{0x8fbee50e, 0xe9c47479, 0x32b5a, 0x0}};
  // 157059713147070443296980
  s21_decimal dec_check = {{0x8a8e18d4, 0x395f493c, 0x2142, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_301) {
  // -32537194617643082788349
  s21_decimal dec_1 = {{0xfbd2dfd, 0xd848634d, 0x6e3, 0x80000000}};
  // -951.07867543078861069231731
  s21_decimal dec_2 = {{0x7a9a2673, 0xd49dd7ab, 0x4eabdf, 0x80170000}};
  // -32537194617643082789300.078675
  s21_decimal dec_check = {{0x9faa0853, 0x8d369d68, 0x692222f6, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_302) {
  // -95
  s21_decimal dec_1 = {{0x5f, 0x0, 0x0, 0x80000000}};
  // -91.47107869030
  s21_decimal dec_2 = {{0xba1d8166, 0x851, 0x0, 0x800b0000}};
  // -186.47107869030
  s21_decimal dec_check = {{0x9e3d9966, 0x10f5, 0x0, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_303) {
  // -54224468
  s21_decimal dec_1 = {{0x33b6654, 0x0, 0x0, 0x80000000}};
  // -8404.782
  s21_decimal dec_2 = {{0x803f2e, 0x0, 0x0, 0x80030000}};
  // -54232872.782
  s21_decimal dec_check = {{0xa087f74e, 0xc, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_304) {
  // 831135172856468869
  s21_decimal dec_1 = {{0x42715585, 0xb88c909, 0x0, 0x0}};
  // -0.3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x80010000}};
  // 831135172856468868.7
  s21_decimal dec_check = {{0x986d572f, 0x7357da5c, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_305) {
  // -9920445974903358082952025916
  s21_decimal dec_1 = {{0x81ed573c, 0xe69887fd, 0x200e0025, 0x80000000}};
  // -648145183200621062
  s21_decimal dec_2 = {{0x2f8db206, 0x8feac9c, 0x0, 0x80000000}};
  // -9920445975551503266152646978
  s21_decimal dec_check = {{0xb17b0942, 0xef973499, 0x200e0025, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_306) {
  // 7804
  s21_decimal dec_1 = {{0x1e7c, 0x0, 0x0, 0x0}};
  // -81606378920455
  s21_decimal dec_2 = {{0x773a1a07, 0x4a38, 0x0, 0x80000000}};
  // -81606378912651
  s21_decimal dec_check = {{0x7739fb8b, 0x4a38, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_307) {
  // -1700
  s21_decimal dec_1 = {{0x6a4, 0x0, 0x0, 0x80000000}};
  // 506.22
  s21_decimal dec_2 = {{0xc5be, 0x0, 0x0, 0x20000}};
  // -1193.78
  s21_decimal dec_check = {{0x1d252, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_308) {
  // -13964714024.53
  s21_decimal dec_1 = {{0x242e8fd5, 0x145, 0x0, 0x80020000}};
  // -82442446358
  s21_decimal dec_2 = {{0x31f3e616, 0x13, 0x0, 0x80000000}};
  // -96407160382.53
  s21_decimal dec_check = {{0xa774706d, 0x8c4, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_309) {
  // 26
  s21_decimal dec_1 = {{0x1a, 0x0, 0x0, 0x0}};
  // -953
  s21_decimal dec_2 = {{0x3b9, 0x0, 0x0, 0x80000000}};
  // -927
  s21_decimal dec_check = {{0x39f, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_310) {
  // -273110
  s21_decimal dec_1 = {{0x42ad6, 0x0, 0x0, 0x80000000}};
  // -26
  s21_decimal dec_2 = {{0x1a, 0x0, 0x0, 0x80000000}};
  // -273136
  s21_decimal dec_check = {{0x42af0, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_311) {
  // -43.1477280155530682547167373
  s21_decimal dec_1 = {{0xe165e08d, 0x39e43095, 0x164e8de, 0x80190000}};
  // -309406.81466150711085
  s21_decimal dec_2 = {{0xda6cef2d, 0xad6361dc, 0x1, 0x800e0000}};
  // -309449.96238952266391825471674
  s21_decimal dec_check = {{0x95c4d8ba, 0x7dcbc57d, 0x63fd19d7, 0x80170000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_312) {
  // -9744870721365
  s21_decimal dec_1 = {{0xe78ec755, 0x8dc, 0x0, 0x80000000}};
  // 37111224046480997238180
  s21_decimal dec_2 = {{0x228045a4, 0xcdb14e95, 0x7db, 0x0}};
  // 37111224036736126516815
  s21_decimal dec_check = {{0x3af17e4f, 0xcdb145b8, 0x7db, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_313) {
  // -7301055314886037
  s21_decimal dec_1 = {{0x68877d95, 0x19f045, 0x0, 0x80000000}};
  // 69342250
  s21_decimal dec_2 = {{0x422142a, 0x0, 0x0, 0x0}};
  // -7301055245543787
  s21_decimal dec_check = {{0x6465696b, 0x19f045, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_314) {
  // 4798636229021.280858432624
  s21_decimal dec_1 = {{0x92c26470, 0x975a6e7a, 0x3f826, 0xc0000}};
  // 3245
  s21_decimal dec_2 = {{0xcad, 0x0, 0x0, 0x0}};
  // 4798636232266.280858432624
  s21_decimal dec_check = {{0x30e3470, 0x9765f5ca, 0x3f826, 0xc0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_315) {
  // -7557779976862756799831
  s21_decimal dec_1 = {{0x48988557, 0xb5444e1f, 0x199, 0x80000000}};
  // -338205417118.586144382
  s21_decimal dec_2 = {{0xf224867e, 0x558b02fa, 0x12, 0x80090000}};
  // -7557779977200962216949.5861444
  s21_decimal dec_check = {{0x62b4f8c4, 0x396ff716, 0xf4347d9f, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_316) {
  // -341400233177
  s21_decimal dec_1 = {{0x7d0a24d9, 0x4f, 0x0, 0x80000000}};
  // 437528940847361627371308853
  s21_decimal dec_2 = {{0xbdf38735, 0x68db8452, 0x169ea5b, 0x0}};
  // 437528940847361285971075676
  s21_decimal dec_check = {{0x40e9625c, 0x68db8403, 0x169ea5b, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_317) {
  // 24222795288134374
  s21_decimal dec_1 = {{0x49dc2e6, 0x560e81, 0x0, 0x0}};
  // 401664838.30173088
  s21_decimal dec_2 = {{0x4892eda0, 0x8eb334, 0x0, 0x80000}};
  // 24222795689799212.30173088
  s21_decimal dec_check = {{0xf4fd13a0, 0x9de980c, 0x200f0, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_318) {
  // 351148315213.1654651
  s21_decimal dec_1 = {{0x7d9383fb, 0x30bb4b52, 0x0, 0x70000}};
  // 3046631
  s21_decimal dec_2 = {{0x2e7ce7, 0x0, 0x0, 0x0}};
  // 351151361844.1654651
  s21_decimal dec_check = {{0xfb29517b, 0x30bb6707, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_320) {
  // -930805924659.90
  s21_decimal dec_1 = {{0x3a64046, 0x54a8, 0x0, 0x80020000}};
  // -79975383881
  s21_decimal dec_2 = {{0x9ee78349, 0x12, 0x0, 0x80000000}};
  // -1010781308540.90
  s21_decimal dec_check = {{0x161588ca, 0x5bee, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_321) {
  // 48743
  s21_decimal dec_1 = {{0xbe67, 0x0, 0x0, 0x0}};
  // 622098986006280365041611304
  s21_decimal dec_2 = {{0x8dc57228, 0x9b406f04, 0x2029695, 0x0}};
  // 622098986006280365041660047
  s21_decimal dec_check = {{0x8dc6308f, 0x9b406f04, 0x2029695, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_322) {
  // 51046
  s21_decimal dec_1 = {{0xc766, 0x0, 0x0, 0x0}};
  // 7086
  s21_decimal dec_2 = {{0x1bae, 0x0, 0x0, 0x0}};
  // 58132
  s21_decimal dec_check = {{0xe314, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_323) {
  // 4570511170667947.01435
  s21_decimal dec_1 = {{0x61c6127b, 0xc6dbc169, 0x18, 0x50000}};
  // -559284.48080201976
  s21_decimal dec_2 = {{0x90a8c8f8, 0xc6b2a0, 0x0, 0x800b0000}};
  // 4570511170108662.53354798024
  s21_decimal dec_check = {{0x6d48bc8, 0xb3338d88, 0x17a1056, 0xb0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_324) {
  // -5583179232835
  s21_decimal dec_1 = {{0xef6a3643, 0x513, 0x0, 0x80000000}};
  // -43161775308
  s21_decimal dec_2 = {{0xca46ccc, 0xa, 0x0, 0x80000000}};
  // -5626341008143
  s21_decimal dec_check = {{0xfc0ea30f, 0x51d, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_325) {
  // 14
  s21_decimal dec_1 = {{0xe, 0x0, 0x0, 0x0}};
  // -215792374182870994022724
  s21_decimal dec_2 = {{0x88627144, 0x20c78a52, 0x2db2, 0x80000000}};
  // -215792374182870994022710
  s21_decimal dec_check = {{0x88627136, 0x20c78a52, 0x2db2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_326) {
  // 905299956114263
  s21_decimal dec_1 = {{0x924ca357, 0x3375d, 0x0, 0x0}};
  // 85710346557820373074299
  s21_decimal dec_2 = {{0x8bf0817b, 0x5e00a175, 0x1226, 0x0}};
  // 85710347463120329188562
  s21_decimal dec_check = {{0x1e3d24d2, 0x5e03d8d3, 0x1226, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_327) {
  // -42
  s21_decimal dec_1 = {{0x2a, 0x0, 0x0, 0x80000000}};
  // 89422695100.71
  s21_decimal dec_2 = {{0x8cc31b7, 0x822, 0x0, 0x20000}};
  // 89422695058.71
  s21_decimal dec_check = {{0x8cc214f, 0x822, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_328) {
  // -0.05
  s21_decimal dec_1 = {{0x5, 0x0, 0x0, 0x80020000}};
  // -52972
  s21_decimal dec_2 = {{0xceec, 0x0, 0x0, 0x80000000}};
  // -52972.05
  s21_decimal dec_check = {{0x50d435, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_329) {
  // -81542744
  s21_decimal dec_1 = {{0x4dc3e58, 0x0, 0x0, 0x80000000}};
  // -886237.98
  s21_decimal dec_2 = {{0x5484ab6, 0x0, 0x0, 0x80020000}};
  // -82428981.98
  s21_decimal dec_check = {{0xeb50a516, 0x1, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_330) {
  // 807641037024.10
  s21_decimal dec_1 = {{0x5bb6378a, 0x4974, 0x0, 0x20000}};
  // -0.271
  s21_decimal dec_2 = {{0x10f, 0x0, 0x0, 0x80030000}};
  // 807641037023.829
  s21_decimal dec_check = {{0x951e2a55, 0x2de8b, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_331) {
  // -21005975185.78429527
  s21_decimal dec_1 = {{0x4eef2e57, 0x1d26d250, 0x0, 0x80080000}};
  // -4344719158953243102
  s21_decimal dec_2 = {{0x463df1de, 0x3c4b8b0e, 0x0, 0x80000000}};
  // -4344719179959218287.78429527
  s21_decimal dec_check = {{0x8ff94c57, 0xde66cd0e, 0x1676301, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_332) {
  // 0.648
  s21_decimal dec_1 = {{0x288, 0x0, 0x0, 0x30000}};
  // 4027820644.25
  s21_decimal dec_2 = {{0xc7ae8f29, 0x5d, 0x0, 0x20000}};
  // 4027820644.898
  s21_decimal dec_check = {{0xccd19a22, 0x3a9, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_333) {
  // 971202515732174162961974
  s21_decimal dec_1 = {{0x8e012636, 0xfe6e86f3, 0xcda8, 0x0}};
  // 5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};
  // 971202515732174162961979
  s21_decimal dec_check = {{0x8e01263b, 0xfe6e86f3, 0xcda8, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_334) {
  // 90098496597824730
  s21_decimal dec_1 = {{0xf48294da, 0x140181a, 0x0, 0x0}};
  // -1441587237982009657851.8
  s21_decimal dec_2 = {{0x8def63d6, 0x7c6afee1, 0x30d, 0x80010000}};
  // -1441497139485411833121.8
  s21_decimal dec_check = {{0xd59352, 0x6fea0dd4, 0x30d, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_335) {
  // 28.055227
  s21_decimal dec_1 = {{0x1ac16bb, 0x0, 0x0, 0x60000}};
  // -589186216399137386867003361
  s21_decimal dec_2 = {{0x1a690fe1, 0xca79ed6b, 0x1e75d08, 0x80000000}};
  // -589186216399137386867003332.94
  s21_decimal dec_check = {{0x510a28ee, 0x17a0bdd6, 0xbe60576f, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_336) {
  // 16912510
  s21_decimal dec_1 = {{0x102107e, 0x0, 0x0, 0x0}};
  // -0.570330854616565
  s21_decimal dec_2 = {{0x7ffe6df5, 0x206b6, 0x0, 0x800f0000}};
  // 16912509.429669145383435
  s21_decimal dec_check = {{0x1b4920b, 0xd43797f8, 0x394, 0xf0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_337) {
  // 24803854011581.016097
  s21_decimal dec_1 = {{0x9cef2821, 0x5838fdce, 0x1, 0x60000}};
  // 13448603061
  s21_decimal dec_2 = {{0x219965b5, 0x3, 0x0, 0x0}};
  // 24817302614642.016097
  s21_decimal dec_check = {{0x851c3f61, 0x5868c53d, 0x1, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_338) {
  // -8661351308
  s21_decimal dec_1 = {{0x441bb8c, 0x2, 0x0, 0x80000000}};
  // -6.9
  s21_decimal dec_2 = {{0x45, 0x0, 0x0, 0x80010000}};
  // -8661351314.9
  s21_decimal dec_check = {{0x2a9153bd, 0x14, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_339) {
  // -62367749157976854112
  s21_decimal dec_1 = {{0xb1e0ce60, 0x6186c16b, 0x3, 0x80000000}};
  // -622579755
  s21_decimal dec_2 = {{0x251bd02b, 0x0, 0x0, 0x80000000}};
  // -62367749158599433867
  s21_decimal dec_check = {{0xd6fc9e8b, 0x6186c16b, 0x3, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_340) {
  // -2280
  s21_decimal dec_1 = {{0x8e8, 0x0, 0x0, 0x80000000}};
  // -49
  s21_decimal dec_2 = {{0x31, 0x0, 0x0, 0x80000000}};
  // -2329
  s21_decimal dec_check = {{0x919, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_342) {
  // -0.1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x80010000}};
  // -7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x80000000}};
  // -7.1
  s21_decimal dec_check = {{0x47, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_343) {
  // 4493604641836143311196702
  s21_decimal dec_1 = {{0x8c22121e, 0xcbb62c35, 0x3b78e, 0x0}};
  // -23045
  s21_decimal dec_2 = {{0x5a05, 0x0, 0x0, 0x80000000}};
  // 4493604641836143311173657
  s21_decimal dec_check = {{0x8c21b819, 0xcbb62c35, 0x3b78e, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_344) {
  // -3.5095
  s21_decimal dec_1 = {{0x8917, 0x0, 0x0, 0x80040000}};
  // 84610799.247414
  s21_decimal dec_2 = {{0xfca22036, 0x4cf3, 0x0, 0x60000}};
  // 84610795.737914
  s21_decimal dec_check = {{0xfc6c933a, 0x4cf3, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_345) {
  // 9633912786
  s21_decimal dec_1 = {{0x3e39d7d2, 0x2, 0x0, 0x0}};
  // -4888380847.01362328629
  s21_decimal dec_2 = {{0x8b041435, 0x7ffdc00f, 0x1a, 0x800b0000}};
  // 4745531938.98637671371
  s21_decimal dec_check = {{0x6b5e3bcb, 0xb9bf9f8f, 0x19, 0xb0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_346) {
  // 3.8537
  s21_decimal dec_1 = {{0x9689, 0x0, 0x0, 0x40000}};
  // -510437648685.0308
  s21_decimal dec_2 = {{0x434c6f04, 0x122267, 0x0, 0x80040000}};
  // -510437648681.1771
  s21_decimal dec_check = {{0x434bd87b, 0x122267, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_347) {
  // 1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  // -45343.311901296766
  s21_decimal dec_2 = {{0x7ed1087e, 0xa11780, 0x0, 0x800c0000}};
  // -45342.311901296766
  s21_decimal dec_check = {{0xaa2bf87e, 0xa11697, 0x0, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_348) {
  // -2423226379347.3
  s21_decimal dec_1 = {{0x379bb41, 0x160a, 0x0, 0x80010000}};
  // -4478.96
  s21_decimal dec_2 = {{0x6d598, 0x0, 0x0, 0x80020000}};
  // -2423226383826.26
  s21_decimal dec_check = {{0x22c82622, 0xdc64, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_349) {
  // 278369.127017643278
  s21_decimal dec_1 = {{0x4527d0e, 0x3dcf73f, 0x0, 0xc0000}};
  // -509348529.4897
  s21_decimal dec_2 = {{0xeb61b531, 0x4a1, 0x0, 0x80040000}};
  // -509070160.362682356722
  s21_decimal dec_check = {{0x38d293f2, 0x98c485ae, 0x1b, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_350) {
  // 281
  s21_decimal dec_1 = {{0x119, 0x0, 0x0, 0x0}};
  // 79894
  s21_decimal dec_2 = {{0x13816, 0x0, 0x0, 0x0}};
  // 80175
  s21_decimal dec_check = {{0x1392f, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_351) {
  // 26681
  s21_decimal dec_1 = {{0x6839, 0x0, 0x0, 0x0}};
  // 5649124.285526756
  s21_decimal dec_2 = {{0x3e54b2e4, 0x1411d9, 0x0, 0x90000}};
  // 5675805.285526756
  s21_decimal dec_check = {{0x65dbace4, 0x142a1d, 0x0, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_352) {
  // 34435.166
  s21_decimal dec_1 = {{0x20d705e, 0x0, 0x0, 0x30000}};
  // -517260908417814640360059095
  s21_decimal dec_2 = {{0x9ace70d7, 0x84cbe45, 0x1abde42, 0x80000000}};
  // -517260908417814640360024659.83
  s21_decimal dec_check = {{0x786f88bf, 0x3dfa5330, 0xa722d1cb, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_353) {
  // -7608168
  s21_decimal dec_1 = {{0x741768, 0x0, 0x0, 0x80000000}};
  // -86492070950
  s21_decimal dec_2 = {{0x23544426, 0x14, 0x0, 0x80000000}};
  // -86499679118
  s21_decimal dec_check = {{0x23c85b8e, 0x14, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_354) {
  // 6955843361177632284066
  s21_decimal dec_1 = {{0x7bec9da2, 0x13b7db5a, 0x179, 0x0}};
  // 721487
  s21_decimal dec_2 = {{0xb024f, 0x0, 0x0, 0x0}};
  // 6955843361177633005553
  s21_decimal dec_check = {{0x7bf79ff1, 0x13b7db5a, 0x179, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_355) {
  // -9548538504886
  s21_decimal dec_1 = {{0x313ee6b6, 0x8af, 0x0, 0x80000000}};
  // 83307876.75
  s21_decimal dec_2 = {{0xf08dbb5b, 0x1, 0x0, 0x20000}};
  // -9548455197009.25
  s21_decimal dec_check = {{0x4c0463bd, 0x3646d, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_356) {
  // 3216
  s21_decimal dec_1 = {{0xc90, 0x0, 0x0, 0x0}};
  // -1779800597932
  s21_decimal dec_2 = {{0x6461e5ac, 0x19e, 0x0, 0x80000000}};
  // -1779800594716
  s21_decimal dec_check = {{0x6461d91c, 0x19e, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_357) {
  // 62.5
  s21_decimal dec_1 = {{0x271, 0x0, 0x0, 0x10000}};
  // -772100599.8924
  s21_decimal dec_2 = {{0xafd1e34c, 0x705, 0x0, 0x80040000}};
  // -772100537.3924
  s21_decimal dec_check = {{0xafc859e4, 0x705, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_359) {
  // -661505.2
  s21_decimal dec_1 = {{0x64f00c, 0x0, 0x0, 0x80010000}};
  // -1716
  s21_decimal dec_2 = {{0x6b4, 0x0, 0x0, 0x80000000}};
  // -663221.2
  s21_decimal dec_check = {{0x653314, 0x0, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_360) {
  // 453680131779410056746634
  s21_decimal dec_1 = {{0x6fe4968a, 0xc99f904, 0x6012, 0x0}};
  // 0.88
  s21_decimal dec_2 = {{0x58, 0x0, 0x0, 0x20000}};
  // 453680131779410056746634.88
  s21_decimal dec_check = {{0xb54ace40, 0xec2545bb, 0x25870c, 0x20000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_361) {
  // -21564675276006
  s21_decimal dec_1 = {{0xeacf3ce6, 0x139c, 0x0, 0x80000000}};
  // 0.9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x10000}};
  // -21564675276005.1
  s21_decimal dec_check = {{0x2c1860f3, 0xc421, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_362) {
  // 624.84
  s21_decimal dec_1 = {{0xf414, 0x0, 0x0, 0x20000}};
  // -20638747
  s21_decimal dec_2 = {{0x13aec1b, 0x0, 0x0, 0x80000000}};
  // -20638122.16
  s21_decimal dec_check = {{0x7b034678, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_363) {
  // 6.91
  s21_decimal dec_1 = {{0x2b3, 0x0, 0x0, 0x20000}};
  // -86089194859.2200918224681780
  s21_decimal dec_2 = {{0x87a13b34, 0xc04bad7, 0x2c81cf6, 0x80100000}};
  // -86089194852.3100918224681780
  s21_decimal dec_check = {{0xda67b34, 0xb0f3cc2, 0x2c81cf6, 0x80100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_364) {
  // 91124343.609503282142786
  s21_decimal dec_1 = {{0x7e49e42, 0xdc4e0361, 0x134b, 0xf0000}};
  // 0.44
  s21_decimal dec_2 = {{0x2c, 0x0, 0x0, 0x20000}};
  // 91124344.049503282142786
  s21_decimal dec_check = {{0x83981e42, 0xdc4f938e, 0x134b, 0xf0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_365) {
  // 397864936497.439112129037
  s21_decimal dec_1 = {{0xb6f76a0d, 0x4d2a35a4, 0x5440, 0xc0000}};
  // -16945993662890909774754289.90
  s21_decimal dec_2 = {{0xf389827e, 0xb89de9fa, 0x579bd5f, 0x80020000}};
  // -16945993662890511909817792.461
  s21_decimal dec_check = {{0x5d29b7cd, 0x3629b9f2, 0x36c165bd, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_366) {
  // 716052835
  s21_decimal dec_1 = {{0x2aae1963, 0x0, 0x0, 0x0}};
  // 414591121
  s21_decimal dec_2 = {{0x18b62891, 0x0, 0x0, 0x0}};
  // 1130643956
  s21_decimal dec_check = {{0x436441f4, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_368) {
  // 752939
  s21_decimal dec_1 = {{0xb7d2b, 0x0, 0x0, 0x0}};
  // -342942806632030049944341
  s21_decimal dec_2 = {{0x1b4c4315, 0xf7802af8, 0x489e, 0x80000000}};
  // -342942806632030049191402
  s21_decimal dec_check = {{0x1b40c5ea, 0xf7802af8, 0x489e, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_369) {
  // -3.07606969
  s21_decimal dec_1 = {{0x1255b5b9, 0x0, 0x0, 0x80080000}};
  // 81496771729601064
  s21_decimal dec_2 = {{0xd148b228, 0x12188e1, 0x0, 0x0}};
  // 81496771729601060.92393031
  s21_decimal dec_check = {{0x1a877247, 0xe2822efe, 0x6bdc2, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_370) {
  // -164701206
  s21_decimal dec_1 = {{0x9d12416, 0x0, 0x0, 0x80000000}};
  // -2482522922346010
  s21_decimal dec_2 = {{0x68eee61a, 0x8d1d7, 0x0, 0x80000000}};
  // -2482523087047216
  s21_decimal dec_check = {{0x72c00a30, 0x8d1d7, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_371) {
  // 91138288355136903067597
  s21_decimal dec_1 = {{0x7f0c37cd, 0x9dd3b3a6, 0x134c, 0x0}};
  // -7385418678258
  s21_decimal dec_2 = {{0x8d41bff2, 0x6b7, 0x0, 0x80000000}};
  // 91138288347751484389339
  s21_decimal dec_check = {{0xf1ca77db, 0x9dd3acee, 0x134c, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_372) {
  // -7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x80000000}};
  // 109879971240967302.99888312975
  s21_decimal dec_2 = {{0xe06c228f, 0xa91704df, 0x23810ee5, 0xb0000}};
  // 109879971240967295.99888312975
  s21_decimal dec_check = {{0xe52bca8f, 0xa917043c, 0x23810ee5, 0xb0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_373) {
  // -39323774036913.89944725
  s21_decimal dec_1 = {{0x66280395, 0x2cb2fe07, 0xd5, 0x80080000}};
  // 202670538066880738442729
  s21_decimal dec_2 = {{0xedc93de9, 0xcab8e14b, 0x2aea, 0x0}};
  // 202670538027556964405815.10055
  s21_decimal dec_check = {{0x344b53a7, 0x2433df4b, 0x417c8394, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_374) {
  // 256229948086483
  s21_decimal dec_1 = {{0x2f0958d3, 0xe90a, 0x0, 0x0}};
  // 8608286146921083
  s21_decimal dec_2 = {{0xcde9827b, 0x1e9530, 0x0, 0x0}};
  // 8864516095007566
  s21_decimal dec_check = {{0xfcf2db4e, 0x1f7e3a, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_375) {
  // 62098017007060
  s21_decimal dec_1 = {{0x523eb5d4, 0x387a, 0x0, 0x0}};
  // 49564869855323660635
  s21_decimal dec_2 = {{0x908a15b, 0xafd9ca87, 0x2, 0x0}};
  // 49564931953340667695
  s21_decimal dec_check = {{0x5b47572f, 0xafda0301, 0x2, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_376) {
  // 944157244475103257934847
  s21_decimal dec_1 = {{0x3c71bbff, 0xdde562a2, 0xc7ee, 0x0}};
  // 84076305
  s21_decimal dec_2 = {{0x502e711, 0x0, 0x0, 0x0}};
  // 944157244475103342011152
  s21_decimal dec_check = {{0x4174a310, 0xdde562a2, 0xc7ee, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_377) {
  // -23.0040154118
  s21_decimal dec_1 = {{0x8f763006, 0x35, 0x0, 0x800a0000}};
  // 896988694
  s21_decimal dec_2 = {{0x3576f616, 0x0, 0x0, 0x0}};
  // 896988670.9959845882
  s21_decimal dec_check = {{0x2ea767fa, 0x7c7b7070, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_378) {
  // -8.72371
  s21_decimal dec_1 = {{0xd4fb3, 0x0, 0x0, 0x80050000}};
  // -1997925817387
  s21_decimal dec_2 = {{0x2da89c2b, 0x1d1, 0x0, 0x80000000}};
  // -1997925817395.72371
  s21_decimal dec_check = {{0x67586c93, 0x2c5ce4b, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_379) {
  // 0.58285869617681427
  s21_decimal dec_1 = {{0x89fc9413, 0xcf12b0, 0x0, 0x110000}};
  // 39582786.344703368
  s21_decimal dec_2 = {{0x9f4bd588, 0x8ca055, 0x0, 0x90000}};
  // 39582786.92756206417681427
  s21_decimal dec_check = {{0x33d11c13, 0xb7c84271, 0x34632, 0x110000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_380) {
  // 9987013660473344
  s21_decimal dec_1 = {{0xd1997800, 0x237b22, 0x0, 0x0}};
  // 3606652697711037236.251
  s21_decimal dec_2 = {{0x6adc41b, 0x845c5fb4, 0xc3, 0x30000}};
  // 3616639711371510580.251
  s21_decimal dec_check = {{0xc62a841b, 0xef55fb6, 0xc4, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_381) {
  // 522339
  s21_decimal dec_1 = {{0x7f863, 0x0, 0x0, 0x0}};
  // -70077710246
  s21_decimal dec_2 = {{0x50f4ffa6, 0x10, 0x0, 0x80000000}};
  // -70077187907
  s21_decimal dec_check = {{0x50ed0743, 0x10, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_382) {
  // 5991056723006625433640
  s21_decimal dec_1 = {{0x79bc4828, 0xc69d2b98, 0x144, 0x0}};
  // 76710.615653130
  s21_decimal dec_2 = {{0x94ff1b0a, 0x45c4, 0x0, 0x90000}};
  // 5991056723006625510350.6156531
  s21_decimal dec_check = {{0xa3428bf3, 0x48a96c0e, 0xc194dc15, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_383) {
  // 465.669505466375968085862
  s21_decimal dec_1 = {{0x7a6f5766, 0xfe95dee3, 0x629b, 0x150000}};
  // -2414351384210772519090
  s21_decimal dec_2 = {{0x67bee8b2, 0xe1db3028, 0x82, 0x80000000}};
  // -2414351384210772518624.3304945
  s21_decimal dec_check = {{0xcfed1df1, 0xf3cd5a56, 0x4e030beb, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_384) {
  // -0.810
  s21_decimal dec_1 = {{0x32a, 0x0, 0x0, 0x80030000}};
  // -951400
  s21_decimal dec_2 = {{0xe8468, 0x0, 0x0, 0x80000000}};
  // -951400.810
  s21_decimal dec_check = {{0x38b5396a, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_385) {
  // 636836703124749657
  s21_decimal dec_1 = {{0x7dae7d59, 0x8d67f9b, 0x0, 0x0}};
  // 9454610700
  s21_decimal dec_2 = {{0x3389e90c, 0x2, 0x0, 0x0}};
  // 636836712579360357
  s21_decimal dec_check = {{0xb1386665, 0x8d67f9d, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_386) {
  // 35.6590364046936616877
  s21_decimal dec_1 = {{0xd0e1afad, 0x54af76cd, 0x13, 0x130000}};
  // 273211.9373
  s21_decimal dec_2 = {{0xa2d8d54d, 0x0, 0x0, 0x40000}};
  // 273247.5963364046936616877
  s21_decimal dec_check = {{0x89162fad, 0xd19c097a, 0x2429f, 0x130000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_387) {
  // 0.4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x10000}};
  // -39955208906064048
  s21_decimal dec_2 = {{0x1c5c0b0, 0x8df30d, 0x0, 0x80000000}};
  // -39955208906064047.6
  s21_decimal dec_check = {{0x11b986dc, 0x58b7e82, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_388) {
  // -249884168363
  s21_decimal dec_1 = {{0x2e41d0ab, 0x3a, 0x0, 0x80000000}};
  // 7764
  s21_decimal dec_2 = {{0x1e54, 0x0, 0x0, 0x0}};
  // -249884160599
  s21_decimal dec_check = {{0x2e41b257, 0x3a, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_389) {
  // 17439.15
  s21_decimal dec_1 = {{0x1a9c2b, 0x0, 0x0, 0x20000}};
  // 0.717431975135909273713
  s21_decimal dec_2 = {{0xc2c06071, 0xe45e6444, 0x26, 0x150000}};
  // 17439.867431975135909273713
  s21_decimal dec_check = {{0x4cb86071, 0x1b9e0ba1, 0xe6d09, 0x150000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_390) {
  // 3767
  s21_decimal dec_1 = {{0xeb7, 0x0, 0x0, 0x0}};
  // 4273.899423
  s21_decimal dec_2 = {{0xfebe879f, 0x0, 0x0, 0x60000}};
  // 8040.899423
  s21_decimal dec_check = {{0xdf46635f, 0x1, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_391) {
  // 35199502847.506239241441415
  s21_decimal dec_1 = {{0x7e61d087, 0xdf755006, 0x1d1dc8, 0xf0000}};
  // 12017.9504258756993661239
  s21_decimal dec_2 = {{0x5b68b937, 0xf1a8b109, 0x1972, 0x130000}};
  // 35199514865.456665117140781124
  s21_decimal dec_check = {{0x9da10844, 0x60d177de, 0x71bc5b34, 0x120000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_392) {
  // 9020916909116530124131218439
  s21_decimal dec_1 = {{0x7d0d3407, 0x88a50826, 0x1d25ed75, 0x0}};
  // 264007984861844
  s21_decimal dec_2 = {{0x2627d294, 0xf01d, 0x0, 0x0}};
  // 9020916909116794132116080283
  s21_decimal dec_check = {{0xa335069b, 0x88a5f843, 0x1d25ed75, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_393) {
  // 660803213420
  s21_decimal dec_1 = {{0xdaf0d86c, 0x99, 0x0, 0x0}};
  // -6659642.788535
  s21_decimal dec_2 = {{0x91a48ab7, 0x60e, 0x0, 0x80060000}};
  // 660796553777.211465
  s21_decimal dec_check = {{0xf0b16849, 0x92b9ef6, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_394) {
  // 245793
  s21_decimal dec_1 = {{0x3c021, 0x0, 0x0, 0x0}};
  // -5464954738249119753
  s21_decimal dec_2 = {{0x3eed3809, 0x4bd76b61, 0x0, 0x80000000}};
  // -5464954738248873960
  s21_decimal dec_check = {{0x3ee977e8, 0x4bd76b61, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_395) {
  // -7439506470671947453371.23
  s21_decimal dec_1 = {{0xc012b523, 0xa5383027, 0x9d89, 0x80020000}};
  // 699162546319393795.8
  s21_decimal dec_2 = {{0xc8402826, 0x61073e50, 0x0, 0x10000}};
  // -7438807308125628059575.43
  s21_decimal dec_check = {{0xed9123a7, 0xdaefc0ff, 0x9d85, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_396) {
  // -5914269.07963350535690016
  s21_decimal dec_1 = {{0xd188d720, 0x5121ee9c, 0x7d3d, 0x80110000}};
  // -5269148739441974
  s21_decimal dec_2 = {{0x4ae21536, 0x12b843, 0x0, 0x80000000}};
  // -5269148745356243.0796335053569
  s21_decimal dec_check = {{0xbb9e7b01, 0x6ea838ee, 0xaa41607a, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_397) {
  // -89957216547007
  s21_decimal dec_1 = {{0xcbeff0bf, 0x51d0, 0x0, 0x80000000}};
  // -36473821617701481
  s21_decimal dec_2 = {{0x5d1fc269, 0x8194bf, 0x0, 0x80000000}};
  // -36563778834248488
  s21_decimal dec_check = {{0x290fb328, 0x81e690, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_398) {
  // -9.71
  s21_decimal dec_1 = {{0x3cb, 0x0, 0x0, 0x80020000}};
  // -9441
  s21_decimal dec_2 = {{0x24e1, 0x0, 0x0, 0x80000000}};
  // -9450.71
  s21_decimal dec_check = {{0xe6baf, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_399) {
  // 328809408442077070333146
  s21_decimal dec_1 = {{0xeb1d94da, 0xcb331728, 0x45a0, 0x0}};
  // -552439.7513543
  s21_decimal dec_2 = {{0x3fc05b47, 0x506, 0x0, 0x80070000}};
  // 328809408442077069780706.24865
  s21_decimal dec_check = {{0x2674fa61, 0xd536cfb5, 0x6a3e7a0e, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_400) {
  // -77.196418918659006
  s21_decimal dec_1 = {{0xe79433be, 0x11241bb, 0x0, 0x800f0000}};
  // 359661078.98170
  s21_decimal dec_2 = {{0x315d13a, 0x20b6, 0x0, 0x50000}};
  // 359661001.785281081340994
  s21_decimal dec_check = {{0x8c417442, 0x4310c60e, 0x4c29, 0xf0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_401) {
  // -4121269277134817
  s21_decimal dec_1 = {{0xc7498fe1, 0xea445, 0x0, 0x80000000}};
  // -934550888
  s21_decimal dec_2 = {{0x37b41d68, 0x0, 0x0, 0x80000000}};
  // -4121270211685705
  s21_decimal dec_check = {{0xfefdad49, 0xea445, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_402) {
  // -6287361
  s21_decimal dec_1 = {{0x5ff001, 0x0, 0x0, 0x80000000}};
  // 4053016100444069593
  s21_decimal dec_2 = {{0x67e85ed9, 0x383f34ab, 0x0, 0x0}};
  // 4053016100437782232
  s21_decimal dec_check = {{0x67886ed8, 0x383f34ab, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_403) {
  // -8488778644546559279204
  s21_decimal dec_1 = {{0xff960064, 0x2d7801bc, 0x1cc, 0x80000000}};
  // 829348400019114052851405
  s21_decimal dec_2 = {{0x448c96cd, 0x111d3d3d, 0xaf9f, 0x0}};
  // 820859621374567493572201
  s21_decimal dec_check = {{0x44f69669, 0xe3a53b80, 0xadd2, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_404) {
  // -8.0122281483651
  s21_decimal dec_1 = {{0xec205d83, 0x48de, 0x0, 0x800d0000}};
  // 353384708616052469
  s21_decimal dec_2 = {{0x2a1d5ef5, 0x4e77985, 0x0, 0x0}};
  // 353384708616052460.98777185163
  s21_decimal dec_check = {{0xbe621b8b, 0x5fde1b1, 0x722f4c48, 0xb0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_405) {
  // -27.8
  s21_decimal dec_1 = {{0x116, 0x0, 0x0, 0x80010000}};
  // 0.31
  s21_decimal dec_2 = {{0x1f, 0x0, 0x0, 0x20000}};
  // -27.49
  s21_decimal dec_check = {{0xabd, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_406) {
  // -41785372799603077695254542410
  s21_decimal dec_1 = {{0xc037b84a, 0x5f503ca2, 0x87040cde, 0x80000000}};
  // 4094615.161716471154881
  s21_decimal dec_2 = {{0x56e6c8c1, 0xf8334b61, 0xdd, 0xf0000}};
  // -41785372799603077695250447795
  s21_decimal dec_check = {{0xbff93db3, 0x5f503ca2, 0x87040cde, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_407) {
  // 0.1310
  s21_decimal dec_1 = {{0x51e, 0x0, 0x0, 0x40000}};
  // -602775957543287904
  s21_decimal dec_2 = {{0x2c837c60, 0x85d7d8a, 0x0, 0x80000000}};
  // -602775957543287903.8690
  s21_decimal dec_check = {{0xd02a60e2, 0xc3f7e56a, 0x146, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_408) {
  // -2427858.45433085573
  s21_decimal dec_1 = {{0xa9882e85, 0x35e8c70, 0x0, 0x800b0000}};
  // -433036.9843389
  s21_decimal dec_2 = {{0x3e2800bd, 0x3f0, 0x0, 0x80070000}};
  // -2860895.43866975573
  s21_decimal dec_check = {{0xa4250555, 0x3f864ec, 0x0, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_409) {
  // -77118458419289551418.883261927
  s21_decimal dec_1 = {{0x7bab45e7, 0xd8a9a560, 0xf92ee4c7, 0x80090000}};
  // -56376030
  s21_decimal dec_2 = {{0x35c3ade, 0x0, 0x0, 0x80000000}};
  // -77118458419345927448.883261927
  s21_decimal dec_check = {{0xd5aa71e7, 0xd971ef13, 0xf92ee4c7, 0x80090000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_410) {
  // -75398841.5324376291486
  s21_decimal dec_1 = {{0x8924589e, 0xdfb0f4ef, 0x28, 0x800d0000}};
  // -33
  s21_decimal dec_2 = {{0x21, 0x0, 0x0, 0x80000000}};
  // -75398874.5324376291486
  s21_decimal dec_check = {{0xa5eaf89e, 0xdfb22111, 0x28, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_411) {
  // -748328948288304995098286
  s21_decimal dec_1 = {{0x5f83deae, 0xfe5ad385, 0x9e76, 0x80000000}};
  // 903040852
  s21_decimal dec_2 = {{0x35d34f54, 0x0, 0x0, 0x0}};
  // -748328948288304092057434
  s21_decimal dec_check = {{0x29b08f5a, 0xfe5ad385, 0x9e76, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_412) {
  // 5293967
  s21_decimal dec_1 = {{0x50c78f, 0x0, 0x0, 0x0}};
  // 3924000606721987525617507102
  s21_decimal dec_2 = {{0x5f69db1e, 0x21d2ab82, 0xcaddb73, 0x0}};
  // 3924000606721987525622801069
  s21_decimal dec_check = {{0x5fbaa2ad, 0x21d2ab82, 0xcaddb73, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_413) {
  // -40091505564251457054062443082
  s21_decimal dec_1 = {{0x2c987a4a, 0x8c7e8bf9, 0x818aea87, 0x80000000}};
  // -327987817819717132178
  s21_decimal dec_2 = {{0x97c65f92, 0xc7bece8d, 0x11, 0x80000000}};
  // -40091505892239274873779575260
  s21_decimal dec_check = {{0xc45ed9dc, 0x543d5a86, 0x818aea99, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_414) {
  // -55.69262891753117564
  s21_decimal dec_1 = {{0xc3b5977c, 0x4d49ff17, 0x0, 0x80110000}};
  // -71321.75547
  s21_decimal dec_2 = {{0xa91c5cbb, 0x1, 0x0, 0x80050000}};
  // -71377.44809891753117564
  s21_decimal dec_check = {{0x2a08477c, 0xf01b9f34, 0x182, 0x80110000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_415) {
  // 30797224148252843743
  s21_decimal dec_1 = {{0x30b15edf, 0xab65b831, 0x1, 0x0}};
  // 9449625059950005.066620716
  s21_decimal dec_2 = {{0xf0b5f2c, 0x33720538, 0x7d109, 0x90000}};
  // 30806673773312793748.066620716
  s21_decimal dec_check = {{0x7b0d552c, 0x9a990134, 0x638aaeeb, 0x90000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_416) {
  // -111
  s21_decimal dec_1 = {{0x6f, 0x0, 0x0, 0x80000000}};
  // 517.885820087500081740
  s21_decimal dec_2 = {{0x2f4d0a4c, 0x131c097e, 0x1c, 0x120000}};
  // 406.885820087500081740
  s21_decimal dec_check = {{0x9af10a4c, 0xeacd198, 0x16, 0x120000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_417) {
  // -3401789401
  s21_decimal dec_1 = {{0xcac32fd9, 0x0, 0x0, 0x80000000}};
  // -1488317748560312
  s21_decimal dec_2 = {{0xfab741b8, 0x5499d, 0x0, 0x80000000}};
  // -1488321150349713
  s21_decimal dec_check = {{0xc57a7191, 0x5499e, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_418) {
  // -0.2111
  s21_decimal dec_1 = {{0x83f, 0x0, 0x0, 0x80040000}};
  // 36738047838
  s21_decimal dec_2 = {{0x8dc21f5e, 0x8, 0x0, 0x0}};
  // 36738047837.7889
  s21_decimal dec_check = {{0x6ee93fa1, 0x14e21, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_419) {
  // -4060058
  s21_decimal dec_1 = {{0x3df39a, 0x0, 0x0, 0x80000000}};
  // -7391763
  s21_decimal dec_2 = {{0x70ca13, 0x0, 0x0, 0x80000000}};
  // -11451821
  s21_decimal dec_check = {{0xaebdad, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_420) {
  // -7944422962568919092853124225
  s21_decimal dec_1 = {{0x9cfaac81, 0xc20f661a, 0x19ab78ff, 0x80000000}};
  // 2417
  s21_decimal dec_2 = {{0x971, 0x0, 0x0, 0x0}};
  // -7944422962568919092853121808
  s21_decimal dec_check = {{0x9cfaa310, 0xc20f661a, 0x19ab78ff, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_421) {
  // 5678405856.59849428935202
  s21_decimal dec_1 = {{0x8eba222, 0xb3280d45, 0x783e, 0xe0000}};
  // 782723160108924627035089
  s21_decimal dec_2 = {{0xc5efa3d1, 0x81eda207, 0xa5bf, 0x0}};
  // 782723160108930305440945.59849
  s21_decimal dec_check = {{0x79bc7e69, 0x395f20d9, 0xfce957a1, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_422) {
  // 8621417134653024260997.2758911
  s21_decimal dec_1 = {{0xa43bc97f, 0xa5b431ee, 0x1692b0e9, 0x70000}};
  // -75692562694975581.6761
  s21_decimal dec_2 = {{0xd2094b39, 0x8740758, 0x29, 0x80040000}};
  // 8621341442090329285415.5997911
  s21_decimal dec_check = {{0x2fedf2d7, 0xa0777efa, 0x169210a0, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_423) {
  // -76907
  s21_decimal dec_1 = {{0x12c6b, 0x0, 0x0, 0x80000000}};
  // 388.1374
  s21_decimal dec_2 = {{0x3b399e, 0x0, 0x0, 0x40000}};
  // -76518.8626
  s21_decimal dec_check = {{0x2d9bda12, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_424) {
  // 0.0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x10000}};
  // -692209.7274044943653185
  s21_decimal dec_2 = {{0x94a35941, 0x3f65abe6, 0x177, 0x80100000}};
  // -692209.7274044943653185
  s21_decimal dec_check = {{0x94a35941, 0x3f65abe6, 0x177, 0x80100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_425) {
  // 5943
  s21_decimal dec_1 = {{0x1737, 0x0, 0x0, 0x0}};
  // 9325827358
  s21_decimal dec_2 = {{0x2bdcd51e, 0x2, 0x0, 0x0}};
  // 9325833301
  s21_decimal dec_check = {{0x2bdcec55, 0x2, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_426) {
  // 3.32568
  s21_decimal dec_1 = {{0x51318, 0x0, 0x0, 0x50000}};
  // 682345791822866535.74
  s21_decimal dec_2 = {{0x7675c886, 0xb2f1ec3e, 0x3, 0x20000}};
  // 682345791822866539.06568
  s21_decimal dec_check = {{0xbc1c5e88, 0x102d3fe, 0xe73, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_427) {
  // -25596912
  s21_decimal dec_1 = {{0x18693f0, 0x0, 0x0, 0x80000000}};
  // 365986.401432
  s21_decimal dec_2 = {{0x367d4c98, 0x55, 0x0, 0x60000}};
  // -25230925.598568
  s21_decimal dec_check = {{0x885b8f68, 0x16f2, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_428) {
  // -5892967219.95424
  s21_decimal dec_1 = {{0x55c826a0, 0x217f6, 0x0, 0x80050000}};
  // -81623122
  s21_decimal dec_2 = {{0x4dd7852, 0x0, 0x0, 0x80000000}};
  // -5974590341.95424
  s21_decimal dec_check = {{0xc58045e0, 0x21f62, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_429) {
  // 1914
  s21_decimal dec_1 = {{0x77a, 0x0, 0x0, 0x0}};
  // -1000820721994889295198
  s21_decimal dec_2 = {{0x3359f55e, 0x412d7814, 0x36, 0x80000000}};
  // -1000820721994889293284
  s21_decimal dec_check = {{0x3359ede4, 0x412d7814, 0x36, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_430) {
  // 7557335321280867703927
  s21_decimal dec_1 = {{0xf2b39c77, 0xaf189239, 0x199, 0x0}};
  // 29113670
  s21_decimal dec_2 = {{0x1bc3d46, 0x0, 0x0, 0x0}};
  // 7557335321280896817597
  s21_decimal dec_check = {{0xf46fd9bd, 0xaf189239, 0x199, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_431) {
  // -17934.5245
  s21_decimal dec_1 = {{0xab0975d, 0x0, 0x0, 0x80040000}};
  // -3002622908049881.89256
  s21_decimal dec_2 = {{0x1c5c1a48, 0x46f9f2a1, 0x10, 0x80050000}};
  // -3002622908067816.41706
  s21_decimal dec_check = {{0x874203ea, 0x46f9f2a1, 0x10, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_432) {
  // 2228956
  s21_decimal dec_1 = {{0x2202dc, 0x0, 0x0, 0x0}};
  // -789412029.6393
  s21_decimal dec_2 = {{0xfe3c6fc9, 0x72d, 0x0, 0x80040000}};
  // -787183073.6393
  s21_decimal dec_check = {{0xcdacbe09, 0x728, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_433) {
  // -78652081536707417206731042
  s21_decimal dec_1 = {{0x6b10b122, 0xe23597bf, 0x410f39, 0x80000000}};
  // -72110.4444713861080399
  s21_decimal dec_2 = {{0x64ff654f, 0x17559fe4, 0x27, 0x80100000}};
  // -78652081536707417206803152.444
  s21_decimal dec_check = {{0x3d803e3c, 0xa158c3ba, 0xfe237a1b, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_434) {
  // -74162574491345
  s21_decimal dec_1 = {{0x51e87ed1, 0x4373, 0x0, 0x80000000}};
  // 79228162514264337592254797346
  s21_decimal dec_2 = {{0xb3291622, 0xffffffff, 0xffffffff, 0x0}};
  // 79228162514264263429680306001
  s21_decimal dec_check = {{0x61409751, 0xffffbc8c, 0xffffffff, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_435) {
  // 8795622699512109393116
  s21_decimal dec_1 = {{0xfda2e4dc, 0xcfc913ff, 0x1dc, 0x0}};
  // 568.26586
  s21_decimal dec_2 = {{0x3631ada, 0x0, 0x0, 0x50000}};
  // 8795622699512109393684.26586
  s21_decimal dec_check = {{0xb1d94c5a, 0x32247c64, 0x2d78e8e, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_436) {
  // 270.0373346237053
  s21_decimal dec_1 = {{0xaa103a7d, 0x997f9, 0x0, 0xd0000}};
  // 0.7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x10000}};
  // 270.7373346237053
  s21_decimal dec_check = {{0x7a93aa7d, 0x99e57, 0x0, 0xd0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_437) {
  // -86000647548431659688.55
  s21_decimal dec_1 = {{0x17c4c9d7, 0x35dfb16f, 0x1d2, 0x80020000}};
  // 10936989686740417.13678
  s21_decimal dec_2 = {{0xf355d40e, 0x4a1f4957, 0x3b, 0x50000}};
  // -85989710558744919271.41322
  s21_decimal dec_check = {{0xe55e9bca, 0x27add09c, 0x71ce7, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_438) {
  // 36302740722763741360
  s21_decimal dec_1 = {{0xe170b8b0, 0xf7cd3e58, 0x1, 0x0}};
  // 9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x0}};
  // 36302740722763741369
  s21_decimal dec_check = {{0xe170b8b9, 0xf7cd3e58, 0x1, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_439) {
  // -576286.6668412354482
  s21_decimal dec_1 = {{0xb2a83fb2, 0x4ff9d0b3, 0x0, 0x800d0000}};
  // 971.772
  s21_decimal dec_2 = {{0xed3fc, 0x0, 0x0, 0x30000}};
  // -575314.8948412354482
  s21_decimal dec_check = {{0xb207cfb2, 0x4fd74a7c, 0x0, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_440) {
  // -79228162514264337592709915318
  s21_decimal dec_1 = {{0xce49a2b6, 0xffffffff, 0xffffffff, 0x80000000}};
  // -148750320.267809689
  s21_decimal dec_2 = {{0xcfc9d399, 0x21077a0, 0x0, 0x80090000}};
  // -79228162514264337592858665638
  s21_decimal dec_check = {{0xd72762a6, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_441) {
  // -67538
  s21_decimal dec_1 = {{0x107d2, 0x0, 0x0, 0x80000000}};
  // 53889690276498993738262
  s21_decimal dec_2 = {{0xf0b67216, 0x5dafcaa8, 0xb69, 0x0}};
  // 53889690276498993670724
  s21_decimal dec_check = {{0xf0b56a44, 0x5dafcaa8, 0xb69, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_442) {
  // 2237084573080398732
  s21_decimal dec_1 = {{0xef6ab8c, 0x1f0bb891, 0x0, 0x0}};
  // 733140077675111
  s21_decimal dec_2 = {{0x79e68267, 0x29ac9, 0x0, 0x0}};
  // 2237817713158073843
  s21_decimal dec_check = {{0x88dd2df3, 0x1f0e535a, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_443) {
  // -3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x80000000}};
  // -6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x80000000}};
  // -9
  s21_decimal dec_check = {{0x9, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_444) {
  // -50057.40
  s21_decimal dec_1 = {{0x4c61ac, 0x0, 0x0, 0x80020000}};
  // 79228162514264337592101518032
  s21_decimal dec_2 = {{0xaa063ad0, 0xffffffff, 0xffffffff, 0x0}};
  // 79228162514264337592101467975
  s21_decimal dec_check = {{0xaa057747, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_445) {
  // -35110064
  s21_decimal dec_1 = {{0x217bcb0, 0x0, 0x0, 0x80000000}};
  // -30020
  s21_decimal dec_2 = {{0x7544, 0x0, 0x0, 0x80000000}};
  // -35140084
  s21_decimal dec_check = {{0x21831f4, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_446) {
  // 8.672
  s21_decimal dec_1 = {{0x21e0, 0x0, 0x0, 0x30000}};
  // 7467468847573
  s21_decimal dec_2 = {{0xa7d3f9d5, 0x6ca, 0x0, 0x0}};
  // 7467468847581.672
  s21_decimal dec_check = {{0x940809e8, 0x1a879f, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_447) {
  // -5609224447563713417109828.2859
  s21_decimal dec_1 = {{0x899f7b6b, 0xf1e0cf, 0xb53e6aca, 0x80040000}};
  // 933
  s21_decimal dec_2 = {{0x3a5, 0x0, 0x0, 0x0}};
  // -5609224447563713417108895.2859
  s21_decimal dec_check = {{0x89111e1b, 0xf1e0cf, 0xb53e6aca, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_448) {
  // -135170211711
  s21_decimal dec_1 = {{0x78c5bf7f, 0x1f, 0x0, 0x80000000}};
  // 47988672870801643
  s21_decimal dec_2 = {{0x97b4e0eb, 0xaa7d71, 0x0, 0x0}};
  // 47988537700589932
  s21_decimal dec_check = {{0x1eef216c, 0xaa7d52, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_449) {
  // -5205
  s21_decimal dec_1 = {{0x1455, 0x0, 0x0, 0x80000000}};
  // 965445023023237457208055
  s21_decimal dec_2 = {{0x5c2b62f7, 0xe12b6cad, 0xcc70, 0x0}};
  // 965445023023237457202850
  s21_decimal dec_check = {{0x5c2b4ea2, 0xe12b6cad, 0xcc70, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_450) {
  // 4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x0}};
  // -61500618282563085555
  s21_decimal dec_2 = {{0xd71124f3, 0x557e167b, 0x3, 0x80000000}};
  // -61500618282563085551
  s21_decimal dec_check = {{0xd71124ef, 0x557e167b, 0x3, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_451) {
  // 13.39206868846974568634601398
  s21_decimal dec_1 = {{0xc8114fb6, 0xd4a03c27, 0x453c415, 0x1a0000}};
  // -31
  s21_decimal dec_2 = {{0x1f, 0x0, 0x0, 0x80000000}};
  // -17.60793131153025431365398602
  s21_decimal dec_check = {{0xd3eeb04a, 0xe7995161, 0x5b07e72, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_452) {
  // -270088
  s21_decimal dec_1 = {{0x41f08, 0x0, 0x0, 0x80000000}};
  // -0.10768667448006236311736
  s21_decimal dec_2 = {{0xc40210b8, 0xc548251d, 0x247, 0x80170000}};
  // -270088.10768667448006236311736
  s21_decimal dec_check = {{0xf80210b8, 0x94fb1d4e, 0x57452a25, 0x80170000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_453) {
  // 71590
  s21_decimal dec_1 = {{0x117a6, 0x0, 0x0, 0x0}};
  // 65903271437.42756
  s21_decimal dec_2 = {{0x1c5b3d24, 0x1769de, 0x0, 0x50000}};
  // 65903343027.42756
  s21_decimal dec_check = {{0xc710e8e4, 0x1769df, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_454) {
  // -0.7491
  s21_decimal dec_1 = {{0x1d43, 0x0, 0x0, 0x80040000}};
  // 1958854667047
  s21_decimal dec_2 = {{0x14d62b27, 0x1c8, 0x0, 0x0}};
  // 1958854667046.2509
  s21_decimal dec_check = {{0xedf5862d, 0x4597ad, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_455) {
  // 1853707128408549287958025768
  s21_decimal dec_1 = {{0x90da1628, 0xc9e30cb9, 0x5fd59c0, 0x0}};
  // -0.6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x80010000}};
  // 1853707128408549287958025767.4
  s21_decimal dec_check = {{0xa884dd8a, 0xe2de7f3f, 0x3be58187, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_456) {
  // 480889573
  s21_decimal dec_1 = {{0x1ca9cae5, 0x0, 0x0, 0x0}};
  // 0.0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x10000}};
  // 480889573.0
  s21_decimal dec_check = {{0x1ea1ecf2, 0x1, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_457) {
  // -5029.6459164445
  s21_decimal dec_1 = {{0x8e94fb1d, 0x2dbe, 0x0, 0x800a0000}};
  // 789657.413
  s21_decimal dec_2 = {{0x2f113745, 0x0, 0x0, 0x30000}};
  // 784627.7670835555
  s21_decimal dec_check = {{0xe1611563, 0x1be025, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_459) {
  // -686492181273
  s21_decimal dec_1 = {{0xd61f6319, 0x9f, 0x0, 0x80000000}};
  // -75009293.31783
  s21_decimal dec_2 = {{0x723a7247, 0x6d2, 0x0, 0x80050000}};
  // -686567190566.31783
  s21_decimal dec_check = {{0x16d077e7, 0xf3eaec, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_460) {
  // -46183.2110615846822
  s21_decimal dec_1 = {{0x93205fa6, 0x668c1db, 0x0, 0x800d0000}};
  // 487847704717735
  s21_decimal dec_2 = {{0xe524e9a7, 0x1bbb1, 0x0, 0x0}};
  // 487847704671551.7889384153178
  s21_decimal dec_check = {{0x6d46005a, 0x9f9c7da4, 0xfc361b2, 0xd0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_461) {
  // -6047378840235189829.1344
  s21_decimal dec_1 = {{0x823eec90, 0x4a674413, 0xcce, 0x80040000}};
  // 1666
  s21_decimal dec_2 = {{0x682, 0x0, 0x0, 0x0}};
  // -6047378840235188163.1344
  s21_decimal dec_check = {{0x8140b670, 0x4a674413, 0xcce, 0x80040000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_462) {
  // 480784.3585215299348775256266
  s21_decimal dec_1 = {{0xb78340ca, 0xc7a2c5, 0xf88f47b, 0x160000}};
  // -3331011204227281274135
  s21_decimal dec_2 = {{0x7d414517, 0x931111ca, 0xb4, 0x80000000}};
  // -3331011204227280793350.6414785
  s21_decimal dec_check = {{0x7af6e8c1, 0x192fe504, 0x6ba17a98, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_463) {
  // 5145271525
  s21_decimal dec_1 = {{0x32ae9ce5, 0x1, 0x0, 0x0}};
  // 1317946116046
  s21_decimal dec_2 = {{0xdbb5c7ce, 0x132, 0x0, 0x0}};
  // 1323091387571
  s21_decimal dec_check = {{0xe6464b3, 0x134, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_464) {
  // -8375036540356304970
  s21_decimal dec_1 = {{0x50daa04a, 0x743a1b5c, 0x0, 0x80000000}};
  // 474326727642484888859231
  s21_decimal dec_2 = {{0x78e0725f, 0x4dad8421, 0x6471, 0x0}};
  // 474318352605944532554261
  s21_decimal dec_check = {{0x2805d215, 0xd97368c5, 0x6470, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_465) {
  // -1412248
  s21_decimal dec_1 = {{0x158c98, 0x0, 0x0, 0x80000000}};
  // 988221
  s21_decimal dec_2 = {{0xf143d, 0x0, 0x0, 0x0}};
  // -424027
  s21_decimal dec_check = {{0x6785b, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_466) {
  // 9
  s21_decimal dec_1 = {{0x9, 0x0, 0x0, 0x0}};
  // 17948230134
  s21_decimal dec_2 = {{0x2dcc41f6, 0x4, 0x0, 0x0}};
  // 17948230143
  s21_decimal dec_check = {{0x2dcc41ff, 0x4, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_467) {
  // 15474865502341918.25
  s21_decimal dec_1 = {{0x896757d1, 0x1579c6d1, 0x0, 0x20000}};
  // -4374.9130
  s21_decimal dec_2 = {{0x29b8f0a, 0x0, 0x0, 0x80040000}};
  // 15474865502337543.3370
  s21_decimal dec_check = {{0xa9c2be9a, 0x6391a9d9, 0x8, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_468) {
  // -250013117568
  s21_decimal dec_1 = {{0x35f16c80, 0x3a, 0x0, 0x80000000}};
  // 36095326744.76407468826
  s21_decimal dec_2 = {{0x3f3331a, 0xac541b50, 0xc3, 0xb0000}};
  // -213917790823.23592531174
  s21_decimal dec_check = {{0xc960cce6, 0xa69228de, 0x487, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_469) {
  // -9751898.2625
  s21_decimal dec_1 = {{0xb49595e1, 0x16, 0x0, 0x80040000}};
  // 4814888205.88
  s21_decimal dec_2 = {{0x1af8596c, 0x70, 0x0, 0x20000}};
  // 4805136307.6175
  s21_decimal dec_check = {{0xd46d584f, 0x2bb3, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_470) {
  // 444555421978394146042786
  s21_decimal dec_1 = {{0x2142f3a2, 0x65d0a5c7, 0x5e23, 0x0}};
  // 7136658697584.07472410028799
  s21_decimal dec_2 = {{0xe1146aff, 0x522fc03f, 0x24e54a0, 0xe0000}};
  // 444555421985530804740370.07472
  s21_decimal dec_check = {{0x98463470, 0x88dc6c74, 0x8fa4c33b, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_471) {
  // 801840947436721.8811
  s21_decimal dec_1 = {{0xff48e47b, 0x6f471cee, 0x0, 0x40000}};
  // -0.69658707
  s21_decimal dec_2 = {{0x426e853, 0x0, 0x0, 0x80080000}};
  // 801840947436721.18451293
  s21_decimal dec_check = {{0xb361c5d, 0xc9da37d4, 0x10fa, 0x80000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_472) {
  // 36980553984500622.175
  s21_decimal dec_1 = {{0xe350e35f, 0x13551ea, 0x2, 0x30000}};
  // -307368520346775288.57204274
  s21_decimal dec_2 = {{0x6008d632, 0x166adda9, 0x196cc8, 0x80080000}};
  // -270387966362274666.39704274
  s21_decimal dec_check = {{0x131800d2, 0x1a4bd48e, 0x165db0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_473) {
  // 6414055247971452303932
  s21_decimal dec_1 = {{0xac71ba3c, 0xb4e5d0e8, 0x15b, 0x0}};
  // 0.1038549251
  s21_decimal dec_2 = {{0x3de70103, 0x0, 0x0, 0xa0000}};
  // 6414055247971452303932.1038549
  s21_decimal dec_check = {{0x6fac1ed5, 0x25772ce7, 0xcf3fd24d, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_474) {
  // 830696.77665353
  s21_decimal dec_1 = {{0x2aa0fc49, 0x4b8d, 0x0, 0x80000}};
  // -7108553940636731774220
  s21_decimal dec_2 = {{0xb39d150c, 0x5b00d246, 0x181, 0x80000000}};
  // -7108553940636730943523.2233465
  s21_decimal dec_check = {{0x3a22a7f9, 0xd5992e4e, 0xe5b0947c, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_475) {
  // -983633749364365008318
  s21_decimal dec_1 = {{0x2c971dbe, 0x52a91388, 0x35, 0x80000000}};
  // 8367622233562964338922240973
  s21_decimal dec_2 = {{0xb4703bcd, 0x355657ec, 0x1b0988ee, 0x0}};
  // 8367621249929214974557232655
  s21_decimal dec_check = {{0x87d91e0f, 0xe2ad4464, 0x1b0988b8, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_476) {
  // -690386833697
  s21_decimal dec_1 = {{0xbe431121, 0xa0, 0x0, 0x80000000}};
  // 76.5
  s21_decimal dec_2 = {{0x2fd, 0x0, 0x0, 0x10000}};
  // -690386833620.5
  s21_decimal dec_check = {{0x6e9ea84d, 0x647, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_477) {
  // 563886.068146
  s21_decimal dec_1 = {{0x4a3a91b2, 0x83, 0x0, 0x60000}};
  // 13539009.5
  s21_decimal dec_2 = {{0x811e38f, 0x0, 0x0, 0x10000}};
  // 14102895.568146
  s21_decimal dec_check = {{0x9614a512, 0xcd3, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_478) {
  // -8263847.6208
  s21_decimal dec_1 = {{0x3da313b0, 0x13, 0x0, 0x80040000}};
  // 449207245166452164550.80
  s21_decimal dec_2 = {{0xaadc09a8, 0x284873b0, 0x983, 0x20000}};
  // 449207245166443900703.1792
  s21_decimal dec_check = {{0x8050b1f0, 0xbc4d30ef, 0x3b73b, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_479) {
  // 182016523975229
  s21_decimal dec_1 = {{0x6413a3d, 0xa58b, 0x0, 0x0}};
  // 24651562106389.3218384
  s21_decimal dec_2 = {{0xa287450, 0x5d176b43, 0xd, 0x70000}};
  // 206668086081618.3218384
  s21_decimal dec_check = {{0xf71d50d0, 0x8f55d2a, 0x70, 0x70000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_480) {
  // 93972381.322422207988
  s21_decimal dec_1 = {{0xfc8745f4, 0x1820f6ec, 0x5, 0xc0000}};
  // -51189933641048580351990418
  s21_decimal dec_2 = {{0x123a1a92, 0xdcf77177, 0x2a57e3, 0x80000000}};
  // -51189933641048580258018036.678
  s21_decimal dec_check = {{0x51c70bc6, 0x26933909, 0xa5675217, 0x80030000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_481) {
  // -137311
  s21_decimal dec_1 = {{0x2185f, 0x0, 0x0, 0x80000000}};
  // 59210359543390389
  s21_decimal dec_2 = {{0x1f9b60b5, 0xd25b82, 0x0, 0x0}};
  // 59210359543253078
  s21_decimal dec_check = {{0x1f994856, 0xd25b82, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_482) {
  // -854877
  s21_decimal dec_1 = {{0xd0b5d, 0x0, 0x0, 0x80000000}};
  // 381376259023740543338420465
  s21_decimal dec_2 = {{0xeea218f1, 0x6dab67ef, 0x13b7790, 0x0}};
  // 381376259023740543337565588
  s21_decimal dec_check = {{0xee950d94, 0x6dab67ef, 0x13b7790, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_483) {
  // 4555729247096
  s21_decimal dec_1 = {{0xb69f9b78, 0x424, 0x0, 0x0}};
  // 7881201
  s21_decimal dec_2 = {{0x7841f1, 0x0, 0x0, 0x0}};
  // 4555737128297
  s21_decimal dec_check = {{0xb717dd69, 0x424, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_484) {
  // -302926932778969
  s21_decimal dec_1 = {{0xac389fd9, 0x11382, 0x0, 0x80000000}};
  // -11
  s21_decimal dec_2 = {{0xb, 0x0, 0x0, 0x80000000}};
  // -302926932778980
  s21_decimal dec_check = {{0xac389fe4, 0x11382, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_485) {
  // -5725.3
  s21_decimal dec_1 = {{0xdfa5, 0x0, 0x0, 0x80010000}};
  // 3558304700073.2962
  s21_decimal dec_2 = {{0xbc813522, 0x7e6a97, 0x0, 0x40000}};
  // 3558304694347.9962
  s21_decimal dec_check = {{0xb917989a, 0x7e6a97, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_486) {
  // -535.4516828706978301
  s21_decimal dec_1 = {{0xaeee39fd, 0x4a4f10af, 0x0, 0x80100000}};
  // 95292690.8810629294
  s21_decimal dec_2 = {{0x889190ae, 0xd3979f9, 0x0, 0xa0000}};
  // 95292155.4293800587021699
  s21_decimal dec_check = {{0x76f4cd83, 0xfb20c36f, 0xc9c9, 0x100000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_487) {
  // 8493779313406755308
  s21_decimal dec_1 = {{0x982bc1ec, 0x75dff748, 0x0, 0x0}};
  // 94034
  s21_decimal dec_2 = {{0x16f52, 0x0, 0x0, 0x0}};
  // 8493779313406849342
  s21_decimal dec_check = {{0x982d313e, 0x75dff748, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_488) {
  // 64845248.67239
  s21_decimal dec_1 = {{0xcbcd1ea7, 0x5e5, 0x0, 0x50000}};
  // -4881018538245
  s21_decimal dec_2 = {{0x73604905, 0x470, 0x0, 0x80000000}};
  // -4880953692996.32761
  s21_decimal dec_check = {{0xff9e2279, 0x6c61026, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_490) {
  // 44362620838928047888861403.190
  s21_decimal dec_1 = {{0xf4fa9836, 0x892bd46d, 0x8f57e65e, 0x30000}};
  // 6640972298547121203
  s21_decimal dec_2 = {{0xc21c4c33, 0x5c29791e, 0x0, 0x0}};
  // 44362627479900346435982606.190
  s21_decimal dec_check = {{0x33843f6e, 0x8b2cf494, 0x8f57e7c6, 0x30000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_491) {
  // -3483887877643961513.40276243
  s21_decimal dec_1 = {{0xcb3c1a13, 0x7374b77, 0x1202e32, 0x80080000}};
  // 9578662154827.095708
  s21_decimal dec_2 = {{0xd9f25e9c, 0x84ee3e7a, 0x0, 0x60000}};
  // -3483878298981806686.30705443
  s21_decimal dec_check = {{0xa88f2523, 0x1a26e37a, 0x1202dfe, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_492) {
  // -9
  s21_decimal dec_1 = {{0x9, 0x0, 0x0, 0x80000000}};
  // 6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x0}};
  // -3
  s21_decimal dec_check = {{0x3, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_493) {
  // 3674928.2907973003415
  s21_decimal dec_1 = {{0x4810a897, 0xfdffae19, 0x1, 0xd0000}};
  // -583229783171601542315
  s21_decimal dec_2 = {{0xf3682cab, 0x9df06db5, 0x1f, 0x80000000}};
  // -583229783171597867386.70920270
  s21_decimal dec_check = {{0xe60624e, 0xdd4e9845, 0xbc73a30d, 0x80080000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_494) {
  // -43978336913635353153079955
  s21_decimal dec_1 = {{0x946d8a93, 0x6bd3f825, 0x2460c6, 0x80000000}};
  // -7.0
  s21_decimal dec_2 = {{0x46, 0x0, 0x0, 0x80010000}};
  // -43978336913635353153079962.0
  s21_decimal dec_check = {{0xcc476a04, 0x3647b177, 0x16bc7c0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_495) {
  // 58429
  s21_decimal dec_1 = {{0xe43d, 0x0, 0x0, 0x0}};
  // -20605256631236509498
  s21_decimal dec_2 = {{0x1a9d3f3a, 0x1df493bc, 0x1, 0x80000000}};
  // -20605256631236451069
  s21_decimal dec_check = {{0x1a9c5afd, 0x1df493bc, 0x1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_496) {
  // 1592929213910287070
  s21_decimal dec_1 = {{0x2b7702de, 0x161b38ae, 0x0, 0x0}};
  // -397671176460385696.81900
  s21_decimal dec_2 = {{0x512983ec, 0xc79ed3da, 0x86b, 0x80050000}};
  // 1195258037449901373.18100
  s21_decimal dec_check = {{0x27967ad4, 0x81bdef38, 0x194f, 0x50000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_497) {
  // -1114519519802410320
  s21_decimal dec_1 = {{0x290fc550, 0xf779199, 0x0, 0x80000000}};
  // -3644372873045007.6608384
  s21_decimal dec_2 = {{0xb65fa780, 0x9e559131, 0x7b7, 0x80070000}};
  // -1118163892675455327.6608384
  s21_decimal dec_check = {{0xa35f2f80, 0xdc5e7d32, 0x93fcd, 0x80070000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_498) {
  // 3995107
  s21_decimal dec_1 = {{0x3cf5e3, 0x0, 0x0, 0x0}};
  // -7691178
  s21_decimal dec_2 = {{0x755baa, 0x0, 0x0, 0x80000000}};
  // -3696071
  s21_decimal dec_check = {{0x3865c7, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_499) {
  // -461893166798884945.27643291
  s21_decimal dec_1 = {{0xb4c1fe9b, 0xdfdf1686, 0x2634f7, 0x80080000}};
  // 8.7449228680920615590778
  s21_decimal dec_2 = {{0x2ef79b7a, 0xa1d6ef6d, 0x1284, 0x160000}};
  // -461893166798884936.53151004191
  s21_decimal dec_check = {{0x79fd361f, 0x7f6ffd66, 0x953ee842, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_500) {
  // -133788515918407206
  s21_decimal dec_1 = {{0x4657e626, 0x1db4ff2, 0x0, 0x80000000}};
  // 9274667410480186
  s21_decimal dec_2 = {{0xc8695c3a, 0x20f342, 0x0, 0x0}};
  // -124513848507927020
  s21_decimal dec_check = {{0x7dee89ec, 0x1ba5caf, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(fail_s21_add_1) {
  // 79228162514264337592150347315
  s21_decimal dec_1 = {{0xacef4e33, 0xffffffff, 0xffffffff, 0x0}};
  // 416116406530806629921174739
  s21_decimal dec_2 = {{0x45f7b4d3, 0x992f4e8b, 0x1583413, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_2) {
  // 1939448114359556
  s21_decimal dec_1 = {{0xf3eaad04, 0x6e3ea, 0x0, 0x0}};
  // 79228162514264337592421855578
  s21_decimal dec_2 = {{0xbd1e315a, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_3) {
  // -79228162514264337592389859604
  s21_decimal dec_1 = {{0xbb35f914, 0xffffffff, 0xffffffff, 0x80000000}};
  // -9500052587262.1
  s21_decimal dec_2 = {{0x8991ded, 0x5667, 0x0, 0x80010000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_4) {
  // 79228162514264337591768340850
  s21_decimal dec_1 = {{0x962a5972, 0xffffffff, 0xffffffff, 0x0}};
  // 143072271317613270240
  s21_decimal dec_2 = {{0xe6a5d4e0, 0xc186d0bb, 0x7, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_5) {
  // -1782314985608953020798762745
  s21_decimal dec_1 = {{0x9fa07ef9, 0xf8f80b9c, 0x5c24be0, 0x80000000}};
  // -79228162514264337591897126487
  s21_decimal dec_2 = {{0x9dd77657, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_6) {
  // -91850356741785296770498
  s21_decimal dec_1 = {{0x6a0f15c2, 0x37c2cc9b, 0x1373, 0x80000000}};
  // -79228162514264337592688123171
  s21_decimal dec_2 = {{0xccfd1d23, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_7) {
  // -63777799175215544
  s21_decimal dec_1 = {{0x86519b8, 0xe29592, 0x0, 0x80000000}};
  // -79228162514264337592172067163
  s21_decimal dec_2 = {{0xae3ab95b, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_8) {
  // 867237840585317192903674791
  s21_decimal dec_1 = {{0x6133cba7, 0x8a8cdd57, 0x2cd5cc1, 0x0}};
  // 79228162514264337593494279892
  s21_decimal dec_2 = {{0xfd0a16d4, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_9) {
  // 79228162514264337592798084928
  s21_decimal dec_1 = {{0xd38aff40, 0xffffffff, 0xffffffff, 0x0}};
  // 642015300577885728.9
  s21_decimal dec_2 = {{0xb11aed49, 0x5918f724, 0x0, 0x10000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_10) {
  // -55447044197779189
  s21_decimal dec_1 = {{0xfd4106f5, 0xc4fcca, 0x0, 0x80000000}};
  // -79228162514264337592257301835
  s21_decimal dec_2 = {{0xb34f4d4b, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_11) {
  // -52828655050.825
  s21_decimal dec_1 = {{0x2137e049, 0x300c, 0x0, 0x80030000}};
  // -79228162514264337592540802351
  s21_decimal dec_2 = {{0xc4352d2f, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_12) {
  // 79228162514264337592245769252
  s21_decimal dec_1 = {{0xb29f5424, 0xffffffff, 0xffffffff, 0x0}};
  // 36266634351778070939543192865
  s21_decimal dec_2 = {{0x6de2c521, 0xa592173b, 0x752f0e8b, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_13) {
  // -8879688040634672139563621859
  s21_decimal dec_1 = {{0x4826dde3, 0x3b84049e, 0x1cb11b15, 0x80000000}};
  // -78306976328757109818570737900
  s21_decimal dec_2 = {{0xbbfe88ec, 0xd20a6a86, 0xfd06033c, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_14) {
  // -9656015886742680414
  s21_decimal dec_1 = {{0xad3735e, 0x86010f4a, 0x0, 0x80000000}};
  // -79228162514264337592947948187
  s21_decimal dec_2 = {{0xdc79ba9b, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_15) {
  // -86447617020921
  s21_decimal dec_1 = {{0xa78113f9, 0x4e9f, 0x0, 0x80000000}};
  // -79228162514264337591840499322
  s21_decimal dec_2 = {{0x9a77667a, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_16) {
  // -79228162514264337592111373114
  s21_decimal dec_1 = {{0xaa9c9b3a, 0xffffffff, 0xffffffff, 0x80000000}};
  // -345970721933306
  s21_decimal dec_2 = {{0x95fbc7fa, 0x13aa8, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_17) {
  // -79228162514264337592170451536
  s21_decimal dec_1 = {{0xae221250, 0xffffffff, 0xffffffff, 0x80000000}};
  // -36790335635513438360614002
  s21_decimal dec_2 = {{0x9914b472, 0x1753f33a, 0x1e6ea8, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_18) {
  // -79228162514264337592985671964
  s21_decimal dec_1 = {{0xdeb9591c, 0xffffffff, 0xffffffff, 0x80000000}};
  // -73346805886226954795
  s21_decimal dec_2 = {{0x72167a2b, 0xf9e43358, 0x3, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_19) {
  // 49484515210991447393238262036
  s21_decimal dec_1 = {{0xaf5c2114, 0xceb4c581, 0x9fe4a1b0, 0x0}};
  // 50400707699078145450827635532
  s21_decimal dec_2 = {{0x5f50db4c, 0x1b7ca610, 0xa2da7cff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_20) {
  // -79228162514264337591828931524
  s21_decimal dec_1 = {{0x99c6e3c4, 0xffffffff, 0xffffffff, 0x80000000}};
  // -2185955667311884.92825
  s21_decimal dec_2 = {{0xe7afda19, 0xd99f75c5, 0xb, 0x80050000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_21) {
  // 871469399626868
  s21_decimal dec_1 = {{0xc7ff5474, 0x31898, 0x0, 0x0}};
  // 79228162514264337591640405624
  s21_decimal dec_2 = {{0x8e8a3678, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_22) {
  // -79228162514264337592874355998
  s21_decimal dec_1 = {{0xd816cd1e, 0xffffffff, 0xffffffff, 0x80000000}};
  // -193975152283
  s21_decimal dec_2 = {{0x29d1ee9b, 0x2d, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_23) {
  // 93923309610592
  s21_decimal dec_1 = {{0x39816660, 0x556c, 0x0, 0x0}};
  // 79228162514264337593525163225
  s21_decimal dec_2 = {{0xfee154d9, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_24) {
  // 79228162514264337593052482271
  s21_decimal dec_1 = {{0xe2b4cadf, 0xffffffff, 0xffffffff, 0x0}};
  // 7853545493719
  s21_decimal dec_2 = {{0x8bca14d7, 0x724, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_25) {
  // 79228162514264337592690134335
  s21_decimal dec_1 = {{0xcd1bcd3f, 0xffffffff, 0xffffffff, 0x0}};
  // 47409478671546161728236
  s21_decimal dec_2 = {{0x7f328aec, 0x12af6196, 0xa0a, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_26) {
  // 3575252184263486215490971153
  s21_decimal dec_1 = {{0xf1ed2611, 0x44a241ab, 0xb8d6119, 0x0}};
  // 79228162514264337591969197985
  s21_decimal dec_2 = {{0xa2232fa1, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_27) {
  // 50318755724756991019
  s21_decimal dec_1 = {{0x41cb3c2b, 0xba5021bb, 0x2, 0x0}};
  // 79228162514264337592170048204
  s21_decimal dec_2 = {{0xae1beacc, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_28) {
  // -22725375232956805137066667135
  s21_decimal dec_1 = {{0x9e20ac7f, 0xe7efc311, 0x496dfd63, 0x80000000}};
  // -76966601766702393924372067344
  s21_decimal dec_2 = {{0x6b6ef410, 0x36da6566, 0xf8b147e2, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_29) {
  // 3660874434110695134985536336
  s21_decimal dec_1 = {{0x28f54350, 0xbba41c19, 0xbd43450, 0x0}};
  // 79228162514264337591585916494
  s21_decimal dec_2 = {{0x8b4ac64e, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_30) {
  // -79228162514264337593318845058
  s21_decimal dec_1 = {{0xf2952a82, 0xffffffff, 0xffffffff, 0x80000000}};
  // -967022678006484244840920.43
  s21_decimal dec_2 = {{0x7365b88b, 0x71126494, 0x4ffd80, 0x80020000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_31) {
  // 79228162514264337593187925665
  s21_decimal dec_1 = {{0xeac77ea1, 0xffffffff, 0xffffffff, 0x0}};
  // 1864400195970239299474749397
  s21_decimal dec_2 = {{0x3b7cf7d5, 0x2485cdc1, 0x6063219, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_32) {
  // 79228162514264337593490372375
  s21_decimal dec_1 = {{0xfcce7717, 0xffffffff, 0xffffffff, 0x0}};
  // 33575397436557575
  s21_decimal dec_2 = {{0x65660907, 0x7748a5, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_33) {
  // 825197760644730
  s21_decimal dec_1 = {{0x5364867a, 0x2ee83, 0x0, 0x0}};
  // 79228162514264337591546612734
  s21_decimal dec_2 = {{0x88f30bfe, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_34) {
  // 53092549955093049800285
  s21_decimal dec_1 = {{0x8ab6765d, 0x272477c5, 0xb3e, 0x0}};
  // 79228162514264337593213245692
  s21_decimal dec_2 = {{0xec49d8fc, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_35) {
  // -538762058338416449745
  s21_decimal dec_1 = {{0x3797d8d1, 0x34d35593, 0x1d, 0x80000000}};
  // -79228162514264337593056028202
  s21_decimal dec_2 = {{0xe2eae62a, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_36) {
  // -79228162514264337591999758630
  s21_decimal dec_1 = {{0xa3f58126, 0xffffffff, 0xffffffff, 0x80000000}};
  // -496334918105295606
  s21_decimal dec_2 = {{0x7349eaf6, 0x6e355fa, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_37) {
  // -30876011247844
  s21_decimal dec_1 = {{0xe1aeb8e4, 0x1c14, 0x0, 0x80000000}};
  // -79228162514264337592112824831
  s21_decimal dec_2 = {{0xaab2c1ff, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_38) {
  // 79228162514264337592597800432
  s21_decimal dec_1 = {{0xc79ae5f0, 0xffffffff, 0xffffffff, 0x0}};
  // 76827524819472955769
  s21_decimal dec_2 = {{0xd313979, 0x2a3232c6, 0x4, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_39) {
  // -79228162514264337592356153402
  s21_decimal dec_1 = {{0xb933a83a, 0xffffffff, 0xffffffff, 0x80000000}};
  // -3204832789618376
  s21_decimal dec_2 = {{0x47fd5ec8, 0xb62c7, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_40) {
  // -52861772841568457637042
  s21_decimal dec_1 = {{0x766bcb2, 0xa47775bb, 0xb31, 0x80000000}};
  // -79228162514264337592513381140
  s21_decimal dec_2 = {{0xc292c314, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_41) {
  // -68924087786751408907598357731
  s21_decimal dec_1 = {{0xefdee4e3, 0xbfb64620, 0xdeb4ab4d, 0x80000000}};
  // -28234356971060274963479013025
  s21_decimal dec_2 = {{0x93d026a1, 0x56761e36, 0x5b3ae9a6, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_42) {
  // 79228162514264337592624630894
  s21_decimal dec_1 = {{0xc9344c6e, 0xffffffff, 0xffffffff, 0x0}};
  // 621453712071965737397363
  s21_decimal dec_2 = {{0x5a5eac73, 0x12bf9e92, 0x8399, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_43) {
  // -79228162514264337593055408821
  s21_decimal dec_1 = {{0xe2e172b5, 0xffffffff, 0xffffffff, 0x80000000}};
  // -79228162514264337591618000518
  s21_decimal dec_2 = {{0x8d345686, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_44) {
  // 99367286519190835342
  s21_decimal dec_1 = {{0x66d4d08e, 0x62ff849e, 0x5, 0x0}};
  // 79228162514264337592447685118
  s21_decimal dec_2 = {{0xbea851fe, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_45) {
  // -79228162514264337592642895570
  s21_decimal dec_1 = {{0xca4afed2, 0xffffffff, 0xffffffff, 0x80000000}};
  // -5125470405.564953287
  s21_decimal dec_2 = {{0x8e79f2c7, 0x4721542d, 0x0, 0x80090000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_46) {
  // -79228162514264337593442782603
  s21_decimal dec_1 = {{0xf9f84d8b, 0xffffffff, 0xffffffff, 0x80000000}};
  // -748775775
  s21_decimal dec_2 = {{0x2ca1695f, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_47) {
  // -890639219461368778330
  s21_decimal dec_1 = {{0x920f0e5a, 0x481a234a, 0x30, 0x80000000}};
  // -79228162514264337592525059146
  s21_decimal dec_2 = {{0xc344f44a, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_48) {
  // -89678056877967939.12226822
  s21_decimal dec_1 = {{0x8e9e7406, 0xb86fdc50, 0x76b01, 0x80080000}};
  // -79228162514264337591959981739
  s21_decimal dec_2 = {{0xa1968eab, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_49) {
  // 79228162514264337592965937801
  s21_decimal dec_1 = {{0xdd8c3a89, 0xffffffff, 0xffffffff, 0x0}};
  // 95431335971381025.19
  s21_decimal dec_2 = {{0xe58328f7, 0x84700571, 0x0, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_50) {
  // -628880436715.0344190210533
  s21_decimal dec_1 = {{0xe4aeb1e5, 0xc49279b0, 0x533b4, 0x800d0000}};
  // -79228162514264337593112964504
  s21_decimal dec_2 = {{0xe64fad98, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_51) {
  // 480617305921367.4523
  s21_decimal dec_1 = {{0xe37bc81b, 0x42b2f4ee, 0x0, 0x40000}};
  // 79228162514264337591646682063
  s21_decimal dec_2 = {{0x8ee9fbcf, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_52) {
  // 79228162514264337591460794201
  s21_decimal dec_1 = {{0x83d58f59, 0xffffffff, 0xffffffff, 0x0}};
  // 1984182289495242
  s21_decimal dec_2 = {{0x7088f4ca, 0x70c9a, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_53) {
  // -79228162514264337592439273107
  s21_decimal dec_1 = {{0xbe27f693, 0xffffffff, 0xffffffff, 0x80000000}};
  // -989532089466645188.52737635631
  s21_decimal dec_2 = {{0xce82152f, 0xb82324f2, 0x3fbc2d0d, 0x800b0000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_54) {
  // 79228162514264337591760976734
  s21_decimal dec_1 = {{0x95b9fb5e, 0xffffffff, 0xffffffff, 0x0}};
  // 9984659373.776832891
  s21_decimal dec_2 = {{0xa93e097b, 0x8a90a2cc, 0x0, 0x90000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_55) {
  // -59760589718035801
  s21_decimal dec_1 = {{0x91b61d59, 0xd44ff0, 0x0, 0x80000000}};
  // -79228162514264337592755909541
  s21_decimal dec_2 = {{0xd10773a5, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_56) {
  // -111356061772594714128028
  s21_decimal dec_1 = {{0x4b3a2e9c, 0x9fcbe079, 0x1794, 0x80000000}};
  // -79228162514264337592304161885
  s21_decimal dec_2 = {{0xb61a545d, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_57) {
  // -616275489082
  s21_decimal dec_1 = {{0x7ce1b13a, 0x8f, 0x0, 0x80000000}};
  // -79228162514264337592489787297
  s21_decimal dec_2 = {{0xc12abfa1, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_58) {
  // 79228162514264337592634769709
  s21_decimal dec_1 = {{0xc9cf012d, 0xffffffff, 0xffffffff, 0x0}};
  // 19102136717608295376989
  s21_decimal dec_2 = {{0xf4b4a85d, 0x87666934, 0x40b, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_59) {
  // 79228162514264337592880093630
  s21_decimal dec_1 = {{0xd86e59be, 0xffffffff, 0xffffffff, 0x0}};
  // 1597812135824726156245699
  s21_decimal dec_2 = {{0x2791fac3, 0x91c71913, 0x15259, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_60) {
  // -22165859356077869291
  s21_decimal dec_1 = {{0x44a48eb, 0x339cf3a5, 0x1, 0x80000000}};
  // -79228162514264337593157305914
  s21_decimal dec_2 = {{0xe8f4463a, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_61) {
  // -9300624119576507111336748
  s21_decimal dec_1 = {{0xae1a6b2c, 0xd8030056, 0x7b17b, 0x80000000}};
  // -79228162514264337591647716906
  s21_decimal dec_2 = {{0x8ef9c62a, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_62) {
  // -79228162514264337592889199896
  s21_decimal dec_1 = {{0xd8f94d18, 0xffffffff, 0xffffffff, 0x80000000}};
  // -1359974350
  s21_decimal dec_2 = {{0x510f8fce, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_63) {
  // -79228162514264337592566802995
  s21_decimal dec_1 = {{0xc5c1ea33, 0xffffffff, 0xffffffff, 0x80000000}};
  // -84097999984076433535.1489779
  s21_decimal dec_2 = {{0x398d64f3, 0x2467ed32, 0x2b7a471, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_64) {
  // -79228162514264337592386413413
  s21_decimal dec_1 = {{0xbb016365, 0xffffffff, 0xffffffff, 0x80000000}};
  // -903582830975
  s21_decimal dec_2 = {{0x61bbd17f, 0xd2, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_65) {
  // 79228162514264337592906144074
  s21_decimal dec_1 = {{0xd9fbd94a, 0xffffffff, 0xffffffff, 0x0}};
  // 35631427219427750415
  s21_decimal dec_2 = {{0xce2cf20f, 0xee7c4245, 0x1, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_66) {
  // -86995281790184472218
  s21_decimal dec_1 = {{0xef43e9a, 0xb74d53de, 0x4, 0x80000000}};
  // -79228162514264337592655082109
  s21_decimal dec_2 = {{0xcb04f27d, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_67) {
  // -79228162514264337593466649069
  s21_decimal dec_1 = {{0xfb6479ed, 0xffffffff, 0xffffffff, 0x80000000}};
  // -92930887041280132722155522
  s21_decimal dec_2 = {{0x77eb6002, 0x7b269ec1, 0x4cdee1, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_68) {
  // 79228162514264337592309035065
  s21_decimal dec_1 = {{0xb664b039, 0xffffffff, 0xffffffff, 0x0}};
  // 167524857516785
  s21_decimal dec_2 = {{0xeb9f92f1, 0x985c, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_69) {
  // -56002518242236191
  s21_decimal dec_1 = {{0x5e5b171f, 0xc6f5fe, 0x0, 0x80000000}};
  // -79228162514264337592041858254
  s21_decimal dec_2 = {{0xa677e4ce, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_70) {
  // -79228162514264337591515821410
  s21_decimal dec_1 = {{0x871d3562, 0xffffffff, 0xffffffff, 0x80000000}};
  // -4812608897488031794084
  s21_decimal dec_2 = {{0x7a7343a4, 0xe45d75f8, 0x104, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_71) {
  // 81593929775
  s21_decimal dec_1 = {{0xff60902f, 0x12, 0x0, 0x0}};
  // 79228162514264337593445222414
  s21_decimal dec_2 = {{0xfa1d880e, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_72) {
  // -79228162514264337592691075778
  s21_decimal dec_1 = {{0xcd2a2ac2, 0xffffffff, 0xffffffff, 0x80000000}};
  // -291445371626512978156686119
  s21_decimal dec_2 = {{0x8b3f8b27, 0x41009ba9, 0xf113f5, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_73) {
  // -79228162514264337593250204081
  s21_decimal dec_1 = {{0xee7dc9b1, 0xffffffff, 0xffffffff, 0x80000000}};
  // -29262107746350041234630
  s21_decimal dec_2 = {{0x90857cc6, 0x4d527603, 0x632, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_74) {
  // 81747386908938596847450.619
  s21_decimal dec_1 = {{0x7e63f9fb, 0xb95d9549, 0x439eae, 0x30000}};
  // 79228162514264337592701431876
  s21_decimal dec_2 = {{0xcdc83044, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_75) {
  // 699847792340676146
  s21_decimal dec_1 = {{0xf34eae32, 0x9b65bdb, 0x0, 0x0}};
  // 79228162514264337593334157138
  s21_decimal dec_2 = {{0xf37ecf52, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_76) {
  // 79228162514264337592539731617
  s21_decimal dec_1 = {{0xc424d6a1, 0xffffffff, 0xffffffff, 0x0}};
  // 969266857323739339002194
  s21_decimal dec_2 = {{0xa6579152, 0xfc66c09, 0xcd40, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_77) {
  // 4770650708
  s21_decimal dec_1 = {{0x1c5a5a54, 0x1, 0x0, 0x0}};
  // 79228162514264337591594842463
  s21_decimal dec_2 = {{0x8bd2f95f, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_78) {
  // 79228162514264337593425216068
  s21_decimal dec_1 = {{0xf8ec4244, 0xffffffff, 0xffffffff, 0x0}};
  // 8131088590561221
  s21_decimal dec_2 = {{0x9713dfc5, 0x1ce32e, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_79) {
  // -79228162514264337592348438950
  s21_decimal dec_1 = {{0xb8bdf1a6, 0xffffffff, 0xffffffff, 0x80000000}};
  // -63446488080633160
  s21_decimal dec_2 = {{0xa84acd48, 0xe1683e, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_80) {
  // -52530417346155238290070945951
  s21_decimal dec_1 = {{0x50ffc09f, 0x69e0d2dd, 0xa9bc248e, 0x80000000}};
  // -79228162514264337592774551573
  s21_decimal dec_2 = {{0xd223e815, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_81) {
  // 79228162514264337592181934688
  s21_decimal dec_1 = {{0xaed14a60, 0xffffffff, 0xffffffff, 0x0}};
  // 4543017298094045895968
  s21_decimal dec_2 = {{0xe6819d20, 0x4707b2ad, 0xf6, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_82) {
  // 30287266684795025
  s21_decimal dec_1 = {{0xcbf6f891, 0x6b9a1b, 0x0, 0x0}};
  // 79228162514264337592604304501
  s21_decimal dec_2 = {{0xc7fe2475, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_83) {
  // 7813656296854677
  s21_decimal dec_1 = {{0x9ff89495, 0x1bc27a, 0x0, 0x0}};
  // 79228162514264337592731367251
  s21_decimal dec_2 = {{0xcf90f753, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_84) {
  // 79228162514264337592232139544
  s21_decimal dec_1 = {{0xb1cf5b18, 0xffffffff, 0xffffffff, 0x0}};
  // 19297434498938.7063288
  s21_decimal dec_2 = {{0x9018fff8, 0x760e9858, 0xa, 0x70000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_85) {
  // 752840883511.033742252
  s21_decimal dec_1 = {{0xd26643ac, 0xcfc41ad4, 0x28, 0x90000}};
  // 79228162514264337592090577112
  s21_decimal dec_2 = {{0xa95f48d8, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_86) {
  // 66140309905226
  s21_decimal dec_1 = {{0x7dad5f4a, 0x3c27, 0x0, 0x0}};
  // 79228162514264337591688879038
  s21_decimal dec_2 = {{0x916ddbbe, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_87) {
  // -552448554082176434426
  s21_decimal dec_1 = {{0x9a4d80fa, 0xf2c388f0, 0x1d, 0x80000000}};
  // -79228162514264337592961495440
  s21_decimal dec_2 = {{0xdd487190, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_88) {
  // 79228162514264337593032420264
  s21_decimal dec_1 = {{0xe182aba8, 0xffffffff, 0xffffffff, 0x0}};
  // 394245180043
  s21_decimal dec_2 = {{0xcad80a8b, 0x5b, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_89) {
  // 79228162514264337593342208885
  s21_decimal dec_1 = {{0xf3f9ab75, 0xffffffff, 0xffffffff, 0x0}};
  // 375434025628285
  s21_decimal dec_2 = {{0x8bbbf27d, 0x15574, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_90) {
  // -79228162514264337593513923760
  s21_decimal dec_1 = {{0xfe35d4b0, 0xffffffff, 0xffffffff, 0x80000000}};
  // -67317689763366664894680
  s21_decimal dec_2 = {{0x2bd778d8, 0x4c9d3f60, 0xe41, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_91) {
  // -44703259902054208722913261348
  s21_decimal dec_1 = {{0xde30f724, 0x2649edc0, 0x9071ab7f, 0x80000000}};
  // -79228162514264337592706226363
  s21_decimal dec_2 = {{0xce1158bb, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_92) {
  // 52624049353599126
  s21_decimal dec_1 = {{0x485d2896, 0xbaf54b, 0x0, 0x0}};
  // 79228162514264337592028735654
  s21_decimal dec_2 = {{0xa5afa8a6, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_93) {
  // -79228162514264337593058499137
  s21_decimal dec_1 = {{0xe3109a41, 0xffffffff, 0xffffffff, 0x80000000}};
  // -8094969061556828753327325312
  s21_decimal dec_2 = {{0xf7408080, 0x231bccbb, 0x1a280060, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_94) {
  // 63923857332749152097
  s21_decimal dec_1 = {{0x9f432f61, 0x771f298f, 0x3, 0x0}};
  // 79228162514264337593442925294
  s21_decimal dec_2 = {{0xf9fa7aee, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_95) {
  // 80149412851244
  s21_decimal dec_1 = {{0x3d482e2c, 0x48e5, 0x0, 0x0}};
  // 79228162514264337591823300181
  s21_decimal dec_2 = {{0x9970f655, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_96) {
  // -79228162514264337591971979509
  s21_decimal dec_1 = {{0xa24da0f5, 0xffffffff, 0xffffffff, 0x80000000}};
  // -7293563584119597490186
  s21_decimal dec_2 = {{0xfd7ce00a, 0x62871ccc, 0x18b, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_97) {
  // 79228162514264337593451631937
  s21_decimal dec_1 = {{0xfa7f5541, 0xffffffff, 0xffffffff, 0x0}};
  // 5248367745
  s21_decimal dec_2 = {{0x38d3bc81, 0x1, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_98) {
  // -58093152732839220363554065837
  s21_decimal dec_1 = {{0x47da0dad, 0xf94c99c8, 0xbbb58797, 0x80000000}};
  // -76722195136656902818247484997
  s21_decimal dec_2 = {{0x70982645, 0x40423f10, 0xf7e71cc4, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_99) {
  // 571403173212
  s21_decimal dec_1 = {{0xa487d5c, 0x85, 0x0, 0x0}};
  // 79228162514264337593024886294
  s21_decimal dec_2 = {{0xe10fb616, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_100) {
  // 6856800023706648926
  s21_decimal dec_1 = {{0xececc15e, 0x5f283f4a, 0x0, 0x0}};
  // 79228162514264337592557840580
  s21_decimal dec_2 = {{0xc53928c4, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_101) {
  // -22201877456450.65944720009061
  s21_decimal dec_1 = {{0x8a0e765, 0xdb92791b, 0x72c7f0a, 0x800e0000}};
  // -79228162514264337592868928457
  s21_decimal dec_2 = {{0xd7c3fbc9, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_102) {
  // -79228162514264337593464805927
  s21_decimal dec_1 = {{0xfb485a27, 0xffffffff, 0xffffffff, 0x80000000}};
  // -714485278
  s21_decimal dec_2 = {{0x2a962e1e, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_103) {
  // -21579382431797082991613372879
  s21_decimal dec_1 = {{0x2abae9cf, 0xac28b6ed, 0x45ba0bf9, 0x80000000}};
  // -69633270113755866988567851272
  s21_decimal dec_2 = {{0xc7ebf108, 0xbaee9500, 0xe0ff4a80, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_104) {
  // -79228162514264337593340232766
  s21_decimal dec_1 = {{0xf3db843e, 0xffffffff, 0xffffffff, 0x80000000}};
  // -343979412343796188372597658
  s21_decimal dec_2 = {{0x4ce4fb9a, 0x4ec39006, 0x11c8879, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_105) {
  // -79228162514264337592444390315
  s21_decimal dec_1 = {{0xbe760bab, 0xffffffff, 0xffffffff, 0x80000000}};
  // -351512505850.8270623701693
  s21_decimal dec_2 = {{0xc9a6babd, 0x4fae0e86, 0x2e85b, 0x800d0000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_106) {
  // 79228162514264337592887266310
  s21_decimal dec_1 = {{0xd8dbcc06, 0xffffffff, 0xffffffff, 0x0}};
  // 97863221564.980514152702769566
  s21_decimal dec_2 = {{0xe887799e, 0x5bee7030, 0x3c368f3f, 0x120000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_107) {
  // -680377018427513499506917
  s21_decimal dec_1 = {{0xaf7f58e5, 0x4fe41be2, 0x9013, 0x80000000}};
  // -79228162514264337592583729988
  s21_decimal dec_2 = {{0xc6c43344, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_108) {
  // -79228162514264337592138891686
  s21_decimal dec_1 = {{0xac4081a6, 0xffffffff, 0xffffffff, 0x80000000}};
  // -4109361683167860
  s21_decimal dec_2 = {{0x5360fa74, 0xe9971, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_109) {
  // -12102847451429.22237
  s21_decimal dec_1 = {{0x37516bfd, 0x10cbcb90, 0x0, 0x80050000}};
  // -79228162514264337592468554842
  s21_decimal dec_2 = {{0xbfe6c45a, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_110) {
  // 8083437920.00488357801
  s21_decimal dec_1 = {{0x155abfa9, 0xd2060c09, 0x2b, 0xb0000}};
  // 79228162514264337592978201865
  s21_decimal dec_2 = {{0xde475d09, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_111) {
  // 79228162514264337593191290059
  s21_decimal dec_1 = {{0xeafad4cb, 0xffffffff, 0xffffffff, 0x0}};
  // 2807015929775
  s21_decimal dec_2 = {{0x8f2ff7af, 0x28d, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_112) {
  // 79228162514264337592248323444
  s21_decimal dec_1 = {{0xb2c64d74, 0xffffffff, 0xffffffff, 0x0}};
  // 250650242628707259631967831
  s21_decimal dec_2 = {{0xa6da9e57, 0xe12dac36, 0xcf5540, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_113) {
  // 6651630210370293357581803390
  s21_decimal dec_1 = {{0xd2219f7e, 0x3b9131df, 0x157e197c, 0x0}};
  // 78747412214548937833467033351
  s21_decimal dec_2 = {{0xc9ab3707, 0x801a8a0, 0xfe72552a, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_114) {
  // -79228162514264337592551292049
  s21_decimal dec_1 = {{0xc4d53c91, 0xffffffff, 0xffffffff, 0x80000000}};
  // -4696876982839876697509673
  s21_decimal dec_2 = {{0xaad4cf29, 0x36209415, 0x3e29a, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_115) {
  // -79228162514264337591411556800
  s21_decimal dec_1 = {{0x80e641c0, 0xffffffff, 0xffffffff, 0x80000000}};
  // -22552474574
  s21_decimal dec_2 = {{0x403b73ce, 0x5, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_116) {
  // 79228162514264337592517443378
  s21_decimal dec_1 = {{0xc2d0bf32, 0xffffffff, 0xffffffff, 0x0}};
  // 6018096577
  s21_decimal dec_2 = {{0x66b4ddc1, 0x1, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_117) {
  // -329520863679201838211756725
  s21_decimal dec_1 = {{0x918372b5, 0xd063416a, 0x11092c1, 0x80000000}};
  // -79228162514264337591812817202
  s21_decimal dec_2 = {{0x98d10132, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_118) {
  // 79228162514264337592684138716
  s21_decimal dec_1 = {{0xccc050dc, 0xffffffff, 0xffffffff, 0x0}};
  // 58773718037072238717850498958
  s21_decimal dec_2 = {{0x77b6378e, 0xace44fc, 0xbde87ae7, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_119) {
  // -866697721549
  s21_decimal dec_1 = {{0xcb35b6cd, 0xc9, 0x0, 0x80000000}};
  // -79228162514264337592001086951
  s21_decimal dec_2 = {{0xa409c5e7, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_120) {
  // 85852507715816781852
  s21_decimal dec_1 = {{0xc5bdf81c, 0xa77160e6, 0x4, 0x0}};
  // 79228162514264337592509902771
  s21_decimal dec_2 = {{0xc25dafb3, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_121) {
  // -79228162514264337593540291735
  s21_decimal dec_1 = {{0xffc82c97, 0xffffffff, 0xffffffff, 0x80000000}};
  // -10292487016486842758346629
  s21_decimal dec_2 = {{0xddd03785, 0xd6d4596f, 0x88384, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_122) {
  // -1891447843829228621226274641
  s21_decimal dec_1 = {{0xd0736f51, 0x1235d06d, 0x61c91a9, 0x80000000}};
  // -79228162514264337593243547918
  s21_decimal dec_2 = {{0xee18390e, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_123) {
  // -6842743361170990952
  s21_decimal dec_1 = {{0x23c26768, 0x5ef64ed5, 0x0, 0x80000000}};
  // -79228162514264337592431305683
  s21_decimal dec_2 = {{0xbdae63d3, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_124) {
  // 79228162514264337591880391772
  s21_decimal dec_1 = {{0x9cd81c5c, 0xffffffff, 0xffffffff, 0x0}};
  // 84601771217.866
  s21_decimal dec_2 = {{0xe28553ca, 0x4cf1, 0x0, 0x30000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_125) {
  // 79228162514264337592146601261
  s21_decimal dec_1 = {{0xacb6252d, 0xffffffff, 0xffffffff, 0x0}};
  // 81621881287513.059755
  s21_decimal dec_2 = {{0x6951b1ab, 0x6cbb2c94, 0x4, 0x60000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_126) {
  // -826864452957
  s21_decimal dec_1 = {{0x84f6455d, 0xc0, 0x0, 0x80000000}};
  // -79228162514264337592075703179
  s21_decimal dec_2 = {{0xa87c538b, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_127) {
  // 832809182987433992230231133
  s21_decimal dec_1 = {{0xc2bf5c5d, 0x45e6204c, 0x2b0e234, 0x0}};
  // 79228162514264337592781263994
  s21_decimal dec_2 = {{0xd28a547a, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_128) {
  // -79228162514264337591546134659
  s21_decimal dec_1 = {{0x88ebc083, 0xffffffff, 0xffffffff, 0x80000000}};
  // -1962024281733012482
  s21_decimal dec_2 = {{0x61631c02, 0x1b3a82b0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_129) {
  // -3862339443209830131428
  s21_decimal dec_1 = {{0x45efe6e4, 0x60ba2c0c, 0xd1, 0x80000000}};
  // -79228162514264337592214195032
  s21_decimal dec_2 = {{0xb0bd8b58, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_130) {
  // 79228162514264337592842688136
  s21_decimal dec_1 = {{0xd6339688, 0xffffffff, 0xffffffff, 0x0}};
  // 19204813346101057
  s21_decimal dec_2 = {{0xd78d741, 0x443aad, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_131) {
  // 79228162514264337592823825875
  s21_decimal dec_1 = {{0xd513c5d3, 0xffffffff, 0xffffffff, 0x0}};
  // 6829460081
  s21_decimal dec_2 = {{0x97114a71, 0x1, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_132) {
  // 88879001186.351366
  s21_decimal dec_1 = {{0xdb43906, 0x13bc2fb, 0x0, 0x60000}};
  // 79228162514264337591923696812
  s21_decimal dec_2 = {{0x9f6ce4ac, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_133) {
  // -79228162514264337591929352142
  s21_decimal dec_1 = {{0x9fc32fce, 0xffffffff, 0xffffffff, 0x80000000}};
  // -3506291366256930992242625785
  s21_decimal dec_2 = {{0x9f410cf9, 0xd549188c, 0xb545613, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_134) {
  // -79228162514264337592614432311
  s21_decimal dec_1 = {{0xc898ae37, 0xffffffff, 0xffffffff, 0x80000000}};
  // -237866927616961574.76
  s21_decimal dec_2 = {{0x1a413f24, 0x4a1b4f0a, 0x1, 0x80020000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_135) {
  // -79228162514264337592744244637
  s21_decimal dec_1 = {{0xd055759d, 0xffffffff, 0xffffffff, 0x80000000}};
  // -162712945555385623
  s21_decimal dec_2 = {{0xd82fad17, 0x242128f, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_136) {
  // 79228162514264337592842559631
  s21_decimal dec_1 = {{0xd631a08f, 0xffffffff, 0xffffffff, 0x0}};
  // 4527010985153.2
  s21_decimal dec_2 = {{0x44d10f8c, 0x292c, 0x0, 0x10000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_137) {
  // 514030488428
  s21_decimal dec_1 = {{0xae9acb6c, 0x77, 0x0, 0x0}};
  // 79228162514264337593263686743
  s21_decimal dec_2 = {{0xef4b8457, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_138) {
  // -79228162514264337592025875018
  s21_decimal dec_1 = {{0xa584024a, 0xffffffff, 0xffffffff, 0x80000000}};
  // -478846686010
  s21_decimal dec_2 = {{0x7d7c933a, 0x6f, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_139) {
  // -79228162514264337592163321816
  s21_decimal dec_1 = {{0xadb547d8, 0xffffffff, 0xffffffff, 0x80000000}};
  // -463937805451217363821433975
  s21_decimal dec_2 = {{0xa3249477, 0xd41339bc, 0x17fc2a6, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_140) {
  // 79228162514264337592444237235
  s21_decimal dec_1 = {{0xbe73b5b3, 0xffffffff, 0xffffffff, 0x0}};
  // 440217171993328472
  s21_decimal dec_2 = {{0x80b07b58, 0x61bf72f, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_141) {
  // -99746251295546
  s21_decimal dec_1 = {{0xfbe04b3a, 0x5ab7, 0x0, 0x80000000}};
  // -79228162514264337591690757909
  s21_decimal dec_2 = {{0x918a8715, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_142) {
  // 73672986980130521
  s21_decimal dec_1 = {{0xfa7e1ed9, 0x105bd30, 0x0, 0x0}};
  // 79228162514264337592993603749
  s21_decimal dec_2 = {{0xdf3260a5, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_143) {
  // 869867493910
  s21_decimal dec_1 = {{0x88249a16, 0xca, 0x0, 0x0}};
  // 79228162514264337593017817308
  s21_decimal dec_2 = {{0xe0a3d8dc, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_144) {
  // -107539292690651
  s21_decimal dec_1 = {{0x715718db, 0x61ce, 0x0, 0x80000000}};
  // -79228162514264337593195681707
  s21_decimal dec_2 = {{0xeb3dd7ab, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_145) {
  // 79228162514264337592642474394
  s21_decimal dec_1 = {{0xca44919a, 0xffffffff, 0xffffffff, 0x0}};
  // 97698597253714242935948807
  s21_decimal dec_2 = {{0xda1b8607, 0x91cee442, 0x50d07b, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_146) {
  // 79228162514264337592185128984
  s21_decimal dec_1 = {{0xaf020818, 0xffffffff, 0xffffffff, 0x0}};
  // 87331911953321102.3602553
  s21_decimal dec_2 = {{0x3b287379, 0xb96dec74, 0xb8ee, 0x70000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_147) {
  // 40292548241.88
  s21_decimal dec_1 = {{0x224d70fc, 0x3aa, 0x0, 0x20000}};
  // 79228162514264337591848151026
  s21_decimal dec_2 = {{0x9aec27f2, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_148) {
  // 132097724516944065920909.15
  s21_decimal dec_1 = {{0x2323d323, 0x3312fa0c, 0xaed47, 0x20000}};
  // 79228162514264337592185402744
  s21_decimal dec_2 = {{0xaf063578, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_149) {
  // 40554199158183028406375347
  s21_decimal dec_1 = {{0x5ea453b3, 0x8aa2139c, 0x218baf, 0x0}};
  // 79228162514264337591977467054
  s21_decimal dec_2 = {{0xa2a15cae, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_150) {
  // -79228162514264337592612363875
  s21_decimal dec_1 = {{0xc8791e63, 0xffffffff, 0xffffffff, 0x80000000}};
  // -78752463320
  s21_decimal dec_2 = {{0x560339d8, 0x12, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_151) {
  // 231661378850
  s21_decimal dec_1 = {{0xf0181d22, 0x35, 0x0, 0x0}};
  // 79228162514264337592060271497
  s21_decimal dec_2 = {{0xa790db89, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_152) {
  // -79228162514264337592092121764
  s21_decimal dec_1 = {{0xa976daa4, 0xffffffff, 0xffffffff, 0x80000000}};
  // -521261272729683032.974689
  s21_decimal dec_2 = {{0x6176a561, 0xa155db0f, 0x6e61, 0x80060000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_153) {
  // 79228162514264337592571447170
  s21_decimal dec_1 = {{0xc608c782, 0xffffffff, 0xffffffff, 0x0}};
  // 31831117975
  s21_decimal dec_2 = {{0x69485097, 0x7, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_154) {
  // -79228162514264337593442405103
  s21_decimal dec_1 = {{0xf9f28aef, 0xffffffff, 0xffffffff, 0x80000000}};
  // -2521875990434.5454432
  s21_decimal dec_2 = {{0xae5ff760, 0x5dfb0884, 0x1, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_155) {
  // 79228162514264337593091992795
  s21_decimal dec_1 = {{0xe50facdb, 0xffffffff, 0xffffffff, 0x0}};
  // 205717047563709520
  s21_decimal dec_2 = {{0x9846ec50, 0x2dada90, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_156) {
  // 79228162514264337591744792104
  s21_decimal dec_1 = {{0x94c30628, 0xffffffff, 0xffffffff, 0x0}};
  // 989983088774489.1561529370586
  s21_decimal dec_2 = {{0xa60e7da, 0xc95efb8f, 0x1ffcf2bb, 0xd0000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_157) {
  // 79228162514264337593251785881
  s21_decimal dec_1 = {{0xee95ec99, 0xffffffff, 0xffffffff, 0x0}};
  // 246315852118272317497
  s21_decimal dec_2 = {{0xd9451839, 0x5a51b276, 0xd, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_158) {
  // -802097965434391946597340070
  s21_decimal dec_1 = {{0x3ecd93a6, 0xd560d0ce, 0x2977ad9, 0x80000000}};
  // -79228162514264337592323991409
  s21_decimal dec_2 = {{0xb748e771, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_159) {
  // 79228162514264337592634779552
  s21_decimal dec_1 = {{0xc9cf27a0, 0xffffffff, 0xffffffff, 0x0}};
  // 3471286270678333172703548
  s21_decimal dec_2 = {{0x63f613c, 0xce48df0d, 0x2df12, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_160) {
  // 79228162514264337591969590383
  s21_decimal dec_1 = {{0xa2292c6f, 0xffffffff, 0xffffffff, 0x0}};
  // 66537794028928658141
  s21_decimal dec_2 = {{0x10666add, 0x9b65bb23, 0x3, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_161) {
  // 462623546.0778121234108022753
  s21_decimal dec_1 = {{0x3dc27fe1, 0xd9aa5e9f, 0xef2bb76, 0x130000}};
  // 79228162514264337593469304861
  s21_decimal dec_2 = {{0xfb8d001d, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_162) {
  // 75646798681902048245929779409
  s21_decimal dec_1 = {{0x32aca0d1, 0x9fe51c4a, 0xf46d90b5, 0x0}};
  // 3826050499341901540173697145
  s21_decimal dec_2 = {{0x9f625079, 0x2bd975e8, 0xc5cd5b5, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_163) {
  // 198091806443689.429
  s21_decimal dec_1 = {{0xcbfdd5d5, 0x2bfc372, 0x0, 0x30000}};
  // 79228162514264337593246908437
  s21_decimal dec_2 = {{0xee4b8015, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_164) {
  // 79228162514264337593063439052
  s21_decimal dec_1 = {{0xe35bfacc, 0xffffffff, 0xffffffff, 0x0}};
  // 48937431849043875919317
  s21_decimal dec_2 = {{0x43d4f5d5, 0xe74b8914, 0xa5c, 0x0}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_165) {
  // -6611365493446755.79
  s21_decimal dec_1 = {{0x53b786fb, 0x92cd430, 0x0, 0x80020000}};
  // -79228162514264337592101043376
  s21_decimal dec_2 = {{0xa9fefcb0, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_add_166) {
  // -293152320032149807115834663
  s21_decimal dec_1 = {{0xf9bc9527, 0x1cc6521a, 0xf27d6b, 0x80000000}};
  // -79228162514264337591982674243
  s21_decimal dec_2 = {{0xa2f0d143, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_add(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

Suite *suite_s21_add(void) {
  Suite *c = suite_create("s21_add_cases");
  TCase *tc = tcase_create("s21_add_tc");

  tcase_add_test(tc, invalid_dec_s21_add_1);
  tcase_add_test(tc, invalid_dec_s21_add_2);
  tcase_add_test(tc, invalid_dec_s21_add_3);
  tcase_add_test(tc, invalid_dec_s21_add_4);
  tcase_add_test(tc, invalid_dec_s21_add_5);
  tcase_add_test(tc, invalid_dec_s21_add_6);
  tcase_add_test(tc, invalid_dec_s21_add_7);
  tcase_add_test(tc, invalid_dec_s21_add_8);
  tcase_add_test(tc, invalid_dec_s21_add_9);
  tcase_add_test(tc, invalid_dec_s21_add_10);
  tcase_add_test(tc, invalid_dec_s21_add_11);
  tcase_add_test(tc, invalid_dec_s21_add_12);
  tcase_add_test(tc, invalid_dec_s21_add_13);
  tcase_add_test(tc, invalid_dec_s21_add_14);
  tcase_add_test(tc, invalid_dec_s21_add_15);
  tcase_add_test(tc, invalid_dec_s21_add_16);
  tcase_add_test(tc, s21_add_1);
  tcase_add_test(tc, s21_add_2);
  tcase_add_test(tc, s21_add_3);
  tcase_add_test(tc, s21_add_4);
  tcase_add_test(tc, s21_add_5);
  tcase_add_test(tc, s21_add_6);
  tcase_add_test(tc, s21_add_7);
  tcase_add_test(tc, s21_add_8);
  tcase_add_test(tc, s21_add_9);
  tcase_add_test(tc, s21_add_10);
  tcase_add_test(tc, s21_add_11);
  tcase_add_test(tc, s21_add_13);
  tcase_add_test(tc, s21_add_14);
  tcase_add_test(tc, s21_add_15);
  tcase_add_test(tc, s21_add_16);
  tcase_add_test(tc, s21_add_17);
  tcase_add_test(tc, s21_add_18);
  tcase_add_test(tc, s21_add_19);
  tcase_add_test(tc, s21_add_20);
  tcase_add_test(tc, s21_add_21);
  tcase_add_test(tc, s21_add_22);
  tcase_add_test(tc, s21_add_23);
  tcase_add_test(tc, s21_add_24);
  tcase_add_test(tc, s21_add_25);
  tcase_add_test(tc, s21_add_26);
  tcase_add_test(tc, s21_add_28);
  tcase_add_test(tc, s21_add_29);
  tcase_add_test(tc, s21_add_30);
  tcase_add_test(tc, s21_add_31);
  tcase_add_test(tc, s21_add_32);
  tcase_add_test(tc, s21_add_33);
  tcase_add_test(tc, s21_add_34);
  tcase_add_test(tc, s21_add_35);
  tcase_add_test(tc, s21_add_36);
  tcase_add_test(tc, s21_add_37);
  tcase_add_test(tc, s21_add_38);
  tcase_add_test(tc, s21_add_39);
  tcase_add_test(tc, s21_add_40);
  tcase_add_test(tc, s21_add_41);
  tcase_add_test(tc, s21_add_42);
  tcase_add_test(tc, s21_add_43);
  tcase_add_test(tc, s21_add_44);
  tcase_add_test(tc, s21_add_45);
  tcase_add_test(tc, s21_add_46);
  tcase_add_test(tc, s21_add_47);
  tcase_add_test(tc, s21_add_48);
  tcase_add_test(tc, s21_add_50);
  tcase_add_test(tc, s21_add_51);
  tcase_add_test(tc, s21_add_52);
  tcase_add_test(tc, s21_add_53);
  tcase_add_test(tc, s21_add_54);
  tcase_add_test(tc, s21_add_56);
  tcase_add_test(tc, s21_add_57);
  tcase_add_test(tc, s21_add_58);
  tcase_add_test(tc, s21_add_59);
  tcase_add_test(tc, s21_add_61);
  tcase_add_test(tc, s21_add_62);
  tcase_add_test(tc, s21_add_63);
  tcase_add_test(tc, s21_add_64);
  tcase_add_test(tc, s21_add_65);
  tcase_add_test(tc, s21_add_66);
  tcase_add_test(tc, s21_add_67);
  tcase_add_test(tc, s21_add_68);
  tcase_add_test(tc, s21_add_69);
  tcase_add_test(tc, s21_add_70);
  tcase_add_test(tc, s21_add_71);
  tcase_add_test(tc, s21_add_72);
  tcase_add_test(tc, s21_add_73);
  tcase_add_test(tc, s21_add_74);
  tcase_add_test(tc, s21_add_75);
  tcase_add_test(tc, s21_add_76);
  tcase_add_test(tc, s21_add_77);
  tcase_add_test(tc, s21_add_78);
  tcase_add_test(tc, s21_add_79);
  tcase_add_test(tc, s21_add_80);
  tcase_add_test(tc, s21_add_81);
  tcase_add_test(tc, s21_add_82);
  tcase_add_test(tc, s21_add_83);
  tcase_add_test(tc, s21_add_84);
  tcase_add_test(tc, s21_add_85);
  tcase_add_test(tc, s21_add_86);
  tcase_add_test(tc, s21_add_87);
  tcase_add_test(tc, s21_add_88);
  tcase_add_test(tc, s21_add_89);
  tcase_add_test(tc, s21_add_90);
  tcase_add_test(tc, s21_add_91);
  tcase_add_test(tc, s21_add_92);
  tcase_add_test(tc, s21_add_93);
  tcase_add_test(tc, s21_add_94);
  tcase_add_test(tc, s21_add_95);
  tcase_add_test(tc, s21_add_96);
  tcase_add_test(tc, s21_add_97);
  tcase_add_test(tc, s21_add_98);
  tcase_add_test(tc, s21_add_99);
  tcase_add_test(tc, s21_add_100);
  tcase_add_test(tc, s21_add_101);
  tcase_add_test(tc, s21_add_102);
  tcase_add_test(tc, s21_add_103);
  tcase_add_test(tc, s21_add_105);
  tcase_add_test(tc, s21_add_106);
  tcase_add_test(tc, s21_add_107);
  tcase_add_test(tc, s21_add_108);
  tcase_add_test(tc, s21_add_109);
  tcase_add_test(tc, s21_add_110);
  tcase_add_test(tc, s21_add_111);
  tcase_add_test(tc, s21_add_112);
  tcase_add_test(tc, s21_add_113);
  tcase_add_test(tc, s21_add_114);
  tcase_add_test(tc, s21_add_115);
  tcase_add_test(tc, s21_add_116);
  tcase_add_test(tc, s21_add_117);
  tcase_add_test(tc, s21_add_118);
  tcase_add_test(tc, s21_add_119);
  tcase_add_test(tc, s21_add_120);
  tcase_add_test(tc, s21_add_121);
  tcase_add_test(tc, s21_add_122);
  tcase_add_test(tc, s21_add_123);
  tcase_add_test(tc, s21_add_124);
  tcase_add_test(tc, s21_add_125);
  tcase_add_test(tc, s21_add_126);
  tcase_add_test(tc, s21_add_127);
  tcase_add_test(tc, s21_add_128);
  tcase_add_test(tc, s21_add_129);
  tcase_add_test(tc, s21_add_130);
  tcase_add_test(tc, s21_add_131);
  tcase_add_test(tc, s21_add_133);
  tcase_add_test(tc, s21_add_134);
  tcase_add_test(tc, s21_add_136);
  tcase_add_test(tc, s21_add_137);
  tcase_add_test(tc, s21_add_138);
  tcase_add_test(tc, s21_add_139);
  tcase_add_test(tc, s21_add_140);
  tcase_add_test(tc, s21_add_141);
  tcase_add_test(tc, s21_add_142);
  tcase_add_test(tc, s21_add_143);
  tcase_add_test(tc, s21_add_144);
  tcase_add_test(tc, s21_add_145);
  tcase_add_test(tc, s21_add_146);
  tcase_add_test(tc, s21_add_147);
  tcase_add_test(tc, s21_add_148);
  tcase_add_test(tc, s21_add_149);
  tcase_add_test(tc, s21_add_150);
  tcase_add_test(tc, s21_add_151);
  tcase_add_test(tc, s21_add_152);
  tcase_add_test(tc, s21_add_153);
  tcase_add_test(tc, s21_add_154);
  tcase_add_test(tc, s21_add_155);
  tcase_add_test(tc, s21_add_156);
  tcase_add_test(tc, s21_add_157);
  tcase_add_test(tc, s21_add_158);
  tcase_add_test(tc, s21_add_159);
  tcase_add_test(tc, s21_add_160);
  tcase_add_test(tc, s21_add_161);
  tcase_add_test(tc, s21_add_162);
  tcase_add_test(tc, s21_add_163);
  tcase_add_test(tc, s21_add_164);
  tcase_add_test(tc, s21_add_165);
  tcase_add_test(tc, s21_add_166);
  tcase_add_test(tc, s21_add_167);
  tcase_add_test(tc, s21_add_168);
  tcase_add_test(tc, s21_add_169);
  tcase_add_test(tc, s21_add_170);
  tcase_add_test(tc, s21_add_171);
  tcase_add_test(tc, s21_add_172);
  tcase_add_test(tc, s21_add_173);
  tcase_add_test(tc, s21_add_174);
  tcase_add_test(tc, s21_add_175);
  tcase_add_test(tc, s21_add_176);
  tcase_add_test(tc, s21_add_177);
  tcase_add_test(tc, s21_add_178);
  tcase_add_test(tc, s21_add_179);
  tcase_add_test(tc, s21_add_180);
  tcase_add_test(tc, s21_add_181);
  tcase_add_test(tc, s21_add_182);
  tcase_add_test(tc, s21_add_183);
  tcase_add_test(tc, s21_add_184);
  tcase_add_test(tc, s21_add_185);
  tcase_add_test(tc, s21_add_187);
  tcase_add_test(tc, s21_add_188);
  tcase_add_test(tc, s21_add_189);
  tcase_add_test(tc, s21_add_190);
  tcase_add_test(tc, s21_add_191);
  tcase_add_test(tc, s21_add_192);
  tcase_add_test(tc, s21_add_193);
  tcase_add_test(tc, s21_add_194);
  tcase_add_test(tc, s21_add_195);
  tcase_add_test(tc, s21_add_196);
  tcase_add_test(tc, s21_add_197);
  tcase_add_test(tc, s21_add_198);
  tcase_add_test(tc, s21_add_199);
  tcase_add_test(tc, s21_add_200);
  tcase_add_test(tc, s21_add_201);
  tcase_add_test(tc, s21_add_202);
  tcase_add_test(tc, s21_add_203);
  tcase_add_test(tc, s21_add_204);
  tcase_add_test(tc, s21_add_205);
  tcase_add_test(tc, s21_add_206);
  tcase_add_test(tc, s21_add_207);
  tcase_add_test(tc, s21_add_208);
  tcase_add_test(tc, s21_add_209);
  tcase_add_test(tc, s21_add_210);
  tcase_add_test(tc, s21_add_211);
  tcase_add_test(tc, s21_add_212);
  tcase_add_test(tc, s21_add_213);
  tcase_add_test(tc, s21_add_214);
  tcase_add_test(tc, s21_add_215);
  tcase_add_test(tc, s21_add_216);
  tcase_add_test(tc, s21_add_217);
  tcase_add_test(tc, s21_add_218);
  tcase_add_test(tc, s21_add_219);
  tcase_add_test(tc, s21_add_220);
  tcase_add_test(tc, s21_add_221);
  tcase_add_test(tc, s21_add_222);
  tcase_add_test(tc, s21_add_223);
  tcase_add_test(tc, s21_add_224);
  tcase_add_test(tc, s21_add_226);
  tcase_add_test(tc, s21_add_227);
  tcase_add_test(tc, s21_add_228);
  tcase_add_test(tc, s21_add_229);
  tcase_add_test(tc, s21_add_230);
  tcase_add_test(tc, s21_add_231);
  tcase_add_test(tc, s21_add_232);
  tcase_add_test(tc, s21_add_233);
  tcase_add_test(tc, s21_add_234);
  tcase_add_test(tc, s21_add_235);
  tcase_add_test(tc, s21_add_236);
  tcase_add_test(tc, s21_add_237);
  tcase_add_test(tc, s21_add_238);
  tcase_add_test(tc, s21_add_239);
  tcase_add_test(tc, s21_add_242);
  tcase_add_test(tc, s21_add_243);
  tcase_add_test(tc, s21_add_246);
  tcase_add_test(tc, s21_add_247);
  tcase_add_test(tc, s21_add_248);
  tcase_add_test(tc, s21_add_249);
  tcase_add_test(tc, s21_add_250);
  tcase_add_test(tc, s21_add_251);
  tcase_add_test(tc, s21_add_253);
  tcase_add_test(tc, s21_add_254);
  tcase_add_test(tc, s21_add_255);
  tcase_add_test(tc, s21_add_256);
  tcase_add_test(tc, s21_add_257);
  tcase_add_test(tc, s21_add_258);
  tcase_add_test(tc, s21_add_259);
  tcase_add_test(tc, s21_add_260);
  tcase_add_test(tc, s21_add_261);
  tcase_add_test(tc, s21_add_262);
  tcase_add_test(tc, s21_add_263);
  tcase_add_test(tc, s21_add_264);
  tcase_add_test(tc, s21_add_265);
  tcase_add_test(tc, s21_add_266);
  tcase_add_test(tc, s21_add_267);
  tcase_add_test(tc, s21_add_268);
  tcase_add_test(tc, s21_add_269);
  tcase_add_test(tc, s21_add_270);
  tcase_add_test(tc, s21_add_271);
  tcase_add_test(tc, s21_add_272);
  tcase_add_test(tc, s21_add_273);
  tcase_add_test(tc, s21_add_274);
  tcase_add_test(tc, s21_add_275);
  tcase_add_test(tc, s21_add_276);
  tcase_add_test(tc, s21_add_277);
  tcase_add_test(tc, s21_add_278);
  tcase_add_test(tc, s21_add_279);
  tcase_add_test(tc, s21_add_280);
  tcase_add_test(tc, s21_add_281);
  tcase_add_test(tc, s21_add_282);
  tcase_add_test(tc, s21_add_283);
  tcase_add_test(tc, s21_add_284);
  tcase_add_test(tc, s21_add_285);
  tcase_add_test(tc, s21_add_286);
  tcase_add_test(tc, s21_add_287);
  tcase_add_test(tc, s21_add_288);
  tcase_add_test(tc, s21_add_289);
  tcase_add_test(tc, s21_add_290);
  tcase_add_test(tc, s21_add_292);
  tcase_add_test(tc, s21_add_293);
  tcase_add_test(tc, s21_add_294);
  tcase_add_test(tc, s21_add_295);
  tcase_add_test(tc, s21_add_296);
  tcase_add_test(tc, s21_add_297);
  tcase_add_test(tc, s21_add_298);
  tcase_add_test(tc, s21_add_300);
  tcase_add_test(tc, s21_add_301);
  tcase_add_test(tc, s21_add_302);
  tcase_add_test(tc, s21_add_303);
  tcase_add_test(tc, s21_add_304);
  tcase_add_test(tc, s21_add_305);
  tcase_add_test(tc, s21_add_306);
  tcase_add_test(tc, s21_add_307);
  tcase_add_test(tc, s21_add_308);
  tcase_add_test(tc, s21_add_309);
  tcase_add_test(tc, s21_add_310);
  tcase_add_test(tc, s21_add_311);
  tcase_add_test(tc, s21_add_312);
  tcase_add_test(tc, s21_add_313);
  tcase_add_test(tc, s21_add_314);
  tcase_add_test(tc, s21_add_315);
  tcase_add_test(tc, s21_add_316);
  tcase_add_test(tc, s21_add_317);
  tcase_add_test(tc, s21_add_318);
  tcase_add_test(tc, s21_add_320);
  tcase_add_test(tc, s21_add_321);
  tcase_add_test(tc, s21_add_322);
  tcase_add_test(tc, s21_add_323);
  tcase_add_test(tc, s21_add_324);
  tcase_add_test(tc, s21_add_325);
  tcase_add_test(tc, s21_add_326);
  tcase_add_test(tc, s21_add_327);
  tcase_add_test(tc, s21_add_328);
  tcase_add_test(tc, s21_add_329);
  tcase_add_test(tc, s21_add_330);
  tcase_add_test(tc, s21_add_331);
  tcase_add_test(tc, s21_add_332);
  tcase_add_test(tc, s21_add_333);
  tcase_add_test(tc, s21_add_334);
  tcase_add_test(tc, s21_add_335);
  tcase_add_test(tc, s21_add_336);
  tcase_add_test(tc, s21_add_337);
  tcase_add_test(tc, s21_add_338);
  tcase_add_test(tc, s21_add_339);
  tcase_add_test(tc, s21_add_340);
  tcase_add_test(tc, s21_add_342);
  tcase_add_test(tc, s21_add_343);
  tcase_add_test(tc, s21_add_344);
  tcase_add_test(tc, s21_add_345);
  tcase_add_test(tc, s21_add_346);
  tcase_add_test(tc, s21_add_347);
  tcase_add_test(tc, s21_add_348);
  tcase_add_test(tc, s21_add_349);
  tcase_add_test(tc, s21_add_350);
  tcase_add_test(tc, s21_add_351);
  tcase_add_test(tc, s21_add_352);
  tcase_add_test(tc, s21_add_353);
  tcase_add_test(tc, s21_add_354);
  tcase_add_test(tc, s21_add_355);
  tcase_add_test(tc, s21_add_356);
  tcase_add_test(tc, s21_add_357);
  tcase_add_test(tc, s21_add_359);
  tcase_add_test(tc, s21_add_360);
  tcase_add_test(tc, s21_add_361);
  tcase_add_test(tc, s21_add_362);
  tcase_add_test(tc, s21_add_363);
  tcase_add_test(tc, s21_add_364);
  tcase_add_test(tc, s21_add_365);
  tcase_add_test(tc, s21_add_366);
  tcase_add_test(tc, s21_add_368);
  tcase_add_test(tc, s21_add_369);
  tcase_add_test(tc, s21_add_370);
  tcase_add_test(tc, s21_add_371);
  tcase_add_test(tc, s21_add_372);
  tcase_add_test(tc, s21_add_373);
  tcase_add_test(tc, s21_add_374);
  tcase_add_test(tc, s21_add_375);
  tcase_add_test(tc, s21_add_376);
  tcase_add_test(tc, s21_add_377);
  tcase_add_test(tc, s21_add_378);
  tcase_add_test(tc, s21_add_379);
  tcase_add_test(tc, s21_add_380);
  tcase_add_test(tc, s21_add_381);
  tcase_add_test(tc, s21_add_382);
  tcase_add_test(tc, s21_add_383);
  tcase_add_test(tc, s21_add_384);
  tcase_add_test(tc, s21_add_385);
  tcase_add_test(tc, s21_add_386);
  tcase_add_test(tc, s21_add_387);
  tcase_add_test(tc, s21_add_388);
  tcase_add_test(tc, s21_add_389);
  tcase_add_test(tc, s21_add_390);
  tcase_add_test(tc, s21_add_391);
  tcase_add_test(tc, s21_add_392);
  tcase_add_test(tc, s21_add_393);
  tcase_add_test(tc, s21_add_394);
  tcase_add_test(tc, s21_add_395);
  tcase_add_test(tc, s21_add_396);
  tcase_add_test(tc, s21_add_397);
  tcase_add_test(tc, s21_add_398);
  tcase_add_test(tc, s21_add_399);
  tcase_add_test(tc, s21_add_400);
  tcase_add_test(tc, s21_add_401);
  tcase_add_test(tc, s21_add_402);
  tcase_add_test(tc, s21_add_403);
  tcase_add_test(tc, s21_add_404);
  tcase_add_test(tc, s21_add_405);
  tcase_add_test(tc, s21_add_406);
  tcase_add_test(tc, s21_add_407);
  tcase_add_test(tc, s21_add_408);
  tcase_add_test(tc, s21_add_409);
  tcase_add_test(tc, s21_add_410);
  tcase_add_test(tc, s21_add_411);
  tcase_add_test(tc, s21_add_412);
  tcase_add_test(tc, s21_add_413);
  tcase_add_test(tc, s21_add_414);
  tcase_add_test(tc, s21_add_415);
  tcase_add_test(tc, s21_add_416);
  tcase_add_test(tc, s21_add_417);
  tcase_add_test(tc, s21_add_418);
  tcase_add_test(tc, s21_add_419);
  tcase_add_test(tc, s21_add_420);
  tcase_add_test(tc, s21_add_421);
  tcase_add_test(tc, s21_add_422);
  tcase_add_test(tc, s21_add_423);
  tcase_add_test(tc, s21_add_424);
  tcase_add_test(tc, s21_add_425);
  tcase_add_test(tc, s21_add_426);
  tcase_add_test(tc, s21_add_427);
  tcase_add_test(tc, s21_add_428);
  tcase_add_test(tc, s21_add_429);
  tcase_add_test(tc, s21_add_430);
  tcase_add_test(tc, s21_add_431);
  tcase_add_test(tc, s21_add_432);
  tcase_add_test(tc, s21_add_433);
  tcase_add_test(tc, s21_add_434);
  tcase_add_test(tc, s21_add_435);
  tcase_add_test(tc, s21_add_436);
  tcase_add_test(tc, s21_add_437);
  tcase_add_test(tc, s21_add_438);
  tcase_add_test(tc, s21_add_439);
  tcase_add_test(tc, s21_add_440);
  tcase_add_test(tc, s21_add_441);
  tcase_add_test(tc, s21_add_442);
  tcase_add_test(tc, s21_add_443);
  tcase_add_test(tc, s21_add_444);
  tcase_add_test(tc, s21_add_445);
  tcase_add_test(tc, s21_add_446);
  tcase_add_test(tc, s21_add_447);
  tcase_add_test(tc, s21_add_448);
  tcase_add_test(tc, s21_add_449);
  tcase_add_test(tc, s21_add_450);
  tcase_add_test(tc, s21_add_451);
  tcase_add_test(tc, s21_add_452);
  tcase_add_test(tc, s21_add_453);
  tcase_add_test(tc, s21_add_454);
  tcase_add_test(tc, s21_add_455);
  tcase_add_test(tc, s21_add_456);
  tcase_add_test(tc, s21_add_457);
  tcase_add_test(tc, s21_add_459);
  tcase_add_test(tc, s21_add_460);
  tcase_add_test(tc, s21_add_461);
  tcase_add_test(tc, s21_add_462);
  tcase_add_test(tc, s21_add_463);
  tcase_add_test(tc, s21_add_464);
  tcase_add_test(tc, s21_add_465);
  tcase_add_test(tc, s21_add_466);
  tcase_add_test(tc, s21_add_467);
  tcase_add_test(tc, s21_add_468);
  tcase_add_test(tc, s21_add_469);
  tcase_add_test(tc, s21_add_470);
  tcase_add_test(tc, s21_add_471);
  tcase_add_test(tc, s21_add_472);
  tcase_add_test(tc, s21_add_473);
  tcase_add_test(tc, s21_add_474);
  tcase_add_test(tc, s21_add_475);
  tcase_add_test(tc, s21_add_476);
  tcase_add_test(tc, s21_add_477);
  tcase_add_test(tc, s21_add_478);
  tcase_add_test(tc, s21_add_479);
  tcase_add_test(tc, s21_add_480);
  tcase_add_test(tc, s21_add_481);
  tcase_add_test(tc, s21_add_482);
  tcase_add_test(tc, s21_add_483);
  tcase_add_test(tc, s21_add_484);
  tcase_add_test(tc, s21_add_485);
  tcase_add_test(tc, s21_add_486);
  tcase_add_test(tc, s21_add_487);
  tcase_add_test(tc, s21_add_488);
  tcase_add_test(tc, s21_add_490);
  tcase_add_test(tc, s21_add_491);
  tcase_add_test(tc, s21_add_492);
  tcase_add_test(tc, s21_add_493);
  tcase_add_test(tc, s21_add_494);
  tcase_add_test(tc, s21_add_495);
  tcase_add_test(tc, s21_add_496);
  tcase_add_test(tc, s21_add_497);
  tcase_add_test(tc, s21_add_498);
  tcase_add_test(tc, s21_add_499);
  tcase_add_test(tc, s21_add_500);
  tcase_add_test(tc, fail_s21_add_1);
  tcase_add_test(tc, fail_s21_add_2);
  tcase_add_test(tc, fail_s21_add_3);
  tcase_add_test(tc, fail_s21_add_4);
  tcase_add_test(tc, fail_s21_add_5);
  tcase_add_test(tc, fail_s21_add_6);
  tcase_add_test(tc, fail_s21_add_7);
  tcase_add_test(tc, fail_s21_add_8);
  tcase_add_test(tc, fail_s21_add_9);
  tcase_add_test(tc, fail_s21_add_10);
  tcase_add_test(tc, fail_s21_add_11);
  tcase_add_test(tc, fail_s21_add_12);
  tcase_add_test(tc, fail_s21_add_13);
  tcase_add_test(tc, fail_s21_add_14);
  tcase_add_test(tc, fail_s21_add_15);
  tcase_add_test(tc, fail_s21_add_16);
  tcase_add_test(tc, fail_s21_add_17);
  tcase_add_test(tc, fail_s21_add_18);
  tcase_add_test(tc, fail_s21_add_19);
  tcase_add_test(tc, fail_s21_add_20);
  tcase_add_test(tc, fail_s21_add_21);
  tcase_add_test(tc, fail_s21_add_22);
  tcase_add_test(tc, fail_s21_add_23);
  tcase_add_test(tc, fail_s21_add_24);
  tcase_add_test(tc, fail_s21_add_25);
  tcase_add_test(tc, fail_s21_add_26);
  tcase_add_test(tc, fail_s21_add_27);
  tcase_add_test(tc, fail_s21_add_28);
  tcase_add_test(tc, fail_s21_add_29);
  tcase_add_test(tc, fail_s21_add_30);
  tcase_add_test(tc, fail_s21_add_31);
  tcase_add_test(tc, fail_s21_add_32);
  tcase_add_test(tc, fail_s21_add_33);
  tcase_add_test(tc, fail_s21_add_34);
  tcase_add_test(tc, fail_s21_add_35);
  tcase_add_test(tc, fail_s21_add_36);
  tcase_add_test(tc, fail_s21_add_37);
  tcase_add_test(tc, fail_s21_add_38);
  tcase_add_test(tc, fail_s21_add_39);
  tcase_add_test(tc, fail_s21_add_40);
  tcase_add_test(tc, fail_s21_add_41);
  tcase_add_test(tc, fail_s21_add_42);
  tcase_add_test(tc, fail_s21_add_43);
  tcase_add_test(tc, fail_s21_add_44);
  tcase_add_test(tc, fail_s21_add_45);
  tcase_add_test(tc, fail_s21_add_46);
  tcase_add_test(tc, fail_s21_add_47);
  tcase_add_test(tc, fail_s21_add_48);
  tcase_add_test(tc, fail_s21_add_49);
  tcase_add_test(tc, fail_s21_add_50);
  tcase_add_test(tc, fail_s21_add_51);
  tcase_add_test(tc, fail_s21_add_52);
  tcase_add_test(tc, fail_s21_add_53);
  tcase_add_test(tc, fail_s21_add_54);
  tcase_add_test(tc, fail_s21_add_55);
  tcase_add_test(tc, fail_s21_add_56);
  tcase_add_test(tc, fail_s21_add_57);
  tcase_add_test(tc, fail_s21_add_58);
  tcase_add_test(tc, fail_s21_add_59);
  tcase_add_test(tc, fail_s21_add_60);
  tcase_add_test(tc, fail_s21_add_61);
  tcase_add_test(tc, fail_s21_add_62);
  tcase_add_test(tc, fail_s21_add_63);
  tcase_add_test(tc, fail_s21_add_64);
  tcase_add_test(tc, fail_s21_add_65);
  tcase_add_test(tc, fail_s21_add_66);
  tcase_add_test(tc, fail_s21_add_67);
  tcase_add_test(tc, fail_s21_add_68);
  tcase_add_test(tc, fail_s21_add_69);
  tcase_add_test(tc, fail_s21_add_70);
  tcase_add_test(tc, fail_s21_add_71);
  tcase_add_test(tc, fail_s21_add_72);
  tcase_add_test(tc, fail_s21_add_73);
  tcase_add_test(tc, fail_s21_add_74);
  tcase_add_test(tc, fail_s21_add_75);
  tcase_add_test(tc, fail_s21_add_76);
  tcase_add_test(tc, fail_s21_add_77);
  tcase_add_test(tc, fail_s21_add_78);
  tcase_add_test(tc, fail_s21_add_79);
  tcase_add_test(tc, fail_s21_add_80);
  tcase_add_test(tc, fail_s21_add_81);
  tcase_add_test(tc, fail_s21_add_82);
  tcase_add_test(tc, fail_s21_add_83);
  tcase_add_test(tc, fail_s21_add_84);
  tcase_add_test(tc, fail_s21_add_85);
  tcase_add_test(tc, fail_s21_add_86);
  tcase_add_test(tc, fail_s21_add_87);
  tcase_add_test(tc, fail_s21_add_88);
  tcase_add_test(tc, fail_s21_add_89);
  tcase_add_test(tc, fail_s21_add_90);
  tcase_add_test(tc, fail_s21_add_91);
  tcase_add_test(tc, fail_s21_add_92);
  tcase_add_test(tc, fail_s21_add_93);
  tcase_add_test(tc, fail_s21_add_94);
  tcase_add_test(tc, fail_s21_add_95);
  tcase_add_test(tc, fail_s21_add_96);
  tcase_add_test(tc, fail_s21_add_97);
  tcase_add_test(tc, fail_s21_add_98);
  tcase_add_test(tc, fail_s21_add_99);
  tcase_add_test(tc, fail_s21_add_100);
  tcase_add_test(tc, fail_s21_add_101);
  tcase_add_test(tc, fail_s21_add_102);
  tcase_add_test(tc, fail_s21_add_103);
  tcase_add_test(tc, fail_s21_add_104);
  tcase_add_test(tc, fail_s21_add_105);
  tcase_add_test(tc, fail_s21_add_106);
  tcase_add_test(tc, fail_s21_add_107);
  tcase_add_test(tc, fail_s21_add_108);
  tcase_add_test(tc, fail_s21_add_109);
  tcase_add_test(tc, fail_s21_add_110);
  tcase_add_test(tc, fail_s21_add_111);
  tcase_add_test(tc, fail_s21_add_112);
  tcase_add_test(tc, fail_s21_add_113);
  tcase_add_test(tc, fail_s21_add_114);
  tcase_add_test(tc, fail_s21_add_115);
  tcase_add_test(tc, fail_s21_add_116);
  tcase_add_test(tc, fail_s21_add_117);
  tcase_add_test(tc, fail_s21_add_118);
  tcase_add_test(tc, fail_s21_add_119);
  tcase_add_test(tc, fail_s21_add_120);
  tcase_add_test(tc, fail_s21_add_121);
  tcase_add_test(tc, fail_s21_add_122);
  tcase_add_test(tc, fail_s21_add_123);
  tcase_add_test(tc, fail_s21_add_124);
  tcase_add_test(tc, fail_s21_add_125);
  tcase_add_test(tc, fail_s21_add_126);
  tcase_add_test(tc, fail_s21_add_127);
  tcase_add_test(tc, fail_s21_add_128);
  tcase_add_test(tc, fail_s21_add_129);
  tcase_add_test(tc, fail_s21_add_130);
  tcase_add_test(tc, fail_s21_add_131);
  tcase_add_test(tc, fail_s21_add_132);
  tcase_add_test(tc, fail_s21_add_133);
  tcase_add_test(tc, fail_s21_add_134);
  tcase_add_test(tc, fail_s21_add_135);
  tcase_add_test(tc, fail_s21_add_136);
  tcase_add_test(tc, fail_s21_add_137);
  tcase_add_test(tc, fail_s21_add_138);
  tcase_add_test(tc, fail_s21_add_139);
  tcase_add_test(tc, fail_s21_add_140);
  tcase_add_test(tc, fail_s21_add_141);
  tcase_add_test(tc, fail_s21_add_142);
  tcase_add_test(tc, fail_s21_add_143);
  tcase_add_test(tc, fail_s21_add_144);
  tcase_add_test(tc, fail_s21_add_145);
  tcase_add_test(tc, fail_s21_add_146);
  tcase_add_test(tc, fail_s21_add_147);
  tcase_add_test(tc, fail_s21_add_148);
  tcase_add_test(tc, fail_s21_add_149);
  tcase_add_test(tc, fail_s21_add_150);
  tcase_add_test(tc, fail_s21_add_151);
  tcase_add_test(tc, fail_s21_add_152);
  tcase_add_test(tc, fail_s21_add_153);
  tcase_add_test(tc, fail_s21_add_154);
  tcase_add_test(tc, fail_s21_add_155);
  tcase_add_test(tc, fail_s21_add_156);
  tcase_add_test(tc, fail_s21_add_157);
  tcase_add_test(tc, fail_s21_add_158);
  tcase_add_test(tc, fail_s21_add_159);
  tcase_add_test(tc, fail_s21_add_160);
  tcase_add_test(tc, fail_s21_add_161);
  tcase_add_test(tc, fail_s21_add_162);
  tcase_add_test(tc, fail_s21_add_163);
  tcase_add_test(tc, fail_s21_add_164);
  tcase_add_test(tc, fail_s21_add_165);
  tcase_add_test(tc, fail_s21_add_166);

  suite_add_tcase(c, tc);
  return c;
}
