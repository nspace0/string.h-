#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_memmove_1) {
  char s21_dest[] = "Hello, world!\n";
  char dest[] = "Hello, world!\n";
  char src[] = "Hello, world!\n";
  int len = strlen(src);
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_ptr_eq(s21_dest, s21_result);
  ck_assert_ptr_eq(dest, result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_2) {
  char s21_dest[] = "Hello, world!\n";
  char dest[] = "Hello, world!\n";
  char src[] = "This is";
  int len = strlen(src);
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_3) {
  char s21_dest[] = "0123456789\n";
  char dest[] = "0123456789\n";
  char src[] = "abcdefghijklm";
  int len = strlen(dest);
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_4) {
  char s21_dest[] = "Hello, world!\n";
  char dest[] = "Hello, world!\n";
  char src[] = "0123456789";
  int len = 3;
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_5) {
  char s21_dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[] = "!2345";
  int len = strlen(src);
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_6) {
  char s21_dest[] = "\0\0\0\0\0";
  char dest[] = "\0\0\0\0\0";
  char src[] = "\0";
  int len = strlen(src);
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_7) {
  char s21_dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[] = "Hello\n";
  int len = 0;
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_8) {
  char s21_dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[] = "Hello\n";
  int len = strlen(src) + 5;
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_9) {
  char s21_dest[] = "Hello, world!\n";
  char dest[] = "Hello, world!\n";
  char src[] = "Hello, world!\n";
  int len = strlen(src);
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_ptr_eq(s21_dest, s21_result);
  ck_assert_ptr_eq(dest, result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_10) {
  char s21_dest[] = "Hello, world!\n";
  char dest[] = "Hello, world!\n";
  char src[] = "This is";
  int len = strlen(src);
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_11) {
  char s21_dest[] = "0123456789\n";
  char dest[] = "0123456789\n";
  char src[] = "abcdefghijklm";
  int len = strlen(dest);
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_12) {
  char s21_dest[] = "Hello, world!\n";
  char dest[] = "Hello, world!\n";
  char src[] = "0123456789";
  int len = 3;
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_13) {
  char s21_dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[] = "!2345";
  int len = strlen(src);
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_14) {
  char s21_dest[] = "\0\0\0\0\0";
  char dest[] = "\0\0\0\0\0";
  char src[] = "\0";
  int len = strlen(src);
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_15) {
  char s21_dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[] = "Hello\n";
  int len = 0;
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_16) {
  char s21_dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[] = "Hello\n";
  int len = strlen(src) + 5;
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_17) {
  char s21_dest[] = "Hello, world!\n";
  char dest[] = "Hello, world!\n";
  char src[] = "Hello, world!\n";
  int len = strlen(src);
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_ptr_eq(s21_dest, s21_result);
  ck_assert_ptr_eq(dest, result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_18) {
  char s21_dest[] = "Hello, world!\n";
  char dest[] = "Hello, world!\n";
  char src[] = "This is";
  int len = strlen(src);
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_19) {
  char s21_dest[] = "0123456789\n";
  char dest[] = "0123456789\n";
  char src[] = "abcdefghijklm";
  int len = strlen(dest);
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_20) {
  char s21_dest[] = "Hello, world!\n";
  char dest[] = "Hello, world!\n";
  char src[] = "0123456789";
  int len = 3;
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_21) {
  char s21_dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[256] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[] = "!2345";
  int len = strlen(src);
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_22) {
  char s21_dest[] = "\0\0\0\0\0";
  char dest[] = "\0\0\0\0\0";
  char src[] = "\0";
  int len = strlen(src);
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_23) {
  char s21_dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[] = "Hello\n";
  int len = 0;
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_24) {
  char s21_dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char src[] = "Hello\n";
  int len = strlen(src) + 5;
  char* s21_result = s21_memmove(s21_dest, src, len);
  char* result = memmove(dest, src, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_memmove_25) {
  char s21_dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  char dest[] = "Lorem ipsum dolor sit amet consectetur.\n";
  int len = 10;
  char* s21_result = s21_memmove(s21_dest, s21_dest + 2, len);
  char* result = memmove(dest, dest + 2, len);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

TCase* tcase_s21_memmove(void) {
  TCase* tcase = tcase_create("s21_memmove");
  tcase_add_test(tcase, test_s21_memmove_1);
  tcase_add_test(tcase, test_s21_memmove_2);
  tcase_add_test(tcase, test_s21_memmove_3);
  tcase_add_test(tcase, test_s21_memmove_4);
  tcase_add_test(tcase, test_s21_memmove_5);
  tcase_add_test(tcase, test_s21_memmove_6);
  tcase_add_test(tcase, test_s21_memmove_7);
  tcase_add_test(tcase, test_s21_memmove_8);
  tcase_add_test(tcase, test_s21_memmove_9);
  tcase_add_test(tcase, test_s21_memmove_10);
  tcase_add_test(tcase, test_s21_memmove_11);
  tcase_add_test(tcase, test_s21_memmove_12);
  tcase_add_test(tcase, test_s21_memmove_13);
  tcase_add_test(tcase, test_s21_memmove_14);
  tcase_add_test(tcase, test_s21_memmove_15);
  tcase_add_test(tcase, test_s21_memmove_16);
  tcase_add_test(tcase, test_s21_memmove_17);
  tcase_add_test(tcase, test_s21_memmove_18);
  tcase_add_test(tcase, test_s21_memmove_19);
  tcase_add_test(tcase, test_s21_memmove_20);
  tcase_add_test(tcase, test_s21_memmove_21);
  tcase_add_test(tcase, test_s21_memmove_22);
  tcase_add_test(tcase, test_s21_memmove_23);
  tcase_add_test(tcase, test_s21_memmove_24);
  tcase_add_test(tcase, test_s21_memmove_25);

  return tcase;
}