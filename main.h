#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


char **tokenize(char *line);
void execute_cmd(char **av);
void print_env(void);
int _strlen(char *s);
int _strcmp(char *value1, char *value2);
char *_strallocat(char *st);
char *_strcpy(char *dt, char *s);
char *_strcat(char *dest, char *src);
int _atoi(char *s);
int _putchar(char c);
void _puts(char *str);
int __exit(char **t);
char *_path(char *comamd);
int get_env(char **env);
#endif
