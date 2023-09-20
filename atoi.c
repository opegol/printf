#include "main.h"

/**
 * _atoi - converts a string to an integer.
 * @s : string to be converted
 * Return: integer derived from string
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int i = 0;

	do {
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
			i = (i * 10) + (*s - '0');
		else if (i > 0)
			break;
	} while (*s++);
	return (i * sign);
}
