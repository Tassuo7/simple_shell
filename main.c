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
	char  *cmd = NULL, *avrg[] = {NULL, NULL};
	size_t buffer_size = 0;
	ssize_t byte_read;
	pid_t pid;
	int status;
	(void)av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_prompt("$ ");
		byte_read = getline(&cmd, &buffer_size, stdin);
		if (byte_read == -1)
			break;
		avrg[0] = cmd;
		if (_strcmp(cmd, "exit\n") == 0)
			break;
		if (_strcmp(cmd, "env\n") == 0)
			get_env(env);
		pid = fork();
		if (pid == -1)
		{
			perror("ERROr");
			exit(1);
		}
		else if (pid == 0)
		{
			if (execve(cmd, avrg, NULL) == -1)
				perror("./hsh");
			exit(0);
		}
		else
			wait(&status);
	}
	free(cmd);
	return (0);
}
