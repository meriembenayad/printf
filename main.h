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

int _putchar(char c);
int _printf(const char *format, ...);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_number(int num);
int print_int(va_list args);

int convert_to_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);

int print_hexa(va_list args, int uppercase);
int print_hexa_lower(va_list args);
int print_hexa_upper(va_list args);

#endif
