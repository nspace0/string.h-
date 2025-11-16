#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_memset_1) {
  char str[10] = "Hello";
  char c = 'w';
  s21_size_t len = strlen(str);
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(test_s21_memset_2) {
  char str[] = "Hello";
  char c = 66;
  s21_size_t len = 2;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(test_s21_memset_3) {
  char str[] = "Hello";
  char c = 10;
  s21_size_t len = 0;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(test_s21_memset_4) {
  char str[] = "Hello, world!";
  char c = 9;
  s21_size_t len = 2;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(test_s21_memset_5) {
  char str[] = "12\t34\n56(!@";
  char c = 0;
  s21_size_t len = 12;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(test_s21_memset_6) {
  char str[] = "Hello, world!";
  char c = 127;
  s21_size_t len = 12;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(test_s21_memset_7) {
  char str[] = "a";
  char c = 'f';
  s21_size_t len = 1;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(test_s21_memset_8) {
  char str[] = "a";
  char c = 100;
  s21_size_t len = 1;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(test_s21_memset_9) {
  char str[] = "\0";
  char c = 127;
  s21_size_t len = 1;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(test_s21_memset_10) {
  char str[] = "Hello";
  char c = 0;
  s21_size_t len = 5;
  ck_assert_str_eq(memset(str, c, len), s21_memset(str, c, len));
}
END_TEST

START_TEST(test_s21_memset_11) {
  char s21_str[] = "Lorem ipsum dolor sit amet consectetur.";
  char str[] = "Lorem ipsum dolor sit amet consectetur.";
  char c = '.';
  int n = 1;
  char *s21_result = s21_memset(s21_str, c, n);
  char *result = memset(str, c, n);
  ck_assert_ptr_eq(s21_result, s21_str);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memset_12) {
  char s21_str[] = "\0\0\0\0\0";
  char str[] = "\0\0\0\0\0";
  char c = '\0';
  int n = 1;
  char *s21_result = s21_memset(s21_str, c, n);
  char *result = memset(str, c, n);
  ck_assert_ptr_eq(s21_result, s21_str);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memset_13) {
  char s21_str[] = "0123356789";
  char str[] = "0123356789";
  char c = '\04';
  int n = strlen(str);
  char *s21_result = s21_memset(s21_str, c, n);
  char *result = memset(str, c, n);
  ck_assert_ptr_eq(s21_result, s21_str);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memset_14) {
  char s21_str[] = "Lorem ipsum dolor sit amet consectetur.";
  char str[] = "Lorem ipsum dolor sit amet consectetur.";
  char c = '^';
  int n = 7;
  char *s21_result = s21_memset(s21_str, c, n);
  char *result = memset(str, c, n);
  ck_assert_ptr_eq(s21_result, s21_str);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memset_15) {
  char s21_str[] = "Lorem ipsum dolor sit amet consectetur.";
  char str[] = "Lorem ipsum dolor sit amet consectetur.";
  char c = '\n';
  int n = strlen(str);
  char *s21_result = s21_memset(s21_str, c, n);
  char *result = memset(str, c, n);
  ck_assert_ptr_eq(s21_result, s21_str);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

TCase *tcase_s21_memset(void) {
  TCase *tcase = tcase_create("s21_memset");
  tcase_add_test(tcase, test_s21_memset_1);
  tcase_add_test(tcase, test_s21_memset_2);
  tcase_add_test(tcase, test_s21_memset_3);
  tcase_add_test(tcase, test_s21_memset_4);
  tcase_add_test(tcase, test_s21_memset_5);
  tcase_add_test(tcase, test_s21_memset_6);
  tcase_add_test(tcase, test_s21_memset_7);
  tcase_add_test(tcase, test_s21_memset_8);
  tcase_add_test(tcase, test_s21_memset_9);
  tcase_add_test(tcase, test_s21_memset_10);
  tcase_add_test(tcase, test_s21_memset_11);
  tcase_add_test(tcase, test_s21_memset_12);
  tcase_add_test(tcase, test_s21_memset_13);
  tcase_add_test(tcase, test_s21_memset_14);
  tcase_add_test(tcase, test_s21_memset_15);
  return tcase;
}