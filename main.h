#ifndef __MAIN_H__
#define __MAIN_H__
/* declaration de bibliotheque */
#define MAX_L 1024
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
/* declaration of prototype */
int _putchar(char c);
void _puts(char *str);
char *_prompt(char *prompt_symbol);
void exit_shell(void);
void execute_command(char **argv);
int _strcmp(char *value1, char *value2);
int get_env(char **env);
void shell_prompt(char **ar, char **ev);
void pid_fork(char *buffer);
char ** _boucle(char **ar, char *c);
#endif
