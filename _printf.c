#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - prints a character
 * @args: va_list containing the character to print
 *
 * Return: number of characters printed (1)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @args: va_list containing the string to print
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (str[count])
		count++;

	return (write(1, str, count));
}

/**
 * print_percent - prints a percent sign
 * @args: va_list (unused)
 *
 * Return: number of characters printed (1)
 */
int print_percent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}

/**
 * get_print_func - selects the correct function to print
 * @format: format specifier character
 *
 * Return: pointer to the appropriate print function, or NULL
 */
int (*get_print_func(char format))(va_list)
{
	int i = 0;
	format_t formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};

	while (formats[i].specifier)
	{
		if (formats[i].specifier == format)
			return (formats[i].func);
		i++;
	}

	return (NULL);
}

/**
 * _printf - produces output according to a format
 * @format: character string containing format specifiers
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0;
	int (*print_func)(va_list);

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			print_func = get_print_func(format[i + 1]);

			if (print_func != NULL)
			{
				count += print_func(args);
				i += 2;
				continue;
			}
		}

		write(1, &format[i], 1);
		count++;
		i++;
	}

	va_end(args);
	return (count);
}
