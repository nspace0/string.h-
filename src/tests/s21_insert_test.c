#include "../s21_string.h"
#include "main_test.h"

START_TEST(test_s21_insert_1) {
  char *result = s21_insert("Hello", " world", 5);
  ck_assert_str_eq(result, "Hello world");
  free(result);
}
END_TEST

START_TEST(test_s21_insert_2) {
  char *result = s21_insert(" ", "Hello world", 0);
  ck_assert_str_eq(result, "Hello world ");
  free(result);
}
END_TEST

START_TEST(test_s21_insert_3) {
  char *result = s21_insert("Hello", " world", 0);
  ck_assert_str_eq(result, " worldHello");
  free(result);
}
END_TEST

START_TEST(test_s21_insert_4) {
  char *result = s21_insert("Hello", " world", -1);
  ck_assert_ptr_eq(result, s21_NULL);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_5) {
  char *result = s21_insert("Hello", " world", 15);
  ck_assert_ptr_eq(result, s21_NULL);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_6) {
  char *result = s21_insert("Hello world", "", 5);
  ck_assert_str_eq(result, "Hello world");
  free(result);
}
END_TEST

START_TEST(test_s21_insert_7) {
  char *src = "Lorem ipsum dolor sit amet consectetur.";
  char *str = s21_NULL;
  s21_size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_s21_insert_8) {
  char *src = s21_NULL;
  char *str = "s21_NULL";
  s21_size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_s21_insert_9) {
  char src[] = "Hello";
  char str[] = ", world!\n";
  s21_size_t start_index = 6;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_s21_insert_10) {
  char src[] = "";
  char str[] = "";
  s21_size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  char *expected = "";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_insert_11) {
  char src[] = "1234567 8910";
  char str[] = "xyz ";
  s21_size_t start_index = 8;
  char *result = s21_insert(src, str, start_index);
  char *expected = "1234567 xyz 8910";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_insert_12) {
  char src[] = "Hello";
  char str[] = ", world!\n";
  s21_size_t start_index = 5;
  char *result = s21_insert(src, str, start_index);
  char *expected = "Hello, world!\n";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_insert_13) {
  char src[] = "1234567 8910";
  char str[] = "xyz ";
  s21_size_t start_index = 8;
  char *result = s21_insert(src, str, start_index);
  char *expected = "1234567 xyz 8910";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_insert_14) {
  char src[] = "world!\n";
  char str[] = "Hello, ";
  s21_size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  char *expected = "Hello, world!\n";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_insert_15) {
  char src[] = "Hello";
  char str[] = ", world!\n";
  s21_size_t start_index = 5;
  char *result = s21_insert(src, str, start_index);
  char *expected = "Hello, world!\n";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_insert_16) {
  char *src = "Lorem ipsum dolor sit amet consectetur.";
  char *str = s21_NULL;
  s21_size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_s21_insert_17) {
  char *src = s21_NULL;
  char *str = "s21_NULL";
  s21_size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_null(result);
}
END_TEST

TCase *tcase_s21_insert(void) {
  TCase *tcase = tcase_create("s21_insert");
  tcase_add_test(tcase, test_s21_insert_1);
  tcase_add_test(tcase, test_s21_insert_2);
  tcase_add_test(tcase, test_s21_insert_3);
  tcase_add_test(tcase, test_s21_insert_4);
  tcase_add_test(tcase, test_s21_insert_5);
  tcase_add_test(tcase, test_s21_insert_6);
  tcase_add_test(tcase, test_s21_insert_7);
  tcase_add_test(tcase, test_s21_insert_8);
  tcase_add_test(tcase, test_s21_insert_9);
  tcase_add_test(tcase, test_s21_insert_10);
  tcase_add_test(tcase, test_s21_insert_11);
  tcase_add_test(tcase, test_s21_insert_12);
  tcase_add_test(tcase, test_s21_insert_13);
  tcase_add_test(tcase, test_s21_insert_14);
  tcase_add_test(tcase, test_s21_insert_15);
  tcase_add_test(tcase, test_s21_insert_16);
  tcase_add_test(tcase, test_s21_insert_17);
  return tcase;
}