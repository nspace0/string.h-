#include "s21_string.h"

char* s21_strstr(const char* haystack, const char* needle) {
  size_t s1len = s21_strlen(haystack);
  size_t s2len = s21_strlen(needle);

  if (s2len > s1len) return s21_NULL;

  for (size_t i = 0; i <= s1len - s2len; ++i) {
    size_t j;
    for (j = 0; j < s2len; ++j)
      if (haystack[i + j] != needle[j]) break;
    if (j == s2len) return (char*)haystack + i;
  }

  return s21_NULL;
}