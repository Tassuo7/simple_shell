#ifndef __MAIN_H__
#define __MAIN_H__
/* declaration de bibliotheque */
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
/* declaration of prototype */
int _putchar(char c);
void _puts(char *str);
char *_prompt(char *prompt_symbol);
void execute_command(char **argv);
void exit_shell(void);
int _strcmp(char *value1, char *value2);
int get_env(char **env);
#endinf
