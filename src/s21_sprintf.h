#include "s21_string.h"

typedef struct spec {
  int flag_plus;
  int flag_minus;
  int flag_space;
  int width;
  int presition;
  char length;
  char specificator;

} Spec;

int s21_sprintf(char* str, const char* format, ...);