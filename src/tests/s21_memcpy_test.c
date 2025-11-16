#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_memcpy_1) {
  char str[10] = "Hello";
  char str1[10] = "world!";
  s21_size_t len = strlen(str);
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(test_s21_memcpy_2) {
  char str[] = "Hello";
  char str1[] = "world";
  s21_size_t len = 2;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(test_s21_memcpy_3) {
  char str[] = "Hello";
  char str1[] = "world!";
  s21_size_t len = 0;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(test_s21_memcpy_4) {
  char str[] = "Hello, world!";
  char str1[] = "";
  s21_size_t len = 2;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(test_s21_memcpy_5) {
  char str[] = "12\t34\n56(!@";
  char str1[] = "Hello, world";
  s21_size_t len = 12;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(test_s21_memcpy_6) {
  char str[] = "Hello, world!";
  char str1[] = "12\t34\n56(!@";
  s21_size_t len = 12;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(test_s21_memcpy_7) {
  char str[] = "Hello, world!";
  char str1[] = "\0";
  s21_size_t len = strlen(str1);
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(test_s21_memcpy_8) {
  char str[] = "\0";
  char str1[] = "\0";
  s21_size_t len = 1;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(test_s21_memcpy_9) {
  char str[] = "\0";
  char str1[] = "\0";
  s21_size_t len = 0;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(test_s21_memcpy_10) {
  char str[] = "Hello";
  char str1[] = "Hello\0";
  s21_size_t len = 5;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(test_s21_memcpy_11) {
  char str[] = "Hello, world!";
  char str1[] = "Hello, world!\0";
  s21_size_t len = strlen(str1);
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(test_s21_memcpy_12) {
  char str[] = "Hello, world!";
  char str1[] = {10, 32, 64, 65, 127};
  s21_size_t len = 5;
  ck_assert_str_eq(memcpy(str, str1, len), s21_memcpy(str, str1, len));
}
END_TEST

START_TEST(test_s21_memcpy_13) {
  char s21_dest[] = "\0\0\0\0\0";
  char dest[] = "\0\0\0\0\0";
  char src[] = "\0";
  int len = 1;
  char* s21_result = s21_memcpy(s21_dest, src, len);
  char* result = memcpy(dest, src, len);
  ck_assert_ptr_eq(dest, result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memcpy_14) {
  char s21_dest[] = "1234567890\t1234567890\n";
  char dest[] = "1234567890\t1234567890\n";
  char src[] = "absolute";
  int len = strlen(src) - 2;
  char* s21_result = s21_memcpy(s21_dest, src, len);
  char* result = memcpy(dest, src, len);
  ck_assert_ptr_eq(dest, result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memcpy_15) {
  char s21_dest[64] = "";
  char dest[64] = "";
  char src[] = "Hello\n";
  int len = strlen(src) + 1;
  char* s21_result = s21_memcpy(s21_dest, src, len);
  char* result = memcpy(dest, src, len);
  ck_assert_ptr_eq(dest, result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

TCase* tcase_s21_memcpy(void) {
  TCase* tcase = tcase_create("s21_memcpy");
  tcase_add_test(tcase, test_s21_memcpy_1);
  tcase_add_test(tcase, test_s21_memcpy_2);
  tcase_add_test(tcase, test_s21_memcpy_3);
  tcase_add_test(tcase, test_s21_memcpy_4);
  tcase_add_test(tcase, test_s21_memcpy_5);
  tcase_add_test(tcase, test_s21_memcpy_6);
  tcase_add_test(tcase, test_s21_memcpy_7);
  tcase_add_test(tcase, test_s21_memcpy_8);
  tcase_add_test(tcase, test_s21_memcpy_9);
  tcase_add_test(tcase, test_s21_memcpy_10);
  tcase_add_test(tcase, test_s21_memcpy_11);
  tcase_add_test(tcase, test_s21_memcpy_12);
  tcase_add_test(tcase, test_s21_memcpy_13);
  tcase_add_test(tcase, test_s21_memcpy_14);
  tcase_add_test(tcase, test_s21_memcpy_15);
  return tcase;
}