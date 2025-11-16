#include "s21_string.h"

char *s21_strrchr(const char *string, int c) {
  c = (unsigned char)c;
  const char *ptr = s21_NULL;

  while (*string) {
    if (*string == c) {
      ptr = string;
    }
    string++;
  }

  if (c == '\0') {
    return (char *)string;
  }

  return (char *)ptr;
}