#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_strcat_1) {
  char s21_dest[256] = "Hello, world!";
  char dest[256] = "Hello, world!";
  char src[] = "\nMy name is Henry";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_ptr_eq(result, dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_2) {
  char s21_dest[10] = "";
  char dest[10] = "";
  char src[] = "123";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_3) {
  char s21_dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[10] = " ";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_4) {
  char s21_dest[] = "\0\0\0";
  char dest[] = "\0\0\0";
  char src[] = "^";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_5) {
  char s21_dest[128] = "Hello, world!";
  char dest[128] = "Hello, world!";
  char src[] = "Hi, my name is Harry";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_6) {
  char s21_dest[128] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[128] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[] = "";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_7) {
  char s21_dest[128] = "";
  char dest[128] = "";
  char src[] = "1234567890\t1234567890";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_8) {
  char s21_dest[256] = "Hello, world!";
  char dest[256] = "Hello, world!";
  char src[] = "\nMy name is Henry";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_ptr_eq(result, dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_9) {
  char s21_dest[10] = "";
  char dest[10] = "";
  char src[] = "123";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_10) {
  char s21_dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[10] = " ";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_11) {
  char s21_dest[] = "\0\0\0";
  char dest[] = "\0\0\0";
  char src[] = "^";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_12) {
  char s21_dest[128] = "Hello, world!";
  char dest[128] = "Hello, world!";
  char src[] = "Hi, my name is Harry";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_13) {
  char s21_dest[128] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[128] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[] = "";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_14) {
  char s21_dest[128] = "";
  char dest[128] = "";
  char src[] = "1234567890\t1234567890";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_15) {
  char s21_dest[256] = "Hello, world!";
  char dest[256] = "Hello, world!";
  char src[] = "\nMy name is Henry";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_ptr_eq(result, dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_16) {
  char s21_dest[10] = "";
  char dest[10] = "";
  char src[] = "123";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_17) {
  char s21_dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[10] = " ";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_18) {
  char s21_dest[] = "\0\0\0";
  char dest[] = "\0\0\0";
  char src[] = "^";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_19) {
  char s21_dest[128] = "Hello, world!";
  char dest[128] = "Hello, world!";
  char src[] = "Hi, my name is Harry";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_20) {
  char s21_dest[128] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[128] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[] = "";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strcat_21) {
  char s21_dest[128] = "";
  char dest[128] = "";
  char src[] = "1234567890\t1234567890";
  char *s21_result = s21_strcat(s21_dest, src);
  char *result = strcat(dest, src);
  ck_assert_ptr_eq(s21_result, s21_dest);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

TCase *tcase_s21_strcat(void) {
  TCase *tcase = tcase_create("s21_strccat");
  tcase_add_test(tcase, test_s21_strcat_1);
  tcase_add_test(tcase, test_s21_strcat_2);
  tcase_add_test(tcase, test_s21_strcat_3);
  tcase_add_test(tcase, test_s21_strcat_4);
  tcase_add_test(tcase, test_s21_strcat_5);
  tcase_add_test(tcase, test_s21_strcat_6);
  tcase_add_test(tcase, test_s21_strcat_7);
  tcase_add_test(tcase, test_s21_strcat_8);
  tcase_add_test(tcase, test_s21_strcat_9);
  tcase_add_test(tcase, test_s21_strcat_10);
  tcase_add_test(tcase, test_s21_strcat_11);
  tcase_add_test(tcase, test_s21_strcat_12);
  tcase_add_test(tcase, test_s21_strcat_13);
  tcase_add_test(tcase, test_s21_strcat_14);
  tcase_add_test(tcase, test_s21_strcat_15);
  tcase_add_test(tcase, test_s21_strcat_16);
  tcase_add_test(tcase, test_s21_strcat_17);
  tcase_add_test(tcase, test_s21_strcat_18);
  tcase_add_test(tcase, test_s21_strcat_19);
  tcase_add_test(tcase, test_s21_strcat_20);
  tcase_add_test(tcase, test_s21_strcat_21);

  return tcase;
}