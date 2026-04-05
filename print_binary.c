#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int print_binary(va_list components)
{
	unsigned int source;
	char buffer[CONVERT_MAX_BUFFER];
	char *converted;
	int length;

	source = va_arg(components, unsigned int);
	converted = change_integer_base(source, "01",
					buffer, CONVERT_MAX_BUFFER);
	if (converted == CONVERT_ERROR)
		return (-1);
	length = (buffer + CONVERT_MAX_BUFFER) - converted;
	return ((int)write(1, converted, length));
}
