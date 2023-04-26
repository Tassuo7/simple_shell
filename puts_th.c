#include "main.h"
/**
 * execute_cmd - A function execute the user command
 * @av: pointer string
 * @ag: array
 * Return: nothing
 */

void execute_cmd(char **av)
{
        char *buffer = NULL;
        char *buffer_c = NULL;

        if (av)
        {
                buffer = av[0];
                buffer_c = _path(buffer);
                if (execve(buffer_c, av, NULL) == -1)
                        perror("./hsh ");
        }
}
