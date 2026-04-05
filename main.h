#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h> /* Requis pour size_t  */

/* --- Constantes et Macros --- */
#define CONVERT_MAX_BUFFER 65 
#define CONVERT_ERROR NULL 

/* --- Orchestrateur principal --- */
int _printf(const char *format, ...); [cite: 1]

/* --- Prototypes des fonctions de conversion (Unit functions) --- */
int print_character(va_list args); [cite: 1]
int print_string(va_list args); [cite: 1]
int print_decimal(va_list args); [cite: 1]
int print_uint(va_list args); [cite: 1]
int print_binary(va_list args); [cite: 1]
int print_octal(va_list args); [cite: 1]
int print_hexadecimal_lowercase(va_list args); [cite: 1]
int print_hexadecimal_uppercase(va_list args); [cite: 1]

/* --- Fonctions Helpers (Utilitaires) --- */
int _putchar(char c);

/**
 * change_integer_base - Convertit un décimal en chaîne selon une base donnée.
 * 
 */
char *change_integer_base(unsigned int n, char *charset,
						char *buffer, size_t buffer_size); [cite: 1]

#endif