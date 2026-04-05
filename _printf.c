#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int (**get_subprinters(void))(va_list)
{
	static int (*table[128])(va_list);

	table['c'] = print_character;
	table['s'] = print_string;
	table['d'] = print_decimal;
	table['i'] = print_decimal;
	table['b'] = print_binary;
	table['o'] = print_octal;
	table['u'] = print_uint;
	table['x'] = print_hexadecimal_lowercase;
	table['X'] = print_hexadecimal_uppercase;
	return (table);
}

int print_single_char(char c, int *total)
{
	int ret;

	ret = write(1, &c, 1);
	if (ret >= 0)
		*total += ret;
	return (ret);
}

int delegate_to(int (*printer)(va_list), va_list components, int *total)
{
	int count;

	count = printer(components);
	if (count >= 0)
		*total += count;
	return (count);
}

int _printf(const char *format, ...)
{
	int (**subprinters)(va_list);
	va_list components;
	int total = 0;
	unsigned int i = 0;
	int spr = 0;

	if (format == NULL)
		return (-1);
	subprinters = get_subprinters();
	va_start(components, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			if (format[i + 1] == '%')
				spr = print_single_char('%', &total);
			else if ((unsigned char)format[i + 1] < 128
				&& subprinters[(unsigned char)format[i + 1]])
				spr = delegate_to(
					subprinters[(unsigned char)format[i + 1]],
					components, &total);
			else
			{
				spr = print_single_char(format[i], &total);
				if (spr >= 0)
					spr = print_single_char(format[i + 1], &total);
			}
			i += 2;
		}
		else
		{
			spr = print_single_char(format[i], &total);
			i++;
		}
		if (spr < 0)
		{
			va_end(components);
			return (-1);
		}
	}
	va_end(components);
	return (total);
}
