#include "main.h"

/**
 * print_number - recursive helper
 * @n: number
 * Return: count
 */
int print_number(long n)
{
	int count = 0;

	if (n < 0)
	{
		if (_putchar('-') < 0)
			return (-1);
		count++;
		n = -n;
	}
	if (n / 10)
	{
		count += print_number(n / 10);
	}
	if (_putchar((n % 10) + '0') < 0)
		return (-1);
	count++;
	return (count);
}

/**
 * print_decimal - prints int
 * @args: va_list
 * Return: count
 */
int print_decimal(va_list args)
{
	return (print_number(va_arg(args, int)));
}