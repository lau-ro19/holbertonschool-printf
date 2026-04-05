#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* Taille du buffer pour les conversions (binaire, octal, etc.) */
#define CONVERT_MAX_BUFFER 65

/* Orchestrateur principal */
int _printf(const char *format, ...);

/* Prototypes des fonctions de conversion */
int print_character(va_list args);
int print_string(va_list args);
int print_decimal(va_list args);

/* Helpers */
int _putchar(char c);

#endif