#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * @format : a character string which is composed of zero or more directives
 * @... : Variadic arguments
 * Return: the number of characters printed
 *	(excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list a;
	int i, r;
	int count = 0;
	int fmt_len;
	
	if (format == NULL)
		return (-1);

	fmt_len = cslen(format);
	va_start(a, format);

	for (i = 0; i < fmt_len; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else if (*(format + i) == '%' && (*(format + i + 1) == '%'))
		{
			_putchar('%');
			count++;
			i++;
		}

		else if(*(format + i) == '%' && (*(format + i + 1) != '\0' 
					&& *(format + i + 1) != '%'))
		{
			
			r = handler_fspecifier(*(format + i + 1), &count, a);
			if (r == -2)
			{
				_putchar('%');
				continue;
			}
			i++;
		}

	
	}
	va_end(a);

	return (count);

}


						
			

