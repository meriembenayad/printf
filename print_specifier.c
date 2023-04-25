#include "main.h"
/**
 * get_print_funcs - function to get functions
 * Return: pointer to print_t
 */
print_t *get_print_funcs(void)
{
	static print_t print_funcs[] = {
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
		{"S", print_S},
		{"p", print_pointer},
		{NULL, NULL}};
	return (print_funcs);
}
