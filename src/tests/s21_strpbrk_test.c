#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_strpbrk_1) {
  char str[100] = "Hello, world!";
  char str1[100] = "world";
  ck_assert_pstr_eq(strpbrk(str, str1), strpbrk(str, str1));
}
END_TEST

START_TEST(test_s21_strpbrk_2) {
  char str[100] = "Hello, world!";
  char str1[100] = "not helloworld((";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(test_s21_strpbrk_3) {
  char str[100] = "Hello, world!";
  char str1[100] = "hello, world!";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(test_s21_strpbrk_4) {
  char str[100] = "Hello, world!";
  char str1[100] = "abc";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(test_s21_strpbrk_5) {
  char str[100] = "Hello, world!";
  char str1[100] = "";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(test_s21_strpbrk_6) {
  char str[100] = "Hello, world!";
  char str1[100] = "\0";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(test_s21_strpbrk_7) {
  char str[100] = "1234347";
  char str1[100] = "89";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(test_s21_strpbrk_8) {
  char str[100] = "1234347";
  char str1[100] = "123";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(test_s21_strpbrk_9) {
  char str[100] = "1234347";
  char str1[100] = "321";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(test_s21_strpbrk_10) {
  char str[100] = "";
  char str1[100] = "";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(test_s21_strpbrk_11) {
  char str[100] = "";
  char str1[100] = "Hello, world!";
  ck_assert_pstr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(test_s21_strpbrk_12) {
  char str1[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char str2[] = "\n";
  char *result = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_13) {
  char str1[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char str2[] = "ur.";
  char *result = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_14) {
  char str1[256] = "Lorem ipsum dolor\tsit amet consectetur.\n";
  char str2[5] = "\t";
  char *result = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_15) {
  char str1[] = "";
  char str2[] = "Ok";
  char *result = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_16) {
  char str1[] = "Hello, world!\n";
  char str2[] = "";
  char *result = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_17) {
  char str1[] = "Lorem ipsum dolor sit amet.\n";
  char str2[] = "_!_";
  char *result = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_18) {
  char str1[] = "1234567890\t1234567890\n";
  char str2[] = "789 ";
  char *result = s21_strpbrk(str1, str2);
  char *expected = strpbrk(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

TCase *tcase_s21_strpbrk(void) {
  TCase *tcase = tcase_create("s21_strpbrk");

  tcase_add_test(tcase, test_s21_strpbrk_1);
  tcase_add_test(tcase, test_s21_strpbrk_2);
  tcase_add_test(tcase, test_s21_strpbrk_3);
  tcase_add_test(tcase, test_s21_strpbrk_4);
  tcase_add_test(tcase, test_s21_strpbrk_5);
  tcase_add_test(tcase, test_s21_strpbrk_6);
  tcase_add_test(tcase, test_s21_strpbrk_7);
  tcase_add_test(tcase, test_s21_strpbrk_8);
  tcase_add_test(tcase, test_s21_strpbrk_9);
  tcase_add_test(tcase, test_s21_strpbrk_10);
  tcase_add_test(tcase, test_s21_strpbrk_11);
  tcase_add_test(tcase, test_s21_strpbrk_12);
  tcase_add_test(tcase, test_s21_strpbrk_13);
  tcase_add_test(tcase, test_s21_strpbrk_14);
  tcase_add_test(tcase, test_s21_strpbrk_15);
  tcase_add_test(tcase, test_s21_strpbrk_16);
  tcase_add_test(tcase, test_s21_strpbrk_17);
  tcase_add_test(tcase, test_s21_strpbrk_18);
  return tcase;
}