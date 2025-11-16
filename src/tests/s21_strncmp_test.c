#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_strncmp_1) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, world!";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(test_s21_strncmp_2) {
  char str[] = "Hello, world!";
  char str1[] = "not helloworld((";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(test_s21_strncmp_3) {
  char str[] = "Hello, world!";
  char str1[] = "hello, world!";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(test_s21_strncmp_4) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, world\0";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(test_s21_strncmp_5) {
  char str[] = "Hello, world!";
  char str1[] = "Hello,\n world";
  s21_size_t len = 10;
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(test_s21_strncmp_6) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, Harry!";
  s21_size_t len = 5;
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(test_s21_strncmp_7) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, Harry";
  s21_size_t len = 8;
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(test_s21_strncmp_8) {
  char str[] = "69917020";
  char str1[] = "69917020";
  s21_size_t len = 0;
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(test_s21_strncmp_9) {
  char str[] = "69917020";
  char str1[] = "69917020";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(test_s21_strncmp_10) {
  char str[] = "Hello";
  char str1[] = "Hello";
  s21_size_t len = 0;
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(test_s21_strncmp_11) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, world!\0";
  s21_size_t len = strlen(str) + 1;
  ck_assert_int_eq(strncmp(str, str1, len), s21_strncmp(str, str1, len));
}
END_TEST

START_TEST(test_s21_strncmp_12) {
  char str1[] = "Hello, world!\n";
  char str2[] = "Hello, world!\n";
  int len = strlen(str2);
  int result = s21_strncmp(str1, str2, len);
  int expected = strncmp(str1, str2, len);
  ck_assert_int_eq(sign_int(result), sign_int(expected));
}
END_TEST

START_TEST(test_s21_strncmp_13) {
  char str1[] = "Hello, world!\n";
  char str2[] = "Hello!";
  int len = strlen(str2) - 1;
  int result = s21_strncmp(str1, str2, len);
  int expected = strncmp(str1, str2, len);
  ck_assert_int_eq(sign_int(result), sign_int(expected));
}
END_TEST

START_TEST(test_s21_strncmp_14) {
  char str1[] = "Hello, world!\n";
  char str2[] = "Hello.";
  int len = strlen(str2);
  int result = s21_strncmp(str1, str2, len);
  int expected = strncmp(str1, str2, len);
  ck_assert_int_eq(sign_int(result), sign_int(expected));
}
END_TEST

START_TEST(test_s21_strncmp_15) {
  char str1[] = "abcde";
  char str2[] = "abCde.";
  int len = strlen(str2);
  int result = s21_strncmp(str1, str2, len);
  int expected = strncmp(str1, str2, len);
  ck_assert_int_eq(sign_int(result), sign_int(expected));
}
END_TEST

TCase* tcase_s21_strncmp(void) {
  TCase* tcase = tcase_create("s21_strncmp");
  tcase_add_test(tcase, test_s21_strncmp_1);
  tcase_add_test(tcase, test_s21_strncmp_2);
  tcase_add_test(tcase, test_s21_strncmp_3);
  tcase_add_test(tcase, test_s21_strncmp_4);
  tcase_add_test(tcase, test_s21_strncmp_5);
  tcase_add_test(tcase, test_s21_strncmp_6);
  tcase_add_test(tcase, test_s21_strncmp_7);
  tcase_add_test(tcase, test_s21_strncmp_8);
  tcase_add_test(tcase, test_s21_strncmp_9);
  tcase_add_test(tcase, test_s21_strncmp_10);
  tcase_add_test(tcase, test_s21_strncmp_11);
  tcase_add_test(tcase, test_s21_strncmp_12);
  tcase_add_test(tcase, test_s21_strncmp_13);
  tcase_add_test(tcase, test_s21_strncmp_14);
  tcase_add_test(tcase, test_s21_strncmp_15);
  return tcase;
}