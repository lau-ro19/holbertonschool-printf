#include "main.h"

/**
 * print_percent - print a percent sign or the current format character
 * @i: index into the global format string
 *
 * This function checks the global `format` string at position `i` and
 * prints a literal percent sign if the character is '%%', otherwise it
 * prints the character found at format[i]. It increments the global
 * `count` variable to reflect the number of characters printed.
 *
 * Return: 0 on success (function updates globals), non-zero on error.
 */
int print_percent(int i)
{
	if (format[i] == '%')
	{
		_putchar('%');
		count++;
	}
	else
	{
		_putchar(format[i]);
		count++;
	}

	return (0);
}
