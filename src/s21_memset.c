#include "s21_string.h"
void *s21_memset(void *string, int c, s21_size_t n) {
  unsigned char *p = (unsigned char *)string;
  while (n > 0) {
    *p = (unsigned char)c;
    n--;
    p++;
  }
  return string;
}
