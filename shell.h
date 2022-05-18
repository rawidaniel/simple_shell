#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
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
char **_strtok(char *str, char delim);

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
int add_node_at_index(env_t **head, char *str, int idx);
int find_index_list(env_t *head, char *name);

/* list_funcs_2.c */
size_t list_len(const env_t *h);
void free_list(env_t **head);
size_t print_list(env_t *h);
int arr_to_list(env_t **head, char **env);
char **list_to_arr(env_t *head);

/* helper_funcs.c */
void sigint_handler(int sig);
void free_everything(char **args);
char **parse_line(char *line, int get);

/* set_env.c */
int _setenv(env_t **head, char **argv, int args);
int _unsetenv(env_t **head, char **argv);
void print_error_setenv(int *i, char *s, char **argv);
void setenv_handler(char **argv, env_t **head, int *i, char *prog_name);

/* print_errors.c */
void print_error(int *i, char *s, char **argv);
void print_error_env(char **argv);
void print_error_exit(int *i, char *s, char **argv);
void print_error_main(char **av);
void print_error_cd(int *i, char *s, char **argv);

/* path_finder.c */
char **get_env(char *name, char **env);
char *path_finder(char **s, char **env);
char *get_env_val(char *name, char **env);

/* builtins.c */
int is_builtin(char *line, char **argv, char *prog_name, int *i, env_t **head);
long int exit_handler(char **tokens);
int env_handler(char **av, env_t **head);
int cd_handler(char **argv, env_t **head);
void change_pwd(char *path, char **env, env_t **head);

/* main.c */
int exec(char **input, char *s, int *i, env_t **head);
#endif
