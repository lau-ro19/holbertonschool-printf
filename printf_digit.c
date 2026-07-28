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

}
