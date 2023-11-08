#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

int _printf(const char *format, ...);
int _strlen(const char *str);
int write_error(void);
int write_percent(void);
int write_int(int n);
int write_str(char *str);
int write_char(char c);

#endif /*_MAIN_H_*/
