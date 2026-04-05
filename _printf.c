#include "main.h"

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
				/* Ici, on appelle la fonction définie dans get_subprinter.c */
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