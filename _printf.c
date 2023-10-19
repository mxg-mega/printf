#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
    va_list v_x;
    int i = 0;
    int n = 0, len; 
    char *output = NULL; 
    int output_size = 0;
    char c, *str; 

    va_start(v_x, format);
    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                c = va_arg(v_x, int);
                output = (char *)malloc(output_size + 2); 
                if (output == NULL) {
                    perror("Error: Memory allocation failed.");
                    exit(1);
                }
                output[output_size] = c;
                output[output_size + 1] = '\0';
                output_size += 2;
            }
            else if (format[i] == 's')
            {
                str = va_arg(v_x, char *);
                if (str)
                {
                    len = strlen(str);
                    output = (char *)malloc(output_size + len + 1); 
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
                output = (char *)malloc(output_size + 2); 
                if (output == NULL) {
                    perror("Error: Memory allocation failed.");
                    exit(1);
                }
                output[output_size] = '%';
                output[output_size + 1] = '\0';
                output_size += 2;
            }
            else
            {
                perror("Error: Unexpected format specifier.");
                exit(98);
            }
        }
        else
        {
            output = (char *)malloc(output_size + 2); 
            if (output == NULL) {
                perror("Error: Memory allocation failed.");
                exit(1);
            }
            output[output_size] = format[i];
            output[output_size + 1] = '\0';
            output_size += 2;
        }
        i++;
    }
    va_end(v_x);

    
    write(1, output, output_size - 1); 

    
    free(output);

    return n;
}

