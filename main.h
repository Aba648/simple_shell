#ifndef MAIN_H
#define MAIN_H

/*LIBRARIES*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>



/*PROTOTYPES*/
char *read_line(void);
char **tokenizer(char *lineptr);
int execute_cmd(char **cmd, char **argv);
void _free(char **arry);
char *getpath(char *cmd);
char *_myenv(char *var);
char *_strdup(const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
int _strcmp(char *, char *);
int _strlen(char *);

/* GLOBAL VAR*/
extern char **environ;
#endif
