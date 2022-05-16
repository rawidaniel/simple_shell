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

#endif
