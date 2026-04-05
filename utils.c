#include "main.h"

/**
 * _putchar - writes char
 * @c: char
 * Return: 1 or -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}