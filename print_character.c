#include "main.h"

/**
 * print_character - Prints a char
 * @args: va_list
 * Return: number of characters printed
 */
int print_character(va_list args)
{
	char c = (char)va_arg(args, int);

	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}