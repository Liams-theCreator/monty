#include "tools.h"

/**
 * _getline - Read from a file descriptor.
 *
 * @buffer: buffer will hold data.
 * @len: length of the data.
 * @file: file descriptor.
 * @line: will hold the file line.
 * Return: number of bytes reads on success and non zero in failure.
 *
 */

int _getline(char **buffer, int *len, int file, unsigned int *line)
{
	ssize_t bytes_read = 0, i = 0, j = 0;
	char local_buffer[1024];

	while ((bytes_read = read(file, local_buffer, sizeof(local_buffer) - 1)) > 0)
	{
		for (i = 0; i < bytes_read; i++)
		{
			if (local_buffer[i] == '\n')
			{
				if ((*buffer) != NULL)
					free(*buffer);
				*buffer = malloc(i + 2);
				if (!(*buffer))
				{
					_puts("Error: malloc failed\n", 2);
					return (1);
				}
				for (j = 0; j < i + 1; j++)
					(*buffer)[j] = local_buffer[j];
				(*buffer)[j] = '\0';
				*len = (int)j, *line = *line + 1;
				lseek(file, i - (bytes_read - 1), SEEK_CUR);
				return (i);
			}
		}
		if ((*buffer))
			free(*buffer);
		*buffer = malloc(bytes_read + 1);
		if (!(*buffer))
		{
			_puts("Error: malloc failed\n", 2);
			return (1);
		}
		for (j = 0; j < bytes_read; j++)
			(*buffer)[j] = local_buffer[j];
		(*buffer)[j] = '\0';
		*len = (int)j, *line = *line + 1;
		return (j);
	}
	return ((bytes_read) == 0 ? -1 : 0);
}
