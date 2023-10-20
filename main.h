#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
int _printf(const char *format, ...);
void handle_format_specifier(
		char format,
		va_list v_x,
		char **buffer,
		int *bufflen);

#endif
