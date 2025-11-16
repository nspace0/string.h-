#ifndef S21_STRING_H
#define S21_STRING_H
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef unsigned long s21_size_t;
#define s21_NULL (void *)0

void *s21_memchr(const void *string, int c, s21_size_t n);
int s21_memcmp(const void *string1, const void *string2, s21_size_t n);
void *s21_memcpy(void *destination, const void *source, s21_size_t n);
void *s21_memset(void *string, int c, s21_size_t n);
char *s21_strncat(char *destination, const char *source, s21_size_t n);

char *s21_strchr(const char *string, int c);
int s21_strncmp(const char *string1, const char *string2, s21_size_t n);
char *s21_strncpy(char *destination, const char *source, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);

s21_size_t s21_strlen(const char *string);
char *s21_strpbrk(const char *string1, const char *string2);
char *s21_strrchr(const char *string, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

void *s21_memmove(void *dest_str, const void *src_str, s21_size_t numBytes);
char *s21_strcat(char *dest, char *src);

// bonus quest5
void *s21_to_upper(const char *string);
void *s21_to_lower(const char *string);
void *s21_insert(const char *source, const char *string,
                 s21_size_t start_index);
void *s21_trim(const char *source, const char *trim_chars);

#endif