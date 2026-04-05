#include "main.h"

/**
 * get_subprinter - logic to select the right function
 * @s: specifier character
 * Return: pointer to function
 */
int (*get_subprinter(char s))(va_list)
{
	if (s == 'c')
		return (print_character);
	if (s == 's')
		return (print_string);
	if (s == 'd' || s == 'i')
		return (print_decimal);
	return (NULL);
}