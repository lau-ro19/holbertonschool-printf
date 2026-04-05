#include "main.h"

/**
 * recursive_int - helper to print digits
 * @n: the number
 * @count: internal counter
 * Return: 0 on success, -1 on failure
 */
int recursive_int(unsigned int n, int *count)
{
	char digit;

	if (n / 10)
	{
		if (recursive_int(n / 10, count) < 0)
			return (-1);
	}
	digit = (n % 10) + '0';
	if (write(1, &digit, 1) < 0)
		return (-1);
	(*count)++;
	return (0);
}

/**
 * print_decimal - prints an integer
 * @args: va_list
 * Return: number of characters printed
 */
int print_decimal(va_list args)
{
	int n = va_arg(args, int);
	unsigned int abs_n;
	int count = 0;

	if (n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		count++;
		abs_n = (unsigned int)(-n);
	}
	else
		abs_n = (unsigned int)n;

	if (recursive_int(abs_n, &count) < 0)
		return (-1);

	return (count);
}