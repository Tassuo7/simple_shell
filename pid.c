#include "main.h"
/**
 * pid_fork - A function creat a process child
 * @buffer: string input
 * Return: nothing
 */
void pid_fork(char *buffer)
{
	char *argv[] = {NULL, NULL};
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		free(buffer);
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		argv[0] = buffer;
		execve(argv[0], argv, NULL);
		free(buffer);
		perror(buffer);
		exit(1);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			free(buffer);
			exit(1);
		}
	}
}
