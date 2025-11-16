#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_trim_1) {
  char *result = s21_trim("", "");
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_2) {
  char *result = s21_trim("", "abcdefg");
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_3) {
  char *result = s21_trim("one more message", "");
  ck_assert_str_eq(result, "one more message");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_4) {
  char *result = s21_trim("one more message", "one more message");
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_5) {
  char *result = s21_trim("+!!++Abo+ba++00", "+!0-");
  ck_assert_str_eq(result, "Abo+ba");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_6) {
  char *result = s21_trim("+!!++Abo+ba++00", "+!0-");
  ck_assert_str_eq(result, "Abo+ba");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_7) {
  char *result = s21_trim("Ab000cd0", "003");
  ck_assert_str_eq(result, "Ab000cd");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_8) {
  char *result = s21_trim("DoNotTouch", "Not");
  ck_assert_str_eq(result, "DoNotTouch");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_9) {
  char *result = s21_trim(" Good morning!    ", " ");
  ck_assert_str_eq(result, "Good morning!");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_10) {
  char str1[] = "************";
  char trim_chars[] = "*";
  char *result = s21_trim(str1, trim_chars);
  char *expected = "";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_11) {
  char str1[] = "** *Hello, world!\n*  *";
  char trim_chars[] = "* ";
  char *result = s21_trim(str1, trim_chars);
  char *expected = "Hello, world!\n";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_12) {
  char str1[] = "abcd0123456789\t0123456789xyz";
  char trim_chars[] = "abcdxyz";
  char *result = s21_trim(str1, trim_chars);
  char *expected = "0123456789\t0123456789";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_13) {
  char str1[] = "=   #Lorem ipsum dolor sit amet consectetur,===";
  char trim_chars[] = "# =";
  char *result = s21_trim(str1, trim_chars);
  char *expected = "Lorem ipsum dolor sit amet consectetur,";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_14) {
  char str1[] = "--$$$000---$@";
  char trim_chars[] = "-$0@";
  char *result = s21_trim(str1, trim_chars);
  char *expected = "";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_15) {
  char str1[] = "************";
  char trim_chars[] = "*";
  char *result = s21_trim(str1, trim_chars);
  char *expected = "";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

TCase *tcase_s21_trim(void) {
  TCase *tcase = tcase_create("s21_trim");
  tcase_add_test(tcase, test_s21_trim_1);
  tcase_add_test(tcase, test_s21_trim_2);
  tcase_add_test(tcase, test_s21_trim_3);
  tcase_add_test(tcase, test_s21_trim_4);
  tcase_add_test(tcase, test_s21_trim_5);
  tcase_add_test(tcase, test_s21_trim_6);
  tcase_add_test(tcase, test_s21_trim_7);
  tcase_add_test(tcase, test_s21_trim_8);
  tcase_add_test(tcase, test_s21_trim_9);
  tcase_add_test(tcase, test_s21_trim_10);
  tcase_add_test(tcase, test_s21_trim_11);
  tcase_add_test(tcase, test_s21_trim_12);
  tcase_add_test(tcase, test_s21_trim_13);
  tcase_add_test(tcase, test_s21_trim_14);
  tcase_add_test(tcase, test_s21_trim_15);

  return tcase;
}