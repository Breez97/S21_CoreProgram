#include "../s21_tests.h"

START_TEST(invalid_dec_s21_sub_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_sub(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 4);
}
END_TEST

START_TEST(invalid_dec_s21_sub_2) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_3) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_4) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_5) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_6) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_7) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_8) {
  // Все биты имеют максимальное значение
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_9) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_10) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_11) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_12) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_13) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_14) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_15) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_sub_16) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_sub(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_sub_1) {
  // 0.4411801883445347138864
  s21_decimal dec_1 = {{0xef3abd30, 0x2a0ce643, 0xef, 0x160000}};
  // 4632.1821190552173180251
  s21_decimal dec_2 = {{0xb854755b, 0x1c67c547, 0x9cf, 0x130000}};
  // -4631.7409388668727833112136
  s21_decimal dec_check = {{0x1aafae48, 0xcb4db9e4, 0x265017, 0x80160000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_2) {
  // 21086715758204745868179
  s21_decimal dec_1 = {{0x1aae393, 0x1cf783e1, 0x477, 0x0}};
  // 5.00340319885
  s21_decimal dec_2 = {{0x7e9b668d, 0x74, 0x0, 0xb0000}};
  // 21086715758204745868173.996597
  s21_decimal dec_check = {{0xceb57235, 0xc81013b1, 0x442285bf, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_3) {
  // -56.4
  s21_decimal dec_1 = {{0x234, 0x0, 0x0, 0x80010000}};
  // 15058387584625382875882136.79
  s21_decimal dec_2 = {{0x198e83af, 0xaab9d2c7, 0x4dd99c2, 0x20000}};
  // -15058387584625382875882193.19
  s21_decimal dec_check = {{0x198e99b7, 0xaab9d2c7, 0x4dd99c2, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_4) {
  // 9595543907
  s21_decimal dec_1 = {{0x3bf06163, 0x2, 0x0, 0x0}};
  // 6753489429.4681
  s21_decimal dec_2 = {{0x31626699, 0x3d6c, 0x0, 0x40000}};
  // 2842054477.5319
  s21_decimal dec_check = {{0x2c79c497, 0x19d9, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_5) {
  // 1179664204168900.041207
  s21_decimal dec_1 = {{0x132ad9f7, 0xf3212790, 0x3f, 0x60000}};
  // 80888985597661694138
  s21_decimal dec_2 = {{0x365048ba, 0x628f67d5, 0x4, 0x0}};
  // -80887805933457525237.958793
  s21_decimal dec_check = {{0x768d4889, 0xbefbf472, 0x42e8a8, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_6) {
  // 62445504099.7808804
  s21_decimal dec_1 = {{0x20e05aa4, 0x8aa828d, 0x0, 0x70000}};
  // 83
  s21_decimal dec_2 = {{0x53, 0x0, 0x0, 0x0}};
  // 62445504016.7808804
  s21_decimal dec_check = {{0xef678f24, 0x8aa828c, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_7) {
  // 3.128
  s21_decimal dec_1 = {{0xc38, 0x0, 0x0, 0x30000}};
  // -253118570624252120421
  s21_decimal dec_2 = {{0x312c0d65, 0xb8b9cee7, 0xd, 0x80000000}};
  // 253118570624252120424.128
  s21_decimal dec_check = {{0x14145ec0, 0x95d03718, 0x3599, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_8) {
  // -0.562
  s21_decimal dec_1 = {{0x232, 0x0, 0x0, 0x80030000}};
  // -0.5378708
  s21_decimal dec_2 = {{0x521294, 0x0, 0x0, 0x80070000}};
  // -0.0241292
  s21_decimal dec_check = {{0x3ae8c, 0x0, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_9) {
  // -2
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -25
  s21_decimal dec_2 = {{0x19, 0x0, 0x0, 0x80000000}};
  // 23
  s21_decimal dec_check = {{0x17, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_10) {
  // 3433791083811963
  s21_decimal dec_1 = {{0xc9c8947b, 0xc3303, 0x0, 0x0}};
  // -8031106101689.2334383373
  s21_decimal dec_2 = {{0x3d5fa10d, 0xabdd08a0, 0x1101, 0x800a0000}};
  // 3441822189913652.2334383373
  s21_decimal dec_check = {{0x9ee62d0d, 0x8c3d0da3, 0x1c7857, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_11) {
  // -56040310495934433851329
  s21_decimal dec_1 = {{0x1ec1f7c1, 0xf389a9c3, 0xbdd, 0x80000000}};
  // 6894523002740204133092823658
  s21_decimal dec_2 = {{0x8bee126a, 0xe41fd3a7, 0x16470408, 0x0}};
  // -6894579043050700067526674987
  s21_decimal dec_check = {{0xaab00a2b, 0xd7a97d6a, 0x16470fe6, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_12) {
  // 602002331637848
  s21_decimal dec_1 = {{0x97219858, 0x22384, 0x0, 0x0}};
  // -0.5561429328900433609717434
  s21_decimal dec_2 = {{0x2bfb76ba, 0xb0227784, 0x499ad, 0x80190000}};
  // 602002331637848.55614293289004
  s21_decimal dec_check = {{0x3638282c, 0x3f6036d, 0xc284773b, 0xe0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_13) {
  // 8698302906941761464970974468
  s21_decimal dec_1 = {{0x51671504, 0x6ea2281b, 0x1c1b1149, 0x0}};
  // 714416509229146968215463103
  s21_decimal dec_2 = {{0xb9ab24bf, 0x917b4b74, 0x24ef394, 0x0}};
  // 7983886397712614496755511365
  s21_decimal dec_check = {{0x97bbf045, 0xdd26dca6, 0x19cc1db4, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_14) {
  // -4317.883261585464900
  s21_decimal dec_1 = {{0x4681e44, 0x3bec33f3, 0x0, 0x800f0000}};
  // -70992695289119152299242549
  s21_decimal dec_2 = {{0x750af435, 0xb92091ca, 0x3ab949, 0x80000000}};
  // 70992695289119152299238231.117
  s21_decimal dec_check = {{0x32880c4d, 0x27397ed9, 0xe563c7fb, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_15) {
  // -0.35
  s21_decimal dec_1 = {{0x23, 0x0, 0x0, 0x80020000}};
  // 129766792167987450364.1422917
  s21_decimal dec_2 = {{0x3c085c45, 0xfe14b50f, 0x43167de, 0x70000}};
  // -129766792167987450364.4922917
  s21_decimal dec_check = {{0x3c3dc425, 0xfe14b50f, 0x43167de, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_16) {
  // 84952434838584.80372
  s21_decimal dec_1 = {{0x57d62cf4, 0x75e52af0, 0x0, 0x50000}};
  // 16890755540
  s21_decimal dec_2 = {{0xeec479d4, 0x3, 0x0, 0x0}};
  // 84935544083044.80372
  s21_decimal dec_check = {{0xcb711074, 0x75df2abb, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_17) {
  // 2
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x0}};
  // 21.2475731828901803460303471
  s21_decimal dec_2 = {{0xce5a9a6f, 0x80a1afb8, 0xafc17c, 0x190000}};
  // -19.2475731828901803460303471
  s21_decimal dec_check = {{0x3a5a9a6f, 0x5479ad28, 0x9f3652, 0x80190000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_18) {
  // 3215712441918033612.39
  s21_decimal dec_1 = {{0xc0d5c7d7, 0x6eb28ed5, 0x11, 0x20000}};
  // 47314562201030204061
  s21_decimal dec_2 = {{0x77879a9d, 0x909f17a3, 0x2, 0x0}};
  // -44098849759112170448.61
  s21_decimal dec_check = {{0xf0229d7d, 0xf72ad04, 0xef, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_19) {
  // -0.114
  s21_decimal dec_1 = {{0x72, 0x0, 0x0, 0x80030000}};
  // -226.8
  s21_decimal dec_2 = {{0x8dc, 0x0, 0x0, 0x80010000}};
  // 226.686
  s21_decimal dec_check = {{0x3757e, 0x0, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_20) {
  // -66785017923897688413769.810645
  s21_decimal dec_1 = {{0xfce7c2d5, 0x20eff319, 0xd7cb45a4, 0x80060000}};
  // -822854238971.3
  s21_decimal dec_2 = {{0xdb589dd1, 0x77b, 0x0, 0x80010000}};
  // -66785017923074834174798.510645
  s21_decimal dec_check = {{0xe518ba35, 0x15849587, 0xd7cb45a4, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_21) {
  // -518
  s21_decimal dec_1 = {{0x206, 0x0, 0x0, 0x80000000}};
  // -969789683472924155
  s21_decimal dec_2 = {{0x363dfdfb, 0xd756294, 0x0, 0x80000000}};
  // 969789683472923637
  s21_decimal dec_check = {{0x363dfbf5, 0xd756294, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_22) {
  // -1312.7537237365932222839882
  s21_decimal dec_1 = {{0x870ffc4a, 0x38382723, 0xadbdd, 0x80160000}};
  // 10
  s21_decimal dec_2 = {{0xa, 0x0, 0x0, 0x0}};
  // -1322.7537237365932222839882
  s21_decimal dec_check = {{0x7d8ffc4a, 0x3b00086e, 0xaf10a, 0x80160000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_23) {
  // -3323344780882859833
  s21_decimal dec_1 = {{0x6aabd739, 0x2e1ee478, 0x0, 0x80000000}};
  // -26057236
  s21_decimal dec_2 = {{0x18d9a14, 0x0, 0x0, 0x80000000}};
  // -3323344780856802597
  s21_decimal dec_check = {{0x691e3d25, 0x2e1ee478, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_24) {
  // -8966560544427953082
  s21_decimal dec_1 = {{0xeba94bba, 0x7c6f9f4e, 0x0, 0x80000000}};
  // 7423471021483603103284661
  s21_decimal dec_2 = {{0x5dd37db5, 0x2ba23434, 0x623fb, 0x0}};
  // -7423479988044147531237743
  s21_decimal dec_check = {{0x497cc96f, 0xa811d383, 0x623fb, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_25) {
  // -18971.934754186
  s21_decimal dec_1 = {{0x3f6e858a, 0x1141, 0x0, 0x80090000}};
  // -4151613056539183
  s21_decimal dec_2 = {{0xbd7ada2f, 0xebfde, 0x0, 0x80000000}};
  // 4151613056520211.065245814
  s21_decimal dec_check = {{0xc6009076, 0x650efc71, 0x36f23, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_26) {
  // 16961440130881922129218983
  s21_decimal dec_1 = {{0xa6884da7, 0x830d23d4, 0xe07b9, 0x0}};
  // 854025717
  s21_decimal dec_2 = {{0x32e765f5, 0x0, 0x0, 0x0}};
  // 16961440130881921275193266
  s21_decimal dec_check = {{0x73a0e7b2, 0x830d23d4, 0xe07b9, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_27) {
  // -1306.6862290078638799530117
  s21_decimal dec_1 = {{0x638b2885, 0x62cf6fe, 0xacf04, 0x80160000}};
  // -4162255846822405638
  s21_decimal dec_2 = {{0xde246606, 0x39c34da3, 0x0, 0x80000000}};
  // 4162255846822404331.3137709921
  s21_decimal dec_check = {{0x676ff361, 0xc85d2f0c, 0x867d5f97, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_28) {
  // 50.99860343576626
  s21_decimal dec_1 = {{0xc42ed832, 0x121e4b, 0x0, 0xe0000}};
  // -12
  s21_decimal dec_2 = {{0xc, 0x0, 0x0, 0x80000000}};
  // 62.99860343576626
  s21_decimal dec_check = {{0x89e9d832, 0x1661b0, 0x0, 0xe0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_29) {
  // 2869.02796894970839438
  s21_decimal dec_1 = {{0x26c8018e, 0x8d937db3, 0xf, 0x110000}};
  // 387269774731668861563
  s21_decimal dec_2 = {{0x76abb27b, 0xfe72a046, 0x14, 0x0}};
  // -387269774731668858693.97203105
  s21_decimal dec_check = {{0x51d7d8a1, 0x829edad8, 0x7d223477, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_30) {
  // 62999987397967
  s21_decimal dec_1 = {{0x53dea54f, 0x394c, 0x0, 0x0}};
  // 43247128849891
  s21_decimal dec_2 = {{0x41c0ade3, 0x2755, 0x0, 0x0}};
  // 19752858548076
  s21_decimal dec_check = {{0x121df76c, 0x11f7, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_31) {
  // -9820829
  s21_decimal dec_1 = {{0x95da9d, 0x0, 0x0, 0x80000000}};
  // 3271728212970564
  s21_decimal dec_2 = {{0x95ef8c44, 0xb9f9e, 0x0, 0x0}};
  // -3271728222791393
  s21_decimal dec_check = {{0x968566e1, 0xb9f9e, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_32) {
  // -4093525431650
  s21_decimal dec_1 = {{0x19211562, 0x3b9, 0x0, 0x80000000}};
  // -80913170649955288156
  s21_decimal dec_2 = {{0x8125c45c, 0x62e55402, 0x4, 0x80000000}};
  // 80913166556429856506
  s21_decimal dec_check = {{0x6804aefa, 0x62e55049, 0x4, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_33) {
  // 533873990042305.6527622
  s21_decimal dec_1 = {{0x189a1106, 0x69e64594, 0x121, 0x70000}};
  // -75383.0791186036
  s21_decimal dec_2 = {{0xe8878674, 0x2ad9a, 0x0, 0x800a0000}};
  // 533873990117688.7318808036
  s21_decimal dec_check = {{0x25a05e4, 0xab82781b, 0x46a85, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_34) {
  // -8425929330.8616949918967
  s21_decimal dec_1 = {{0x79886cf7, 0xb497e751, 0x11d7, 0x800d0000}};
  // 1473.77254452608
  s21_decimal dec_2 = {{0xf0e64d80, 0x8609, 0x0, 0xb0000}};
  // -8425930804.6342395179767
  s21_decimal dec_check = {{0x937eb2f7, 0xb4cc4333, 0x11d7, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_36) {
  // 57263.0617037477201629
  s21_decimal dec_1 = {{0xbf9346dd, 0xad8a044, 0x1f, 0x100000}};
  // -5825545295834087.2
  s21_decimal dec_2 = {{0x9bcfb708, 0xcef706, 0x0, 0x80010000}};
  // 5825545295891350.2617037477202
  s21_decimal dec_check = {{0xb7a09552, 0xdbeb1df3, 0xbc3bc800, 0xd0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_37) {
  // -2919
  s21_decimal dec_1 = {{0xb67, 0x0, 0x0, 0x80000000}};
  // -86240
  s21_decimal dec_2 = {{0x150e0, 0x0, 0x0, 0x80000000}};
  // 83321
  s21_decimal dec_check = {{0x14579, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_38) {
  // 4.39455029706373258
  s21_decimal dec_1 = {{0x6c68388a, 0x6194205, 0x0, 0x110000}};
  // -1484.0
  s21_decimal dec_2 = {{0x39f8, 0x0, 0x0, 0x80010000}};
  // 1488.39455029706373258
  s21_decimal dec_check = {{0xa860388a, 0x118ff7c3, 0x8, 0x110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_39) {
  // -257114869
  s21_decimal dec_1 = {{0xf5342f5, 0x0, 0x0, 0x80000000}};
  // -9283049
  s21_decimal dec_2 = {{0x8da5e9, 0x0, 0x0, 0x80000000}};
  // -247831820
  s21_decimal dec_check = {{0xec59d0c, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_40) {
  // 4843.280
  s21_decimal dec_1 = {{0x49e710, 0x0, 0x0, 0x30000}};
  // 7071739357.6005674
  s21_decimal dec_2 = {{0x438a102a, 0xfb3d18, 0x0, 0x70000}};
  // -7071734514.3205674
  s21_decimal dec_check = {{0xfcb82f2a, 0xfb3d0c, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_41) {
  // 20068401272353
  s21_decimal dec_1 = {{0x89edd621, 0x1240, 0x0, 0x0}};
  // -540023668478884723043
  s21_decimal dec_2 = {{0x433c3963, 0x46557950, 0x1d, 0x80000000}};
  // 540023688547285995396
  s21_decimal dec_check = {{0xcd2a0f84, 0x46558b90, 0x1d, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_42) {
  // 4196605820324
  s21_decimal dec_1 = {{0x1932fda4, 0x3d1, 0x0, 0x0}};
  // -3.27553056
  s21_decimal dec_2 = {{0x13861020, 0x0, 0x0, 0x80080000}};
  // 4196605820327.27553056
  s21_decimal dec_check = {{0xd6673420, 0xbff5e3e6, 0x16, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_43) {
  // 39820804751877592240095
  s21_decimal dec_1 = {{0xbae6cfdf, 0xb0adbe2a, 0x86e, 0x0}};
  // 663.43976604498
  s21_decimal dec_2 = {{0xe9289352, 0x3c56, 0x0, 0xb0000}};
  // 39820804751877592239431.560234
  s21_decimal dec_check = {{0x41d12c2a, 0x1af78264, 0x80aaff67, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_44) {
  // -141372375411813344150696
  s21_decimal dec_1 = {{0xfe4d04a8, 0xcfd3ee18, 0x1def, 0x80000000}};
  // -380786.3660238731462986457646
  s21_decimal dec_2 = {{0x7a34622e, 0xa5e17c02, 0xc4dca7e, 0x80160000}};
  // -141372375411813343769909.63398
  s21_decimal dec_check = {{0x6790f6c6, 0xc12ee2ff, 0x2dae0c7e, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_45) {
  // 41076798902208467254
  s21_decimal dec_1 = {{0xa44a9136, 0x3a0e1af7, 0x2, 0x0}};
  // 8934916
  s21_decimal dec_2 = {{0x885604, 0x0, 0x0, 0x0}};
  // 41076798902199532338
  s21_decimal dec_check = {{0xa3c23b32, 0x3a0e1af7, 0x2, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_46) {
  // -9696116721614600893
  s21_decimal dec_1 = {{0x3c903abd, 0x868f86c9, 0x0, 0x80000000}};
  // 117812836531845
  s21_decimal dec_2 = {{0x70457e85, 0x6b26, 0x0, 0x0}};
  // -9696234534451132738
  s21_decimal dec_check = {{0xacd5b942, 0x868ff1ef, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_47) {
  // 1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  // 901525611934891280807722
  s21_decimal dec_2 = {{0x6da9b72a, 0xcd254f61, 0xbee7, 0x0}};
  // -901525611934891280807721
  s21_decimal dec_check = {{0x6da9b729, 0xcd254f61, 0xbee7, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_48) {
  // -0.5
  s21_decimal dec_1 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 92741838.172
  s21_decimal dec_2 = {{0x97d8255c, 0x15, 0x0, 0x30000}};
  // -92741838.672
  s21_decimal dec_check = {{0x97d82750, 0x15, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_49) {
  // -37111052
  s21_decimal dec_1 = {{0x236450c, 0x0, 0x0, 0x80000000}};
  // -3693055
  s21_decimal dec_2 = {{0x3859ff, 0x0, 0x0, 0x80000000}};
  // -33417997
  s21_decimal dec_check = {{0x1fdeb0d, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_50) {
  // -4988.7633
  s21_decimal dec_1 = {{0x2f93991, 0x0, 0x0, 0x80040000}};
  // 7072.9
  s21_decimal dec_2 = {{0x11449, 0x0, 0x0, 0x10000}};
  // -12061.6633
  s21_decimal dec_check = {{0x73076b9, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_51) {
  // -911878725798493438247095
  s21_decimal dec_1 = {{0xb83e80b7, 0xb768d2d, 0xc119, 0x80000000}};
  // -8
  s21_decimal dec_2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -911878725798493438247087
  s21_decimal dec_check = {{0xb83e80af, 0xb768d2d, 0xc119, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_52) {
  // -197355987205741484752
  s21_decimal dec_1 = {{0xec21ad0, 0xb2dd50ba, 0xa, 0x80000000}};
  // -782876244103333133287053.8
  s21_decimal dec_2 = {{0x1c5bf18a, 0xff456b6, 0x679ce, 0x80010000}};
  // 782678888116127391802301.8
  s21_decimal dec_check = {{0x88c6e56a, 0x134f2f71, 0x67963, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_53) {
  // -57698535467182279483735
  s21_decimal dec_1 = {{0xacede157, 0xd8083375, 0xc37, 0x80000000}};
  // 49838541299696969369084702589
  s21_decimal dec_2 = {{0x378b2f7d, 0x88311e74, 0xa10979a1, 0x0}};
  // -49838598998232436551364186324
  s21_decimal dec_check = {{0xe47910d4, 0x603951e9, 0xa10985d9, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_55) {
  // 73931027755205072239
  s21_decimal dec_1 = {{0x3c8b156f, 0x1ffc60a, 0x4, 0x0}};
  // 762622544692596
  s21_decimal dec_2 = {{0xe5dfc574, 0x2b599, 0x0, 0x0}};
  // 73930265132660379643
  s21_decimal dec_check = {{0x56ab4ffb, 0x1fd1070, 0x4, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_56) {
  // 750458
  s21_decimal dec_1 = {{0xb737a, 0x0, 0x0, 0x0}};
  // -943428070318
  s21_decimal dec_2 = {{0xa8b1ebae, 0xdb, 0x0, 0x80000000}};
  // 943428820776
  s21_decimal dec_check = {{0xa8bd5f28, 0xdb, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_57) {
  // -62852429960507792904092953028
  s21_decimal dec_1 = {{0x810ca9c4, 0x757276da, 0xcb164fbf, 0x80000000}};
  // -4.636668
  s21_decimal dec_2 = {{0x46bffc, 0x0, 0x0, 0x80060000}};
  // -62852429960507792904092953023
  s21_decimal dec_check = {{0x810ca9bf, 0x757276da, 0xcb164fbf, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_59) {
  // 74980.95881
  s21_decimal dec_1 = {{0xbeebdd09, 0x1, 0x0, 0x50000}};
  // -57
  s21_decimal dec_2 = {{0x39, 0x0, 0x0, 0x80000000}};
  // 75037.95881
  s21_decimal dec_check = {{0xbf42d6a9, 0x1, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_60) {
  // 1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  // -97286.9
  s21_decimal dec_2 = {{0xed845, 0x0, 0x0, 0x80010000}};
  // 97287.9
  s21_decimal dec_check = {{0xed84f, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_61) {
  // 4.5509
  s21_decimal dec_1 = {{0xb1c5, 0x0, 0x0, 0x40000}};
  // -98832684267
  s21_decimal dec_2 = {{0x2e314eb, 0x17, 0x0, 0x80000000}};
  // 98832684271.5509
  s21_decimal dec_check = {{0xc661cd75, 0x382e0, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_62) {
  // 3256
  s21_decimal dec_1 = {{0xcb8, 0x0, 0x0, 0x0}};
  // -0.2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x80010000}};
  // 3256.2
  s21_decimal dec_check = {{0x7f32, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_63) {
  // -282289074769694038198
  s21_decimal dec_1 = {{0x154c18b6, 0x4d8c41df, 0xf, 0x80000000}};
  // -63721.086
  s21_decimal dec_2 = {{0x3cc4e7e, 0x0, 0x0, 0x80030000}};
  // -282289074769693974476.914
  s21_decimal dec_check = {{0x2d743872, 0xebe14f6b, 0x3bc6, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_64) {
  // 875111
  s21_decimal dec_1 = {{0xd5a67, 0x0, 0x0, 0x0}};
  // -9.3
  s21_decimal dec_2 = {{0x5d, 0x0, 0x0, 0x80010000}};
  // 875120.3
  s21_decimal dec_check = {{0x858863, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_65) {
  // 362412347753134
  s21_decimal dec_1 = {{0xb34002ae, 0x1499c, 0x0, 0x0}};
  // -446954430438474533383
  s21_decimal dec_2 = {{0xf0504a07, 0x3abd1e6a, 0x18, 0x80000000}};
  // 446954792850822286517
  s21_decimal dec_check = {{0xa3904cb5, 0x3abe6807, 0x18, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_66) {
  // 882.099449396632
  s21_decimal dec_1 = {{0xc8567d98, 0x32243, 0x0, 0xc0000}};
  // -20259945451765345864099280740
  s21_decimal dec_2 = {{0xdcbfb764, 0xa97ebd18, 0x4176a253, 0x80000000}};
  // 20259945451765345864099281622
  s21_decimal dec_check = {{0xdcbfbad6, 0xa97ebd18, 0x4176a253, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_67) {
  // -6902865258905539445495
  s21_decimal dec_1 = {{0xe98402f7, 0x347fd406, 0x176, 0x80000000}};
  // 990904143897
  s21_decimal dec_2 = {{0xb67d5019, 0xe6, 0x0, 0x0}};
  // -6902865259896443589392
  s21_decimal dec_check = {{0xa0015310, 0x347fd4ed, 0x176, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_68) {
  // -65971037497395298225386568
  s21_decimal dec_1 = {{0xeb007448, 0x1bd9a833, 0x3691e9, 0x80000000}};
  // 887183082328.186683146079757
  s21_decimal dec_2 = {{0x46578e0d, 0x433bbd63, 0x2dddc53, 0xf0000}};
  // -65971037497396185408468896.187
  s21_decimal dec_check = {{0x623f49bb, 0xca3c31b1, 0xd529f694, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_69) {
  // 7365842902984239060803
  s21_decimal dec_1 = {{0x1ba39743, 0x4d9ad65b, 0x18f, 0x0}};
  // -9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x80000000}};
  // 7365842902984239060812
  s21_decimal dec_check = {{0x1ba3974c, 0x4d9ad65b, 0x18f, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_70) {
  // -21.1383867177
  s21_decimal dec_1 = {{0x3775d729, 0x31, 0x0, 0x800a0000}};
  // -65978878891
  s21_decimal dec_2 = {{0x5ca5cbab, 0xf, 0x0, 0x80000000}};
  // 65978878869.8616132823
  s21_decimal dec_check = {{0x4e4774d7, 0xc468a79c, 0x23, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_71) {
  // -469949292785117360149
  s21_decimal dec_1 = {{0xd6f6f015, 0x79db47e3, 0x19, 0x80000000}};
  // -5058637596510787
  s21_decimal dec_2 = {{0xd8fcca43, 0x11f8cd, 0x0, 0x80000000}};
  // -469944234147520849362
  s21_decimal dec_check = {{0xfdfa25d2, 0x79c94f15, 0x19, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_72) {
  // -35681.59938986772306
  s21_decimal dec_1 = {{0x41160752, 0x3184a68f, 0x0, 0x800e0000}};
  // -455996
  s21_decimal dec_2 = {{0x6f53c, 0x0, 0x0, 0x80000000}};
  // 420314.40061013227694
  s21_decimal dec_check = {{0x1ad0f8ae, 0x474dac0b, 0x2, 0xe0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_73) {
  // -1986.29
  s21_decimal dec_1 = {{0x307e5, 0x0, 0x0, 0x80020000}};
  // -90875
  s21_decimal dec_2 = {{0x162fb, 0x0, 0x0, 0x80000000}};
  // 88888.71
  s21_decimal dec_check = {{0x87a227, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_74) {
  // -564393
  s21_decimal dec_1 = {{0x89ca9, 0x0, 0x0, 0x80000000}};
  // -1762662410172832082340
  s21_decimal dec_2 = {{0x58ae9a4, 0x8ddadb11, 0x5f, 0x80000000}};
  // 1762662410172831517947
  s21_decimal dec_check = {{0x5824cfb, 0x8ddadb11, 0x5f, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_75) {
  // 756954601059
  s21_decimal dec_1 = {{0x3e029663, 0xb0, 0x0, 0x0}};
  // -1453435155714.042455292
  s21_decimal dec_2 = {{0x100f64fc, 0xca76f57e, 0x4e, 0x80090000}};
  // 2210389756773.042455292
  s21_decimal dec_check = {{0x634782fc, 0xd351eca3, 0x77, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_76) {
  // 436279611283550
  s21_decimal dec_1 = {{0x4340d85e, 0x18ccb, 0x0, 0x0}};
  // 597831522.732
  s21_decimal dec_2 = {{0x318919ac, 0x8b, 0x0, 0x30000}};
  // 436279013452027.268
  s21_decimal dec_check = {{0x83c41584, 0x60df973, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_77) {
  // -2100
  s21_decimal dec_1 = {{0x834, 0x0, 0x0, 0x80000000}};
  // -2612823163
  s21_decimal dec_2 = {{0x9bbc847b, 0x0, 0x0, 0x80000000}};
  // 2612821063
  s21_decimal dec_check = {{0x9bbc7c47, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_78) {
  // -6458767673466528
  s21_decimal dec_1 = {{0x8dd1ea0, 0x16f237, 0x0, 0x80000000}};
  // 4023910
  s21_decimal dec_2 = {{0x3d6666, 0x0, 0x0, 0x0}};
  // -6458767677490438
  s21_decimal dec_check = {{0x91a8506, 0x16f237, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_79) {
  // -0.32484669
  s21_decimal dec_1 = {{0x1efad3d, 0x0, 0x0, 0x80080000}};
  // 167237298
  s21_decimal dec_2 = {{0x9f7d6b2, 0x0, 0x0, 0x0}};
  // -167237298.32484669
  s21_decimal dec_check = {{0xc7fc1f3d, 0x3b6a24, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_80) {
  // -916981296494.852
  s21_decimal dec_1 = {{0x58717904, 0x341fd, 0x0, 0x80030000}};
  // 36079920
  s21_decimal dec_2 = {{0x2268930, 0x0, 0x0, 0x0}};
  // -917017376414.852
  s21_decimal dec_check = {{0xbef95c84, 0x34205, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_81) {
  // 26647849020441335022736878
  s21_decimal dec_1 = {{0x53c7d5ee, 0xca3d884f, 0x160ae6, 0x0}};
  // 19216663
  s21_decimal dec_2 = {{0x1253917, 0x0, 0x0, 0x0}};
  // 26647849020441335003520215
  s21_decimal dec_check = {{0x52a29cd7, 0xca3d884f, 0x160ae6, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_82) {
  // 8696148547
  s21_decimal dec_1 = {{0x654b243, 0x2, 0x0, 0x0}};
  // -440577259.8
  s21_decimal dec_2 = {{0x69ac136, 0x1, 0x0, 0x80010000}};
  // 9136725806.8
  s21_decimal dec_check = {{0x45e9b7d4, 0x15, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_83) {
  // 450001312902931780.55584456
  s21_decimal dec_1 = {{0x73e4eac8, 0x15ed7cf, 0x253926, 0x80000}};
  // 355828928997.80255
  s21_decimal dec_2 = {{0xdb5f469f, 0x7e6a73, 0x0, 0x50000}};
  // 450000957074002782.75329456
  s21_decimal dec_check = {{0x87b90db0, 0x138f033e, 0x253924, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_84) {
  // 25042312481197727
  s21_decimal dec_1 = {{0xbbcbce9f, 0x58f7d9, 0x0, 0x0}};
  // -38363930641.454483
  s21_decimal dec_2 = {{0xaa125593, 0x884bca, 0x0, 0x80060000}};
  // 25042350845128368.454483
  s21_decimal dec_check = {{0x439bfb53, 0x8c6e6595, 0x54d, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_85) {
  // 5098299.728
  s21_decimal dec_1 = {{0x2fe1e150, 0x1, 0x0, 0x30000}};
  // 7146.835
  s21_decimal dec_2 = {{0x6d0d53, 0x0, 0x0, 0x30000}};
  // 5091152.893
  s21_decimal dec_check = {{0x2f74d3fd, 0x1, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_86) {
  // 27373659578.75365898
  s21_decimal dec_1 = {{0xe368780a, 0x25fd13d5, 0x0, 0x80000}};
  // -20.064
  s21_decimal dec_2 = {{0x4e60, 0x0, 0x0, 0x80030000}};
  // 27373659598.81765898
  s21_decimal dec_check = {{0x5affb40a, 0x25fd13d6, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_87) {
  // 7162612554846319903
  s21_decimal dec_1 = {{0x635e351f, 0x6366b62b, 0x0, 0x0}};
  // -419070718683611479987472568
  s21_decimal dec_2 = {{0xc24048b8, 0x2e5c05ed, 0x15aa5ad, 0x80000000}};
  // 419070725846224034833792471
  s21_decimal dec_check = {{0x259e7dd7, 0x91c2bc19, 0x15aa5ad, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_88) {
  // -248216183397.49
  s21_decimal dec_1 = {{0x3bbe6fa5, 0x1693, 0x0, 0x80020000}};
  // 170035385.87
  s21_decimal dec_2 = {{0xf57d689b, 0x3, 0x0, 0x20000}};
  // -248386218783.36
  s21_decimal dec_check = {{0x313bd840, 0x1697, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_89) {
  // -6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x80000000}};
  // 8276208454764463841980023
  s21_decimal dec_2 = {{0xe185ae77, 0x28c9d897, 0x6d88e, 0x0}};
  // -8276208454764463841980029
  s21_decimal dec_check = {{0xe185ae7d, 0x28c9d897, 0x6d88e, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_90) {
  // -57382478817744783.6
  s21_decimal dec_1 = {{0xc6a16b9c, 0x7f6a29a, 0x0, 0x80010000}};
  // -9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x80000000}};
  // -57382478817744774.6
  s21_decimal dec_check = {{0xc6a16b42, 0x7f6a29a, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_91) {
  // -41.07763967776
  s21_decimal dec_1 = {{0x69cfe720, 0x3bc, 0x0, 0x800b0000}};
  // 327677346747.7
  s21_decimal dec_2 = {{0xeeeb2555, 0x2fa, 0x0, 0x10000}};
  // -327677346788.77763967776
  s21_decimal dec_check = {{0x55b69b20, 0x57ab378a, 0x6f0, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_92) {
  // -0.3498
  s21_decimal dec_1 = {{0xdaa, 0x0, 0x0, 0x80040000}};
  // 6289394194324501468952985190
  s21_decimal dec_2 = {{0x8f10fe66, 0x74891cbb, 0x14527706, 0x0}};
  // -6289394194324501468952985190.3
  s21_decimal dec_check = {{0x96a9efff, 0x8d5b1f53, 0xcb38a640, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_93) {
  // -0.8016621719
  s21_decimal dec_1 = {{0xddd3f097, 0x1, 0x0, 0x800a0000}};
  // 6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x0}};
  // -6.8016621719
  s21_decimal dec_check = {{0xd61b4897, 0xf, 0x0, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_94) {
  // -86.4
  s21_decimal dec_1 = {{0x360, 0x0, 0x0, 0x80010000}};
  // 235295256891
  s21_decimal dec_2 = {{0xc8b0b13b, 0x36, 0x0, 0x0}};
  // -235295256977.4
  s21_decimal dec_check = {{0xd6e6efae, 0x223, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_95) {
  // 43
  s21_decimal dec_1 = {{0x2b, 0x0, 0x0, 0x0}};
  // -145
  s21_decimal dec_2 = {{0x91, 0x0, 0x0, 0x80000000}};
  // 188
  s21_decimal dec_check = {{0xbc, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_96) {
  // -42.6020679251
  s21_decimal dec_1 = {{0x30cfae53, 0x63, 0x0, 0x800a0000}};
  // 94608194.6318
  s21_decimal dec_2 = {{0x46e0dace, 0xdc, 0x0, 0x40000}};
  // -94608237.2338679251
  s21_decimal dec_check = {{0xb3817dd3, 0xd2128e7, 0x0, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_97) {
  // 73.40
  s21_decimal dec_1 = {{0x1cac, 0x0, 0x0, 0x20000}};
  // 5954.95002411207
  s21_decimal dec_2 = {{0x7c1590c7, 0x21d99, 0x0, 0xb0000}};
  // -5881.55002411207
  s21_decimal dec_check = {{0x81fdd8c7, 0x216ec, 0x0, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_99) {
  // -156038886.801865
  s21_decimal dec_1 = {{0xa26b41c9, 0x8dea, 0x0, 0x80060000}};
  // 6.41074125
  s21_decimal dec_2 = {{0x263603cd, 0x0, 0x0, 0x80000}};
  // -156038893.21260625
  s21_decimal dec_check = {{0x981bb651, 0x376fa7, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_100) {
  // 235713083364967994638
  s21_decimal dec_1 = {{0x80f4550e, 0xc72d1875, 0xc, 0x0}};
  // 3524.90293
  s21_decimal dec_2 = {{0x15029335, 0x0, 0x0, 0x50000}};
  // 235713083364967991113.09707
  s21_decimal dec_check = {{0xbd45e98b, 0x2f724be4, 0x137f6b, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_101) {
  // 103580961081.825
  s21_decimal dec_1 = {{0xd26409e1, 0x5e34, 0x0, 0x30000}};
  // 6.9051
  s21_decimal dec_2 = {{0x10dbb, 0x0, 0x0, 0x40000}};
  // 103580961074.9199
  s21_decimal dec_check = {{0x37e7550f, 0x3ae10, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_102) {
  // 809063384128793.3
  s21_decimal dec_1 = {{0x7c1e22fd, 0x1cbe63, 0x0, 0x10000}};
  // -7853037931697381417446999
  s21_decimal dec_2 = {{0x65206e57, 0xa10149a, 0x67ef2, 0x80000000}};
  // 7853037932506444801575792.3
  s21_decimal dec_check = {{0x6f627263, 0x64bd8c6b, 0x40f574, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_103) {
  // -65.89
  s21_decimal dec_1 = {{0x19bd, 0x0, 0x0, 0x80020000}};
  // -4907747.6
  s21_decimal dec_2 = {{0x2ecdce4, 0x0, 0x0, 0x80010000}};
  // 4907681.71
  s21_decimal dec_check = {{0x1d40872b, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_104) {
  // 51614390
  s21_decimal dec_1 = {{0x31392b6, 0x0, 0x0, 0x0}};
  // -87
  s21_decimal dec_2 = {{0x57, 0x0, 0x0, 0x80000000}};
  // 51614477
  s21_decimal dec_check = {{0x313930d, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_105) {
  // 586011884321
  s21_decimal dec_1 = {{0x7107bb21, 0x88, 0x0, 0x0}};
  // -502015256
  s21_decimal dec_2 = {{0x1dec2518, 0x0, 0x0, 0x80000000}};
  // 586513899577
  s21_decimal dec_check = {{0x8ef3e039, 0x88, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_106) {
  // -97894632013138384
  s21_decimal dec_1 = {{0x2e8f89d0, 0x15bcaa6, 0x0, 0x80000000}};
  // -80890930791.5494726484
  s21_decimal dec_2 = {{0x92239b54, 0xd9df29c3, 0x2b, 0x800a0000}};
  // -97894551122207592.4505273516
  s21_decimal dec_check = {{0x7089a4ac, 0x802704b7, 0x329c3c6, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_107) {
  // -1699810301586841877123193710
  s21_decimal dec_1 = {{0xb3145b6e, 0x16f593f5, 0x57e0cd5, 0x80000000}};
  // 49.0126783162659
  s21_decimal dec_2 = {{0x88ce2923, 0x1bdc4, 0x0, 0xd0000}};
  // -1699810301586841877123193759.0
  s21_decimal dec_check = {{0xfecb9436, 0xe597c798, 0x36ec8052, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_108) {
  // 3752313002793.2550
  s21_decimal dec_1 = {{0x842cfb86, 0x854f16, 0x0, 0x40000}};
  // -2080120993094169786078792
  s21_decimal dec_2 = {{0xd7c5648, 0x95c1b9ca, 0x1b87b, 0x80000000}};
  // 2080120993097922099081585.2550
  s21_decimal dec_check = {{0x4d175806, 0xdfeeb3c5, 0x43365b89, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_109) {
  // -660214
  s21_decimal dec_1 = {{0xa12f6, 0x0, 0x0, 0x80000000}};
  // -480049489979665971320713402
  s21_decimal dec_2 = {{0xe5bff0ba, 0xff2ff69a, 0x18d166e, 0x80000000}};
  // 480049489979665971320053188
  s21_decimal dec_check = {{0xe5b5ddc4, 0xff2ff69a, 0x18d166e, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_110) {
  // 66606664659449271267929808
  s21_decimal dec_1 = {{0xf570aed0, 0x86bae740, 0x371882, 0x0}};
  // 621421
  s21_decimal dec_2 = {{0x97b6d, 0x0, 0x0, 0x0}};
  // 66606664659449271267308387
  s21_decimal dec_check = {{0xf5673363, 0x86bae740, 0x371882, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_111) {
  // -618215.978376173
  s21_decimal dec_1 = {{0x9fc91bed, 0x23243, 0x0, 0x80090000}};
  // 2363390343487952296622
  s21_decimal dec_2 = {{0xa3d49aae, 0x1ea1339f, 0x80, 0x0}};
  // -2363390343487952914837.9783762
  s21_decimal dec_check = {{0xb9af6252, 0x6ba2a5ab, 0x4c5d81b8, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_112) {
  // -9.10
  s21_decimal dec_1 = {{0x38e, 0x0, 0x0, 0x80020000}};
  // 97905311
  s21_decimal dec_2 = {{0x5d5ea9f, 0x0, 0x0, 0x0}};
  // -97905320.10
  s21_decimal dec_check = {{0x478fa9aa, 0x2, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_113) {
  // 6.08
  s21_decimal dec_1 = {{0x260, 0x0, 0x0, 0x20000}};
  // -61.09180466703
  s21_decimal dec_2 = {{0x6788160f, 0x58e, 0x0, 0x800b0000}};
  // 67.17180466703
  s21_decimal dec_check = {{0xf727d60f, 0x61b, 0x0, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_114) {
  // 472819096046177669596284
  s21_decimal dec_1 = {{0x59f3c47c, 0x93161f10, 0x641f, 0x0}};
  // 0.93
  s21_decimal dec_2 = {{0x5d, 0x0, 0x0, 0x20000}};
  // 472819096046177669596283.07
  s21_decimal dec_check = {{0x2338c013, 0x74a42263, 0x271c55, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_115) {
  // -0.167682029188
  s21_decimal dec_1 = {{0xaa0b684, 0x27, 0x0, 0x800c0000}};
  // 0.34340
  s21_decimal dec_2 = {{0x8624, 0x0, 0x0, 0x50000}};
  // -0.511082029188
  s21_decimal dec_check = {{0xfedce084, 0x76, 0x0, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_116) {
  // 8293.53386
  s21_decimal dec_1 = {{0x316eedaa, 0x0, 0x0, 0x50000}};
  // -74606510906732578
  s21_decimal dec_2 = {{0xf486f022, 0x1090e39, 0x0, 0x80000000}};
  // 74606510906740871.53386
  s21_decimal dec_check = {{0x9798ceea, 0x71552ebe, 0x194, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_117) {
  // 392272682707978.2988294
  s21_decimal dec_1 = {{0x49a17a06, 0xa6c541bb, 0xd4, 0x70000}};
  // 2891238067653075170
  s21_decimal dec_2 = {{0x3f8c60e2, 0x281fbdb4, 0x0, 0x0}};
  // -2890845794970367191.7011706
  s21_decimal dec_check = {{0x438362fa, 0xa546f0fa, 0x17e99a, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_118) {
  // 4245602504.797980445598278
  s21_decimal dec_1 = {{0xe8136246, 0x92ad8ba2, 0x3830a, 0xf0000}};
  // -4975134589307885217993095
  s21_decimal dec_2 = {{0x3f795187, 0x96254ec1, 0x41d86, 0x80000000}};
  // 4975134589307889463595599.7980
  s21_decimal dec_check = {{0x834b4d1c, 0x1154835c, 0xa0c15949, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_119) {
  // -11316276090783
  s21_decimal dec_1 = {{0xc69dd79f, 0xa4a, 0x0, 0x80000000}};
  // -634068655629724391
  s21_decimal dec_2 = {{0x3604eae7, 0x8ccaa15, 0x0, 0x80000000}};
  // 634057339353633608
  s21_decimal dec_check = {{0x6f671348, 0x8cc9fca, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_120) {
  // -45052890424126967
  s21_decimal dec_1 = {{0x79d5adf7, 0xa00f5d, 0x0, 0x80000000}};
  // -740.4578
  s21_decimal dec_2 = {{0x70fc22, 0x0, 0x0, 0x80040000}};
  // -45052890424126226.5422
  s21_decimal dec_check = {{0x2a6a844e, 0x6c583367, 0x18, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_121) {
  // -54894427658185779
  s21_decimal dec_1 = {{0xecb6ec33, 0xc30630, 0x0, 0x80000000}};
  // -46662248388.395689631261503
  s21_decimal dec_2 = {{0x3163a33f, 0x8dc50a3d, 0x26991d, 0x800f0000}};
  // -54894380995937390.604310368738
  s21_decimal dec_check = {{0xfee151e2, 0xa6f10874, 0xb15f9154, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_122) {
  // 9
  s21_decimal dec_1 = {{0x9, 0x0, 0x0, 0x0}};
  // 60
  s21_decimal dec_2 = {{0x3c, 0x0, 0x0, 0x0}};
  // -51
  s21_decimal dec_check = {{0x33, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_123) {
  // -931855003211044.8563450291558
  s21_decimal dec_1 = {{0x7ca82566, 0x7621a345, 0x1e1c1fb9, 0x800d0000}};
  // 992229738520683
  s21_decimal dec_2 = {{0x7d19a06b, 0x3866d, 0x0, 0x0}};
  // -1924084741731727.8563450291558
  s21_decimal dec_check = {{0x8a910566, 0x841062c7, 0x3e2ba7ec, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_124) {
  // -152375283.073536985013
  s21_decimal dec_1 = {{0xf3c387b5, 0x42a1c0a2, 0x8, 0x800c0000}};
  // 858.2169
  s21_decimal dec_2 = {{0x82f419, 0x0, 0x0, 0x40000}};
  // -152376141.290436985013
  s21_decimal dec_check = {{0x253a80b5, 0x42a4cd2e, 0x8, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_125) {
  // -78884373030649878
  s21_decimal dec_1 = {{0x58d24016, 0x11840eb, 0x0, 0x80000000}};
  // 828.0924
  s21_decimal dec_2 = {{0x7e5b5c, 0x0, 0x0, 0x40000}};
  // -78884373030650706.0924
  s21_decimal dec_check = {{0x9565b6bc, 0xc367e93d, 0x2a, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_126) {
  // -24178224651204540983212852656
  s21_decimal dec_1 = {{0xefb545b0, 0xaf15d7dd, 0x4e1fc238, 0x80000000}};
  // -7014918048459728819399
  s21_decimal dec_2 = {{0x69314c7, 0x478b4e72, 0x17c, 0x80000000}};
  // -24178217636286492523484033257
  s21_decimal dec_check = {{0xe92230e9, 0x678a896b, 0x4e1fc0bc, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_128) {
  // 565
  s21_decimal dec_1 = {{0x235, 0x0, 0x0, 0x0}};
  // 3771.78
  s21_decimal dec_2 = {{0x5c15a, 0x0, 0x0, 0x20000}};
  // -3206.78
  s21_decimal dec_check = {{0x4e4a6, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_129) {
  // 1120181984705.387
  s21_decimal dec_1 = {{0xb1483b6b, 0x3facc, 0x0, 0x30000}};
  // 41
  s21_decimal dec_2 = {{0x29, 0x0, 0x0, 0x0}};
  // 1120181984664.387
  s21_decimal dec_check = {{0xb1479b43, 0x3facc, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_130) {
  // -59235252046091
  s21_decimal dec_1 = {{0xc828090b, 0x35df, 0x0, 0x80000000}};
  // 0.944305
  s21_decimal dec_2 = {{0xe68b1, 0x0, 0x0, 0x60000}};
  // -59235252046091.944305
  s21_decimal dec_check = {{0xe40a8171, 0x360de3e4, 0x3, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_131) {
  // -47610.8045
  s21_decimal dec_1 = {{0x1c60d50d, 0x0, 0x0, 0x80040000}};
  // -32504361009595746697644
  s21_decimal dec_2 = {{0xebdd41ac, 0x109ffabd, 0x6e2, 0x80000000}};
  // 32504361009595746650033.1955
  s21_decimal dec_check = {{0x567479b3, 0x69329acd, 0x10cdea9, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_132) {
  // -250817
  s21_decimal dec_1 = {{0x3d3c1, 0x0, 0x0, 0x80000000}};
  // 7063084485125123964
  s21_decimal dec_2 = {{0xda74af7c, 0x62051dea, 0x0, 0x0}};
  // -7063084485125374781
  s21_decimal dec_check = {{0xda78833d, 0x62051dea, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_133) {
  // -0.31460255611901
  s21_decimal dec_1 = {{0xe95c3bfd, 0x1c9c, 0x0, 0x800e0000}};
  // 669
  s21_decimal dec_2 = {{0x29d, 0x0, 0x0, 0x0}};
  // -669.31460255611901
  s21_decimal dec_check = {{0xf8d57bfd, 0xedc9ce, 0x0, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_134) {
  // 8679.257
  s21_decimal dec_1 = {{0x846f59, 0x0, 0x0, 0x30000}};
  // 24277.132250745
  s21_decimal dec_2 = {{0x75d80e79, 0x1614, 0x0, 0x90000}};
  // -15597.875250745
  s21_decimal dec_check = {{0xa9d04639, 0xe2f, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_135) {
  // -26053957159886
  s21_decimal dec_1 = {{0x28dc8bce, 0x17b2, 0x0, 0x80000000}};
  // -1364136247434826480166188.0
  s21_decimal dec_2 = {{0x1e5b73b8, 0xbdd417ca, 0xb48ab, 0x80010000}};
  // 1364136247408772523006302.0
  s21_decimal dec_check = {{0x85bdfdac, 0xbdd32ad4, 0xb48ab, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_136) {
  // -69427340038394
  s21_decimal dec_1 = {{0xcff0d0fa, 0x3f24, 0x0, 0x80000000}};
  // 283613508638802.8712
  s21_decimal dec_2 = {{0xa72e2528, 0x275bf9d5, 0x0, 0x40000}};
  // -353040848677196.8712
  s21_decimal dec_check = {{0x56114ac8, 0x30fe87d0, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_137) {
  // -33732192192880290845884
  s21_decimal dec_1 = {{0x5aa854bc, 0xa0349e9c, 0x724, 0x80000000}};
  // -4585824.16165944882851495339
  s21_decimal dec_2 = {{0xee83dab, 0x97f222e8, 0x17b549a, 0x80140000}};
  // -33732192192880286260059.838341
  s21_decimal dec_check = {{0x4e861785, 0xe9354227, 0x6cfe9d8a, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_138) {
  // -272159.328235140255
  s21_decimal dec_1 = {{0x91c3b49f, 0x3c6e777, 0x0, 0x800c0000}};
  // -0.77231
  s21_decimal dec_2 = {{0x12daf, 0x0, 0x0, 0x80050000}};
  // -272158.555925140255
  s21_decimal dec_check = {{0xc080531f, 0x3c6e6c3, 0x0, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_139) {
  // -63668185894792813
  s21_decimal dec_1 = {{0xb3c0ae6d, 0xe231e0, 0x0, 0x80000000}};
  // -584761006914128314
  s21_decimal dec_2 = {{0x9f9dc9ba, 0x81d7d09, 0x0, 0x80000000}};
  // 521092821019335501
  s21_decimal dec_check = {{0xebdd1b4d, 0x73b4b28, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_140) {
  // -125
  s21_decimal dec_1 = {{0x7d, 0x0, 0x0, 0x80000000}};
  // 480.3214
  s21_decimal dec_2 = {{0x494a8e, 0x0, 0x0, 0x40000}};
  // -605.3214
  s21_decimal dec_check = {{0x5c5d5e, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_141) {
  // -599644.4692
  s21_decimal dec_1 = {{0x656a7c14, 0x1, 0x0, 0x80040000}};
  // 6547444795156284056
  s21_decimal dec_2 = {{0xf1c54298, 0x5add3259, 0x0, 0x0}};
  // -6547444795156883700.4692
  s21_decimal dec_check = {{0x8ee3cd94, 0x607ed975, 0xddd, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_142) {
  // -182960417486854351776947
  s21_decimal dec_1 = {{0xc86cb3, 0x4dd9e275, 0x26be, 0x80000000}};
  // 66.9843115
  s21_decimal dec_2 = {{0x27ecfeab, 0x0, 0x0, 0x70000}};
  // -182960417486854351777013.98431
  s21_decimal dec_check = {{0xd342d79f, 0x972bc851, 0x3b1e218a, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_143) {
  // 7260686462385971.8392569842
  s21_decimal dec_1 = {{0xb6dff2, 0x4a400ab, 0x3c0f1a, 0xa0000}};
  // 1518676.1
  s21_decimal dec_2 = {{0xe7bb49, 0x0, 0x0, 0x10000}};
  // 7260686460867295.7392569842
  s21_decimal dec_check = {{0xaa0545f2, 0x46e0c63, 0x3c0f1a, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_144) {
  // -91799261775625425526571
  s21_decimal dec_1 = {{0xf0541f2b, 0x72ad0398, 0x1370, 0x80000000}};
  // -862813022741774580257.0
  s21_decimal dec_2 = {{0x1511454a, 0xbb5c480b, 0x1d3, 0x80010000}};
  // -90936448752883650946314.0
  s21_decimal dec_check = {{0x4e37f264, 0xbf65dbee, 0xc090, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_145) {
  // -40465274426985758099
  s21_decimal dec_1 = {{0x772f3d93, 0x319188b2, 0x2, 0x80000000}};
  // 132611728159214162
  s21_decimal dec_2 = {{0x5fb0a52, 0x1d721aa, 0x0, 0x0}};
  // -40597886155144972261
  s21_decimal dec_check = {{0x7d2a47e5, 0x3368aa5c, 0x2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_146) {
  // -913841487990300
  s21_decimal dec_1 = {{0x4d45ce1c, 0x33f22, 0x0, 0x80000000}};
  // -0.6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x80010000}};
  // -913841487990299.4
  s21_decimal dec_check = {{0x4ba0d12, 0x207757, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_147) {
  // -2915848
  s21_decimal dec_1 = {{0x2c7e08, 0x0, 0x0, 0x80000000}};
  // -0.62881585112871686811766
  s21_decimal dec_2 = {{0x804ab076, 0xd14b933d, 0xd50, 0x80170000}};
  // -2915847.3711841488712831318823
  s21_decimal dec_check = {{0x852bbb27, 0x3cac12a4, 0x5e3752fb, 0x80160000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_148) {
  // -5.28452616
  s21_decimal dec_1 = {{0x1f7f8c08, 0x0, 0x0, 0x80080000}};
  // -78
  s21_decimal dec_2 = {{0x4e, 0x0, 0x0, 0x80000000}};
  // 72.71547384
  s21_decimal dec_check = {{0xb16b01f8, 0x1, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_149) {
  // -5
  s21_decimal dec_1 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 2417545960254390226773
  s21_decimal dec_2 = {{0xd78d4f55, 0xe309a24, 0x83, 0x0}};
  // -2417545960254390226778
  s21_decimal dec_check = {{0xd78d4f5a, 0xe309a24, 0x83, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_151) {
  // 70.94780009
  s21_decimal dec_1 = {{0xa6e1c069, 0x1, 0x0, 0x80000}};
  // 8310
  s21_decimal dec_2 = {{0x2076, 0x0, 0x0, 0x0}};
  // -8239.05219991
  s21_decimal dec_check = {{0xd493f597, 0xbf, 0x0, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_152) {
  // 9.011727777169157036254965
  s21_decimal dec_1 = {{0xa66526f5, 0xbddf9346, 0x7744e, 0x180000}};
  // 0.0315073482973379279081
  s21_decimal dec_2 = {{0xf55bb8e9, 0x1485df6e, 0x11, 0x160000}};
  // 8.980220428871819108346865
  s21_decimal dec_check = {{0xce90ebf1, 0xb9944bee, 0x76da2, 0x180000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_153) {
  // -742444.1
  s21_decimal dec_1 = {{0x7149b9, 0x0, 0x0, 0x80010000}};
  // 528764033395658831335082970
  s21_decimal dec_2 = {{0x675d4bda, 0xafde7b65, 0x1b56223, 0x0}};
  // -528764033395658831335825414.1
  s21_decimal dec_check = {{0xa16403d, 0xdeb0d1f6, 0x1115d564, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_154) {
  // 1463488347579044887384218
  s21_decimal dec_1 = {{0x18e1d09a, 0xdcbf358f, 0x135e7, 0x0}};
  // -36199123845360066810853033745
  s21_decimal dec_2 = {{0x97418711, 0xc2b41935, 0x74f736a3, 0x80000000}};
  // 36200587333707645855740417963
  s21_decimal dec_check = {{0xb02357ab, 0x9f734ec4, 0x74f86c8b, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_155) {
  // -983646687208409140
  s21_decimal dec_1 = {{0x4f8c0834, 0xda69d73, 0x0, 0x80000000}};
  // 30553557680900894803
  s21_decimal dec_2 = {{0xc2817053, 0xa8040ad4, 0x1, 0x0}};
  // -31537204368109303943
  s21_decimal dec_check = {{0x120d7887, 0xb5aaa848, 0x1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_156) {
  // 231914521
  s21_decimal dec_1 = {{0xdd2bc19, 0x0, 0x0, 0x0}};
  // 5042986.891967934948
  s21_decimal dec_2 = {{0xfeb331e4, 0x45fc49db, 0x0, 0xc0000}};
  // 226871534.108032065052
  s21_decimal dec_check = {{0x1d2b5e1c, 0x4c799a41, 0xc, 0xc0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_157) {
  // 60170985964149237621910136
  s21_decimal dec_1 = {{0x34eeea78, 0xaf65bef6, 0x31c5b3, 0x0}};
  // 307.81892465367514
  s21_decimal dec_2 = {{0xd5e999da, 0x6d5bf7, 0x0, 0xe0000}};
  // 60170985964149237621909828.181
  s21_decimal dec_check = {{0xc53f3255, 0x2571f1be, 0xc26c45e5, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_158) {
  // -3805309920571396890949553.651
  s21_decimal dec_1 = {{0x2a4f8df3, 0x24a93fdb, 0xc4badb8, 0x80030000}};
  // -75176457023.472013551174580
  s21_decimal dec_2 = {{0x106583b4, 0xe6b70c09, 0x3e2f3b, 0x800f0000}};
  // -3805309920571321714492530.1790
  s21_decimal dec_check = {{0xd2f1ac1e, 0x6e99d2d5, 0x7af4c931, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_159) {
  // -9422945
  s21_decimal dec_1 = {{0x8fc861, 0x0, 0x0, 0x80000000}};
  // 675941267943.75852
  s21_decimal dec_2 = {{0xc7b42ac, 0xf02480, 0x0, 0x50000}};
  // -675950690888.75852
  s21_decimal dec_check = {{0x719c454c, 0xf0255b, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_160) {
  // -1010234563978115
  s21_decimal dec_1 = {{0x90536383, 0x396cd, 0x0, 0x80000000}};
  // -43134269345046798
  s21_decimal dec_2 = {{0xb1f5210e, 0x993e63, 0x0, 0x80000000}};
  // 42124034781068683
  s21_decimal dec_check = {{0x21a1bd8b, 0x95a796, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_161) {
  // 818246476050023850
  s21_decimal dec_1 = {{0xafad45aa, 0xb5afed5, 0x0, 0x0}};
  // 806525685602419563
  s21_decimal dec_2 = {{0x808f836b, 0xb315ad6, 0x0, 0x0}};
  // 11720790447604287
  s21_decimal dec_check = {{0x2f1dc23f, 0x29a3ff, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_162) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // 3.50022449226421102297806
  s21_decimal dec_2 = {{0x86ddc2ce, 0xc1474103, 0x4a1e, 0x170000}};
  // -3.50022449226421102297806
  s21_decimal dec_check = {{0x86ddc2ce, 0xc1474103, 0x4a1e, 0x80170000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_163) {
  // 7966
  s21_decimal dec_1 = {{0x1f1e, 0x0, 0x0, 0x0}};
  // -15022899243673
  s21_decimal dec_2 = {{0xca92aa99, 0xda9, 0x0, 0x80000000}};
  // 15022899251639
  s21_decimal dec_check = {{0xca92c9b7, 0xda9, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_164) {
  // 9280
  s21_decimal dec_1 = {{0x2440, 0x0, 0x0, 0x0}};
  // -34530072852276251
  s21_decimal dec_2 = {{0x166da41b, 0x7aaceb, 0x0, 0x80000000}};
  // 34530072852285531
  s21_decimal dec_check = {{0x166dc85b, 0x7aaceb, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_165) {
  // 586201701133169565151622318
  s21_decimal dec_1 = {{0x443574ae, 0xe4e7ef43, 0x1e4e509, 0x0}};
  // 806.848027
  s21_decimal dec_2 = {{0x3017861b, 0x0, 0x0, 0x60000}};
  // 586201701133169565151621511.15
  s21_decimal dec_check = {{0xa4e058cb, 0x6a997646, 0xbd6977dd, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_166) {
  // 2
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x0}};
  // -968704591627705
  s21_decimal dec_2 = {{0x1d1385b9, 0x37108, 0x0, 0x80000000}};
  // 968704591627707
  s21_decimal dec_check = {{0x1d1385bb, 0x37108, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_167) {
  // 804702364878080885737.5913837
  s21_decimal dec_1 = {{0x59deb76d, 0x1a3eb293, 0x1a00578a, 0x70000}};
  // -434828723966656015
  s21_decimal dec_2 = {{0xae2b3e0f, 0x608d26b, 0x0, 0x80000000}};
  // 805137193602047541752.5913837
  s21_decimal dec_check = {{0x9ec288ed, 0x39e26a24, 0x1a03f053, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_168) {
  // -6877917340113699
  s21_decimal dec_1 = {{0xebda1b23, 0x186f6d, 0x0, 0x80000000}};
  // -31.73970067
  s21_decimal dec_2 = {{0xbd2ef093, 0x0, 0x0, 0x80080000}};
  // -6877917340113667.26029933
  s21_decimal dec_check = {{0x9c29d26d, 0x43bd968d, 0x91a5, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_169) {
  // 311
  s21_decimal dec_1 = {{0x137, 0x0, 0x0, 0x0}};
  // 820917.585
  s21_decimal dec_2 = {{0x30ee3551, 0x0, 0x0, 0x30000}};
  // -820606.585
  s21_decimal dec_check = {{0x30e97679, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_170) {
  // -1109311989013.0
  s21_decimal dec_1 = {{0xd17872d2, 0xa16, 0x0, 0x80010000}};
  // -8.3330712
  s21_decimal dec_2 = {{0x4f78698, 0x0, 0x0, 0x80070000}};
  // -1109311989004.6669288
  s21_decimal dec_check = {{0x210d51e8, 0x99f2adc4, 0x0, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_171) {
  // 5717404438121398078711
  s21_decimal dec_1 = {{0x4bc30cf7, 0xf0ecf45d, 0x135, 0x0}};
  // -22
  s21_decimal dec_2 = {{0x16, 0x0, 0x0, 0x80000000}};
  // 5717404438121398078733
  s21_decimal dec_check = {{0x4bc30d0d, 0xf0ecf45d, 0x135, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_172) {
  // -222
  s21_decimal dec_1 = {{0xde, 0x0, 0x0, 0x80000000}};
  // 867
  s21_decimal dec_2 = {{0x363, 0x0, 0x0, 0x0}};
  // -1089
  s21_decimal dec_check = {{0x441, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_173) {
  // -1699999470362.00472940941
  s21_decimal dec_1 = {{0x4d7c118d, 0xb7313b1a, 0x23ff, 0x800b0000}};
  // -39312391.8355
  s21_decimal dec_2 = {{0x8802f213, 0x5b, 0x0, 0x80040000}};
  // -1699960157970.16922940941
  s21_decimal dec_check = {{0xd6e3e60d, 0x80a2a9e4, 0x23ff, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_174) {
  // 3559926497829759380225321
  s21_decimal dec_1 = {{0xcc91fd29, 0x8c5d38, 0x2f1d8, 0x0}};
  // -81826182574
  s21_decimal dec_2 = {{0xd3875ae, 0x13, 0x0, 0x80000000}};
  // 3559926497829841206407895
  s21_decimal dec_check = {{0xd9ca72d7, 0x8c5d4b, 0x2f1d8, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_175) {
  // 0.99
  s21_decimal dec_1 = {{0x63, 0x0, 0x0, 0x20000}};
  // -0.9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x80010000}};
  // 1.89
  s21_decimal dec_check = {{0xbd, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_176) {
  // 0.133690220239
  s21_decimal dec_1 = {{0x208edecf, 0x1f, 0x0, 0xc0000}};
  // -927.52811920464
  s21_decimal dec_2 = {{0xb2680c50, 0x545b, 0x0, 0x800b0000}};
  // 927.661809424879
  s21_decimal dec_check = {{0x189f59ef, 0x34bb4, 0x0, 0xc0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_178) {
  // 41658974106.4837
  s21_decimal dec_1 = {{0xdb888285, 0x17ae2, 0x0, 0x40000}};
  // 82444029836181355030202
  s21_decimal dec_2 = {{0xefcee6ba, 0x4cc088d0, 0x1175, 0x0}};
  // -82444029836139696056095.5163
  s21_decimal dec_check = {{0xa68c3f1b, 0x20dee6b4, 0x2a9f606, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_179) {
  // 79398954760306402120262
  s21_decimal dec_1 = {{0x9d95d246, 0x39d8a8ce, 0x10d0, 0x0}};
  // 2047371
  s21_decimal dec_2 = {{0x1f3d8b, 0x0, 0x0, 0x0}};
  // 79398954760306400072891
  s21_decimal dec_check = {{0x9d7694bb, 0x39d8a8ce, 0x10d0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_180) {
  // -92.150039896
  s21_decimal dec_1 = {{0x74920558, 0x15, 0x0, 0x80090000}};
  // 0.2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x10000}};
  // -92.350039896
  s21_decimal dec_check = {{0x807dc758, 0x15, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_182) {
  // -3492777842.9094766865
  s21_decimal dec_1 = {{0xbbea911, 0xe4b8656d, 0x1, 0x800a0000}};
  // 8.485954392
  s21_decimal dec_2 = {{0xf9cd6358, 0x1, 0x0, 0x90000}};
  // -3492777851.3954310785
  s21_decimal dec_check = {{0xcdc48a81, 0xe4b86580, 0x1, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_183) {
  // -576626.97
  s21_decimal dec_1 = {{0x36fdce9, 0x0, 0x0, 0x80020000}};
  // -2.38
  s21_decimal dec_2 = {{0xee, 0x0, 0x0, 0x80020000}};
  // -576624.59
  s21_decimal dec_check = {{0x36fdbfb, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_184) {
  // 7583578.39766852148274754902
  s21_decimal dec_1 = {{0x9057556, 0xdead4b4b, 0x2734c84, 0x140000}};
  // 447179927352053
  s21_decimal dec_2 = {{0x30b872f5, 0x196b5, 0x0, 0x0}};
  // -447179919768474.60233147851725
  s21_decimal dec_check = {{0x55ac23cd, 0x863d0682, 0x907ddb22, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_185) {
  // 235
  s21_decimal dec_1 = {{0xeb, 0x0, 0x0, 0x0}};
  // 380955936495223
  s21_decimal dec_2 = {{0x37451677, 0x15a7a, 0x0, 0x0}};
  // -380955936494988
  s21_decimal dec_check = {{0x3745158c, 0x15a7a, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_186) {
  // 9
  s21_decimal dec_1 = {{0x9, 0x0, 0x0, 0x0}};
  // 25694.54222059041546226931506
  s21_decimal dec_2 = {{0xd7509732, 0x7ba0db51, 0x84d6718, 0x170000}};
  // -25685.54222059041546226931506
  s21_decimal dec_check = {{0x2cd09732, 0x6299efaf, 0x84ca883, 0x80170000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_187) {
  // 1817964.09680123172
  s21_decimal dec_1 = {{0x146cd524, 0x285dedf, 0x0, 0xb0000}};
  // -22735136767953923048334624872
  s21_decimal dec_2 = {{0x4fa70868, 0xc74e1cd3, 0x49761079, 0x80000000}};
  // 22735136767953923048336442836
  s21_decimal dec_check = {{0x4fc2c5d4, 0xc74e1cd3, 0x49761079, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_188) {
  // -20411
  s21_decimal dec_1 = {{0x4fbb, 0x0, 0x0, 0x80000000}};
  // 3554912547722070085566657
  s21_decimal dec_2 = {{0x1c9780c1, 0x32033b53, 0x2f0c8, 0x0}};
  // -3554912547722070085587068
  s21_decimal dec_check = {{0x1c97d07c, 0x32033b53, 0x2f0c8, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_190) {
  // -320637609026859188506
  s21_decimal dec_1 = {{0x5c86411a, 0x61bd9e99, 0x11, 0x80000000}};
  // -76063252295971848600889
  s21_decimal dec_2 = {{0xcd683d39, 0x65ace2cd, 0x101b, 0x80000000}};
  // 75742614686944989412383
  s21_decimal dec_check = {{0x70e1fc1f, 0x3ef4434, 0x100a, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_191) {
  // 1759437855.472762354455079801
  s21_decimal dec_1 = {{0x9d94eb79, 0x43498069, 0x5af5f75, 0x120000}};
  // -9.039565
  s21_decimal dec_2 = {{0x89eecd, 0x0, 0x0, 0x80060000}};
  // 1759437864.512327354455079801
  s21_decimal dec_check = {{0xeaa2bb79, 0xc0bc7ce2, 0x5af5f75, 0x120000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_192) {
  // 641908496.273657
  s21_decimal dec_1 = {{0xf7e610f9, 0x247cf, 0x0, 0x60000}};
  // 5073731239837582816433479.6
  s21_decimal dec_2 = {{0xdb5654cc, 0x376748b7, 0x29f80b, 0x10000}};
  // -5073731239837582174524983.3263
  s21_decimal dec_check = {{0x39f3d12f, 0x6b74085a, 0xa3f0ebd0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_193) {
  // 46250292253
  s21_decimal dec_1 = {{0xc4bb741d, 0xa, 0x0, 0x0}};
  // -181627.202472
  s21_decimal dec_2 = {{0x49d32ba8, 0x2a, 0x0, 0x80060000}};
  // 46250473880.202472
  s21_decimal dec_check = {{0x9a52ace8, 0xa4508f, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_194) {
  // -4763805.6519732
  s21_decimal dec_1 = {{0x996fc834, 0x2b53, 0x0, 0x80070000}};
  // -0.9076612045169233210324
  s21_decimal dec_2 = {{0x37f3abd4, 0xb4bc521, 0x1ec, 0x80160000}};
  // -4763804.7443119954830766789676
  s21_decimal dec_check = {{0xd45e542c, 0x8a377de4, 0x99ed44ee, 0x80160000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_195) {
  // -7.96041717
  s21_decimal dec_1 = {{0x2f72a1f5, 0x0, 0x0, 0x80080000}};
  // -3907196.8333088173
  s21_decimal dec_2 = {{0x892b45ad, 0x8acfbf, 0x0, 0x800a0000}};
  // 3907188.8728916473
  s21_decimal dec_check = {{0x6401f9, 0x8acfad, 0x0, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_196) {
  // 75644718952
  s21_decimal dec_1 = {{0x9cc6cf68, 0x11, 0x0, 0x0}};
  // -758314.5819953558397600
  s21_decimal dec_2 = {{0xf01f22a0, 0x1549e204, 0x19b, 0x80100000}};
  // 75645477266.5819953558397600
  s21_decimal dec_check = {{0x658722a0, 0x6543c825, 0x271b987, 0x100000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_197) {
  // 276624916842552577200873104
  s21_decimal dec_1 = {{0x875de90, 0xca4b966e, 0xe4d19a, 0x0}};
  // -548517195062915
  s21_decimal dec_2 = {{0x9c909e83, 0x1f2df, 0x0, 0x80000000}};
  // 276624916843101094395936019
  s21_decimal dec_check = {{0xa5067d13, 0xca4d894d, 0xe4d19a, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_199) {
  // -722.9806
  s21_decimal dec_1 = {{0x6e516e, 0x0, 0x0, 0x80040000}};
  // 488022975990832337
  s21_decimal dec_2 = {{0x9e299cd1, 0x6c5ce4f, 0x0, 0x0}};
  // -488022975990833059.9806
  s21_decimal dec_check = {{0x39ebf57e, 0x8ecb0612, 0x108, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_200) {
  // 470298139583.4145472621
  s21_decimal dec_1 = {{0x3d02006d, 0xf2fa560c, 0xfe, 0xa0000}};
  // 67757182377136668405
  s21_decimal dec_2 = {{0xa96bef5, 0xac51de61, 0x3, 0x0}};
  // -67757181906838528821.585452738
  s21_decimal dec_check = {{0xdc8f1ec2, 0x3e970cd7, 0xdaef6d5f, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_201) {
  // -6744843839044324399286782
  s21_decimal dec_1 = {{0x17ec89fe, 0xb7985897, 0x59446, 0x80000000}};
  // 620605742213197678969994
  s21_decimal dec_2 = {{0x4e17048a, 0x1acd80c2, 0x836b, 0x0}};
  // -7365449581257522078256776
  s21_decimal dec_check = {{0x66038e88, 0xd265d959, 0x617b1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_202) {
  // 14726.88
  s21_decimal dec_1 = {{0x1678b0, 0x0, 0x0, 0x20000}};
  // -716051555
  s21_decimal dec_2 = {{0x2aae1463, 0x0, 0x0, 0x80000000}};
  // 716066281.88
  s21_decimal dec_check = {{0xac166f5c, 0x10, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_203) {
  // 5.156019
  s21_decimal dec_1 = {{0x4eacb3, 0x0, 0x0, 0x60000}};
  // 0
  s21_decimal dec_2 = {{0x0, 0x0, 0x0, 0x0}};
  // 5.156019
  s21_decimal dec_check = {{0x4eacb3, 0x0, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_204) {
  // -163380946761.770289460
  s21_decimal dec_1 = {{0x52534934, 0xdb5db973, 0x8, 0x80090000}};
  // -836461.675725842459900687934
  s21_decimal dec_2 = {{0x2812b63e, 0x4d1796e5, 0x2b3e7a6, 0x80150000}};
  // -163380110300.09456361754009931
  s21_decimal dec_check = {{0xbcf214b, 0xa4340e9e, 0x34ca7c68, 0x80110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_205) {
  // 310560833672666401173964
  s21_decimal dec_1 = {{0x444b71cc, 0x8959e379, 0x41c3, 0x0}};
  // -9.243070703
  s21_decimal dec_2 = {{0x26ee10ef, 0x2, 0x0, 0x80090000}};
  // 310560833672666401173973.24307
  s21_decimal dec_check = {{0x9e920213, 0xc8b8e9d5, 0x6458fd74, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_206) {
  // -225976724739799.3917732928
  s21_decimal dec_1 = {{0x2c185840, 0x3a5abc78, 0x1de86, 0x800a0000}};
  // 193443982
  s21_decimal dec_2 = {{0xb87b88e, 0x0, 0x0, 0x0}};
  // -225976918183781.3917732928
  s21_decimal dec_check = {{0x9290d040, 0x55333f3c, 0x1de86, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_207) {
  // 0.82377286759257901777577022
  s21_decimal dec_1 = {{0x65b4643e, 0xa9d41641, 0x442411, 0x1a0000}};
  // -754031
  s21_decimal dec_2 = {{0xb816f, 0x0, 0x0, 0x80000000}};
  // 754031.82377286759257901777577
  s21_decimal dec_check = {{0xca4e42a9, 0x49eb8b30, 0xf3a40cf3, 0x170000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_208) {
  // -29
  s21_decimal dec_1 = {{0x1d, 0x0, 0x0, 0x80000000}};
  // -738306492057944851.3058823338
  s21_decimal dec_2 = {{0xb0dfdcaa, 0x531ebda1, 0x17db20cf, 0x800a0000}};
  // 738306492057944822.3058823338
  s21_decimal dec_check = {{0x2b8708aa, 0x531ebd5e, 0x17db20cf, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_209) {
  // -283069.0300273406082821
  s21_decimal dec_1 = {{0x6c317f05, 0x73b82675, 0x99, 0x80100000}};
  // 675096028476033221084
  s21_decimal dec_2 = {{0x3ef441dc, 0x98d6e516, 0x24, 0x0}};
  // -675096028476033504153.03002734
  s21_decimal dec_check = {{0xb8544a6e, 0x8cddac1f, 0xda22a277, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_210) {
  // 4.11374762
  s21_decimal dec_1 = {{0x188514aa, 0x0, 0x0, 0x80000}};
  // 0.2550808004845373868338
  s21_decimal dec_2 = {{0x9765c932, 0x47927da5, 0x8a, 0x160000}};
  // 3.8586668195154626131662
  s21_decimal dec_check = {{0x26c8b6ce, 0xc997ea90, 0x82b, 0x160000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_211) {
  // -74446511814548596
  s21_decimal dec_1 = {{0x43791c74, 0x1087cb5, 0x0, 0x80000000}};
  // -6059
  s21_decimal dec_2 = {{0x17ab, 0x0, 0x0, 0x80000000}};
  // -74446511814542537
  s21_decimal dec_check = {{0x437904c9, 0x1087cb5, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_212) {
  // 7590770902888174853
  s21_decimal dec_1 = {{0x26055505, 0x6957d5eb, 0x0, 0x0}};
  // -982357.3736882965320340
  s21_decimal dec_2 = {{0xb5cc1294, 0x8978ca2b, 0x214, 0x80100000}};
  // 7590770902889157210.3736882965
  s21_decimal dec_check = {{0x9f27715, 0xe0476084, 0xf545629f, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_213) {
  // 9215237480.8318880701122935
  s21_decimal dec_1 = {{0xdc868977, 0x3f937715, 0x4c3a06, 0x100000}};
  // 61446842766362
  s21_decimal dec_2 = {{0xb53c541a, 0x37e2, 0x0, 0x0}};
  // -61437627528881.168111929887706
  s21_decimal dec_check = {{0x481b8bda, 0xf55a580b, 0xc68403ad, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_214) {
  // 44813951465793297
  s21_decimal dec_1 = {{0x2a19a711, 0x9f360d, 0x0, 0x0}};
  // -6.00
  s21_decimal dec_2 = {{0x258, 0x0, 0x0, 0x80020000}};
  // 44813951465793303.00
  s21_decimal dec_check = {{0x720544fc, 0x3e311d24, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_215) {
  // 755316100
  s21_decimal dec_1 = {{0x2d053584, 0x0, 0x0, 0x0}};
  // 49443275969859245949
  s21_decimal dec_2 = {{0x6b11577d, 0xae29cd88, 0x2, 0x0}};
  // -49443275969103929849
  s21_decimal dec_check = {{0x3e0c21f9, 0xae29cd88, 0x2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_216) {
  // -23606.7203834741056115
  s21_decimal dec_1 = {{0x6978e273, 0xcc172f26, 0xc, 0x80100000}};
  // 386392359507
  s21_decimal dec_2 = {{0xf6c78253, 0x59, 0x0, 0x0}};
  // -386392383113.7203834741056115
  s21_decimal dec_check = {{0xa70be273, 0x9a146187, 0xc7c29b2, 0x80100000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_217) {
  // -7187361378450551.0345986
  s21_decimal dec_1 = {{0xdf93d02, 0x46c2d648, 0xf38, 0x80070000}};
  // -5.7
  s21_decimal dec_2 = {{0x39, 0x0, 0x0, 0x80010000}};
  // -7187361378450545.3345986
  s21_decimal dec_check = {{0xa937cc2, 0x46c2d648, 0xf38, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_218) {
  // 608181
  s21_decimal dec_1 = {{0x947b5, 0x0, 0x0, 0x0}};
  // -6.0722962
  s21_decimal dec_2 = {{0x39e8f12, 0x0, 0x0, 0x80070000}};
  // 608187.0722962
  s21_decimal dec_check = {{0xbbe7792, 0x588, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_219) {
  // -3.2923
  s21_decimal dec_1 = {{0x809b, 0x0, 0x0, 0x80040000}};
  // 2143.219006
  s21_decimal dec_2 = {{0x7fbeed3e, 0x0, 0x0, 0x60000}};
  // -2146.511306
  s21_decimal dec_check = {{0x7ff129ca, 0x0, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_220) {
  // 99587792237855875444133
  s21_decimal dec_1 = {{0xd33eada5, 0xaa3fb997, 0x1516, 0x0}};
  // 869254360328519023555087
  s21_decimal dec_2 = {{0xcd2f720f, 0x5f904bcd, 0xb812, 0x0}};
  // -769666568090663148110954
  s21_decimal dec_check = {{0xf9f0c46a, 0xb5509235, 0xa2fb, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_221) {
  // 22224697446317840.8586143091
  s21_decimal dec_1 = {{0x69a06573, 0xa0875c0b, 0xb7d6a0, 0xa0000}};
  // -705950462867459629826738231
  s21_decimal dec_2 = {{0x92088837, 0x4680c4d8, 0x247f2d3, 0x80000000}};
  // 705950462889684327273056071.86
  s21_decimal dec_check = {{0x3029d812, 0xa924b10e, 0xe41ada87, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_222) {
  // -399660192
  s21_decimal dec_1 = {{0x17d254a0, 0x0, 0x0, 0x80000000}};
  // -0.617
  s21_decimal dec_2 = {{0x269, 0x0, 0x0, 0x80030000}};
  // -399660191.383
  s21_decimal dec_check = {{0xd9a8e97, 0x5d, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_223) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // 8981791148661821192360482
  s21_decimal dec_2 = {{0xdcf15222, 0xdfb1fae8, 0x76df7, 0x0}};
  // -8981791148661821192360482
  s21_decimal dec_check = {{0xdcf15222, 0xdfb1fae8, 0x76df7, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_224) {
  // -1922
  s21_decimal dec_1 = {{0x782, 0x0, 0x0, 0x80000000}};
  // 23033345629
  s21_decimal dec_2 = {{0x5ce4f65d, 0x5, 0x0, 0x0}};
  // -23033347551
  s21_decimal dec_check = {{0x5ce4fddf, 0x5, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_225) {
  // 7031.9618778668440
  s21_decimal dec_1 = {{0x1a0b1d98, 0xf9d352, 0x0, 0xd0000}};
  // 38867444975927594.7435295
  s21_decimal dec_2 = {{0xd510a51f, 0x158a4291, 0x524e, 0x70000}};
  // -38867444975920562.781651633156
  s21_decimal dec_check = {{0x50268404, 0x17baca34, 0x7d96659e, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_226) {
  // 716466976446.81021833275127
  s21_decimal dec_1 = {{0x71d2e6f7, 0x430b2453, 0x3b43c7, 0xe0000}};
  // 5493.89416328
  s21_decimal dec_2 = {{0xea293788, 0x7f, 0x0, 0x80000}};
  // 716466970952.91605505275127
  s21_decimal dec_check = {{0x63bf4f7, 0x3b6b5190, 0x3b43c7, 0xe0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_227) {
  // 306103962501648
  s21_decimal dec_1 = {{0x61f30210, 0x11666, 0x0, 0x0}};
  // -7184714.67311871809281
  s21_decimal dec_2 = {{0x29cbd701, 0xf2cb68e5, 0x26, 0x800e0000}};
  // 306103969686362.67311871809281
  s21_decimal dec_check = {{0xe5efd701, 0xb3b37481, 0x62e853b0, 0xe0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_228) {
  // 122832
  s21_decimal dec_1 = {{0x1dfd0, 0x0, 0x0, 0x0}};
  // -691807689959369845
  s21_decimal dec_2 = {{0xbce96c75, 0x999cb6d, 0x0, 0x80000000}};
  // 691807689959492677
  s21_decimal dec_check = {{0xbceb4c45, 0x999cb6d, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_229) {
  // -51686126120857362924792.798
  s21_decimal dec_1 = {{0xa0976bde, 0x82e9c71f, 0x2ac0f6, 0x80030000}};
  // 45623385508068.07739758722660
  s21_decimal dec_2 = {{0xfc72be64, 0x6b823335, 0xebde0c4, 0xe0000}};
  // -51686126166480748432860.875398
  s21_decimal dec_check = {{0xd2978a86, 0xda58a6f0, 0xa701c2f1, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_230) {
  // -3.3618651214
  s21_decimal dec_1 = {{0xd3d3e84e, 0x7, 0x0, 0x800a0000}};
  // 60479201938859764.61
  s21_decimal dec_2 = {{0x827c378d, 0x53ee875f, 0x0, 0x20000}};
  // -60479201938859767.9718651214
  s21_decimal dec_check = {{0xeb97d54e, 0x10ef3fad, 0x1f445b1, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_232) {
  // -66966
  s21_decimal dec_1 = {{0x10596, 0x0, 0x0, 0x80000000}};
  // -9940174302742005797
  s21_decimal dec_2 = {{0xf0674825, 0x89f297dc, 0x0, 0x80000000}};
  // 9940174302741938831
  s21_decimal dec_check = {{0xf066428f, 0x89f297dc, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_233) {
  // -60281516944
  s21_decimal dec_1 = {{0x90ef390, 0xe, 0x0, 0x80000000}};
  // -77.74
  s21_decimal dec_2 = {{0x1e5e, 0x0, 0x0, 0x80020000}};
  // -60281516866.26
  s21_decimal dec_check = {{0x89d705e2, 0x57b, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_234) {
  // 67839
  s21_decimal dec_1 = {{0x108ff, 0x0, 0x0, 0x0}};
  // 6.65
  s21_decimal dec_2 = {{0x299, 0x0, 0x0, 0x20000}};
  // 67832.35
  s21_decimal dec_check = {{0x678103, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_235) {
  // 7828.03
  s21_decimal dec_1 = {{0xbf1d3, 0x0, 0x0, 0x20000}};
  // -566487432201823.41
  s21_decimal dec_2 = {{0x589c7d45, 0xc941bb, 0x0, 0x80020000}};
  // 566487432209651.44
  s21_decimal dec_check = {{0x58a86f18, 0xc941bb, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_236) {
  // -27729141.08746437492612582705
  s21_decimal dec_1 = {{0xa3a4cd31, 0xa7a5e44, 0x8f5b367, 0x80140000}};
  // -6390
  s21_decimal dec_2 = {{0x18f6, 0x0, 0x0, 0x80000000}};
  // -27722751.08746437492612582705
  s21_decimal dec_check = {{0xf244cd31, 0xc8119d5d, 0x8f52c16, 0x80140000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_237) {
  // 90426688030396257
  s21_decimal dec_1 = {{0xfa444f61, 0x1414297, 0x0, 0x0}};
  // -894
  s21_decimal dec_2 = {{0x37e, 0x0, 0x0, 0x80000000}};
  // 90426688030397151
  s21_decimal dec_check = {{0xfa4452df, 0x1414297, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_238) {
  // -75361041187.77533320367
  s21_decimal dec_1 = {{0x8d124caf, 0x88743009, 0x198, 0x800b0000}};
  // -352
  s21_decimal dec_2 = {{0x160, 0x0, 0x0, 0x80000000}};
  // -75361040835.77533320367
  s21_decimal dec_check = {{0xe9934caf, 0x88741005, 0x198, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_239) {
  // -3.856044
  s21_decimal dec_1 = {{0x3ad6ac, 0x0, 0x0, 0x80060000}};
  // 40943729536230886
  s21_decimal dec_2 = {{0xe6c965e6, 0x91761a, 0x0, 0x0}};
  // -40943729536230889.856044
  s21_decimal dec_check = {{0x97539c2c, 0x9063fc06, 0x8ab, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_240) {
  // 708454790022752774755
  s21_decimal dec_1 = {{0xaa222a63, 0x67c905f8, 0x26, 0x0}};
  // -9963738534847319929263
  s21_decimal dec_2 = {{0x5d8c71af, 0x22a62f4b, 0x21c, 0x80000000}};
  // 10672193324870072704018
  s21_decimal dec_check = {{0x7ae9c12, 0x8a6f3544, 0x242, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_241) {
  // 64942782221319078265
  s21_decimal dec_1 = {{0x43470179, 0x85431c59, 0x3, 0x0}};
  // 1380091792102.837947908
  s21_decimal dec_2 = {{0xb9e78e04, 0xd09efce0, 0x4a, 0x90000}};
  // 64942780841227286162.162052092
  s21_decimal dec_check = {{0x130bebfc, 0xc3f34843, 0xd1d768c3, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_242) {
  // -645052148486.48
  s21_decimal dec_1 = {{0xca6ace88, 0x3aaa, 0x0, 0x80020000}};
  // 5756454102
  s21_decimal dec_2 = {{0x571c84d6, 0x1, 0x0, 0x0}};
  // -650808602588.48
  s21_decimal dec_check = {{0xd18eb220, 0x3b30, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_243) {
  // 8.3392424736489451447161323
  s21_decimal dec_1 = {{0x5bf491eb, 0x6745aad6, 0x44fb08, 0x190000}};
  // -11077697.5517577
  s21_decimal dec_2 = {{0x46466789, 0x64c0, 0x0, 0x80070000}};
  // 11077705.891000173648945144716
  s21_decimal dec_check = {{0xe05ce38c, 0xa8ad3537, 0x23cb4377, 0x150000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_244) {
  // 181
  s21_decimal dec_1 = {{0xb5, 0x0, 0x0, 0x0}};
  // -2253213128836363416830.84
  s21_decimal dec_2 = {{0xff31b38c, 0xb15e682f, 0x2fb6, 0x80020000}};
  // 2253213128836363417011.84
  s21_decimal dec_check = {{0xff31fa40, 0xb15e682f, 0x2fb6, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_245) {
  // 9197514489718256
  s21_decimal dec_1 = {{0x37f9e5f0, 0x20ad17, 0x0, 0x0}};
  // 970423696901
  s21_decimal dec_2 = {{0xf1c27e05, 0xe1, 0x0, 0x0}};
  // 9196544066021355
  s21_decimal dec_check = {{0x463767eb, 0x20ac35, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_246) {
  // -15107.56811227772
  s21_decimal dec_1 = {{0x7b13427c, 0x55e06, 0x0, 0x800b0000}};
  // -0.4583856
  s21_decimal dec_2 = {{0x45f1b0, 0x0, 0x0, 0x80070000}};
  // -15107.10972667772
  s21_decimal dec_check = {{0xcee2577c, 0x55dfb, 0x0, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_247) {
  // -4096.07130134396
  s21_decimal dec_1 = {{0x177d377c, 0x17489, 0x0, 0x800b0000}};
  // -4585481957455247461572226
  s21_decimal dec_2 = {{0x4bcbde82, 0x799a24e7, 0x3cb03, 0x80000000}};
  // 4585481957455247461568129.9287
  s21_decimal dec_check = {{0xc932b357, 0x15418b00, 0x942a37be, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_248) {
  // 29532849776239439427
  s21_decimal dec_1 = {{0x55b9ee43, 0x99d9c266, 0x1, 0x0}};
  // 391876434159169.823623357
  s21_decimal dec_2 = {{0xc5e0c8bd, 0xaa00096e, 0x52fb, 0x90000}};
  // 29532457899805280257.176376643
  s21_decimal dec_check = {{0xb56e1543, 0xb0b621f8, 0x5f6cad36, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_249) {
  // -59444007882784788.821279
  s21_decimal dec_1 = {{0x7b7db51f, 0x7753ed8a, 0xc96, 0x80060000}};
  // 318.30097392
  s21_decimal dec_2 = {{0x6938bdf0, 0x7, 0x0, 0x80000}};
  // -59444007882785107.12225292
  s21_decimal dec_check = {{0xa6537e0c, 0x9cc8ca1f, 0x4eac6, 0x80080000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_250) {
  // -57947245923857996938271
  s21_decimal dec_1 = {{0xee3f7c1f, 0x53953e14, 0xc45, 0x80000000}};
  // -690792185782239453167748
  s21_decimal dec_2 = {{0x4ccec084, 0xeb5fa316, 0x9247, 0x80000000}};
  // 632844939858381456229477
  s21_decimal dec_check = {{0x5e8f4465, 0x97ca6501, 0x8602, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_251) {
  // -96542952425554477
  s21_decimal dec_1 = {{0xc0e4822d, 0x156fd4d, 0x0, 0x80000000}};
  // 82099.693
  s21_decimal dec_2 = {{0x4e4bded, 0x0, 0x0, 0x30000}};
  // -96542952425636576.693
  s21_decimal dec_check = {{0x81813db5, 0x3bcd77b9, 0x5, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_252) {
  // -6943419981
  s21_decimal dec_1 = {{0x9ddc2e4d, 0x1, 0x0, 0x80000000}};
  // -101450819.231082674529
  s21_decimal dec_2 = {{0xc90cf961, 0x7fe9b694, 0x5, 0x800c0000}};
  // -6841969161.768917325471
  s21_decimal dec_check = {{0x9578d69f, 0xe7656e52, 0x172, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_253) {
  // -72964.6
  s21_decimal dec_1 = {{0xb222e, 0x0, 0x0, 0x80010000}};
  // -4145201924084.4342961525
  s21_decimal dec_2 = {{0x606da575, 0x1e53c556, 0x8c7, 0x800a0000}};
  // 4145201851119.8342961525
  s21_decimal dec_check = {{0x6dc95975, 0x1e512dba, 0x8c7, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_254) {
  // -5349
  s21_decimal dec_1 = {{0x14e5, 0x0, 0x0, 0x80000000}};
  // -738
  s21_decimal dec_2 = {{0x2e2, 0x0, 0x0, 0x80000000}};
  // -4611
  s21_decimal dec_check = {{0x1203, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_255) {
  // -187079179483801739
  s21_decimal dec_1 = {{0xc600e88b, 0x298a385, 0x0, 0x80000000}};
  // -0.96
  s21_decimal dec_2 = {{0x60, 0x0, 0x0, 0x80020000}};
  // -187079179483801738.04
  s21_decimal dec_check = {{0x585ad5ec, 0x39fe041, 0x1, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_256) {
  // 33190502
  s21_decimal dec_1 = {{0x1fa7266, 0x0, 0x0, 0x0}};
  // 0.77
  s21_decimal dec_2 = {{0x4d, 0x0, 0x0, 0x20000}};
  // 33190501.23
  s21_decimal dec_check = {{0xc5d4af8b, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_257) {
  // 469992040644
  s21_decimal dec_1 = {{0x6db568c4, 0x6d, 0x0, 0x0}};
  // -96
  s21_decimal dec_2 = {{0x60, 0x0, 0x0, 0x80000000}};
  // 469992040740
  s21_decimal dec_check = {{0x6db56924, 0x6d, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_258) {
  // 25054891.803150359106302
  s21_decimal dec_1 = {{0x8f7292fe, 0x3a78d475, 0x54e, 0xf0000}};
  // -0.2
  s21_decimal dec_2 = {{0x2, 0x0, 0x0, 0x80010000}};
  // 25054892.003150359106302
  s21_decimal dec_check = {{0xb06712fe, 0x3a798a5b, 0x54e, 0xf0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_259) {
  // 2769554315
  s21_decimal dec_1 = {{0xa5140b8b, 0x0, 0x0, 0x0}};
  // 3.579
  s21_decimal dec_2 = {{0xdfb, 0x0, 0x0, 0x30000}};
  // 2769554311.421
  s21_decimal dec_check = {{0xd64d08fd, 0x284, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_260) {
  // -0.758623
  s21_decimal dec_1 = {{0xb935f, 0x0, 0x0, 0x80060000}};
  // 769679757004855642261445
  s21_decimal dec_2 = {{0x82a987c5, 0x6c5901ca, 0xa2fc, 0x0}};
  // -769679757004855642261445.75862
  s21_decimal dec_check = {{0xeecc2176, 0x505ba19f, 0xf8b26ad3, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_261) {
  // -28.913708178
  s21_decimal dec_1 = {{0xbb642c92, 0x6, 0x0, 0x80090000}};
  // 8.99640
  s21_decimal dec_2 = {{0xdba38, 0x0, 0x0, 0x50000}};
  // -37.910108178
  s21_decimal dec_check = {{0xd39e5812, 0x8, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_263) {
  // 4511083290672112046032
  s21_decimal dec_1 = {{0x67738fd0, 0x8bdb501f, 0xf4, 0x0}};
  // -55676271079278961426508544
  s21_decimal dec_2 = {{0x46592b00, 0xb3f7f587, 0x2e0de8, 0x80000000}};
  // 55680782162569633538554576
  s21_decimal dec_check = {{0xadccbad0, 0x3fd345a6, 0x2e0edd, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_264) {
  // -65560
  s21_decimal dec_1 = {{0x10018, 0x0, 0x0, 0x80000000}};
  // -713353759894443
  s21_decimal dec_2 = {{0x9d752bab, 0x288ca, 0x0, 0x80000000}};
  // 713353759828883
  s21_decimal dec_check = {{0x9d742b93, 0x288ca, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_265) {
  // 961659367
  s21_decimal dec_1 = {{0x3951c1e7, 0x0, 0x0, 0x0}};
  // -5.92
  s21_decimal dec_2 = {{0x250, 0x0, 0x0, 0x80020000}};
  // 961659372.92
  s21_decimal dec_check = {{0x63efc08c, 0x16, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_266) {
  // 323949
  s21_decimal dec_1 = {{0x4f16d, 0x0, 0x0, 0x0}};
  // 76556870.05375738483840
  s21_decimal dec_2 = {{0x32e91480, 0x3fff1d2, 0x19f, 0xe0000}};
  // -76232921.05375738483840
  s21_decimal dec_check = {{0x189bd480, 0x426e23e8, 0x19d, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_267) {
  // -3.37225903960195
  s21_decimal dec_1 = {{0x8636f083, 0x132b4, 0x0, 0x800e0000}};
  // 0.823411319597130210
  s21_decimal dec_2 = {{0x889f61e2, 0xb6d583b, 0x0, 0x120000}};
  // -4.195670359199080210
  s21_decimal dec_check = {{0x4ab25f12, 0x3a3a03f6, 0x0, 0x80120000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_268) {
  // -7.6998093949446624957323607
  s21_decimal dec_1 = {{0x4cda5957, 0x96fc3de, 0x3fb0fb, 0x80190000}};
  // 8.184256861205051521091155
  s21_decimal dec_2 = {{0xe5afc653, 0x74159eba, 0x6c515, 0x180000}};
  // -15.8840662561497140168235157
  s21_decimal dec_check = {{0x45b81895, 0x9247f72b, 0x8363d1, 0x80190000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_269) {
  // -68608110.27502645414982
  s21_decimal dec_1 = {{0x1f08c46, 0xece12f61, 0x173, 0x800e0000}};
  // -163
  s21_decimal dec_2 = {{0xa3, 0x0, 0x0, 0x80000000}};
  // -68607947.27502645414982
  s21_decimal dec_check = {{0x8419cc46, 0xeca7469d, 0x173, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_270) {
  // 8698964578444
  s21_decimal dec_1 = {{0x62b1908c, 0x7e9, 0x0, 0x0}};
  // -64915152585724
  s21_decimal dec_2 = {{0x3c9c43fc, 0x3b0a, 0x0, 0x80000000}};
  // 73614117164168
  s21_decimal dec_check = {{0x9f4dd488, 0x42f3, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_271) {
  // -95
  s21_decimal dec_1 = {{0x5f, 0x0, 0x0, 0x80000000}};
  // 25355.788169616
  s21_decimal dec_2 = {{0x9abf3190, 0x170f, 0x0, 0x90000}};
  // -25450.788169616
  s21_decimal dec_check = {{0xb9302790, 0x1725, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_272) {
  // 93059069.262
  s21_decimal dec_1 = {{0xaac0b54e, 0x15, 0x0, 0x30000}};
  // -4219583802272760909177
  s21_decimal dec_2 = {{0x9c06cd79, 0xbe7d17da, 0xe4, 0x80000000}};
  // 4219583802272853968246.262
  s21_decimal dec_check = {{0x255355f6, 0x18a52e07, 0x37d88, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_273) {
  // -12.331482
  s21_decimal dec_1 = {{0xbc29da, 0x0, 0x0, 0x80060000}};
  // -8687
  s21_decimal dec_2 = {{0x21ef, 0x0, 0x0, 0x80000000}};
  // 8674.668518
  s21_decimal dec_check = {{0x50cefe6, 0x2, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_274) {
  // -779236734
  s21_decimal dec_1 = {{0x2e72357e, 0x0, 0x0, 0x80000000}};
  // 82.022
  s21_decimal dec_2 = {{0x14066, 0x0, 0x0, 0x30000}};
  // -779236816.022
  s21_decimal dec_check = {{0x6e223496, 0xb5, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_275) {
  // 18401738525
  s21_decimal dec_1 = {{0x48d43f1d, 0x4, 0x0, 0x0}};
  // 761400256925585
  s21_decimal dec_2 = {{0x4fd88f91, 0x2b47d, 0x0, 0x0}};
  // -761381855187060
  s21_decimal dec_check = {{0x7045074, 0x2b479, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_276) {
  // -0.4489077374
  s21_decimal dec_1 = {{0xb91e27e, 0x1, 0x0, 0x800a0000}};
  // 573113059.5210910682386
  s21_decimal dec_2 = {{0x575ecd12, 0xaf6a0f83, 0x136, 0xd0000}};
  // -573113059.9699988056386
  s21_decimal dec_check = {{0x893b8942, 0xaf6a1398, 0x136, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_277) {
  // -8448017035212004664352575.332
  s21_decimal dec_1 = {{0x20c20f64, 0x23795793, 0x1b4c0931, 0x80030000}};
  // 6.379
  s21_decimal dec_2 = {{0x18eb, 0x0, 0x0, 0x30000}};
  // -8448017035212004664352581.711
  s21_decimal dec_check = {{0x20c2284f, 0x23795793, 0x1b4c0931, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_278) {
  // -9410.5381327
  s21_decimal dec_1 = {{0xe91e29cf, 0x15, 0x0, 0x80070000}};
  // 6986922903392077948110
  s21_decimal dec_2 = {{0xbdb724ce, 0xc3089254, 0x17a, 0x0}};
  // -6986922903392077957520.5381327
  s21_decimal dec_check = {{0xee9144cf, 0x6c57765b, 0xe1c278bf, 0x80070000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_279) {
  // 3825186138309798680
  s21_decimal dec_1 = {{0xadb42b18, 0x3515ca86, 0x0, 0x0}};
  // 85.705016801473492761
  s21_decimal dec_2 = {{0x40b67719, 0xa56562b2, 0x4, 0x120000}};
  // 3825186138309798594.2949831985
  s21_decimal dec_check = {{0xa43da531, 0xa890dcfe, 0x7b9932b8, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_280) {
  // 1958093457.2
  s21_decimal dec_1 = {{0x8f1d59ac, 0x4, 0x0, 0x10000}};
  // -9689698187815378
  s21_decimal dec_2 = {{0xaa7729d2, 0x226cba, 0x0, 0x80000000}};
  // 9689700145908835.2
  s21_decimal dec_check = {{0x37c4fbe0, 0x1583f4f, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_281) {
  // -44821205898.662
  s21_decimal dec_1 = {{0xc00e55a6, 0x28c3, 0x0, 0x80030000}};
  // -9166544658640437899533
  s21_decimal dec_2 = {{0x319df10d, 0xeb5c9899, 0x1f0, 0x80000000}};
  // 9166544658595616693634.338
  s21_decimal dec_check = {{0x10e74522, 0x61b3eda6, 0x79517, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_282) {
  // -7394221454
  s21_decimal dec_1 = {{0xb8badd8e, 0x1, 0x0, 0x80000000}};
  // -255
  s21_decimal dec_2 = {{0xff, 0x0, 0x0, 0x80000000}};
  // -7394221199
  s21_decimal dec_check = {{0xb8badc8f, 0x1, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_283) {
  // 75180064911850377158
  s21_decimal dec_1 = {{0x5da68fc6, 0x13553eb7, 0x4, 0x0}};
  // 8004001611209.6499160
  s21_decimal dec_2 = {{0x720dd5d8, 0x56c74295, 0x4, 0x70000}};
  // 75180056907848765948.3500840
  s21_decimal dec_check = {{0x57081128, 0x837724de, 0x26ddff6, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_284) {
  // -4028.5932
  s21_decimal dec_1 = {{0x266b6ec, 0x0, 0x0, 0x80040000}};
  // -89135192444538008
  s21_decimal dec_2 = {{0x3aa48c98, 0x13cabfc, 0x0, 0x80000000}};
  // 89135192444533979.4068
  s21_decimal dec_check = {{0xb94d3a94, 0x51fe2cb2, 0x30, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_285) {
  // -9138
  s21_decimal dec_1 = {{0x23b2, 0x0, 0x0, 0x80000000}};
  // -62489062607.375895
  s21_decimal dec_2 = {{0xab0f4e17, 0xde0178, 0x0, 0x80060000}};
  // 62489053469.375895
  s21_decimal dec_check = {{0x8a647d97, 0xde0176, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_286) {
  // -248599394397370797
  s21_decimal dec_1 = {{0x26eb9ad, 0x37333d5, 0x0, 0x80000000}};
  // -246.75659469783077
  s21_decimal dec_2 = {{0xad4b8025, 0x57aa61, 0x0, 0x800e0000}};
  // -248599394397370550.24340530217
  s21_decimal dec_check = {{0x5617f429, 0x6bc9e590, 0x5053a8f1, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_287) {
  // -19.724152291584205511846
  s21_decimal dec_1 = {{0x7f89dca6, 0x3f99a628, 0x42d, 0x80150000}};
  // 6969628.02993194318080916775
  s21_decimal dec_2 = {{0xeae3d27, 0x41e10f67, 0x240839d, 0x140000}};
  // -6969647.754084234765014679596
  s21_decimal dec_check = {{0x1258402c, 0xd264402f, 0x16852851, 0x80150000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_288) {
  // -8553852650842648915552
  s21_decimal dec_1 = {{0xd8aae60, 0xb48d51b0, 0x1cf, 0x80000000}};
  // 900206793643296125486733678
  s21_decimal dec_2 = {{0xa289996e, 0x1155ad8f, 0x2e8a234, 0x0}};
  // -900215347495946968135649230
  s21_decimal dec_check = {{0xb01447ce, 0xc5e2ff3f, 0x2e8a403, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_289) {
  // 911105025566154
  s21_decimal dec_1 = {{0x2b66e5ca, 0x33ca5, 0x0, 0x0}};
  // 34451318223967
  s21_decimal dec_2 = {{0x5295b45f, 0x1f55, 0x0, 0x0}};
  // 876653707342187
  s21_decimal dec_check = {{0xd8d1316b, 0x31d4f, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_290) {
  // 0.1509789
  s21_decimal dec_1 = {{0x17099d, 0x0, 0x0, 0x70000}};
  // -3025.8108
  s21_decimal dec_2 = {{0x1cdb3bc, 0x0, 0x0, 0x80040000}};
  // 3025.9617789
  s21_decimal dec_check = {{0xb9d1ffd, 0x7, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_291) {
  // -7577368338391.274
  s21_decimal dec_1 = {{0x8c2460ea, 0x1aeb93, 0x0, 0x80030000}};
  // 18422564233552715511.375104
  s21_decimal dec_2 = {{0x2a722500, 0x354f1fa4, 0xf3d21, 0x60000}};
  // -18422571810921053902.649104
  s21_decimal dec_check = {{0x988cb710, 0x9e7757ff, 0xf3d21, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_292) {
  // 631360.91
  s21_decimal dec_1 = {{0x3c3615b, 0x0, 0x0, 0x20000}};
  // -23019
  s21_decimal dec_2 = {{0x59eb, 0x0, 0x0, 0x80000000}};
  // 654379.91
  s21_decimal dec_check = {{0x3e68127, 0x0, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_294) {
  // 8311
  s21_decimal dec_1 = {{0x2077, 0x0, 0x0, 0x0}};
  // 976509904006
  s21_decimal dec_2 = {{0x5c86a486, 0xe3, 0x0, 0x0}};
  // -976509895695
  s21_decimal dec_check = {{0x5c86840f, 0xe3, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_295) {
  // -28742823968504086154131936
  s21_decimal dec_1 = {{0xc4f739e0, 0x9c084265, 0x17c687, 0x80000000}};
  // -42
  s21_decimal dec_2 = {{0x2a, 0x0, 0x0, 0x80000000}};
  // -28742823968504086154131894
  s21_decimal dec_check = {{0xc4f739b6, 0x9c084265, 0x17c687, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_296) {
  // -4896820604718623804722782
  s21_decimal dec_1 = {{0x49418e5e, 0x2d490418, 0x40cf1, 0x80000000}};
  // 0.368946981387056616836
  s21_decimal dec_2 = {{0x802a9584, 0x2afcce, 0x14, 0x150000}};
  // -4896820604718623804722782.3689
  s21_decimal dec_check = {{0x90c94649, 0xf42ff4ad, 0x9e398cf8, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_297) {
  // 9289186966804430203634
  s21_decimal dec_1 = {{0x365e2af2, 0x915d9a16, 0x1f7, 0x0}};
  // -48129801543049436879713128578
  s21_decimal dec_2 = {{0xc6d6d082, 0xb6a930eb, 0x9b8409e9, 0x80000000}};
  // 48129810832236403684143332212
  s21_decimal dec_check = {{0xfd34fb74, 0x4806cb01, 0x9b840be1, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_299) {
  // 48496374874314903398
  s21_decimal dec_1 = {{0xddb80f66, 0xa105bc00, 0x2, 0x0}};
  // 47023.171
  s21_decimal dec_2 = {{0x2cd8443, 0x0, 0x0, 0x30000}};
  // 48496374874314856374.829
  s21_decimal dec_check = {{0x142ea22d, 0xfe666362, 0xa44, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_300) {
  // 1611752638459609
  s21_decimal dec_1 = {{0x677b2ed9, 0x5b9e1, 0x0, 0x0}};
  // 864694941674
  s21_decimal dec_2 = {{0x53d5b7ea, 0xc9, 0x0, 0x0}};
  // 1610887943517935
  s21_decimal dec_check = {{0x13a576ef, 0x5b918, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_301) {
  // 8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x0}};
  // 3074779065342415876396127
  s21_decimal dec_2 = {{0x59a0145f, 0x1b6cbb3e, 0x28b1c, 0x0}};
  // -3074779065342415876396119
  s21_decimal dec_check = {{0x59a01457, 0x1b6cbb3e, 0x28b1c, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_302) {
  // 29776769511872485204945288
  s21_decimal dec_1 = {{0x1853e988, 0xe8e351b0, 0x18a179, 0x0}};
  // -0.847228375055
  s21_decimal dec_2 = {{0x42bf100f, 0xc5, 0x0, 0x800c0000}};
  // 29776769511872485204945288.847
  s21_decimal dec_check = {{0x7c83e8f, 0xb7f717df, 0x6036c435, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_303) {
  // 221430034463216
  s21_decimal dec_1 = {{0xb28bf9f0, 0xc963, 0x0, 0x0}};
  // -538784313
  s21_decimal dec_2 = {{0x201d3239, 0x0, 0x0, 0x80000000}};
  // 221430573247529
  s21_decimal dec_check = {{0xd2a92c29, 0xc963, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_304) {
  // -461737125276.0
  s21_decimal dec_1 = {{0x10c5f818, 0x433, 0x0, 0x80010000}};
  // -79228162514264337593486175476
  s21_decimal dec_2 = {{0xfc8e6cf4, 0xffffffff, 0xffffffff, 0x80000000}};
  // 79228162514264337131749050200
  s21_decimal dec_check = {{0x7ae10758, 0xffffff94, 0xffffffff, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_305) {
  // -6629
  s21_decimal dec_1 = {{0x19e5, 0x0, 0x0, 0x80000000}};
  // 2234854
  s21_decimal dec_2 = {{0x2219e6, 0x0, 0x0, 0x0}};
  // -2241483
  s21_decimal dec_check = {{0x2233cb, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_306) {
  // 585563941906808466647088.20988
  s21_decimal dec_1 = {{0x46f28ffc, 0xb9020834, 0xbd34b6c9, 0x50000}};
  // 5897655543.003508
  s21_decimal dec_2 = {{0xefa5f974, 0x14f3e2, 0x0, 0x60000}};
  // 585563941906802568991545.20637
  s21_decimal dec_check = {{0xc8952a3d, 0xb8ffefd0, 0xbd34b6c9, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_307) {
  // -57188114135293017654
  s21_decimal dec_1 = {{0x78a2be36, 0x19a4fecf, 0x3, 0x80000000}};
  // 9869626.29129245734
  s21_decimal dec_2 = {{0x33d59426, 0xdb26548, 0x0, 0xb0000}};
  // -57188114135302887280.291292457
  s21_decimal dec_check = {{0xb9bb2529, 0x4aced94c, 0xb8c8e637, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_308) {
  // 961
  s21_decimal dec_1 = {{0x3c1, 0x0, 0x0, 0x0}};
  // -9303200.4877176676445
  s21_decimal dec_2 = {{0xf686205d, 0xb141387, 0x5, 0x800d0000}};
  // 9304161.4877176676445
  s21_decimal dec_check = {{0x72d0c05d, 0xb3637c6, 0x5, 0xd0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_309) {
  // 674
  s21_decimal dec_1 = {{0x2a2, 0x0, 0x0, 0x0}};
  // -183217765171446293952838
  s21_decimal dec_2 = {{0x60c37946, 0x4144861b, 0x26cc, 0x80000000}};
  // 183217765171446293953512
  s21_decimal dec_check = {{0x60c37be8, 0x4144861b, 0x26cc, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_310) {
  // -6663833312002
  s21_decimal dec_1 = {{0x8b6adb02, 0x60f, 0x0, 0x80000000}};
  // 437
  s21_decimal dec_2 = {{0x1b5, 0x0, 0x0, 0x0}};
  // -6663833312439
  s21_decimal dec_check = {{0x8b6adcb7, 0x60f, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_311) {
  // 2483664009032847
  s21_decimal dec_1 = {{0x16fff48f, 0x8d2e1, 0x0, 0x0}};
  // -137912693746964669355126
  s21_decimal dec_2 = {{0xc8ff5476, 0x43198e18, 0x1d34, 0x80000000}};
  // 137912696230628678387973
  s21_decimal dec_check = {{0xdfff4905, 0x432260f9, 0x1d34, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_312) {
  // 4469281706609192696
  s21_decimal dec_1 = {{0x6b97aef8, 0x3e061408, 0x0, 0x0}};
  // 48365895171908082824
  s21_decimal dec_2 = {{0xc55c9c88, 0x9f362d67, 0x2, 0x0}};
  // -43896613465298890128
  s21_decimal dec_check = {{0x59c4ed90, 0x6130195f, 0x2, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_313) {
  // 943658756309397
  s21_decimal dec_1 = {{0xacf58195, 0x35a40, 0x0, 0x0}};
  // -6870909927458269.102734
  s21_decimal dec_2 = {{0xdf19028e, 0x7907af61, 0x174, 0x80060000}};
  // 7814568683767666.102734
  s21_decimal dec_check = {{0xff9cd1ce, 0xa0ed0e86, 0x1a7, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_314) {
  // -1531442415836791
  s21_decimal dec_1 = {{0xb9309e77, 0x570d6, 0x0, 0x80000000}};
  // -7304533174259276461203
  s21_decimal dec_2 = {{0xd4ae3493, 0xfac2ece9, 0x18b, 0x80000000}};
  // 7304531642816860624412
  s21_decimal dec_check = {{0x1b7d961c, 0xfabd7c13, 0x18b, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_315) {
  // -17786331.5
  s21_decimal dec_1 = {{0xa99fa93, 0x0, 0x0, 0x80010000}};
  // 9787499456469.08333543067571
  s21_decimal dec_2 = {{0x3570fb3, 0xde99049e, 0x3299a5c, 0xe0000}};
  // -9787517242800.58333543067571
  s21_decimal dec_check = {{0x9f68efb3, 0x4a1756f0, 0x3299abd, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_316) {
  // 69620730.1746
  s21_decimal dec_1 = {{0x19305c72, 0xa2, 0x0, 0x40000}};
  // -90635442181
  s21_decimal dec_2 = {{0x1a4b1805, 0x15, 0x0, 0x80000000}};
  // 90705062911.1746
  s21_decimal dec_check = {{0x2e8a9fc2, 0x338f5, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_317) {
  // 2597178167199773121
  s21_decimal dec_1 = {{0x5a57b1c1, 0x240b07c8, 0x0, 0x0}};
  // -6.28515
  s21_decimal dec_2 = {{0x99723, 0x0, 0x0, 0x80050000}};
  // 2597178167199773127.28515
  s21_decimal dec_check = {{0xfa4b5c3, 0x54c016da, 0x36ff, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_318) {
  // 1.147215382
  s21_decimal dec_1 = {{0x44611e16, 0x0, 0x0, 0x90000}};
  // -0.688735862985
  s21_decimal dec_2 = {{0x5bdb40c9, 0xa0, 0x0, 0x800c0000}};
  // 1.835951244985
  s21_decimal dec_check = {{0x7738c6b9, 0x1ab, 0x0, 0xc0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_319) {
  // -563051968057977563361662
  s21_decimal dec_1 = {{0xf571b17e, 0x1bbccb8c, 0x773b, 0x80000000}};
  // -7.5422775056467588
  s21_decimal dec_2 = {{0x43370684, 0x10bf49d, 0x0, 0x80100000}};
  // -563051968057977563361654.45772
  s21_decimal dec_check = {{0x9b69608c, 0xf417f604, 0xb5ee9132, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_320) {
  // -2870173.07200774950986476
  s21_decimal dec_1 = {{0xdcb1a2ec, 0x3d49583c, 0x3cc7, 0x80110000}};
  // -2256930218
  s21_decimal dec_2 = {{0x868605aa, 0x0, 0x0, 0x80000000}};
  // 2254060044.92799225049013524
  s21_decimal dec_check = {{0xf2f25d14, 0xfcf555c0, 0xba7393, 0x110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_321) {
  // 3.4869
  s21_decimal dec_1 = {{0x8835, 0x0, 0x0, 0x40000}};
  // -1580364047026
  s21_decimal dec_2 = {{0xf509a2b2, 0x16f, 0x0, 0x80000000}};
  // 1580364047029.4869
  s21_decimal dec_check = {{0xc863d155, 0x382553, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_322) {
  // -9152950
  s21_decimal dec_1 = {{0x8ba9b6, 0x0, 0x0, 0x80000000}};
  // -84642
  s21_decimal dec_2 = {{0x14aa2, 0x0, 0x0, 0x80000000}};
  // -9068308
  s21_decimal dec_check = {{0x8a5f14, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_323) {
  // 484555163123638534534.39
  s21_decimal dec_1 = {{0x415c987f, 0xc75f9dc4, 0xa42, 0x20000}};
  // 603590625002
  s21_decimal dec_2 = {{0x88ce06ea, 0x8c, 0x0, 0x0}};
  // 484555162520047909532.39
  s21_decimal dec_check = {{0xd0e1e517, 0xc75f66de, 0xa42, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_324) {
  // 871484413
  s21_decimal dec_1 = {{0x33f1cbfd, 0x0, 0x0, 0x0}};
  // 75.1
  s21_decimal dec_2 = {{0x2ef, 0x0, 0x0, 0x10000}};
  // 871484337.9
  s21_decimal dec_check = {{0x771f4f3, 0x2, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_326) {
  // 858650802.737356145
  s21_decimal dec_1 = {{0x13439d71, 0xbea8a5b, 0x0, 0x90000}};
  // 765763936114822361447695109
  s21_decimal dec_2 = {{0xfbdc8305, 0x28473e08, 0x2796cd2, 0x0}};
  // -765763936114822360589044306.26
  s21_decimal dec_check = {{0x642e0822, 0xbbd43b6e, 0xf76e8217, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_327) {
  // 79
  s21_decimal dec_1 = {{0x4f, 0x0, 0x0, 0x0}};
  // 10701611439.140316408456513630
  s21_decimal dec_2 = {{0x391885e, 0x9211b771, 0x22942a5e, 0x120000}};
  // -10701611360.140316408456513630
  s21_decimal dec_check = {{0x5bb5885e, 0x49b95600, 0x22942a5a, 0x80120000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_328) {
  // -4
  s21_decimal dec_1 = {{0x4, 0x0, 0x0, 0x80000000}};
  // -9196615816687303660569711
  s21_decimal dec_2 = {{0xcffe846f, 0x8ada9e36, 0x79b75, 0x80000000}};
  // 9196615816687303660569707
  s21_decimal dec_check = {{0xcffe846b, 0x8ada9e36, 0x79b75, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_329) {
  // -49
  s21_decimal dec_1 = {{0x31, 0x0, 0x0, 0x80000000}};
  // 256277315133665245197097
  s21_decimal dec_2 = {{0xdce8f329, 0xd2330aa8, 0x3644, 0x0}};
  // -256277315133665245197146
  s21_decimal dec_check = {{0xdce8f35a, 0xd2330aa8, 0x3644, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_330) {
  // 53450
  s21_decimal dec_1 = {{0xd0ca, 0x0, 0x0, 0x0}};
  // 0.335278866358
  s21_decimal dec_2 = {{0x102d7fb6, 0x4e, 0x0, 0xc0000}};
  // 53449.664721133642
  s21_decimal dec_check = {{0xd711204a, 0xbde42f, 0x0, 0xc0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_331) {
  // 2453342688916425491975673444
  s21_decimal dec_1 = {{0x23d29664, 0xa8a29642, 0x7ed5b85, 0x0}};
  // -999202338297756.645
  s21_decimal dec_2 = {{0x90fa3be5, 0xddde13b, 0x0, 0x80030000}};
  // 2453342688917424694313971200.6
  s21_decimal dec_check = {{0xa28e4c06, 0x967d5e46, 0x4f459338, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_332) {
  // 233722267643332576557
  s21_decimal dec_1 = {{0xa39cc52d, 0xab8c4c1b, 0xc, 0x0}};
  // 98
  s21_decimal dec_2 = {{0x62, 0x0, 0x0, 0x0}};
  // 233722267643332576459
  s21_decimal dec_check = {{0xa39cc4cb, 0xab8c4c1b, 0xc, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_333) {
  // 698683236943501
  s21_decimal dec_1 = {{0xde26068d, 0x27b72, 0x0, 0x0}};
  // -5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 698683236943506
  s21_decimal dec_check = {{0xde260692, 0x27b72, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_334) {
  // 7400.78649177623718361
  s21_decimal dec_1 = {{0x833369d9, 0x1ea78a52, 0x28, 0x110000}};
  // -4680747150871191253391175101
  s21_decimal dec_2 = {{0x3f46edbd, 0x7dd28da0, 0xf1fd2c3, 0x80000000}};
  // 4680747150871191253391182501.8
  s21_decimal dec_check = {{0x78c66a7a, 0xea398842, 0x973e3ba2, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_335) {
  // -67582603
  s21_decimal dec_1 = {{0x4073a8b, 0x0, 0x0, 0x80000000}};
  // -8470448442220297592748222
  s21_decimal dec_2 = {{0x373bb8be, 0xee1e401d, 0x701af, 0x80000000}};
  // 8470448442220297525165619
  s21_decimal dec_check = {{0x33347e33, 0xee1e401d, 0x701af, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_336) {
  // -65092669986053
  s21_decimal dec_1 = {{0x9178d505, 0x3b33, 0x0, 0x80000000}};
  // -925.4
  s21_decimal dec_2 = {{0x2426, 0x0, 0x0, 0x80010000}};
  // -65092669985127.6
  s21_decimal dec_check = {{0xaeb82e0c, 0x25003, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_337) {
  // 1971856635330.77
  s21_decimal dec_1 = {{0xdd6e0015, 0xb356, 0x0, 0x20000}};
  // 630257502966033752574.9972
  s21_decimal dec_2 = {{0xda7ff8d4, 0x46e78a6e, 0x5369f, 0x40000}};
  // -630257500994177117244.2272
  s21_decimal dec_check = {{0x5b87f0a0, 0x46a17c80, 0x5369f, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_338) {
  // 983625334548861.14
  s21_decimal dec_1 = {{0xf9c934e2, 0x15d7433, 0x0, 0x20000}};
  // 64404754
  s21_decimal dec_2 = {{0x3d6bd12, 0x0, 0x0, 0x0}};
  // 983625270144107.14
  s21_decimal dec_check = {{0x79e759da, 0x15d7432, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_339) {
  // 5633636387097947279
  s21_decimal dec_1 = {{0x1eb02c8f, 0x4e2eb272, 0x0, 0x0}};
  // -3874230
  s21_decimal dec_2 = {{0x3b1db6, 0x0, 0x0, 0x80000000}};
  // 5633636387101821509
  s21_decimal dec_check = {{0x1eeb4a45, 0x4e2eb272, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_340) {
  // -90827092.2999
  s21_decimal dec_1 = {{0x792a6cf7, 0xd3, 0x0, 0x80040000}};
  // 78738146173635494859
  s21_decimal dec_2 = {{0xb85383cb, 0x44b616c5, 0x4, 0x0}};
  // -78738146173726321951.2999
  s21_decimal dec_check = {{0xb77696a7, 0x8d98c43, 0xa6bc, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_341) {
  // 82515321138673
  s21_decimal dec_1 = {{0x1867adf1, 0x4b0c, 0x0, 0x0}};
  // 925198629.26326831136
  s21_decimal dec_2 = {{0xe78b1820, 0x3f89523, 0x5, 0xb0000}};
  // 82514395940043.73673168864
  s21_decimal dec_check = {{0x32d4fe0, 0x6fcb6a57, 0x6d34f, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_342) {
  // 791350
  s21_decimal dec_1 = {{0xc1336, 0x0, 0x0, 0x0}};
  // 828960264932510995344146635
  s21_decimal dec_2 = {{0x75c240cb, 0x1d7d1ab, 0x2adb32a, 0x0}};
  // -828960264932510995343355285
  s21_decimal dec_check = {{0x75b62d95, 0x1d7d1ab, 0x2adb32a, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_343) {
  // 9267.45
  s21_decimal dec_1 = {{0xe2419, 0x0, 0x0, 0x20000}};
  // -1955336857696517
  s21_decimal dec_2 = {{0x56d1b905, 0x6f25e, 0x0, 0x80000000}};
  // 1955336857705784.45
  s21_decimal dec_check = {{0xe9fa6a0d, 0x2b6acd9, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_344) {
  // 76775615
  s21_decimal dec_1 = {{0x49380bf, 0x0, 0x0, 0x0}};
  // 26700415657962
  s21_decimal dec_2 = {{0xacca67ea, 0x1848, 0x0, 0x0}};
  // -26700338882347
  s21_decimal dec_check = {{0xa836e72b, 0x1848, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_345) {
  // 421747797483.976555308281
  s21_decimal dec_1 = {{0x1e9124f9, 0xfe712014, 0x594e, 0xc0000}};
  // -1567549771850381465
  s21_decimal dec_2 = {{0x56e2f899, 0x15c10e36, 0x0, 0x80000000}};
  // 1567550193598178948.9765553083
  s21_decimal dec_check = {{0xfe0c13bb, 0xb08a3cdc, 0x32a678a6, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_346) {
  // 651308439517.654553
  s21_decimal dec_1 = {{0x30a9ee19, 0x909e993, 0x0, 0x60000}};
  // 1299
  s21_decimal dec_2 = {{0x513, 0x0, 0x0, 0x0}};
  // 651308438218.654553
  s21_decimal dec_check = {{0xe33cc359, 0x909e992, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_347) {
  // -55750921713586454038099
  s21_decimal dec_1 = {{0xd4968653, 0x43762d76, 0xbce, 0x80000000}};
  // 726392702
  s21_decimal dec_2 = {{0x2b4bdf7e, 0x0, 0x0, 0x0}};
  // -55750921713587180430801
  s21_decimal dec_check = {{0xffe265d1, 0x43762d76, 0xbce, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_348) {
  // 76883115703457754
  s21_decimal dec_1 = {{0x50bad7da, 0x11124c9, 0x0, 0x0}};
  // 867911312372.4164
  s21_decimal dec_2 = {{0x7eb47b84, 0x1ed59b, 0x0, 0x40000}};
  // 76882247792145381.5836
  s21_decimal dec_check = {{0x3db381c, 0xad8e2246, 0x29, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_350) {
  // -999962223847123533.2844196839
  s21_decimal dec_1 = {{0xd28293e7, 0xbfce7145, 0x204f7e5f, 0x800a0000}};
  // 6841397409412883
  s21_decimal dec_2 = {{0xf65af713, 0x184e36, 0x0, 0x0}};
  // -1006803621256536416.2844196839
  s21_decimal dec_check = {{0xb0607fe7, 0xb75fc1cf, 0x20881598, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_351) {
  // 43784
  s21_decimal dec_1 = {{0xab08, 0x0, 0x0, 0x0}};
  // 967823248010486704254.19036
  s21_decimal dec_2 = {{0xcfd18d1c, 0x5722cc6f, 0x500e74, 0x50000}};
  // -967823248010486660470.19036
  s21_decimal dec_check = {{0xcad8781c, 0x5722cc6e, 0x500e74, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_352) {
  // -738592
  s21_decimal dec_1 = {{0xb4520, 0x0, 0x0, 0x80000000}};
  // 4683776528087711564974097
  s21_decimal dec_2 = {{0xaa144811, 0x8cbc82c, 0x3dfd4, 0x0}};
  // -4683776528087711565712689
  s21_decimal dec_check = {{0xaa1f8d31, 0x8cbc82c, 0x3dfd4, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_353) {
  // -257
  s21_decimal dec_1 = {{0x101, 0x0, 0x0, 0x80000000}};
  // 95527343363.5050763277
  s21_decimal dec_2 = {{0xb0e4340d, 0xc914fea2, 0x33, 0xa0000}};
  // -95527343620.5050763277
  s21_decimal dec_check = {{0x10d4180d, 0xc91500f9, 0x33, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_354) {
  // -993334.70
  s21_decimal dec_1 = {{0x5ebb55e, 0x0, 0x0, 0x80020000}};
  // 683279593908
  s21_decimal dec_2 = {{0x16a331b4, 0x9f, 0x0, 0x0}};
  // -683280587242.70
  s21_decimal dec_check = {{0xddab1fae, 0x3e24, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_356) {
  // -0.76010903
  s21_decimal dec_1 = {{0x487d597, 0x0, 0x0, 0x80080000}};
  // 93973119509.376245037617167021
  s21_decimal dec_2 = {{0xcae0baad, 0x5d833459, 0x2fa4be18, 0x120000}};
  // -93973119510.136354067617167021
  s21_decimal dec_check = {{0x7e9836ad, 0x680fa77c, 0x2fa4be18, 0x80120000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_357) {
  // -3.42
  s21_decimal dec_1 = {{0x156, 0x0, 0x0, 0x80020000}};
  // 6372550595781762822371516.6
  s21_decimal dec_2 = {{0x3045b75e, 0x99a0d24e, 0x34b666, 0x10000}};
  // -6372550595781762822371520.02
  s21_decimal dec_check = {{0xe2b92b02, 0x48370d, 0x20f2002, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_358) {
  // -603337981018666736419539
  s21_decimal dec_1 = {{0x5a5e02d3, 0x47a1ada, 0x7fc3, 0x80000000}};
  // -13974130972519705050.6951897
  s21_decimal dec_2 = {{0xe774bcd9, 0x945a347c, 0x73975f, 0x80070000}};
  // -603324006887694216714488.30481
  s21_decimal dec_check = {{0xe3f1e211, 0xe6c7e35f, 0xc2f1caca, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_359) {
  // 745104706577594984
  s21_decimal dec_1 = {{0x6c077a68, 0xa5724c8, 0x0, 0x0}};
  // -12.985432469513860
  s21_decimal dec_2 = {{0x9999a684, 0x2e222e, 0x0, 0x800f0000}};
  // 745104706577594996.98543246951
  s21_decimal dec_check = {{0xca13be67, 0xc5884c, 0xf0c19de4, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_360) {
  // -28473063.27
  s21_decimal dec_1 = {{0xa9b67257, 0x0, 0x0, 0x80020000}};
  // -542461183981572372.22029
  s21_decimal dec_2 = {{0xf8077a8d, 0xb01edade, 0xb7c, 0x80050000}};
  // 542461183953099308.95029
  s21_decimal dec_check = {{0x758d6b5, 0xb01ed848, 0xb7c, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_361) {
  // 0.14035139451557663322495381
  s21_decimal dec_1 = {{0x871d5995, 0x6f296be5, 0xb9c0e, 0x1a0000}};
  // -270048854811779746605.3
  s21_decimal dec_2 = {{0x2bb0efc5, 0x64ce9ab6, 0x92, 0x80010000}};
  // 270048854811779746605.44035139
  s21_decimal dec_check = {{0xe2c37943, 0x521e09bd, 0x5741eaef, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_362) {
  // -915177572.93
  s21_decimal dec_1 = {{0x4ee2276d, 0x15, 0x0, 0x80020000}};
  // -4596011153
  s21_decimal dec_2 = {{0x11f19091, 0x1, 0x0, 0x80000000}};
  // 3680833580.07
  s21_decimal dec_check = {{0xb37a5137, 0x55, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_363) {
  // 738596611
  s21_decimal dec_1 = {{0x2c061703, 0x0, 0x0, 0x0}};
  // 80342727133051250159037333
  s21_decimal dec_2 = {{0x4d62ab95, 0xf70dba32, 0x42753b, 0x0}};
  // -80342727133051249420440722
  s21_decimal dec_check = {{0x215c9492, 0xf70dba32, 0x42753b, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_364) {
  // 2015906494377993.09767529727
  s21_decimal dec_1 = {{0xefded4ff, 0xeff234, 0xa6c07b, 0xb0000}};
  // 83622821366155.659021
  s21_decimal dec_2 = {{0xd5a7470d, 0x887ff0fa, 0x4, 0x60000}};
  // 1932283673011837.43865429727
  s21_decimal dec_check = {{0x91149edf, 0xc7db33f2, 0x9fd5b2, 0xb0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_365) {
  // -304039
  s21_decimal dec_1 = {{0x4a3a7, 0x0, 0x0, 0x80000000}};
  // -5228851022209
  s21_decimal dec_2 = {{0x6fcec981, 0x4c1, 0x0, 0x80000000}};
  // 5228850718170
  s21_decimal dec_check = {{0x6fca25da, 0x4c1, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_366) {
  // 716084
  s21_decimal dec_1 = {{0xaed34, 0x0, 0x0, 0x0}};
  // -6547817890507331804145541
  s21_decimal dec_2 = {{0xea152785, 0xeb49e668, 0x56a8d, 0x80000000}};
  // 6547817890507331804861625
  s21_decimal dec_check = {{0xea2014b9, 0xeb49e668, 0x56a8d, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_367) {
  // -2934031435207463289393.25
  s21_decimal dec_1 = {{0xe61db3d, 0x6a9163a4, 0x3e21, 0x80020000}};
  // -39761189369524162692677
  s21_decimal dec_2 = {{0xb5a48645, 0x75595bc5, 0x86b, 0x80000000}};
  // 36827157934316699403283.75
  s21_decimal dec_check = {{0xe5e297b7, 0x6c567596, 0x30bd8, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_368) {
  // -49229809.651
  s21_decimal dec_1 = {{0x765347f3, 0xb, 0x0, 0x80030000}};
  // 575591139944243452695.05
  s21_decimal dec_2 = {{0x46759501, 0x492ba0ac, 0xc30, 0x20000}};
  // -575591139944292682504.701
  s21_decimal dec_check = {{0x36eb19fd, 0xdbb446c6, 0x79e2, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_369) {
  // 954.7
  s21_decimal dec_1 = {{0x254b, 0x0, 0x0, 0x10000}};
  // 4206878204.9680
  s21_decimal dec_2 = {{0xe6cf6990, 0x2642, 0x0, 0x40000}};
  // -4206877250.2680
  s21_decimal dec_check = {{0xe63dbc98, 0x2642, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_370) {
  // 151.79646901
  s21_decimal dec_1 = {{0x88c707b5, 0x3, 0x0, 0x80000}};
  // -5602557.057758
  s21_decimal dec_2 = {{0x726c5ade, 0x518, 0x0, 0x80060000}};
  // 5602708.85422701
  s21_decimal dec_check = {{0x3b1a866d, 0x1fd90, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_371) {
  // 90469348702495859637779422
  s21_decimal dec_1 = {{0x2af47bde, 0x38678786, 0x4ad5a1, 0x0}};
  // 577424
  s21_decimal dec_2 = {{0x8cf90, 0x0, 0x0, 0x0}};
  // 90469348702495859637201998
  s21_decimal dec_check = {{0x2aebac4e, 0x38678786, 0x4ad5a1, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_372) {
  // -9765737300317275597104294322
  s21_decimal dec_1 = {{0xd61d29b2, 0xd8a975e5, 0x1f8e074f, 0x80000000}};
  // -9373949356603192857791167713
  s21_decimal dec_2 = {{0x1ee1fce1, 0xdc23516c, 0x1e49f2fc, 0x80000000}};
  // -391787943714082739313126609
  s21_decimal dec_check = {{0xb73b2cd1, 0xfc862479, 0x1441452, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_373) {
  // -2140760117
  s21_decimal dec_1 = {{0x7f996835, 0x0, 0x0, 0x80000000}};
  // -86495153.1
  s21_decimal dec_2 = {{0x338e1ceb, 0x0, 0x0, 0x80010000}};
  // -2054264963.9
  s21_decimal dec_check = {{0xc86ff527, 0x4, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_374) {
  // 36844080197047074871
  s21_decimal dec_1 = {{0x1cfec037, 0xff5077bb, 0x1, 0x0}};
  // 800.3856
  s21_decimal dec_2 = {{0x7a2110, 0x0, 0x0, 0x40000}};
  // 36844080197047074070.6144
  s21_decimal dec_check = {{0x9eba4360, 0x3744fd1c, 0x4e05, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_375) {
  // -62136546344364
  s21_decimal dec_1 = {{0x4ac5bdac, 0x3883, 0x0, 0x80000000}};
  // 20984929537.566071136
  s21_decimal dec_2 = {{0x433a5960, 0x2339723b, 0x1, 0x90000}};
  // -62157531273901.566071136
  s21_decimal dec_check = {{0x85c1160, 0x910798e6, 0xd29, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_376) {
  // -943430584102.270414
  s21_decimal dec_1 = {{0x23a7b5ce, 0xd17bd1e, 0x0, 0x80060000}};
  // -500581824043.418499497
  s21_decimal dec_2 = {{0x750db9a9, 0x22f7e4c5, 0x1b, 0x80090000}};
  // -442848760058.851914503
  s21_decimal dec_check = {{0xd2107307, 0x1c2d8f5, 0x18, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_377) {
  // 616694349589106
  s21_decimal dec_1 = {{0x57a46a72, 0x230e1, 0x0, 0x0}};
  // -36711807592021152565624385823
  s21_decimal dec_2 = {{0x20c1311f, 0x5b61a0e4, 0x769f4ba5, 0x80000000}};
  // 36711807592021769259973974929
  s21_decimal dec_check = {{0x78659b91, 0x5b63d1c5, 0x769f4ba5, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_378) {
  // 27.66806872
  s21_decimal dec_1 = {{0xa4ea1f58, 0x0, 0x0, 0x80000}};
  // -19851968
  s21_decimal dec_2 = {{0x12eeac0, 0x0, 0x0, 0x80000000}};
  // 19851995.66806872
  s21_decimal dec_check = {{0x4afcdf58, 0x70d87, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_381) {
  // -17799545826912383984726764.910
  s21_decimal dec_1 = {{0x5eaced6e, 0xbd5c0004, 0x39837070, 0x80030000}};
  // 681981749179206143
  s21_decimal dec_2 = {{0x9f2049ff, 0x976e2c9, 0x0, 0x0}};
  // -17799546508894133163932907.910
  s21_decimal dec_check = {{0xf4cdf986, 0xb5c1e399, 0x39837095, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_382) {
  // 96295507762.5360582912561
  s21_decimal dec_1 = {{0xb2672a31, 0xe63c599a, 0xcbe9, 0xd0000}};
  // -47836755343282829672199247335
  s21_decimal dec_2 = {{0xd43c55e7, 0x6469dc8b, 0x9a91a2f7, 0x80000000}};
  // 47836755343282829768494755098
  s21_decimal dec_check = {{0x3fe52d1a, 0x6469dca2, 0x9a91a2f7, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_383) {
  // 2028850705050472406874.628
  s21_decimal dec_1 = {{0xb2107a04, 0x379413ac, 0x1ada0, 0x30000}};
  // -646501658119395642.1050231668
  s21_decimal dec_2 = {{0xb8eeb74, 0x1fcfd17e, 0x14e3bc83, 0x800a0000}};
  // 2029497206708591802516.7330232
  s21_decimal dec_check = {{0x3692dbb8, 0x488a37f4, 0x41939b80, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_384) {
  // 7934048219165904678640781405
  s21_decimal dec_1 = {{0xcb81885d, 0xca8d76da, 0x19a2e40f, 0x0}};
  // -46494
  s21_decimal dec_2 = {{0xb59e, 0x0, 0x0, 0x80000000}};
  // 7934048219165904678640827899
  s21_decimal dec_check = {{0xcb823dfb, 0xca8d76da, 0x19a2e40f, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_385) {
  // 70
  s21_decimal dec_1 = {{0x46, 0x0, 0x0, 0x0}};
  // -0.731105151713071338
  s21_decimal dec_2 = {{0xd50d0ea, 0xa256843, 0x0, 0x80120000}};
  // 70.731105151713071338
  s21_decimal dec_check = {{0xd2a8d0ea, 0xd5975d62, 0x3, 0x120000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_386) {
  // -781
  s21_decimal dec_1 = {{0x30d, 0x0, 0x0, 0x80000000}};
  // -9794318.4001248
  s21_decimal dec_2 = {{0x2cb0c8e0, 0x5914, 0x0, 0x80070000}};
  // 9793537.4001248
  s21_decimal dec_check = {{0x5b2da460, 0x5912, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_387) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // 7021806543553.5626727841264
  s21_decimal dec_2 = {{0x68c7ddf0, 0xf463bc6f, 0x3a1540, 0xd0000}};
  // -7021806543553.5626727841264
  s21_decimal dec_check = {{0x68c7ddf0, 0xf463bc6f, 0x3a1540, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_388) {
  // -77800812904178700971162.3010
  s21_decimal dec_1 = {{0xf67a4b62, 0x2f98bdf1, 0x2838da1, 0x80040000}};
  // 27056461284461305
  s21_decimal dec_2 = {{0x4bbd4af9, 0x601fb5, 0x0, 0x0}};
  // -77800839960639985432467.3010
  s21_decimal dec_check = {{0x88bae9f2, 0xda6f57d0, 0x2838daf, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_389) {
  // -79
  s21_decimal dec_1 = {{0x4f, 0x0, 0x0, 0x80000000}};
  // -49320468.76764559
  s21_decimal dec_2 = {{0xa61ae98f, 0x1185ab, 0x0, 0x80080000}};
  // 49320389.76764559
  s21_decimal dec_check = {{0xcf3a7a8f, 0x1185a9, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_390) {
  // -321466535806477956223397
  s21_decimal dec_1 = {{0xfd9711a5, 0xbc5f0949, 0x4412, 0x80000000}};
  // 1483568294
  s21_decimal dec_2 = {{0x586d74a6, 0x0, 0x0, 0x0}};
  // -321466535806479439791691
  s21_decimal dec_check = {{0x5604864b, 0xbc5f094a, 0x4412, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_391) {
  // -249525
  s21_decimal dec_1 = {{0x3ceb5, 0x0, 0x0, 0x80000000}};
  // -16279337901159
  s21_decimal dec_2 = {{0x54271c67, 0xece, 0x0, 0x80000000}};
  // 16279337651634
  s21_decimal dec_check = {{0x54234db2, 0xece, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_392) {
  // 3279084774568953
  s21_decimal dec_1 = {{0x6b2d33f9, 0xba64f, 0x0, 0x0}};
  // 8761309222646651863687
  s21_decimal dec_2 = {{0x6774c287, 0xf3971e97, 0x1da, 0x0}};
  // -8761305943561877294734
  s21_decimal dec_check = {{0xfc478e8e, 0xf38b7847, 0x1da, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_393) {
  // 159138024663.55237785
  s21_decimal dec_1 = {{0x38d6d399, 0xdcd92f07, 0x0, 0x80000}};
  // -77705535
  s21_decimal dec_2 = {{0x4a1b13f, 0x0, 0x0, 0x80000000}};
  // 159215730198.55237785
  s21_decimal dec_check = {{0x31ea3299, 0xdcf4ca4e, 0x0, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_394) {
  // 84384597444.5
  s21_decimal dec_1 = {{0x7923b9ad, 0xc4, 0x0, 0x10000}};
  // 2661653501.70
  s21_decimal dec_2 = {{0xf8b0ef1a, 0x3d, 0x0, 0x20000}};
  // 81722943942.80
  s21_decimal dec_check = {{0xc2b451a8, 0x76e, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_395) {
  // -1847217899600872402486554
  s21_decimal dec_1 = {{0x3f52851a, 0xe20ba31c, 0x18729, 0x80000000}};
  // -23.9171
  s21_decimal dec_2 = {{0x3a643, 0x0, 0x0, 0x80040000}};
  // -1847217899600872402486530.0829
  s21_decimal dec_check = {{0x876ba15d, 0xe6937f69, 0x3bafd40d, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_396) {
  // 179824761889303049688357
  s21_decimal dec_1 = {{0x46325525, 0x51e359e6, 0x2614, 0x0}};
  // -3946717220352690504081547010
  s21_decimal dec_2 = {{0x1d7f1f02, 0x39807e8d, 0xcc0a5e1, 0x80000000}};
  // 3946897045114579807131235367
  s21_decimal dec_check = {{0x63b17427, 0x8b63d873, 0xcc0cbf5, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_397) {
  // 0.75
  s21_decimal dec_1 = {{0x4b, 0x0, 0x0, 0x20000}};
  // 4533371397173577357
  s21_decimal dec_2 = {{0x5372868d, 0x3ee9c544, 0x0, 0x0}};
  // -4533371397173577356.25
  s21_decimal dec_check = {{0x98bc8ec9, 0x93510eb0, 0x18, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_398) {
  // 701392892415.2
  s21_decimal dec_1 = {{0xebdf3f8, 0x661, 0x0, 0x10000}};
  // 2165872178737777432630097
  s21_decimal dec_2 = {{0xaf909351, 0x2a83ef65, 0x1caa4, 0x0}};
  // -2165872178737076039737681.8
  s21_decimal dec_check = {{0xcce7cd32, 0xa9275397, 0x11ea69, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_399) {
  // -10603404550519603215870
  s21_decimal dec_1 = {{0xd9723dfe, 0xcfcc6373, 0x23e, 0x80000000}};
  // -75
  s21_decimal dec_2 = {{0x4b, 0x0, 0x0, 0x80000000}};
  // -10603404550519603215795
  s21_decimal dec_check = {{0xd9723db3, 0xcfcc6373, 0x23e, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_400) {
  // -943416135424715842553367
  s21_decimal dec_1 = {{0xd37a8617, 0xb0f11fde, 0xc7c6, 0x80000000}};
  // 787032713540049322921471
  s21_decimal dec_2 = {{0x47484dff, 0x20ff0ea5, 0xa6a9, 0x0}};
  // -1730448848964765165474838
  s21_decimal dec_check = {{0x1ac2d416, 0xd1f02e84, 0x16e6f, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_401) {
  // -79626344
  s21_decimal dec_1 = {{0x4bf0068, 0x0, 0x0, 0x80000000}};
  // 91890320058076955.918394140492
  s21_decimal dec_2 = {{0x69e7274c, 0xde260ad2, 0x28e9e427, 0xc0000}};
  // -91890320137703299.918394140492
  s21_decimal dec_check = {{0xbcf5a74c, 0x2f2fa4cf, 0x28e9e42c, 0x800c0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_402) {
  // 83229033902022235658
  s21_decimal dec_1 = {{0x18fa960a, 0x8308ed5e, 0x4, 0x0}};
  // 1586111.33041
  s21_decimal dec_2 = {{0xedf5d271, 0x24, 0x0, 0x50000}};
  // 83229033902020649546.66959
  s21_decimal dec_check = {{0x6f3b2fcf, 0x7f31b4b8, 0x6e271, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_403) {
  // 439036548
  s21_decimal dec_1 = {{0x1a2b2a84, 0x0, 0x0, 0x0}};
  // 560564619523058261
  s21_decimal dec_2 = {{0x2c52ea55, 0x7c7868d, 0x0, 0x0}};
  // -560564619084021713
  s21_decimal dec_check = {{0x1227bfd1, 0x7c7868d, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_404) {
  // -79228162514264337592781165902
  s21_decimal dec_1 = {{0xd288d54e, 0xffffffff, 0xffffffff, 0x80000000}};
  // -518131781772790.2913957
  s21_decimal dec_2 = {{0xd9cd95a5, 0xe13aaf6c, 0x118, 0x80070000}};
  // -79228162514263819460999393112
  s21_decimal dec_check = {{0xddbc2f58, 0xfffe28c2, 0xffffffff, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_405) {
  // -1867497108.3269473408
  s21_decimal dec_1 = {{0x88f80480, 0x32ad341, 0x1, 0x800a0000}};
  // -3749407067561
  s21_decimal dec_2 = {{0xfa138da9, 0x368, 0x0, 0x80000000}};
  // 3747539570452.6730526592
  s21_decimal dec_check = {{0x6b757f80, 0x8b96f01c, 0x7ef, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_406) {
  // 6385240.524199
  s21_decimal dec_1 = {{0xadfe45a7, 0x5ce, 0x0, 0x60000}};
  // -3530756237845
  s21_decimal dec_2 = {{0x1178aa15, 0x336, 0x0, 0x80000000}};
  // 3530762623085.524199
  s21_decimal dec_check = {{0x1f3d34e7, 0x30ffc9e6, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_407) {
  // 3476169.70680
  s21_decimal dec_1 = {{0xef9607b8, 0x50, 0x0, 0x50000}};
  // 682393303719.65441
  s21_decimal dec_2 = {{0x36881201, 0xf26f4f, 0x0, 0x50000}};
  // -682389827549.94761
  s21_decimal dec_check = {{0x46f20a49, 0xf26efe, 0x0, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_408) {
  // -752962.633
  s21_decimal dec_1 = {{0x2ce14c49, 0x0, 0x0, 0x80030000}};
  // -71011870339024.53
  s21_decimal dec_2 = {{0xf2a3ad75, 0x193a7d, 0x0, 0x80020000}};
  // 71011869586061.897
  s21_decimal dec_check = {{0x4d837a49, 0xfc48eb, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_409) {
  // -17.572
  s21_decimal dec_1 = {{0x44a4, 0x0, 0x0, 0x80030000}};
  // -81344470
  s21_decimal dec_2 = {{0x4d937d6, 0x0, 0x0, 0x80000000}};
  // 81344452.428
  s21_decimal dec_check = {{0xf081d74c, 0x12, 0x0, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_410) {
  // 6.14296
  s21_decimal dec_1 = {{0x95f98, 0x0, 0x0, 0x50000}};
  // -437741743774740
  s21_decimal dec_2 = {{0xb1241c14, 0x18e1f, 0x0, 0x80000000}};
  // 437741743774746.14296
  s21_decimal dec_check = {{0xb9616418, 0x5f7d1bab, 0x2, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_411) {
  // -212.950159
  s21_decimal dec_1 = {{0xcb15c8f, 0x0, 0x0, 0x80060000}};
  // 679310.6691628932824
  s21_decimal dec_2 = {{0x6bdf1ed8, 0x5e45f68b, 0x0, 0xd0000}};
  // -679523.6193218932824
  s21_decimal dec_check = {{0xa5b13058, 0x5e4d8750, 0x0, 0x800d0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_412) {
  // 84.4
  s21_decimal dec_1 = {{0x34c, 0x0, 0x0, 0x10000}};
  // 9625240553512517311860
  s21_decimal dec_2 = {{0xa5d51d74, 0xc90bc6b5, 0x209, 0x0}};
  // -9625240553512517311775.6
  s21_decimal dec_check = {{0x7a53233c, 0xda75c318, 0x1461, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_413) {
  // -7052.6740077284974418
  s21_decimal dec_1 = {{0xe05f52, 0xd2c1506f, 0x3, 0x80100000}};
  // 263474596778935641946008404
  s21_decimal dec_2 = {{0x31252b54, 0x82d8f897, 0xd9f0ea, 0x0}};
  // -263474596778935641946015456.67
  s21_decimal dec_check = {{0x328fafc3, 0x1cc11b0f, 0x55221b9b, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_414) {
  // -93472353
  s21_decimal dec_1 = {{0x5924661, 0x0, 0x0, 0x80000000}};
  // 3.226
  s21_decimal dec_2 = {{0xc9a, 0x0, 0x0, 0x30000}};
  // -93472356.226
  s21_decimal dec_check = {{0xc362f782, 0x15, 0x0, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_415) {
  // -546.422034
  s21_decimal dec_1 = {{0x2091bd12, 0x0, 0x0, 0x80060000}};
  // 338848557371752102910725
  s21_decimal dec_2 = {{0x366e5b05, 0x460d102, 0x47c1, 0x0}};
  // -338848557371752102911271.42203
  s21_decimal dec_check = {{0x26e4473b, 0x3aec004e, 0x6d7ce54e, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_416) {
  // 32264571051004677758
  s21_decimal dec_1 = {{0x57c4e7e, 0xbfc2c86d, 0x1, 0x0}};
  // -1514235448032.0503
  s21_decimal dec_2 = {{0x23dccff7, 0x35cbe4, 0x0, 0x80040000}};
  // 32264572565240125790.0503
  s21_decimal dec_check = {{0x6b96e9d7, 0xa8eaee8a, 0x4452, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_417) {
  // 3677650608675551998389755
  s21_decimal dec_1 = {{0x305c2dfb, 0xd6c74a66, 0x30ac5, 0x0}};
  // -76227
  s21_decimal dec_2 = {{0x129c3, 0x0, 0x0, 0x80000000}};
  // 3677650608675551998465982
  s21_decimal dec_check = {{0x305d57be, 0xd6c74a66, 0x30ac5, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_418) {
  // 2
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x0}};
  // 9035568134409011069815806
  s21_decimal dec_2 = {{0xe2d8bfe, 0x214ad94c, 0x7795b, 0x0}};
  // -9035568134409011069815804
  s21_decimal dec_check = {{0xe2d8bfc, 0x214ad94c, 0x7795b, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_420) {
  // -2506
  s21_decimal dec_1 = {{0x9ca, 0x0, 0x0, 0x80000000}};
  // -266840768767690442568688
  s21_decimal dec_2 = {{0xc20073f0, 0x7791433a, 0x3881, 0x80000000}};
  // 266840768767690442566182
  s21_decimal dec_check = {{0xc2006a26, 0x7791433a, 0x3881, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_421) {
  // 717
  s21_decimal dec_1 = {{0x2cd, 0x0, 0x0, 0x0}};
  // 526306
  s21_decimal dec_2 = {{0x807e2, 0x0, 0x0, 0x0}};
  // -525589
  s21_decimal dec_check = {{0x80515, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_422) {
  // 621.4518
  s21_decimal dec_1 = {{0x5ed376, 0x0, 0x0, 0x40000}};
  // 521731300321783765649281
  s21_decimal dec_2 = {{0x45d5c781, 0x1c474fc3, 0x6e7b, 0x0}};
  // -521731300321783765648659.5482
  s21_decimal dec_check = {{0xee624b9a, 0xa19bbbd7, 0x10dba900, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_423) {
  // 9.6858755
  s21_decimal dec_1 = {{0x5c5f283, 0x0, 0x0, 0x70000}};
  // -23
  s21_decimal dec_2 = {{0x17, 0x0, 0x0, 0x80000000}};
  // 32.6858755
  s21_decimal dec_check = {{0x137b7803, 0x0, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_424) {
  // -431.25
  s21_decimal dec_1 = {{0xa875, 0x0, 0x0, 0x80020000}};
  // -27
  s21_decimal dec_2 = {{0x1b, 0x0, 0x0, 0x80000000}};
  // -404.25
  s21_decimal dec_check = {{0x9de9, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_425) {
  // -3172
  s21_decimal dec_1 = {{0xc64, 0x0, 0x0, 0x80000000}};
  // 0.297582753
  s21_decimal dec_2 = {{0x11bcc0a1, 0x0, 0x0, 0x90000}};
  // -3172.297582753
  s21_decimal dec_check = {{0x9baba8a1, 0x2e2, 0x0, 0x80090000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_427) {
  // -73.995232177274
  s21_decimal dec_1 = {{0x5b876c7a, 0x434c, 0x0, 0x800c0000}};
  // -5372880011048212.46669612798
  s21_decimal dec_2 = {{0x290be6fe, 0xe7047a23, 0x1bc6f28, 0x800b0000}};
  // 5372880011048138.471463950706
  s21_decimal dec_check = {{0x3eef9972, 0x62c8213, 0x115c5799, 0xc0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_428) {
  // -258.547
  s21_decimal dec_1 = {{0x3f1f3, 0x0, 0x0, 0x80030000}};
  // -679102334.86917448376937932
  s21_decimal dec_2 = {{0xc3366dcc, 0x224f81e8, 0x382c8d, 0x80110000}};
  // 679102076.32217448376937932
  s21_decimal dec_check = {{0x48ebadcc, 0xbb81293e, 0x382c8b, 0x110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_429) {
  // 451574586329
  s21_decimal dec_1 = {{0x23f15bd9, 0x69, 0x0, 0x0}};
  // 94.794606031138392897
  s21_decimal dec_2 = {{0x251b0b41, 0x238a17f1, 0x5, 0x120000}};
  // 451574586234.20539396886160710
  s21_decimal dec_check = {{0xa110e546, 0x2bfdc9ff, 0x91e95fd1, 0x110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_430) {
  // 403303429870
  s21_decimal dec_1 = {{0xe6c1f6ee, 0x5d, 0x0, 0x0}};
  // 564277
  s21_decimal dec_2 = {{0x89c35, 0x0, 0x0, 0x0}};
  // 403302865593
  s21_decimal dec_check = {{0xe6b95ab9, 0x5d, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_431) {
  // -5653
  s21_decimal dec_1 = {{0x1615, 0x0, 0x0, 0x80000000}};
  // -1.906454
  s21_decimal dec_2 = {{0x1d1716, 0x0, 0x0, 0x80060000}};
  // -5651.093546
  s21_decimal dec_check = {{0x50d4d82a, 0x1, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_432) {
  // -52.3076029901
  s21_decimal dec_1 = {{0xc9c2cdcd, 0x79, 0x0, 0x800a0000}};
  // -4492884745658664690004585900
  s21_decimal dec_2 = {{0xa854edac, 0x1937a5c7, 0xe846d5a, 0x80000000}};
  // 4492884745658664690004585847.7
  s21_decimal dec_check = {{0x935146ad, 0xfc2c79cc, 0x912c4584, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_433) {
  // -0.3463360565912855323562989448
  s21_decimal dec_1 = {{0xf3ffd788, 0x7bb0d852, 0xb30d320, 0x801c0000}};
  // 21278338804853899780184
  s21_decimal dec_2 = {{0x3e97e058, 0x8045558b, 0x481, 0x0}};
  // -21278338804853899780184.346336
  s21_decimal dec_check = {{0xf2fc0ee0, 0xf48bf3d8, 0x44c10781, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_434) {
  // -414594681218885277
  s21_decimal dec_1 = {{0x7bd1669d, 0x5c0efaa, 0x0, 0x80000000}};
  // -2582536916602
  s21_decimal dec_2 = {{0x4b320e7a, 0x259, 0x0, 0x80000000}};
  // -414592098681968675
  s21_decimal dec_check = {{0x309f5823, 0x5c0ed51, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_435) {
  // -2446871267825885561613876
  s21_decimal dec_1 = {{0xf489ee34, 0x283f780c, 0x20625, 0x80000000}};
  // 209
  s21_decimal dec_2 = {{0xd1, 0x0, 0x0, 0x0}};
  // -2446871267825885561614085
  s21_decimal dec_check = {{0xf489ef05, 0x283f780c, 0x20625, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_436) {
  // -1961
  s21_decimal dec_1 = {{0x7a9, 0x0, 0x0, 0x80000000}};
  // -119.63227890231812
  s21_decimal dec_2 = {{0xcc3aa04, 0x2a807e, 0x0, 0x800e0000}};
  // -1841.36772109768188
  s21_decimal dec_check = {{0x2bb095fc, 0x28e2f6b, 0x0, 0x800e0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_437) {
  // 5.204726
  s21_decimal dec_1 = {{0x4f6af6, 0x0, 0x0, 0x60000}};
  // -679769471746.0459
  s21_decimal dec_2 = {{0xa2ecffeb, 0x182677, 0x0, 0x80040000}};
  // 679769471751.250626
  s21_decimal dec_check = {{0xa4e362c2, 0x96f06bb, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_438) {
  // 0.46661
  s21_decimal dec_1 = {{0xb645, 0x0, 0x0, 0x50000}};
  // -23766690068.90
  s21_decimal dec_2 = {{0x5c830c2a, 0x229, 0x0, 0x80020000}};
  // 23766690069.36661
  s21_decimal dec_check = {{0x5fe83a55, 0x87191, 0x0, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_439) {
  // -8274589678
  s21_decimal dec_1 = {{0xed3437ee, 0x1, 0x0, 0x80000000}};
  // -45076.6649932450
  s21_decimal dec_2 = {{0x4a0bbaa2, 0x199f8, 0x0, 0x800a0000}};
  // -8274544601.3350067550
  s21_decimal dec_check = {{0xb6fe3d5e, 0x7c52e0be, 0x4, 0x800a0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_440) {
  // 87497762
  s21_decimal dec_1 = {{0x5371c22, 0x0, 0x0, 0x0}};
  // -367384032736855
  s21_decimal dec_2 = {{0x42c47657, 0x14e22, 0x0, 0x80000000}};
  // 367384120234617
  s21_decimal dec_check = {{0x47fb9279, 0x14e22, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_441) {
  // -4673750780691128476896001
  s21_decimal dec_1 = {{0x1dc20b01, 0x8999ddab, 0x3ddb4, 0x80000000}};
  // -4
  s21_decimal dec_2 = {{0x4, 0x0, 0x0, 0x80000000}};
  // -4673750780691128476895997
  s21_decimal dec_check = {{0x1dc20afd, 0x8999ddab, 0x3ddb4, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_442) {
  // -3769927500168228087721
  s21_decimal dec_1 = {{0x979da7a9, 0x5e40ff78, 0xcc, 0x80000000}};
  // -7518.90
  s21_decimal dec_2 = {{0xb7912, 0x0, 0x0, 0x80020000}};
  // -3769927500168228080202.10
  s21_decimal dec_check = {{0x398a04f2, 0xd163cb1b, 0x4fd4, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_443) {
  // 39131805
  s21_decimal dec_1 = {{0x2551a9d, 0x0, 0x0, 0x0}};
  // -12.3
  s21_decimal dec_2 = {{0x7b, 0x0, 0x0, 0x80010000}};
  // 39131817.3
  s21_decimal dec_check = {{0x17530a9d, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_444) {
  // 304386521404418
  s21_decimal dec_1 = {{0x827b9402, 0x114d6, 0x0, 0x0}};
  // -41.003150166
  s21_decimal dec_2 = {{0x8bfa6b56, 0x9, 0x0, 0x80090000}};
  // 304386521404459.003150166
  s21_decimal dec_check = {{0x8df7ff56, 0xd38e3c72, 0x4074, 0x90000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_445) {
  // 306.6532012322077454693962
  s21_decimal dec_1 = {{0x5da4f64a, 0x892a801, 0x2895d, 0x160000}};
  // -159406234105.7415
  s21_decimal dec_2 = {{0x8f96ab87, 0x5a9ca, 0x0, 0x80040000}};
  // 159406234412.39470123220774547
  s21_decimal dec_check = {{0xd388ae93, 0x49cb60ef, 0x3381c650, 0x110000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_446) {
  // 480688458119441899
  s21_decimal dec_1 = {{0x19d6edeb, 0x6abbf9b, 0x0, 0x0}};
  // 2.01415879
  s21_decimal dec_2 = {{0xc015cc7, 0x0, 0x0, 0x80000}};
  // 480688458119441896.98584121
  s21_decimal dec_check = {{0x24012e39, 0x5a583f0d, 0x27c2f9, 0x80000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_447) {
  // -6011488484047359656058450.8
  s21_decimal dec_1 = {{0x5aa6af3c, 0x6fe84475, 0x31b9d2, 0x80010000}};
  // -275455.905419551271688297
  s21_decimal dec_2 = {{0x8eda1869, 0x7e9b1725, 0x3a54, 0x80120000}};
  // -6011488484047359655782994.8946
  s21_decimal dec_check = {{0x76ed4612, 0x234b6a69, 0xc23dde05, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_448) {
  // 3250933398059475208526
  s21_decimal dec_1 = {{0xc97094e, 0x3bc38d5a, 0xb0, 0x0}};
  // 117211301
  s21_decimal dec_2 = {{0x6fc80a5, 0x0, 0x0, 0x0}};
  // 3250933398059357997225
  s21_decimal dec_check = {{0x59a88a9, 0x3bc38d5a, 0xb0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_449) {
  // 6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x0}};
  // -85845240
  s21_decimal dec_2 = {{0x51de4f8, 0x0, 0x0, 0x80000000}};
  // 85845246
  s21_decimal dec_check = {{0x51de4fe, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_450) {
  // -7745846771631409217662.8885
  s21_decimal dec_1 = {{0x36775c95, 0xf2e2ad13, 0x401277, 0x80040000}};
  // 2370287373220849095
  s21_decimal dec_2 = {{0xc06c25c7, 0x20e4f3ce, 0x0, 0x0}};
  // -7748217059004630066757.8885
  s21_decimal dec_check = {{0xb6fb0a05, 0xe256694f, 0x40177c, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_451) {
  // -448327.363
  s21_decimal dec_1 = {{0x1ab8eec3, 0x0, 0x0, 0x80030000}};
  // 8253484649553152757030.470
  s21_decimal dec_2 = {{0x2a015e46, 0x4ca43cc9, 0x6d3be, 0x30000}};
  // -8253484649553153205357.833
  s21_decimal dec_check = {{0x44ba4d09, 0x4ca43cc9, 0x6d3be, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_452) {
  // -73409542832
  s21_decimal dec_1 = {{0x178cbab0, 0x11, 0x0, 0x80000000}};
  // 345154948305144566172743
  s21_decimal dec_2 = {{0xe852cc47, 0xe322263c, 0x4916, 0x0}};
  // -345154948305217975715575
  s21_decimal dec_check = {{0xffdf86f7, 0xe322264d, 0x4916, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_453) {
  // -58151084398
  s21_decimal dec_1 = {{0x8a13216e, 0xd, 0x0, 0x80000000}};
  // 35312360948.5
  s21_decimal dec_2 = {{0x37ceab8d, 0x52, 0x0, 0x10000}};
  // -93463445346.5
  s21_decimal dec_check = {{0x9c8df9d9, 0xd9, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_454) {
  // -81264804098214056293193344
  s21_decimal dec_1 = {{0x2d5e5680, 0xdb84c4a1, 0x43387d, 0x80000000}};
  // 20567719785493
  s21_decimal dec_2 = {{0xcba1b415, 0x12b4, 0x0, 0x0}};
  // -81264804098234624012978837
  s21_decimal dec_check = {{0xf9000a95, 0xdb84d755, 0x43387d, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_455) {
  // -16
  s21_decimal dec_1 = {{0x10, 0x0, 0x0, 0x80000000}};
  // -8787.481407492628880
  s21_decimal dec_2 = {{0x33f2a190, 0x79f367c8, 0x0, 0x800f0000}};
  // 8771.481407492628880
  s21_decimal dec_check = {{0xe78aa190, 0x79ba8fdd, 0x0, 0xf0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_456) {
  // 792
  s21_decimal dec_1 = {{0x318, 0x0, 0x0, 0x0}};
  // -9523434934549980304
  s21_decimal dec_2 = {{0x9b65a490, 0x842a099d, 0x0, 0x80000000}};
  // 9523434934549981096
  s21_decimal dec_check = {{0x9b65a7a8, 0x842a099d, 0x0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_457) {
  // -71794242494529694128
  s21_decimal dec_1 = {{0xa4b269b0, 0xe458632a, 0x3, 0x80000000}};
  // -160062732049676215930888
  s21_decimal dec_2 = {{0xfb025008, 0x4a19e7a, 0x21e5, 0x80000000}};
  // 159990937807181686236760
  s21_decimal dec_check = {{0x564fe658, 0x20493b50, 0x21e1, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_458) {
  // 0.2
  s21_decimal dec_1 = {{0x2, 0x0, 0x0, 0x10000}};
  // -2970618388913139057234
  s21_decimal dec_2 = {{0xaad98252, 0x99c95b4, 0xa1, 0x80000000}};
  // 2970618388913139057234.2
  s21_decimal dec_check = {{0xac7f1736, 0x601dd90e, 0x64a, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_459) {
  // -366207025
  s21_decimal dec_1 = {{0x15d3e031, 0x0, 0x0, 0x80000000}};
  // 5152682974886796120223937012
  s21_decimal dec_2 = {{0x8adc71f4, 0xc66ac751, 0x10a6330f, 0x0}};
  // -5152682974886796120590144037
  s21_decimal dec_check = {{0xa0b05225, 0xc66ac751, 0x10a6330f, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_460) {
  // 9344447004
  s21_decimal dec_1 = {{0x2cf8f21c, 0x2, 0x0, 0x0}};
  // 866286230397593396489865398
  s21_decimal dec_2 = {{0x2769c8b6, 0xa64a0d68, 0x2cc933e, 0x0}};
  // -866286230397593387145418394
  s21_decimal dec_check = {{0xfa70d69a, 0xa64a0d65, 0x2cc933e, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_461) {
  // 2466933265203784956446
  s21_decimal dec_1 = {{0x8a1dba1e, 0xbb938e54, 0x85, 0x0}};
  // 798792539070045.86
  s21_decimal dec_2 = {{0x1a0cdcaa, 0x11bc9c2, 0x0, 0x20000}};
  // 2466932466411245886400.14
  s21_decimal dec_check = {{0xd98fd70e, 0x4487cf43, 0x343d, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_464) {
  // 93604858.24
  s21_decimal dec_1 = {{0x2dedadc0, 0x2, 0x0, 0x20000}};
  // 5238
  s21_decimal dec_2 = {{0x1476, 0x0, 0x0, 0x0}};
  // 93599620.24
  s21_decimal dec_check = {{0x2de5afa8, 0x2, 0x0, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_465) {
  // 7185.91
  s21_decimal dec_1 = {{0xaf6ff, 0x0, 0x0, 0x20000}};
  // 70898037684
  s21_decimal dec_2 = {{0x81da33b4, 0x10, 0x0, 0x0}};
  // -70898030498.09
  s21_decimal dec_check = {{0xb9313b51, 0x672, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_466) {
  // -20.9
  s21_decimal dec_1 = {{0xd1, 0x0, 0x0, 0x80010000}};
  // 0.061460645339507
  s21_decimal dec_2 = {{0xebeee173, 0x37e5, 0x0, 0xf0000}};
  // -20.961460645339507
  s21_decimal dec_check = {{0x5fbd2173, 0x4a7856, 0x0, 0x800f0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_467) {
  // -512622210.0414
  s21_decimal dec_1 = {{0x8aa5b7be, 0x4a9, 0x0, 0x80040000}};
  // -64449335337184
  s21_decimal dec_2 = {{0xc7bd20e0, 0x3a9d, 0x0, 0x80000000}};
  // 64448822714973.9586
  s21_decimal dec_check = {{0xc12e7642, 0x8f1aea0, 0x0, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_468) {
  // 49909656302820093167139921702
  s21_decimal dec_1 = {{0xfd119f26, 0x937c94ca, 0xa1444cd1, 0x0}};
  // 318157217391.15269170268554
  s21_decimal dec_2 = {{0x89fa098a, 0xbb3f771c, 0x1a513d, 0xe0000}};
  // 49909656302820092848982704311
  s21_decimal dec_check = {{0xe96bc0b7, 0x937c9480, 0xa1444cd1, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_469) {
  // 0.1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x10000}};
  // -6461986
  s21_decimal dec_2 = {{0x629a22, 0x0, 0x0, 0x80000000}};
  // 6461986.1
  s21_decimal dec_check = {{0x3da0555, 0x0, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_470) {
  // -138
  s21_decimal dec_1 = {{0x8a, 0x0, 0x0, 0x80000000}};
  // 3484940409943304263566352522
  s21_decimal dec_2 = {{0xd73fe08a, 0x2c1233c9, 0xb42acd6, 0x0}};
  // -3484940409943304263566352660
  s21_decimal dec_check = {{0xd73fe114, 0x2c1233c9, 0xb42acd6, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_471) {
  // 103397611985785190
  s21_decimal dec_1 = {{0x8d095166, 0x16f5794, 0x0, 0x0}};
  // 532164798872889172
  s21_decimal dec_2 = {{0xa6c92754, 0x762a110, 0x0, 0x0}};
  // -428767186887103982
  s21_decimal dec_check = {{0x19bfd5ee, 0x5f3497c, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_473) {
  // -5965665113151
  s21_decimal dec_1 = {{0xfd59943f, 0x56c, 0x0, 0x80000000}};
  // -7
  s21_decimal dec_2 = {{0x7, 0x0, 0x0, 0x80000000}};
  // -5965665113144
  s21_decimal dec_check = {{0xfd599438, 0x56c, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_474) {
  // 148735863379984
  s21_decimal dec_1 = {{0x444d5810, 0x8746, 0x0, 0x0}};
  // -47001130616302403932258658
  s21_decimal dec_2 = {{0xd3020162, 0x656ba066, 0x26e0e0, 0x80000000}};
  // 47001130616451139795638642
  s21_decimal dec_check = {{0x174f5972, 0x656c27ad, 0x26e0e0, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_475) {
  // -67.162148969786753
  s21_decimal dec_1 = {{0x5fb22d81, 0xee9b9e, 0x0, 0x800f0000}};
  // 116596240198413601440310
  s21_decimal dec_2 = {{0xd3a38236, 0xb1e17319, 0x18b0, 0x0}};
  // -116596240198413601440377.16215
  s21_decimal dec_check = {{0x5ef620f7, 0xa241488f, 0x25ac9d6c, 0x80050000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_476) {
  // 27992174066057743256210
  s21_decimal dec_1 = {{0x619d4a92, 0x7573b42f, 0x5ed, 0x0}};
  // -27298797849973296939
  s21_decimal dec_2 = {{0x62db0f2b, 0x7ad8d002, 0x1, 0x80000000}};
  // 28019472863907716553149
  s21_decimal dec_check = {{0xc47859bd, 0xf04c8431, 0x5ee, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_477) {
  // 8604304901957
  s21_decimal dec_1 = {{0x58898745, 0x7d3, 0x0, 0x0}};
  // -5.2
  s21_decimal dec_2 = {{0x34, 0x0, 0x0, 0x80010000}};
  // 8604304901962.2
  s21_decimal dec_check = {{0x755f48e6, 0x4e41, 0x0, 0x10000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_478) {
  // 786120.4849568886329563825
  s21_decimal dec_1 = {{0x2cb5dab1, 0xc4d0ea8d, 0x680ac, 0x130000}};
  // 0.5877730
  s21_decimal dec_2 = {{0x59afe2, 0x0, 0x0, 0x70000}};
  // 786119.8971838886329563825
  s21_decimal dec_check = {{0xd0dbab1, 0x733f0642, 0x680ac, 0x130000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_479) {
  // 5541
  s21_decimal dec_1 = {{0x15a5, 0x0, 0x0, 0x0}};
  // -88947621050690251294
  s21_decimal dec_2 = {{0xb6732a1e, 0xd2656e14, 0x4, 0x80000000}};
  // 88947621050690256835
  s21_decimal dec_check = {{0xb6733fc3, 0xd2656e14, 0x4, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_480) {
  // -464675097
  s21_decimal dec_1 = {{0x1bb26119, 0x0, 0x0, 0x80000000}};
  // 286470307401578009
  s21_decimal dec_2 = {{0xf5e3619, 0x3f9bf3a, 0x0, 0x0}};
  // -286470307866253106
  s21_decimal dec_check = {{0x2b109732, 0x3f9bf3a, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_481) {
  // 5695650.7
  s21_decimal dec_1 = {{0x365165b, 0x0, 0x0, 0x10000}};
  // 5023406662368.11
  s21_decimal dec_2 = {{0x4cf79f8b, 0x1c8e0, 0x0, 0x20000}};
  // -5023400966717.41
  s21_decimal dec_check = {{0x2b04bffd, 0x1c8e0, 0x0, 0x80020000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_482) {
  // -42
  s21_decimal dec_1 = {{0x2a, 0x0, 0x0, 0x80000000}};
  // 6.5308761506336556250144
  s21_decimal dec_2 = {{0x6794f420, 0x6522595d, 0xdd4, 0x160000}};
  // -48.5308761506336556250144
  s21_decimal dec_check = {{0xa614f420, 0xa40371fe, 0x66c4, 0x80160000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_483) {
  // 0.64441019460
  s21_decimal dec_1 = {{0xfbec44, 0xf, 0x0, 0xb0000}};
  // 896
  s21_decimal dec_2 = {{0x380, 0x0, 0x0, 0x0}};
  // -895.35558980540
  s21_decimal dec_check = {{0x9f3013bc, 0x516e, 0x0, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_484) {
  // -6031223
  s21_decimal dec_1 = {{0x5c0777, 0x0, 0x0, 0x80000000}};
  // 9730548067
  s21_decimal dec_2 = {{0x43fc6163, 0x2, 0x0, 0x0}};
  // -9736579290
  s21_decimal dec_check = {{0x445868da, 0x2, 0x0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_485) {
  // 18.827
  s21_decimal dec_1 = {{0x498b, 0x0, 0x0, 0x30000}};
  // -6468204454970536235114
  s21_decimal dec_2 = {{0x9df0106a, 0xa45e71c7, 0x15e, 0x80000000}};
  // 6468204454970536235132.827
  s21_decimal dec_check = {{0xf1c0679b, 0x10ec73c0, 0x559b2, 0x30000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_486) {
  // -20029.20654
  s21_decimal dec_1 = {{0x776224ce, 0x0, 0x0, 0x80050000}};
  // -9549233116202707262
  s21_decimal dec_2 = {{0xd8a8a93e, 0x8485b0ec, 0x0, 0x80000000}};
  // 9549233116202687232.79346
  s21_decimal dec_check = {{0xe3dc15f2, 0x7f176617, 0xca36, 0x50000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_487) {
  // 18534129795736879436811
  s21_decimal dec_1 = {{0xc7e7140b, 0xbcb87331, 0x3ec, 0x0}};
  // -688100372660
  s21_decimal dec_2 = {{0x35fa70b4, 0xa0, 0x0, 0x80000000}};
  // 18534129796424979809471
  s21_decimal dec_check = {{0xfde184bf, 0xbcb873d1, 0x3ec, 0x0}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_488) {
  // -308.80
  s21_decimal dec_1 = {{0x78a0, 0x0, 0x0, 0x80020000}};
  // -6451062575421190074355
  s21_decimal dec_2 = {{0xb4a06ff3, 0xb67a4126, 0x15d, 0x80000000}};
  // 6451062575421190074046.20
  s21_decimal dec_check = {{0x8eab424c, 0x47c1731e, 0x889b, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_489) {
  // 7108037884230303
  s21_decimal dec_1 = {{0x923ba9f, 0x1940b9, 0x0, 0x0}};
  // 70319721111418.6699
  s21_decimal dec_2 = {{0x4781a7cb, 0x9c24223, 0x0, 0x40000}};
  // 7037718163118884.3301
  s21_decimal dec_check = {{0xbc283b25, 0xd0adf9d1, 0x3, 0x40000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_490) {
  // -157875767226689975
  s21_decimal dec_1 = {{0x803069b7, 0x230e32c, 0x0, 0x80000000}};
  // -7521902754721832.4
  s21_decimal dec_2 = {{0x994d6194, 0x10b3b4e, 0x0, 0x80010000}};
  // -150353864471968142.6
  s21_decimal dec_check = {{0x6896bf92, 0x14dda46e, 0x0, 0x80010000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_492) {
  // 6828399301087516.6380231973
  s21_decimal dec_1 = {{0x26bb8d25, 0xadacdaa0, 0x387bb2, 0xa0000}};
  // 9.4510648189201
  s21_decimal dec_2 = {{0xf99ce111, 0x55f4, 0x0, 0xd0000}};
  // 6828399301087507.1869583783799
  s21_decimal dec_check = {{0x53027777, 0x6b35aba2, 0xdca331f6, 0xd0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_493) {
  // -890447.52248784172
  s21_decimal dec_1 = {{0xfae6c52c, 0x13c59ba, 0x0, 0x800b0000}};
  // 233.610296709
  s21_decimal dec_2 = {{0x64423d85, 0x36, 0x0, 0x90000}};
  // -890681.13278455072
  s21_decimal dec_check = {{0x24c6cd20, 0x13c6efa, 0x0, 0x800b0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_494) {
  // 10250847892812486713
  s21_decimal dec_1 = {{0xe1a65839, 0x8e4253d8, 0x0, 0x0}};
  // -4059.11
  s21_decimal dec_2 = {{0x63197, 0x0, 0x0, 0x80020000}};
  // 10250847892812490772.11
  s21_decimal dec_check = {{0x2500a7db, 0x91e8c0b8, 0x37, 0x20000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_495) {
  // -0.6
  s21_decimal dec_1 = {{0x6, 0x0, 0x0, 0x80010000}};
  // 7.0102
  s21_decimal dec_2 = {{0x111d6, 0x0, 0x0, 0x40000}};
  // -7.6102
  s21_decimal dec_check = {{0x12946, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_496) {
  // 1
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  // -97.025686
  s21_decimal dec_2 = {{0x5c87e96, 0x0, 0x0, 0x80060000}};
  // 98.025686
  s21_decimal dec_check = {{0x5d7c0d6, 0x0, 0x0, 0x60000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_497) {
  // -406328309276592656880
  s21_decimal dec_1 = {{0xa85d51f0, 0x6f02477, 0x16, 0x80000000}};
  // 0.551
  s21_decimal dec_2 = {{0x227, 0x0, 0x0, 0x30000}};
  // -406328309276592656880.551
  s21_decimal dec_check = {{0xac8813a7, 0x1a0e7369, 0x560b, 0x80030000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_498) {
  // -2140202.6
  s21_decimal dec_1 = {{0x14691aa, 0x0, 0x0, 0x80010000}};
  // -20902088053.7843339887
  s21_decimal dec_2 = {{0xb983126f, 0x54bf5768, 0xb, 0x800a0000}};
  // 20899947851.1843339887
  s21_decimal dec_check = {{0x3c4eee6f, 0x54734e61, 0xb, 0xa0000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_499) {
  // -78851.0751
  s21_decimal dec_1 = {{0x2effb81f, 0x0, 0x0, 0x80040000}};
  // 3.322
  s21_decimal dec_2 = {{0xcfa, 0x0, 0x0, 0x30000}};
  // -78854.3971
  s21_decimal dec_check = {{0x2f0039e3, 0x0, 0x0, 0x80040000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_500) {
  // -6321794141421.168762
  s21_decimal dec_1 = {{0xfe8de87a, 0x57bb8646, 0x0, 0x80060000}};
  // 6
  s21_decimal dec_2 = {{0x6, 0x0, 0x0, 0x0}};
  // -6321794141427.168762
  s21_decimal dec_check = {{0xfee975fa, 0x57bb8646, 0x0, 0x80060000}};
  s21_decimal result;
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(fail_s21_sub_1) {
  // -79228162514264337591648379792
  s21_decimal dec_1 = {{0x8f03e390, 0xffffffff, 0xffffffff, 0x80000000}};
  // 874142064346521593.426591
  s21_decimal dec_2 = {{0xf1d3b29f, 0x56153802, 0xb91b, 0x60000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_2) {
  // -136550842478129.63320817
  s21_decimal dec_1 = {{0x1bc443f1, 0x3e5c97a6, 0x2e4, 0x80080000}};
  // 79228162514264337592192832294
  s21_decimal dec_2 = {{0xaf779326, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_3) {
  // -79228162514264337593136450781
  s21_decimal dec_1 = {{0xe7b60cdd, 0xffffffff, 0xffffffff, 0x80000000}};
  // 5543398857819815056
  s21_decimal dec_2 = {{0x18a7fc90, 0x4cee1be4, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_4) {
  // -800409286704878746214149
  s21_decimal dec_1 = {{0x97ce1f05, 0x463d83ef, 0xa97e, 0x80000000}};
  // 79228162514264337591808551768
  s21_decimal dec_2 = {{0x988feb58, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_5) {
  // 32775947862324871
  s21_decimal dec_1 = {{0x982b687, 0x74718d, 0x0, 0x0}};
  // -79228162514264337592754111122
  s21_decimal dec_2 = {{0xd0ec0292, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_6) {
  // 7478949493530.10
  s21_decimal dec_1 = {{0xdcc91632, 0x2a834, 0x0, 0x20000}};
  // -79228162514264337592151154068
  s21_decimal dec_2 = {{0xacfb9d94, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_7) {
  // -9086340273
  s21_decimal dec_1 = {{0x1d968cb1, 0x2, 0x0, 0x80000000}};
  // 79228162514264337592784013307
  s21_decimal dec_2 = {{0xd2b447fb, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_8) {
  // 54301699080284560973129118210
  s21_decimal dec_1 = {{0xf36cf202, 0x9ffb8a5c, 0xaf75500d, 0x0}};
  // -54727517517515376688741202700
  s21_decimal dec_2 = {{0xf703bb0c, 0x5c86e976, 0xb0d58a9d, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_9) {
  // -79228162514264337592546375977
  s21_decimal dec_1 = {{0xc48a3929, 0xffffffff, 0xffffffff, 0x80000000}};
  // 953136827419124893
  s21_decimal dec_2 = {{0x4a8e49d, 0xd3a38e5, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_10) {
  // 79228162514264337592423254518
  s21_decimal dec_1 = {{0xbd3389f6, 0xffffffff, 0xffffffff, 0x0}};
  // -91114287613371
  s21_decimal dec_2 = {{0x32bf45bb, 0x52de, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_11) {
  // 977984735309519474
  s21_decimal dec_1 = {{0x67e0da72, 0xd927fef, 0x0, 0x0}};
  // -79228162514264337592187043665
  s21_decimal dec_2 = {{0xaf1f3f51, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_12) {
  // -82665760220038346168855133
  s21_decimal dec_1 = {{0x94dbea5d, 0xd74e2c2b, 0x446127, 0x80000000}};
  // 79228162514264337591972056423
  s21_decimal dec_2 = {{0xa24ecd67, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_13) {
  // 79228162514264337591835247284
  s21_decimal dec_1 = {{0x9a2742b4, 0xffffffff, 0xffffffff, 0x0}};
  // -64657661254266201.3122882
  s21_decimal dec_2 = {{0xabd07942, 0xfd07c5d6, 0x88ea, 0x80070000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_14) {
  // -701483112257.01064988733231553
  s21_decimal dec_1 = {{0xa92c51c1, 0x5acee834, 0xe2a952b3, 0x80110000}};
  // 79228162514264337593080147686
  s21_decimal dec_2 = {{0xe45aeee6, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_15) {
  // -71839594072.8066757353377
  s21_decimal dec_1 = {{0xf55bdfa1, 0x526d6b5a, 0x9820, 0x800d0000}};
  // 79228162514264337591552562340
  s21_decimal dec_2 = {{0x894dd4a4, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_16) {
  // 79228162514264337593264817138
  s21_decimal dec_1 = {{0xef5cc3f2, 0xffffffff, 0xffffffff, 0x0}};
  // -4649993154041970003539351
  s21_decimal dec_2 = {{0x3913f597, 0xa24cb18f, 0x3d8ac, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_17) {
  // 79228162514264337593046176249
  s21_decimal dec_1 = {{0xe25491f9, 0xffffffff, 0xffffffff, 0x0}};
  // -768702782232929
  s21_decimal dec_2 = {{0x9045d961, 0x2bb21, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_18) {
  // 5706499121888255
  s21_decimal dec_1 = {{0xdd123bff, 0x144607, 0x0, 0x0}};
  // -79228162514264337593446059705
  s21_decimal dec_2 = {{0xfa2a4eb9, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_19) {
  // -79228162514264337591510444059
  s21_decimal dec_1 = {{0x86cb281b, 0xffffffff, 0xffffffff, 0x80000000}};
  // 1816668885027203086
  s21_decimal dec_2 = {{0xce8d280e, 0x19361ab9, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_20) {
  // -79228162514264337593186557193
  s21_decimal dec_1 = {{0xeab29d09, 0xffffffff, 0xffffffff, 0x80000000}};
  // 507455031
  s21_decimal dec_2 = {{0x1e3f2637, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_21) {
  // -42739768565
  s21_decimal dec_1 = {{0xf37d1cf5, 0x9, 0x0, 0x80000000}};
  // 79228162514264337592614923266
  s21_decimal dec_2 = {{0xc8a02c02, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_22) {
  // 1768130372
  s21_decimal dec_1 = {{0x69638744, 0x0, 0x0, 0x0}};
  // -79228162514264337593132681764
  s21_decimal dec_2 = {{0xe77c8a24, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_23) {
  // -79228162514264337593337432964
  s21_decimal dec_1 = {{0xf3b0cb84, 0xffffffff, 0xffffffff, 0x80000000}};
  // 1519335527726
  s21_decimal dec_2 = {{0xbf74552e, 0x161, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_24) {
  // 36268443796720096485199804
  s21_decimal dec_1 = {{0x3df64fbc, 0x47216a27, 0x1e0024, 0x0}};
  // -79228162514264337593185570752
  s21_decimal dec_2 = {{0xeaa38fc0, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_25) {
  // -22416447899802141428940549
  s21_decimal dec_1 = {{0xa19dff05, 0x135bbeee, 0x128ade, 0x80000000}};
  // 79228162514264337591910937368
  s21_decimal dec_2 = {{0x9eaa3318, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_26) {
  // 5930299398722675
  s21_decimal dec_1 = {{0x6d129473, 0x151193, 0x0, 0x0}};
  // -79228162514264337593263613382
  s21_decimal dec_2 = {{0xef4a65c6, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_27) {
  // -34651381521764
  s21_decimal dec_1 = {{0xe7495d64, 0x1f83, 0x0, 0x80000000}};
  // 79228162514264337593375139737
  s21_decimal dec_2 = {{0xf5f02799, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_28) {
  // 657760086323071344467
  s21_decimal dec_1 = {{0x6cf0df53, 0xa841418c, 0x23, 0x0}};
  // -79228162514264337593018271844
  s21_decimal dec_2 = {{0xe0aac864, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_29) {
  // 62497922600619952457839768131
  s21_decimal dec_1 = {{0xaacb7243, 0xf89d7b43, 0xc9f111e4, 0x0}};
  // -64073447989342151817811217706
  s21_decimal dec_2 = {{0x47984d2a, 0x6f2050ce, 0xcf08505f, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_30) {
  // 79228162514264337592841562178
  s21_decimal dec_1 = {{0xd6226842, 0xffffffff, 0xffffffff, 0x0}};
  // -8905792735496.048789536138
  s21_decimal dec_2 = {{0x5acdbd8a, 0xfdd7f57d, 0x75ddf, 0x800c0000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_31) {
  // 79228162514264337592887871467
  s21_decimal dec_1 = {{0xd8e507eb, 0xffffffff, 0xffffffff, 0x0}};
  // -525140773429.467412551860505
  s21_decimal dec_2 = {{0x75368119, 0x5ee2be57, 0x1b262e2, 0x800f0000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_32) {
  // -7451385582222876652.98907566
  s21_decimal dec_1 = {{0x974fa1ae, 0x2e6e013e, 0x2685d3a, 0x80080000}};
  // 79228162514264337591760892667
  s21_decimal dec_2 = {{0x95b8b2fb, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_33) {
  // 41659064065799021564449397846
  s21_decimal dec_1 = {{0xe8461c56, 0x314e986c, 0x869b91f4, 0x0}};
  // -45506577673582622866841775159
  s21_decimal dec_2 = {{0xeea3ac37, 0xcdce7613, 0x930a28a6, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_34) {
  // -614333113785910.764007
  s21_decimal dec_1 = {{0xa8d721e7, 0x4d95a81c, 0x21, 0x80060000}};
  // 79228162514264337591497666770
  s21_decimal dec_2 = {{0x860830d2, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_35) {
  // 288790268118816346
  s21_decimal dec_1 = {{0x1cfd65a, 0x401fd38, 0x0, 0x0}};
  // -79228162514264337593027858861
  s21_decimal dec_2 = {{0xe13d11ad, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_36) {
  // 75678408904708.8364893410678
  s21_decimal dec_1 = {{0xbe4a9576, 0xac202acc, 0x271ff43, 0xd0000}};
  // -79228162514264337593471375294
  s21_decimal dec_2 = {{0xfbac97be, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_37) {
  // 767321847134901369025
  s21_decimal dec_1 = {{0x1861f8c1, 0x98bad286, 0x29, 0x0}};
  // -79228162514264337593275534695
  s21_decimal dec_2 = {{0xf0004d67, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_38) {
  // 79228162514264337592470192217
  s21_decimal dec_1 = {{0xbfffc059, 0xffffffff, 0xffffffff, 0x0}};
  // -656309603761811338209989461
  s21_decimal dec_2 = {{0xc78b1355, 0xe93cb94d, 0x21ee2f6, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_39) {
  // -79228162514264337592844505768
  s21_decimal dec_1 = {{0xd64f52a8, 0xffffffff, 0xffffffff, 0x80000000}};
  // 9248731503307346561189266421
  s21_decimal dec_2 = {{0x62fbc3f5, 0x6e59216a, 0x1de25f13, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_40) {
  // -7970110583003307.8663438790
  s21_decimal dec_1 = {{0xe8b2e1c6, 0x9ac1e286, 0x41ed5d, 0x800a0000}};
  // 79228162514264337592097556872
  s21_decimal dec_2 = {{0xa9c9c988, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_41) {
  // 833276239898159.102
  s21_decimal dec_1 = {{0x46e727fe, 0xb906453, 0x0, 0x30000}};
  // -79228162514264337591479669262
  s21_decimal dec_2 = {{0x84f5920e, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_42) {
  // 282273206863224657939
  s21_decimal dec_1 = {{0x34dc5813, 0x4d53e218, 0xf, 0x0}};
  // -79228162514264337592444436117
  s21_decimal dec_2 = {{0xbe76be95, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_43) {
  // -29998183318602.5248580
  s21_decimal dec_1 = {{0x2b859744, 0x43158fe9, 0x10, 0x80070000}};
  // 79228162514264337592456591749
  s21_decimal dec_2 = {{0xbf303985, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_44) {
  // 79228162514264337591876900355
  s21_decimal dec_1 = {{0x9ca2d603, 0xffffffff, 0xffffffff, 0x0}};
  // -103026501303.56
  s21_decimal dec_2 = {{0xc5cd1fb4, 0x95e, 0x0, 0x80020000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_45) {
  // 2596938729262687
  s21_decimal dec_1 = {{0xea760e5f, 0x939e6, 0x0, 0x0}};
  // -79228162514264337592083835266
  s21_decimal dec_2 = {{0xa8f86982, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_46) {
  // -41308697517533698054353
  s21_decimal dec_1 = {{0x609dd8d1, 0x5956b956, 0x8bf, 0x80000000}};
  // 79228162514264337592730578981
  s21_decimal dec_2 = {{0xcf84f025, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_47) {
  // -1352653962790764648242866
  s21_decimal dec_1 = {{0x26f69eb2, 0x84ac4a5b, 0x11e6f, 0x80000000}};
  // 79228162514264337592575321587
  s21_decimal dec_2 = {{0xc643e5f3, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_48) {
  // 79228162514264337592566476999
  s21_decimal dec_1 = {{0xc5bcf0c7, 0xffffffff, 0xffffffff, 0x0}};
  // -1300290244
  s21_decimal dec_2 = {{0x4d80dac4, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_49) {
  // -79228162514264337592358971177
  s21_decimal dec_1 = {{0xb95ea729, 0xffffffff, 0xffffffff, 0x80000000}};
  // 9682562856610208460348172
  s21_decimal dec_2 = {{0x6b089b0c, 0xc8c28655, 0x8025c, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_50) {
  // 79228162514264337592555496268
  s21_decimal dec_1 = {{0xc515634c, 0xffffffff, 0xffffffff, 0x0}};
  // -300302891742753663680191151
  s21_decimal dec_2 = {{0x7d131aaf, 0x61add3b2, 0xf8679c, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_51) {
  // 74874441943195854
  s21_decimal dec_1 = {{0x82c7a0ce, 0x10a01e8, 0x0, 0x0}};
  // -79228162514264337591986235676
  s21_decimal dec_2 = {{0xa327291c, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_52) {
  // 79228162514264337592942284265
  s21_decimal dec_1 = {{0xdc234de9, 0xffffffff, 0xffffffff, 0x0}};
  // -610752094181792632605931354
  s21_decimal dec_2 = {{0xb7fa775a, 0x5e3bb4de, 0x1f933c9, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_53) {
  // 79228162514264337593494495465
  s21_decimal dec_1 = {{0xfd0d60e9, 0xffffffff, 0xffffffff, 0x0}};
  // -63261525
  s21_decimal dec_2 = {{0x3c54b55, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_54) {
  // 79228162514264337593300695875
  s21_decimal dec_1 = {{0xf1803b43, 0xffffffff, 0xffffffff, 0x0}};
  // -181539805248.80807165817699
  s21_decimal dec_2 = {{0x56f9f363, 0x41976c04, 0xf0441, 0x800e0000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_55) {
  // -909267147573863463187
  s21_decimal dec_1 = {{0xf0d13913, 0x4a9dd536, 0x31, 0x80000000}};
  // 79228162514264337591728824062
  s21_decimal dec_2 = {{0x93cf5efe, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_56) {
  // -779780243831525846952765
  s21_decimal dec_1 = {{0x90b62b3d, 0xf8c2b7f9, 0xa51f, 0x80000000}};
  // 79228162514264337591657431854
  s21_decimal dec_2 = {{0x8f8e032e, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_57) {
  // 79228162514264337593002969783
  s21_decimal dec_1 = {{0xdfc14ab7, 0xffffffff, 0xffffffff, 0x0}};
  // -4092002488
  s21_decimal dec_2 = {{0xf3e700b8, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_58) {
  // 2531024921810624080
  s21_decimal dec_1 = {{0xa62ede50, 0x232001c1, 0x0, 0x0}};
  // -79228162514264337592609616429
  s21_decimal dec_2 = {{0xc84f322d, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_59) {
  // 43664247038941218
  s21_decimal dec_1 = {{0xbe241822, 0x9b2066, 0x0, 0x0}};
  // -79228162514264337593282732982
  s21_decimal dec_2 = {{0xf06e23b6, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_60) {
  // -589351464973177924139
  s21_decimal dec_1 = {{0xe572a2b, 0xf2e502e0, 0x1f, 0x80000000}};
  // 79228162514264337591412120954
  s21_decimal dec_2 = {{0x80eedd7a, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_61) {
  // 79228162514264337592067287997
  s21_decimal dec_1 = {{0xa7fbebbd, 0xffffffff, 0xffffffff, 0x0}};
  // -5944919435651743
  s21_decimal dec_2 = {{0x6b2e2a9f, 0x151edf, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_62) {
  // -79228162514264337592971327473
  s21_decimal dec_1 = {{0xddde77f1, 0xffffffff, 0xffffffff, 0x80000000}};
  // 1314988909276825823828
  s21_decimal dec_2 = {{0x9f92aa54, 0x492315e0, 0x47, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_63) {
  // 79228162514264337592729203097
  s21_decimal dec_1 = {{0xcf6ff199, 0xffffffff, 0xffffffff, 0x0}};
  // -95013834293518290246.13746
  s21_decimal dec_2 = {{0x7b692572, 0x71cfc95, 0x7dbff, 0x80050000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_64) {
  // 562836857888205824451.486475
  s21_decimal dec_1 = {{0xa021230b, 0x343085bf, 0x1d19157, 0x60000}};
  // -79228162514264337591532633639
  s21_decimal dec_2 = {{0x881dbe27, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_65) {
  // -79228162514264337592132779592
  s21_decimal dec_1 = {{0xabe33e48, 0xffffffff, 0xffffffff, 0x80000000}};
  // 4283455908512
  s21_decimal dec_2 = {{0x51de2aa0, 0x3e5, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_66) {
  // 79228162514264337593285503087
  s21_decimal dec_1 = {{0xf098686f, 0xffffffff, 0xffffffff, 0x0}};
  // -1338526544473558267
  s21_decimal dec_2 = {{0xe5c70cfb, 0x129366cc, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_67) {
  // 55875677441475289252106577
  s21_decimal dec_1 = {{0xf0501151, 0x8b2692e6, 0x2e3822, 0x0}};
  // -79228162514264337591503196922
  s21_decimal dec_2 = {{0x865c92fa, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_68) {
  // 79228162514264337592340135386
  s21_decimal dec_1 = {{0xb83f3dda, 0xffffffff, 0xffffffff, 0x0}};
  // -128215077679299683
  s21_decimal dec_2 = {{0xfec7c63, 0x1c782ef, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_69) {
  // 79228162514264337593042699744
  s21_decimal dec_1 = {{0xe21f85e0, 0xffffffff, 0xffffffff, 0x0}};
  // -5125597443976825
  s21_decimal dec_2 = {{0x26e8ee79, 0x1235b4, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_70) {
  // -79228162514264337591782465913
  s21_decimal dec_1 = {{0x9701e179, 0xffffffff, 0xffffffff, 0x80000000}};
  // 161716134565252859171592
  s21_decimal dec_2 = {{0x9e181308, 0xa6335a4b, 0x223e, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_71) {
  // -79228162514264337592102234927
  s21_decimal dec_1 = {{0xaa112b2f, 0xffffffff, 0xffffffff, 0x80000000}};
  // 549465802815
  s21_decimal dec_2 = {{0xeeb6c83f, 0x7f, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_72) {
  // 9126955493552088444535
  s21_decimal dec_1 = {{0xf4406e77, 0xc5f3a0b3, 0x1ee, 0x0}};
  // -79228162514264337591418712540
  s21_decimal dec_2 = {{0x815371dc, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_73) {
  // -79228162514264337593405602591
  s21_decimal dec_1 = {{0xf7c0fb1f, 0xffffffff, 0xffffffff, 0x80000000}};
  // 47359619899444
  s21_decimal dec_2 = {{0xc5522034, 0x2b12, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_74) {
  // -388370171345.79564681229664
  s21_decimal dec_1 = {{0x8f9df560, 0xeae1d48b, 0x20200e, 0x800e0000}};
  // 79228162514264337591851666099
  s21_decimal dec_2 = {{0x9b21cab3, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_75) {
  // -3964753983687.1
  s21_decimal dec_1 = {{0x298737c7, 0x240f, 0x0, 0x80010000}};
  // 79228162514264337592634281417
  s21_decimal dec_2 = {{0xc9c78dc9, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_76) {
  // 79228162514264337591796515788
  s21_decimal dec_1 = {{0x97d843cc, 0xffffffff, 0xffffffff, 0x0}};
  // -380917244738369373
  s21_decimal dec_2 = {{0x4573775d, 0x5494a37, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_77) {
  // -79228162514264337592238725553
  s21_decimal dec_1 = {{0xb233d9b1, 0xffffffff, 0xffffffff, 0x80000000}};
  // 93796338506542681722347
  s21_decimal dec_2 = {{0x91c08deb, 0xb5aed566, 0x13dc, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_78) {
  // 79228162514264337593419032804
  s21_decimal dec_1 = {{0xf88de8e4, 0xffffffff, 0xffffffff, 0x0}};
  // -139010215239725553236271
  s21_decimal dec_2 = {{0x41ef392f, 0xc2452cd8, 0x1d6f, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_79) {
  // -79228162514264337591808540463
  s21_decimal dec_1 = {{0x988fbf2f, 0xffffffff, 0xffffffff, 0x80000000}};
  // 46884692259.3056423
  s21_decimal dec_2 = {{0xc331b6a7, 0x681adca, 0x0, 0x70000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_80) {
  // -79228162514264337591463212783
  s21_decimal dec_1 = {{0x83fa76ef, 0xffffffff, 0xffffffff, 0x80000000}};
  // 840687681485
  s21_decimal dec_2 = {{0xbce3ffcd, 0xc3, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_81) {
  // -79228162514264337592854006539
  s21_decimal dec_1 = {{0xd6e04b0b, 0xffffffff, 0xffffffff, 0x80000000}};
  // 80033559966
  s21_decimal dec_2 = {{0xa25f359e, 0x12, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_82) {
  // -8792884179
  s21_decimal dec_1 = {{0xc18c3d3, 0x2, 0x0, 0x80000000}};
  // 79228162514264337592039692514
  s21_decimal dec_2 = {{0xa656d8e2, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_83) {
  // 79228162514264337592209809484
  s21_decimal dec_1 = {{0xb07aa04c, 0xffffffff, 0xffffffff, 0x0}};
  // -7530630763835277
  s21_decimal dec_2 = {{0x9b9cef8d, 0x1ac111, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_84) {
  // -713996659185931723534
  s21_decimal dec_1 = {{0xf91b230e, 0xb4b1b29c, 0x26, 0x80000000}};
  // 79228162514264337592678838438
  s21_decimal dec_2 = {{0xcc6f70a6, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_85) {
  // 9277160522
  s21_decimal dec_1 = {{0x28f63c4a, 0x2, 0x0, 0x0}};
  // -79228162514264337591986465412
  s21_decimal dec_2 = {{0xa32aaa84, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_86) {
  // 93399179360
  s21_decimal dec_1 = {{0xbf066060, 0x15, 0x0, 0x0}};
  // -79228162514264337592647689625
  s21_decimal dec_2 = {{0xca942599, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_87) {
  // 79228162514264337592541119456
  s21_decimal dec_1 = {{0xc43a03e0, 0xffffffff, 0xffffffff, 0x0}};
  // -27128290451053149101527
  s21_decimal dec_2 = {{0xd4771dd7, 0xa0a89163, 0x5be, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_88) {
  // 8089153791123
  s21_decimal dec_1 = {{0x67236493, 0x75b, 0x0, 0x0}};
  // -79228162514264337593477161400
  s21_decimal dec_2 = {{0xfc04e1b8, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_89) {
  // 538102005607240
  s21_decimal dec_1 = {{0xa2e5ab48, 0x1e966, 0x0, 0x0}};
  // -79228162514264337592862860617
  s21_decimal dec_2 = {{0xd7676549, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_90) {
  // 45595228716268143940110923804
  s21_decimal dec_1 = {{0x982c381c, 0x75233d32, 0x93537d3d, 0x0}};
  // -55419970731757289876998666996
  s21_decimal dec_2 = {{0x5e4d3af4, 0x529d87e2, 0xb3125349, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_91) {
  // 79228162514264337592999586203
  s21_decimal dec_1 = {{0xdf8da99b, 0xffffffff, 0xffffffff, 0x0}};
  // -710984882515821.6491
  s21_decimal dec_2 = {{0x3e48ab2b, 0x62ab41d6, 0x0, 0x80040000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_92) {
  // 50443572308.3368385986495446
  s21_decimal dec_1 = {{0xf98503d6, 0x57a1e78a, 0x1a1426b, 0x100000}};
  // -79228162514264337592579530726
  s21_decimal dec_2 = {{0xc6841fe6, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_93) {
  // 79228162514264337593178232960
  s21_decimal dec_1 = {{0xea339880, 0xffffffff, 0xffffffff, 0x0}};
  // -317330387945696153
  s21_decimal dec_2 = {{0x79f0ab99, 0x467624e, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_94) {
  // -79228162514264337591808584607
  s21_decimal dec_1 = {{0x98906b9f, 0xffffffff, 0xffffffff, 0x80000000}};
  // 76717668170527.2
  s21_decimal dec_2 = {{0x3d97cf38, 0x2b9be, 0x0, 0x10000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_95) {
  // -79228162514264337592285130960
  s21_decimal dec_1 = {{0xb4f7f0d0, 0xffffffff, 0xffffffff, 0x80000000}};
  // 385633692770505401241041
  s21_decimal dec_2 = {{0x62330dd1, 0x3e8f4fe7, 0x51a9, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_96) {
  // -79228162514264337591749613040
  s21_decimal dec_1 = {{0x950c95f0, 0xffffffff, 0xffffffff, 0x80000000}};
  // 85653494503313895221381
  s21_decimal dec_2 = {{0xc22e6885, 0x49058f19, 0x1223, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_97) {
  // 33388115008263661948545873913
  s21_decimal dec_1 = {{0x58dd37f9, 0x5b969ca7, 0x6be2005d, 0x0}};
  // -73288532843139144453456007981
  s21_decimal dec_2 = {{0xcb82132d, 0x572034a2, 0xecceda7e, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_98) {
  // -343432592861313208377083
  s21_decimal dec_1 = {{0xe7fb5efb, 0x84a66780, 0x48b9, 0x80000000}};
  // 79228162514264337592145482561
  s21_decimal dec_2 = {{0xaca51341, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_99) {
  // 78466055305208654730
  s21_decimal dec_1 = {{0xb11deb8a, 0x40ef6d91, 0x4, 0x0}};
  // -79228162514264337591871776559
  s21_decimal dec_2 = {{0x9c54a72f, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_100) {
  // -79228162514264337592333393361
  s21_decimal dec_1 = {{0xb7d85dd1, 0xffffffff, 0xffffffff, 0x80000000}};
  // 831713308378571315
  s21_decimal dec_2 = {{0xecdea233, 0xb8ad6d8, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_101) {
  // 680718149730042.28
  s21_decimal dec_1 = {{0x7eae99c4, 0xf1d6f4, 0x0, 0x20000}};
  // -79228162514264337593226974957
  s21_decimal dec_2 = {{0xed1b56ed, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_102) {
  // -3913902466883505.6351185
  s21_decimal dec_1 = {{0x8c3a77d1, 0xbb1450dd, 0x849, 0x80070000}};
  // 79228162514264337591538693587
  s21_decimal dec_2 = {{0x887a35d3, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_103) {
  // 54153928997732.34077
  s21_decimal dec_1 = {{0x7e27fb9d, 0x4b275726, 0x0, 0x50000}};
  // -79228162514264337593053858978
  s21_decimal dec_2 = {{0xe2c9cca2, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_104) {
  // 250256078688785263585781
  s21_decimal dec_1 = {{0x51b169f5, 0x68c1f5eb, 0x34fe, 0x0}};
  // -79228162514264337591751110212
  s21_decimal dec_2 = {{0x95236e44, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_105) {
  // 305650556059133.38864619
  s21_decimal dec_1 = {{0x1e6d63eb, 0xef5b24f9, 0x678, 0x80000}};
  // -79228162514264337591520103968
  s21_decimal dec_2 = {{0x875e8e20, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_106) {
  // -79228162514264337591843329267
  s21_decimal dec_1 = {{0x9aa294f3, 0xffffffff, 0xffffffff, 0x80000000}};
  // 36531237469238
  s21_decimal dec_2 = {{0x976ebc36, 0x2139, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_107) {
  // -79228162514264337591857813173
  s21_decimal dec_1 = {{0x9b7f96b5, 0xffffffff, 0xffffffff, 0x80000000}};
  // 7929508897.99236828
  s21_decimal dec_2 = {{0xed03cdc, 0xb0120a2, 0x0, 0x80000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_108) {
  // 5306292329.3986440783162535
  s21_decimal dec_1 = {{0xf56ca7, 0xd5efaff7, 0x2be482, 0x100000}};
  // -79228162514264337591489663002
  s21_decimal dec_2 = {{0x858e101a, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_109) {
  // -675209285
  s21_decimal dec_1 = {{0x283ee045, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593047803849
  s21_decimal dec_2 = {{0xe26d67c9, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_110) {
  // -79228162514264337592152768443
  s21_decimal dec_1 = {{0xad143fbb, 0xffffffff, 0xffffffff, 0x80000000}};
  // 6093801248294741668
  s21_decimal dec_2 = {{0xf070a6a4, 0x549187f2, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_111) {
  // -3299245263763547
  s21_decimal dec_1 = {{0x65f9385b, 0xbb8a5, 0x0, 0x80000000}};
  // 79228162514264337591598018588
  s21_decimal dec_2 = {{0x8c03701c, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_112) {
  // -79228162514264337592801276326
  s21_decimal dec_1 = {{0xd3bbb1a6, 0xffffffff, 0xffffffff, 0x80000000}};
  // 4870865004326166639174862788
  s21_decimal dec_2 = {{0x27c9c7c4, 0xfa8c3bbd, 0xfbd15c8, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_113) {
  // -4663582437977
  s21_decimal dec_1 = {{0xd32cb259, 0x43d, 0x0, 0x80000000}};
  // 79228162514264337593140416991
  s21_decimal dec_2 = {{0xe7f291df, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_114) {
  // -79228162514264337591612260967
  s21_decimal dec_1 = {{0x8cdcc267, 0xffffffff, 0xffffffff, 0x80000000}};
  // 8900660893433
  s21_decimal dec_2 = {{0x58bb16f9, 0x818, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_115) {
  // -485255623259867964634368
  s21_decimal dec_1 = {{0xba85f500, 0xc292785e, 0x66c1, 0x80000000}};
  // 79228162514264337592736499230
  s21_decimal dec_2 = {{0xcfdf461e, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_116) {
  // 79228162514264337593138577399
  s21_decimal dec_1 = {{0xe7d67ff7, 0xffffffff, 0xffffffff, 0x0}};
  // -9273242963749651
  s21_decimal dec_2 = {{0x20c52b13, 0x20f1f7, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_117) {
  // -79228162514264337593378714492
  s21_decimal dec_1 = {{0xf626b37c, 0xffffffff, 0xffffffff, 0x80000000}};
  // 414964863700077844132878
  s21_decimal dec_2 = {{0x67b0740e, 0x4a537d25, 0x57df, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_118) {
  // -79228162514264337592072527269
  s21_decimal dec_1 = {{0xa84bdda5, 0xffffffff, 0xffffffff, 0x80000000}};
  // 77792630269.60955607962494
  s21_decimal dec_2 = {{0x756d537e, 0xb196df05, 0x66f52, 0xe0000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_119) {
  // 79228162514264337593176489479
  s21_decimal dec_1 = {{0xea18fe07, 0xffffffff, 0xffffffff, 0x0}};
  // -8817170650572845895375
  s21_decimal dec_2 = {{0xe2564ecf, 0xfad2c752, 0x1dd, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_120) {
  // -79228162514264337593123390588
  s21_decimal dec_1 = {{0xe6eec47c, 0xffffffff, 0xffffffff, 0x80000000}};
  // 73858169390578421365748
  s21_decimal dec_2 = {{0xe7e27bf4, 0xdc00af60, 0xfa3, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_121) {
  // 796206534836455319
  s21_decimal dec_1 = {{0xfcc58797, 0xb0cb19f, 0x0, 0x0}};
  // -79228162514264337592030819643
  s21_decimal dec_2 = {{0xa5cf753b, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_122) {
  // 79228162514264337593134594071
  s21_decimal dec_1 = {{0xe799b817, 0xffffffff, 0xffffffff, 0x0}};
  // -97250331383.44
  s21_decimal dec_2 = {{0x492548a8, 0x8d8, 0x0, 0x80020000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_123) {
  // 208845427647374
  s21_decimal dec_1 = {{0x9d87238e, 0xbdf1, 0x0, 0x0}};
  // -79228162514264337591806717379
  s21_decimal dec_2 = {{0x9873edc3, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_124) {
  // 79228162514264337591911054774
  s21_decimal dec_1 = {{0x9eabfdb6, 0xffffffff, 0xffffffff, 0x0}};
  // -7633309780095924
  s21_decimal dec_2 = {{0x6de733b4, 0x1b1e74, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_125) {
  // 79228162514264337591692066653
  s21_decimal dec_1 = {{0x919e7f5d, 0xffffffff, 0xffffffff, 0x0}};
  // -9043446988957186945
  s21_decimal dec_2 = {{0x49de7b81, 0x7d80c71f, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_126) {
  // -8980101630851539
  s21_decimal dec_1 = {{0xd7c0f9d3, 0x1fe75a, 0x0, 0x80000000}};
  // 79228162514264337592053374079
  s21_decimal dec_2 = {{0xa7279c7f, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_127) {
  // 4308627843034
  s21_decimal dec_1 = {{0x2e3b67da, 0x3eb, 0x0, 0x0}};
  // -79228162514264337592232468184
  s21_decimal dec_2 = {{0xb1d45ed8, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_128) {
  // -79228162514264337591472422644
  s21_decimal dec_1 = {{0x8486fef4, 0xffffffff, 0xffffffff, 0x80000000}};
  // 27531876917471044
  s21_decimal dec_2 = {{0x9faa6744, 0x61d018, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_129) {
  // -4559655819
  s21_decimal dec_1 = {{0xfc6d38b, 0x1, 0x0, 0x80000000}};
  // 79228162514264337593023219787
  s21_decimal dec_2 = {{0xe0f6484b, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_130) {
  // 569432586759140133022
  s21_decimal dec_1 = {{0x9e59c89e, 0xde76f0ac, 0x1e, 0x0}};
  // -79228162514264337592299703392
  s21_decimal dec_2 = {{0xb5d64c60, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_131) {
  // -79228162514264337593330085575
  s21_decimal dec_1 = {{0xf340aec7, 0xffffffff, 0xffffffff, 0x80000000}};
  // 266066782089.26001655099796
  s21_decimal dec_2 = {{0x1c96b194, 0xea744b6c, 0x16022e, 0xe0000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_132) {
  // -79228162514264337592006302217
  s21_decimal dec_1 = {{0xa4595a09, 0xffffffff, 0xffffffff, 0x80000000}};
  // 7025099612024.945770743
  s21_decimal dec_2 = {{0x516400f7, 0xd4d77c90, 0x17c, 0x90000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_133) {
  // 79228162514264337592952902203
  s21_decimal dec_1 = {{0xdcc5523b, 0xffffffff, 0xffffffff, 0x0}};
  // -902369899028358
  s21_decimal dec_2 = {{0x5d499f86, 0x334b3, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_134) {
  // -61046381648305175.509198587
  s21_decimal dec_1 = {{0xc9d9e6fb, 0xfaf335ac, 0x327f12, 0x80090000}};
  // 79228162514264337593485202895
  s21_decimal dec_2 = {{0xfc7f95cf, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_135) {
  // -9848374764174712
  s21_decimal dec_1 = {{0x6f6efd78, 0x22fd0b, 0x0, 0x80000000}};
  // 79228162514264337593329344402
  s21_decimal dec_2 = {{0xf3355f92, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_136) {
  // 48748071309677441367449
  s21_decimal dec_1 = {{0xef20bd99, 0xa363c1cc, 0xa52, 0x0}};
  // -79228162514264337592224516310
  s21_decimal dec_2 = {{0xb15b08d6, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_137) {
  // 40005586061865380345598
  s21_decimal dec_1 = {{0x6459f6fe, 0xb508d496, 0x878, 0x0}};
  // -79228162514264337593085354704
  s21_decimal dec_2 = {{0xe4aa62d0, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_138) {
  // -79228162514264337592258531259
  s21_decimal dec_1 = {{0xb3620fbb, 0xffffffff, 0xffffffff, 0x80000000}};
  // 9206337315566911052874791235
  s21_decimal dec_2 = {{0x14843943, 0xe89a0c7e, 0x1dbf4dc1, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_139) {
  // -1967449642227636
  s21_decimal dec_1 = {{0x9109d7b4, 0x6fd62, 0x0, 0x80000000}};
  // 79228162514264337592049277587
  s21_decimal dec_2 = {{0xa6e91a93, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_140) {
  // -62875425533105773375
  s21_decimal dec_1 = {{0xe24b9b3f, 0x68926264, 0x3, 0x80000000}};
  // 79228162514264337593460363750
  s21_decimal dec_2 = {{0xfb0491e6, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_141) {
  // 720051001935
  s21_decimal dec_1 = {{0xa6625a4f, 0xa7, 0x0, 0x0}};
  // -79228162514264337592013079773
  s21_decimal dec_2 = {{0xa4c0c4dd, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_142) {
  // 79228162514264337593308310236
  s21_decimal dec_1 = {{0xf1f46adc, 0xffffffff, 0xffffffff, 0x0}};
  // -328331688045
  s21_decimal dec_2 = {{0x7217f86d, 0x4c, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_143) {
  // 3493572711338551602
  s21_decimal dec_1 = {{0x8552932, 0x307ba9df, 0x0, 0x0}};
  // -79228162514264337591572234114
  s21_decimal dec_2 = {{0x8a79ff82, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_144) {
  // -79228162514264337593443134775
  s21_decimal dec_1 = {{0xf9fdad37, 0xffffffff, 0xffffffff, 0x80000000}};
  // 5314261215813460310
  s21_decimal dec_2 = {{0x6c326156, 0x49c00c6b, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_145) {
  // 7411954373913862240863629
  s21_decimal dec_1 = {{0xd3fe058d, 0xda0ad956, 0x6218a, 0x0}};
  // -79228162514264337591684160349
  s21_decimal dec_2 = {{0x9125db5d, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_146) {
  // -2458247064948567662174
  s21_decimal dec_1 = {{0x35fb5e5e, 0x4307f938, 0x85, 0x80000000}};
  // 79228162514264337591451081347
  s21_decimal dec_2 = {{0x83415a83, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_147) {
  // 79228162514264337592001891840
  s21_decimal dec_1 = {{0xa4160e00, 0xffffffff, 0xffffffff, 0x0}};
  // -75431566471275208718
  s21_decimal dec_2 = {{0x539fe00e, 0x16d2c20d, 0x4, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_148) {
  // 79228162514264337592873097378
  s21_decimal dec_1 = {{0xd80398a2, 0xffffffff, 0xffffffff, 0x0}};
  // -5427948771485
  s21_decimal dec_2 = {{0xcaf5589d, 0x4ef, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_149) {
  // -79228162514264337593299486850
  s21_decimal dec_1 = {{0xf16dc882, 0xffffffff, 0xffffffff, 0x80000000}};
  // 731729203362606.19
  s21_decimal dec_2 = {{0x23d21e0b, 0x103f662, 0x0, 0x20000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_150) {
  // 8928094647563
  s21_decimal dec_1 = {{0xbbe8f50b, 0x81e, 0x0, 0x0}};
  // -79228162514264337591984236530
  s21_decimal dec_2 = {{0xa308a7f2, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_151) {
  // 79228162514264337592938371279
  s21_decimal dec_1 = {{0xdbe798cf, 0xffffffff, 0xffffffff, 0x0}};
  // -1887520818029069334643058174
  s21_decimal dec_2 = {{0xb6c9a5fe, 0x937095f6, 0x6195214, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_152) {
  // -472666978270703
  s21_decimal dec_1 = {{0x5b563def, 0x1ade3, 0x0, 0x80000000}};
  // 79228162514264337591642588536
  s21_decimal dec_2 = {{0x8eab8578, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_153) {
  // 79228162514264337592040686048
  s21_decimal dec_1 = {{0xa66601e0, 0xffffffff, 0xffffffff, 0x0}};
  // -3662548416289548357257920816
  s21_decimal dec_2 = {{0x2a80130, 0x7d1cfd68, 0xbd596cb, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_154) {
  // -37770010454937
  s21_decimal dec_1 = {{0x40e6b99, 0x225a, 0x0, 0x80000000}};
  // 79228162514264337593009316864
  s21_decimal dec_2 = {{0xe0222400, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_155) {
  // -79228162514264337591820971564
  s21_decimal dec_1 = {{0x994d6e2c, 0xffffffff, 0xffffffff, 0x80000000}};
  // 126319776832334292040
  s21_decimal dec_2 = {{0x15e76448, 0xd909ffc2, 0x6, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_156) {
  // 54308941374423625231
  s21_decimal dec_1 = {{0x5e08ee0f, 0xf1b01e70, 0x2, 0x0}};
  // -79228162514264337592985288414
  s21_decimal dec_2 = {{0xdeb37ede, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_157) {
  // 79228162514264337593219818502
  s21_decimal dec_1 = {{0xecae2406, 0xffffffff, 0xffffffff, 0x0}};
  // -487866229545776491415171
  s21_decimal dec_2 = {{0xa61e4683, 0x480321d1, 0x674f, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_158) {
  // -923069117
  s21_decimal dec_1 = {{0x3704eabd, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593454441747
  s21_decimal dec_2 = {{0xfaaa3513, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_159) {
  // -79228162514264337593087929918
  s21_decimal dec_1 = {{0xe4d1ae3e, 0xffffffff, 0xffffffff, 0x80000000}};
  // 27327169148777878590.2
  s21_decimal dec_2 = {{0x7b314a6e, 0xd068138d, 0xe, 0x10000}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_160) {
  // -76696670700282148234
  s21_decimal dec_1 = {{0x416d758a, 0x28614fa5, 0x4, 0x80000000}};
  // 79228162514264337592173931648
  s21_decimal dec_2 = {{0xae572c80, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_161) {
  // -79228162514264337592593927519
  s21_decimal dec_1 = {{0xc75fcd5f, 0xffffffff, 0xffffffff, 0x80000000}};
  // 2012722581561
  s21_decimal dec_2 = {{0x9f9d5039, 0x1d4, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_162) {
  // 79228162514264337592136478613
  s21_decimal dec_1 = {{0xac1baf95, 0xffffffff, 0xffffffff, 0x0}};
  // -32648464780216
  s21_decimal dec_2 = {{0x90254bb8, 0x1db1, 0x0, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_163) {
  // 79228162514264337593233301003
  s21_decimal dec_1 = {{0xed7bde0b, 0xffffffff, 0xffffffff, 0x0}};
  // -917716884461823113596
  s21_decimal dec_2 = {{0x452ab97c, 0xbfe15425, 0x31, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_164) {
  // 2059982071761122737620234
  s21_decimal dec_1 = {{0xfed850a, 0xda146df6, 0x1b437, 0x0}};
  // -79228162514264337591496865106
  s21_decimal dec_2 = {{0x85fbf552, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_165) {
  // 17610362204453107801886055
  s21_decimal dec_1 = {{0x8d698d67, 0xa5e46453, 0xe9123, 0x0}};
  // -79228162514264337592688698960
  s21_decimal dec_2 = {{0xcd05e650, 0xffffffff, 0xffffffff, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 1;  // Результат слишком велик или положительная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_sub_166) {
  // -1633736311.0976389756
  s21_decimal dec_1 = {{0xbc51827c, 0xe2b9f930, 0x0, 0x800a0000}};
  // 79228162514264337593135471440
  s21_decimal dec_2 = {{0xe7a71b50, 0xffffffff, 0xffffffff, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2;  // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_sub(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

Suite *suite_s21_sub() {
  Suite *c = suite_create("s21_sub_cases");
  TCase *tc = tcase_create("s21_sub_tc");

  tcase_add_test(tc, invalid_dec_s21_sub_1);
  tcase_add_test(tc, invalid_dec_s21_sub_2);
  tcase_add_test(tc, invalid_dec_s21_sub_3);
  tcase_add_test(tc, invalid_dec_s21_sub_4);
  tcase_add_test(tc, invalid_dec_s21_sub_5);
  tcase_add_test(tc, invalid_dec_s21_sub_6);
  tcase_add_test(tc, invalid_dec_s21_sub_7);
  tcase_add_test(tc, invalid_dec_s21_sub_8);
  tcase_add_test(tc, invalid_dec_s21_sub_9);
  tcase_add_test(tc, invalid_dec_s21_sub_10);
  tcase_add_test(tc, invalid_dec_s21_sub_11);
  tcase_add_test(tc, invalid_dec_s21_sub_12);
  tcase_add_test(tc, invalid_dec_s21_sub_13);
  tcase_add_test(tc, invalid_dec_s21_sub_14);
  tcase_add_test(tc, invalid_dec_s21_sub_15);
  tcase_add_test(tc, invalid_dec_s21_sub_16);
  tcase_add_test(tc, s21_sub_1);
  tcase_add_test(tc, s21_sub_2);
  tcase_add_test(tc, s21_sub_3);
  tcase_add_test(tc, s21_sub_4);
  tcase_add_test(tc, s21_sub_5);
  tcase_add_test(tc, s21_sub_6);
  tcase_add_test(tc, s21_sub_7);
  tcase_add_test(tc, s21_sub_8);
  tcase_add_test(tc, s21_sub_9);
  tcase_add_test(tc, s21_sub_10);
  tcase_add_test(tc, s21_sub_11);
  tcase_add_test(tc, s21_sub_12);
  tcase_add_test(tc, s21_sub_13);
  tcase_add_test(tc, s21_sub_14);
  tcase_add_test(tc, s21_sub_15);
  tcase_add_test(tc, s21_sub_16);
  tcase_add_test(tc, s21_sub_17);
  tcase_add_test(tc, s21_sub_18);
  tcase_add_test(tc, s21_sub_19);
  tcase_add_test(tc, s21_sub_20);
  tcase_add_test(tc, s21_sub_21);
  tcase_add_test(tc, s21_sub_22);
  tcase_add_test(tc, s21_sub_23);
  tcase_add_test(tc, s21_sub_24);
  tcase_add_test(tc, s21_sub_25);
  tcase_add_test(tc, s21_sub_26);
  tcase_add_test(tc, s21_sub_27);
  tcase_add_test(tc, s21_sub_28);
  tcase_add_test(tc, s21_sub_29);
  tcase_add_test(tc, s21_sub_30);
  tcase_add_test(tc, s21_sub_31);
  tcase_add_test(tc, s21_sub_32);
  tcase_add_test(tc, s21_sub_33);
  tcase_add_test(tc, s21_sub_34);
  tcase_add_test(tc, s21_sub_36);
  tcase_add_test(tc, s21_sub_37);
  tcase_add_test(tc, s21_sub_38);
  tcase_add_test(tc, s21_sub_39);
  tcase_add_test(tc, s21_sub_40);
  tcase_add_test(tc, s21_sub_41);
  tcase_add_test(tc, s21_sub_42);
  tcase_add_test(tc, s21_sub_43);
  tcase_add_test(tc, s21_sub_44);
  tcase_add_test(tc, s21_sub_45);
  tcase_add_test(tc, s21_sub_46);
  tcase_add_test(tc, s21_sub_47);
  tcase_add_test(tc, s21_sub_48);
  tcase_add_test(tc, s21_sub_49);
  tcase_add_test(tc, s21_sub_50);
  tcase_add_test(tc, s21_sub_51);
  tcase_add_test(tc, s21_sub_52);
  tcase_add_test(tc, s21_sub_53);
  tcase_add_test(tc, s21_sub_55);
  tcase_add_test(tc, s21_sub_56);
  tcase_add_test(tc, s21_sub_57);
  tcase_add_test(tc, s21_sub_59);
  tcase_add_test(tc, s21_sub_60);
  tcase_add_test(tc, s21_sub_61);
  tcase_add_test(tc, s21_sub_62);
  tcase_add_test(tc, s21_sub_63);
  tcase_add_test(tc, s21_sub_64);
  tcase_add_test(tc, s21_sub_65);
  tcase_add_test(tc, s21_sub_66);
  tcase_add_test(tc, s21_sub_67);
  tcase_add_test(tc, s21_sub_68);
  tcase_add_test(tc, s21_sub_69);
  tcase_add_test(tc, s21_sub_70);
  tcase_add_test(tc, s21_sub_71);
  tcase_add_test(tc, s21_sub_72);
  tcase_add_test(tc, s21_sub_73);
  tcase_add_test(tc, s21_sub_74);
  tcase_add_test(tc, s21_sub_75);
  tcase_add_test(tc, s21_sub_76);
  tcase_add_test(tc, s21_sub_77);
  tcase_add_test(tc, s21_sub_78);
  tcase_add_test(tc, s21_sub_79);
  tcase_add_test(tc, s21_sub_80);
  tcase_add_test(tc, s21_sub_81);
  tcase_add_test(tc, s21_sub_82);
  tcase_add_test(tc, s21_sub_83);
  tcase_add_test(tc, s21_sub_84);
  tcase_add_test(tc, s21_sub_85);
  tcase_add_test(tc, s21_sub_86);
  tcase_add_test(tc, s21_sub_87);
  tcase_add_test(tc, s21_sub_88);
  tcase_add_test(tc, s21_sub_89);
  tcase_add_test(tc, s21_sub_90);
  tcase_add_test(tc, s21_sub_91);
  tcase_add_test(tc, s21_sub_92);
  tcase_add_test(tc, s21_sub_93);
  tcase_add_test(tc, s21_sub_94);
  tcase_add_test(tc, s21_sub_95);
  tcase_add_test(tc, s21_sub_96);
  tcase_add_test(tc, s21_sub_97);
  tcase_add_test(tc, s21_sub_99);
  tcase_add_test(tc, s21_sub_100);
  tcase_add_test(tc, s21_sub_101);
  tcase_add_test(tc, s21_sub_102);
  tcase_add_test(tc, s21_sub_103);
  tcase_add_test(tc, s21_sub_104);
  tcase_add_test(tc, s21_sub_105);
  tcase_add_test(tc, s21_sub_106);
  tcase_add_test(tc, s21_sub_107);
  tcase_add_test(tc, s21_sub_108);
  tcase_add_test(tc, s21_sub_109);
  tcase_add_test(tc, s21_sub_110);
  tcase_add_test(tc, s21_sub_111);
  tcase_add_test(tc, s21_sub_112);
  tcase_add_test(tc, s21_sub_113);
  tcase_add_test(tc, s21_sub_114);
  tcase_add_test(tc, s21_sub_115);
  tcase_add_test(tc, s21_sub_116);
  tcase_add_test(tc, s21_sub_117);
  tcase_add_test(tc, s21_sub_118);
  tcase_add_test(tc, s21_sub_119);
  tcase_add_test(tc, s21_sub_120);
  tcase_add_test(tc, s21_sub_121);
  tcase_add_test(tc, s21_sub_122);
  tcase_add_test(tc, s21_sub_123);
  tcase_add_test(tc, s21_sub_124);
  tcase_add_test(tc, s21_sub_125);
  tcase_add_test(tc, s21_sub_126);
  tcase_add_test(tc, s21_sub_128);
  tcase_add_test(tc, s21_sub_129);
  tcase_add_test(tc, s21_sub_130);
  tcase_add_test(tc, s21_sub_131);
  tcase_add_test(tc, s21_sub_132);
  tcase_add_test(tc, s21_sub_133);
  tcase_add_test(tc, s21_sub_134);
  tcase_add_test(tc, s21_sub_135);
  tcase_add_test(tc, s21_sub_136);
  tcase_add_test(tc, s21_sub_137);
  tcase_add_test(tc, s21_sub_138);
  tcase_add_test(tc, s21_sub_139);
  tcase_add_test(tc, s21_sub_140);
  tcase_add_test(tc, s21_sub_141);
  tcase_add_test(tc, s21_sub_142);
  tcase_add_test(tc, s21_sub_143);
  tcase_add_test(tc, s21_sub_144);
  tcase_add_test(tc, s21_sub_145);
  tcase_add_test(tc, s21_sub_146);
  tcase_add_test(tc, s21_sub_147);
  tcase_add_test(tc, s21_sub_148);
  tcase_add_test(tc, s21_sub_149);
  tcase_add_test(tc, s21_sub_151);
  tcase_add_test(tc, s21_sub_152);
  tcase_add_test(tc, s21_sub_153);
  tcase_add_test(tc, s21_sub_154);
  tcase_add_test(tc, s21_sub_155);
  tcase_add_test(tc, s21_sub_156);
  tcase_add_test(tc, s21_sub_157);
  tcase_add_test(tc, s21_sub_158);
  tcase_add_test(tc, s21_sub_159);
  tcase_add_test(tc, s21_sub_160);
  tcase_add_test(tc, s21_sub_161);
  tcase_add_test(tc, s21_sub_162);
  tcase_add_test(tc, s21_sub_163);
  tcase_add_test(tc, s21_sub_164);
  tcase_add_test(tc, s21_sub_165);
  tcase_add_test(tc, s21_sub_166);
  tcase_add_test(tc, s21_sub_167);
  tcase_add_test(tc, s21_sub_168);
  tcase_add_test(tc, s21_sub_169);
  tcase_add_test(tc, s21_sub_170);
  tcase_add_test(tc, s21_sub_171);
  tcase_add_test(tc, s21_sub_172);
  tcase_add_test(tc, s21_sub_173);
  tcase_add_test(tc, s21_sub_174);
  tcase_add_test(tc, s21_sub_175);
  tcase_add_test(tc, s21_sub_176);
  tcase_add_test(tc, s21_sub_178);
  tcase_add_test(tc, s21_sub_179);
  tcase_add_test(tc, s21_sub_180);
  tcase_add_test(tc, s21_sub_182);
  tcase_add_test(tc, s21_sub_183);
  tcase_add_test(tc, s21_sub_184);
  tcase_add_test(tc, s21_sub_185);
  tcase_add_test(tc, s21_sub_186);
  tcase_add_test(tc, s21_sub_187);
  tcase_add_test(tc, s21_sub_188);
  tcase_add_test(tc, s21_sub_190);
  tcase_add_test(tc, s21_sub_191);
  tcase_add_test(tc, s21_sub_192);
  tcase_add_test(tc, s21_sub_193);
  tcase_add_test(tc, s21_sub_194);
  tcase_add_test(tc, s21_sub_195);
  tcase_add_test(tc, s21_sub_196);
  tcase_add_test(tc, s21_sub_197);
  tcase_add_test(tc, s21_sub_199);
  tcase_add_test(tc, s21_sub_200);
  tcase_add_test(tc, s21_sub_201);
  tcase_add_test(tc, s21_sub_202);
  tcase_add_test(tc, s21_sub_203);
  tcase_add_test(tc, s21_sub_204);
  tcase_add_test(tc, s21_sub_205);
  tcase_add_test(tc, s21_sub_206);
  tcase_add_test(tc, s21_sub_207);
  tcase_add_test(tc, s21_sub_208);
  tcase_add_test(tc, s21_sub_209);
  tcase_add_test(tc, s21_sub_210);
  tcase_add_test(tc, s21_sub_211);
  tcase_add_test(tc, s21_sub_212);
  tcase_add_test(tc, s21_sub_213);
  tcase_add_test(tc, s21_sub_214);
  tcase_add_test(tc, s21_sub_215);
  tcase_add_test(tc, s21_sub_216);
  tcase_add_test(tc, s21_sub_217);
  tcase_add_test(tc, s21_sub_218);
  tcase_add_test(tc, s21_sub_219);
  tcase_add_test(tc, s21_sub_220);
  tcase_add_test(tc, s21_sub_221);
  tcase_add_test(tc, s21_sub_222);
  tcase_add_test(tc, s21_sub_223);
  tcase_add_test(tc, s21_sub_224);
  tcase_add_test(tc, s21_sub_225);
  tcase_add_test(tc, s21_sub_226);
  tcase_add_test(tc, s21_sub_227);
  tcase_add_test(tc, s21_sub_228);
  tcase_add_test(tc, s21_sub_229);
  tcase_add_test(tc, s21_sub_230);
  tcase_add_test(tc, s21_sub_232);
  tcase_add_test(tc, s21_sub_233);
  tcase_add_test(tc, s21_sub_234);
  tcase_add_test(tc, s21_sub_235);
  tcase_add_test(tc, s21_sub_236);
  tcase_add_test(tc, s21_sub_237);
  tcase_add_test(tc, s21_sub_238);
  tcase_add_test(tc, s21_sub_239);
  tcase_add_test(tc, s21_sub_240);
  tcase_add_test(tc, s21_sub_241);
  tcase_add_test(tc, s21_sub_242);
  tcase_add_test(tc, s21_sub_243);
  tcase_add_test(tc, s21_sub_244);
  tcase_add_test(tc, s21_sub_245);
  tcase_add_test(tc, s21_sub_246);
  tcase_add_test(tc, s21_sub_247);
  tcase_add_test(tc, s21_sub_248);
  tcase_add_test(tc, s21_sub_249);
  tcase_add_test(tc, s21_sub_250);
  tcase_add_test(tc, s21_sub_251);
  tcase_add_test(tc, s21_sub_252);
  tcase_add_test(tc, s21_sub_253);
  tcase_add_test(tc, s21_sub_254);
  tcase_add_test(tc, s21_sub_255);
  tcase_add_test(tc, s21_sub_256);
  tcase_add_test(tc, s21_sub_257);
  tcase_add_test(tc, s21_sub_258);
  tcase_add_test(tc, s21_sub_259);
  tcase_add_test(tc, s21_sub_260);
  tcase_add_test(tc, s21_sub_261);
  tcase_add_test(tc, s21_sub_263);
  tcase_add_test(tc, s21_sub_264);
  tcase_add_test(tc, s21_sub_265);
  tcase_add_test(tc, s21_sub_266);
  tcase_add_test(tc, s21_sub_267);
  tcase_add_test(tc, s21_sub_268);
  tcase_add_test(tc, s21_sub_269);
  tcase_add_test(tc, s21_sub_270);
  tcase_add_test(tc, s21_sub_271);
  tcase_add_test(tc, s21_sub_272);
  tcase_add_test(tc, s21_sub_273);
  tcase_add_test(tc, s21_sub_274);
  tcase_add_test(tc, s21_sub_275);
  tcase_add_test(tc, s21_sub_276);
  tcase_add_test(tc, s21_sub_277);
  tcase_add_test(tc, s21_sub_278);
  tcase_add_test(tc, s21_sub_279);
  tcase_add_test(tc, s21_sub_280);
  tcase_add_test(tc, s21_sub_281);
  tcase_add_test(tc, s21_sub_282);
  tcase_add_test(tc, s21_sub_283);
  tcase_add_test(tc, s21_sub_284);
  tcase_add_test(tc, s21_sub_285);
  tcase_add_test(tc, s21_sub_286);
  tcase_add_test(tc, s21_sub_287);
  tcase_add_test(tc, s21_sub_288);
  tcase_add_test(tc, s21_sub_289);
  tcase_add_test(tc, s21_sub_290);
  tcase_add_test(tc, s21_sub_291);
  tcase_add_test(tc, s21_sub_292);
  tcase_add_test(tc, s21_sub_294);
  tcase_add_test(tc, s21_sub_295);
  tcase_add_test(tc, s21_sub_296);
  tcase_add_test(tc, s21_sub_297);
  tcase_add_test(tc, s21_sub_299);
  tcase_add_test(tc, s21_sub_300);
  tcase_add_test(tc, s21_sub_301);
  tcase_add_test(tc, s21_sub_302);
  tcase_add_test(tc, s21_sub_303);
  tcase_add_test(tc, s21_sub_304);
  tcase_add_test(tc, s21_sub_305);
  tcase_add_test(tc, s21_sub_306);
  tcase_add_test(tc, s21_sub_307);
  tcase_add_test(tc, s21_sub_308);
  tcase_add_test(tc, s21_sub_309);
  tcase_add_test(tc, s21_sub_310);
  tcase_add_test(tc, s21_sub_311);
  tcase_add_test(tc, s21_sub_312);
  tcase_add_test(tc, s21_sub_313);
  tcase_add_test(tc, s21_sub_314);
  tcase_add_test(tc, s21_sub_315);
  tcase_add_test(tc, s21_sub_316);
  tcase_add_test(tc, s21_sub_317);
  tcase_add_test(tc, s21_sub_318);
  tcase_add_test(tc, s21_sub_319);
  tcase_add_test(tc, s21_sub_320);
  tcase_add_test(tc, s21_sub_321);
  tcase_add_test(tc, s21_sub_322);
  tcase_add_test(tc, s21_sub_323);
  tcase_add_test(tc, s21_sub_324);
  tcase_add_test(tc, s21_sub_326);
  tcase_add_test(tc, s21_sub_327);
  tcase_add_test(tc, s21_sub_328);
  tcase_add_test(tc, s21_sub_329);
  tcase_add_test(tc, s21_sub_330);
  tcase_add_test(tc, s21_sub_331);
  tcase_add_test(tc, s21_sub_332);
  tcase_add_test(tc, s21_sub_333);
  tcase_add_test(tc, s21_sub_334);
  tcase_add_test(tc, s21_sub_335);
  tcase_add_test(tc, s21_sub_336);
  tcase_add_test(tc, s21_sub_337);
  tcase_add_test(tc, s21_sub_338);
  tcase_add_test(tc, s21_sub_339);
  tcase_add_test(tc, s21_sub_340);
  tcase_add_test(tc, s21_sub_341);
  tcase_add_test(tc, s21_sub_342);
  tcase_add_test(tc, s21_sub_343);
  tcase_add_test(tc, s21_sub_344);
  tcase_add_test(tc, s21_sub_345);
  tcase_add_test(tc, s21_sub_346);
  tcase_add_test(tc, s21_sub_347);
  tcase_add_test(tc, s21_sub_348);
  tcase_add_test(tc, s21_sub_350);
  tcase_add_test(tc, s21_sub_351);
  tcase_add_test(tc, s21_sub_352);
  tcase_add_test(tc, s21_sub_353);
  tcase_add_test(tc, s21_sub_354);
  tcase_add_test(tc, s21_sub_356);
  tcase_add_test(tc, s21_sub_357);
  tcase_add_test(tc, s21_sub_358);
  tcase_add_test(tc, s21_sub_359);
  tcase_add_test(tc, s21_sub_360);
  tcase_add_test(tc, s21_sub_361);
  tcase_add_test(tc, s21_sub_362);
  tcase_add_test(tc, s21_sub_363);
  tcase_add_test(tc, s21_sub_364);
  tcase_add_test(tc, s21_sub_365);
  tcase_add_test(tc, s21_sub_366);
  tcase_add_test(tc, s21_sub_367);
  tcase_add_test(tc, s21_sub_368);
  tcase_add_test(tc, s21_sub_369);
  tcase_add_test(tc, s21_sub_370);
  tcase_add_test(tc, s21_sub_371);
  tcase_add_test(tc, s21_sub_372);
  tcase_add_test(tc, s21_sub_373);
  tcase_add_test(tc, s21_sub_374);
  tcase_add_test(tc, s21_sub_375);
  tcase_add_test(tc, s21_sub_376);
  tcase_add_test(tc, s21_sub_377);
  tcase_add_test(tc, s21_sub_378);
  tcase_add_test(tc, s21_sub_381);
  tcase_add_test(tc, s21_sub_382);
  tcase_add_test(tc, s21_sub_383);
  tcase_add_test(tc, s21_sub_384);
  tcase_add_test(tc, s21_sub_385);
  tcase_add_test(tc, s21_sub_386);
  tcase_add_test(tc, s21_sub_387);
  tcase_add_test(tc, s21_sub_388);
  tcase_add_test(tc, s21_sub_389);
  tcase_add_test(tc, s21_sub_390);
  tcase_add_test(tc, s21_sub_391);
  tcase_add_test(tc, s21_sub_392);
  tcase_add_test(tc, s21_sub_393);
  tcase_add_test(tc, s21_sub_394);
  tcase_add_test(tc, s21_sub_395);
  tcase_add_test(tc, s21_sub_396);
  tcase_add_test(tc, s21_sub_397);
  tcase_add_test(tc, s21_sub_398);
  tcase_add_test(tc, s21_sub_399);
  tcase_add_test(tc, s21_sub_400);
  tcase_add_test(tc, s21_sub_401);
  tcase_add_test(tc, s21_sub_402);
  tcase_add_test(tc, s21_sub_403);
  tcase_add_test(tc, s21_sub_404);
  tcase_add_test(tc, s21_sub_405);
  tcase_add_test(tc, s21_sub_406);
  tcase_add_test(tc, s21_sub_407);
  tcase_add_test(tc, s21_sub_408);
  tcase_add_test(tc, s21_sub_409);
  tcase_add_test(tc, s21_sub_410);
  tcase_add_test(tc, s21_sub_411);
  tcase_add_test(tc, s21_sub_412);
  tcase_add_test(tc, s21_sub_413);
  tcase_add_test(tc, s21_sub_414);
  tcase_add_test(tc, s21_sub_415);
  tcase_add_test(tc, s21_sub_416);
  tcase_add_test(tc, s21_sub_417);
  tcase_add_test(tc, s21_sub_418);
  tcase_add_test(tc, s21_sub_420);
  tcase_add_test(tc, s21_sub_421);
  tcase_add_test(tc, s21_sub_422);
  tcase_add_test(tc, s21_sub_423);
  tcase_add_test(tc, s21_sub_424);
  tcase_add_test(tc, s21_sub_425);
  tcase_add_test(tc, s21_sub_427);
  tcase_add_test(tc, s21_sub_428);
  tcase_add_test(tc, s21_sub_429);
  tcase_add_test(tc, s21_sub_430);
  tcase_add_test(tc, s21_sub_431);
  tcase_add_test(tc, s21_sub_432);
  tcase_add_test(tc, s21_sub_433);
  tcase_add_test(tc, s21_sub_434);
  tcase_add_test(tc, s21_sub_435);
  tcase_add_test(tc, s21_sub_436);
  tcase_add_test(tc, s21_sub_437);
  tcase_add_test(tc, s21_sub_438);
  tcase_add_test(tc, s21_sub_439);
  tcase_add_test(tc, s21_sub_440);
  tcase_add_test(tc, s21_sub_441);
  tcase_add_test(tc, s21_sub_442);
  tcase_add_test(tc, s21_sub_443);
  tcase_add_test(tc, s21_sub_444);
  tcase_add_test(tc, s21_sub_445);
  tcase_add_test(tc, s21_sub_446);
  tcase_add_test(tc, s21_sub_447);
  tcase_add_test(tc, s21_sub_448);
  tcase_add_test(tc, s21_sub_449);
  tcase_add_test(tc, s21_sub_450);
  tcase_add_test(tc, s21_sub_451);
  tcase_add_test(tc, s21_sub_452);
  tcase_add_test(tc, s21_sub_453);
  tcase_add_test(tc, s21_sub_454);
  tcase_add_test(tc, s21_sub_455);
  tcase_add_test(tc, s21_sub_456);
  tcase_add_test(tc, s21_sub_457);
  tcase_add_test(tc, s21_sub_458);
  tcase_add_test(tc, s21_sub_459);
  tcase_add_test(tc, s21_sub_460);
  tcase_add_test(tc, s21_sub_461);
  tcase_add_test(tc, s21_sub_464);
  tcase_add_test(tc, s21_sub_465);
  tcase_add_test(tc, s21_sub_466);
  tcase_add_test(tc, s21_sub_467);
  tcase_add_test(tc, s21_sub_468);
  tcase_add_test(tc, s21_sub_469);
  tcase_add_test(tc, s21_sub_470);
  tcase_add_test(tc, s21_sub_471);
  tcase_add_test(tc, s21_sub_473);
  tcase_add_test(tc, s21_sub_474);
  tcase_add_test(tc, s21_sub_475);
  tcase_add_test(tc, s21_sub_476);
  tcase_add_test(tc, s21_sub_477);
  tcase_add_test(tc, s21_sub_478);
  tcase_add_test(tc, s21_sub_479);
  tcase_add_test(tc, s21_sub_480);
  tcase_add_test(tc, s21_sub_481);
  tcase_add_test(tc, s21_sub_482);
  tcase_add_test(tc, s21_sub_483);
  tcase_add_test(tc, s21_sub_484);
  tcase_add_test(tc, s21_sub_485);
  tcase_add_test(tc, s21_sub_486);
  tcase_add_test(tc, s21_sub_487);
  tcase_add_test(tc, s21_sub_488);
  tcase_add_test(tc, s21_sub_489);
  tcase_add_test(tc, s21_sub_490);
  tcase_add_test(tc, s21_sub_492);
  tcase_add_test(tc, s21_sub_493);
  tcase_add_test(tc, s21_sub_494);
  tcase_add_test(tc, s21_sub_495);
  tcase_add_test(tc, s21_sub_496);
  tcase_add_test(tc, s21_sub_497);
  tcase_add_test(tc, s21_sub_498);
  tcase_add_test(tc, s21_sub_499);
  tcase_add_test(tc, s21_sub_500);
  tcase_add_test(tc, fail_s21_sub_1);
  tcase_add_test(tc, fail_s21_sub_2);
  tcase_add_test(tc, fail_s21_sub_3);
  tcase_add_test(tc, fail_s21_sub_4);
  tcase_add_test(tc, fail_s21_sub_5);
  tcase_add_test(tc, fail_s21_sub_6);
  tcase_add_test(tc, fail_s21_sub_7);
  tcase_add_test(tc, fail_s21_sub_8);
  tcase_add_test(tc, fail_s21_sub_9);
  tcase_add_test(tc, fail_s21_sub_10);
  tcase_add_test(tc, fail_s21_sub_11);
  tcase_add_test(tc, fail_s21_sub_12);
  tcase_add_test(tc, fail_s21_sub_13);
  tcase_add_test(tc, fail_s21_sub_14);
  tcase_add_test(tc, fail_s21_sub_15);
  tcase_add_test(tc, fail_s21_sub_16);
  tcase_add_test(tc, fail_s21_sub_17);
  tcase_add_test(tc, fail_s21_sub_18);
  tcase_add_test(tc, fail_s21_sub_19);
  tcase_add_test(tc, fail_s21_sub_20);
  tcase_add_test(tc, fail_s21_sub_21);
  tcase_add_test(tc, fail_s21_sub_22);
  tcase_add_test(tc, fail_s21_sub_23);
  tcase_add_test(tc, fail_s21_sub_24);
  tcase_add_test(tc, fail_s21_sub_25);
  tcase_add_test(tc, fail_s21_sub_26);
  tcase_add_test(tc, fail_s21_sub_27);
  tcase_add_test(tc, fail_s21_sub_28);
  tcase_add_test(tc, fail_s21_sub_29);
  tcase_add_test(tc, fail_s21_sub_30);
  tcase_add_test(tc, fail_s21_sub_31);
  tcase_add_test(tc, fail_s21_sub_32);
  tcase_add_test(tc, fail_s21_sub_33);
  tcase_add_test(tc, fail_s21_sub_34);
  tcase_add_test(tc, fail_s21_sub_35);
  tcase_add_test(tc, fail_s21_sub_36);
  tcase_add_test(tc, fail_s21_sub_37);
  tcase_add_test(tc, fail_s21_sub_38);
  tcase_add_test(tc, fail_s21_sub_39);
  tcase_add_test(tc, fail_s21_sub_40);
  tcase_add_test(tc, fail_s21_sub_41);
  tcase_add_test(tc, fail_s21_sub_42);
  tcase_add_test(tc, fail_s21_sub_43);
  tcase_add_test(tc, fail_s21_sub_44);
  tcase_add_test(tc, fail_s21_sub_45);
  tcase_add_test(tc, fail_s21_sub_46);
  tcase_add_test(tc, fail_s21_sub_47);
  tcase_add_test(tc, fail_s21_sub_48);
  tcase_add_test(tc, fail_s21_sub_49);
  tcase_add_test(tc, fail_s21_sub_50);
  tcase_add_test(tc, fail_s21_sub_51);
  tcase_add_test(tc, fail_s21_sub_52);
  tcase_add_test(tc, fail_s21_sub_53);
  tcase_add_test(tc, fail_s21_sub_54);
  tcase_add_test(tc, fail_s21_sub_55);
  tcase_add_test(tc, fail_s21_sub_56);
  tcase_add_test(tc, fail_s21_sub_57);
  tcase_add_test(tc, fail_s21_sub_58);
  tcase_add_test(tc, fail_s21_sub_59);
  tcase_add_test(tc, fail_s21_sub_60);
  tcase_add_test(tc, fail_s21_sub_61);
  tcase_add_test(tc, fail_s21_sub_62);
  tcase_add_test(tc, fail_s21_sub_63);
  tcase_add_test(tc, fail_s21_sub_64);
  tcase_add_test(tc, fail_s21_sub_65);
  tcase_add_test(tc, fail_s21_sub_66);
  tcase_add_test(tc, fail_s21_sub_67);
  tcase_add_test(tc, fail_s21_sub_68);
  tcase_add_test(tc, fail_s21_sub_69);
  tcase_add_test(tc, fail_s21_sub_70);
  tcase_add_test(tc, fail_s21_sub_71);
  tcase_add_test(tc, fail_s21_sub_72);
  tcase_add_test(tc, fail_s21_sub_73);
  tcase_add_test(tc, fail_s21_sub_74);
  tcase_add_test(tc, fail_s21_sub_75);
  tcase_add_test(tc, fail_s21_sub_76);
  tcase_add_test(tc, fail_s21_sub_77);
  tcase_add_test(tc, fail_s21_sub_78);
  tcase_add_test(tc, fail_s21_sub_79);
  tcase_add_test(tc, fail_s21_sub_80);
  tcase_add_test(tc, fail_s21_sub_81);
  tcase_add_test(tc, fail_s21_sub_82);
  tcase_add_test(tc, fail_s21_sub_83);
  tcase_add_test(tc, fail_s21_sub_84);
  tcase_add_test(tc, fail_s21_sub_85);
  tcase_add_test(tc, fail_s21_sub_86);
  tcase_add_test(tc, fail_s21_sub_87);
  tcase_add_test(tc, fail_s21_sub_88);
  tcase_add_test(tc, fail_s21_sub_89);
  tcase_add_test(tc, fail_s21_sub_90);
  tcase_add_test(tc, fail_s21_sub_91);
  tcase_add_test(tc, fail_s21_sub_92);
  tcase_add_test(tc, fail_s21_sub_93);
  tcase_add_test(tc, fail_s21_sub_94);
  tcase_add_test(tc, fail_s21_sub_95);
  tcase_add_test(tc, fail_s21_sub_96);
  tcase_add_test(tc, fail_s21_sub_97);
  tcase_add_test(tc, fail_s21_sub_98);
  tcase_add_test(tc, fail_s21_sub_99);
  tcase_add_test(tc, fail_s21_sub_100);
  tcase_add_test(tc, fail_s21_sub_101);
  tcase_add_test(tc, fail_s21_sub_102);
  tcase_add_test(tc, fail_s21_sub_103);
  tcase_add_test(tc, fail_s21_sub_104);
  tcase_add_test(tc, fail_s21_sub_105);
  tcase_add_test(tc, fail_s21_sub_106);
  tcase_add_test(tc, fail_s21_sub_107);
  tcase_add_test(tc, fail_s21_sub_108);
  tcase_add_test(tc, fail_s21_sub_109);
  tcase_add_test(tc, fail_s21_sub_110);
  tcase_add_test(tc, fail_s21_sub_111);
  tcase_add_test(tc, fail_s21_sub_112);
  tcase_add_test(tc, fail_s21_sub_113);
  tcase_add_test(tc, fail_s21_sub_114);
  tcase_add_test(tc, fail_s21_sub_115);
  tcase_add_test(tc, fail_s21_sub_116);
  tcase_add_test(tc, fail_s21_sub_117);
  tcase_add_test(tc, fail_s21_sub_118);
  tcase_add_test(tc, fail_s21_sub_119);
  tcase_add_test(tc, fail_s21_sub_120);
  tcase_add_test(tc, fail_s21_sub_121);
  tcase_add_test(tc, fail_s21_sub_122);
  tcase_add_test(tc, fail_s21_sub_123);
  tcase_add_test(tc, fail_s21_sub_124);
  tcase_add_test(tc, fail_s21_sub_125);
  tcase_add_test(tc, fail_s21_sub_126);
  tcase_add_test(tc, fail_s21_sub_127);
  tcase_add_test(tc, fail_s21_sub_128);
  tcase_add_test(tc, fail_s21_sub_129);
  tcase_add_test(tc, fail_s21_sub_130);
  tcase_add_test(tc, fail_s21_sub_131);
  tcase_add_test(tc, fail_s21_sub_132);
  tcase_add_test(tc, fail_s21_sub_133);
  tcase_add_test(tc, fail_s21_sub_134);
  tcase_add_test(tc, fail_s21_sub_135);
  tcase_add_test(tc, fail_s21_sub_136);
  tcase_add_test(tc, fail_s21_sub_137);
  tcase_add_test(tc, fail_s21_sub_138);
  tcase_add_test(tc, fail_s21_sub_139);
  tcase_add_test(tc, fail_s21_sub_140);
  tcase_add_test(tc, fail_s21_sub_141);
  tcase_add_test(tc, fail_s21_sub_142);
  tcase_add_test(tc, fail_s21_sub_143);
  tcase_add_test(tc, fail_s21_sub_144);
  tcase_add_test(tc, fail_s21_sub_145);
  tcase_add_test(tc, fail_s21_sub_146);
  tcase_add_test(tc, fail_s21_sub_147);
  tcase_add_test(tc, fail_s21_sub_148);
  tcase_add_test(tc, fail_s21_sub_149);
  tcase_add_test(tc, fail_s21_sub_150);
  tcase_add_test(tc, fail_s21_sub_151);
  tcase_add_test(tc, fail_s21_sub_152);
  tcase_add_test(tc, fail_s21_sub_153);
  tcase_add_test(tc, fail_s21_sub_154);
  tcase_add_test(tc, fail_s21_sub_155);
  tcase_add_test(tc, fail_s21_sub_156);
  tcase_add_test(tc, fail_s21_sub_157);
  tcase_add_test(tc, fail_s21_sub_158);
  tcase_add_test(tc, fail_s21_sub_159);
  tcase_add_test(tc, fail_s21_sub_160);
  tcase_add_test(tc, fail_s21_sub_161);
  tcase_add_test(tc, fail_s21_sub_162);
  tcase_add_test(tc, fail_s21_sub_163);
  tcase_add_test(tc, fail_s21_sub_164);
  tcase_add_test(tc, fail_s21_sub_165);
  tcase_add_test(tc, fail_s21_sub_166);

  suite_add_tcase(c, tc);
  return c;
}
