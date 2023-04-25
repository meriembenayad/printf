#include "main.h"
/**
 * print_hexa - prints hexadecimal
 * @args: argument
 * @uppercase: hexa in uppercase
 * Return: haxadecimal printed
 */
int print_hexa(va_list args, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[9];
	char *hex_digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	int i = 8;
	int count = 0;

	buffer[i] = '\0';
	if (num == 0)
		buffer[--i] = '0';
	while (num > 0)
	{
		buffer[--i] = hex_digits[num % 16];
		num /= 16;
	}
	while (buffer[i] != '\0')
		count += _putchar(buffer[i++]);
	return (count);
}
/**
 * print_hexa_lower - print lowercase hexadecimal
 * @args: argument
 * Return: hexadecimal in lowercase
 */
int print_hexa_lower(va_list args)
{
	return (print_hexa(args, 0));
}

/**
 * print_hexa_upper - print uppercase hexadecimal
 * @args: argument
 * Return: hexadecimal in uppercase
 */
int print_hexa_upper(va_list args)
{
	return (print_hexa(args, 1));
}
/**
 * print_pointer - prints pointer
 * @args: argument
 * Return: pointer printed
 */
int print_pointer(va_list args)
{
	int count = 2;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	num_addrs = (unsigned long)addrs;

	_putchar('0');
	_putchar('x');

	while (num_addrs > 0)
	{
		_putchar(map_to[num_addrs % 16]);
		num_addrs /= 16;
		count++;
	}

	return (count);
}
