#include "main.h"
/**
 * print_char - prints character
 * @args: argument
 * Return: character printed
 */
int print_char(va_list args)
{
	int character = va_arg(args, int);

	return (_putchar(character));
}

/**
 * print_string - prints string
 * @args: argument
 * Return: string printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0, i;

	if (str == NULL)
	{
		str = "(null)";
	}

	for (i = 0; str[i] != '\0'; i++)
		count += _putchar(str[i]);
	return (count);
}
/**
 * print_percent - prints percent
 * @args: argument
 * Return: percent (%)
 */
int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}
/**
 * print_int - prints integer
 * @args: argument
 * Return: integer printed
 */
int print_int(va_list ap)
{
	int n = va_arg(ap, int);
	unsigned int num = n;
	int div = 1, count = 0;
	char c;

	if (n < 0)
	{
		count += write(1, "-", 1);
		num = -n;
	}

	while (num / div >= 10)
		div *= 10;

	while (div >= 1)
	{
		c = '0' + num / div;
		count += write(1, &c, 1);
		num %= div;
		div /= 10;
	}

	return (count);
}
