#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_to_lower_1) {
  char *str1 = "Default sentence with numbers: 123";
  char *result = s21_to_lower(str1);
  ck_assert_str_eq(result, "default sentence with numbers: 123");
  free(result);
}
END_TEST

// Test empty sentence
START_TEST(test_s21_to_lower_2) {
  char *str1 = "";
  char *result = s21_to_lower(str1);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

// Test sentence with only large letters
START_TEST(test_s21_to_lower_3) {
  char *str1 = "LARGE LETTERS";
  char *result = s21_to_lower(str1);
  ck_assert_str_eq(result, "large letters");
  free(result);
}
END_TEST

// Test sentence with formats
START_TEST(test_s21_to_lower_4) {
  char *str1 = "Another\n one SenTenCE\t wWith\0 words";
  char *result = s21_to_lower(str1);
  ck_assert_str_eq(result, "another\n one sentence\t wwith\0 words");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_5) {
  char *str = "";
  char *result = s21_to_lower(str);
  char *expected = "";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_6) {
  char str[] = "hello, world!\n";
  char *result = s21_to_lower(str);
  char *expected = "hello, world!\n";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_7) {
  char *str = s21_NULL;
  char *result = s21_to_lower(str);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_8) {
  char str[] = "HeLLO, WoRlD!\n";
  char *result = s21_to_lower(str);
  char *expected = "hello, world!\n";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_9) {
  char *str = "ZXCVBNMLKJ_HGFDSAQWER_TYUIOP";
  char *result = s21_to_lower(str);
  char *expected = "zxcvbnmlkj_hgfdsaqwer_tyuiop";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_10) {
  char *str = "HELLO\nMy name\tis HENRY.\n";
  char *result = s21_to_lower(str);
  char *expected = "hello\nmy name\tis henry.\n";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_11) {
  char *str = "0123456789\t0123456789\v";
  char *result = s21_to_lower(str);
  char *expected = "0123456789\t0123456789\v";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_12) {
  char *str = "";
  char *result = s21_to_lower(str);
  char *expected = "";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_13) {
  char str[] = "hello, world!\n";
  char *result = s21_to_lower(str);
  char *expected = "hello, world!\n";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_14) {
  char *str = s21_NULL;
  char *result = s21_to_lower(str);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_15) {
  char str[] = "HeLLO, WoRlD!\n";
  char *result = s21_to_lower(str);
  char *expected = "hello, world!\n";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

TCase *tcase_s21_to_lower(void) {
  TCase *tcase = tcase_create("s21_to_lower");
  tcase_add_test(tcase, test_s21_to_lower_1);
  tcase_add_test(tcase, test_s21_to_lower_2);
  tcase_add_test(tcase, test_s21_to_lower_3);
  tcase_add_test(tcase, test_s21_to_lower_4);
  tcase_add_test(tcase, test_s21_to_lower_5);
  tcase_add_test(tcase, test_s21_to_lower_6);
  tcase_add_test(tcase, test_s21_to_lower_7);
  tcase_add_test(tcase, test_s21_to_lower_8);
  tcase_add_test(tcase, test_s21_to_lower_9);
  tcase_add_test(tcase, test_s21_to_lower_10);
  tcase_add_test(tcase, test_s21_to_lower_11);
  tcase_add_test(tcase, test_s21_to_lower_12);
  tcase_add_test(tcase, test_s21_to_lower_13);
  tcase_add_test(tcase, test_s21_to_lower_14);
  tcase_add_test(tcase, test_s21_to_lower_15);
  return tcase;
}