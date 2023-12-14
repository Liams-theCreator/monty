#ifndef __tools__
#define __tools__
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int _putchar(char c, int fd);
int _puts(char *str, int fd);
int _getline(char **buffer, int *len, int file, unsigned int *line);
int _strlen(char *str);
int _kiki(char *va);
void print_number(int n, int fd);
int is_buffer_valid(char *buffer);

#endif
