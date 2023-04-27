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
