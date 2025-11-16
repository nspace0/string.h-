#include "s21_string.h"

char *s21_strchr(const char *string, int c) {
  c = (unsigned char)c;

  while (*string) {
    if (*string == c) {
      return (char *)string;
    }
    string++;
  }

  if (c == '\0') {
    return (char *)string;
  }
  return s21_NULL;
}
