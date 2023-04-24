#ifndef SHELL
#define SHELL
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
extern char **environ;
char **getToken(char *line_input, char *delimiter, ssize_t input);
void shellexec(char **args, char **envp);
int funct_exit(char **args);
int funct_env(char **args);
int count(char *b[]);
int check_builtin(char **args);
#endif
