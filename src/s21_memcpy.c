#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *ptrDest = (unsigned char *)dest;
  const unsigned char *ptrSrc = (const unsigned char *)src;
  while (n--) *ptrDest++ = *ptrSrc++;
  return dest;
}