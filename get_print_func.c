#include "main.h"

/**
 * get_print_func - selects the right function for the specifier
 * @s: specifier character
 * Return: pointer to function, or NULL
 */
int (*get_print_func(char s))(va_list)
{
	op_t ops[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op)
	{
		if (s == ops[i].op[0])
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
