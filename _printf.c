#include "main.h"
/**
 * _printf - the same implementation of printf
 * @format: format specifier
 * Return: length of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0, i, j;
	print_t print_funcs[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", convert_to_binary},
		{NULL, NULL}};

	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			for (j = 0; print_funcs[j].spec != NULL; j++)
			{
				if (format[i] == *print_funcs[j].spec)
					count += print_funcs[j].f(args);
			}
		}
		else
			count += write(1, &format[i], 1);
	}
	va_end(args);
	return (count);
}
