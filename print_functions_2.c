#include "main.h"
/**
 * convert_to_binary - prints unsigned number to binary
 * @num: number
 * Return: number printed
 */
int convert_to_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char binary[33];
	int count = 0, i;

	binary[32] = '\0';
	for (i = 31; i >= 0; i--)
	{
		binary[i] = (n % 2) + '0';
		n /= 2;
	}
	i = 0;
	while (binary[i] == '0' && i < 31)
		i++;
	while (binary[i] != '\0')
		count += write(1, &binary[i++], 1);
	return (count);
}
