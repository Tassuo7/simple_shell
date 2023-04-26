#include "main.h"

/**
 * *_strcpy - Check description
 * Description: it a function that copies the string pointed to by src,
 * @dt: A pointer to destination of string
 * @s: A pointer to source string to copy from
 * Return: pointer to dest
 */
char *_strcpy(char *dt, char *s)
{
        dt = strcpy(dt, s);
        return (dt);

}
/**
 * *_strcat - a function that concatenates two strings
 * @dest: an input string
 * @src: an input string
 * Return: A pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
        int i, len1, len2;

        len1 = strlen(dest);
        len2 = strlen(src);
        for (i = 0; i <= len2; i++)
        {
                dest[len1 + i] = src[i];
        }
        return (dest);
}
# include "main.h"
/**
 * *_path - A function return path
 * @commad: the string unput
 * Return: path
 */
char *_path(char *comamd)
{
        int commad_length, path_length;
        struct stat buff;
        char *pth, *cmd_path, *path_token, *f_t;

        if (stat(comamd, &buff) != 0)
        {
                pth = getenv("PATH");
                if (pth != NULL)
                {
                        cmd_path = _strallocat(pth);
                        commad_length = _strlen(comamd);
                        path_token = strtok(cmd_path, ":");
                        while (path_token != NULL)
                        {
                                path_length = _strlen(path_token);
                                f_t = malloc(commad_length + path_length + 2);
                                if (f_t == NULL)
                                        return (NULL);
                                _strcpy(f_t, path_token);
                                _strcat(f_t, "/");
                                _strcat(f_t, comamd);
                                _strcat(f_t, "\0");
                                if (stat(f_t, &buff) == 0)
                                {
                                        free(cmd_path);
                                        return (f_t);
                                }
                                else
                                {
                                        free(f_t);
                                        path_token = strtok(NULL, ":");
                                }
                        }
                }
                if (stat(comamd, &buff) == 0)
                        return (comamd);
                free(cmd_path);
        }
        return (NULL);
}
/**
 * _strallocat - A function return a pointer
 * @st: string input
 * Return: pointer to string
 */
char *_strallocat(char *st)
{
        char *dup_sr;
        int j, l;

        l = 0, j = 0;
        if (st == NULL)
                return (NULL);
        while (*(st + l))
                l++;
        l++;
        dup_sr = malloc(sizeof(char) * l);
        if (dup_sr == NULL)
                return (NULL);
        while (j < l)
        {
                *(dup_sr + j) = *(st + j);
                j++;
        }
        return (dup_sr);
}
/**
 * __exit - A function exit with argument
 * @t: string input
 * Return: value of exit status
 */
int __exit(char **t)
{
        int status = 0;

        if (t[1] != NULL)
        {
                status = _atoi(t[1]);
        }
        return (status);
}
