#include "tools.h"

/**
 * is_buffer_valid - check if buffer is not empty.
 *
 * @buffer: buffer (string).
 *
 * Return: 0 if success otherwise -1.
 */
int is_buffer_valid(char *buffer)
{
	int i = 0;

	if (buffer[0] == '\n' || buffer[0] == '#')
		return (-1);
	while (buffer[i]) /**/
	{
		if (buffer[i] != 32 && buffer[i] != 9 && buffer[i] != '\n')
		{
			if (buffer[i] == '#')
				return (-1);
			return (0);
		}
		i++;
	}
	return (-1);
}
