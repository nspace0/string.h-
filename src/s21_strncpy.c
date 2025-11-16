#include "s21_string.h"
char *s21_strncpy(char *destination, const char *source, s21_size_t n) {
  if (destination == s21_NULL || source == s21_NULL) return s21_NULL;
  char *ptr = destination;
  while (n > 0 && *source != '\0') {
    *destination++ = *source++;
    n--;
  }

  while (n > 0) {
    *destination++ = '\0';
    n--;
  }
  return ptr;
}
