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
	argv[0] = buffer;
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("hsh");
		exit(0);
	}
	else
	{
		wait(&status);
	}
}
