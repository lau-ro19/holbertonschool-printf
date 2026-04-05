#include "main.h"

/**
 * print_int - prints an integer (%d and %i)
 * @args: va_list containing the integer to print
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	long num = n;

	return (print_number(num));
}

/**
 * print_number - helper function that prints a number recursively
 * @n: the number to print
 * Return: number of characters printed
 */
int print_number(long n)
{
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}

	if (n / 10)
		count += print_number(n / 10);

	count += _putchar((n % 10) + '0');
	return (count);
}
