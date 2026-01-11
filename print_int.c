#include "main.h"
#include <unistd.h>

/**
 * print_number - helper function to print a number recursively
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_number(long n)
{
	int count = 0;
	char digit;

	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}

	if (n / 10)
		count += print_number(n / 10);

	digit = (n % 10) + '0';
	count += write(1, &digit, 1);

	return (count);
}

/**
 * print_int - prints an integer
 * @args: va_list containing the integer to print
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);

	return (print_number(n));
}
