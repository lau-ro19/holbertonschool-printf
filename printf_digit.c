#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	long int num;
	long int div;

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
