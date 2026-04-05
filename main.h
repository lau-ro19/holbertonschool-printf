#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct op - Struct for printf operators
 * @op: The specifier
 * @f: The function associated
 */
typedef struct op
{
	char *op;
	int (*f)(va_list);
} op_t;

int _printf(const char *format, ...);
int _putchar(char c);


int print_char(va_list args);
int print_str(va_list args);
int print_pct(va_list args);


int print_int(va_list args);
int print_number(long n);

#endif
