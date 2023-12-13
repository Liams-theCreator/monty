#include "monty.h"
#include "tools.h"


int _putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

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

