#include "main.h"
/**
 * print_S - prints the string
 * @args: argument
 * Return: string printed
 */
int print_S(va_list args)
{
	int count = 0;
	unsigned int i;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] > 0 && str[i] < 32)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar("0123456789ABCDEF"[str[i] / 16]);
			count += _putchar("0123456789ABCDEF"[str[i] % 16]);
		}
		else
		{
			count += _putchar(str[i]);
		}
	}

	return (count);
}
