#include "main.h"

/**
 * write_char - Write a character to stdout.
 * @c: The character to write.
 * Return: Number of characters written (always 1).
 */
int write_char(char c)
{
	return write(1, &c, 1);
}

/**
 * write_str - Write a string to stdout.
 * @str: The string to write.
 * Return: Number of characters written.
 */
int write_str(char *str)
{
	if (!str)
		str = "(null)";
	return write(1, str, _strlen(str));
}

/**
 * write_int - Write an integer to stdout.
 * @n: The integer to write.
 * Return: Number of characters written.
 */
int write_int(int n)
{
	char buffer[12];
	int length = 0;

	if (n < 0)
	{
		n *= -1;
		write_char('-');
		length++;
	}

	while (n)
	{
		buffer[length++] = (n % 10) + '0';
		n /= 10;
	}

	if (length == 0)
		buffer[length++] = '0';

	while (length--)
		write_char(buffer[length]);

	return length;
}

/**
 * write_percent - Write a percent sign to stdout.
 * Return: Number of characters written (always 1).
 */
int write_percent()
{
	return write(1, "%", 1);
}

/**
 * write_error - Write an error message to stdout.
 * Return: Number of characters written.
 */
int write_error()
{
	return write(1, "Error: Unexpected format specifier.", 33);
}

