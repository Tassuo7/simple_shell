#include "main.h"
/**
 * main - repeatedly prompts user and executes user's cmds if applicable
 * @ac: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */

int main(__attribute__((unused)) int ac, char **argv, char **env)
{
        char *buffer = NULL, **tokens;
        size_t buffer_size= 0;
        ssize_t byte_read;
        pid_t pid;
        int status = 0;

        while (1)
        {
                if (isatty(STDIN_FILENO))
                        _puts("$ ");
                byte_read = getline(&buffer, &buffer_size, stdin);
                if (byte_read == -1)
                        break;
                tokens = tokenize(buffer);
                if (_strcmp(tokens[0], "exit\n") == 0)
                {
                        status = __exit(tokens);
                        break;
                }
                if (_strcmp(buffer, "env\n") == 0)
                {
                        get_env(env);
                        continue;
                }
                (void)argv;
                pid = fork();
                if (pid == 0)
                {
                        execute_cmd(tokenize(buffer));
                        exit(0);
                }
                else if (pid > 0)
                        wait(NULL);
                else
                {
                        perror("fork");
                        exit(1);
                }
        }
        free(buffer);
        return (status);
}
