#include <stdlib.h>

/**
 * slen - get length of string
 * @str : given string
 * Return: length of string
 */
int slen(char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}


/**
 * cslen - get length of const string
 * @str : given string
 * Return: length of string
 */
int cslen(const char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}
