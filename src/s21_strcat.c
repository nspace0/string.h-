#include "s21_string.h"

char *s21_strcat(char *dest, char *src) {
  char *temp = dest;
  while (*temp != '\0') {
    temp++;
  }
  while (*src != '\0') {
    *temp++ = *src++;
  }
  *temp = '\0';
  return dest;
}