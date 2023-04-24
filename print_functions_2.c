#include "main.h"
/**
 * convert_to_binary - prints unsigned number to binary
 * @args: number
 * Return: number printed
 */
int convert_to_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char binary[33];
	int count = 0, i;

	binary[32] = '\0';
	for (i = 31; i >= 0; i--)
	{
		binary[i] = (num % 2) + '0';
		num /= 2;
	}
	i = 0;
	while (binary[i] == '0' && i < 31)
		i++;
	while (binary[i] != '\0')
		count += _putchar(binary[i++]);
	return (count);
}
/**
 * print_unsigned - prints unsigned
 * @args: argument
 * Return: unsigned printed
 */
int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[11];
	int i = 10, count = 0;

	buffer[i] = '\0';
	if (num == 0)
		buffer[--i] = '0';
	while (num > 0)
	{
		buffer[--i] = (num % 10) + '0';
		num /= 10;
	}
	while (buffer[i] != '\0')
		count += _putchar(buffer[i++]);
	return (count);
}
/**
 * print_octal - prints octal
 * @args: argument
 * Return: octal printed
 */
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[12];
	int i = 11, count = 0;

	buffer[i] = '\0';
	if (num == 0)
		buffer[--i] = '0';
	while (num > 0)
	{
		buffer[--i] = (num % 8) + '0';
		num /= 8;
	}
	while (buffer[i] != '\0')
		count += _putchar(buffer[i++]);
	return (count);
}
