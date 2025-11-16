#include "s21_string.h"
s21_size_t s21_strlen(const char *string) {
  const char *end = string;

  while (*end != '\0') {
    ++end;
  }

  return end - string;
}
