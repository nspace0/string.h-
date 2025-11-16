#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_strcspn_1) {
  char str[100] = "Hello, world!";
  char str1[100] = "world";
  ck_assert_uint_eq(strcspn(str, str1), strcspn(str, str1));
}
END_TEST

START_TEST(test_s21_strcspn_2) {
  char str[100] = "Hello, world!";
  char str1[100] = "not helloworld((";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(test_s21_strcspn_3) {
  char str[100] = "Hello, world!";
  char str1[100] = "hello, world!";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(test_s21_strcspn_4) {
  char str[100] = "Hello, world!";
  char str1[100] = "abc";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(test_s21_strcspn_5) {
  char str[100] = "Hello, world!";
  char str1[100] = "";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(test_s21_strcspn_6) {
  char str[100] = "Hello, world!";
  char str1[100] = "\0";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(test_s21_strcspn_7) {
  char str[100] = "1234347";
  char str1[100] = "89";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(test_s21_strcspn_8) {
  char str[100] = "1234347";
  char str1[100] = "123";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(test_s21_strcspn_9) {
  char str[100] = "1234347";
  char str1[100] = "321";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(test_s21_strcspn_10) {
  char str[100] = "";
  char str1[100] = "";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(test_s21_strcspn_11) {
  char str[100] = "";
  char str1[100] = "Hello, world!";
  ck_assert_uint_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(test_s21_strcspn_12) {
  char str1[] = "1234567890\t1234567890\n";
  char str2[] = "157";
  s21_size_t result = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strcspn_13) {
  char str1[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char str2[] = "_!\t\n";
  s21_size_t result = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strcspn_14) {
  char str1[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char str2[] = "123456";
  s21_size_t result = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strcspn_15) {
  char str1[] = "";
  char str2[] = "Hello";
  s21_size_t result = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(result, expected);
}
END_TEST

TCase *tcase_s21_strcspn(void) {
  TCase *tcase = tcase_create("s21_strcspn");
  tcase_add_test(tcase, test_s21_strcspn_1);
  tcase_add_test(tcase, test_s21_strcspn_2);
  tcase_add_test(tcase, test_s21_strcspn_3);
  tcase_add_test(tcase, test_s21_strcspn_4);
  tcase_add_test(tcase, test_s21_strcspn_5);
  tcase_add_test(tcase, test_s21_strcspn_6);
  tcase_add_test(tcase, test_s21_strcspn_7);
  tcase_add_test(tcase, test_s21_strcspn_8);
  tcase_add_test(tcase, test_s21_strcspn_9);
  tcase_add_test(tcase, test_s21_strcspn_10);
  tcase_add_test(tcase, test_s21_strcspn_11);
  tcase_add_test(tcase, test_s21_strcspn_12);
  tcase_add_test(tcase, test_s21_strcspn_13);
  tcase_add_test(tcase, test_s21_strcspn_14);
  tcase_add_test(tcase, test_s21_strcspn_15);
  return tcase;
}