#include "main.h"

/**
 * print_character - prints char
 * @args: va_list
 * Return: 1
 */
int print_character(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_string - prints string
 * @args: va_list
 * Return: number of chars
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
		str = "(null)";

	while (str[count])
	{
		if (_putchar(str[count]) < 0)
			return (-1);
		count++;
	}
	return (count);
}