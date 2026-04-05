#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

int _printf(const char *format, ...);

int print_character(va_list args);
int print_string(va_list args);
int print_decimal(va_list args);
int print_uint(va_list args);
int print_binary(va_list args);
int print_octal(va_list args);
int print_hexadecimal_lowercase(va_list args);
int print_hexadecimal_uppercase(va_list args);

int print_single_char(char c, int *total);
int delegate_to(int (*printer)(va_list), va_list components, int *total);
int recursive_int(unsigned int n, int *count);

#define CONVERT_MAX_BUFFER 65
#define CONVERT_ERROR NULL
char *change_integer_base(unsigned int n, char *charset,
                          char *buffer, size_t buffer_size);

#endif
