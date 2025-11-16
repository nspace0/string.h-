#include <stdio.h>
#include <string.h>
typedef long unsigned s21_size_t;

void *s21_memmove(void *dest_str, const void *src_str, s21_size_t n) {
  char *dest = (char *)dest_str;
  const char *source = (const char *)src_str;
  s21_size_t i;

  if (dest <= source) {
    for (i = 0; i < n; i++) {
      dest[i] = source[i];
    }
  }

  else {
    for (i = n; i > 0; i--) {
      dest[i - 1] = source[i - 1];
    }
  }

  return dest;
}