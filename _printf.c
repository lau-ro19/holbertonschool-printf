#include "main.h"

/**
 * _printf - formatted output conversion
 * @format: string containing directives
 * Return: total number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, total = 0, printed = 0;
	int (*f)(va_list);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				printed = _putchar('%');
			}
			else
			{
				f = get_subprinter(format[i + 1]);
				if (f)
					printed = f(args);
				else if (format[i + 1] != '\0')
				{
					printed = _putchar('%');
					printed += _putchar(format[i + 1]);
				}
				else
					return (-1);
			}
			i += 2;
		}
		else
		{
			printed = _putchar(format[i]);
			i++;
		}
		if (printed < 0)
			return (-1);
		total += printed;
	}
	va_end(args);
	return (total);
}