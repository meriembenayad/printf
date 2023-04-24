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
 * print_number - prints number
 * @num: number
 * Return: number
 */
int print_number(int num)
{
	int count = 0;

	if (num < 0)
	{
		count += _putchar('-');
		num = -num;
	}
	if (num / 10 > 0)
		count += print_number(num / 10);
	count += _putchar("0123456789"[num % 10]);
	return (count);
}
/**
 * print_int - prints integer
 * @args: argument
 * Return: integer printed
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);

	return (print_number(num));
}
