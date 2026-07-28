#include "main.h"

/**
 * print_string - Prints a string to standard output
 * @args: List of variadic arguments
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	int count = 0;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	while (*str != '\0')
	{
		count += _putchar(*str);
		str++;
	}

	return (count);
}