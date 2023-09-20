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
int execute_cmd(char **cmd, char **argv, int idx);
void _free(char **arry);
char *_myenv(char *var);
char *get_path(char *cmd);
void display_error(char *cmd, char *estr, int idx);
char *_atoi(int i);
void convert_string(char *str, int num);
char *_strdup(const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
int _strcmp(char *, char *);
int _strlen(char *);
void hand_built(char **command , char **argv , int status , int idx);
void bui_env(char **command , int status);
void exit_bui(char **command , int status);


/* GLOBAL VAR*/
extern char **environ;
#endif
