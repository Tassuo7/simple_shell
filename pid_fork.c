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
	int s, ex_s;
	(void)ex_s;

	pid = fork();
	argv[0] = buffer;
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("hsh");
		exit(0);
	}
	else
	{
		waitpid(pid, &s, 0);
		if (WIFEXITED(s))
		{
			ex_s = WEXITSTATUS(s);
			_putchar(s);
		}
	}
}
