#include "s21_string.h"

char* s21_strpbrk(const char* string1, const char* string2) {
  const char* ptr1 = s21_NULL;
  const char* ptr2 = s21_NULL;

  for (ptr1 = string1; *ptr1 != '\0'; ptr1++) {
    for (ptr2 = string2; *ptr2 != '\0'; ptr2++) {
      if (*ptr1 == *ptr2) {
        return (char*)ptr1;
      }
    }
  }

  return s21_NULL;
}
