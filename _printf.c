#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

void resize(unsigned int increase, int *bufflen, char **buffer)
{
	unsigned int newSize = *bufflen * increase + 1;
	*buffer = realloc(*buffer, newSize);
	if (!*buffer)
	{
		perror("Memory allocation failed");
		exit(1);
	}
}
/**
 * handle_format_specifier - Handle format specifier character.
 * @format: format character ('c', 's', or '%').
 * @v_x: va_list containing the variable arguments.
 * @buffer: Pointer to the buffer for output.
 * @bufflen: Current length of the buffer.
 */
void handle_format_specifier(char format, va_list v_x, char **buffer, int *bufflen)
{
	char c;
	char *str;

	switch (format)
	{
		case 'c':
			c = va_arg(v_x, int);
			if (*bufflen + 1 >= **buffer)
			{
				resize(2, bufflen, buffer);
			}
			(*buffer)[*bufflen] = c;
			(*bufflen)++;
			break;
		case 's':
			str = va_arg(v_x, char *);
			if (str)
			{
				int strLen = strlen(str);

				if (*bufflen + strLen >= *bufflen)
				{
					resize(strLen, bufflen, buffer);
				}
				strcpy(*buffer + *bufflen, str);
				*bufflen += strLen;
			}
			break;
		case '%':
			if (*bufflen + 1 >= *bufflen)
			{
				resize(2, bufflen, buffer);
			}
			(*buffer)[*bufflen] = '%';
			(*bufflen)++;
			break;
		default:
			write(1, "Error: Unexpected format specifier.", 33);
		exit(98);
	}
}

/**
 * _printf - custom implementation of `printf`
 * @format: pointer to the string provided to the function.
 * @...: variable number of arguments
 * <for now> , only handles '%c', '%s' n '%%'
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list v_x;
	int i = 0;
	int n = 0;       /* Number of characters printed */
	char *buffer = NULL;  /* Initialize the buffer to NULL */
	int bufflen = 0;      /* Length of the buffer */

	va_start(v_x, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			handle_format_specifier(format[i], v_x, &buffer, &bufflen);
		}
		else
		{
			if (bufflen + 1 >= i)
			{
				int newSize;

				newSize = bufflen * 2 + 1;
				buffer = realloc(buffer, newSize);
				if (!buffer)
				{
					perror("Memory allocation failed");
					exit(1);
				}
			}
			buffer[bufflen] = format[i];
			bufflen++;
		}
		i++;
	}
	va_end(v_x);
	if (buffer)
	{
		buffer[bufflen] = '\0';
		write(1, buffer, bufflen);
		free(buffer);
	}
	return (n);
}
