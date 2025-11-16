#include "s21_string.h"

s21_size_t s21_strcspn(const char *string1, const char *string2) {
  s21_size_t lenstring1 = s21_strlen(string1);
  s21_size_t lenstring2 = s21_strlen(string2);
  s21_size_t i, j;

  for (i = 0; i < lenstring1; ++i)
    for (j = 0; j < lenstring2; ++j)
      if (string1[i] == string2[j]) return i;
  return i;
}
