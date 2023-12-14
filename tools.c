#include "tools.h"

/**
 * _putchar - print character to file descriptor.
 *
 * @c: character.
 * @fd: file descriptor.
 *
 * Return: length.
 */
int _putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}
/**
 * _puts - print string to file descriptor.
 *
 * @str: string.
 * @fd: file descriptor.
 *
 * Return: length.
 */
int _puts(char *str, int fd)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i], fd);
		i++;
	}
	return (i);
}
/**
 * _strlen - count length of a string.
 *
 * @str: string.
 *
 * Return: length.
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

/**
 * _kiki - check if a string is a number.
 *
 * @va: string.
 *
 * Return: 1 if string is a number otherwise -1.
 */
int _kiki(char *va)
{
	int i = 0;

	if (!va)
		return (-1);
	while (va[i])
	{
		if (va[i] < 48 || va[i] > 57)
		{
			if (va[i] == '-' && (va[i + 1] >= 48 && va[i + 1] <= 57))
				return (1);
			return (-1);
		}
		i++;
	}

	return (1);
}
/**
 * print_number - print a number to file descriptor.
 *
 * @n: number.
 * @fd: file descriptor.
 *
 */
void print_number(int n, int fd)
{
	if (n < 0)
	{
		n = -n;
		_putchar('-', fd);

	}
	if (n / 10)
		print_number(n / 10, fd);
	_putchar((n % 10) + 48, fd);
}

