#include "shell.h"

/**
 * _putchar - write character c to standard output
 * @c: the character to print
 *
 * Return: on success 1
 * on error, -1 is returned,and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_prompt - prints a prompt for the shell
 */
void print_prompt(void)
{
	char *s = "$ ";

	write(1, s, 2);
}

/**
 * _puts - print string to standard output
 * @str: pointer to string to print
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
