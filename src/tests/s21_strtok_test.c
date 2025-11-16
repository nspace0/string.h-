#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_strtok_1) {
  char str[100] = "Hello hello Hello";
  char str1[100] = "hello";
  ck_assert_pstr_eq(strtok(str, str1), strtok(str, str1));
}
END_TEST

START_TEST(test_s21_strtok_2) {
  char str[100] = "Hello hello Hello";
  char str1[100] = "Hello";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(test_s21_strtok_3) {
  char str[100] = "helloHellohelloHello";
  char str1[100] = "Hello";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(test_s21_strtok_4) {
  char str[100] = "Hello, world!";
  char str1[100] = "\0";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(test_s21_strtok_5) {
  char str[100] = "Hello, world!";
  char str1[100] = "l";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(test_s21_strtok_6) {
  char str[100] = "Hello, world!";
  char str1[100] = "A";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(test_s21_strtok_7) {
  char str[100] = "12341234124";
  char str1[100] = "12";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(test_s21_strtok_8) {
  char str[100] = "69917020";
  char str1[100] = "6998";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(test_s21_strtok_9) {
  char str[100] = "Hello, what is   your name?";
  char str1[100] = " ";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(test_s21_strtok_10) {
  char str[100] = "H  ello ";
  char str1[100] = "Hello";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(test_s21_strtok_11) {
  char str[100] = "Hello, world! ";
  char str1[100] = "Hello, world!";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}
END_TEST

START_TEST(test_s21_strtok_12) {
  char str[] = "hello,world,nspace00";
  const char delim[] = ",";
  char *token;

  token = s21_strtok(str, delim);
  ck_assert_str_eq(token, "hello");

  token = s21_strtok(s21_NULL, delim);
  ck_assert_str_eq(token, "world");

  token = s21_strtok(s21_NULL, delim);
  ck_assert_str_eq(token, "nspace00");

  token = s21_strtok(s21_NULL, delim);
  ck_assert_ptr_eq(token, s21_NULL);
}
END_TEST

START_TEST(test_s21_strtok_13) {
  char str1[] = "Hello     is   my   new  string.";
  char str2[] = "Hello     is   my   new  string.";
  char delim[] = "i";

  char *result = s21_strtok(str1, delim);
  char *expected = strtok(str2, delim);
  while (result != s21_NULL || expected != NULL) {
    ck_assert_str_eq(result, expected);
    result = s21_strtok(s21_NULL, delim);
    expected = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(test_s21_strtok_14) {
  char str1[] = "";
  char str2[] = "";
  char delim[] = " ,.-";

  char *result = s21_strtok(str1, delim);
  char *expected = strtok(str2, delim);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strtok_15) {
  char str1[] = ",,!./Hello, world!\n..,!/";
  char str2[] = ",,!./Hello, world!\n..,!/";
  char delim[] = "!";

  char *result = s21_strtok(str1, delim);
  char *expected = strtok(str2, delim);
  while (result != s21_NULL || expected != NULL) {
    ck_assert_str_eq(result, expected);
    result = s21_strtok(s21_NULL, delim);
    expected = strtok(NULL, delim);
  }
}
END_TEST

TCase *tcase_s21_strtok(void) {
  TCase *tcase = tcase_create("s21_strtok");
  tcase_add_test(tcase, test_s21_strtok_1);
  tcase_add_test(tcase, test_s21_strtok_2);
  tcase_add_test(tcase, test_s21_strtok_3);
  tcase_add_test(tcase, test_s21_strtok_4);
  tcase_add_test(tcase, test_s21_strtok_5);
  tcase_add_test(tcase, test_s21_strtok_6);
  tcase_add_test(tcase, test_s21_strtok_7);
  tcase_add_test(tcase, test_s21_strtok_8);
  tcase_add_test(tcase, test_s21_strtok_9);
  tcase_add_test(tcase, test_s21_strtok_10);
  tcase_add_test(tcase, test_s21_strtok_11);
  tcase_add_test(tcase, test_s21_strtok_12);
  tcase_add_test(tcase, test_s21_strtok_13);
  tcase_add_test(tcase, test_s21_strtok_14);
  tcase_add_test(tcase, test_s21_strtok_15);
  return tcase;
}