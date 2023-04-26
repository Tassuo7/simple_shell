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
		if (_strcmp(buffer, "exit\n") == 0)
			exit_shell();
		if (_strcmp(buffer, "env\n") == 0)
		{
			get_env(ev);
		}
	}
	return (0);
}
