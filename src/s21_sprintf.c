#include "s21_sprintf.h"

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "s21_string.h"

void reverse_str(char* str) {
  char* end = str + (s21_strlen(str) - 1);
  char* start = str;

  while (start < end) {
    char temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }
}

int int_to_str(char* str, long long int num, int presition) {
  int len = 0;
  if (num == 0) {
    str[len++] = '0';
  }
  while (num > 0) {
    str[len++] = num % 10 + '0';
    num = num / 10;
  }
  while (len < presition) {
    str[len++] = '0';
  }
  str[len] = '\0';
  reverse_str(str);
  return len;
}

void s21_ltoa(char* str, Spec spec, long long int n) {
  unsigned long long int num = n < 0 ? -n : n;
  int len = 0;

  if (num == 0) {
    str[len++] = '0';
  }

  while (num > 0) {
    str[len++] = num % 10 + '0';
    num = num / 10;
  }
  while (len < spec.presition) {
    str[len++] = '0';
  }

  if (spec.flag_plus && n >= 0) {
    str[len++] = '+';
  } else if (spec.flag_space && n >= 0) {
    str[len++] = ' ';
  } else if (n < 0) {
    str[len++] = '-';
  }
  str[len] = '\0';
  reverse_str(str);

  if (spec.width > len) {
    if (spec.flag_minus) {
      s21_memset(str + len, ' ', (spec.width - len));
    } else {
      s21_memmove(str + (spec.width - len), str, len + 1);
      s21_memset(str, ' ', (spec.width - len));
    }
    len = spec.width;
    str[len] = '\0';
  }
}
void parse_spec(Spec* spec, char** format) {
  spec->flag_plus = 0;
  spec->flag_minus = 0;
  spec->flag_space = 0;
  spec->width = 0;
  spec->presition = -1;
  spec->length = 0;
  spec->specificator = 0;
  while (s21_strchr(" +-", **format)) {
    if (**format == ' ') spec->flag_space = 1;
    if (**format == '+') spec->flag_plus = 1;
    if (**format == '-') spec->flag_minus = 1;
    (*format)++;
  }
  while (s21_strchr("0123456789", **format)) {
    spec->width = (spec->width * 10) + (**format - '0');
    (*format)++;
  }
  if (**format == '.') {
    spec->presition = 0;
    (*format)++;
    while (s21_strchr("0123456789", **format)) {
      spec->presition = (spec->presition * 10) + (**format - '0');
      (*format)++;
    }
  }
  while (s21_strchr("hl", **format)) {
    spec->length = **format;
    (*format)++;
  }
  spec->specificator = **format;
  if (spec->specificator == 'f' && spec->presition == -1) {
    spec->presition = 6;
  }
  (*format)++;
}

void s21_ftoa(char* str, Spec spec, long double n) {
  long long ipart = (long long)fabsl(n);
  long double fpart = fabsl(n) - (long double)ipart;
  long double rounding = 0.5;
  int len = 0;

  for (int i = 0; i < spec.presition; i++) {
    rounding /= 10;
  }
  fpart += rounding;
  if (fpart >= 1.0) {
    ipart += 1;
    fpart -= 1.0;
  }
  len = int_to_str(str, ipart, 0);

  if (spec.presition) {
    str[len++] = '.';
    fpart = fpart * pow(10, spec.presition);
    len += int_to_str(str + len, (long long)(fpart), spec.presition);
  }

  if (spec.flag_plus && n >= 0) {
    s21_memmove(str + 1, str, ++len);
    s21_memset(str, '+', 1);
  } else if (spec.flag_space && n >= 0) {
    s21_memmove(str + 1, str, ++len);
    s21_memset(str, ' ', 1);
  } else if (n < 0) {
    s21_memmove(str + 1, str, ++len);
    s21_memset(str, '-', 1);
  }

  if (spec.width > len) {
    if (spec.flag_minus) {
      s21_memset(str + len, ' ', (spec.width - len));
    } else {
      s21_memmove(str + (spec.width - len), str, len + 1);
      s21_memset(str, ' ', (spec.width - len));
    }
    len = spec.width;
    str[len] = '\0';
  }
}

