#include "shell.h"

/**
 * list_len - return the number of elements in a linked list
 * @h: pointer to the env_t linked list
 *
 * Return: the number of elements in h
 */
size_t list_len(const env_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}
	return (num);
}

/**
 * free_list - free all the node of the linked list
 * @head: list_s list to be freed
 */
void free_list(env_t **head)
{
	env_t *temp = NULL;

	if (*head == NULL)
		return;
	while (*head)
	{
		temp = (*head)->next;
		free((*head)->str);
		free(*head);
		*head = temp;
	}

	*head = NULL;
}

/**
 * print_list - print all the node in the linked list
 * @h: pointer to list_s list to print
 *
 * Return: the number of node printed
 */
size_t print_list(env_t *h)
{
	size_t count = 0;

	while (h)
	{
		if (!h->str)
			_puts("(nil)");
		else
			_puts(h->str);
		h = h->next;
		count++;
	}
	return (count);
}

/**
 * arr_to_list - transform the environ variable in to linked list
 * @head: double pointer to the env_t list to fill
 * @env: a null terminating array of string containing the
 * environment variable
 *
 * Return: number of node in the list
 */
int arr_to_list(env_t **head, char **env)
{
	int count = 0;

	if (head)
		free_list(head);
	while (env[count])
	{
		add_node_end(head, env[count]);
		count++;
	}
	return (count);
}

/**
 * list_to_array - transform the linked list in to array of string
 * @head: pointer to list_s list
 *
 * Description: If the list doesn't exist, return NULL
 * Allocate memory for the array, check if it failed
 * Traverse the list, allocate memory for each string
 * Fill each string with the string from the node
 * Set last element of the array to NULL
 * Return the array
 *
 * Return: address of the array on success, or NULL on failure
 */
char **list_to_array(env_t *head)
{
	char **arr =  NULL;
	char *s = NULL;
	env_t *temp = head;
	size_t size = 0;
	int i;

	size = list_len(head);

	if (!head || !size)
		return (NULL);
	arr = malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);

	for (i = 0; temp; temp = temp->next, i++)
	{
		s = malloc(sizeof(char) * (_strlen(temp->str) + 1));
		if (!s)
		{
			free_everything(arr);
			return (NULL);
		}
		s = _strcpy(s, temp->str);
		arr[i] = s;
	}
	arr[i] = NULL;

	return (arr);
}
