#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int print_string(va_list args)
{
	const char *str;
	int i = 0;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		if (write(1, &str[i], 1) < 0)
			return (-1);
		i++;
	}
	return (i);
}
