#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_strncpy_1) {
  char str[100] = "Hello";
  char str1[100] = "world";
  ck_assert_str_eq(strncpy(str, str1, 3), strncpy(str, str1, 3));
}
END_TEST

START_TEST(test_s21_strncpy_2) {
  char str[100] = "Hello, world!";
  char str1[100] = "not helloworld((";
  ck_assert_str_eq(strncpy(str, str1, strlen(str1)),
                   s21_strncpy(str, str1, strlen(str1)));
}
END_TEST

START_TEST(test_s21_strncpy_3) {
  char str[100] = "Hello, world!";
  char str1[100] = "hello, world!";
  ck_assert_str_eq(strncpy(str, str1, 13), s21_strncpy(str, str1, 13));
}
END_TEST

START_TEST(test_s21_strncpy_4) {
  char str[100] = "Hello, world!";
  char str1[100] = "hello, \0 world!";
  ck_assert_str_eq(strncpy(str, str1, 15), s21_strncpy(str, str1, 15));
}
END_TEST

START_TEST(test_s21_strncpy_5) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello,\n world";
  ck_assert_str_eq(strncpy(str, str1, 10), s21_strncpy(str, str1, 10));
}
END_TEST

START_TEST(test_s21_strncpy_6) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, Harry!";
  ck_assert_str_eq(strncpy(str, str1, 1), s21_strncpy(str, str1, 1));
}
END_TEST

START_TEST(test_s21_strncpy_7) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, Harry";
  ck_assert_str_eq(strncpy(str, str1, 5), s21_strncpy(str, str1, 5));
}
END_TEST

START_TEST(test_s21_strncpy_8) {
  char str[100] = "69917020";
  char str1[100] = "69917020";
  ck_assert_str_eq(strncpy(str, str1, 8), s21_strncpy(str, str1, 8));
}
END_TEST

START_TEST(test_s21_strncpy_9) {
  char str[100] = "69917020";
  char str1[100] = "69917020";
  ck_assert_str_eq(strncpy(str, str1, 4), s21_strncpy(str, str1, 4));
}
END_TEST

START_TEST(test_s21_strncpy_10) {
  char str[100] = "Hello";
  char str1[100] = "Hello";
  ck_assert_str_eq(strncpy(str, str1, 6), s21_strncpy(str, str1, 6));
}
END_TEST

START_TEST(test_s21_strncpy_11) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, world!\0";
  ck_assert_str_eq(strncpy(str, str1, 90), s21_strncpy(str, str1, 90));
}
END_TEST

START_TEST(test_s21_strncpy_12) {
  char s21_dest[] = "Hello, world!\n";
  char dest[] = "Hello, world!\n";
  char src[] = "0123456789";
  int len = 3;
  char* s21_result = s21_strncpy(s21_dest, src, len);
  char* result = strncpy(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strncpy_13) {
  char s21_dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[] = "!2345";
  int len = strlen(src);
  char* s21_result = s21_strncpy(s21_dest, src, len);
  char* result = strncpy(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strncpy_14) {
  char s21_dest[] = "\0\0\0\0\0";
  char dest[] = "\0\0\0\0\0";
  char src[] = "\0";
  int len = strlen(src);
  char* s21_result = s21_strncpy(s21_dest, src, len);
  char* result = strncpy(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strncpy_15) {
  char s21_dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[] = "Hello\n";
  int len = 0;
  char* s21_result = s21_strncpy(s21_dest, src, len);
  char* result = strncpy(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

TCase* tcase_s21_strncpy(void) {
  TCase* tcase = tcase_create("s21_strncpy");

  tcase_add_test(tcase, test_s21_strncpy_1);
  tcase_add_test(tcase, test_s21_strncpy_2);
  tcase_add_test(tcase, test_s21_strncpy_3);
  tcase_add_test(tcase, test_s21_strncpy_4);
  tcase_add_test(tcase, test_s21_strncpy_5);
  tcase_add_test(tcase, test_s21_strncpy_6);
  tcase_add_test(tcase, test_s21_strncpy_7);
  tcase_add_test(tcase, test_s21_strncpy_8);
  tcase_add_test(tcase, test_s21_strncpy_9);
  tcase_add_test(tcase, test_s21_strncpy_10);
  tcase_add_test(tcase, test_s21_strncpy_11);
  tcase_add_test(tcase, test_s21_strncpy_12);
  tcase_add_test(tcase, test_s21_strncpy_13);
  tcase_add_test(tcase, test_s21_strncpy_14);
  tcase_add_test(tcase, test_s21_strncpy_15);
  return tcase;
}