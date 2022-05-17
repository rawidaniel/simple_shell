#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <unstdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>>
#include <sys/stat.h>
#include <limits.h>
#include <signal.h>

extern char **environ;

/**
 * struct list_s - singlt linked list
 * @str: string -(malloced string)
 * @next: pointer to next node
 *
 * Description: singly linked list node struct
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} env_t;

/* tokenize.c */
int wordcount(char *str, char delim);
char **_strtok(char *str, chardelim);
/* string_funs_1.c */
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, unsigned int n);
/* string_funcs_2.c */
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
/* print_funcs */
int _putchar(char c);
void print_prompt(void);
void _puts(char *str);
/* convert_funcs.c */
long int _atoi(char *str);
char *convert(int num, int base);

/* list_funcs_1.c */
env_t *add_node_end(env_t **head, char *str);
int delete_node_at_index(env_t **head, unsigned int index);
int add_node_at_index(env_t **head, int idx);
int find_node_at_index(env_t *head, char *name);
#endif
