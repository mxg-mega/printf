#include "main.h"

/**
 * _strlen - Calculate the length of a string.
 * @str: The input string.
 * Return: The length of the string.
 */
int _strlen(const char *str)
{
	int len = 0;
	while (str && str[len])
	{
		len++;
	}
	return (len);
}
