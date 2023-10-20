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
	va_list v_x;
	int n = 0, u, ul; /* Number of characters printed */
	char *str, str2[20];

	va_start(v_x, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(v_x, int);
				if (c)
				{
					write(1, &c, 1); /* Send character to stdout */
					n++;
				}
				else
				{
					c = ' ';
					write(1, &c, 1);
					n++;
				}
			}
			else if (*format == 's')
			{
				str = va_arg(v_x, char *);
				if (str)
				{
					write(1, str, _strlen(str)); /* Send string to stdout */
					n += _strlen(str);
				}
				else
				{
					str = "(nil)";
					write(1, str, _strlen(str));
					n +=_strlen(str);
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1); /* Send '%' to stdout */
				n++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				u = va_arg(v_x, int);
				ul = sprintf(str2, "%d", u);
				write(1, str2, ul);
				n += ul;
			}
			else
			{
				write(1, "Error: Unexpected format specifier.", 33);
				exit(98);
			}
		}
		else
		{
			write(1, format, 1); /* Send character to stdout */
			n++;
		}
		format++;
	}

	va_end(v_x);

	return (n);
}

