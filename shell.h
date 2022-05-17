#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <unstdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>>
#include <sys/stat.h>
#include <limits.h>
#include <signal.H>

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
#endif
