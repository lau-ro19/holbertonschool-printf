#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int (*get_subprinter(char s))(va_list);

/* Helpers */
int _putchar(char c);
int print_number(long n);

/* Specifiers */
int print_character(va_list args);
int print_string(va_list args);
int print_decimal(va_list args);

#endif