#include "s21_string.h"
void *s21_to_upper(const char *string) {
  if (string == s21_NULL) return s21_NULL;

  s21_size_t len = s21_strlen(string);

  char *ptr = (char *)malloc(sizeof(char) * (len + 1));

  if (ptr == s21_NULL) return s21_NULL;

  for (s21_size_t i = 0; i < len; i++) {
    if (string[i] >= 97 && string[i] <= 122) {
      ptr[i] = string[i] - 32;
    } else {
      ptr[i] = string[i];
    }
  }
  ptr[len] = '\0';

  return ptr;
}
