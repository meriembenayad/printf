#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

/**
 * struct specifier - struct specifier
 * @spec: format specifier
 * @f: function pointer
 */
typedef struct specifier
{
	char *spec;
	int (*f)(va_list);
} print_t;

int _printf(const char *format, ...);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif
