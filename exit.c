#include "main.h"
/**
 * exit_shell - A function terminates the calling process immediately
 *@V : value of the normal exit
 * Return: nothing
 */
void exit_shell(int V)
{
	_puts("exit");
	exit(V);
}
