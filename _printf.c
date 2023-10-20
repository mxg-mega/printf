#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
	int n = 0;
	int i, len;
    int output_size = 0;
    char *output = NULL, *str, c;
    
    va_list v_x;
    va_start(v_x, format);

    
    for (i = 0; format && format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                c = va_arg(v_x, int);
                output = (char *)realloc(output, output_size + 2);
                if (output == NULL) {
                    perror("Error: Memory allocation failed.");
                    exit(1);
                }
                output[output_size] = c;
                output_size++;
            }
            else if (format[i] == 's')
            {
                str = va_arg(v_x, char *);
                if (str)
                {
                    len = strlen(str);
                    output = (char *)realloc(output, output_size + len + 1);
                    if (output == NULL) {
                        perror("Error: Memory allocation failed.");
                        exit(1);
                    }
                    strcpy(output + output_size, str);
                    output_size += len;
                }
            }
            else if (format[i] == '%')
            {
                output = (char *)realloc(output, output_size + 2);
                if (output == NULL) {
                    perror("Error: Memory allocation failed.");
                    exit(1);
                }
                output[output_size] = '%';
                output_size++;
            }
            else
            {
                perror("Error: Unexpected format specifier.");
                exit(98);
            }
        }
        else
        {
            output = (char *)realloc(output, output_size + 2);
            if (output == NULL) {
                perror("Error: Memory allocation failed.");
                exit(1);
            }
            output[output_size] = format[i];
            output_size++;
        }
    }

    va_end(v_x);

    write(1, output, output_size);

    free(output);

    return n;
}
