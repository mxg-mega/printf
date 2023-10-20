#include "main.h"

/**
 * _printf - prints formatted string.
 * @format: pointer to the format string.
 * @...: variable number of arguments.
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list v_x;
	int n = 0;  /* Number of characters printed */
	int int_arg;
	char *str;

	va_start(v_x, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++; /* Move to the format specifier character */
			switch (*format)
			{
				case 'c':
					n += write_char(va_arg(v_x, int));
					break;
				case 's':
					str = va_arg(v_x, char *);
					n += write_str(str);
					break;
				case 'd':
				case 'i':
					int_arg = va_arg(v_x, int);
					n += write_int(int_arg);
					break;
				case '%':
					n += write_percent();
					break;
				default:
					n += write_error();
					break;
			}
		}
		else
		{
			n += write_char(*format);
		}
		format++;
	}

	va_end(v_x);

	return (n);
}

