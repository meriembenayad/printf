#include "main.h"
/**
 * print_char - prints character
 * @args: argument
 * Return: character printed
 */
int print_char(va_list args)
{
	int character = va_arg(args, int);

	return (write(1, &character, 1));
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
		count += write(1, &str[i], 1);
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
	return (write(1, "%", 1));
}
