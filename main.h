#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

#define BUFFERSIZE 1024

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

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
print_t *get_print_funcs(void);
int _printf(const char *format, ...);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);

int convert_to_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);

int print_hexa(va_list args, int uppercase);
int print_hexa_lower(va_list args);
int print_hexa_upper(va_list args);
int print_pointer(va_list args);

int print_S(va_list args);
/* get_flag */
int get_flag(char s, flags_t *f);

#endif
