#include "main.h"

/**
 * get_subprinter - Correspondance table for specifiers
 * @s: The character to match
 * Return: pointer to the printing function
 */
int (*get_subprinter(char s))(va_list)
{
	static int (*table[128])(va_list) = {NULL};

	table['c'] = print_character;
	table['s'] = print_string;
	table['d'] = print_decimal;
	table['i'] = print_decimal;

	return (table[(int)s]);
}

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, total = 0, spr = 0;
	int (*f)(va_list);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				spr = write(1, "%", 1);
			else
			{
				f = get_subprinter(format[i + 1]);
				if (f)
					spr = f(args);
				else if (format[i + 1] != '\0')
				{
					spr = write(1, &format[i], 1);
					spr += write(1, &format[i + 1], 1);
				}
				else
					return (-1);
			}
			i++;
		}
		else
			spr = write(1, &format[i], 1);

		if (spr < 0)
			return (-1);
		total += spr;
		i++;
	}
	va_end(args);
	return (total);
}