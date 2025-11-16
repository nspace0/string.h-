#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_strrchr_1) {
  char str[100] = "Hello";
  char c = 'e';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(test_s21_strrchr_2) {
  char str[100] = "Hello, world!";
  char c = 'o';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(test_s21_strrchr_3) {
  char str[100] = "Hello, world!";
  char c = 'h';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(test_s21_strrchr_4) {
  char str[100] = "Hello, world!";
  char c = 'H';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(test_s21_strrchr_5) {
  char str[100] = "Hello, world!";
  char c = 69;
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(test_s21_strrchr_6) {
  char str[100] = "Hello, world!";
  char c = 68;
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(test_s21_strrchr_7) {
  char str[100] = "Hello, world!";
  char c = 0;
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(test_s21_strrchr_8) {
  char str[100] = "69917020";
  char c = '\0';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(test_s21_strrchr_9) {
  char str[100] = "69917020";
  char c = '0';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(test_s21_strrchr_10) {
  char str[] = "Hello, world!\n";
  char c = ',';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strrchr_11) {
  char str[] = "Hello, world!\n";
  char c = 'H';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strrchr_12) {
  char str[] = "Hello, world!\n";
  char c = '\n';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strrchr_13) {
  char str[] = "1234567890\t1234567890\n";
  char c = '9';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strrchr_14) {
  char str[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char c = '7';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strrchr_15) {
  char str[256] = "";
  char c = 'a';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

TCase *tcase_s21_strrchr(void) {
  TCase *tcase = tcase_create("s21_strrchr");

  tcase_add_test(tcase, test_s21_strrchr_1);
  tcase_add_test(tcase, test_s21_strrchr_2);
  tcase_add_test(tcase, test_s21_strrchr_3);
  tcase_add_test(tcase, test_s21_strrchr_4);
  tcase_add_test(tcase, test_s21_strrchr_5);
  tcase_add_test(tcase, test_s21_strrchr_6);
  tcase_add_test(tcase, test_s21_strrchr_7);
  tcase_add_test(tcase, test_s21_strrchr_8);
  tcase_add_test(tcase, test_s21_strrchr_9);
  tcase_add_test(tcase, test_s21_strrchr_10);
  tcase_add_test(tcase, test_s21_strrchr_11);
  tcase_add_test(tcase, test_s21_strrchr_12);
  tcase_add_test(tcase, test_s21_strrchr_13);
  tcase_add_test(tcase, test_s21_strrchr_14);
  tcase_add_test(tcase, test_s21_strrchr_15);
  return tcase;
}
