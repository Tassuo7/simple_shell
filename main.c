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
	char  *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t byte_read;
	pid_t pid;
	char *argv[] = {NULL, NULL};
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_prompt("$ ");
		byte_read = getline(&buffer, &buffer_size, stdin);
		(void)av;
		if (byte_read == -1)
		{ 
			free(buffer);
			break;
		}
		if(buffer[byte_read-1] == '\n')
			buffer[byte_read-1] = '\0';
		if (_strcmp(av[0], "exit") == 0)
			exit_shell();
		if (_strcmp(buffer, "env") == 0)
			get_env(env);
		pid = fork();
		if (pid == -1)
		{
			free(buffer);
			perror("fork");
			exit(1);
		}
		else if(pid == 0)
		{ 
			argv[0] = buffer;
			execve(argv[0], argv, NULL);
			free(buffer);
			perror(buffer);
			exit(1);
		}
		else
		{
			if(waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				free(buffer);
				exit(1);
			}
		}
	}
	return (0);
}
