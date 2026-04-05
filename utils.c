#include <stddef.h>
#include "main.h"

/**
 * change_integer_base - converts an unsigned int into a string based on charset
 * @n: the integer to convert
 * @charset: the symbols for the new base (ex: "01234567")
 * @buffer: array to store the result
 * @buffer_size: size of the buffer
 * Return: pointer to the start of the converted string in the buffer
 */
char *change_integer_base(unsigned int n, char *charset,
						char *buffer, size_t buffer_size)
{
	char *digit_writer;
	unsigned int base = 0;

	if (!charset || buffer_size > CONVERT_MAX_BUFFER)
		return (NULL);

	/* Calcul de la base à partir de la longueur du charset */
	while (charset[base])
		base++;

	if (base < 2)
		return (NULL);

	/* On commence à la fin du buffer */
	digit_writer = buffer + buffer_size - 1;
	*digit_writer = '\0';

	/* Conversion progressive */
	do {
		*(--digit_writer) = charset[n % base];
		n = n / base;
	} while (n);

	return (digit_writer);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1, on error -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}