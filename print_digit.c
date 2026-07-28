#include "main.h"

/**
 * print_digit - prints an integer (%d and %i)
 * @args: va_list containing the integer to print
 *
 * Return: number of characters printed
 */
int print_digit(va_list args)
{
	int count = 0;
	long int num;
	long int div;
	int n;

	n = va_arg(args, int);
	num = n;


	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	div = 1;
	while (num / div >= 10)
		div *= 10;

	while (div != 0)
	{
		_putchar((num / div) + '0');
		count++;

		num %= div;
		div /= 10;
	}
	return (count);
}
