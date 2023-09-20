#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

int c_handler(va_list a);
int s_handler(va_list a);
int i_handler(va_list a);
int d_handler(va_list a);
int b_handler(va_list a);
int handler_fspecifier(char c, int *cnt, va_list a);

/**
 * c_handler - handles %c specifier
 * @format: original string
 * @index: index in original string
 * @a: va_list argument
 * Return: count
 */
int c_handler(va_list a)
{
	char s;

	s = va_arg(a, int);
	if (!s)
		return (0);
	_putchar(s);
	return (1);

}

/**
 * s_handler - handles %s specifier
 * @format: original string
 * @index: index in original string
 * @a: va_list argument
 * Return: count
 */
int s_handler(va_list a)
{
	int len, i = 0;
	char *s;

	s = va_arg(a, char *);
	len = slen(s);
	if (s == NULL || *(s + i) == '\0')
		return (0);
	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}

	return (len);
}

/**
 * i_handler - handles %i & %d specifier
 * @a : variadic argument
 * Return: count
 */
int i_handler(va_list a)
{
	int i, digit;
	int count = 0;
	int num = 1;

	i = va_arg(a, int);
	if (i < 0)
	{
		_putchar('-');
		i *= -1;
		count++;
	}
	if (i < 10)
	{
		_putchar(i + '0');
		count++;
	}

	while ((i / num) >= 10)
		num *= 10;
	
	while (i > 10)
	{
		digit = (i / num);
		i = i - (digit * num);
		num /= 10;
		_putchar(digit + '0');
		count++;
	}
	_putchar(i + '0');

	return (count);
}


/**
 * b_handler - handles %b binary specifier
 * @a : variadic argument
 * Return: count
 */
int b_handler(va_list a)
{
	unsigned int d;
	int i = 0, num;
	int count = 0;
	int *arr;

	arr = malloc(sizeof(int) * 32);
	d = va_arg(a, int);
	if (d == 0)
	{
		_putchar(d + '0');
		return (count);
	}
	while (d > 0)
	{
		arr[i] = d % 2;
		i++;
		d /= 2;
	}
	num = i - 1;
	for (i = num; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
		count++;
	}
	free(arr);
	return (count);
}
 
/**
 * handler_fspecifier - handle format specifiers
 * @format : original format string
 * @c : format character
 * @index : index in original string
 * @cnt : pointer to count of characters printed to std ouput
 * @a : va_list argument
 * Return: count of strings printed to std output 
 */
int handler_fspecifier(char c, int *cnt, va_list a)
{
	const int hc = 5;
	int i, count;

	handler_t types[] = {
		{'c', c_handler},
		{'s', s_handler},
		{'d', i_handler},
		{'i', i_handler},
		{'b', b_handler}
	};

	i = 0;
	while (i < hc)
	{
		if (types[i].symbol == c)
		{
			count = types[i].handle(a);
			break;
		}

		i++;
	}
	if (i == hc)
		return (-2);

	count += (*cnt);
	return (count);
}

