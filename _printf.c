#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - prints formatted string.
 * @format: pointer to the format string.
 * @...: variable number of arguments.
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *p;
	int n = 0;  /* Number of characters printed */

	va_start(args, format);

	for (p = format; *p; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			n++;
			continue;
		}
		switch(*++p)
		{
			case 'c':
			{
				char c = va_arg(args, int);

				putchar(c);
				n++;
				break;
			}
			case's':
			{
				char *str;

				for (str = va_arg(args, char *); *str; str++)
					write(1, str, 1);

				n += strlen(str);
				break;
			}
			case '%':
			{
				write(1, "%", 1);
				n++;
				break;
			}
			default:
			{
				putchar(*p);
				n++;
				break;
			}
		}
	}

	va_end(args);
	return (n);
}

