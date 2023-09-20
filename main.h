#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>


/**
 * struct handler - A new struct type defining a handler
 * @symbol: A symbol representing a data type.
 * @print: A function pointer to a function that handles format specifiers
 *         corresponding to symbol.
 */
typedef struct handler
{
	char symbol;
	int (*handle)(va_list a);

} handler_t;

int _putchar(char c);
int _printf(const char *format, ...);
int handler_fspecifier(char c, int *cnt, va_list a);

/* help_funcs */
int slen(char *str);
int cslen(const char *str); /* giving errors of mismatch of char * & const char * */
int _atoi(char *c);
#endif

