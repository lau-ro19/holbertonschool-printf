#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

#define CONVERT_MAX_BUFFER 65
#define CONVERT_ERROR NULL

int _printf(const char *format, ...);
int (*get_subprinter(char s))(va_list);

int print_character(va_list args);
int print_string(va_list args);
int print_decimal(va_list args);
int recursive_int(unsigned int n, int *count);

int _putchar(char c);
char *change_integer_base(unsigned int n, char *charset,
						char *buffer, size_t buffer_size);

#endif