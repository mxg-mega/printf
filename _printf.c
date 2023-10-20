#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints formatted string.
 * @format: pointer to the format string.
 * @...: variable number of arguments.
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list v_x;
	int i = 0;
	int n = 0;  /* Number of characters printed */
	char c;
	char *str;

	if (format != NULL)
	{
		return (0);
	}
	va_start(v_x, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(v_x, int);
				write(1, &c, 1);  /* Send character to stdout */
			}
			else if (format[i] == 's')
			{
				str = va_arg(v_x, char *);
				if (str)
				{
					write(1, str, _strlen(str));  /* Send string to stdout */
				}
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);  /* Send '%' to stdout */
			}
			else
			{
				write(1, "Error: Unexpected format specifier.", 33);
				exit(98);
			}
		}
		else
		{
			write(1, &format[i], 1);  /* Send character to stdout */
		}
		n++;
		i++;
	}

	va_end(v_x);

	return (n);
}

/**
 * _strlen - Calculate the length of a string.
 * @str: The input string.
 * Return: The length of the string.
 */
int _strlen(const char *str)
{
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

