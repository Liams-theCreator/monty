#ifndef __tools__
#define __tools__
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int _putchar(char c, int fd);
int _puts(char *str, int fd);
int _getline(char **buffer, int *len, int file);
#endif
