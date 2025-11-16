#include <check.h>

#include "../s21_string.h"

Suite *string_suite(void);
extern TCase *tcase_s21_memchr(void);
extern TCase *tcase_s21_strpbrk(void);
extern TCase *tcase_s21_memcmp(void);
extern TCase *tcase_s21_memset(void);
extern TCase *tcase_s21_strchr(void);
extern TCase *tcase_s21_strrchr(void);

extern TCase *tcase_s21_memcpy(void);
extern TCase *tcase_s21_strtok(void);
extern TCase *tcase_s21_strncpy(void);
extern TCase *tcase_s21_trim(void);
extern TCase *tcase_s21_to_upper(void);
extern TCase *tcase_s21_insert(void);
extern TCase *tcase_s21_to_lower(void);
extern TCase *tcase_s21_strncat(void);
extern TCase *tcase_s21_strncmp(void);
extern TCase *tcase_s21_strstr(void);
extern TCase *tcase_s21_strlen(void);
extern TCase *tcase_s21_strcspn(void);
extern TCase *tcase_s21_sprintf(void);
extern TCase *tcase_s21_memmove(void);
extern TCase *tcase_s21_strcat(void);
extern TCase *tcase_s21_strerror(void);

int main(void) {
  Suite *s = string_suite();

  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  srunner_set_fork_status(runner, CK_FORK);

  int failed_count = 0;
  failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}

Suite *string_suite(void) {
  Suite *s = suite_create("s21_string");

  suite_add_tcase(s, tcase_s21_memchr());
  suite_add_tcase(s, tcase_s21_strpbrk());
  suite_add_tcase(s, tcase_s21_memcmp());
  suite_add_tcase(s, tcase_s21_memset());
  suite_add_tcase(s, tcase_s21_strchr());
  suite_add_tcase(s, tcase_s21_strrchr());

  suite_add_tcase(s, tcase_s21_memcpy());
  suite_add_tcase(s, tcase_s21_strtok());
  suite_add_tcase(s, tcase_s21_strncpy());
  suite_add_tcase(s, tcase_s21_trim());
  suite_add_tcase(s, tcase_s21_to_upper());
  suite_add_tcase(s, tcase_s21_insert());
  suite_add_tcase(s, tcase_s21_to_lower());
  suite_add_tcase(s, tcase_s21_strncat());
  suite_add_tcase(s, tcase_s21_strncmp());
  suite_add_tcase(s, tcase_s21_strstr());
  suite_add_tcase(s, tcase_s21_strlen());
  suite_add_tcase(s, tcase_s21_strcspn());
  suite_add_tcase(s, tcase_s21_sprintf());
  suite_add_tcase(s, tcase_s21_memmove());
  suite_add_tcase(s, tcase_s21_strcat());
  suite_add_tcase(s, tcase_s21_strerror());
  return s;
}

int sign_int(int x) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }
