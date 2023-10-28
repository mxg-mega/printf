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
	int count = 0;
  va_list args;
  va_start(args, format);

  while (*format != '\0') {
    if (*format == '%') {
      switch (*++format) {
        case 'c':
          count += putchar(va_arg(args, char));
          break;
        case 's':
          count += fputs(va_arg(args, char *), stdout);
          break;
        case '%':
          count += putchar('%');
          break;
        default:
          // Ignore unknown format specifiers.
          break;
      }
    } else {
      count += putchar(*format);
    }
    format++;
  }

  va_end(args);
  return count;
	}

	va_end(args);

	return (n);	
}

