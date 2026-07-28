#include "main.h"

/**
 * print_char - Prints a single character to standard output
 * @args: List of variadic arguments
 *
 * Return: Number of characters printed (always 1)
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	return (_putchar(c));
}
