#include "main.h"
/**
 * _boucle - a fucntion repeat command
 * @ar: array of string
 * @c: string input
 * Return: nothing
 */
char **_boucle(char **ar, char *c)
{
	int index;

	index = 0;
	ar[index] = strtok(c, " ");
	while (c[index])
	{
		ar[++index] = strtok(NULL, " ");
	}
	ar[index] = NULL;
	return (ar);
}
