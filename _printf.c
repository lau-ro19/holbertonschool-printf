#include "main.h"

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	int (*f)(va_list);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			f = get_print_func(format[i + 1]);
			if (f)
			{
				count += f(args);
				i += 2;
				continue;
			}
			if (!format[i + 1])
				return (-1);
			count += _putchar('%');
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
