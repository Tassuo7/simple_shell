#include "main.h"
/**
 * main - shell project
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: environement
 * Return: Always 0.
 */
int main(__attribute__((unused))int argc, char **av, char **env)
{
	size_t buffer_size = 0;
	char  *buffer = NULL;
	ssize_t byte_read;
	pid_t pid;
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_prompt("$ ");
		byte_read = getline(&buffer, &buffer_size, stdin);
		if (byte_read == -1)
			break;
		if (_strcmp(buffer, "exit\n") == 0)
			exit_shell();
		if (_strcmp(buffer, "env\n") == 0)
		{
			get_env(env);
		}
		buffer[byte_read - 1] = '\0';
		av[0] = buffer;
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			if (execve(av[0], av, NULL) == -1)
				perror(".hsh/");
			exit(0);
		}
		else
			wait(&status);

	}
	free(buffer);
	return (0);
}
