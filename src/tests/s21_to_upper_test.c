#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_to_upper_1) {
  char *str1 = "Default sentence with numbers: 123";
  char *result = s21_to_upper(str1);
  ck_assert_str_eq(result, "DEFAULT SENTENCE WITH NUMBERS: 123");
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_2) {
  char *str1 = "";
  char *result = s21_to_upper(str1);
  ck_assert_str_eq(result, "");  //тест: пустая строка.
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_3) {
  char *str1 = "LARGE LETTERS";
  char *result = s21_to_upper(str1);
  ck_assert_str_eq(result, "LARGE LETTERS");  //тест: ту аппер текст
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_4) {
  char *str1 = "Another\n one SenTenCE\t wWith\0 words";
  char *result = s21_to_upper(str1);
  ck_assert_str_eq(result, "ANOTHER\n ONE SENTENCE\t WWITH");
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_5) {
  char str[] = "HELLO, WORLD!\n";
  char *result = s21_to_upper(str);
  char *expected = "HELLO, WORLD!\n";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_6) {
  char str[] = "HELLO, WORLD!\n";
  char *result = s21_to_upper(str);
  char *expected = "HELLO, WORLD!\n";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_7) {
  char *str = "qwertyuiop_lkjhgfdsaz_xcvbnm";
  char *result = s21_to_upper(str);
  char *expected = "QWERTYUIOP_LKJHGFDSAZ_XCVBNM";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_8) {
  char str[] = "Hello, world!\n";
  char *result = s21_to_upper(str);
  char *expected = "HELLO, WORLD!\n";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_9) {
  char str[] = "HELLO\nMy name\tis Henry.\n";
  char *result = s21_to_upper(str);
  char *expected = "HELLO\nMY NAME\tIS HENRY.\n";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_10) {
  char str[] = "0123456789\t0123456789\v";
  char *result = s21_to_upper(str);
  char *expected = "0123456789\t0123456789\v";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_11) {
  char str[] = "";
  char *result = s21_to_upper(str);
  char *expected = "";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_12) {
  char str[] = "HELLO, WORLD!\n";
  char *result = s21_to_upper(str);
  char *expected = "HELLO, WORLD!\n";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_13) {
  char *str = "qwertyuiop_lkjhgfdsaz_xcvbnm";
  char *result = s21_to_upper(str);
  char *expected = "QWERTYUIOP_LKJHGFDSAZ_XCVBNM";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_14) {
  char str[] = "Hello, world!\n";
  char *result = s21_to_upper(str);
  char *expected = "HELLO, WORLD!\n";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_15) {
  char str[] = "HELLO\nMy name\tis Henry.\n";
  char *result = s21_to_upper(str);
  char *expected = "HELLO\nMY NAME\tIS HENRY.\n";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

TCase *tcase_s21_to_upper(void) {
  TCase *tcase = tcase_create("s21_to_upper");
  tcase_add_test(tcase, test_s21_to_upper_1);
  tcase_add_test(tcase, test_s21_to_upper_2);
  tcase_add_test(tcase, test_s21_to_upper_3);
  tcase_add_test(tcase, test_s21_to_upper_4);
  tcase_add_test(tcase, test_s21_to_upper_5);
  tcase_add_test(tcase, test_s21_to_upper_6);
  tcase_add_test(tcase, test_s21_to_upper_7);
  tcase_add_test(tcase, test_s21_to_upper_8);
  tcase_add_test(tcase, test_s21_to_upper_9);
  tcase_add_test(tcase, test_s21_to_upper_10);
  tcase_add_test(tcase, test_s21_to_upper_11);
  tcase_add_test(tcase, test_s21_to_upper_12);
  tcase_add_test(tcase, test_s21_to_upper_13);
  tcase_add_test(tcase, test_s21_to_upper_14);
  tcase_add_test(tcase, test_s21_to_upper_15);
  return tcase;
}