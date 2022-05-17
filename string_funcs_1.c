#include "shell.h"
/**
 * _strdup - allocate memory for the string to duplicate
 * @str: string to duplicate
 * Return: new string on success,or NULL on failure
 */
char *_strdup(char *str)
{
	char *dup = NULL;
	int len = 0, i = 0;

	if (str == NULL)
		return (NULL);
	while (str[len])
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/**
 * str_concat - concatenate the two string,
 * allocate a memory for the resultant string
 * @s1: string to concatenate
 * @s2: another string to concatenate
 * Return: pointer to the string crated on success,or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *str = NULL;
	int i = 0, j = 0, len1 = 0, len2 = 0;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == NULL)
		return (NULL);
	while (i < len1)
	{
		str[i] = sl[i];
		i++;
	}
	while (j < len2)
	{
		str[i] = s2[j];
		i++, j++;
	}
	str[i] = '\0';
	return (str);
}
/**
 * _strcmp - compares two string
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: less than 0 id s1 is less than s2, 0 if  the are equal,
 * greater than 0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * _strncmp - compare string up to n byte
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: number of byte to compare
 *
 * Return: 0 if the strings are the same, non-zero  if they are the different
 */
int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0;

	while (*s1 == *s2 && i < n)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		i++;
	}
	return (i != n);
}
