#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j, count = 0;
	op_t ops[] = {
		{"c", print_char}, {"s", print_str},
		{"%", print_pct}, {"d", print_int},
		{"i", print_int}, {NULL, NULL}
	};

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (ops[j].op)
			{
				if (format[i + 1] == ops[j].op[0])
				{
					count += ops[j].f(args);
					i++;
					break;
				}
				j++;
			}
			if (!ops[j].op && format[i + 1])
				count += _putchar(format[i]);
			else if (!ops[j].op && !format[i + 1])
				return (-1);
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
