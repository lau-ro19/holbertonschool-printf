#include "main.h"

/**
 * print_percent - prints a percent sign
 * @args: list of arguments (unused)
 *
 * Return: number of characters printed (always 1)
 */
int print_percent(va_list args)
{
	(void)args;

	return (_putchar('%'));
}
