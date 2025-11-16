#include "s21_string.h"

int s21_memcmp(const void *string1, const void *string2, s21_size_t n) {
  const unsigned char *ptr1 = (const unsigned char *)string1;
  const unsigned char *ptr2 = (const unsigned char *)string2;

  for (s21_size_t i = 0; i < n; i++) {
    if (ptr1[i] != ptr2[i]) {
      return ptr1[i] - ptr2[i];
    }
  }
  return 0;
}
