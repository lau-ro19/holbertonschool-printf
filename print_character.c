#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int print_character(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	return ((write(1, &c, 1) < 0) ? -1 : 1);
}
