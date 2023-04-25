#include "main.h"
/**
 * _printf - the same implementation of printf
 * @format: format specifier
 * Return: length of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0, i, j, flag, space = 0;
	print_t *print_funcs = get_print_funcs();
	va_list args;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			for (; format[i] == ' '; i++)
				space = 0;
			flag = 0;
			for (j = 0; print_funcs[j].spec != NULL; j++)
			{
				if (format[i] == *print_funcs[j].spec)
				{
					if (space)
					{
						count += _putchar(' ');
						space = 0;
					}
					count += print_funcs[j].f(args);
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
	}
	va_end(args);
	return (count);
}
