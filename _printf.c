#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf - custom implementation of `printf`
 * @format: pointer to the string provided to the function.
 * @...: variable number of arguments
 * <for now> , only handles '%c', '%s' n '%%'
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	int n = 0, c; /* n: No. of chars printed */
	char *s1;
	va_list a;

	va_start(a, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			n++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(a, int);
				write(1, &c, 1);
				n++;
			}
			else if (*format == 's')
			{
				s1 = va_arg(a, char *);
				write(1, s1, strlen(s1));
				n += strlen(s1);
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				n++;
			}
		}
		format++;
	}
	va_end(a);
	return (n);
}
