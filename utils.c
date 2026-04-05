#include "main.h"
#include <stddef.h>

char *change_integer_base(unsigned int n, char *charset,
                          char *buffer, size_t buffer_size)
{
	char *writer;
	unsigned int base = 0;
	char seen[256] = {0};

	if (!charset || buffer_size > CONVERT_MAX_BUFFER)
		return (CONVERT_ERROR);
	while (charset[base])
	{
		if (seen[(unsigned char)charset[base]])
			return (CONVERT_ERROR);
		seen[(unsigned char)charset[base]] = 1;
		base++;
	}
	if (base < 2)
		return (CONVERT_ERROR);
	writer = buffer + buffer_size;
	*writer = '\0';
	do {
		*(--writer) = charset[n % base];
		n /= base;
	} while (n);
	return (writer);
}
