#include "main.h"
/**
 * *get_cmd - A function print "$ " and get command from use.
 * Return: string command
 */

char *get_cmd()
{
	char *buffer = NULL;
	size_t buffer_size = 0;

	if (isatty(STDIN_FILENO))
		_puts("$ ");
	if (getline(&buffer, &buffer_size, stdin) == -1)
	{
		free(buffer);
		exit(1);
	}
	return (buffer);
}
