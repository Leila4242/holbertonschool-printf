#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct format - structure for format specifiers
 * @specifier: the format specifier character
 * @func: pointer to the corresponding print function
 */
typedef struct format
{
	char specifier;
	int (*func)(va_list);
} format_t;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_number(long n);
int (*get_print_func(char format))(va_list);

#endif
