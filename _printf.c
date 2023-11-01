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
	int n = 0;  /* Number of characters printed */

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

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

			if (*format == '\0')
			{
				break;
			}

			if (*format == 'c')
			{
				char c = (char)va_arg(args, int);

				write(1, &c, 1);
				n++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (str != NULL)
				{
					int len = 0;

					while (str[len])
						len++;
					write(1, str, len);
					n += len;
				}
				else
				{
					char p = ' ';

					write(1, &p, 1);
					n++;
				}
			}
			else if (*format == '%' || *format == ' ')
			{
				write(1, "%", 1);
				n++;
			}
			else
			{
				char * errorMsg = "\nError: Unexpected format specifier.\n";

				write(1, errorMsg, _strlen(errorMsg));
				return (-1);  /* Return an error code */
			}
		}
		format++;
	}

	va_end(args);
	return (n);
}

