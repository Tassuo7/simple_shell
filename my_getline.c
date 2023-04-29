#include"main.h"
/**
 * my_getline - is a function used to read the command
 * @line : The pointer to read comand
 * @n : the size of the command
 * Return: the command or -1 if fails
 */

ssize_t my_getline(char **line, size_t *n)
{
	int ch;
	size_t i = 0;

	if (*line == NULL || *n == 0)
	{
		*n = 256;
		*line = malloc(*n);
	}
	if (*line == NULL)
		return (-1);
	while (read(STDIN_FILENO, &ch, 1) != '\0')
	{
		(*line)[i++] = ch;
		if (ch == '\n')
			break;
	}
	free(*line);
	return (ch);
}
