#include "monty.h"

#define buffer_size 1024
int main(int ac, char **av)
{
	int fd = 0;
	int read_bytes = 0;
	int len = 0;
	char *buffer = NULL;
	char bu[10];

	if (ac != 2)
	{
		_puts("USAGE: monty file\n", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		_puts("Error: Can't open file ", 2);
		_puts(av[1], 2);
		_putchar('\n', 2);
		exit(EXIT_FAILURE);
	}
	if ((read_bytes = _getline(&buffer, &len, fd)) != -1)
	{
		printf("%s", buffer);
	}
	
	read(fd, bu, 7);
	printf("%s", bu);
	if (read_bytes == -1)
	{
		free(buffer);
		_puts("Error Reading from file hhh", 2);
		exit(1);
	}

	free(buffer);
	close(fd);
	return (0);
}



	// while (bytes_read = read(fd, buffer, buffer_size - 1) > 0)
	// {
	// 	buffer[bytes_read] = '\0';
		
	// }
