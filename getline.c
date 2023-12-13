#include "tools.h"

int _getline(char **buffer, int *len, int file)
{
	ssize_t bytes_read = 0, i = 0, j = 0;
	char local_buffer[1024];	 

	while ((bytes_read = read(file, local_buffer, sizeof(local_buffer) - 1)) > 0)
	{
		for (i = 0; i < bytes_read; i++)
		{
			if (local_buffer[i] == '\n')
			{
				*buffer = malloc(i + 2);
				if (!(*buffer))
				{
					/*print error*/
					return (-1);
				}
				for (j = 0; j < i + 1; j++)
					(*buffer)[j] = local_buffer[j];
				(*buffer)[j] = '\0';
				*len = (int)j;
				lseek(file, i - (bytes_read - 1), SEEK_CUR);
				return (i);
			}
		}
	}
	return (0);
}
