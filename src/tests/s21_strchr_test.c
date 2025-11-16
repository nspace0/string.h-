#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_strchr_1) {
  char str[100] = "Hello";
  char c = 'e';
  ck_assert_pstr_eq(strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_2) {
  char str[100] = "Hello, world!";
  char c = 'o';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_3) {
  char str[100] = "Hello, world!";
  char c = 'h';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_4) {
  char str[100] = "Hello, world!";
  char c = 'H';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_5) {
  char str[100] = "Hello, world!";
  char c = 69;
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_6) {
  char str[100] = "Hello, world!";
  char c = 68;
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_7) {
  char str[100] = "Hello, world!";
  char c = 0;
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_8) {
  char str[100] = "69917020";
  char c = '\0';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_9) {
  char str[100] = "69917020";
  char c = '0';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(test_s21_strchr_10) {
  char str[] = "Hello, world!\n";
  char c = 'r';
  char *result = s21_strchr(str, c);
  char *expected = strchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strchr_11) {
  char str[] = "Hello, world!\n";
  char c = 'H';
  char *result = s21_strchr(str, c);
  char *expected = strchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strchr_12) {
  char str[] = "Hello, world!\n";
  char c = '\n';
  char *result = s21_strchr(str, c);
  char *expected = strchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strchr_13) {
  char str[] = "1234567890\t1234567890\n";
  char c = '9';
  char *result = s21_strchr(str, c);
  char *expected = strchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strchr_14) {
  char str[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char c = '7';
  char *result = s21_strchr(str, c);
  char *expected = strchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strchr_15) {
  char str[256] = "";
  char c = 'a';
  char *result = s21_strchr(str, c);
  char *expected = strchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strchr_16) {
  char str[] = "Lorem ipsum dolor\0sit amet consectetur.\n";
  char c = '.';
  char *result = s21_strchr(str, c);
  char *expected = strchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

TCase *tcase_s21_strchr(void) {
  TCase *tcase = tcase_create("s21_strchr");
  tcase_add_test(tcase, test_s21_strchr_1);
  tcase_add_test(tcase, test_s21_strchr_2);
  tcase_add_test(tcase, test_s21_strchr_3);
  tcase_add_test(tcase, test_s21_strchr_4);
  tcase_add_test(tcase, test_s21_strchr_5);
  tcase_add_test(tcase, test_s21_strchr_6);
  tcase_add_test(tcase, test_s21_strchr_7);
  tcase_add_test(tcase, test_s21_strchr_8);
  tcase_add_test(tcase, test_s21_strchr_9);
  tcase_add_test(tcase, test_s21_strchr_10);
  tcase_add_test(tcase, test_s21_strchr_11);
  tcase_add_test(tcase, test_s21_strchr_12);
  tcase_add_test(tcase, test_s21_strchr_13);
  tcase_add_test(tcase, test_s21_strchr_14);
  tcase_add_test(tcase, test_s21_strchr_15);
  tcase_add_test(tcase, test_s21_strchr_16);
  return tcase;
}