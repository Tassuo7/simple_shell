#include "main.h"
/**
 * main - shell project
 * @argc: number of arguments
 * @av: array of arguments
 * @env: environement
 * Return: Always 0.
 */
int main(__attribute__((unused))int argc, char **av, char **env)
{
	char  *cmd = NULL;
	size_t buffer_size = 0;
	ssize_t byte_read;
	(void)av;

	while (1)
	{
		if (isatty(0))
		{
			_prompt("$ ");
			fflush(stdout);
		}
		byte_read = getline(&cmd, &buffer_size, stdin);
		if (byte_read == -1)
			break;
		if (cmd == NULL || cmd[0] == ' ' || cmd[0] == '\n')
			continue;
		if (cmd[byte_read - 1] == '\n')
			cmd[byte_read - 1] = '\0';
		if (_strcmp(cmd, "exit\n") == 0)
			break;
		if (_strcmp(cmd, "env\n") == 0)
			get_env(env);
		else
			pid_fork(cmd);
	}
	free(cmd);
	return (0);
}
