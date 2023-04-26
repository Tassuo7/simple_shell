#include "main.h"
/**
 * shell_prompt - A function display prompt and read command
 * @ar: array of strings ends
 * @ev: array is terminated by a null pointer
 * Return: nothing
 */
void shell_prompt(char **av, char **ev)
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
		{
			exit(EXIT_FAILURE);
		}
		if (_strcmp(buffer, "exit\n") == 0)
			exit_shell();
		if (_strcmp(buffer, "env\n") == 0)
		{
			get_env(ev);
			continue;
		}
		buffer[byte_read - 1] = '\0';
		av[0] = buffer;
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			exit(1);
		}
		if (pid == 0)
		{
			if (execve(av[0], av, NULL) == -1)
				perror(".hsh/");
			else
				execve(av[0], av, NULL);
			exit(0);
		}
		else
			wait(&status);
	}
	free(buffer);
}

