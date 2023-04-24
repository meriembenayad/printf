#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

typedef struct token
{
    char *spec;
    int (*f)(va_list);
} print_t;

int _printf(const char *format, ...);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_number(int num);
int print_int(va_list args);
int convert_to_binary(va_list args);

#endif
