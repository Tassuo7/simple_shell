#include "main.h"
/**
 * main - shell project
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: environement
 * Return: Always 0.
 */
int main(int argc, char **argv, char **env)
{
	if (argc == 1)
	{
		shell_prompt(argv, env);
	}
	return (0);
}
