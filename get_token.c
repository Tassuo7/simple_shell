#include "main.h"
/**
 * tokenize - return the command line after split it to argv
 * @line: the command line taken from the user
 * Return: pointer to string to cmd line
 */

char **tokenize(char *line)
{
        char *token, **argv, *line_cp = NULL, *delim = " \n";
        int token_num = 0, i;

        line_cp = malloc(sizeof(char) * (_strlen(line) + 1));
        if (line_cp == NULL)
                return (NULL);
        _strcpy(line_cp, line);
        token = strtok(line_cp, delim);
        while (token != NULL)
        {
                token_num++;
                token = strtok(NULL, delim);

        }
        token_num++;
        argv = malloc(sizeof(char *) * token_num);
        _strcpy(line_cp, line);
        token = strtok(line_cp, delim);
        for (i = 0; token != NULL; i++)
        {
                argv[i] = malloc(sizeof(char) * _strlen(token) + 1);
                if (argv == NULL)
                {
                        free(line_cp);
                        free(argv);
                        return (NULL);
                }
                _strcpy(argv[i], token);
                token = strtok(NULL, delim);
        }
        argv[i] = NULL;
        free(line_cp);
        return (argv);

}
