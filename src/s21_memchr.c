#include "s21_string.h"
void *s21_memchr(const void *string, int c, s21_size_t n) {
  const unsigned char *ptr = (const unsigned char *)string;
  unsigned char ch = (unsigned char)c;

  while (n--) {
    if (*ptr == ch) return (void *)ptr;

    ptr++;
  }
  return s21_NULL;
}
