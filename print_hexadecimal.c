#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int print_hexadecimal_lowercase(va_list args)
{
	unsigned int source;
	char buffer[CONVERT_MAX_BUFFER];
	char *converted;
	int length;

	source = va_arg(args, unsigned int);
	converted = change_integer_base(source, "0123456789abcdef",
					buffer, CONVERT_MAX_BUFFER);
	if (converted == CONVERT_ERROR)
		return (-1);
	length = (buffer + CONVERT_MAX_BUFFER) - converted;
	return ((int)write(1, converted, length));
}

int print_hexadecimal_uppercase(va_list args)
{
	unsigned int source;
	char buffer[CONVERT_MAX_BUFFER];
	char *converted;
	int length;

	source = va_arg(args, unsigned int);
	converted = change_integer_base(source, "0123456789ABCDEF",
					buffer, CONVERT_MAX_BUFFER);
	if (converted == CONVERT_ERROR)
		return (-1);
	length = (buffer + CONVERT_MAX_BUFFER) - converted;
	return ((int)write(1, converted, length));
}
