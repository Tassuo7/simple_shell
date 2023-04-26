#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
/* declaration of prototype */
int _putchar(char c);
void _puts(char *str);
int get_env(char **env);
char *get_cmd();
int _strcmp(char *value1, char *value2);
void pid_fork(char *buffer);

#endif
