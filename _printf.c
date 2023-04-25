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
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hexa_lower},
		{"X", print_hexa_upper},
		{NULL, NULL}};

	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'y')
			{
				count += _putchar('%');
				count += _putchar('y');
			}
			else
			{
				for (j = 0; print_funcs[j].spec != NULL; j++)
				{
					if (format[i] == *print_funcs[j].spec)
						count += print_funcs[j].f(args);
				}
			}
		}
		else
			count += _putchar(format[i]);
	}
	va_end(args);
	return (count);
}
