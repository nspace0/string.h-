#include "../s21_sprintf.h"

#include <locale.h>
#include <wchar.h>

#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_sprintf_1) {  // c
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my name is %c...";

  char symbol = 'A';
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, symbol);
  expected_len = sprintf(expected_str, pattern, symbol);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_2) {  // d
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my age is % d...";

  int age = 17;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, age);
  expected_len = sprintf(expected_str, pattern, age);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_3) {  // i
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my age is %i...";

  int age = -17;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, age);
  expected_len = sprintf(expected_str, pattern, age);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_6) {  // f
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %f...";

  float number = 27.777;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_11) {  // s
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %-10.2s...";

  char str[5] = "123";
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, str);
  expected_len = sprintf(expected_str, pattern, str);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_12) {  // s
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %s...";

  char str[4] = "123";
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, str);
  expected_len = sprintf(expected_str, pattern, str);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_13) {  // u
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %u...";

  unsigned int number = 123;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_14) {  // u
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %u...";

  unsigned int number = -123;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_21) {  // %
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, percent is %d%%...";

  int number = 100;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_22) {  // -
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, percent is %-10d%%...";

  int number = 100;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_23) {  // -
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, percent is %+10d%%...";

  int number = 100;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_31) {  // (num)
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %2d...";

  int number = 10;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_32) {  // (num)
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %10d...";

  int number = 10;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_35) {  // hd
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %hd...";

  short int number = 327;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_36) {  // ld
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %ld...";

  long int number = 9223372036854775807;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, number);
  expected_len = sprintf(expected_str, pattern, number);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_40) {  // s
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, number is %5.2s...";

  char str[5] = "123";
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, str);
  expected_len = sprintf(expected_str, pattern, str);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_41) {  // c
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my name is %-3c...";

  char symbol = 'F';
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, symbol);
  expected_len = sprintf(expected_str, pattern, symbol);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_42) {  // f
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my name is %.4f...";

  float f = 0.0005;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, f);
  expected_len = sprintf(expected_str, pattern, f);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_43) {  // int
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my name is %.5d...";

  int d = 0;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, d);
  expected_len = sprintf(expected_str, pattern, d);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_44) {  // f
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my name is %+5.f...";

  float f = 26.9;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, f);
  expected_len = sprintf(expected_str, pattern, f);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_45) {  // f
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my name is % -8.3f...";

  float f = 26.434;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, f);
  expected_len = sprintf(expected_str, pattern, f);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_46) {  // f
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my name is % -8.3f...";

  float f = -26.434;
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, f);
  expected_len = sprintf(expected_str, pattern, f);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_47) {  // lc
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my name is %5lc...";
  setlocale(LC_ALL, "");

  wchar_t c = L'я';
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, c);
  expected_len = sprintf(expected_str, pattern, c);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_48) {  // lc
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my name is %-5lc...";
  setlocale(LC_ALL, "");

  wchar_t c = L'я';
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, c);
  expected_len = sprintf(expected_str, pattern, c);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_49) {  // lc
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my name is %5.4ls...";
  setlocale(LC_ALL, "");

  wchar_t *c = L"привет";
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, c);
  expected_len = sprintf(expected_str, pattern, c);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

START_TEST(test_s21_sprintf_50) {  // lc
  char result_str[124];
  char expected_str[124];
  const char *pattern = "Hello, my name is %-5.4ls...";
  setlocale(LC_ALL, "");

  wchar_t *c = L"привет";
  int result_len = 0;
  int expected_len = 0;

  result_len = s21_sprintf(result_str, pattern, c);
  expected_len = sprintf(expected_str, pattern, c);

  ck_assert_str_eq(result_str, expected_str);
  ck_assert_int_eq(result_len, expected_len);
}
END_TEST

TCase *tcase_s21_sprintf(void) {
  TCase *tcase = tcase_create("s21_sprintf");
  tcase_add_test(tcase, test_s21_sprintf_1);
  tcase_add_test(tcase, test_s21_sprintf_2);
  tcase_add_test(tcase, test_s21_sprintf_3);
  tcase_add_test(tcase, test_s21_sprintf_6);
  tcase_add_test(tcase, test_s21_sprintf_11);
  tcase_add_test(tcase, test_s21_sprintf_12);
  tcase_add_test(tcase, test_s21_sprintf_13);
  tcase_add_test(tcase, test_s21_sprintf_14);

  tcase_add_test(tcase, test_s21_sprintf_21);
  tcase_add_test(tcase, test_s21_sprintf_22);
  tcase_add_test(tcase, test_s21_sprintf_23);
  tcase_add_test(tcase, test_s21_sprintf_31);
  tcase_add_test(tcase, test_s21_sprintf_32);
  tcase_add_test(tcase, test_s21_sprintf_35);
  tcase_add_test(tcase, test_s21_sprintf_36);
  tcase_add_test(tcase, test_s21_sprintf_40);
  tcase_add_test(tcase, test_s21_sprintf_41);
  tcase_add_test(tcase, test_s21_sprintf_42);
  tcase_add_test(tcase, test_s21_sprintf_43);
  tcase_add_test(tcase, test_s21_sprintf_44);
  tcase_add_test(tcase, test_s21_sprintf_45);
  tcase_add_test(tcase, test_s21_sprintf_46);
  tcase_add_test(tcase, test_s21_sprintf_47);
  tcase_add_test(tcase, test_s21_sprintf_48);
  tcase_add_test(tcase, test_s21_sprintf_49);
  tcase_add_test(tcase, test_s21_sprintf_50);

  return tcase;
}