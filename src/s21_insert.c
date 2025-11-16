#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = s21_NULL;
  if (src && str) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);

    if (start_index <= src_len) {
      s21_size_t size = src_len + str_len + 1;
      char *ins = (char *)calloc(size, sizeof(char));

      if (ins) {
        s21_strncpy(ins, src, start_index);
        s21_strncat(ins, str, str_len);
        s21_strncat(ins, src + start_index, src_len - start_index);
        res = ins;
      }
    }
  }
  return (void *)res;
}
