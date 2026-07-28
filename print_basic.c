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
