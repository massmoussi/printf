#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int _printf(const char *format, ...);
int (*get_print_func(const char c))(va_list);
int print_int_recursive(unsigned int num);
int print_int(va_list);

#endif /* MAIN_H */
