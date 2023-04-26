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

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_prompt("$ ");
		byte_read = getline(&cmd, &buffer_size, stdin);
		(void)av;
		if (byte_read == -1)
		{
			free(cmd);
			break;
		}
		if (cmd[byte_read - 1] == '\n')
			cmd[byte_read - 1] = '\0';
		if (_strcmp(cmd, "exit\n") == 0)
			exit_shell();
		if (_strcmp(cmd, "env") == 0)
			get_env(env);
		pid_fork(cmd);
	}
	return (0);
}
