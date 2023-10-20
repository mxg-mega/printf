#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int _strlen(const char *str);
int write_error();
int write_percent();
int write_int(int n);
int write_str(char *str);
int write_char(char c);

#endif
