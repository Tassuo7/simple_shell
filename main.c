#include "main.h"

int main(int argc, char **argv, char **env)
{
        size_t buffer_size = 0;
        char  *buffer = NULL;
        ssize_t byte_read;
        pid_t pid;
        int status;

        if (argc == 1)
        {
                while (1)
                {
                        /* Print symbol and wait for user input */
                        _prompt("$ ");
                        /* read command input by user */
                        byte_read = getline(&buffer, &buffer_size, stdin);
                        /* Check for errors or end of file condition (Ctrl+D)  */
                        if (byte_read == -1)
                        {
                                _putchar('\n');
                                exit(EXIT_FAILURE);
                        }
                        /* test the input equal to exit or env and execute it */
                        if (_strcmp(buffer, "exit\n") == 0)
                                exit_shell();
                        else if (_strcmp(buffer, "env\n") == 0)
                        {
                                get_env(env);
                        }
                        /* delete the trailing newline character from the input*/
                        buffer[byte_read - 1] = '\0';
                        /* get the command */
                        argv[0] = buffer;
                        /* create a new child process*/
                        pid = fork();
                        if (pid == -1)
                        {
                                perror("Error:");
                                exit(1);
                        }
                        if (pid == 0)
                        {
                                /* use execve to execute the command*/
                                if (execve(argv[0], argv, NULL) == -1)
                                        perror(".hsh/:");
                                exit(0);
                        }
                        else
                                wait(&status);
                }
                free(buffer);
        }
        return (0);
}
