#include "shell.h"

/**
 * _strlen - return the length of the string
 * @str: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *str)
{
	int len = 0;

	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

/**
 * _strcpy - copies the string pointed to by src
 * including the null terminating byte(\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to the buffer
 */
char *_strcpy(char *dest, char *src)
{
	int len = 0, i = 0;

	while (src[len])
		len++;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
