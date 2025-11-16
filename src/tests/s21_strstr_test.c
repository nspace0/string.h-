#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_strstr_1) {
  char str[100] = "Hello hello Hello";
  char str1[100] = "hello";
  ck_assert_pstr_eq(strstr(str, str1), strstr(str, str1));
}
END_TEST

START_TEST(test_s21_strstr_2) {
  char str[100] = "Hello hello Hello";
  char str1[100] = "Hello";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(test_s21_strstr_3) {
  char str[100] = "helloHellohelloHello";
  char str1[100] = "Hello";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(test_s21_strstr_4) {
  char str[100] = "Hello, world!";
  char str1[100] = "\0";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(test_s21_strstr_5) {
  char str[100] = "Hello, world!";
  char str1[100] = "l";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(test_s21_strstr_6) {
  char str[100] = "Hello, world!";
  char str1[100] = "A";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(test_s21_strstr_7) {
  char str[100] = "12341234124";
  char str1[100] = "12";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(test_s21_strstr_8) {
  char str[100] = "69917020";
  char str1[100] = "6998";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(test_s21_strstr_9) {
  char str[100] = "69917020";
  char str1[100] = "270";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(test_s21_strstr_10) {
  char str[100] = "Hello";
  char str1[100] = "Hello";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(test_s21_strstr_11) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, world!\0";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(test_s21_strstr_12) {
  char str1[] = "Hello, world!\tIt's a good day\n";
  char str2[] = "!\t";
  char *result = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strstr_13) {
  char str1[] = "0123456789\n0123456789";
  char str2[] = "789";
  char *result = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strstr_14) {
  char str1[] = "Hello! My name is Henry\n";
  char str2[] = "He";
  char *result = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strstr_15) {
  char str1[] = "";
  char str2[] = "abc";
  char *result = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

TCase *tcase_s21_strstr(void) {
  TCase *tcase = tcase_create("s21_strstr");

  tcase_add_test(tcase, test_s21_strstr_1);
  tcase_add_test(tcase, test_s21_strstr_2);
  tcase_add_test(tcase, test_s21_strstr_3);
  tcase_add_test(tcase, test_s21_strstr_4);
  tcase_add_test(tcase, test_s21_strstr_5);
  tcase_add_test(tcase, test_s21_strstr_6);
  tcase_add_test(tcase, test_s21_strstr_7);
  tcase_add_test(tcase, test_s21_strstr_8);
  tcase_add_test(tcase, test_s21_strstr_9);
  tcase_add_test(tcase, test_s21_strstr_10);
  tcase_add_test(tcase, test_s21_strstr_11);
  tcase_add_test(tcase, test_s21_strstr_12);
  tcase_add_test(tcase, test_s21_strstr_13);
  tcase_add_test(tcase, test_s21_strstr_14);
  tcase_add_test(tcase, test_s21_strstr_15);
  return tcase;
}