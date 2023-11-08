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
	int n = 0;
	int len = 0;

	if (format == NULL)
	{
		return;
	}
	va_start(args, format);
	for (p = format; p[n] != '\0'; n++)
	{
		if (p[n] == '%')
		{
			n++;
			switch (p[n])
			{
				case 'c':
				{
					char c = va_arg(args, int);

					putchar(c);
					len++;
					break;
				}
				case 's':
				{
					char *str;

					str = va_arg(args, char *);
					if (str == NULL)
						return;

					write_str(str);
					len += strlen(str);
					break;
				}
				case '%':
				{
					putchar('%');
					len++;
					break;
				}
				default:
				{
					putchar(p[n - 1]);
					putchar(p[n]);
					len += 2;
					break;
				}
			}
		}
		else
		{
			putchar(p[n]);
			len++;
		}
	}
	va_end(args);
	return (len);
}

