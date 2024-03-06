#include "../s21_tests.h"

// Проверка на неккоректные значения
// На вход подается пустой указатель на результирующий decimal
// Возвращаемое значение 1

START_TEST(s21_from_int_to_decimal_false) {
  // Указатель на decimal равен NULL
  int number = 73485735;
  int result = s21_from_int_to_decimal(number, NULL);

  ck_assert_int_eq(result, CONVERSION_ERROR);
}
END_TEST

// Проверка на корректные значения
// На вход подается число в пределах INT_MIN и INT_MAX, которое конвертируется в
// decimal Возвращаемое значение 0

START_TEST(s21_from_int_to_decimal_true_1) {
  // 34
  s21_decimal check = {{0x22, 0x0, 0x0, 0x0}};

  int number = 34;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_2) {
  // -214602426
  s21_decimal check = {{0xcca92ba, 0x0, 0x0, 0x80000000}};

  int number = -214602426;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_3) {
  // -1145601990
  s21_decimal check = {{0x44487fc6, 0x0, 0x0, 0x80000000}};

  int number = -1145601990;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_4) {
  // 1805123435
  s21_decimal check = {{0x6b97ff6b, 0x0, 0x0, 0x0}};

  int number = 1805123435;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_5) {
  // 1317520965
  s21_decimal check = {{0x4e87c645, 0x0, 0x0, 0x0}};

  int number = 1317520965;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_6) {
  // -1938560322
  s21_decimal check = {{0x738c1542, 0x0, 0x0, 0x80000000}};

  int number = -1938560322;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_7) {
  // -1785313466
  s21_decimal check = {{0x6a69b8ba, 0x0, 0x0, 0x80000000}};

  int number = -1785313466;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_8) {
  // 756692391
  s21_decimal check = {{0x2d1a35a7, 0x0, 0x0, 0x0}};

  int number = 756692391;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_9) {
  // 160380551
  s21_decimal check = {{0x98f3687, 0x0, 0x0, 0x0}};

  int number = 160380551;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_10) {
  // -1540822402
  s21_decimal check = {{0x5bd71582, 0x0, 0x0, 0x80000000}};

  int number = -1540822402;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_11) {
  // -195427890
  s21_decimal check = {{0xba5fe32, 0x0, 0x0, 0x80000000}};

  int number = -195427890;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_12) {
  // -938347272
  s21_decimal check = {{0x37ee0b08, 0x0, 0x0, 0x80000000}};

  int number = -938347272;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_13) {
  // -2016614964
  s21_decimal check = {{0x78331a34, 0x0, 0x0, 0x80000000}};

  int number = -2016614964;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_14) {
  // -359528936
  s21_decimal check = {{0x156df9e8, 0x0, 0x0, 0x80000000}};

  int number = -359528936;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_15) {
  // -62183050
  s21_decimal check = {{0x3b4d68a, 0x0, 0x0, 0x80000000}};

  int number = -62183050;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_16) {
  // -1415205736
  s21_decimal check = {{0x545a5368, 0x0, 0x0, 0x80000000}};

  int number = -1415205736;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_17) {
  // -395691674
  s21_decimal check = {{0x1795c69a, 0x0, 0x0, 0x80000000}};

  int number = -395691674;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_18) {
  // 1875273625
  s21_decimal check = {{0x6fc66799, 0x0, 0x0, 0x0}};

  int number = 1875273625;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_19) {
  // 153180033
  s21_decimal check = {{0x9215781, 0x0, 0x0, 0x0}};

  int number = 153180033;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_20) {
  // 2147483647
  s21_decimal check = {{0x7fffffff, 0x0, 0x0, 0x0}};

  int number = 2147483647;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_21) {
  // -2147483647 - 1
  s21_decimal check = {{0x80000000, 0x0, 0x0, 0x80000000}};

  int number = -2147483647 - 1;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_22) {
  // 1292146235
  s21_decimal check = {{0x4d04963b, 0x0, 0x0, 0x0}};

  int number = 1292146235;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_23) {
  // -1078882118
  s21_decimal check = {{0x404e6f46, 0x0, 0x0, 0x80000000}};

  int number = -1078882118;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_24) {
  // 23424
  s21_decimal check = {{0x5b80, 0x0, 0x0, 0x0}};

  int number = 23424;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_25) {
  // -896598657
  s21_decimal check = {{0x35710281, 0x0, 0x0, 0x80000000}};

  int number = -896598657;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_26) {
  // -1939751480
  s21_decimal check = {{0x739e4238, 0x0, 0x0, 0x80000000}};

  int number = -1939751480;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_27) {
  // -315295568
  s21_decimal check = {{0x12cb0750, 0x0, 0x0, 0x80000000}};

  int number = -315295568;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_28) {
  // 1942262643
  s21_decimal check = {{0x73c49373, 0x0, 0x0, 0x0}};

  int number = 1942262643;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_29) {
  // -354067792
  s21_decimal check = {{0x151aa550, 0x0, 0x0, 0x80000000}};

  int number = -354067792;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_30) {
  // 967241545
  s21_decimal check = {{0x39a6ef49, 0x0, 0x0, 0x0}};

  int number = 967241545;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_31) {
  // -188385664
  s21_decimal check = {{0xb3a8980, 0x0, 0x0, 0x80000000}};

  int number = -188385664;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_32) {
  // 832055583
  s21_decimal check = {{0x3198291f, 0x0, 0x0, 0x0}};

  int number = 832055583;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_33) {
  // 1843559659
  s21_decimal check = {{0x6de27ceb, 0x0, 0x0, 0x0}};

  int number = 1843559659;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_34) {
  // -2068866824
  s21_decimal check = {{0x7b506708, 0x0, 0x0, 0x80000000}};

  int number = -2068866824;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_35) {
  // -962889982
  s21_decimal check = {{0x396488fe, 0x0, 0x0, 0x80000000}};

  int number = -962889982;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_36) {
  // 1127436577
  s21_decimal check = {{0x43335121, 0x0, 0x0, 0x0}};

  int number = 1127436577;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_37) {
  // -1835297530
  s21_decimal check = {{0x6d646afa, 0x0, 0x0, 0x80000000}};

  int number = -1835297530;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_38) {
  // 1644957447
  s21_decimal check = {{0x620c0f07, 0x0, 0x0, 0x0}};

  int number = 1644957447;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_39) {
  // 1738115355
  s21_decimal check = {{0x6799891b, 0x0, 0x0, 0x0}};

  int number = 1738115355;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_40) {
  // -1219800326
  s21_decimal check = {{0x48b4ad06, 0x0, 0x0, 0x80000000}};

  int number = -1219800326;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_41) {
  // 77406113
  s21_decimal check = {{0x49d1fa1, 0x0, 0x0, 0x0}};

  int number = 77406113;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_42) {
  // -1041986334
  s21_decimal check = {{0x3e1b731e, 0x0, 0x0, 0x80000000}};

  int number = -1041986334;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_43) {
  // -34197264
  s21_decimal check = {{0x209cf10, 0x0, 0x0, 0x80000000}};

  int number = -34197264;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_44) {
  // 2026003945
  s21_decimal check = {{0x78c25de9, 0x0, 0x0, 0x0}};

  int number = 2026003945;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_45) {
  // -934103824
  s21_decimal check = {{0x37ad4b10, 0x0, 0x0, 0x80000000}};

  int number = -934103824;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_46) {
  // 105229613
  s21_decimal check = {{0x645ad2d, 0x0, 0x0, 0x0}};

  int number = 105229613;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_47) {
  // 1097605029
  s21_decimal check = {{0x416c1fa5, 0x0, 0x0, 0x0}};

  int number = 1097605029;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_48) {
  // 886655849
  s21_decimal check = {{0x34d94b69, 0x0, 0x0, 0x0}};

  int number = 886655849;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_true_49) {
  // 1297789555
  s21_decimal check = {{0x4d5ab273, 0x0, 0x0, 0x0}};

  int number = 1297789555;
  s21_decimal conversion = {0};

  int result = s21_from_int_to_decimal(number, &conversion);

  ck_assert_int_eq(result, CONVERSION_OK);
  ck_assert_uint_eq(check.bits[0], conversion.bits[0]);
  ck_assert_uint_eq(check.bits[1], conversion.bits[1]);
  ck_assert_uint_eq(check.bits[2], conversion.bits[2]);
  ck_assert_uint_eq(check.bits[3], conversion.bits[3]);
}
END_TEST

Suite *suite_s21_from_int_to_decimal() {
  Suite *suite = suite_create("s21_from_int_to_decimal");

  TCase *testsFalse = tcase_create("False Tests");
  tcase_add_test(testsFalse, s21_from_int_to_decimal_false);

  TCase *testsTrue = tcase_create("True Tests");
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_1);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_2);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_3);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_4);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_5);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_6);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_7);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_8);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_9);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_10);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_11);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_12);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_13);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_14);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_15);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_16);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_17);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_18);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_19);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_20);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_21);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_22);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_23);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_24);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_25);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_26);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_27);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_28);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_29);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_30);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_31);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_32);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_33);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_34);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_35);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_36);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_37);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_38);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_39);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_40);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_41);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_42);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_43);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_44);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_45);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_46);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_47);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_48);
  tcase_add_test(testsTrue, s21_from_int_to_decimal_true_49);

  suite_add_tcase(suite, testsFalse);
  suite_add_tcase(suite, testsTrue);

  return suite;
}