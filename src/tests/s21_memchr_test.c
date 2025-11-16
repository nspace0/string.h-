#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_memchr_1) {
  char str[] = "Hello, world!";
  int len = strlen(str);
  void *result = s21_memchr(str, 'l', len);
  void *expected = memchr(str, 'l', len);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_2) {
  char str[] = "Hello, world!";
  int len = strlen(str);
  void *result = s21_memchr(str, 'H', len);
  void *expected = memchr(str, 'H', len);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_3) {
  char str[] = "0123456789 9876543210";
  int len = strlen(str);
  void *result = s21_memchr(str, 'l', len);
  void *expected = memchr(str, 'l', len);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_4) {
  char str[] = "0123456789 9876543210";
  int len = strlen(str);
  void *result = s21_memchr(str, ' ', len);
  void *expected = memchr(str, ' ', len);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_5) {
  char str[20] = "\0Hello, world!";
  void *result = s21_memchr(str, 'o', 20);
  void *expected = memchr(str, 'o', 20);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_6) {
  char str[20] = "\0Hello, world!";
  void *result = s21_memchr(str, '1', 20);
  void *expected = memchr(str, '1', 20);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_7) {
  char str[] = {'H', 'e', 'l', '\10', 'p', ' ', 'm', 'e', '\0'};
  int len = strlen(str);
  void *result = s21_memchr(str, '\10', len - 2);
  void *expected = memchr(str, '\10', len - 2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_8) {
  char str[] = "Help me";
  int len = strlen(str);
  void *result = s21_memchr(str, -2, len);
  void *expected = memchr(str, -2, len);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_9) {
  char str[] = "Help me";
  int len = strlen(str);
  void *result = s21_memchr(str, '\10', len);
  void *expected = memchr(str, '\10', len);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_10) {
  char str[] = {'H', 'e', 'l', '\10', 'p', ' ', 'm', 'e', '\0'};
  int len = strlen(str);
  void *result = s21_memchr(str, '\10', len - 2);
  void *expected = memchr(str, '\10', len - 2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_11) {
  char str[20] = "\0Hello, world!";
  void *result = s21_memchr(str, '1', 20);
  void *expected = memchr(str, '1', 20);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_12) {
  char str[] = "Hello, world!";
  int len = strlen(str);
  void *result = s21_memchr(str, 'H', len);
  void *expected = memchr(str, 'H', len);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_13) {
  char str[] = "Hello, world!";
  int len = strlen(str);
  void *result = s21_memchr(str, 'H', len);
  void *expected = memchr(str, 'H', len);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_14) {
  char str[] = "0123456789 9876543210";
  int len = strlen(str);
  void *result = s21_memchr(str, ' ', len);
  void *expected = memchr(str, ' ', len);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_15) {
  char str[20] = "\0Hello, world!";
  void *result = s21_memchr(str, '1', 20);
  void *expected = memchr(str, '1', 20);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_16) {
  char str[] = "0123456789 9876543210";
  int len = strlen(str);
  void *result = s21_memchr(str, 'l', len);
  void *expected = memchr(str, 'l', len);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

TCase *tcase_s21_memchr(void) {
  TCase *tcase = tcase_create("s21_memchr");
  tcase_add_test(tcase, test_s21_memchr_1);
  tcase_add_test(tcase, test_s21_memchr_2);
  tcase_add_test(tcase, test_s21_memchr_3);
  tcase_add_test(tcase, test_s21_memchr_4);
  tcase_add_test(tcase, test_s21_memchr_5);
  tcase_add_test(tcase, test_s21_memchr_6);
  tcase_add_test(tcase, test_s21_memchr_7);
  tcase_add_test(tcase, test_s21_memchr_8);
  tcase_add_test(tcase, test_s21_memchr_9);
  tcase_add_test(tcase, test_s21_memchr_10);
  tcase_add_test(tcase, test_s21_memchr_11);
  tcase_add_test(tcase, test_s21_memchr_12);
  tcase_add_test(tcase, test_s21_memchr_13);
  tcase_add_test(tcase, test_s21_memchr_14);
  tcase_add_test(tcase, test_s21_memchr_15);
  tcase_add_test(tcase, test_s21_memchr_16);
  return tcase;
}