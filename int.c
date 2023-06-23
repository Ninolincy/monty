#include "monty.h"

/**
 * is_int - checks if a string is valid for atoi
 * @str: the string
 *
 * Return: 1 for true, 0 for false
 */

bool is_int(const char *str)
{
	if (str == NULL || *str == '\0')
		return (false);

	if (*str == '+' || *str == '-')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}

	return (true);
}
