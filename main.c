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
        char *cmd, *args[64], *token;
        const char *del;
        int i;

        del = "\n";
        while (1)
        {
                cmd = get_cmd();
                (void)av;

                i = 0;
                token = strtok(cmd, del);
                while (token != NULL)
                {
                        args[i] = token;
                        i++;
                        token = strtok(NULL, del);
                }
                args[i] = NULL;
                if (_strcmp(cmd, "env\n") == 0)
                        get_env(env);
                if (_strcmp(args[0], "exit\n") == 0)
                        exit(0);
                else
                {
                        pid_fork(cmd);
                }
                free(cmd);
        }
        return (0);
}
