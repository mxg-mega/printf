#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - prints formatted string, doesn't; handle the flag chara-
 * cters, have to reproduce the buffer handling of the C library printf
 * function, have to handle precision, length modifiers and field width.
 * @format: pointer to the string provided to `_printf`.
 * @...: variable number of arguments.
 * Return: the number of characters printed(excluding the null
 * terminator used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list v_x;
	int i = 0;
	int n = 0; /* number of characters printed */
	char c;
	char *str;

	va_start(v_x, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(v_x, int);
				write(1, &c, 1);
			}
			else if (format[i] == 's')
			{
				str = va_arg(v_x, char *);
				if (str)
				{
				write(1, str, strlen(str));
				}
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
			}
			else
			{
				perror("Error: Unexpected format specifier.");
				exit(98);
			}
		}
		else
		{
			write(1, &format[i], 1);
		}
		n++;
		i++;
	}
	va_end(v_x);
	return (n);
}
