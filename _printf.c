#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - A simple implementation of printf
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
const char *ptr;

va_start(args, format);

for (ptr = format; *ptr != '\0'; ptr++)
{
if (*ptr == '%')
{
ptr++;
switch (*ptr)
{
case 'c':
{
char c = (char)va_arg(args, int);

putchar(c);
count++;
break;
}
case 's':
{
const char *str = va_arg(args, const char *);

for (; *str != '\0'; str++)
{
putchar(*str);
count++;
}
break;
}
case '%':
{
putchar('%');
count++;
break;
}
default:
break;
}
}
else
{
putchar(*ptr);
count++;
}
}

va_end(args);
return (count);
}
