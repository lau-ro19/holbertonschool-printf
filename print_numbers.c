#include "main.h"

/**
 * print_int - prints an integer
 * @args: va_list containing the int
 * Return: number of chars printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	long res = n;

	return (print_number(res));
}

/**
 * print_number - recursive helper to print digits
 * @n: the number to print (long to handle INT_MIN)
 * Return: count of digits printed
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
