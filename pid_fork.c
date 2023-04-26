#include "main.h"
/**
 * pid_fork - A function creat process child
 * @buffer: a string input
 */
void pid_fork(char *buffer)
{
        char *argv[] = {NULL, NULL};
        pid_t pid;
        int status;

        argv[0] = buffer;
        pid = fork();
        if (pid == -1)
        {
                free(buffer);
                perror("ERROR");
                exit(1);
        }
        else if (pid == 0)
        {
                if (execve(argv[0], argv, NULL) == -1)
                        perror("hsh/");
                free(buffer);
                exit(0);
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
