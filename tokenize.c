#include "shell.h"

/**
 * wordcount - count tokens in the string
 * @str: string to be parsed
 * @delim: separator between tokens
 *
 * Description: loop through the string
 * if the current character is not delimiter and the character
 * next to the current one is delimter or null terminator
 * it increment the count
 *
 * Return: the number of tokens
 */
int wordcount(char *str, char delim)
{
	int count = 0;
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != delim && (str[i + 1] == delim || str[i + 1] == '\0')
				count++;
	}
	return (count);
}

/**
 * _strtok - convert a string int an array of tokens
 * @str: string to be parsed
 * @delim: separator between tokens
 *
 * Description: if the string is NULL, return NULL
 * set the total to the nuber of token in string
 * if total is 0,return NULL
 * Allocate memory for the array of string, check if it failed
 * loop through the string and as loop as the increment is smaller than total
 * store the current position of str in cpy
 * Go pass the characters until the delim
 * Allocate memory for the previous token, check if it failed
 * Loop through cpy (copy of the token)
 * Store each character into the array of strings words
 * Terminate the string by a null byte
 * Continue
 * Set the last string of the array to NULL, return array
 *
 * Return: pointer to the array of string on success,or NULL on failure
 */
char **_strtok(char *str, char delim)
{
	char **words, *cpy = NULL;
	int i = 0, j = 0, len = 0, total = 0;

	if (str == NULL || *str == NULL)
		return (NULL);
	total = wordcount(str, delim);
	if (total == 0)
		return (0);
	words = malloc(sizeof(char *) * (total + 1));
	if (words == NULL)
		return (NULL);
	while (*str && i < total)
	{
		if (*str == delim)
			str++;
		else
		{
			cpy = str;
			while (*str != delim && *str)
			{
				len++;
				str++;
			}
			words[i] = malloc(sizeof(char) * (len + 1));
			if (words[i] == NULL)
				return (NULL);
			while (*cpy != delim && *cpy && *cpy != '\n')
			{
				words[i][j] = *cpy;
				j++;
				cpy++;
			}
			words[i][j] = '\0';
			i++;
			j = 0;
			len = 0;
		}
	}
	words[i] = NULL;
	return (words);
}
