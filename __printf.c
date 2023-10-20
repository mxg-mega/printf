#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

struct FormatArg {
    char fs;
    union {
        char charValue;
        int intValue;
        float floatValue;
        char *stringValue;
    } argument;
} fmt;

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
	int bufflen = 0;
	char c;
	char *str;
	char *buffer;

	va_start(v_x,  format);
	fmt formatArgs[] = {
		{'c', .argument.charValue = va_arg(v_x, char)},
		{'s', .argument.stringValue = va_arg(v_x, char*)},
		{'%',.argument.charValue = va_arg(v_x, char)},
	};

	va_end(v_x);
	while (format && format[i] && buffer)
	{
		if (format[i] == '%')
		{
			int j, str;

			i++;
			for (j = 0; j < sizeof(formatArgs) / sizeof(formatArgs[0]); j++)
			{
				if (format[i] == formatArgs[j].fs)
				{
					switch (format[i])
					{
						case 'c':
							buffer[bufflen] = formatArgs[j].argument.charValue; 
							bufflen++;
							break;
						case 's':
							for (str = 0; formatArgs[j].argument.stringValue[str] != 0; str++)
							{
								buffer[bufflen] = formatArgs[j].argument.stringValue[str];
								bufferlen++;
							}
							bufferlen++;
        	                			break;
						case '%':
							buffer[bufflen] = format[i--];
							bufflen++;
						default:
							// Handle unsupported format specifiers
							perror("Error: undefined Specifier");
							exit(98);
							break;
					}
	    			}
			}
		}
		else
		{
			buffer[bufflen] = format[i];
			bufflen++;
		}
		i++;
	}
	buffer[bufflen++] = '\0';
	write(1, buffer, bufflen); 
	return (n);
}
