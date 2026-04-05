#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int recursive_int(unsigned int n, int *count)
{
	char digit;

	if (n / 10)
	{
		if (recursive_int(n / 10, count) < 0)
			return (-1);
	}
	digit = (char)((n % 10) + '0');
	if (write(1, &digit, 1) < 0)
		return (-1);
	(*count)++;
	return (0);
}

int print_decimal(va_list args)
{
	int n;
	unsigned int abs_n;
	int count = 0;

	n = va_arg(args, int);
	if (n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		count++;
		abs_n = (unsigned int)(-(n + 1)) + 1;
	}
	else
		abs_n = (unsigned int)n;
	if (recursive_int(abs_n, &count) < 0)
		return (-1);
	return (count);
}
