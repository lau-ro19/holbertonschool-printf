#include "main.h"

/**
 * write_text_block - writes normal text until a conversion is found
 * @format: format string
 * @index: address of the current index
 *
 * Return: number of characters written, or -1 on error
 */
int write_text_block(const char *format, int *index)
{
	int start;
	int total;
	ssize_t written;

	if (format == NULL || index == NULL)
		return (-1);

	start = *index;
	total = 0;

	while (format[*index] != '\0' && format[*index] != '%')
		(*index)++;

	while (start + total < *index)
	{
		written = write(STDOUT_FILENO, format + start + total,
				*index - start - total);
		if (written <= 0)
			return (-1);

		total += written;
	}

	return (total);
}
	/**
 * _printf - produces output according to a format
 * @format: character string containing format directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0, i = 0, printed;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		printed = write_text_block(format, &i);
		if (printed == -1)
		{
			va_end(args);
			return (-1);
		}
		count += printed;

		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(args);
			else if (format[i] == '%')
				count += print_percent(args);
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_digit(args);
			else
			{
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
			i++;
		}
	}

	va_end(args);
	return (count);

}
