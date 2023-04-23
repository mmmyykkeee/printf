#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

		va_start(args, format);

	while (format && format[i])
	{
	if (format[i] == '%')
	{
		i++;

		switch (format[i])
	{
		case 'c':
			count += write(1, &(va_arg(args, int)), 1);
		break;
		case 's':
			count += write(1, &(va_arg(args, int)), 1);
		break;
		case '%':
			count += write(1, "%", 1);
		break;
		default:
			count += write(1, &format[i - 1], 1);
			count += write(1, &format[i], 1);
		}
	}
	else
	{
		count += write(1, &format[i], 1);
	}

	i++;
	}

		va_end(args);

	return (count);
}

/**
 * _strlen - finds the length of a string
 * @s: string to find length of
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s && *s++)
	len++;

	return (len);
}

