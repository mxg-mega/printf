#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

	va_start(v_x, format);
	while (format && format[i])
	{
		switch (format[i])
		{
			case '%':
				i++;
				switch (format[i])
				{
					case 'c':
						write(1, (char[]){va_arg(v_x, int)}, 1);
						break;
					case 's':
						write(1, va_arg(v_x, char *), strlen(va_arg(v_x, char *));
						break;
					case '%':
						write(1, "%", 1);
						break;
				}
				break;
		default:
			write(1, &format[i], 1);
		}
		n++;
		i++;
	}
	va_end(v_x);
	return (n);
}
