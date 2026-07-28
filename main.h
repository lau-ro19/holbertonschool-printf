#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h> 

int _putchar(char c);
int _printf(const char *format, ...);
int write_text_block(const char *format, int *index);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_digit(va_list args);

#endif /* MAIN_H */