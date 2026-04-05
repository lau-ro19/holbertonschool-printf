#include "main.h"

/**
 * print_char - prints a char
 * @args: va_list containing the char
 * Return: 1
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * print_str - prints a string
 * @args: va_list containing the string
 * Return: number of chars printed
 */
int print_str(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (!str)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * print_percent - prints a %
 * @args: ignored
 * Return: 1
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}
