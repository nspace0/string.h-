#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *static_str = s21_NULL;
  char *start = s21_NULL;

  if (str) {
    static_str = str;
  }

  if (static_str) {
    // Пропускаем начальные разделители
    while (*static_str && s21_strchr(delim, *static_str)) {
      static_str++;
    }

    // Если достигли конца строки, возвращаем NULL
    if (*static_str == '\0') {
      return s21_NULL;
    }

    start = static_str;

    // Ищем конец токена
    while (*static_str && !s21_strchr(delim, *static_str)) {
      static_str++;
    }

    // Если достигли разделителя, заменяем его на '\0' и перемещаем указатель
    if (*static_str) {
      *static_str = '\0';
      static_str++;
    } else {
      // Если достигли конца строки, устанавливаем static_str в NULL
      static_str = s21_NULL;
    }
  }
  return start;
}