void s21_ctoa(char* str, Spec spec, char b) {
  int len = 1;
  str[0] = b;

  if (spec.width > len) {
    if (spec.flag_minus) {
      s21_memset(str + len, ' ', spec.width - len);
    } else {
      s21_memmove(str + (spec.width - len), str, 1);
      s21_memset(str, ' ', (spec.width - len));
    }
    len = spec.width;
  }
  str[len] = '\0';
}

void s21_wctoa(char* str, Spec spec, wchar_t c) {
  // printf("%s", str);
  int len = wctomb(str, c);
  if (spec.width > len) {
    if (spec.flag_minus) {
      s21_memset(str + len, ' ', (spec.width - len));
    } else {
      s21_memmove(str + (spec.width - len), str, len);
      s21_memset(str, ' ', (spec.width - len));
    }
    len = spec.width;
  }
  str[len] = '\0';
}

void s21_stoa(char* str, Spec spec, char* src) {
  s21_strcat(str, src);

  if (spec.presition >= 0 && (s21_size_t)spec.presition <= s21_strlen(str)) {
    str[spec.presition] = '\0';
  }
  s21_size_t len = s21_strlen(str);
  if ((s21_size_t)spec.width > len) {
    if (spec.flag_minus) {
      s21_memset(str + len, ' ', (spec.width - len));
    } else {
      s21_memmove(str + (spec.width - len), str, len + 1);
      s21_memset(str, ' ', (spec.width - len));
    }
    len = spec.width;
    str[len] = '\0';
  }
}

void s21_wstoa(char* str, Spec spec, wchar_t* src) {
  s21_size_t actual_len = 0;
  s21_size_t buf_size = MB_CUR_MAX * wcslen(src) + 1;
  int len = wcstombs(str, src, buf_size);
  if (spec.presition >= 0 && spec.presition <= len) {
    for (int i = 0; i < spec.presition; i++) {
      s21_size_t char_len =
          mbrlen(str + actual_len, buf_size - actual_len, s21_NULL);
      if (actual_len + char_len > (s21_size_t)spec.presition) {
        break;
      }
      actual_len += char_len;
    }
    str[actual_len] = '\0';
    len = actual_len;
  }
  if (spec.width > len) {
    if (spec.flag_minus) {
      s21_memset(str + len, ' ', (spec.width - len));
    } else {
      s21_memmove(str + (spec.width - len), str, len + 1);
      s21_memset(str, ' ', (spec.width - len));
    }
    len = spec.width;
    str[len] = '\0';
  }
}

int s21_sprintf(char* str, const char* format, ...) {
  str[0] = '\0';
  va_list arguments;
  va_start(arguments, format);
  int counter = 0;
  char* s = str;
  while (*format) {
    s = str + counter;

    if (*format == '%') {
      format++;
      Spec spec;
      parse_spec(&spec, (char**)&format);

      if (spec.specificator == 'd' || spec.specificator == 'i') {
        if (spec.length == 'l') {
          s21_ltoa(s, spec, va_arg(arguments, long int));
        } else if (spec.length == 'h') {
          s21_ltoa(s, spec, va_arg(arguments, int));
        } else {
          s21_ltoa(s, spec, va_arg(arguments, int));
        }
      }

      else if (spec.specificator == 'f') {
        s21_ftoa(s, spec, va_arg(arguments, double));
      }

      else if (spec.specificator == 'c') {
        if (spec.length == 'l') {
          s21_wctoa(s, spec, va_arg(arguments, wchar_t));
        } else {
          s21_ctoa(s, spec, va_arg(arguments, int));
        }
      }

      else if (spec.specificator == 's') {
        if (spec.length == 'l') {
          s21_wstoa(s, spec, va_arg(arguments, wchar_t*));
        } else {
          s21_stoa(s, spec, va_arg(arguments, char*));
        }
      }

      else if (spec.specificator == 'u') {
        if (spec.length == 'l') {
          s21_ltoa(s, spec, va_arg(arguments, unsigned long));
        } else if (spec.length == 'h') {
          s21_ltoa(s, spec, va_arg(arguments, unsigned int));
        } else {
          s21_ltoa(s, spec, va_arg(arguments, unsigned int));
        }
      } else if (spec.specificator == '%') {
        *s++ = '%';
        *s = '\0';
      }

    } else {
      *s++ = *format++;
      *s = '\0';
    }
    s21_size_t len = s21_strlen(str + counter);
    counter += len;
  }
  va_end(arguments);
  return counter;
}
