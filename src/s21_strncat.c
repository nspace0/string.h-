#include "s21_string.h"

char *s21_strncat(char *destination, const char *source, s21_size_t n) {
  char *ptr = destination;

  while (*ptr != '\0') {
    ptr++;
  }

  while (n-- && *source != '\0') {
    *ptr++ = *source++;
  }

  *ptr = '\0';

  return destination;
}
