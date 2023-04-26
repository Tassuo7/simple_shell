#include "main.h"
/**
 * _prompt - function display prompt
 * @prompt_symbol: the symbol to be prompted
 * Return: symbol
 */
char *_prompt(char *prompt_symbol)
{
	_puts(prompt_symbol);
	return (prompt_symbol);
}
/**
* _putchar - is a function used to write a character
* @character : The charcter passed as parameter
* Return: the character written or error when some error occurs
*/
int _putchar(char character)
{
	return (write(1, &character, 1));
}
/**
 * _puts - is a function print a string
 * @str: the string input
 * Return: nothing
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
/**
 * _strcmp - A function compare two string
 * @value1 : First string
 * @value2 : second string
 * Return: 0 if successful
 */
int _strcmp(char *value1, char *value2)
{
	int i;

	for (i = 0; value1[i] != '\0' && value2[i] != '\0'; i++)
	{
		if (value1[i] != value2[i])
			return ((int)value1[i] - value2[i]);
	}
	return (0);
}
/**
 * get_env - A function that prints the current environment
 * @env : the environement
 * Return: 0 if seccessful
 */
int get_env(char **env)
{
	char **e = env;

	for (e = env; *e != NULL; e++)
	{
		_puts(*e);
		_putchar('\n');
	}
	return (0);
}
