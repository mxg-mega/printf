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
	int i = 0;
	int n = 0;  /* Number of characters printed */

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				if (str)
				{
					int len = 0;
					while (str[len] != '\0')
					{
						len++;
					}
					write(1, str, len);
				}
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
			}
			else
			{
				write(1, "Error: Unexpected format specifier.", 33);
				return -1;  /* Return an error code */
			}
		}
		else
		{
			write(1, &format[i], 1);
		}
		n++;
		i++;
	}

	va_end(args);

	return (n);	
}

