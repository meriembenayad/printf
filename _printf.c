#include "main.h"
/**
 * _printf - the same implementation of printf
 * @format: format specifier
 * Return: length of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0, i, j;
	char buffer[BUFFER_SIZE];
	int buff_index = 0;
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
			for (j = 0; print_funcs[j].spec != NULL; j++)
			{
				if (format[i] == *print_funcs[j].spec)
					count += print_funcs[j].f(args);
			}
		}
		else
			buffer[buff_index++] = format[i];
			count++;
			if (buff_index == BUFFER_SIZE)
			{
				write(1, buffer, BUFFER_SIZE);
				buff_index = 0;
			}
	}
	if (buff_index > 0)
		write(1, buffer, buff_index);
	va_end(args);
	return (count);
}
