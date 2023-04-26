#include "main.h"
/**
 * exit_shell - A function terminates the calling process immediately
 * @V : value of normal exit or not
 * Return: nothing
 */
void exit_shell(int V)
{
	_puts("exit");
	_exit(V);
}
